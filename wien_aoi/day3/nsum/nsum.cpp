#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int M = 1e9 + 7;

// int f(int n, int m) {
//   if (n < 0) {
//     return 0;
//   }
//   if (n == 0) {
//     return 1;
//   }
//   if (m > n) {
//     return 0;
//   }
//   return f(n - m, m) + f(n, m + 1);
// }

int dp[1005][1005];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i <= n; i++) {
    for (int j = n; j >= 0; j--) {
      if (i == 0) {
        dp[i][j] = 1;
      } else if (j > i) {
        dp[i][j] = 0;
      } else if (i - j < 0) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = dp[i - j][j] + dp[i][j + 1];
        dp[i][j] %= M;
      }
    }
  }
  cout << dp[n][1];
}
