#include <bits/stdc++.h>
#include <istream>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  iostream::sync_with_stdio(false);
  int n, x;
  vector<int> c;

  cin >> n >> x;
  c.assign(n, 0);
  vector<int> dp(x + 1, 0);
  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = c[i]; j <= x; ++j) {
      dp[j] = (dp[j - c[i]] + dp[j]) % int(1e9 + 7);
    }
  }
  cout << dp[x];
}
