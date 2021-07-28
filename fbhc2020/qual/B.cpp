#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin ("B.in");
	ofstream fout ("B.out");

	int T;
	fin >> T;
	for(int t=1; t<=T; t++) {
		int N;
		fin >> N;
		char c;
		int a,b;
		a = b = 0;
		for(int i=0; i<N; i++) {
			fin >> c;
			if(c == 'A')
				a++;
			if(c == 'B')
				b++;
		}

		if(a - b == 1 || b - a == 1)
			fout << "Case #" << t << ": Y" << endl;
		else
			fout << "Case #" << t << ": N" << endl;
	}

	fin.close();
	fout.close();
}
