#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  vector<vector<int>> dp(a + 5, vector<int>(b + 5));

  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (i == j) {
        dp[i][j] = 0;
      } else {
        int minr = INT_MAX;
        for (int x = 0; x < i / 2; x++) {
        }
      }
    }
  }

  cout << dp[a][b];
}
