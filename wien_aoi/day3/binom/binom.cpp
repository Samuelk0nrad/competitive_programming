#include <bits/stdc++.h>
#include <vector>

using namespace std;
const int M = 1e9 + 7;

vector<vector<int>> dp;

int main() {
  int n, k;
  cin >> n >> k;

  dp.resize(k + 5, vector<int>(n + 5, 0));

  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0) {
        dp[0][j] = 1;
        continue;
      } else if (j == 0) {
        dp[i][0] = 0;
      } else if (i == j) {
        dp[i][j] = 1;
      } else if (i > j) {
        continue;
      } else {
        dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        dp[i][j] %= M;
      }
    }
  }

  cout << dp[k][n];
}
