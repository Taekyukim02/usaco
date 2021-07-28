#include <iostream>
#include <fstream>

using namespace std;

int N, c[100000];
int seen[100001];
int bit[100001];

void bitupdate(int i) {
	i++;
//	cout << "bitupdate in" << endl;
	for(; i<=100000; i+=(i&-i)) {
//		cout << i << endl;
		bit[i]++;
	}
//	cout << "bitupdate out" << endl;
}

int bound=-1;
void update(int i) {
//	cout << "update in" << endl;
	seen[i]++;
	bitupdate(i);
	if(i > bound)
		bound = i;
//	cout << "update out" << endl;
}

// get # of c[i] seen, less than n
long long getLess(int n) {
//	cout << "getless in" << endl;
	long long ret=0;
	for(; n>=0; n-=(n&-n)) {
		ret+=bit[n];
		if(n==0)
			break;
	}
//	cout << "getless out" << endl;
	return ret;
}

// get lowest integer of highest interval seen
int getBound() {
//	cout << "getbound in" << endl;
	if(bound!=-1 && seen[bound-1]==false)
		return bound;

	bool f=false;
	int i = 100000000;
	if(bound != -1)
		i = bound;

	for(; i>=0; i--) {
		if(seen[i]) 
			f = true;
		if(f && seen[i]==0)
			break;
		if(f)
			bound = i;
	}
//	cout << "getbound out" << endl;
	return bound;
}

int main() {
	ifstream fin ("greedy.in");
	fin >> N;
	for(int i=0; i<N; i++)
		fin >> c[i];
	fin.close();
	
	int cnt = N-1;
	update(c[0]);
	for(int i=1; i<N; i++) {
		for(int j=0; j<6; j++)
			cout << seen[j] << " ";
		cout << endl;
		cout << getLess(getBound()) << " " << N-1-i << " " << getBound() << endl;
		if(getLess(getBound()) + N-1-i >= getBound()) {
			cnt--;
			update(c[i]);
		}
		else
			break;
	}

	ofstream fout ("greedy.out");
	fout << cnt << endl;
	fout.close();
}
