#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long r, x, d, n;
    cin >> r >> x >> d >> n;

    string s;
    cin >> s;

    long long res = 0;
    for (auto c : s) {
      if (c == '1') {
        res++;
        r = r - d;
      } else {
        if (r < x) {
          res++;
          r = r - d;
        }
      }
      if (r < 0)
        r = 0;
    }

    cout << res << "\n";
  }
}
