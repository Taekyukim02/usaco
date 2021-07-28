#include <iostream>
#include <fstream>

using namespace std;

long long T, N, K, As, Bs, Cs, Ax, Bx, Cx, Ay, By, Cy;
long long Ds, Dx, Dy, S[1000010], X[1000010], Y[1000010];

long long mymax(long long a, long long b) {
	if(a > b) return a;
	return b;
}

int main() {
	ifstream fin  ("A.in");
	ofstream fout ("A.txt");

	fin >> T;
	for(int t=1; t<=T; t++) {
		// read input
		fin >> N >> K;
		for(int i=0; i<K; i++)
			fin >> S[i];
		fin >> As >> Bs >> Cs >> Ds;
		for(int i=0; i<K; i++)
			fin >> X[i];
		fin >> Ax >> Bx >> Cx >> Dx;
		for(int i=0; i<K; i++)
			fin >> Y[i];
		fin >> Ay >> By >> Cy >> Dy;
		
		// generate input
		
		for(int i=K; i<N; i++) {
			S[i] = (As * S[i-2] + Bs * S[i-1] + Cs) % Ds;
			X[i] = (Ax * X[i-2] + Bx * X[i-1] + Cx) % Dx;
			Y[i] = (Ay * Y[i-2] + By * Y[i-1] + Cy) % Dy;
		}

		// check if possible

		long long low = 0;
		long long high = 0;
		long long total = 0;
		for(int i=0; i<N; i++) {
			low += X[i];
			high += X[i] + Y[i];
			total += S[i];
		}
		
		if(total < low || high < total) {
			fout << "Case #" << t << ": -1" << endl;
			continue;
		}

		// if possible, check overflow and underflow
		
		long long under = 0;
		long long over = 0;

		for(int i=0; i<N; i++) {
			if(S[i] < X[i])
				under += X[i] - S[i];
			if(S[i] > X[i] + Y[i])
				over += S[i] - X[i] - Y[i];
		}

		fout << "Case #" << t << ": " << mymax(under, over) << endl;
	}

	fin.close();
	fout.close();
}
