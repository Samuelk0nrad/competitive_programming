#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> dp(n + 5, INT_MAX);

  int mr = 1;

  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;

    bool found = false;

    int r = mr;
    int l = 0;
    while (r > l) {
      int m = (r - l) / 2 + l; // 5 6 1: 12 => 6
      if (dp[m] == e) {
        found = true;
      }
      if (dp[m] > e) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    if (!found) {
      if (dp[r] == INT_MAX) {
        mr++;
      }
      dp[r] = e;
    }
  }

  cout << mr - 1;
}
