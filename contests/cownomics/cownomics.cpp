#include <iostream>
#include <fstream>
#include <map>
#define MOD 1000000009ll
#define prime 31ll

using namespace std;

int N, M;
char spot[500][500], nospot[500][500];
long long hsh[500][500][2];
long long powr[500];

long long get_spot(long long x, long long i, long long j) {
	if(i > 0)
		return (hsh[x][j][0] - hsh[x][i-1][0] + MOD) % MOD;
	return hsh[x][j][0];
	//    return ((((hsh[x][j][0] - (i == 0 ? 0 : hsh[x][i - 1][0]) * powr[j - i + 1]) + MOD) % MOD + MOD) % MOD);
}

long long get_nospot(long long x, long long i, long long j) {
	if(i > 0)
		return (hsh[x][j][1] - hsh[x][i-1][1] + MOD) % MOD;
	return hsh[x][j][1];
	//    return ((((hsh[x][j][1] - (i == 0 ? 0 : hsh[x][i - 1][1]) * powr[j - i + 1]) + MOD) % MOD + MOD) % MOD);
}

void makeHash() {
    powr[0] = 1;
    for(int i=1; i<500; i++)
        powr[i] = powr[i-1] * prime % MOD;
    
    for(int i=0; i<N; i++) {
        hsh[i][0][0] = spot[i][0];
        for(int j=1; j<M; j++) {
            hsh[i][j][0] = (hsh[i][j-1][0] + (powr[j] * spot[i][j] %MOD)) % MOD;    
        }
    }
        
    for(int i=0; i<N; i++) {
        hsh[i][0][1] = nospot[i][0];
        for(int j=1; j<M; j++) {
            hsh[i][j][1] = (hsh[i][j-1][1] + (powr[j] * nospot[i][j] %MOD)) % MOD;    
        }
    }
}

int main() {
    ifstream fin ("cownomics.in");
    fin >> N >> M;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            fin >> spot[i][j];
        
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            fin >> nospot[i][j];
    
    fin.close();
    
    makeHash();
    
    // binary search
    int l = 1;
    int h = M;
    
    while(l<h) {
        int mid = (l+h)/2;
        
        bool goodA = false;
        for(int i=0; i+mid-1<M; i++) {
            map <long long, int> mp;
            for(int j=0; j<N; j++) {
                mp[get_spot(j, i, i+mid-1)] = 1;
            }
        
            bool good = true;
            for(int j=0; j<N; j++) {
                if(mp.find( get_nospot(j, i, i+mid-1)) != mp.end()) {
                    good = false;
					break;
				}
            }
            if(good) {
                goodA = true;
                break;
            }
        }
        
        if(goodA) {
            h = mid;
		}
        else
            l = mid+1;
    }
    
    // print output
    ofstream fout ("cownomics.out");
    fout << l << endl;
    fout.close();
    return 0;
}
