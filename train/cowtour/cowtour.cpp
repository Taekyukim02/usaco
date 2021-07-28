/*
ID: taekyuk1
TASK: cowtour
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <iomanip>
#define INF 100000000

using namespace std;

int N;
int locX[150], locY[150];
bool grid[150][150];
vector <int> fields[150];
bool visited[150];

double dist(int i, int j) {
	return sqrt((double) (locX[i]-locX[j])*(locX[i]-locX[j]) 
				+ (locY[i]-locY[j])*(locY[i]-locY[j]) );
}

void dfs(int i, int n) {
	if(visited[i]) return;
	visited[i] = true;
	fields[n].push_back(i);
	for(int j=0; j<N; j++) {
		if(grid[i][j])
			dfs(j, n);
	}
}

int main() {
	ifstream fin("cowtour.in");
	fin >> N;
	for(int i=0; i<N; i++)
		fin >> locX[i] >> locY[i];
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			char a;
			fin >> a;
			grid[i][j] = (int) (a-'0');
		}
	}
	fin.close();

	// get fields
	int numFields = 0;
	for(int i=0; i<N; i++) {
		if(!visited[i]) {
			dfs(i, numFields);
			numFields++;
		}
	}

	// run floyd-warshall to get optimal distances
	double opt[150][150];
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++) {
			if(grid[i][j])
				opt[i][j] = dist(i,j);
			else
				opt[i][j] = INF;
		}
	
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++) {
				if(opt[i][j] > opt[i][k] + opt[k][j])
					opt[i][j] = opt[i][k] + opt[k][j];
			}

	// get mDist for each pasture in each field
	double mDist[150];
	for(int i=0; i<N; i++) mDist[i] = 0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++)
			if(i!=j && opt[i][j] < INF && opt[i][j] > mDist[i])
				mDist[i] = opt[i][j];
	}

	// get diameters of each field
	double dia[150];
	for(int i=0; i<numFields; i++) {
		dia[i] = 0;
		for(int a : fields[i])
			if(dia[i] < mDist[a])
				dia[i] = mDist[a];
	}

	// try combining every pair of fields
	double m = 100000000;
	for(int i=0; i<numFields; i++) 
		for(int j=i+1; j<numFields; j++)
			for(int a : fields[i])
				for(int b : fields[j]) {
					m = min(m, max( max(dia[i],dia[j]), 
							  dist(a,b) + mDist[a] + mDist[b]) );
				}

	ofstream fout("cowtour.out");
	fout << fixed << setprecision(6) << m << endl;
	fout.close();
}
