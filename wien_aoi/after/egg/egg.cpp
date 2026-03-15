#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> dp;

int main() {
  ll n, k;
  cin >> n >> k;

  if (k >= log2(n)) {
    cout << ceil(log2(n));
  } else if (k == 1) {
    cout << n;
  } else {
    dp.resize(k + 5, vector<ll>(n + 5));
    for (ll h = 0; h <= n; h++) {
      for (ll e = 0; e <= k; e++) {
        if (h == 0) {
          dp[e][h] = 0;
        } else if (e == 0) {
          dp[e][h] = LONG_LONG_MAX;
        } else {
          if (e == 1) {
            dp[e][h] = h;
            continue;
          }
          ll mt = LONG_LONG_MAX;
          ll hb = h - 1;
          ll l = 0;
          for (; l <= hb; l++) {
            if (hb < 0)
              continue;
            ll p = max(dp[e - 1][l], dp[e][hb]) + 1;
            mt = min(mt, p);
            if (mt == dp[e][h - 1]) {
              break;
            }
            hb--;
          }
          dp[e][h] = mt;
        }
      }
    }
    cout << dp[k][n];
  }
}
