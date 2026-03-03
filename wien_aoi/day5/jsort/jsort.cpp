#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int e;

  vector<int> a(n + 5);
  vector<int> dp(n + 5, INT_MAX);

  int rmax = 1;

  for (int i = 0; i < n; i++) {
    cin >> e;
    a[i] = e;
    if (i == 0)
      continue;

    int l = 0;
    int r = rmax;
    while (l < r) {
      int m = (l + r) / 2;
      if (a[m] < e) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    if (dp[r] == INT_MAX) {
      rmax++;
    }
    dp[r] = e;
  }
  rmax--;
  cout << n - rmax;
}
