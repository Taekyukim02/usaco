#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>

#define MAX_N 300005

using namespace std;

long long done[MAX_N];
bool finished[4*MAX_N];

int N, M;

// lazy-fill [q1, q2] range
void fill(int node, int l, int r, int q1, int q2, long long val) {
	if(finished[node]) return;
	if(l > r || r < q1 || q2 < l) return;
    if(l == r && q1 <= l && r <= q2) {
		if(l != val-1) {
			done[l] = val;
			finished[node] = true;
		}
		return;
	}
	fill(2*node+0, l, (l+r)/2+0, q1, q2, val);
	fill(2*node+1, (l+r)/2+1, r, q1, q2, val);
	finished[node] = finished[2*node] && finished[2*node+1];
}

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

int main() {
	fastscan(N);
	fastscan(M);
	int a, b, c;
	for(int i=0; i<M; i++) {
		fastscan(a);
		fastscan(b);
		fastscan(c);
		fill(1, 0, N-1, a-1, b-1, c);
	}

	for(int i=0; i<N; i++) {
		cout << done[i] << " ";
	}
	cout << endl;
}
