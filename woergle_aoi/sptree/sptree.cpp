#include "grader.cpp"
#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

vector<vector<pair<int, ll>>> edfs;
vector<bool> v;
vector<vector<int>> e;
vector<ll> w;

vector<int> deep;

/*
4 3
1 2 1
2 3 2
3 4 3

1 4
4 1
3 4


9 10
4 2 4
2 5 2
1 2 2
8 7 6
9 7 10
6 3 1
7 6 2
3 1 3

8 9
4 5
3 2
6 8
5 9
 */

int s = 0;
int d = 0;
void dfs(int i) {
  w[i] = s;
  deep[i] = d;
  for (auto j : edfs[i]) {
    if (!v[j.first]) {
      v[j.first] = true;
      d++;
      s += j.second;
      e[j.first][0] = i;
      dfs(j.first);
      d--;
      s -= j.second;
    }
  }
}

void init(int N, int E[][2], long long L[]) {
  edfs.resize(N + 5);
  v.resize(N + 5, false);
  w.resize(N + 5);
  deep.resize(N + 5);

  int root = 1;
  for (int i = 0; i < N - 1; i++) {
    int a = E[i][0], b = E[i][1];
    int l = L[i];
    edfs[a].push_back({b, l});
    edfs[b].push_back({a, l});
  }

  e.resize(N + 5, vector<int>(30, root));
  v[root] = true;
  dfs(root);

  for (int g = 1; g < 30; g++) {
    for (int i = 1; i <= N; i++) {
      e[i][g] = e[e[i][g - 1]][g - 1];
    }
  }
}

ll query(int a, int b) {
  int x = a, y = b;
  if (deep[a] < deep[b]) {
    int t = a;
    a = b;
    b = t;
  }

  int m = deep[a] - deep[b];
  for (int i = 30; i >= 0; i--) {
    int s = 1 << i;
    if (s > m)
      continue;
    else {
      a = e[a][i];
      m -= s;
    }

    if (m == 0) {
      break;
    }
  }

  bool ok = false;
  if (a == b)
    ok = true;
  while (!ok) {
    for (int i = 0; i <= 30; i++) {
      if (e[a][i] == e[b][i]) {
        if (i == 0) {
          a = e[a][i];
          b = e[b][i];
          ok = true;
          break;
        } else {
          a = e[a][i - 1];
          b = e[b][i - 1];
          break;
        }
      }
    }
  }
  return (w[x] + w[y]) - 2 * w[a];
}
