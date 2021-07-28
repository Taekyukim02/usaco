#include <iostream>

using namespace std;

long long binom[501][501];

int main() {
	binom[0][0] = 1;
    for(int i=1; i<501; i++) {
        binom[i][0] = binom[i][i] = 1;
        for(int j=1; j<i; j++)
            binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
    }

	int a, b;
	long long tot = 0;
	while(true) {
		cin >> a >> b;
		tot += binom[a-1][b-1];
		cout << "TOT =" << tot << "=" << endl;
	}
	
}
