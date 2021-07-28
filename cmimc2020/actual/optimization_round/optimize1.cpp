#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_N 8
#define MAX_M 40000

using namespace std;

long long primes[MAX_M];
vector<long long> ans[MAX_N];

void generate(int index, int i, int M, int currM, vector<long long> generators[]) {
	if(i >= generators[index].size()) {
		ans[index].push_back(currM);
		return;
	}
	long long p = generators[index][i];
	long long nextM = currM;
	while(nextM <= M) {
		generate(index, i+1, M, nextM, generators);
		nextM *= p;
	}
	return;
}



int main() {
	int test_case;
	cin >> test_case;
	ifstream fin ("uniqueproducts" + to_string(test_case) + ".txt");
	ofstream fout ("OUTPUT_uniqueproducts.txt");

	// Generate primes
	long long num_primes = 0;

	for(int i=2; i<=MAX_M; i++) {
		bool prime_yes = true;
		for(int j=2; j<i; j++) {
			if(i % j == 0) {
				prime_yes = false;
				break;
			}
		}
		if(prime_yes) {
			primes[num_primes] = i;
			num_primes ++;
		}
	}
	
	// Read input data
	long long T, N, M;
	T = 1;
	
	// For each test case, run:
	for(long long t = 1; t <= T; t++) {
		// Read rest of data
		fin >> N >> M;

		// Algorithm:
		double s = 0;
		for(int i = 0; i < num_primes && primes[i] <= M; i++) {
			s += log(M)/log(primes[i]);
		}
		s /= N;

//		cout << s << endl;

		vector<long long> generators[MAX_N];
		long long index = 0;
		for(int i = 0; i < num_primes && primes[i] <= M; i++) {
			double curr_sum = 0;
			while(curr_sum < s && i < num_primes && primes[i] <= M) {
				generators[index % N].push_back(primes[i]);
				i++;
				curr_sum += log(M)/log(primes[i]);
			}
			index ++;
		}


		for(int index = 0; index < N; index ++) {
			generate(index, 0, M, 1, generators);
			long long k = 99999999;
		}

/*
		// debug
		for(int i=0; i<N; i++) {
			for(int j=0; j<generators[i].size(); j++) {
				cout << generators[i][j] << " ";
			}
			cout << endl;
		}
		*/


		// Output:
		long long k = 99999999;
		for(int i=0; i<N; i++) {
//			cout << "ans " << ans[i].size() << " " << endl;
			if(k > ans[i].size())
				k = ans[i].size();
		}


		for(int i=0; i<N; i++) {
			for(int j=0; j<k; j++) {
				fout << ans[i][j] << " ";
			}
			fout << "\n";
		}
	}
}

// Note: 
//	use long long, NOT int
// 	3 problems for 3 hours.
// 	brute force first, then discuss with others
