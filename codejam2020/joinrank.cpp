#include <iostream>

using namespace std;

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		int R, S;
		cin >> R >> S;	
		cout << "Case #" << t << ": " << (S-1)*(R-1) << endl;

		int k = 1;
		for(int j=0; j<R-1; j++) {
			for(int i=0; i<S-1; i++) {
				cout << R-j << " " << R*S - (R-j) - k << endl;
				k++;
			}
			k++;
		}
	}
}
