#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <string.h>

#define MAX_N 1005

using namespace std;

void fastscan(int &number) 
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

int ar[MAX_N], arr[MAX_N];
int N, M;
int n=1;
string str;

void paint(int i, int p) {
	while((i<n) && (arr[i] & p) == p) {
		arr[i] -= p;
		i++;
	}
}

int main() {
	fastscan(N);
	cin >> str;
	for(int i=0; i<N; i++) {
		switch(str[i]) {
			case 'r': ar[i] = 1;
					  break;
			case 'y': ar[i] = 2;
					  break;
			case 'b': ar[i] = 4;
					  break;
			case 'o': ar[i] = 3;
					  break;
			case 'g': ar[i] = 6;
					  break;
			case 'p': ar[i] = 5;
					  break;
		}
	}

	arr[0] = ar[0];
	for(int i=1; i<N; i++) {
		if(ar[i] != ar[i-1]) {
			arr[n] = ar[i];
			n++;
		}
	}

	int cnt=0;
	for(int i=0; i<n; i++) {
		if(arr[i] == 0)
			continue;

		paint(i, arr[i]);
		cnt++;
	}

	cout << cnt << endl;
	return (0);		
}
