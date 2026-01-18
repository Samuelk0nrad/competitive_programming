#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    unsigned int a, b;
    cin >> a >> b;

    if (a == b) {
      cout << "0";
    } else {
      unsigned int x = (a | b) & (~(a & b));
      unsigned int c = a ^ x;

      unsigned int l = __builtin_clz(x);

      if (__builtin_clz(x) < __builtin_clz(a)) {
        cout << "-1";
      } else {
        if (x > a) {
          unsigned int r = __bit_floor(x);

          cout << "2\n" << r << " " << ((~r) & x);
        } else {
          cout << "1\n" << x;
        }
      }
    }

    cout << "\n";
  }
}
