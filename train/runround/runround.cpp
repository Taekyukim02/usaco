/*
ID: taekyuk1
TASK: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long M;

vector <int> to_vector(long long n) {
	vector <int> ret;
	while(n>0) {
		ret.push_back(n%10);
		n/=10;
	}
	return ret;
}

bool roundNumber(long long n) {
	vector <int> vec = to_vector(n);

	bool visited[10];
	for(int i=0; i<10; i++) visited[i] = false;

	for(int i=0; i<vec.size(); i++) {
		if(visited[vec[i]]) return false;
		visited[vec[i]] = true;
	}

	for(int i=0; i<10; i++) visited[i] = false;

	int ind = 0;
	for(int i=0; i<vec.size(); i++) {
		if(visited[ind])
			return false;
		visited[ind] = true;
		ind = (ind + 10*vec.size() - vec[ind]) % vec.size();
	}

	if(ind != 0)
		return false;

	return true;
}

long long solve() {
	long long n = M+1;
	while(!roundNumber(n)) {
		n++;
	}
	return n;
}

int main() {
	ifstream fin ("runround.in");
	fin >> M;
	fin.close();

	ofstream fout ("runround.out");
	fout << solve() << endl;
	fout.close();
	return 0;
}
