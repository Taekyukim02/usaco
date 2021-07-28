#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int paint[100000];
int N;
bool in[100001];
int last[100001];

int solve() {
	int ans = 0;
	stack <int> st;		// contains open intervals
	for(int i=0; i<N; i++) {
		if(paint[i] == 0 && st.size())
			return -1;
		if(paint[i] == 0)
			continue;

		if(!st.empty() && paint[i] == st.top()) {
			if(last[paint[i]] == i) {
				st.pop();
				in[paint[i]] = false;
			}
		}
		else {
			if(in[paint[i]] == true)
				return -1;
			if(in[paint[i]] == false && last[paint[i]] != i) {
				in[paint[i]] = true;
				st.push(paint[i]);
			}
			else if(in[paint[i]] == false && last[paint[i]] == i)
				ans = max(ans, (int) st.size()+1);
		}
		ans = max(ans, (int) st.size());
	}

	return ans;
}

int main() {
	// read input
	ifstream fin ("art2.in");
	fin >> N;
	for(int i=0; i<N; i++) {
		fin >> paint[i];
		last[paint[i]] = max(last[paint[i]], i);
	}
	fin.close();

	// print output
	ofstream fout ("art2.out");
	fout << solve() << endl;
	fout.close();
	return 0;
}
