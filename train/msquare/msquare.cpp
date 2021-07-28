/*
ID: taekyuk1
TASK: msquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define f first
#define s second

using namespace std;

vector<int> exchange(vector <int> arr) {
	for(int i=0; i<4; i++) {
		int temp = arr[i];
		arr[i] = arr[7-i];
		arr[7-i] = temp;
	}
	return arr;
}

vector<int> rotB(vector<int> arr) {
	int temp = arr[3];
	for(int i=3; i>0; i--) 
		arr[i] = arr[i-1];
	arr[0] = temp;

	temp = arr[4];
	for(int i=4; i<7; i++)
		arr[i] = arr[i+1];
	arr[7] = temp;
	return arr;
}

vector<int> rotC(vector<int> arr) {
	int temp = arr[1];
	arr[1] = arr[6];
	arr[6] = arr[5];
	arr[5] = arr[2];
	arr[2] = temp;
	return arr;
}

bool visited[50000];
int fact[10] = {1, 1, 2, 6, 24, 120, 720, 
				720*7, 720*8, 720*8*9};
int mp(vector <int> in) {
	int ret = 0;
	int place[8];
	for(int i=0; i<8; i++)
		place[i] = i;

	for(int i=0; i<8; i++) {
//		cout << fact[7-i] << " " << place[in[i]-1] << endl;
		ret += fact[7-i]*(place[in[i]-1]);
		for(int j=in[i]; j<8; j++)
			place[j]--;
	}
//	cout << ret << endl;
	return ret;
}

int main() {
	vector<int> target(8);
	ifstream fin ("msquare.in");
	for(int i=0; i<8; i++)
		fin >> target[i];
	fin.close();

	bool found = false;
	string str = "nothing";
	queue <pair<string, vector<int> > > bfs;
	vector<int> start = {1,2,3,4,5,6,7,8};
	
	/*
	start = rotB(start);
	start = rotC(start);
	start = exchange(start);
	start = rotB(start);
	start = rotC(start);
	start = rotC(start);
	start = rotB(start);
	for(int i=0; i<8; i++)
		cout << start[i] << " \n"[i==8];
	
	return 0;
	*/

	bfs.emplace("", start);
	while(!bfs.empty()) {
		auto x = bfs.front();
		bfs.pop();

		bool e = true;
		for(int i=0; i<8; i++)
			if(x.s[i] != target[i])
				e = false;
		if(e) {
			str = x.f;
			break;
		}

		if(visited[mp(x.s)])
			continue;
		visited[mp(x.s)] = true;

		bfs.emplace(x.f+"A", exchange(vector<int>(x.s)));
		bfs.emplace(x.f+"B", rotB(vector<int>(x.s)));
		bfs.emplace(x.f+"C", rotC(vector<int>(x.s)));
	}

	ofstream fout ("msquare.out");
	fout << str.length() << endl;
	fout << str << endl;
	fout.close();
}
