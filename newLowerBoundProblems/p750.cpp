#include <iostream>
#include <iomanip>

using namespace std;

int N, a, b, cnt;
int arr[8];

bool valid_square(int x, int y, int n) {
    for(int i=0; i<n; i++) {
        if(arr[i] == y || arr[i] - i == y - x || arr[i] + i == x + y)
            return false;
    }

    return true;
}

int it(int n) {
    if(n == a && arr[a-1] != b-1) return 0;

    if(n == 8) {
        cnt++;
        cout << setw(2) << setfill(' ') << cnt << "     ";

        for(int i=0; i<8; i++) {
            cout << " " << arr[i] + 1;
        }
        cout << endl;
        return 0;
    }


    for(int i=0; i<8; i++) {
        if(valid_square(n, i, n)) {
            arr[n] = i;
            it(n+1);
        }
    }

    return 0;
}

int main() {
    cin >> N;
    while(N--) {
        cnt = 0;
        cin >> b >> a;
        cout << "SOLN       COLUMN\n"
             << " #      1 2 3 4 5 6 7 8\n" << endl;
        it(0);

        if(N > 0)
            cout << endl;
    }
}