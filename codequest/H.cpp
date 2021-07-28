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

int good[1000][1000];

int main() {
	ll T; fastscan(T);

	for(int t=1; t<=T; t++) {
		for(int i=0; i<1000; i++) {
			for(int j=0; j<1000; j++) {
				good[i][j] = 0;
			}
		}

		for(int x=0; x<3; x++) {
			int a, b, c;
			cin >> a >> b >> c;
			for(int i=0; i<1000; i++) {
				for(int j=0; j<1000; j++) {
					if(abs(i-500-a) + abs(j-500-b) == c) {
						good[i][j]++;
						if(good[i][j] == 3) {
							cout << "(" << i-500 << "," << j-500 << ")" << endl;
							i = j = 1000;
						}
					}
				}
			}
		}
	}
}
