#include <iostream>
#include <vector>

#define mp make_pair

using namespace std;

int n, m, k;
bool vis[310][310];
char g[310][310];

int ff(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= m || vis[r][c] || g[r][c] == '#') return 0;
    vis[r][c] = true;
    return ff(r - 1, c) + ff(r + 1, c) + ff(r, c - 1) + ff(r, c + 1) + 1;
}

int ff2(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= m || vis[r][c] || g[r][c] == '.') return 0;
    vis[r][c] = true;
    return ff2(r - 1, c) + ff2(r + 1, c) + ff2(r, c - 1) + ff2(r, c + 1) + 1;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; ++x) {
      cin >> n >> m >> k;
      for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) vis[i][j] = false;
      bool ans = true;
      vector<pair<pair<int, int>, int > > v;
      for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> g[i][j];
      for (int i = 0; i < k; ++i) {
          int a, b, c; cin >> a >> b >> c; --a; --b;
          v.push_back(mp(mp(a, b), c));
      }
      for (int i = 0; i < v.size(); ++i) if (g[v[i].first.first][v[i].first.second] != '.') ans = false;
      for (int i = 0; i < v.size(); ++i) {
          if (vis[v[i].first.first][v[i].first.second]) ans = false;
          else if (ff(v[i].first.first, v[i].first.second) != v[i].second) ans = false;
      }
      for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (!vis[i][j] && g[i][j] == '.') ans = false;
      for (int i = 0; i < n - 1; ++i) for (int j = 0; j < m - 1; ++j) {
          if (g[i][j] == '#' && g[i + 1][j] == '#' && g[i][j + 1] == '#' && g[i + 1][j + 1] == '#') ans = false;
      }
      for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) vis[i][j] = false;
      bool fst = true;
      for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
          if (g[i][j] == '#') {
              if (!fst && !vis[i][j]) {
                  ans = false;
              } else {
              }
              ff2(i, j);
              fst = false;
          }
      }
      cout << "Puzzle #" << x + 1 << ": " << (ans ? "Correct" : "Incorrect") << endl;
    }

}