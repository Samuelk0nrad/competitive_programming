#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, zx, zy;
    cin >> n >> zx >> zy;

    string s;
    cin >> s;

    int x = 0, y = 0;

    for (char e : s) {
      if (e == '4') {
        if (abs(zx - x) >= abs(zy - y)) {
          if (zx < x) {
            x--;
          } else if (zx > x) {
            x++;
          }
        } else {
          if (zy < y) {
            y--;
          } else if (zy > y) {
            y++;
          }
        }

      } else {
        if (zx < x) {
          x--;
        } else if (zx > x) {
          x++;
        }
        if (zy < y) {
          y--;
        } else if (zy > y) {
          y++;
        }
      }
    }

    if (zx == x && zy == y) {
      cout << "yes";
    } else {
      cout << "no";
    }
    cout << "\n";
  }
}
