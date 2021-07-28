#include <iostream>
#include <algorithm>

using namespace std;

long long A[10005];

long long mymin(long long a, long long b) {
	if(a < b) return a;
	return b;
}

void solve() {
	long long N, D; cin >> N >> D;
	for(long long i=0; i<N; i++)
		cin >> A[i];
	
	sort(A, A+N);

	long long bestAns = D-1;
	for(long long i=0; i<N; i++) {
		for(long long j=1; j<=D; j++) {
			long long curNumCuts = j-1;
			long long curNumPieces = j;
			long long extraPieces = 0;
			for(long long k=0; k<N; k++) {
				if(k == i) continue;

				if(curNumPieces == D)
					break;

				if(A[k]*j % A[i] == 0) {
					long long thisCut = (A[k]*j / A[i]) - 1;
					long long thisPiece = (A[k]*j / A[i]);
					if(curNumPieces + thisPiece > D) {
						extraPieces += thisPiece;
						break;
					} else {
						curNumCuts += thisCut;
						curNumPieces += thisPiece;
						if(curNumPieces == D)
							break;
					}
				} else {
					extraPieces += (A[k]*j / A[i]);
				}
			}

			if(curNumPieces == D && curNumCuts < bestAns)
				bestAns = curNumCuts;
			else if(curNumCuts < bestAns && curNumPieces < D 
							&& extraPieces + curNumPieces >= D) {
				bestAns = mymin(bestAns, curNumCuts + (D-curNumPieces));
			}
		}
	}

	cout << bestAns << endl;
}

int main() {
	long long T; cin >> T;
	for(long long t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
