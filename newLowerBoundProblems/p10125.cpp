#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1005];

int main() {
    int N;
    while(cin >> N) {
        if(N==0) return 0;

        for(int i=0; i<N; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + N);

        bool f = true;
        for(int a=N-1; a>=0 && f; a--) {
            for(int b=N-1; b>=2 && f; b--) {
                if(a == b) continue;

                for(int c=b-1; c>=1 && f; c--) {
                    if(a == c) continue;

                    long long target = arr[a] - arr[b] - arr[c];
                    if(target == arr[a]) continue;

                    int l = 0;
                    int r =  c-1;
                    while(l < r) {
                        int mid = (l+r)/2;
                        if(arr[mid] < target)
                            l = mid+1;
                        else
                            r = mid;
                    }
                    if(arr[l] == target) {
                        cout << arr[a] << endl;
                        f = false;
                    }
                }
            }
        }

        if(f == 1)
            cout << "no solution" << endl;
    }
}