#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dp[75][75][75][305];

int main() {
  ll h1, h2, h3, a1, a2, a3;
  cin >> h1 >> h2 >> h3 >> a1 >> a2 >> a3;

  for (int o = 0; o <= h1; o++) {
    for (int u = 0; u <= h2; u++) {
      for (int h = 0; h <= h3; h++) {
        for (int i = 300; i > 0; i--) {
          if (o == 0 && u == 0 && h == 0) {
            dp[o][u][h][i] = 0;
          } else {
            int an = INT_MAX;
            int x = 0;
            if (o != 0) {
              if (o - i >= 0) {
                x = a1;
                if (u != 0)
                  x += a2;
                if (h != 0)
                  x += a3;
                an = min(an, dp[o - i][u][h][i + 1] + x);
              } else {
                x = 0;
                if (u != 0)
                  x += a2;
                if (h != 0)
                  x += a3;
                an = min(an, dp[0][u][h][i + 1] + x);
              }
            }
            if (u != 0) {
              if (u - i >= 0) {
                x = a2;
                if (o != 0)
                  x += a1;
                if (h != 0)
                  x += a3;
                an = min(an, dp[o][u - i][h][i + 1] + x);
              } else {
                x = 0;
                if (o != 0)
                  x += a1;
                if (h != 0)
                  x += a3;
                an = min(an, dp[o][0][h][i + 1] + x);
              }
            }
            if (h != 0) {
              if (h - i >= 0) {
                x = a3;
                if (o != 0)
                  x += a1;
                if (u != 0)
                  x += a2;
                an = min(an, dp[o][u][h - i][i + 1] + x);
              } else {
                x = 0;
                if (o != 0)
                  x += a1;
                if (u != 0)
                  x += a2;
                an = min(an, dp[o][u][0][i + 1] + x);
              }
            }
            dp[o][u][h][i] = an;
          }
        }
      }
    }
  }

  cout << dp[h1][h2][h3][1];
}
