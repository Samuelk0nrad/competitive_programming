#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> dpm;
vector<vector<int>> edges;

int dp(uint visited, uint current) {
  if (dpm[visited][current] != -1) {
    return dpm[visited][current];
  } else if (current == n) {
    if (visited == (1 << (n + 1)) - 1) {
      dpm[visited][current] = 1;
      return 1;
    } else {
      dpm[visited][current] = 0;
      return 0;
    }
  } else {
    int total = 0;
    for (int i : edges[current]) {
      if (!((visited >> i) & 1)) {
        total += dp(visited | (1 << i), i);
        total = total % int(1e9 + 7);
      }
    }
    dpm[visited][current] = total;
    return total;
  }
}

int main() {
  int m;
  cin >> n >> m;
  edges.assign(n + 1, {});
  dpm.assign((1 << (n + 1)) + 1, vector<int>(n + 1, -1));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
  }

  int t1 = 1 | 1 << 2;
  t1 = 3 | 1 << 3;

  int res = dp(3, 1);
  cout << res;
}
