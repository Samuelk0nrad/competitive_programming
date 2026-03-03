#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct item {
  int i;
  bool found = true;
  vector<vector<int>> b;
  vector<int> need;
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<item> a(n + 5);

  for (int i = 0; i < m; i++) {
    int in, k;
    cin >> in >> k;
    a[in].found = false;
    vector<int> ab(k);
    for (int j = 0; j < k; j++) {
      int e;
      cin >> e;
      ab[j] = e;
      a[e].need.push_back(in);
    }
    a[in].b.push_back(ab);
  }

  vector<int> res;

  bool possible = false;
  for (int i = 1; i <= n; i++) {
    if (a[i].found) {
      res.push_back(i);
      possible = true;
    }
  }
  if (!possible) {
    cout << -1;
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    if (!a[i].found) {
      for (auto b : a[i].b) {
        bool ok = true;
        for (int j : b) {
          if (!a[j].found) {
            ok = false;
          }
        }
        if (ok) {
          a[i].found = true;
          res.push_back(i);
          break;
        }
      }
    }
  }

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (!a[i].found) {
      ok = false;
    }
  }
  if (ok && res.size() == n) {
    for (int i : res) {
      cout << i << " ";
    }
  } else {
    cout << -1;
  }
}
