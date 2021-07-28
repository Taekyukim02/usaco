/*
ID: taekyuk1
TASK: ratios
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

struct trip {
	short x, y, z;
	trip(short a, short b, short c) {
		x = a;
		y = b;
		z = c;
	}
	trip() { trip(0, 0, 0); }

};

trip add(trip a, trip b) {
	return trip(a.x+b.x, a.y+b.y, a.z+b.z);
}

trip dp[100][100][100];
trip r[4];

int main() {
	ifstream fin ("ratios.in");
	for(int i=0; i<4; i++)
		fin >> r[i].x >> r[i].y >> r[i].z;
	fin.close();

	// dp
	trip ansid = dp[0][0][0] = trip();
	int m = 0;
	bool found = false;
	for(int s=1; s<=300; s++) {
		for(int a=0; a<100 && a<=s; a++) {
			for(int b=0; b<100 && a+b<=s; b++) {
				int c = s-a-b;
				if(a) dp[a][b][c] = add(dp[a-1][b][c], r[1]);
				else if(b) dp[a][b][c] = add(dp[a][b-1][c], r[2]);
				else if(c) dp[a][b][c] = add(dp[a][b][c-1], r[3]);

				if(r[0].x) m = dp[a][b][c].x / r[0].x;
				if(r[0].y) m = dp[a][b][c].y / r[0].y;
				if(r[0].z) m = dp[a][b][c].z / r[0].z;

				if(r[0].x*m == dp[a][b][c].x
					&& r[0].y*m == dp[a][b][c].y
					&& r[0].z*m == dp[a][b][c].z ) {
					ansid = trip(a, b, c);
					found = true;
					break;
				}
			}
			if(found) break;
		}
		if(found) break;
	}

	// output answer
	ofstream fout ("ratios.out");
	if(!ansid.x && !ansid.y && !ansid.z)
		fout << "NONE" << endl;
	else
		fout << ansid.x << " " << ansid.y << " " << ansid.z << " " << m << endl;
	fout.close();

	return 0;
}
