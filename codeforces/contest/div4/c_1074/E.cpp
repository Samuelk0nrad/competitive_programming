#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> r(n, 0);
  vector<int> s(m, 0);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
  }
  vector<pair<int, int>> rs(n, {INT_MAX, INT_MAX});
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int diff = abs(r[i] - s[j]);
      if (r[i] > s[j]) {
        rs[i].first = min(rs[i].first, diff);
      } else {
        rs[i].second = min(rs[i].second, diff);
      }
    }
  }

  string ks;

  cin >> ks;

  int live = n;
  int pos = 0;
  for (int i = 0; i < k; ++i) {
    if (ks[i] == 'L') {
      pos--;
    } else {
      pos++;
    }
    for (int j = 0; j < n; ++j) {
      if (rs[j].first == -1)
        continue;
      if (pos < 0 && rs[j].first <= abs(pos)) {
        live--;
        rs[j].first = -1;
      } else if (pos > 0 && rs[j].second <= pos) {
        live--;
        rs[j].first = -1;
      }
    }
    cout << live << " ";
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
