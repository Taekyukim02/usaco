/*
ID: taekyuk1
TASK: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, B, D;

// returns hamming distance of two integers
int hDist(int x, int y) {
	int count = 0;
	for(int z=1; z< (1<<B); z*=2)
		if((z&x) != (z&y))
			count++;
	return count;
}

int main() {
	ifstream fin ("hamming.in");
	fin >> N >> B >> D;
	fin.close();

	// generate all possible numbers
	vector <int> num;
	for(int i=0; i< (1<<B); i++)
		num.push_back(i);

	// go through list every time and eliminate things
	for(int i=0; i<N; i++) {
		for(int j=i+1; j<num.size();) {
			if(hDist( num[i], num[j]) < D)
				num.erase(num.begin() + j);
			else
				j++;
		}
	}

	// print numbers
	ofstream fout ("hamming.out");
	for(int i=0; i<N; i++) {
		if(i!=N-1)
			if((i+1)%10)
				fout << num[i] << " ";
			else
				fout << num[i] << endl;
		else
			fout << num[i] << endl;
	}
	return 0;
}
