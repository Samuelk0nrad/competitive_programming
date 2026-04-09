#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> v;

int main() {
  int n, m;
  cin >> n >> m;

  g.resize(n + 5, vector<int>());
  v.resize(n + 5, false);

  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> s;

  int res = 0;

  for (int i = 1; i <= n; i++) {
    if (v[i] != true) {
      v[i] = true;
      res++;
      s.push_back(i);
      while (!s.empty()) {
        int e = s.back();
        s.pop_back();
        for (int i : g[e]) {
          if (!v[i]) {
            v[i] = true;
            s.push_back(i);
          }
        }
      }
    }
  }

  cout << res;
}
