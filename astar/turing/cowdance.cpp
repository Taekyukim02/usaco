#include <iostream>

using namespace std;

int N, a[20];
int lst[20];
bool used[20];
long long tot = 0;

int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> a[i];
		used[i] = false;
		lst[i] = 0;
	}

	for(int i=N-1; i>0; i--) {
		int mn = 987654321;
		int ind = 0;
		for(int j=0; j<N; j++) {
			if(used[j]) continue;

			int prod = 1;
			for(int k=0; k<N; k++) {
				if(!used[k] && k != j)
					prod *= abs(a[k] - a[j]);
			}
			if(prod < mn) {
				mn = prod;
				ind = j;
			}
		}
		used[ind] = true;
		lst[i] = a[ind];
		tot += mn;
	}

	for(int a : lst)
		cout << a << " ";
	cout << endl;

	cout << tot << endl;

}
