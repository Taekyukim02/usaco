#include <iostream>

using namespace std;

int main() {
	int N, M, g[100];
	cin >> N >> M;
	for(int i=0; i<M; i++)
		cin >> g[i];
	
	int cpy[100];
	for(int i=0; i<M; i++)
		cpy[i] = g[i];
	int remaining = M-1;
	while(remaining>1) {

		// find two maxes
		int id1=1, id2=-1;
		for(int i=1; i<M; i++) {
			if(cpy[i] > cpy[id1])
				id1 = i;
		}
		for(int i=1; i<M; i++) {
			if((id2 == -1 && i!=id1) || (id2!=-1 && i!=id1 && cpy[i] > cpy[id2]))
				id2 = i;
		}

		cpy[id1]--;
		cpy[id2]--;
		if(!cpy[id1]) remaining--;
		if(!cpy[id2]) remaining--;
	}
	
	int r;
	for(int i=1; i<M; i++)
		if(cpy[i] > 0)
			r = cpy[i];
	
	if(r>=g[0]) {
		cout << "NO" << endl;
		return 0;
	}
	else {
		cout << "YES" << endl;
		cout << g[0] - r << endl;
	}

	/*	------------------------------  */

	if(M==2) {
		for(int i=0; i<M; i++)
			for(int j=0; j<g[i]; j++)
				cout << i+1 << endl;
		return 0;
	}

	/*  ------------------------------  */

	for(int i=0; i<M; i++)
		cpy[i] = g[i];
	cpy[0] = r;

	int numField = 0;
	int idField = 0;
	int s = 0;
	for(int i=N-g[0]+r; i>0;i-=2) {
		if(numField == 0) {
			for(; s<M; s++)
				if(cpy[s] > 0)
					break;
			for(int i=0; i<cpy[s]; i++) {
				cout << s+1 << endl;
				idField = s;
				numField++;
			}
			cpy[s] = 0;
		}

/*
		cout << "i: " << i << endl;
		cout << numField << " " << idField << endl;
		for(int j=0; j<M; j++)
			cout << cpy[j] << " ";		// debug
			cout << endl;
*/
		int m=0, id;
		for(int j=0; j<M; j++)
			if(m < cpy[j]) {
				id = j;
				m = cpy[j];
			}

		if(2*m <= (i-1)) {		// no majority after picking first one
			bool p = false;
			id = 0;
			while(!p) {
				if(cpy[id] > 0) {
					cout << id+1 << endl;
					cpy[id]--;
					p = true;
				}
				id++;
			}
		}
		else {
			cout << id+1 << endl;
			cpy[id]--;
		}
		numField--;
	}

	for(int i=0; i<g[0]-r; i++)
		cout << 1 << endl;

	return 0;
}
