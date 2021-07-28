#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>

#define MAX_N 30005
#define MAX_M 801
#define INF 987654321

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

int N, D, P[MAX_N];
long long dp[MAX_N][MAX_M];
long long maxAns = -1;

int main() {
	fastscan(N);
	fastscan(D);
	for(int i=0; i<N; i++) {
		int a;
		fastscan(a);
		P[a]++;
	}

	for(int i=0; i<MAX_N; i++)
		for(int j=0; j<MAX_M; j++)
			dp[i][j] = -INF;
	
	// dp
	dp[D][400] = P[D];
	maxAns = P[D];

	for(int i=0; i<MAX_N; i++) {
		for(int j=0; j<MAX_M; j++) {
			int del = j-400;
			if(i+D+del+1 < MAX_N && dp[i][j] != -INF && D+del+1 > 0) {
			    dp[i+D+del+1][j+1] = max(dp[i+D+del+1][j+1], dp[i][j] + P[i+D+del+1]);
			    maxAns = max(maxAns, dp[i+D+del+1][j+1]);
			}
			if(i+D+del+0 < MAX_N && dp[i][j] != -INF && D+del+0 > 0) {
				dp[i+D+del+0][j+0] = max(dp[i+D+del+0][j+0], dp[i][j] + P[i+D+del+0]);
				maxAns = max(maxAns, dp[i+D+del+0][j+0]);
			}
            if(i+D+del-1 < MAX_N && dp[i][j] != -INF && D+del-1 > 0) {
                dp[i+D+del-1][j-1] = max(dp[i+D+del-1][j-1], dp[i][j] + P[i+D+del-1]);
                maxAns = max(maxAns, dp[i+D+del-1][j-1]);
            }

		}
	}

	cout << maxAns << endl;
}
