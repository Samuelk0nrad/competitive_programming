#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    long long f, m = 0, res = 0;
    long long l = -1;

    for (int i = 0; i < n; ++i) {
      long long e;
      cin >> e;

      if (l != -1) {
        res += max(e, l);
      }

      if (i == 0)
        f = e;

      if (e > m)
        m = e;

      l = e;
    }

    res += max(f, l);
    res -= m;

    cout << res << "\n";
  }
}
