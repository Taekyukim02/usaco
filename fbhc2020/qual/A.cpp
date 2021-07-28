#include <iostream>
#include <fstream>

using namespace std;

char I[100], O[100];
char poss[100][100];

int main() {
	ifstream fin ("A.in");
	ofstream fout ("A.out");
	int T; fin >> T;
	for(int t=1; t<=T; t++) {
		int N;
		fin >> N;
		for(int i=0; i<N; i++)
			fin >> I[i];
		for(int i=0; i<N; i++)
			fin >> O[i];
		
		for(int i=0; i<100; i++)
			for(int j=0; j<100; j++)
				poss[i][j] = 'N';

		for(int i=0; i<100; i++)
			poss[i][i] = 'Y';

		for(int i=0; i<N-1; i++) {
			if(O[i] == 'Y' && I[i+1] == 'Y')
				poss[i][i+1] = 'Y';
			if(O[i+1] == 'Y' && I[i] == 'Y')
				poss[i+1][i] = 'Y';
		}

		for(int a=0; a<N; a++)
			for(int b=0; b<N; b++)
				for(int c=0; c<N; c++)
					if(poss[a][b] == 'Y' && poss[b][c] == 'Y')
						poss[a][c] = 'Y';
		
		fout << "Case #" << t << ":" << endl;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++)
				fout << poss[i][j];
			fout << endl;
		}
	}

	fin.close();
	fout.close();
}
