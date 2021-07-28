/*
ID: taekyuk1
TASK: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int input[1000];
	int given[3][3];
	int total[3];
	for(int i=0; i<3; i++)
		given[i][0] = given[i][1] = given[i][2] = total[i] = 0;

	int N;
	
	// read input
	ifstream fin("sort3.in");
	fin >> N;
	for(int i=0; i<N; i++) {
		fin >> input[i];
		total[input[i]-1]++;
	}
	fin.close();

	for(int i=0; i<N; i++) {
		if(i<total[0])
			given[0][input[i]-1]++;
		else if(i < total[0] + total[1])
			given[1][input[i]-1]++;
		else 
			given[2][input[i]-1]++;
	}

	int counter = 0;

	// sort 1's
	if(given[0][1] > 0 && given[1][0] > 0) {
		int change = min(given[0][1], given[1][0]);
		counter += change;
		given[0][1] -= change;
		given[1][0] -= change;
	}
	if(given[0][2] > 0 && given[2][0] > 0) {
		int change = min(given[0][2], given[2][0]);
		counter += change;
		given[0][2] -= change;
		given[2][0] -= change;
	}
	if(given[1][2] > 0 && given[2][1] > 0) {
		int change = min(given[1][2], given[2][1]);
		counter += change;
		given[1][2] -= change;
		given[2][1] -= change;
	}

	counter += (given[0][1] + given[0][2])*2;

	ofstream fout ("sort3.out");
	fout << counter << endl;
	fout.close();
}
