#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

#define MAX_N 100000
#define MAX_M 100000
#define f first
#define s second
#define ll long long

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef pair<long long, long long> ii;

void fastscan(ll &number)
{
    //variable to indicate sign of input number 
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer 
    c = getchar();
    if (c=='-')
    {
        // number is negative 
        negative = true;

        // extract the next character from the buffer 
        c = getchar();
    }

    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative)
        number *= -1;
}

///////   START CODING HERE    ////////

string str1[10000], str2[10000];
int a[10000];
double b[10000], c[10000];

double PI = 3.141592;

int main() {
	ll T; fastscan(T);

	for(int t=1; t<=T; t++) {
		int X; cin >> X;
		for(int i=0; i<X; i++) {
			cin >> str1[i] >> str2[i] >> a[i] >> b[i] >> c[i];
		}
		bool good = false;
		for(int i=0; i<X; i++) {
			if(a[i] <= 1000 && abs(b[i]*cos(c[i]*PI/180.0)) <= 20.0001 && abs(b[i]*sin(c[i]*PI/180.0)) <= 40.00001) {
				cout << str1[i] + " " + str2[i] << endl;
				good = true;
				break;
			}
		}
		if(!good)
			cout << "ABORT LAUNCH" << endl;
	}
}
