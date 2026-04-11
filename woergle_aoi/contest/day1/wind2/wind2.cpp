#include "wind2.h"
#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int to;
  int w;
  int d;
};

vector<vector<Edge>> e;
vector<vector<Edge>> ne;
vector<vector<Edge>> t;
vector<bool> v;
int N;

int d = 0;
void dfs(int i) {
  for (auto e : ne[i]) {
    if (!v[e.to]) {
      d++;
      v[e.to] = true;
      t[e.to][0] = {i, e.w, d};
      dfs(e.to);
      d--;
    }
  }
}

void init(int n, int q, vector<vector<int>> edges) {
  N = n;
  e.resize(n + 5);
  ne.resize(n + 5);
  for (auto i : edges) {
    e[i[0]].push_back({i[1], i[2]});
    e[i[1]].push_back({i[0], i[2]});
  }

  vector<bool> visit(n + 5, false);

  priority_queue<pair<int, pair<int, int>>> s;
  s.push({0, {-1, 1}});
  while (!s.empty()) {
    auto i = s.top();
    s.pop();
    if (visit[i.second.second]) {
      continue;
    }
    visit[i.second.second] = true;

    if (i.second.first != -1) {
      ne[i.second.first].push_back({i.second.second, i.first});
      ne[i.second.second].push_back({i.second.first, i.first});
    }

    for (auto j : e[i.second.second]) {
      if (!visit[j.to]) {
        s.push({j.w, {i.second.second, j.to}});
      }
    }
  }

  int root = 1;
  v.resize(n + 5, false);
  t.resize(n + 5, vector<Edge>(30, {root, INT_MAX}));
  v[root] = true;
  dfs(root);

  for (int m = 1; m < 30; m++) {
    for (int i = 1; i <= n; i++) {
      t[i][m] = {t[t[i][m - 1].to][m - 1].to,
                 min(t[t[i][m - 1].to][m - 1].w, t[i][m - 1].w)};
    }
  }

  return;
}

bool query(int u, int v, int k) {
  int a = u, b = v;
  int x = INT_MAX, y = INT_MAX;

  if (t[a][0].d > t[b][0].d) {
    int t = a;
    a = b;
    b = t;
  }

  int m = t[b][0].d - t[a][0].d;
  for (int i = 26; i >= 0; i--) {
    int s = 1 << i;
    if (m - s >= 0) {
      y = min(t[b][i].w, y);
      b = t[b][i].to;
      m -= s;
    }
    if (m == 0) {
      break;
    }
  }

  while (a != b) {
    for (int i = 0; i <= 26; i++) {
      if (t[b][i].to == t[a][i].to) {
        if (i != 0) {
          y = min(t[b][i - 1].w, y);
          x = min(t[a][i - 1].w, x);
          b = t[b][i - 1].to;
          a = t[a][i - 1].to;
        } else {
          y = min(t[b][i].w, y);
          x = min(t[a][i].w, x);
          b = t[b][i].to;
          a = t[a][i].to;
        }
        break;
      }
    }
  }

  return min(y, x) >= k;
}

void insert(int u, int v, int w) {
  // TODO: Implement your solution here
}
