// https://cses.fi/problemset/task/1195
#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

vector<vector<pair<ll, int>>> e;
vector<int> v;

int main() {
  int n, m;
  cin >> n >> m;

  e.resize(n * 2 + 5);
  v.resize(n * 2 + 5, false);

  int from, to, wight;
  for (int i = 0; i < m; i++) {
    cin >> from >> to >> wight;
    e[from].push_back({to, wight});
    e[from + n].push_back({to + n, wight});
    e[from].push_back({to + n, wight / 2});
  }

  priority_queue<pair<ll, int>> s;
  s.push({0, 1});
  ll res = 0;
  while (!s.empty()) {
    auto i = s.top();
    s.pop();

    if (v[i.second]) {
      continue;
    }
    v[i.second] = true;

    if (i.second == n || i.second == n * 2) {
      res = -i.first;
      break;
    }

    for (auto e : e[i.second]) {
      s.push({i.first - e.second, e.first});
    }
  }

  cout << res;
}
