#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int>> a;

int main() {
  int n;
  freopen("factory.in", "r", stdin);
  cin >> n;
  a.resize(n + 5, vector<int>());
  int b, c;
  for (int i = 0; i < n - 1; i++) {
    cin >> b >> c;
    a[c].push_back(b);
  }

  vector<int> s;
  int t = 0;
  vector<bool> v(n, false);
  int res = -1;
  for (int i = 0; i < n; i++) {
    s.push_back(i);
    v[i] = true;
    while (!s.empty()) {
      int j = s.back();
      s.pop_back();
      t++;
      for (auto e : a[j]) {
        if (v[e]) {
          continue;
        }
        v[e] = true;
        s.push_back(e);
      }
    }
    if (t == n) {
      res = i;
      break;
    }
    v.assign(n + 5, false);
    t = 0;
  }
  freopen("factory.out", "w", stdout);
  cout << res;
}
