/*
ID: taekyuk1
TASK: dualpal
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string changeBase(int N, int b)
{
	if(N==0) return "";

	int x = N%b;
	char c;
	if(x < 10) c = (char) ('0' + x);
	else	   c = (char) ('A' + x-10);
	return changeBase(N/b, b) + c;
}

bool isPalin(string N)
{
	for(int i=0; i<N.length(); i++)
		if(N[i] != N[N.length()-i-1])
			return false;
	return true;
}

int main()
{
	ifstream fin ("dualpal.in");
	ofstream fout ("dualpal.out");

	int N, S;
	fin >> N >> S;

	int numFound = 0;
	int tryNum = S+1;
	while(numFound < N) {
		bool isPalinInOne = false;
		for(int b = 2; b<=10; b++) {
			string str = changeBase(tryNum, b);
			if(isPalin(str)) {
				if(isPalinInOne) {
					fout << tryNum << endl;
					numFound++;
					break;
				} else
					isPalinInOne = true;
			}
		}
		tryNum++;
	}
	return 0;
}
