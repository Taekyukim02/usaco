#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

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

int ar[MAX_N];
int N, M;
string str;
int v[MAX_N];

int main() {
    cin >> str;
    N = str.length();

    for(int i=0; i<N; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            v[i] = str[i] - 'A' + 1;
        }
        if(str[i] >= 'a' && str[i] <= 'z') {
            v[i] = str[i] - 'a' + 1;
        }
    }

    for(int i=0; i<N-1; i++) {
        v[i] += (26 - v[i+1]);
        v[i] = v[i] % 26;
        if(v[i] == 0) v[i] = 26;
    }

    string ans = "";
    for(int i=0; i<N; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            ans += (char) (v[i] + 'A' - 1);
        }
        if(str[i] >= 'a' && str[i] <= 'z') {
            ans += (char) (v[i] + 'a' - 1);
        }
    }
    cout << ans << endl;

    return (0);
}