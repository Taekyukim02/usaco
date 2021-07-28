#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <algorithm>

#define MAX_N 100005

using namespace std;

void fastscan(long long &number)
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

long long N;
long long a[MAX_N], b[MAX_N];
long long arr[MAX_N];

int main() {
    fastscan(N);
    for(int i=0; i<N; i++) {
        fastscan(a[i]);
        fastscan(b[i]);
    }

    long long ans = 0;
    for(int i=0; i<N; i++) {
        ans += b[i]*N - a[i];
        arr[i] = a[i] - b[i];
    }

    sort(arr, arr+N);

    for(int i=0; i<N; i++) {
        ans += arr[i] * (N-i);
    }

    cout << ans << endl;
}