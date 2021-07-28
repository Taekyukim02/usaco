#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int N, M;
char A[50000], B[50000];

int main() {
	// read input
	cin >> N >> M;
	int j=0;
	while(j<N) {
		string str;
		cin >> str;
		for(int i=0; i<str.length(); i++) {
			A[j] = str[i];
			j++;
		}
	}
	int j=0;
	while(j<M) {
		string str;
		cin >> str;
		for(int i=0; i<str.length(); i++) {
			B[j] = str[i];
			j++;
		}
	}


}
