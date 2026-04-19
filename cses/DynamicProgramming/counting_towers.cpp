#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int M = int(1e9) + 7;

vector<vector<int>> dp;

int main() {
  int n;
  cin >> n;

  dp.resize(n + 5, vector<int>(3, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 1; j++) {
      if (i == 1) {
        if (j == 1)
          dp[i][j] = 2;
        dp[i][j] = 0;
        continue;
      }
      int ans = 0;
      for (int y = i - 1; y > 0; y--) {
        ans += dp[y][j] + dp[i - y][0] + 1;
        ans %= M;
      }
      if (j == 1)
        ans += dp[i][0] * 2;
      ans %= M;
      dp[i][j] = ans;
    }
  }
}
