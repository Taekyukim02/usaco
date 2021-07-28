/*
ID: taekyuk1
TASK: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

set <int> d;

bool checkNum(int N)
{
	int x = N%10;
	if(d.find(x) != d.end()) {
		if(N < 10)
			return true;
		else
			return checkNum(N/10);
	}
	return false;
}

int main()
{
	ifstream fin ("crypt1.in");
	ofstream fout ("crypt1.out");

	// read input
	int N;
	fin >> N;

	for(int i=0; i<N; i++) {
		int x;
		fin >> x;
		d.insert(x);
	}

	// try all possible cases
	int count = 0;
	for(int a : d) {
		if(a == 0) continue;
		for(int b : d) {
			for(int c : d) {
				for(int x : d) {
					if(x == 0) continue;
					for(int y : d) {
						int f = a*100 + b*10 + c;
						int s = x*10 + y;
						
						if(f*x>99 && f*x<1000 && f*y>99 && f*y <1000 && f*s>999 && f*s<10000 &&
							checkNum(f*x) && checkNum(f*y) && checkNum(f*s))

							count++;
					}
				}
			}
		}
	}

	fout << count << endl;
	return 0;
}
