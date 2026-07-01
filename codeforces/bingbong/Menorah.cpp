#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int norm = 0;
    int xn = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1') {
        ok = true;
      }
      if (a[i] != b[i]) {
        norm++;
      }
      if (a[i] == b[i]) {
        xn++;
      }
    }
    if (ok) {
      cout << min(norm, xn) << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
