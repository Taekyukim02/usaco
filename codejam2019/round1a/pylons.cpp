#include <iostream>

using namespace std;

int T, R, C, lastx, lasty;
bool reversed;
bool vis[6];

void fll(int r, int c) {
    lastx = r;
    lasty = c;

    if(reversed)
        cout << c << " " << r << endl;
    else
        cout << r << " " << c << endl;

    if(r+1 <= R && c-2 >= 1) {
        fll(r+1, c-2);
    } else {
        int newr = r;
        int newc = c+1;
        while(newr-1 >= 1 && newc+2 <= C) {
            newr = newr - 1;
            newc = newc + 2;
        }
        if(newr != R)
            fll(newr, newc);
    }
}

int main() {
    cin >> T;
    for(int i=1; i<=T; i++) {
        for(int j=0; j<6; j++)
            vis[j] = false;

        cin >> R >> C;

        cout << "Case #";
        cout << i;
        cout << ": ";
        if(R <= 4 && C <= 4 && !(R == 4 && C == 4)) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
            reversed = false;
            if(R > C) {
                reversed = true;
                int temp = R;
                R = C;
                C = temp;
            }

            fll(1, 3);

            if(R - C + 2 == 0) {
                if(!reversed) {
                    cout << "1 2" << endl;
                    cout << R << " " << C << endl;
                    cout << "1 1" << endl;
                    cout << R << " " << C - 1 << endl;
                } else {
                    cout << "2 1" << endl;
                    cout << C << " " << R << endl;
                    cout << "1 1" << endl;
                    cout << C - 1 << " " << R << endl;
                }
            } else if(R - C + 1 == 0) {
                if(!reversed) {
                    cout << "1 2" << endl;
                    cout << R << " " << C-1 << endl;
                    cout << "1 1" << endl;
                    cout << R << " " << C << endl;
                } else {
                    cout << "2 1" << endl;
                    cout << C-1 << " " << R << endl;
                    cout << "1 1" << endl;
                    cout << C << " " << R << endl;
                }
            } else {
                if(!reversed) {
                    cout << "1 1" << endl;
                    cout << R << " " << C-1 << endl;
                    cout << "1 2" << endl;
                    cout << R << " " << C << endl;
                } else {
                    cout << "1 1" << endl;
                    cout << C-1 << " " << R << endl;
                    cout << "2 1" << endl;
                    cout << C << " " << R << endl;
                }
            }
        }
    }
}