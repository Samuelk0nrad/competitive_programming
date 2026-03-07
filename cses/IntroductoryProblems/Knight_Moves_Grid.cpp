#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

int n;

queue<pair<int, int>> q;
vector<vector<bool>> visited;
vector<vector<int>> dist;

void visit(pair<int, int> &cpos, pair<int, int> npos) {
  if (npos.first < 0 || npos.first >= n) {
    return;
  }
  if (npos.second < 0 || npos.second >= n) {
    return;
  }
  if (visited[npos.first][npos.second]) {
    return;
  }

  visited[npos.first][npos.second] = true;
  dist[npos.first][npos.second] = dist[cpos.first][cpos.second] + 1;
  q.push(npos);
}

int main() {
  cin >> n;

  visited.assign(n, vector<bool>(n, false));
  dist.assign(n, vector<int>(n));

  q.push({0, 0});
  dist[0][0] = 0;
  visited[0][0] = true;

  while (!q.empty()) {
    pair<int, int> cpos = q.front();
    q.pop();
    visit(cpos, {cpos.first + 2, cpos.second + 1});
    visit(cpos, {cpos.first + 1, cpos.second + 2});

    visit(cpos, {cpos.first - 2, cpos.second + 1});
    visit(cpos, {cpos.first - 1, cpos.second + 2});

    visit(cpos, {cpos.first + 2, cpos.second - 1});
    visit(cpos, {cpos.first + 1, cpos.second - 2});

    visit(cpos, {cpos.first - 2, cpos.second - 1});
    visit(cpos, {cpos.first - 1, cpos.second - 2});
  }

  for (auto a : dist) {
    for (auto e : a) {
      cout << e << " ";
    }
    cout << "\n";
  }
}
