#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;

    long long rdkdiff = rk - rd, cdkdiff = ck - cd;

    long long rkdiff = 0, ckdiff = 0;

    if (rdkdiff > 0) {
      rkdiff = n - rk;
    } else if (rdkdiff == 0) {
      rkdiff = 0;
    } else {
      rkdiff = rk;
    }

    if (cdkdiff > 0) {
      ckdiff = n - ck;
    } else if (cdkdiff == 0) {
      ckdiff = 0;
    } else {
      ckdiff = ck;
    }
    // cout << " rdkdiff: " << rdkdiff << " cdkdiff: " << cdkdiff
    //     << " rkdiff: " << rkdiff << " ckdiff: " << ckdiff << " ";

    cout << max(abs(rdkdiff) + rkdiff, abs(cdkdiff) + ckdiff) << "\n";
  }
}
