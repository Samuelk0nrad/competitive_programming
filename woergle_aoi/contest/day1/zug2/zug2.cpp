#include "zug2.h"
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> e;
int N;

void init(int n, std::vector<std::pair<int, int>> edges) {
  N = n;
  e.resize(n + 5);
  e[1].push_back(2);
  e[2].push_back(3);
  e[3].push_back(1);
  e[2].push_back(1);
  e[3].push_back(2);
  e[1].push_back(3);
  for (int i = 0; i < edges.size(); i++) {
    e[i + 4].push_back(edges[i].first);
    e[i + 4].push_back(edges[i].second);
    e[edges[i].first].push_back(i + 4);
    e[edges[i].second].push_back(i + 4);
  }

  return;
}

int calculate(int u, int v) {
  vector<bool> visited(N + 5);

  priority_queue<pair<int, int>> p;
  p.push({0, u});
  visited[u] = true;
  int res = -1;
  while (!p.empty()) {
    auto j = p.top();
    p.pop();
    if (j.second == v) {
      res = -j.first;
      break;
    }
    for (int i : e[j.second]) {
      if (!visited[i]) {
        p.push({j.first - 1, i});
        visited[i] = true;
      }
    }
  }

  return res;
}
