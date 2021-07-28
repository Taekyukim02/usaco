#include <iostream>
#include <string>

using namespace std;

string str;
int t[3000000], o[3000000], c[3000000];

void init(int l, int r, int node) {
	if(l==r) {
		t[node] = 0;
		if(str[l] == '(') {
			o[node] = 1;
			c[node] = 0;
		}
		else {
			o[node] = 0;
			c[node] = 1;
		}
		return;
	}
	int mid = (l+r)/2;
	init(l, mid, node*2);
	init(mid+1, r, node*2+1);

	int add = min(o[2*node], c[2*node+1]);
	t[node] = t[2*node] + t[2*node+1] + add;
	o[node] = o[2*node] + o[2*node+1] - add;
	c[node] = c[2*node] + c[2*node+1] - add;

	return;
}

struct pnt{
	int t, o, c;
	pnt(int x, int y, int z) {
		t = x;
		o = y;
		c = z;
	}
};

pnt get(int q1, int q2, int l, int r, int node) {
	if(q1>q2 || l>q2 || r<q1 || l>r)
		return pnt(0, 0, 0);
	if(l >= q1 && r <= q2)
		return pnt(t[node], o[node], c[node]);
	int mid = (l+r)/2;
	pnt a = get(q1, q2, l, mid, 2*node);
	pnt b = get(q1, q2, mid+1, r, 2*node+1);
	int tmp = min(a.o, b.c);
//	cout << l << " to " << r << "   " << a.t+b.t+tmp << " " << a.o+b.o-tmp << " " << a.c+b.c-tmp << endl;
	return pnt(a.t+b.t+tmp, a.o+b.o-tmp, a.c+b.c-tmp);
}

int main() {
	int N;
	cin >> str;
	N = str.length();

	init(0, N-1, 1);

//	for(int i=0; i<3*N; i++)
//		cout << i << " " << t[i] << " " << o[i] << " " << c[i] << endl;

	int M;
	cin >> M;
	for(int i=0; i<M; i++) {
		int l, r;
		cin >> l >> r;
		cout << 2*get(l-1,r-1,0,N-1,1).t << endl;
	}

	return 0;
}
