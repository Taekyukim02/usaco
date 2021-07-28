/*
ID: taekyuk1
TASK: namenum
LANG: C++
*/
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map <string, int> mp;
ifstream fin ("namenum.in");
ifstream dict ("dict.txt");
ofstream fout ("namenum.out");
bool printed = false;

void dfs(vector <int> digits, string curr) {
	if(digits.size() == 0) {
		if(mp.find(curr) != mp.end()) {
			fout << curr << endl;
			printed = true;
		}
		return;
	}
	int f = digits[0];
	digits.erase( digits.begin() );
	switch(f) {
		case 2: dfs(digits, curr + "A");
				dfs(digits, curr + "B");
				dfs(digits, curr + "C");
				break;
		case 3: dfs(digits, curr + "D");
				dfs(digits, curr + "E");
				dfs(digits, curr + "F");
				break;
		case 4: dfs(digits, curr + "G");
				dfs(digits, curr + "H");
				dfs(digits, curr + "I");
				break;
		case 5: dfs(digits, curr + "J");
				dfs(digits, curr + "K");
				dfs(digits, curr + "L");
				break;
		case 6: dfs(digits, curr + "M");
				dfs(digits, curr + "N");
				dfs(digits, curr + "O");
				break;
		case 7: dfs(digits, curr + "P");
				dfs(digits, curr + "R");
				dfs(digits, curr + "S");
				break;
		case 8: dfs(digits, curr + "T");
				dfs(digits, curr + "U");
				dfs(digits, curr + "V");
				break;
		case 9: dfs(digits, curr + "W");
				dfs(digits, curr + "X");
				dfs(digits, curr + "Y");
				break;
	};
}

int main()
{	
	// read dictionary
	string word;
	while(dict >> word)
		mp[word] = 1;

	// read input
	long long N;
	fin >> N;
	
	int d1[12];
	int id=0;
	for(long long i=N; i>0; i/=10)
		d1[id++] = (i%10);

	vector <int> digits;
	for(int i=0; i<id; i++)
		digits.push_back(d1[id-i-1]);

	// dfs
	dfs(digits, "");

	if(!printed) fout << "NONE" << endl;

	return 0;
}
