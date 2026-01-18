#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;

    if (y == 1) {
      cout << -1;
    } else if (x - y == 1 || x - y == 0) {
      cout << -1;
    } else if (x < y) {
      cout << 2;
    } else if (y < x) {
      cout << 3;
    }
    cout << "\n";
  }
}
