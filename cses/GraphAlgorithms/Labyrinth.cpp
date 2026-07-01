#include <bits/stdc++.h>
#include <deque>
#include <vector>

using namespace std;

vector<vector<bool>> a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  a.resize(n + 5, vector<bool>(m + 5, false));
  int ax, ay;
  int bx, by;

  string s;
  for (int x = 1; x <= n; x++) {
    cin >> s;
    for (int y = 1; y <= m; y++) {
      if (s[y - 1] == '.') {
        a[x][y] = true;
      } else if (s[y - 1] == 'A') {
        ax = x;
        ay = y;
      } else if (s[y - 1] == 'B') {
        a[x][y] = true;
        bx = x;
        by = y;
      }
    }
  }

  deque<pair<string, pair<int, int>>> q;
  q.push_back({"", {ax, ay}});
  while (!q.empty()) {
    auto e = q.front();
    auto p = e.second;
    q.pop_front();

    int x = p.first, y = p.second;

    if (x == bx && y == by) {
      cout << "YES\n" << e.first.length() << "\n";
      cout << e.first;
      return 0;
    }

    if (a[x - 1][y]) {
      a[x - 1][y] = false;
      q.push_back({e.first + "U", {x - 1, y}});
    }

    if (a[x][y - 1]) {
      a[x][y - 1] = false;
      q.push_back({e.first + "L", {x, y - 1}});
    }

    if (a[x][y + 1]) {
      a[x][y + 1] = false;
      q.push_back({e.first + "R", {x, y + 1}});
    }

    if (a[x + 1][y]) {
      a[x + 1][y] = false;
      q.push_back({e.first + "D", {x + 1, y}});
    }
  }

  cout << "NO";
}
