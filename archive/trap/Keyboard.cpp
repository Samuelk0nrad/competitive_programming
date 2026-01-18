#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> k(m);
  for (int i = 0; i < m; i++) {
    int e;
    cin >> e;
    k[i].push_back(e);
  }

  vector<vector<int>> dp(n + 1, vector<int>(2, INT_MIN));
  dp[0][0] = 0;

  for (int i = 1; i < n; i++) {
  }
}
