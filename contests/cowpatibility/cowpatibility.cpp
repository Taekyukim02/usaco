#include <iostream>
#include <fstream>
#include <bitset>
#include <map>

using namespace std;

int N, fav[50000][5];
map <int, int> mp;
bitset <50000> bs[40000];

int main() {
	// read input
	ifstream fin ("cowpatibility.in");
	fin >> N;
	for(int i=0; i<N; i++) 
		for(int j=0; j<5; j++) {
			fin >> fav[i][j];
			mp[fav[i][j]] = 1;
		}
	fin.close();

	// coordinate compress
	int id = 0;
	for(auto it = mp.begin(); it != mp.end(); ++it) {
		it->second = id;
		id++;
	}

	// create bitset for every flavor
	for(int i=0; i<N; i++)
		for(int j=0; j<5; j++)
			bs[mp[fav[i][j]]].flip(i);

	/*
	for(int i=0; i<mp.size(); i++)
		cout << bs[i] << endl;
*/
	// for every cow, get the combined list of compatible cows and add the uncompatible ones
	long long total = 0;
	for(int i=0; i<N; i++)
		total += N - (bs[mp[fav[i][0]]] | bs[mp[fav[i][1]]] | bs[mp[fav[i][2]]] | bs[mp[fav[i][3]]] | bs[mp[fav[i][4]]] ).count();
	
	// return total/2
	ofstream fout ("cowpatibility.out");
	if(total%2) cout << "something went wrong" << endl;

	fout << total/2 << endl;
	fout.close();

	return 0;
}
