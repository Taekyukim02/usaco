#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>

using namespace std;

string a;
int cnt[30];

int main() {
	cin >> a;
	for(int i=0; i<a.length(); i++) {
		cnt[a[i] - 'a']++;
	}
	char m = 'a'; 
	int mcnt = -1;
	for(int i=0; i<26; i++) {
		if(cnt[i] > mcnt && cnt[i] >= 1) {
			m = (char) (i + 'a');
			mcnt = cnt[i];
		}
	}
	cout << m << endl;

	cout << a << endl;
}
