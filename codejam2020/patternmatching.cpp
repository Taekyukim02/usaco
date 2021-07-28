#include <iostream>

using namespace std;

string str[50];
void solve() {
	int N; cin >> N;
	int lmax = 0, rmax = 0;
	int li = 0, ri = 0;
	for(int i=0; i<N; i++) {
		cin >> str[i];
		int a = 0;
		while(str[i][a] != '*')
			a++;
		if(a > lmax) {
			lmax = a;
			li = i;
		}
		int b = 0;
		while(str[i][str[i].length()-1-b] != '*')
			b++;
		if(b > rmax) {
			rmax = b;
			ri = i;
		}
	}

	for(int i=0; i<N; i++) {
		for(int c=0; str[i][c] != '*' && c<lmax; c++)
			if(str[i][c] != str[li][c]) {
				cout << "*" << endl;
				return;
			}
		for(int c=0; str[i][str[i].length()-1-c] != '*' && c<rmax; c++)
			if(str[i][str[i].length()-1-c] != str[ri][str[ri].length() - 1 -c]) {
				cout << "*" << endl;
				return;
			}
	}

	for(char c : str[li])
		if(c != '*')
			cout << c;
	for(int i=0; i<N; i++)
		for(char c : str[i])
			if(c != '*')
				cout << c;
	for(char c : str[ri])
		if(c != '*')
			cout << c;
	cout << endl;
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
