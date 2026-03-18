#include "zugfahrt.h"
#include "grader.cpp"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Edge {
  int to;
  ll wight;
};

struct Node {
  ll w = LONG_LONG_MAX;
  bool v = false;
  vector<Edge> e;
};

vector<Node> g;

int find_path(int n, int m, int h, vector<int> a, vector<int> b,
              vector<int> w) {
  if (h) {
    g.resize(n * 2 + 5);
  } else {
    g.resize(n + 5);
  }

  for (int i = 0; i < m; i++) {
    g[a[i]].e.push_back({b[i], w[i]});
    g[b[i]].e.push_back({a[i], w[i]});

    if (h) {
      g[a[i] + n].e.push_back({b[i] + n, w[i]});
      g[b[i] + n].e.push_back({a[i] + n, w[i]});

      g[a[i]].e.push_back({b[i] + n, w[i] / 2});
      g[b[i]].e.push_back({a[i] + n, w[i] / 2});
    }
  }

  priority_queue<pair<ll, int>> s;
  s.push({0, 1});

  ll res = 0;

  while (!s.empty()) {
    int i = s.top().second;
    int w = -s.top().first;
    s.pop();
    if (g[i].v)
      continue;
    g[i].v = true;

    if (w > 1000000) {
      return 1000000;
    }
    if (i == n || i == n * 2) {
      return w;
    }

    for (auto e : g[i].e) {
      if (!g[e.to].v && g[e.to].w > w + e.wight) {
        s.push({-(w + e.wight), e.to});
      }
    }
  }

  return 0;
}
