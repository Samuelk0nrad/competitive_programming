#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int M = 1e9 + 7;
const int N = 5e6 + 5;

int dp[205][9];
int dp2[205][9];

int main() {
  int n;
  cin >> n;

  int m[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};

  int ci = 0;
  int cci = 0;
  bool f = true;
  for (int i = 0; i <= n; i++) {
    if (f) {
      for (int j = 8; j > 0; j--) {
        if (i == 0) {
          dp[0][j] = 1;
        } else if (m[j] > i) {
          dp[ci][j] = 0;
        } else if (i - m[j] < 0) {
          dp[ci][j] = 0;
        } else {
          // i: 210 ci: 10 m[j]: 20 fi: 190 10 - 20: -10 + 200 = 190
          int fi = ci - m[j];
          int first;
          if (fi < 0) {
            fi = fi + 200;
            first = dp2[fi][j];
          } else {
            first = dp[fi][j];
          }
          int sec = 0;
          if (j < 8) {
            sec = dp[ci][j + 1];
          }
          dp[ci][j] = first + sec;
          dp[ci][j] %= M;
        }
      }
    } else {
      for (int j = 8; j > 0; j--) {
        if (i == 0) {
          dp2[0][j] = 1;
        } else if (m[j] > i) {
          dp2[ci][j] = 0;
        } else if (i - m[j] < 0) {
          dp2[ci][j] = 0;
        } else {
          int fi = ci - m[j];
          int first;
          if (fi < 0) {
            fi = fi + 200;
            first = dp[fi][j];
          } else {
            first = dp2[fi][j];
          }
          int sec = 0;
          if (j < 8) {
            sec = dp2[ci][j + 1];
          }
          dp2[ci][j] = first + sec;
          dp2[ci][j] %= M;
        }
      }
    }

    ci++;
    if (ci >= 200) {
      f = !f;
      ci %= 200;
    }
  }
  ci--;

  if (ci == -1) {
    f = !f;
    ci = 199;
  }

  if (f) {
    cout << dp[ci][1];
  } else {
    cout << dp2[ci][1];
  }
}
