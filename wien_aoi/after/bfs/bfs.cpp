#include <bits/stdc++.h>
#include <deque>
#include <vector>
#define ll long long

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 5);

  int f, s;
  for (int i = 0; i < m; i++) {
    cin >> f >> s;
    a[f].push_back(s);
    a[s].push_back(f);
  }

  vector<bool> visited(n + 5, false);

  deque<pair<int, int>> dq;
  dq.push_back({0, 1});
  int res = -1;
  while (!dq.empty()) {
    auto node = dq.front();
    dq.pop_front();

    if (node.second == n) {
      res = node.first;
    }

    for (int i : a[node.second]) {
      if (!visited[i]) {
        dq.push_back({node.first + 1, i});
        visited[i] = true;
      }
    }
  }

  cout << res;
}
