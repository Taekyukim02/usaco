#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#define MAX_N 1000000
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

ii minV[MAX_N*3], maxV[MAX_N*3];
long long arr[MAX_N], N;

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

void build(int l, int r, int n) {
	if(l == r) {
		maxV[n] = minV[n] = ii(arr[l], l);
		return;
	}

	int mid = (l+r)/2;
	build(l, mid, 2*n);
	build(mid+1, r, 2*n+1);

	maxV[n] = (maxV[2*n].f>maxV[2*n+1].f) ? maxV[2*n] : maxV[2*n+1];
	minV[n] = (minV[2*n].f<minV[2*n+1].f) ? minV[2*n] : minV[2*n+1];
}

ii maxId(int l, int r, int q1, int q2, int n) {
	if(l > r || q1 > q2 || r < q1 || q2 < l)
		return ii(0, -1);
	
	if(q1 <= l && r <= q2)
		return maxV[n];
	
	// recurse down
	int mid = (l+r)/2;

	ii a = maxId(l, mid, q1, q2, 2*n);
	ii b = maxId(mid+1, r, q1, q2, 2*n+1);
	return (a.f>b.f) ? a : b;
}

ii minId(int l, int r, int q1, int q2, int n) {
	if(l > r || q1 > q2 || r < q1 || q2 < l)
		return ii(987654321, -1);
	
	if(q1 <= l && r <= q2)
		return minV[n];
	
	// recurse down
	int mid = (l+r)/2;

	ii a = minId(l, mid, q1, q2, 2*n);
	ii b = minId(mid+1, r, q1, q2, 2*n+1);
	return (a.f<b.f) ? a : b;
}

long long sum=0;
void recurMax(int l, int r) {
	if(l>r) return;

	// add maximum
	ii m = maxId(0, N-1, l, r, 1);
	sum += (r-m.s+1) * (m.s-l+1) * m.f;

	// recurse down
	recurMax(l, m.s-1);
	recurMax(m.s+1, r);
}

void recurMin(int l, int r) {
	if(l>r) return;

	// add maximum
	ii m = minId(0, N-1, l, r, 1);
	sum -= (r-m.s+1) * (m.s-l+1) * m.f;

	// recurse down
	recurMin(l, m.s-1);
	recurMin(m.s+1, r);
}

int main() {
	fastscan(N);
	for(int i=0; i<N; i++)
		fastscan(arr[i]);
	
	build(0, N-1, 1);

	// recursive algorithm
	recurMax(0, N-1);
	recurMin(0, N-1);

	cout << sum << endl;
}

