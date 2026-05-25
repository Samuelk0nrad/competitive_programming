#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<bool>> a;

void dfs(int x, int y) {
  if (a[x - 1][y]) {
    a[x - 1][y] = false;
    dfs(x - 1, y);
  }
  if (a[x][y - 1]) {
    a[x][y - 1] = false;
    dfs(x, y - 1);
  }
  if (a[x + 1][y]) {
    a[x + 1][y] = false;
    dfs(x + 1, y);
  }
  if (a[x][y + 1]) {
    a[x][y + 1] = false;
    dfs(x, y + 1);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  a.resize(n + 5, vector<bool>(m + 5, false));
  string s;
  for (int x = 1; x <= n; x++) {
    cin >> s;

    for (int y = 1; y <= m; y++) {
      if (s[y - 1] == '.') {
        a[x][y] = true;
      }
    }
  }

  int res = 0;

  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= m; y++) {
      if (a[x][y]) {
        res++;
        dfs(x, y);
      }
    }
  }

  cout << res;
}
