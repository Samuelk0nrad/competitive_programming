#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, k;
    cin >> x >> k;
    if (x == 1) {
      if (k == 2) {
        cout << "yes";
      } else {
        cout << "no";
      }
    } else if (k > 1) {
      cout << "no";
    } else {
      bool r = false;
      int max = floor(x / 2.0);
      for (int i = 2; i <= max; ++i) {
        if (x % i == 0) {
          r = true;
          break;
        } else {
          max = floor(x / i);
        }
      }
      if (r) {
        cout << "no";
      } else {
        cout << "yes";
      }
    }
    cout << "\n";
  }
}
