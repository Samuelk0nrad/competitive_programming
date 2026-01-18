#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    int lm = 0, ls = 0;
    int res = 0;

    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;

      if ((a - lm) % 2 == (ls == b)) {
        res += a - lm - 1;
      } else {
        res += a - lm;
      }

      lm = a;
      ls = b;
    }

    res += m - lm;

    cout << res << "\n";
  }
}
