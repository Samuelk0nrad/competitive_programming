#include "berg2.h"
#include <bits/stdc++.h>

using namespace std;

int calculate(vector<pair<long, long>> &intervals) {
  vector<int> l;
  vector<int> a;
  vector<vector<vector<int>>> dp;
  l.resize(105, 0);
  a.resize(105, 0);
  long h = 0;
  for (auto i : intervals) {
    l[i.first]++;
    l[i.second + 1]--;
    h = max(h, i.second);
  }

  int v = 0;
  int mh = 0;
  for (int i = 0; i <= h; i++) {
    v += l[i];
    a[i] = v;
    mh = max(mh, v);
  }

  dp.resize(h + 5, vector<vector<int>>(mh + 5, vector<int>(5, 0)));

  for (int i = h; i >= 0; i--) {
    for (int j = mh; j >= 0; j--) {
      for (int x = 2; x >= 0; x--) {
        if (x == 2) {
          if (a[i] > j) {
            dp[i][j][x] = 1 + dp[i + 1][j][x];
          } else {
            dp[i][j][x] = dp[i + 1][j][x];
          }
          continue;
        } else if (x == 0) {
          int ans = 0;

          ans += dp[i + 1][a[i]][x + 1];
          ans += dp[i + 1][j][x];

          dp[i][j][x] = ans;
        } else {

          int ans = 0;

          if (a[i] > j) {
            ans += dp[i + 1][a[i]][x + 1];
          }
          ans += dp[i + 1][j][x];

          dp[i][j][x] = ans;
        }
      }
    }
  }

  if (dp[0][0][0] == 0) {
    return -1;
  }
  return dp[0][0][0];
}
