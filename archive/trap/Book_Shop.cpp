#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, x;

  cin >> n >> x;

  vector<int> h(n + 1);
  vector<int> s(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(x + 1, INT_MIN));
  dp[0][0] = 0;

  int max_pages = INT_MIN;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      if (j - h[i] >= 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i]] + s[i]);
        max_pages = max(max_pages, dp[i][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  if (max_pages <= 0) {
    cout << 0;
  } else {
    cout << max_pages;
  }
  cout << endl;
}
