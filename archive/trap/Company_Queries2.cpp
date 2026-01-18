// https://cses.fi/problemset/result/15781494/
#include <bits/stdc++.h>
#include <ios>
#include <vector>

using namespace std;

const int MAXP = 18;
vector<vector<int>> e;
vector<int> depth;

int lca(int a, int b) {
  if (depth[a] < depth[b]) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  int k = depth[a] - depth[b];
  for (int i = MAXP; i >= 0; --i) {
    if (k >= (1 << i)) {
      a = e[i][a];
      k = depth[a] - depth[b];
    }
  }
  if (a == b) {
    return a;
  }
  for (int i = MAXP; i >= 0; --i) {
    if (e[i][a] != e[i][b]) {
      a = e[i][a];
      b = e[i][b];
    }
  }
  return e[0][a];
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;

  e.assign(MAXP + 1, vector<int>(n + 1, 0));
  depth.assign(n + 2, 0);

  for (int i = 1; i <= n; ++i) {
    if (i == 1) {
      e[0][i] = 1;
      continue;
    }
    cin >> e[0][i];
    depth[i] = depth[e[0][i]] + 1;
  }

  for (int p = 1; p <= MAXP; ++p) {
    for (int i = 1; i <= n; ++i) {
      if (i == 1) {
        e[p][i] = 1;
        continue;
      }
      e[p][i] = e[p - 1][e[p - 1][i]];
    }
  }

  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    int res = lca(a, b);
    cout << res << "\n";
  }
}
