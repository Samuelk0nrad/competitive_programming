#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> dp;

const int M = int(1e9) + 7;

int sumt(int i) {
  if (i == 0)
    return 0;
  else
    return (i * i + i) / 2;
}

int main() {
  int n;
  cin >> n;

  int sum = sumt(n);

  dp.resize(n + 5, vector<int>(sum / 2 + 5, 0));

  for (int i = n; i > 0; i--) {
    for (int s = sumt(n) / 2; s >= 0; s--) {
      ll s2 = abs(sumt(i) - s);
      if (i == n) {
        if (s == s2)
          dp[i][s] = 1;
        else
          dp[i][s] = 0;
        break;
      }
      ll ans = dp[i + 1][s];
      if (s + i <= sumt(n) / 2) {
        ans += dp[i + 1][s + i];
      }
      ans %= M;

      dp[i][s] = ans;
    }
  }
  cout << dp[1][0];
}
