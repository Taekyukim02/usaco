#include <iostream>

using namespace std;

int R, C;
int sum[8][8];
int walls[8][8];
int mask[] = {0, 1, 2, 4, 8,
			  3, 6, 12, 5, 10, 9,
			  14, 13, 11, 7, 15};

bool solve(int r, int c) {
	if(c >= C) {
		r++;
		c -= C;
	}
	if(r == R) {
		return true;
	}
	
	// actual filling now
	for(int i=0; i<16; i++) {
		if((mask[i] & walls[r][c]) == walls[r][c]) {
			// check perimeter condition
			if(r-1>=0 && c-1>=0) {
				if((walls[r-1][c-1] & 1) && !
			}

			// try the mask
			bool right=false, down=false;
			if(mask[i] & 1)
				right = true;
			if(mask[i] & 2)
				down = true;

			int prev = walls[r][c];
			walls[r][c] |= mark[i];
			if(right && c+1<C)
				walls[r][c+1] |= 4;
			if(down && r+1<R)
				walls[r+1][c] |= 8;

			solve(r, c+1);
			
			walls[r][c] = prev;
			if(right && c+1<C)
				walls[r][c+1] &= 15-4;
			if(down && r+1<R)
				walls[r+1][c] *= 15-8;
		}
	}
	return false;
}

int main() {
	cin >> R >> C;
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			cin >> sum[i][j];
	
	solve(0, 0);

	cout << getSum() << endl;
}
