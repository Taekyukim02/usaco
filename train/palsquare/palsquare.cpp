/*
ID: taekyuk1
TASK: palsquare
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
	ifstream fin ("palsquare.in");
	ofstream fout ("palsquare.out");

	int B;
	fin >> B;

	for(int i=1; i<=300; i++) {
		string baseB1 = changeBase(i, B);
		string baseB2 = changeBase(i*i, B);
		if(isPalin(baseB2))
			fout << baseB1 << " " << baseB2 << endl;
	}
	
	return 0;
}
