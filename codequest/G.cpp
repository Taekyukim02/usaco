#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>

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
typedef pair<ii, ii> iiii;

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
iiii arr[100000];

int main() {
	ll T; fastscan(T);

	for(int t=1; t<=T; t++) {
		ll X, D; cin >> X >> D;
		for(int i=0; i<X; i++) {
			ll a, b, c, d;
			cin >> a >> b >> c >> d;
			arr[i] = iiii(ii(a, b), ii(-c, d));
		}
		sort(arr, arr+X);

		for(int j=0; j<D; j++) {
			ll a, b; cin >> a >> b;

			ll i=0;
			while(arr[i].f.f < a || arr[i].f.s < b) {
				i++;
			}

			ll A = arr[i].f.f;
			ll B = arr[i].f.s;

			if(-arr[i].s.f < 0.000005 && arr[i].s.s < 0.000005)
				cout << "No Stop" << endl;
			else
				while(arr[i].f.f == A || arr[i].f.s == B) {
					cout << -arr[i].s.f << " " << arr[i].s.s << endl;
					i++;
				}
		}
	}
}
