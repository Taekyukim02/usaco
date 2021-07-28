#include <iostream>
#include <vector>
#include <map>
using namespace std;

int T[25000];
map <int,int> rToR;
int N, K, S;
int spots[100000];
int rel[25000];
int first[27];

void updateRel(int idx) {
	rToR.clear();
	for(int i=1; i<=S; i++)
		if(first[i] != -1 && first[i] < T[idx])  // then add this into the mapping
			rToR[ rel[idx-T[idx]+1+first[i]] ] = i;
}

bool validRel(int idx) {

		for(int j=1; j<=3; j++) {
			if(rToR.find(j) != rToR.end())
			cout << "rTR at " << j << " set to " << rToR[j] << endl;
			else
			cout << "rTR at " << j << " not set " << endl;
		}
		cout << endl;
	if( rToR.find(rel[idx+1]) == rToR.end() ) {		// new relative index
		rToR[rel[idx+1]] = rel[ T[idx]];

		// check if valid mapping
		for(int i=1; i<=S; i++)
			if(rToR.find(i) != rToR.end())
				if( (i<rel[idx+1] && rToR[i] > rToR[rel[idx+1]])
						|| (i<rel[idx+1] && rToR[i] > rToR[rel[idx+1]]) )
					return false;

		// is valid mapping
	} else {										// index already found
		if(rToR[ rel[idx+1]] != rToR[ rel[T[idx]]])
			return false;
	}
	return true;
}

int main()
{
    cin >> N >> K >> S;

    for(int i=0; i<N; i++) {
        cin >> spots[i];
    }

    for(int i=0; i<K; i++) {
        cin >> rel[i];
    }

    // find index to first relative number in the pattern
    for(int i=1; i<=S; i++) {
        first[i] = -1;
        int index = 0;
        while(index < K) {
            if(rel[index] != i)
                index++;
            else {
                first[i] = index;
                break;
            }
        }
    }

    // Create T[] for pattern array
    T[0] = 0;
	rToR[rel[0]] = rel[0];
    for(int i=1; i<K; i++) {
        int idx = i-1;
        while(idx != 0 && !validRel(idx)) {
            idx = T[idx];
			updateRel(idx);
			cout << "update" << endl;
		}
        T[i] = T[idx]+1;
    }

     // debug
    for(int i=0; i<K; i++)
        cout << T[i] << " ";
    cout << endl;
    return 0;
    
/*

    // iterate through all cows
    int startIndex = 0;     // first cow of pattern-checking
    int checkIndex = 0;     // cow we are on in the actual string
    map <int, int> relToActual;
    vector <int> result;            // contains answers (startIndices)
    while(checkIndex < N) {
		cout << startIndex << checkIndex << endl;
		for(int i=1; i<=S; i++) {
			if(relToActual.find(i) != relToActual.end())
			cout << "rTA at " << i << " set to " << relToActual[i] << endl;
			else
			cout << "rTA at " << i << " not set " << endl;
		}
		cout << endl;

        int pIndex = checkIndex-startIndex;
        if(relToActual.find( rel[pIndex] ) != relToActual.end()) {
            if(relToActual[ rel[pIndex] ] == spots[checkIndex])
                checkIndex++;
            else if(checkIndex == startIndex) {
                startIndex++;
                checkIndex++;
            } else {
                // move startIndex and update relToActual
                startIndex = checkIndex-T[pIndex-1];
                pIndex = checkIndex-startIndex;

                relToActual.clear();
                for(int i=1; i<=S; i++) {
                    if(first[i] != -1 && first[i] <= pIndex-1)
                        relToActual[i] = spots[ startIndex + first[i] ];
                }
            }
        } else {
            relToActual[ rel[pIndex] ] = spots[checkIndex];
            // check validity of new rel
            bool isGood = true;
            for(int i=1; i<=S; i++)
                if(relToActual.find(i) != relToActual.end() )
                    if((i < rel[pIndex]
                            && relToActual[i] > relToActual[ rel[pIndex] ])
                        || (i > rel[pIndex]
                            && relToActual[i] < relToActual[ rel[pIndex] ]))
                        isGood = false;
            if(!isGood) {
                // move startIndex and update relToActual
                startIndex += pIndex-T[pIndex-1];
                pIndex = checkIndex-startIndex;

                relToActual.clear();
                for(int i=1; i<=S; i++) {
                    if(first[i] != -1 && first[i] <= pIndex-1)
                        relToActual[i] = spots[ startIndex + first[i] ];
                }
            } else
                checkIndex++;
        }

        // full pattern reached
        if(checkIndex-startIndex == K) {
            result.push_back(startIndex+1);

			cout << relToActual[1] << " "<< relToActual[2] << " "<< relToActual[3] << endl; 

			startIndex += pIndex-T[pIndex-1];
			pIndex = checkIndex-startIndex;
			relToActual.clear();
			for(int i=1; i<=S; i++) {
				if(first[i] != -1 && first[i] <= pIndex-1)
					relToActual[i] = spots[ startIndex + first[i] ];
			}
        }
    }

    cout << result.size() << endl;
    for(int a : result)
        cout << a << endl;

    return 0;
	*/
}
