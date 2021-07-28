#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <queue>

#define MAX_N 200005
#define MAX_Q 200005

using namespace std;

void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

int N, Q;
priority_queue <int> queue1;
int arr[MAX_N];
int cnt1[MAX_Q], cnt2[MAX_Q];
bool seenQ = false, seen0 = false;

int main() {
    fastscan(N);
    fastscan(Q);
    for(int i=0; i<N; i++) {
        fastscan(arr[i]);
        if (i > 0)
            cnt2[arr[i]]++;
        if (arr[i] == Q)
            seenQ = true;
        if (arr[i] == 0)
            seen0 = true;
    }

    // check if possible
    for(int i=1; i<N-1; i++) {
        // update cnt1[], cnt2[]
        cnt1[arr[i-1]]++;
        cnt2[arr[i]]  --;
        if(cnt1[arr[i-1]] == 1 && cnt2[arr[i-1]] > 0)
            queue1.push(arr[i-1]);

        // check queue
        int f = (queue1.empty() ? -1 : queue1.top());
        while(!queue1.empty() && cnt2[f] == 0) {
            queue1.pop();
            f = (queue1.empty() ? -1 : queue1.top());
        }

        // check validity
        if(arr[i] != 0 && !queue1.empty() && f > arr[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    // edge case
    if(!seenQ && !seen0) {
        cout << "NO" << endl;
        return 0;
    }


    // print corresponding array
    cout << "YES\n";
    int prev = 1;
    if(!seenQ)
        prev = Q;

    for(int i=0; i<N; i++) {
        if(arr[i] == 0) {
            cout << prev << " ";
            if(!seenQ)
                seenQ = true;
        } else {
            cout << arr[i] << " ";
            if(seenQ)
                prev = arr[i];
        }
    }
    cout << endl;
}