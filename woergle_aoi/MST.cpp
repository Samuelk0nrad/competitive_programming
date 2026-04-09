#include <bits/stdc++.h>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

struct Edge {
  int w;
  int to;
};

vector<vector<Edge>> g;
vector<bool> v;

int main() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 5, vector<Edge>());
  v.resize(n + 5, false);

  int a, b, w;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    g[a].push_back(Edge{w, b});
    g[b].push_back(Edge{w, a});
  }

  priority_queue<pair<int, int>> q;
  q.push({0, 1});

  ll res = 0;

  while (!q.empty()) {
    auto e = q.top();
    q.pop();
    if (v[e.second]) {
      continue;
    }
    v[e.second] = true;
    res += -e.first;

    for (auto &i : g[e.second]) {
      q.push({-i.w, i.to});
    }
  }

  cout << res;
}
