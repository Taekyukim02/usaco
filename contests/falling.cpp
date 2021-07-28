#include <iostream>
#include <fstream>

#define MAX_N 105

using namespace std;

// modified from https://stackoverflow.com/questions/5690663/c-fractions-class
class Fraction
{
public:
    int numerator, denominator;
    Fraction()
    {
        numerator = 1;
        denominator = 1;
    }
    Fraction(int n, int d)
    {
        numerator = n;
        if (d==0)
        {
            cout << "ERROR: ATTEMPTING TO DIVIDE BY ZERO" << endl;
            exit(0); // will terminate the program if division by 0 is attempted
        }
        else
            denominator = d;
    }
    /*In the following functions I am dividing both numerator and denominator by the gcd function.
    GCD function accepts both numerator and denominator values. If we had 2 fractions, 1/2 and 1/4
    and we passed it into the Sum, the result would be n=6 and d=8. These are the values that GCD
    function will accept, find greatest common divisor and return the integer value of 2. In my case
    am diving both numerator and denominator on the same line by the greatest common divisor. Although
    it probably would be more efficient to create a local int variable and store GCD value in it, but
    for such small program it shouldn't make any difference.*/
    Fraction Sum(Fraction otherFraction)
    {
        int n = numerator*otherFraction.denominator+otherFraction.numerator*denominator;
        int d = denominator*otherFraction.denominator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    Fraction Difference(Fraction otherFraction)
    {
        int n = numerator*otherFraction.denominator-otherFraction.numerator*denominator;
        int d = denominator*otherFraction.denominator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    Fraction Product(Fraction otherFraction)
    {
        int n = numerator*otherFraction.numerator;
        int d = denominator*otherFraction.denominator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    Fraction Division(Fraction otherFraction)
    {
        int n = numerator*otherFraction.denominator;
        int d = denominator*otherFraction.numerator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    bool isLessThan(Fraction other) {
        if(numerator * other.denominator <= denominator * other.numerator)
            return true;
        return false;
    }
    void simplify() {
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }
    // I got the GCD algorithm from the following source:
    // Source C#: http://www.ww.functionx.com/csharp2/examples/gcd.htm
    int gcd(int n, int d)
    {
        int remainder;
        while (d != 0)
        {
            remainder = n % d;
            n = d;
            d = remainder;
        }
        return n;
    }
    void show() // Display method
    {
        if (denominator == 1) // e.g. fraction 2/1 will display simply as 2
            cout << numerator << endl;
        else
            cout << numerator << "/" << denominator << endl;
    }
};

int N, A[MAX_N], Q[MAX_N];
Fraction dist[MAX_N][MAX_N];

int main() {
    ifstream fin ("falling.in");
    fin >> N;
    for(int i=1; i<=N; i++)
        fin >> A[i];
    for(int i=1; i<=N; i++)
        fin >> Q[i];
    fin.close();

    // initialize distances
    for(int i=1; i<=N; i++)
        for(int j=i+1; j<=N; j++) {
            if(A[i] <= A[j])
                dist[i][j] = dist[j][i] = Fraction(A[j]-A[i], j-i);
            else
                dist[i][j] = dist[j][i] = Fraction(987654321, 1);
        }
    for(int i=1; i<=N; i++)
        dist[i][i] = Fraction(0,1);
/*
    for(int i=1; i<=N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j].simplify();
            cout << dist[i][j].numerator << "/"
                 << dist[i][j].denominator << endl;
        }
    }
    cout << "-------" <<endl; */
    // Floyd-Warshall
    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                if(dist[i][k].isLessThan(dist[k][j])
                    && dist[k][j].isLessThan(dist[i][j])) {
                    dist[i][j] = dist[k][j];
                }

    ofstream fout("falling.out");
    for(int i=1; i<=N; i++) {
        dist[i][Q[i]].simplify();
        if(dist[i][Q[i]].numerator < 987654320) {
            fout << dist[i][Q[i]].numerator << "/"
                 << dist[i][Q[i]].denominator << endl;
        }
        else
            fout << "-1" << endl;
    }
    fout.close();
    /*
    for(int i=1; i<=N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j].simplify();
            cout << dist[i][j].numerator << "/"
                 << dist[i][j].denominator << endl;
        }
    }*/
}