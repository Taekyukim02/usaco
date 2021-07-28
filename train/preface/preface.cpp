/*
ID: taekyuk1
TASK: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#define MAX_N 3501

using namespace std;

int a, b, c, d, e, f, g;

int main() {
	// read input
	ifstream fin ("preface.in");
	int N;
	fin >> N;
	fin.close();

	// dp
	int I[MAX_N], V[MAX_N], X[MAX_N], L[MAX_N], C[MAX_N], D[MAX_N], M[MAX_N];
	I[0] = 0;
	I[1] = 1;
	I[2] = 2;
	I[3] = 3;
	I[4] = 1;
	I[5] = 0;
	I[6] = 1;
	I[7] = 2;
	I[8] = 3;
	I[9] = 1;

	V[0] = 0;
	V[1] = 0;
	V[2] = 0;
	V[3] = 0;
	V[4] = 1;
	V[5] = 1;
	V[6] = 1;
	V[7] = 1;
	V[8] = 1;
	V[9] = 0;

	X[0] = 0;
	X[1] = 1;
	X[2] = 2;
	X[3] = 3;
	X[4] = 1;
	X[5] = 0;
	X[6] = 1;
	X[7] = 2;
	X[8] = 3;
	X[9] = 1;

	L[0] = 0;
	L[1] = 0;
	L[2] = 0;
	L[3] = 0;
	L[4] = 1;
	L[5] = 1;
	L[6] = 1;
	L[7] = 1;
	L[8] = 1;
	L[9] = 0;

	C[0] = 0;
	C[1] = 1;
	C[2] = 2;
	C[3] = 3;
	C[4] = 1;
	C[5] = 0;
	C[6] = 1;
	C[7] = 2;
	C[8] = 3;
	C[9] = 1;

	D[0] = 0;
	D[1] = 0;
	D[2] = 0;
	D[3] = 0;
	D[4] = 1;
	D[5] = 1;
	D[6] = 1;
	D[7] = 1;
	D[8] = 1;
	D[9] = 0;

	M[0] = 0;
	M[1] = 1;
	M[2] = 2;
	M[3] = 3;

	for(int i=1; i<=N; i++) {
		int x = i;
		a += I[x%10];
		b += V[x%10];
		if(x%10 == 9)
			c += 1;
		x /= 10;
		c += X[x%10];
		d += L[x%10];
		if(x%10 == 9)
			e += 1;
		x /= 10;
		e += C[x%10];
		f += D[x%10];
		if(x%10 == 9)
			g += 1;
		x /= 10;
		g += M[x%10];

		cout << i << " " << a << " " << b << " " << c << endl;
	}

	ofstream fout ("preface.out");
	if(g > 0)
		fout << "I " << a << endl << "V " << b << endl << "X " << c << endl << "L " << d << endl << "C " << e << endl << "D " << f << endl << "M " << g << endl;
	else if(f > 0)
		fout << "I " << a << endl << "V " << b << endl << "X " << c << endl << "L " << d << endl << "C " << e << endl << "D " << f << endl;
	else if(e > 0)
		fout << "I " << a << endl << "V " << b << endl << "X " << c << endl << "L " << d << endl << "C " << e << endl;
	else if(d > 0)
		fout << "I " << a << endl << "V " << b << endl << "X " << c << endl << "L " << d << endl;
	else if(c > 0)
		fout << "I " << a << endl << "V " << b << endl << "X " << c << endl;
	else if(b > 0)
		fout << "I " << a << endl << "V " << b << endl;
	else if(a > 0)
		fout << "I " << a << endl;
	fout.close();

	return 0;
}
