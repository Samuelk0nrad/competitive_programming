#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int m = INT_MAX, mi = -1, l = 0;
    long long res = 0;

    for (int i = 0; i < n; ++i) {
      int e;
      cin >> e;

      if (m == 0)
        continue;
      else if (i - 1 != mi) {
        m = 0;
      } else if (m > e && i > 0) {
        m = 0;
        res += e;
      } else if (m > e) {
        m = e;
        mi = i;
      }

      l = e;

      res += m;
    }

    cout << res << '\n';
  }
}
