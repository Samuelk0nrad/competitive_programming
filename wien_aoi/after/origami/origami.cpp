#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int main() {
  int a, b;
  cin >> a >> b;

  dp.resize(a + 5, vector<int>(b + 5, 0));

  for (int x = 1; x <= a; x++) {
    for (int y = 1; y <= b; y++) {
      if (x == y) {
        dp[x][y] = 0;
      } else {
        int ans = INT_MAX;
        int sec = x - 1;
        for (int i = 1; i <= sec; i++) {
          ans = min(ans, dp[i][y] + dp[sec][y]);
          sec--;
        }
        sec = y - 1;
        for (int i = 1; i <= sec; i++) {
          ans = min(ans, dp[x][i] + dp[x][sec]);
          sec--;
        }
        dp[x][y] = ans + 1;
      }
    }
  }

  cout << dp[a][b];
}
