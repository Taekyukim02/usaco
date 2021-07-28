#include <iostream>

using namespace std;

string str;
int N, T;

int main() {
	cin >> T;
	for(int i=1; i<=T; i++) {
		cin >> N >> str;

		cout << "Case #";
		cout << i;
		cout << ": ";

		int x=0, y=0;
		for(int j=0; j<N-1; j++) {
			if(str[2*j] == 'E')
				x++;
			else
				y++;

			if(x == j && y == j+1)
				cout << "ES";
			else
				cout << "SE";

			if(str[2*j+1] == 'E')
				x++;
			else
				y++;
		}

		cout << "\n";
	}
}
