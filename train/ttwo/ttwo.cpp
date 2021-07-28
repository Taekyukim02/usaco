/*
ID: taekyuk1
TASK: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

struct point{
	int x, y;
	int dir;
	point(int a, int b, int c) {
		x = a;
		y = b;
		dir = c;
	}
	point() {}
};


// manages the visited array for point structs
bool v[400][400];
bool visited(point p1, point p2) {
	return v[p1.x+p1.y*10+p1.dir*100]
			[p2.x+p2.y*10+p2.dir*100];
}

void markVisited(point p1, point p2) {
	v[p1.x+p1.y*10+p1.dir*100]
	 [p2.x+p2.y*10+p2.dir*100] = true;
}

char grid[10][10];
point move(point p) {
	point c = point(p.x, p.y, p.dir);
	switch(c.dir) {
		case 0: c.x--;
				break;
		case 1: c.y++;
				break;
		case 2: c.x++;
				break;
		case 3: c.y--;
				break;
	};

	if(c.x<0 || c.x>=10 || c.y<0 || c.y>=10 || grid[c.x][c.y] == '*') 
		p = point(p.x, p.y, (p.dir+1)%4);
	else
		p = c;
	
	return p;
}

int main() {
	ifstream fin ("ttwo.in");
	point p1, p2;
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++) {
			fin >> grid[i][j];
			if(grid[i][j] == 'C')
				p1 = point(i, j, 0);
			if(grid[i][j] == 'F')
				p2 = point(i, j, 0);
		}
	fin.close();
	
	int cnt = 0;
	//cout << "1: " << p1.x << " " << p1.y << " " << p1.dir << endl;
	//cout << "2: " << p2.x << " " << p2.y << " " << p2.dir << endl;
	while(!visited(p1, p2) && (p1.x!=p2.x || p1.y!=p2.y)) {
		markVisited(p1,p2);
		p1 = move(p1);
		p2 = move(p2);
		//cout << "1: " << p1.x << " " << p1.y << " " << p1.dir << endl;
		//cout << "2: " << p2.x << " " << p2.y << " " << p2.dir << endl;
		cnt++;
	}

	if(visited(p1, p2))
		cnt = 0;
	
	ofstream fout ("ttwo.out");
	fout << cnt << endl;
	fout.close();
}
