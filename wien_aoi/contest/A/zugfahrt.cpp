#include "zugfahrt.h"
#include "grader.cpp"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct edge {
  ll to;
  ll w;
};

struct path {
  ll wight = LONG_LONG_MAX;
  ll realw = LONG_LONG_MAX;
  ll maxw = 0;
};

int find_path(int n, int m, int h, vector<int> a, vector<int> b,
              vector<int> w) {

  vector<vector<edge>> nodes(n + 5);
  vector<bool> visited(n + 5, false);
  vector<path> wight(n + 5);
  wight[1].wight = 0;
  wight[1].realw = 0;

  for (int i = 0; i < m; i++) {
    nodes[a[i]].push_back({b[i], w[i]});
    nodes[b[i]].push_back({a[i], w[i]});
  }

  priority_queue<pair<ll, int>> dq;

  dq.push({0, 1});

  ll res = 0;

  while (!dq.empty()) {
    auto i = dq.top();
    ll cw = -i.first;
    dq.pop();

    if (i.second == n) {
      res = wight[i.second].wight;
      break;
    }

    if (cw >= 1000000) {
      return 1000000;
    }

    if (visited[i.second]) {
      continue;
    }
    visited[i.second] = true;

    for (auto e : nodes[i.second]) {
      if (visited[e.to]) {
        continue;
      }
      path possible = wight[i.second];
      if (wight[i.second].maxw < e.w && h == 1) {
        possible.wight = wight[i.second].realw + (e.w / 2);
        possible.realw = wight[i.second].realw + e.w;
        possible.maxw = e.w;
      } else {
        possible.wight = wight[i.second].wight + e.w;
        possible.realw = wight[i.second].realw + e.w;
      }

      if (wight[e.to].wight > possible.wight) {
        wight[e.to] = possible;
        dq.push({-wight[e.to].wight, e.to});
      }
    }
  }

  if (res <= 1000000) {
    return res;
  } else {
    return 1000000;
  }
}
