#include "stocks.h"
#include "grader.cpp"
#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

// ll dp[1050][1050][2];
vector<vector<int>> fdp;
vector<vector<int>> sdp;

long long calculate_max_profit(int n, int k, std::vector<int> prices) {
  // ll res = f(0, 0, 0, false, prices, n);

  fdp.resize(n + 5, vector<int>(2));
  sdp.resize(n + 5, vector<int>(2));

  vector<vector<int>> *cdp = &sdp;
  vector<vector<int>> *ldp = &fdp;

  for (int d = n; d >= 0; d--) {
    for (int b = 0; b <= n; b++) {
      if (d == n) {
        if (b != 0) {
          (*cdp)[b][0] = INT_MIN;
          (*cdp)[b][1] = INT_MIN;
        } else {
          (*cdp)[b][0] = 0;
          (*cdp)[b][1] = 0;
        }
      } else if (b > d) {
        (*cdp)[b][0] = INT_MIN;
        (*cdp)[b][1] = INT_MIN;
      } else {
        // sold == false;
        ll pos1 = INT_MIN;
        if (b > 0) {
          ll win = prices[d] - prices[b - 1];
          pos1 = (*ldp)[0][1] + win;
        }
        ll pos2 = INT_MIN;
        if (b == 0) {
          pos2 = (*ldp)[d + 1][0];
        }
        ll pos3 = INT_MIN;
        pos3 = (*ldp)[b][0];
        ll res = max(pos1, pos2);
        res = max(res, pos3);
        (*cdp)[b][0] = res;
        // sold == true;
        (*cdp)[b][1] = max(pos1, pos3);
      }
    }
    vector<vector<int>> *temp = ldp;
    ldp = cdp;
    cdp = temp;
  }

  ll res = (*ldp)[0][0];
  return res;
}

