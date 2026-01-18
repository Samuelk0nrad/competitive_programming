#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
      int e;
      cin >> e;

      a[i] = e;
    }

    sort(a.begin(), a.end());

    long long m = a[floor(n / 2.0)];
    if (m < l)
      m = l;
    else if (m > r)
      m = r;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
      res += abs((long long)a[i] - m);
    }

    cout << res << "\n";
  }
}
