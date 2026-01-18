#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, x, y;
    cin >> a >> x >> y;

    if (x > y) {
      int temp = x;
      x = y;
      y = temp;
    }

    if (a >= x && a <= y) {
      cout << "no";
    } else {
      cout << "yes";
    }
    cout << "\n";
  }
}
