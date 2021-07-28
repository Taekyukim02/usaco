#include <iostream>

#define f first
#define s second

using namespace std;

typedef pair <int, bool> ii;

int a, b;
int safe[105];
bool unsafe[105][105];
int H, W;
string grid[105];
ii vis[105][105];

// return number of new safe spots, (open == 1, not open == 0)
ii dfs(int h, int w, int minH) {
    if(grid[h][w] == 'X') return ii(0, 0);

    int cnt = 0;
    if(vis[h][w].f) return ii(0, vis[h][w].s);
    if(h < minH) return ii(0, 0);
    if(h >= H) return ii(0, 1);
    if(w < 0 || w >= W) return ii(0, 1);

    if(unsafe[h-1][w]) {
        unsafe[h][w] = true;
    }
    if(safe[h-1][w]) {
        int toR = w+1;
        while(toR < W && (grid[h-1][toR] == 'X' || safe[h-1][w] == safe[h-1][toR])) {
            if(safe[h-1][w] == safe[h-1][toR]) {

            }

            toR ++;
        }
    }

    // expand right
    ii r = dfs(h, w+1, minH);
    if() {}
}

int main() {
    cin >> H >> W;
    for(int i=0; i<H; i++)
        cin >> grid[i];

    int maxAnswer = 0;
    for(a=0; a<H; a++) {
        for(b=0; b<W; b++) {

            for(int i=0; i<105; i++) {
                for(int j=0; j<105; j++)
                    safe[i][j] = unsafe[i][j] = 0;

            for(int i=0; i<105; i++)
                for(int j=0; j<105; j++)
                    vis[i][j] = ii(0, 0);

            int cnt = 0;
            for(int h=H-1; h>=0; h--)
                for(int w=0; w<W; w++)
                    if(grid[h][w] == '.' && !(vis[h][w].f) && !(h==a && w==b)) {
                        cnt += dfs(h, w, h).f;
                    }
        }
    }

    cout << maxAnswer << endl;
}