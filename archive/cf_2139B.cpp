#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    int cr = 0;
    int s = (n) - (m % n);
    if (!(m % n)) {
      s = 0;
      cr = 1;
    }

    vector<int> a;
    vector<int> c(n, 0);

    for (int i = 0; i < n; ++i) {
      int e;
      cin >> e;
      a.push_back(e);
    }

    sort(a.begin(), a.end());

    int k = 1;

    int res = 0;
    int rounds = m / n;
    int roudpoint = 0;
    for (int i = 0; i < m && cr < 2; ++i) {
      int r = a[s] * (k - c[s]);
      if (cr) {
        roudpoint += r;
      }
      res += r;
      c[s] = i + 1;

      k++;
      s++;
      if (s >= n) {
        cr++;
        s = 0;
      }
    }

    res += (rounds - 1) * roudpoint;

    cout << res << "\n";
  }
}
