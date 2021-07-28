#include "grader.h"
#include <vector>
//#include <iostream>

#define MAX_N 100005
#define level 18

using namespace std;
/*
// debug
int grid[100][100];
int getN() {return 5;}
int getQ() {return 3;}

void setFarmLocation(int a, int b, int c) {
    grid[b][c] = a;
    cout << a << " at " << b << " " << c <<endl;
}

void addBox(int a, int b, int c, int d) {
    cout << a << " ";
    cout << b << " ";
    cout << c << " ";
    cout << d << endl;
}
*/

vector <int> G[MAX_N];
int locX[MAX_N];
int locY[MAX_N];

int depth[MAX_N];
int parent[MAX_N][level];

// pre-compute the depth for each node and their first parent
void dfs(int cur, int prev)
{
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (int i=0; i<G[cur].size(); i++)
    {
        if (G[cur][i] != prev)
            dfs(G[cur][i], cur);
    }
}

void precomputeLCA(int n)
{
    for (int i=1; i<level; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            if (parent[node][i-1] != -1)
                parent[node][i] =
                        parent[parent[node][i-1]][i-1];
        }
    }
}

// Returns the LCA of u and v
int lca(int u, int v)
{
    if (depth[v] < depth[u])
        swap(u, v);

    int diff = depth[v] - depth[u];

    for (int i=0; i<level; i++)
        if ((diff>>i)&1)
            v = parent[v][i];

    if (u == v)
        return u;

    for (int i=level-1; i>=0; i--)
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }

    return parent[u][0];
}

void addRoad(int a, int b){
    a++; b++;
    G[a].push_back(b);
    G[b].push_back(a);
}

int x,y;
void dfs2(int n, int p) {
    locX[n] = x++;
    for(int to : G[n]) {
        if(to != p) {
            dfs2(to, n);
        }
    }
    locY[n] = y--;
}

void buildFarms(){
    depth[0] = 0;
    dfs(1, 0);
    precomputeLCA(getN());

    x = 1;
    y = getN();
    dfs2(1, -10);

    for(int i=1; i<=getN(); i++) {
        setFarmLocation(i-1, locX[i], locY[i]);
    }
}

void notifyFJ(int a, int b) {
    a++; b++;
    int low = lca(a, b);
    if(low == a) {
        addBox(locX[low], locY[low], locX[b], locY[b]);
    } else if(low == b) {
        addBox(locX[low], locY[low], locX[a], locY[a]);
    } else {
        addBox(locX[low], locY[low], locX[b], locY[b]);
        addBox(locX[low]+1, locY[low]+1, locX[a], locY[a]);
    }
}
/*
int main() {
    addRoad(0, 1);
    addRoad(1, 2);
    addRoad(3, 1);
    addRoad(4, 0);
    buildFarms();

    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            cout << grid[i][j] << " \n"[j==9];

    notifyFJ(0, 1);
    notifyFJ(1, 2);
    notifyFJ(4, 2);
    cout << cnt << endl;
}*/