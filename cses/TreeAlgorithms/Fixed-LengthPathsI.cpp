#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int>> e;
vector<int> a;

vector<bool> visited;
void dfs(int i) {
  for (int b : e[i]) {
    if (visited[b]) {
      continue;
    }
    visited[b] = true;
    a[b] = i;
    dfs(b);
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  e.resize(n + 5, vector<int>());
  a.resize(n + 5, 0);
  visited.resize(n + 5, false);
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  visited[1] = true;
  dfs(1);
}
