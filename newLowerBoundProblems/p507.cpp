#include <iostream>

using namespace std;

int N, arr[20005];

int main() {
    int TC;
    cin >> TC;
    for(int t=1; t<=TC; t++) {
        cin >> N;
        for(int i=0; i<N-1; i++)
            cin >> arr[i];

        int ans = 0, curr = 0, bL, bR, left = 0, right = 0;
        for(int i=0; i<N-1; i++) {
            curr += arr[i];
            right = i;
            if(curr < 0) {
                curr = 0;
                left = right = i+1;
            }
            if(curr > ans || (curr == ans && bR-bL < right-left)) {
                ans = curr;
                bL = left;
                bR = right;
            }
        }

        if(ans > 0)
            cout << "The nicest part of route " << t
                 << " is between stops " << bL+1 << " and " << bR+2 << endl;
        else
            cout << "Route " << t << " has no nice parts" << endl;
    }
}