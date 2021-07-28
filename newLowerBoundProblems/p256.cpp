#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int pw(int a, int b) {
    if(b>0)
        return a*pw(a, b-1);
    return 1;
}
int main() {
    ifstream fin ("256.in");
    ofstream fout ("256.out");

    int N;
    while(cin >> N) {
        long long c = pw(10, N/2);
        long long a = pw(10, N);

        for(long long i=0; i<a; i++)
            if(((i%c) + (i/c))*((i%c) + (i/c)) == i)
                cout << setw(N) << setfill('0') << i << endl;
    }
}