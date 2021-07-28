/*
ID: taekyuk1
TASK: shopping
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#define INF 1000000000

using namespace std;

typedef pair<int,int> ii;

int main() {
	int s;
	vector <ii> offers[110];
	int price[110];
	ifstream fin ("shopping.in");
	fin >> s;
	for(int i=0; i<s; i++) {
		int n;
		fin >> n;
		for(int j=0; j<n; j++) {
			int a, b;
			fin >> a >> b;
			offers[i].push_back( ii(a,b) );
		}
		fin >> price[i];
	}
	int b;
	int c[5], k[5], p[5];
	for(int i=0; i<5; i++)
		c[i] = k[i] = p[i] = 0;

	fin >> b;
	for(int i=0; i<b; i++) {
		fin >> c[i] >> k[i] >> p[i];
		offers[s+i].push_back( ii(c[i], 1) );
		price[s+i] = p[i];
	}
	fin.close();
	
	int useK[110][5];
	for(int i=0; i<s+b; i++) {
		for(int j=0; j<5; j++)
			useK[i][j] = 0;

		if(i<s) {
			for(ii a : offers[i])
				for(int j=0; j<b; j++) 
					if(a.first == c[j])
						useK[i][j] = a.second;
		}
		else {
			useK[i][i-s] = 1;
		}
	}

	int dp[6][6][6][6][6];
	for(int a=0; a<6; a++)
	for(int y=0; y<6; y++)
	for(int z=0; z<6; z++)
	for(int d=0; d<6; d++)
	for(int e=0; e<6; e++)
		dp[a][y][z][d][e] = INF;
	
	dp[0][0][0][0][0] = 0;

	for(int i=0; i<s+b; i++) {
		for(int a=0; a<6; a++) {
			if(a+useK[i][0] > k[0]) break;
		for(int y=0; y<6; y++) {
			if(y+useK[i][1] > k[1]) break;
		for(int z=0; z<6; z++) {
			if(z+useK[i][2] > k[2]) break;
		for(int d=0; d<6; d++) {
			if(d+useK[i][3] > k[3]) break;
		for(int e=0; e<6; e++) {
			if(e+useK[i][4] > k[4]) break;

			dp[a+useK[i][0]][y+useK[i][1]][z+useK[i][2]]
				[d+useK[i][3]][e+useK[i][4]] = min(
			dp[a+useK[i][0]][y+useK[i][1]][z+useK[i][2]]
				[d+useK[i][3]][e+useK[i][4]], dp[a][y][z][d][e]
					+ price[i]);
		} } } } }
	}

//	for(int a=0; a<6; a++)
//	for(int y=0; y<6; y++)
//		cout << dp[a][y][0][0][0] << " \n"[y==5];

	int m = INF;
//	cout << k[0] << " " << k[1] << " " << k[2] << " " << k[3] << " " << k[4] << endl;
	for(int i=k[0]; i<6; i++)
	for(int j=k[1]; j<6; j++)
	for(int y=k[2]; y<6; y++)
	for(int l=k[3]; l<6; l++)
	for(int z=k[4]; z<6; z++)
		m = min(m, dp[i][j][y][l][z]);

	ofstream fout ("shopping.out");
	fout << m << endl;
	fout.close();

	return 0;
}
