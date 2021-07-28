#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int trie[330000][27];
int cnt = 1;

void build(char* str, int sz, int n) {
	if(sz==0) {
		trie[n][0] = -1;
		return;
	}
	if(trie[n][str[0]-'a'+1] != 0)	// already seen prefix
		build(str+1, sz-1, trie[n][str[0]-'a'+1]);
	else {
		trie[n][str[0]-'a'+1] = cnt;
		cnt++;
		build(str+1, sz-1, trie[n][str[0]-'a'+1]);
	}
}

bool valid;
bool seen[27][27];

void makeGraph(char* str, int sz, vector<int> graph[], int n) {
	if(sz == 0) return;
	if(trie[n][0] == -1) {
		valid = false;
		return;
	}

	int c = str[0]-'a'+1;
	for(int i=1; i<=26; i++) {
		if(i != c && !seen[c][i] && trie[n][i] != 0) {
			graph[c].push_back(i);
			seen[c][i] = true;
		}
	}

	makeGraph(str+1, sz-1, graph, trie[n][c]);
}

bool loop(vector <int> graph[], bool visited[], bool recurVisited[], int n) {
	visited[n] = recurVisited[n] = true;

	for(int to : graph[n]) {
		if(!visited[to] && loop(graph, visited, recurVisited, to))
			return true;
		else if(recurVisited[to])
			return true;
	}

	recurVisited[n] = false;
	return false;
}

string str[30000];

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> str[i];
		char c[str[i].length()+1];
		strcpy(c, str[i].c_str());
		build(c, str[i].length(), 0);
	}
/*
	for(int i=0; i<100; i++) {
		for(int j=0; j<27; j++)
			cout << trie[i][j] << " ";
		cout << endl;
	}
	*/

	vector <string> ans;
	for(int i=0; i<N; i++) {
		vector <int> graph[27];
		for(int j=0; j<27; j++)
			for(int k=0; k<27; k++)
				seen[j][k] = false;

		valid = true;
		char c[str[i].length()+1];
		strcpy(c, str[i].c_str());
		makeGraph(c, str[i].length(), graph, 0);
	/*	
		cout << "i " << i << endl;
		for(int j=1; j<27; j++) {
			cout << "j: " << j << " ";
			for(int to : graph[j])
				cout << to << " ";
			cout << endl;
		}
		*/

		if(!valid) continue;

		bool visited[27];
		bool recurVisited[27];
		for(int j=0; j<27; j++) {
			visited[j] = false;
			recurVisited[j] = false;
		}
		for(int j=1; j<27; j++) {
			if(loop(graph, visited, recurVisited, j)) {
				valid = false;
				break;
			}
		}
		
		if(valid) {
			ans.push_back(str[i]);
		}
	}

	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
