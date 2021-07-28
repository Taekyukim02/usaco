#include <iostream>

using namespace std;

int arr[160][160], sum[160][160];

int sub(int x, int l, int r) {
    if(l > 0)
        return sum[x][r] - sum[x][l-1];
    return sum[x][r];
}

int main() {
    int TC; cin >> TC;
    while(TC--) {
        int N;  cin >> N;
        for(int i=0; i<N; i++) {
            cin >> arr[i][0];
            arr[i][N] = arr[i+N][N] = arr[i+N][0] = arr[i][0];
            sum[i][0] = sum[i][N] = arr[i][0];
            for (int j = 1; j < N; j++) {
                cin >> arr[i][j];
            }
            for (int j = 1; j < 2*N; j++) {
                sum[i][j] = sum[i][j - 1] + arr[i][j];
                sum[i+N][j] = sum[i+N][j - 1] + arr[i+N][j];
            }
        }

        int ans = -987654321, curr = 0;
        for(int l=0; l<2*N; l++)
            for(int r=l; r<arr[0].length(); r++) {
                curr = 0;
                for(int i=0; i<arr[0].length(); i++) {
                    if(sub(i, l, r) == r-l+1) {
                        curr += r - l + 1;
                        if (curr > ans) ans = curr;
                    } else
                        curr = 0;
                }
            }

        cout << ans << endl;
    }
}