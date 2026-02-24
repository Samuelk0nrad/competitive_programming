#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int M = 1e9 + 7;
const int N = 5e6 + 5;

int dp[N][8];

int main() {
  int n;
  cin >> n;

  int m[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};

  // 1 2 3 4 5 6 7 8 9
  // 1 2 2 4 4

  for (int i = 0; i <= n; i++) {
    for (int j = 8; j > 0; j--) {
      if (i == 0) {
        dp[i][j] = 1;
      } else if (m[j] > i) {
        dp[i][j] = 0;
      } else if (i - m[j] < 0) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = dp[i - m[j]][j] + dp[i][j + 1];
        dp[i][j] %= M;
      }
    }
  }

  cout << dp[n][1];
}
