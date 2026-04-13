// https://cses.fi/problemset/result/16039337/
#include <bits/stdc++.h>
#include <cmath>
#define ll long long

using namespace std;

ll pw[18];

int main() {
  ll q;
  cin >> q;
  ll k;
  pw[0] = 1;

  for (int i = 1; i < 18; i++)
    pw[i] = pw[i - 1] * 10;

  while (q--) {
    cin >> k;
    for (int d = 1; d < 100; d++) {
      ll e = pw[d] - 1;
      ll s = pw[d - 1];
      ll c = (e - (s - 1)) * d;

      if (c < k) {
        k -= c;
        continue;
      }

      ll numb = ((k - 1) / d) + s;
      ll p = abs(((k - 1) % d) - (d - 1));

      ll h = numb % pw[p + 1];
      ll l = numb % pw[p];
      ll res = (h - l) / pw[p];

      cout << res << "\n";
      break;
    }
  }
}
