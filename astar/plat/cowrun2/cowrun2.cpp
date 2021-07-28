#include <iostream>
#include <cstdlib>

using namespace std;

long long N, M, K, currR;
string cows;
int cards[14][8];

bool bessie_move(int idx, long long R, int m1, int m2);

bool my_move(int idx, long long R, int move) {
	int random = rand() % 2;
	return bessie_move(idx, R, move, random)
			&& bessie_move(idx, R, move, 1-random);
}

bool bessie_move(int idx, long long R, int m1, int m2) {
	R = (R*cards[idx][m1*4+m2*2] % M + cards[idx][m1*4+m2*2+1]) % M;
	
	if(idx == N-1) {
		if(R <= K || R >= (M-K) )
			return true;
		return false;
	}

	int random = rand() % 2;
	return my_move(idx+1, R, 0) || my_move(idx+1, R, 1);
}

int main() {
	cin >> N >> M >> K;
	cin >> cows;

	for(int i=0; i<N; i++)
		for(int j=0; j<8; j++)
			cin >> cards[i][j];
	
	// algorithm
	string output = "";
	for(int i=0; i<N; i++) {
		if(my_move(i, currR, 1)) {
			output += "B";
			currR+=	currR*cards[i][4+2*(cows[i]=='B')]
						+ cards[i][4+2*(cows[i]=='B')+1];
			currR %= M;
		} else {
			output += "T";
			currR+=	currR*cards[i][2*(cows[i]=='B')]
						+ cards[i][2*(cows[i]=='B')+1];
			currR %= M;
		}
	}

	cout << output << endl;
}
