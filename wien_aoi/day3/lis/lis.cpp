#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> dp(n + 5, 0);
  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int ms = 1;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        ms = max(ms, dp[j] + 1);
      }
    }
    dp[i] = ms;
  }

  cout << dp[n - 1];
}
