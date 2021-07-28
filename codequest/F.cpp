#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <ctime>

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

time_t dateToTimeT(int month, int day, int year) {
  // january 5, 2000 is passed as (1, 5, 2000)
  tm tmp = tm();
  tmp.tm_mday = day;
  tmp.tm_mon = month - 1;
  tmp.tm_year = year - 1900;
  return mktime(&tmp);
}

time_t badTime() {
  return time_t(-1);
}

time_t now() {
  return time(0);
}

time_t arr1[10000];
time_t arr2[10000];
int a[10000], b[10000];


int main() {
	ll T; fastscan(T);

	string str;
	for(int t=1; t<=T; t++) {
		int P, O; cin >> P >> O;
		for(int i=0; i<P; i++) {
			cin >> str >> a[i];
			arr1[i] = dateToTimeT(stoi(str.substr(5,2)), stoi(str.substr(8,2)), stoi(str.substr(0,4)));

		}
		for(int i=0; i<O; i++) {
			cin >> str >> b[i];
			arr2[i] = dateToTimeT(stoi(str.substr(5,2)), stoi(str.substr(8,2)), stoi(str.substr(0,4)));
		}

		queue<time_t> Q;
		queue<int> Qs;

		int i=0, j=0;
		bool good = true;
		while(i < P || j < O) {
			cout << i << " " << j << "here" << endl;

			if(j == O && i < P) {
				good = false;
				break;
			} else if(i == P) {
				cout << "here1" << endl;
				if(Q.empty()) { good = false;
					break;
				}
				time_t f = Q.front();
				int fs = Qs.front();
				double mysec = difftime(f, arr2[j]);
				
				if(mysec > 28*60*60*24 + 0.0001) {
					good = false;
					break;
				cout << "here2" << endl;
				} else {
					if(fs > b[j]) {
						fs -= b[j];
						j++;
				cout << "here3" << endl;
				cout << fs << b[j-1] << endl;
						continue;
					} else {
						Q.pop();
						Qs.pop();
						b[j] -= fs;
						if(b[j] == 0)
							j++;
					}
				}
			} else if(difftime(arr1[i], arr2[j]) >= 0) {
				cout << "greater" << endl;
				if(Q.empty()) { 
					good = false;
					break;
				}
				time_t f = Q.front();
				int fs = Qs.front();
				double mysec = difftime(f, arr2[j]);
				
				if(mysec > 28*60*60*24 + 0.0001) {
					good = false;
					break;
				} else {
					if(fs > b[j]) {
						fs -= b[j];
						j++;
						continue;
					} else {
						Q.pop();
						Qs.pop();
						b[j] -= fs;
						if(b[j] == 0)
							j++;
					}
				}
			}
			else {
				cout << "lesser" << endl;
				Q.push(arr1[i]);
				Qs.push(a[i]);
				i++;
			}
		}

		if(!Q.empty()) {
			good = false;
			cout << Q.front() << " " << Qs.front();
		}

		if(good)
			cout << "OK" << endl;
		else
			cout << "NOT OK" << endl;
	}

}
