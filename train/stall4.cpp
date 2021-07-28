/*
ID: taekyuk1
TASK: stall4
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define MAX_N 205

using namespace std;

int N, M, k, l;
vector <int> barns[MAX_N];
int bestAns = -1;

int main() {
    ifstream fin ("stall4.in");
    fin >> N >> M;
    for(int i=1; i<=N; i++) {
        fin >> k;
        for(int j=0; j<k; j++) {
            fin >> l;
            barns[i].push_back(l);
        }
    }

    // brute-force search


    // print answer
    ofstream fout ("stall4.out");
    fout << bestAns << endl;
    fout.close();
}