#include <iostream>
#define MAX_N 200

using namespace std;

int arr[MAX_N][MAX_N];
bool seen[MAX_N];
int a, b, c;

int main() {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		a = b = c = 0;
		int N;
		cin >> N;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				cin >> arr[i][j];
		
		for(int i=0; i<N; i++)
			a += arr[i][i];
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<MAX_N; j++) seen[j] = 0;
			for(int j=0; j<N; j++) {
				int k = arr[i][j];
				if(seen[k]) {
					b++;
					break;
				} else
					seen[k] = 1;
			}
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<MAX_N; j++) seen[j] = 0;
			for(int j=0; j<N; j++) {
				int k = arr[j][i];
				if(seen[k]) {
					c++;
					break;
				} else
					seen[k] = 1;
			}
		}

		cout << "Case #"<<t<<": " << a << " " << b << " " << c << endl;
	}
}
