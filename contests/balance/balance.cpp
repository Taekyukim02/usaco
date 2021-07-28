#include <iostream>
#include <fstream>

using namespace std;

int N;
long long f[100000];
double ans[100000];
bool visited[100000];

// returns index of unvisited element with maximum f value
int findMax() {
	int m = -1;
	for(int i=0; i<N; i++)
		if(!visited[i] && (m==-1 || f[m] < f[i]))
			m = i;
	return m;
}

int main() {
	ifstream fin ("balance.in");
	fin >> N;
	for(int i=0; i<N; i++) {
		fin >> f[i];
		f[i] *= 100000;
	}
	fin.close();

	// find minimum and update surrounding
	for(int i=0; i<N; i++) {
		int minIndex = findMax();
		if(f[minIndex] <= 0)
			break;
		
		// get answer and mark as done
		ans[minIndex] += f[minIndex];
		visited[minIndex] = true;

		// update neighbors
		if(minIndex > 0 && !visited[minIndex-1]) {
			f[minIndex-1] -= f[minIndex]/2;
			ans[minIndex-1] += f[minIndex]/2;
		}
		if(minIndex < N-1 && !visited[minIndex+1]) {
			f[minIndex+1] -= f[minIndex]/2;
			ans[minIndex+1] += f[minIndex]/2;
		}
	}

	// print output
	ofstream fout ("balance.out");
	for(int i=0; i<N; i++)
		fout << ans[i] << endl;
	fout.close();
}
