/*
ID: taekyuk1
TASK: heritage
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string in, pre, post="";
int idx = 0;

void build(string a) {
	if(a.length() == 0)
		return;
	if(a.length() == 1) {
		post += a;
		idx++;
		return;
	}

	int i;
	for(i=0; i<a.length(); i++)
		if(a[i] == pre[idx])
			break;
	
	idx++;
	build(a.substr(0,i));
	if(i+1 < a.length())
		build(a.substr(i+1, 100000));
	post += a[i];
}

int main() {
	ifstream fin ("heritage.in");
	fin >> in >> pre;
	fin.close();

	build(in);

	ofstream fout ("heritage.out");
	fout << post << endl;
	fout.close();
}
