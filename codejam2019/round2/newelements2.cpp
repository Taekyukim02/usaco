#include <iostream>

using namespace std;

long long T, N, C[10], J[10];

int main() {
    cin >> T;
    for(int ii=0; ii<T; ii++) {
        cin >> N;
        for(int i=0; i<N; i++) {
            cin >> C[i] >> J[i];
        }

        double m1 = 1.0;
        bool imp1 = false;
        for(int i=0; i<N-1; i++) {
            if(C[i] > C[i+1] && J[i+1] > J[i])
                m1 = min(m1, ((double) J[i+1] - J[i])/(C[i] - C[i+1]));
            if(J[i+1] <= J[i] && C[i+1] <= C[i])
                imp1 = true;
            if(J[i+1] <= J[i] && C[i+1] > C[i] || C[])
        }
    }
}