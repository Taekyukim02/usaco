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
int dx[8] = {1, 2, -1, -2, 1, -1, 2, -1};
int dy[8] = {2, 1, -2, -1, -2, 2, -1, 1};
int dX[8] = {-1, -1, -1, 0, 0, 1, 1};
int dY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
string str[]
int main() {
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> str[i];

    return (0);
}