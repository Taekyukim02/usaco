#include <iostream>

using namespace std;

int T, N, M;
int arr[7] = {9, 17, 16, 5, 7, 13, 11};
int res[7];

int main() {
    cin >> T >> N >> M;
    for(int i=0; i<T; i++) {
        for(int j=0; j<7; j++) {
            for(int k=0; k<18; k++)
                cout << arr[j] << " ";
            cout << endl;

            res[j] = 0;
            int sum = 0, s;
            for(int k=0; k<18; k++) {
                cin >> s;
                sum += s;
            }

            res[j] = sum % arr[j];
        }

        for(int i=1; i<=M; i++) {
            int j;
            for(j=0; j<7; j++) {
                if(i % arr[j] != res[j])
                    break;
            }

            if(j == 7) {
                cout << i << endl;
                int a;
                cin >> a;
                if (a == -1)
                    return 0;
                break;
            }
        }
    }
}