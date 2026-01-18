#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  long long k, x;
  long long c = 0;
  long long v = 0;
  while (t--) {
    cin >> k >> x;

    bool swap = false;
    int dx = (1 << (k + 1)) - x;
    if (dx < x) {
      swap = true;
      x = dx;
    }

    c = 1 << k;
    v = c;

    vector<int> o;

    while (c != x) {
      long long t = c / x;
      if (c % x == 0 && c % 2 == 0 && t > 0 && !(t & (t - 1))) {
        c = c / 2;
        v += c;
        o.push_back(1);
      } else if (v % 2 == 0) {
        v = v / 2;
        c += v;
        o.push_back(2);
      } else {
        c = c / 2;
        v += c;
        o.push_back(1);
      }
    }

    cout << o.size() << "\n";
    for (int e : o) {
      if (swap) {
        if (e == 1) {
          cout << 2 << " ";
        } else {
          cout << 1 << " ";
        }
      } else {
        cout << e << " ";
      }
    }
    cout << "\n";
  }
}
