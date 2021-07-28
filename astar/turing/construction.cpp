#include <iostream>
#include <algorithm>
#define f first
#define s second

using namespace std;

typedef pair<long long,long long> ii;

long long getSum(long long BITree[], long long index) 
{ 
    long long sum = 0; // Iniialize result 
  
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse ancestors of BITree[index] 
    while (index>0) 
    { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree. The given value 'val' is added to BITree[i] and  
// all of its ancestors in tree. 
void updateBIT(long long BITree[], long long n, long long index, long long val) 
{ 
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse all ancestors and add 'val' 
    while (index <= n) 
    { 
    // Add 'val' to current node of BI Tree 
    BITree[index] += val; 
  
    // Update index to that of parent in update View 
    index += index & (-index); 
    } 
} 

long long N, M, C;
ii LR[100005];
long long bitTree[1000005];
long long cnt[1000005];

long long main() {
	cin >> N >> M >> C;
	for(long long i=0; i<N; i++)
		cin >> LR[i].f >> LR[i].s;
	sort(LR, LR+N);

	long long bestans = -1;
	for(long long i=0; i<N; i++) {
		long long curr = (-M-getSum(cnt, 1000000 - C*LR[i].f)*C) * LR[i].f + LR[i].s + getSum(bitTree, 1000000-C*LR[i].f);
		bestans = bestans < curr ? curr : bestans;
		long long a = 1000000 - (LR[i].s+C*LR[i].f);
		if(a < 0) a = 0;
		updateBIT(bitTree, 1000000, a, LR[i].s+C*LR[i].f);
		updateBIT(cnt, 1000000, a, 1);
	}
		
	cout << bestans << endl;
}
