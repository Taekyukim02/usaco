#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int cnt[4];
	cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
	for(int i=0; i<N; i++) {
		int x;
		cin >> x;
		if(x%2)
			cnt[i%2]++;
		else
			cnt[i%2+2]++;
	}
	
	if((cnt[0]-cnt[1])==0 || (cnt[2]-cnt[3])==0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
