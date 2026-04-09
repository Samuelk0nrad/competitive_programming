#include <bits/stdc++.h>
#include <vector>
#define ll long long
#ifdef EVAL
#include "trolls.h"
#else
#include "grader.cpp"
#endif

using namespace std;

vector<vector<pair<int, ll>>> e;

void build(vector<Troll> &t) {
  e.resize(t.size() + 5, vector<pair<int, ll>>(35, {t.size(), 0}));
  vector<int> l;
  for (int i = 0; i < t.size(); i++) {
    for (int j = l.size() - 1; j >= 0; j--) {
      if (t[l[j]].s >= t[i].s) {
        break;
      } else {
        e[l[j]][0] = {i, t[l[j]].h};
        l.pop_back();
      }
    }
    l.push_back(i);
  }
  for (int i : l) {
    e[i][0] = {t.size(), t[i].h};
  }

  for (int i = 1; i < 32; i++) {
    for (int j = 0; j <= t.size(); j++) {
      auto a = e[j][i - 1];
      e[j][i] = {e[a.first][i - 1].first, a.second + e[a.first][i - 1].second};
    }
  }
  return;
}

int query(int k, int d, int n) {
  int a = k;
  for (int i = 28; i >= 0; i--) {
    if (e[a][i].second <= d) {
      d -= e[a][i].second;
      a = e[a][i].first;
      continue;
    }
    if (a == n || d == 0) {
      break;
    }
    continue;
  }
  return a;
}

/*
5 6

1 1
2 2
3 3
4 4
5 5

0 1
1 3
5 0
0 13
3 1
2 6
*/

vector<int> simulateAttacks(vector<Troll> trolls, vector<Query> queries) {
  int N = trolls.size();
  int Q = queries.size();
  vector<int> results(Q);

  build(trolls);

  for (int j = 0; j < Q; j++) {
    // queries[j].k
    // queries[j].damage
    int res = query(queries[j].k, queries[j].d, N);
    if (res == N) {
      results[j] = 0;
    } else {
      results[j] = res + 1;
    }
  }

  return results;
}
