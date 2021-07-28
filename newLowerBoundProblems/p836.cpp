#include <iostream>

using namespace std;

string arr[30];
int sum[30][30];

int sub(int x, int l, int r) {
    if(l > 0)
        return sum[x][r] - sum[x][l-1];
    return sum[x][r];
}

int main() {
    int TC; cin >> TC;
    while(TC--) {
        cin >> arr[0];
        for(int i=1; i<arr[0].length(); i++)
            cin >> arr[i];
        for(int i=0; i<arr[0].length(); i++) {
            sum[i][0] = arr[i][0] - '0';
            for(int j=1; j<arr[0].length(); j++)
                sum[i][j] = sum[i][j-1] + (arr[i][j] - '0');
        }

        int ans = 0, curr = 0;
        for(int l=0; l<arr[0].length(); l++)
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
        if(TC > 0) cout << endl;
    }
}