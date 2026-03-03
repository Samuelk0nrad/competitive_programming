#include <bits/stdc++.h>

using namespace std;

string a, b;

int main() {
  cin >> a >> b;

  vector<vector<int>> dp(a.size() + 5, vector<int>(b.size() + 5));
  vector<vector<pair<int, int>>> parent(a.size() + 5,
                                        vector<pair<int, int>>(b.size() + 5));

  for (int i = a.size() - 1; i >= 0; i--) {
    for (int j = b.size() - 1; j >= 0; j--) {
      if (i == a.size() - 1 && j == b.size() - 1) {
        if (a[i] == b[j]) {
          dp[i][j] = 1;
          parent[i][j] = {-1, -1};
        } else {
          dp[i][j] = 0;
          parent[i][j] = {-1, -1};
        }
        continue;
      } else if (j == b.size() - 1) {
        if (a[i] == b[j]) {
          dp[i][j] = 1;
          parent[i][j] = {-1, -1};
        } else {
          dp[i][j] = dp[i + 1][j];
          parent[i][j] = {i + 1, j};
        }
        continue;
      } else if (i == a.size() - 1) {
        if (a[i] == b[j]) {
          dp[i][j] = 1;
          parent[i][j] = {-1, -1};
        } else {
          dp[i][j] = dp[i][j + 1];
          parent[i][j] = {i, j + 1};
        }
        continue;
      }
      if (a[i] == b[j]) {
        dp[i][j] = dp[i + 1][j + 1] + 1;
        parent[i][j] = {i + 1, j + 1};
      } else {
        if (dp[i + 1][j] > dp[i][j + 1]) {
          dp[i][j] = dp[i + 1][j];
          parent[i][j] = {i + 1, j};
        } else {
          dp[i][j] = dp[i][j + 1];
          parent[i][j] = {i, j + 1};
        }
      }
    }
  }

  vector<pair<int, int>> path;

  pair<int, int> d = parent[0][0];
  if (a[0] == b[0]) {
    path.push_back({0, 0});
  }

  while (true) {
    if (d.first < 0 || d.second < 0)
      break;
    if (dp[d.first][d.second] == 0)
      break;
    if (a[d.first] == b[d.second]) {
      path.push_back(d);
    }
    d = parent[d.first][d.second];
  }

  cout << dp[0][0] << "\n";
  for (auto i : path) {
    cout << a[i.first];
  }

  cout << " ";
}
