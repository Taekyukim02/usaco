/*
ID: taekyuk1
TASK: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int N;
map <vector<char>, int> ans;
vector<char> c;

int digit(int n) {
	int r = 0;
	while(n > 0) {
		n /= 10;
		r++;
	}
	return r;
}

void dfs(vector<char> c) {
	if(c.size() == N-1) {
		int num [] {1, 2, 3, 4, 5, 6, 7, 8, 9};

		// preprocess concatenation
		for(int i=c.size()-1; i>=0; i--)
			if(c[i] == ' ') {
				while(digit(num[i]) <= digit(num[i+1]))
					num[i] *= 10;
				num[i] += num[i+1];
			}

		// sum
		int sum = num[0];
		for(int i=0; i<c.size(); i++) {
			if(c[i] == '+')
				sum += num[i+1];
			if(c[i] == '-')
				sum -= num[i+1];
		}
		
		if(sum == 0)
			ans[c] = 1;

		return;
	}
	c.push_back('+');
	dfs(c);
	c.erase(--c.end());
	c.push_back('-');
	dfs(c);
	c.erase(--c.end());
	c.push_back(' ');
	dfs(c);
	c.erase(--c.end());
}

void solve() {
	dfs(c);
}

int main() {
	// read input
	ifstream fin ("zerosum.in");
	fin >> N;

	// solve
	solve();

	// print output
	ofstream fout ("zerosum.out");
	for(auto it = ans.begin(); it != ans.end(); ++it) {
		for(int i=0; i<N-1; i++) 
			fout << i+1 << (it->first)[i];
		fout << N << endl;
	}
	fout.close();
	return 0;
}

