#include <bits/stdc++.h>
#include <cmath>
#include <tuple>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> q(n);

    if () {
    }

    for (int i = 2; i <= n; ++i) {
      int r = n - (i - 2);
      q[i] = {i, 1, r};
      if (r % 2 == 1) {
        q[i] = {i, ceil(r / 2.0), n};
      }
    }
  }
}
