#include <iostream>

using namespace std;

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		int X, Y;
		string str;
		cin >> X >> Y;
		cin >> str;
		
		int i=0;
		for(i=0; i<str.length(); i++) {
			if(abs(X) + abs(Y) <= i)
				break;

			char c = str[i];
			if(c == 'N')
				Y += 1;
			if(c == 'S')
				Y -= 1;
			if(c == 'E')
				X += 1;
			if(c == 'W')
				X -= 1;
		}

		if(abs(X) + abs(Y) <= i)
			cout << "Case #" << t << ": " << i << endl;
		else
			cout << "Case #" << t << ": IMPOSSIBLE" << endl;
	}
}
