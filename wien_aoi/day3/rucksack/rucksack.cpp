#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int V, n;
vector<pair<int, int>> a;
int dp[5005][2005];

int main() {
  cin >> V >> n;

  a.resize(n + 5);

  for (int i = 1; i <= n; i++) {
    int v, w;
    cin >> v >> w;
    a[i] = {v, w};
  }

  for (int i = 0; i <= n; i++) {
    for (int v = 0; v <= V; v++) {
      if (i == 0) {
        dp[v][0] = 0;
      } else if (v - a[i].first < 0) {
        dp[v][i] = dp[v][i - 1];
      } else {
        dp[v][i] = max(dp[v - a[i].first][i - 1] + a[i].second, dp[v][i - 1]);
      }
    }
  }

  cout << dp[V][n];
}
