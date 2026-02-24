#include <bits/stdc++.h>

using namespace std;

string s;

int dp[50][50];
bool used[5005][5005];

int f(int l, int r) {
  if (used[l][r]) {
    return dp[l][r];
  }
  if (l == r) {
    return 0;
  }
  if (l > r) {
    return 0;
  }
  if (s[l] == s[r]) {
    return f(l + 1, r - 1);
  }
  return min(f(l + 1, r), f(l, r - 1)) + 1;
}

int main() {
  int n;
  cin >> n >> s;

  // cout << f(0, n - 1);
  // return 1;

  for (int l = n - 1; l >= 0; l--) {
    for (int r = 0; r < n; r++) {
      if (l > r) {
        dp[l][r] = 0;
      } else if (l == r) {
        dp[l][r] = 0;
      } else if (s[l] == s[r]) {
        dp[l][r] = dp[l + 1][r - 1];
      } else {
        dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
      }
    }
  }

  // cout << f(0, n - 1);
  cout << dp[0][n - 1];
}
