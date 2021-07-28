/*
ID: taekyuk1
TASK: contact
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

struct cmp {
	bool operator() (const string& a, const string& b) const {
		if(a.length() != b.length())
			return a.length()<b.length();
		return (a < b);
	}
};

int A, B, N;
string str = "";

int main() {
	ifstream fin ("contact.in");
	fin >> A >> B >> N;
	string s;
	while(fin >> s)
		str += s;
	fin.close();

	map <string, int> mp;
	for(int i=A; i<=B; i++) {
		for(int j=0; j+i-1<str.length(); j++) {
			s = str.substr(j, i);
			if(mp.find(s) != mp.end())
				mp[s]++;
			else
				mp[s] = 1;
		}
	}

	map <int, set<string, cmp> > cnt; 
	for(auto it=mp.begin(); it!=mp.end(); ++it) {
		cnt[it->second].insert(it->first);
	}

	auto it = (--cnt.end());
	ofstream fout ("contact.out");
	for(int i=0; i<N && i<cnt.size(); i++) {
		fout << it->first << endl;
		int j = 0;
		for(auto k=(it->second).begin(); k!=(it->second).end(); ++k) {
			fout << (*k);
			j++;
			if(j%6 == 0) fout << endl;
			else if(k != (--((it->second).end())))fout << " ";
		}
		if(j%6 != 0) fout << endl;
		--it;
	}
	return 0;
}
