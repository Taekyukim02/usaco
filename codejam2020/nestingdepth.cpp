#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		string str;
		string output = "";
		cin >> str;
		int d = 0;
		for(int i=0; i<str.length(); i++) {
			int k = (int) (str[i] - '0');
			while(k > d) {
				d++;
				output += "(";
			}
			while(k < d) {
				d--;
				output += ")";
			}
			output += str[i];
		}
		while(0 < d) {
			d--;
			output += ")";
		}
		cout << "Case #"<<t<<": " << output << endl;
	}
}
