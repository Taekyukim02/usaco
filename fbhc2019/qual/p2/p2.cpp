#include <fstream>

#define MAX_N 5000

using namespace std;

int T;
string s;

int main() {
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");
	fin >> T;
	for(int i=1; i<=T; i++) {
		fin >> s;
		int N = s.length();
		int M = 0;
		for(char c : s)
			if(c == 'B')
				M++;
		bool b = false;
		if((M < N-1 && M >= 2) || (N == 3 && M == 1))
			b = true;
		if(b)
			fout << "Case #" << i << ": Y" << endl;
		else
			fout << "Case #" << i << ": N" << endl;
	}
}
