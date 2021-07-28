#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <ctime>
#include <cstdlib>

#define MAX_N 10
#define MAX_M 80000

using namespace std;

long long primes[MAX_M];
vector<long long> best_ans[MAX_N];
long long bestk = -1;

vector<long long> ans[MAX_N];

void generate(int index, int i, long long M, long long currM, vector<long long> generators[]) {
	if(i >= generators[index].size()) {
		ans[index].push_back(currM);
//		cout << "added " << currM << " to " << index << endl;
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
	ofstream fout ("OUTPUT_uniqueproducts" + to_string(test_case) + ".txt");

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
	fin >> N >> M;
	srand (static_cast <unsigned> (time(0)));


	// For each test case, run:
	auto Start = std::chrono::high_resolution_clock::now();

	double s = 0;
	int ind;
	for(ind = 0; ind < num_primes && primes[ind] <= M; ind++) {
		s += log(M)/log(primes[ind]);
	}
	s /= N;
//	cout << s << endl;

	while(true) {
		auto End = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> Elapsed = End - Start;
			if (Elapsed.count() >= 1000 * 1000.0)
				break;


		//randomness
		random_shuffle(primes, primes+ind);
		double gamma = 1 + (double) rand()/RAND_MAX ;

		// Algorithm:
		vector<long long> generators[MAX_N];
		for(int i=0; i<N; i++) {
			ans[i].clear();
		}
		long long index = 0;
		for(int i = 0; i < num_primes && primes[i] <= M; i++) {
			double curr_sum = 0;
			while(gamma * curr_sum < s && i < num_primes && primes[i] <= M) {
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

		if(k > bestk) {
			bestk = k;
			for(int i=0; i<N; i++) {
				best_ans[i] = ans[i];
			}
		}
	}

	// Output:
	cout << "best k: " << bestk << endl;
	for(int i=0; i<N; i++) {
		for(int j=0; j<bestk; j++) {
			fout << best_ans[i][j] << " ";
		}
		fout << "\n";
	}
}

// Note: 
//	use long long, NOT int
// 	3 problems for 3 hours.
// 	brute force first, then discuss with others
