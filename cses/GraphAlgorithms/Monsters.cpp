#include <bits/stdc++.h>

using namespace std;

bool w[1000][1000];
int M[1000][1000];

int n, m;

string res = "";
int c = 0;
bool dfs(pair<int, int> p) {
  if (p.first >= n || p.second >= m) {
    return true;
  } else if (p.first < 0 || p.second < 0) {
    return true;
  } else if (w[p.first][p.second] == true) {
    return false;
  } else if (c >= M[p.first][p.second]) {
    return false;
  }
  bool ans = false;

  w[p.first][p.second] = true;
  c++;
  res.push_back('D');
  ans = dfs({p.first + 1, p.second});
  if (ans)
    return ans;
  res.pop_back();

  res.push_back('U');
  ans = dfs({p.first - 1, p.second});
  if (ans)
    return ans;
  res.pop_back();

  res.push_back('R');
  ans = dfs({p.first, p.second + 1});
  if (ans)
    return ans;
  res.pop_back();

  res.push_back('L');
  ans = dfs({p.first, p.second - 1});
  if (ans)
    return ans;
  res.pop_back();
  c--;
  w[p.first][p.second] = false;

  return false;
}

int main() {
  cin >> n >> m;

  string s;
  pair<int, int> start;
  deque<pair<int, pair<int, int>>> ms;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      w[i][j] = false;
      M[i][j] = INT_MAX;
      if (s[j] == '#') {
        w[i][j] = true;
      } else if (s[j] == 'A') {
        start = {i, j};
      } else if (s[j] == 'M') {
        ms.push_back({0, {i, j}});
        M[i][j] = 0;
      }
    }
  }

  while (!ms.empty()) {
    auto e = ms.front();
    ms.pop_front();
    if (e.second.first > n || e.second.second > m) {
      continue;
    } else if (e.second.first < 0 || e.second.second < 0) {
      continue;
    } else if (w[e.second.first][e.second.second] == true) {
      continue;
    } else if (e.first > M[e.second.first][e.second.second]) {
      continue;
    }

    M[e.second.first][e.second.second] = e.first;

    ms.push_back({e.first + 1, {e.second.first, e.second.second + 1}});
    ms.push_back({e.first + 1, {e.second.first + 1, e.second.second}});
    ms.push_back({e.first + 1, {e.second.first, e.second.second - 1}});
    ms.push_back({e.first + 1, {e.second.first - 1, e.second.second}});
  }

  bool ans = dfs(start);
  if (ans) {
    res.pop_back();
    cout << "YES\n";
    cout << res.size() << "\n";
    cout << res;
  } else {
    cout << "NO";
  }
}
