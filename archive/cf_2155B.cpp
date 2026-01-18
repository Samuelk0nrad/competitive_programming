#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    k = n * n - k;

    if (k == 1) {
      cout << "no\n";
      continue;
    }

    cout << "yes" << "\n";

    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {

        if (k >= n * (x + 1) - y) {
          if (y != n - 1) {
            cout << "D";
          } else if (x == 0) {
            cout << "U";
          } else {
            cout << "L";
          }
        } else {
          cout << "U";
        }
      }
      cout << '\n';
    }
  }
}
