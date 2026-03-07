// https://cses.fi/problemset/task/3311/
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> g(n);
  vector<vector<char>> r(n, vector<char>(m));

  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (char c = 'A'; c <= 'E'; ++c) {
        if (c == 'E') {
          cout << "IMPOSSIPLE";
          return 0;
        }
        if (g[i][j] == c)
          continue;
        if (i != 0 && r[i - 1][j] == c)
          continue;
        if (j != 0 && r[i][j - 1] == c)
          continue;
        if (i != n - 1 && r[i + 1][j] == c)
          continue;
        if (j != m - 1 && r[i][j + 1] == c)
          continue;

        r[i][j] = c;
        break;
      }
    }
  }

  for (auto s : r) {
    for (auto e : s) {
      cout << e;
    }
    cout << "\n";
  }
  cout << "\n";
}
