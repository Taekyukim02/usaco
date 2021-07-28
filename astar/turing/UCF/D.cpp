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

typedef pair<char, int> ii;

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
ii a[7];
ii b[7];
int cnt1[26];
int cnt2[26];
int count1[26][256];
int count2[26][256];

int main() {
    for(int i=0; i<5; i++) {
        cin >> a[i].f;
        b[i].f = a[i].f;
    }
    for(int i=0; i<5; i++) {
        string c;
        cin >> c;
        switch(c) {
            case "A":
                a[i].s = 1;
                break;
            case "2":
                a[i].s = 2;
                break;
            case "3":
                a[i].s = 3;
                break;
            case "4":
                a[i].s = 4;
                break;
            case "5":
                a[i].s = 5;
                break;
            case "6":
                a[i].s = 6;
                break;
            case "7":
                a[i].s = 7;
                break;
            case "8":
                a[i].s = 8;
                break;
            case "9":
                a[i].s = 9;
                break;
            case "10":
                a[i].s = 10;
                break;
            case "J":
                a[i].s = 11;
                break;
            case "Q":
                a[i].s = 12;
                break;
            case "K":
                a[i].s = 13;
                break;
        }

        b[i].s = a[i].s;
    }
    for(int i=5; i<7; i++) {
        cin >> a[i].f;
        string c;
        cin >> c;
        switch(c) {
            case "A":
                a[i].s = 1;
                break;
            case "2":
                a[i].s = 2;
                break;
            case "3":
                a[i].s = 3;
                break;
            case "4":
                a[i].s = 4;
                break;
            case "5":
                a[i].s = 5;
                break;
            case "6":
                a[i].s = 6;
                break;
            case "7":
                a[i].s = 7;
                break;
            case "8":
                a[i].s = 8;
                break;
            case "9":
                a[i].s = 9;
                break;
            case "10":
                a[i].s = 10;
                break;
            case "J":
                a[i].s = 11;
                break;
            case "Q":
                a[i].s = 12;
                break;
            case "K":
                a[i].s = 13;
                break;
        }
    }
    for(int i=5; i<7; i++) {
        cin >> b[i].f;
        string c;
        cin >> c;
        switch(c) {
            case "A":
                b[i].s = 1;
                break;
            case "2":
                b[i].s = 2;
                break;
            case "3":
                b[i].s = 3;
                break;
            case "4":
                b[i].s = 4;
                break;
            case "5":
                b[i].s = 5;
                break;
            case "6":
                b[i].s = 6;
                break;
            case "7":
                b[i].s = 7;
                break;
            case "8":
                b[i].s = 8;
                break;
            case "9":
                b[i].s = 9;
                break;
            case "10":
                b[i].s = 10;
                break;
            case "J":
                b[i].s = 11;
                break;
            case "Q":
                b[i].s = 12;
                break;
            case "K":
                b[i].s = 13;
                break;
        }
    }

    for(int i=0; i<7; i++) {
        cnt1[a[i].s]++;
        cnt1[a[i].s + 13]++;
        count1[a[i].s][a[i].f] ++;
        count1[a[i].s + 13][a[i].f] ++;
    }
    for(int i=0; i<7; i++) {
        cnt1[b[i].s]++;
        cnt1[b[i].s + 13]++;
        count1[b[i].s][b[i].f] ++;
        count1[b[i].s + 13][b[i].f] ++;
    }
    bool o1 = false;
    bool o2 = false;
    bool f1 = true;
    bool f2 = true;
    for(int i=10; i<=14; i++)
        if(count1[i]['S'] == false)
            f1 = false;
    o1 |= f1;
    f1 = true;
    for(int i=10; i<=14; i++)
        if(count1[i]['C'] == false)
            f1 = false;
    o1 |= f1;
    f1 = true;
    for(int i=10; i<=14; i++)
        if(count1[i]['D'] == false)
            f1 = false;
    o1 |= f1;
    f1 = true;
    for(int i=10; i<=14; i++)
        if(count1[i]['H'] == false)
            f1 = false;
    o1 |= f1;
    f1 = true;

    f2 = true;
    for(int i=10; i<=14; i++)
        if(count2[i]['S'] == false)
            f2 = false;
    o2 |= f2;
    f2 = true;
    for(int i=10; i<=14; i++)
        if(count2[i]['D'] == false)
            f2 = false;
    o2 |= f2;
    f2 = true;
    for(int i=10; i<=14; i++)
        if(count2[i]['C'] == false)
            f2 = false;
    o2 |= f2;
    f2 = true;
    for(int i=10; i<=14; i++)
        if(count2[i]['H'] == false)
            f2 = false;
    o2 |= f2;

    if(o1 && o2) {
        cout << "tie" << endl;
        return 0;
    }
    else if(o1) {
        
    }

    return (0);
}