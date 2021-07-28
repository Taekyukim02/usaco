#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>

#define MAX_N (1<<17)

using namespace std;

long long segtree[4*MAX_N];		// define MAX_N
long long arr[MAX_N];

long long N, M;

void fastscan(long long &number) 
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

// point update on x
void update(int node, int l, int r, int x, int val) {
	if(x < l || r < x)
		return;
	if(l == r && l == x) {
		segtree[node] = val;
		return;
	}
	
	update(2*node+0, l, (l+r)/2+0, x, val);
	update(2*node+1, (l+r)/2+1, r, x, val);

	long long p1 = segtree[2*node+0];
	long long p2 = segtree[2*node+1];
	long long diff = r-l+1;
	int cnt=0;
	while(diff > 1) {
		cnt++;
		diff >>= 1;
	}
	if(cnt % 2 == 1)
		segtree[node] = p1 | p2;
	else
		segtree[node] = p1 ^ p2;
}

// build tree
long long build(int node, int l, int r) {
	if(l > r)
		return 0;

	if(l == r) {
		segtree[node] = arr[l];
		return segtree[node];
	}
	long long p1 = build(2*node+0, l, (l+r)/2+0);
	long long p2 = build(2*node+1, (l+r)/2+1, r);
	long long diff = r-l+1;
	
	int cnt=0;
	while(diff > 1) {
		cnt++;
		diff >>= 1;
	}
	if(cnt % 2 == 1)
		segtree[node] = p1 | p2;
	else
		segtree[node] = p1 ^ p2;

	return segtree[node];
}


int main() {
	fastscan(N);
	fastscan(M);
	for(int i=0; i<(1<<N); i++)
		fastscan(arr[i]);

	build(1, 0, (1<<N)-1);
	
	long long a, b;
	for(int i=0; i<M; i++) {
		fastscan(a);
		fastscan(b);
		update(1, 0, (1<<N)-1, a-1, b);
		cout << segtree[1] << endl;
	}
}
