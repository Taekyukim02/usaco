#include <iostream>

using namespace std;

long long Q, N, A, B;

int main() {
	cin >> Q;
	for(int i=0; i<Q; i++) {
		cin >> N >> A >> B;
		if(2*A <= B)
			cout << A*N << endl;
		else
			cout << A*(N%2) + B*(N/2) << endl;
	}
}
