#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

const int M = 1e9 + 7;

vector<ll> dp;

int main() {
  ll n;
  cin >> n;
  dp.resize(n + 5, 0);
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      if (i - j < 0) {
        continue;
      }
      dp[i] = dp[i] + dp[i - j];
      dp[i] %= M;
    }
  }
  cout << dp[n];
}
