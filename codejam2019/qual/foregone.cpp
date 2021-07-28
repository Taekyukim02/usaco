#include <iostream>

using namespace std;

int T;
string str;
char res1[105], res2[105];
int len1, len2;

int main() {
	cin >> T;
	for(int i=1; i<=T; i++) {
		cin >> str;

		len1 = len2 = 0;
		for(int j=0; j<str.length(); j++) {
			if(str[j] == '4') {
				res1[len1++] = '3';
				res2[len2++] = '1';
			} else {
				res1[len1++] = str[j];
				if(len2 != 0)
					res2[len2++] = '0';
			}
		}

		cout << "Case #";
		cout << i;
		cout << ": ";
		for(int j=0; j<len1; j++)
			cout << res1[j];
		cout << " ";
		for(int j=0; j<len2; j++)
			cout << res2[j];
		cout << "\n";
	}
}
