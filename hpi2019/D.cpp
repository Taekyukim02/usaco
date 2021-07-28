#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <string.h>

#define MAX_N 100005
#define MAX_M 100005
#define f first
#define s second

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

string str;

int N, M;

int main() {
	bool flag = false;

	str = readline();

		for (int i = 0; i < str.size(); i ++) {
			char c = str[i];
			int x = (int)(c - 'a');

			if ('a' <= c && c <= 'h')
				x += 3;
			else if ('i' <= c && c <= 'p')
				x = (x / 10 + x % 10) * 2;		
			else if ('q' <= c && c <= 'z')
				x %= 5;
			
			str[i] = (char)(x + 'a');
		}
	
		if (flag)
			cout << " " << str;
		else
			cout << str;

		flag = true;
	
	cout << endl;
	return (0);		
}

