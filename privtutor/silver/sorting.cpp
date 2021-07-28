#include <iostream>
#define PI 3.14
#define MAX_N 100010
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;

int arr[MAX_N];

int main() {
	ii p1 = ii(1,2);
	iiii q1 = iiii(ii(1,2), ii(3,4));
	cout << "first number: " << p1.f << endl;
	cout << "second number: " << p1.s << endl;

	cout << q1.f.f << " " << q1.s.f;

	for(int i=0; i<MAX_N; i++)
		arr[i] = 0;
}
