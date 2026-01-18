#include <iostream>

using namespace std;

int main() {
  int n = 0;
  cin >> n;
  int ba = 0;
  int bb = 0;
  int bc = 0;
  int bd = 0;

  cin >> ba;
  cin >> bb;
  cin >> bc;
  cin >> bd;

  for (int r = 0; r < n; r++) {
    int a = ba;
    int b = bb;
    int c = bc;
    int d = bd;
    int t = 0;

    for (int i = 0; i < 4; i++) {
      if (t == -1) {
        cin >> t;
        t = -1;
        continue;
      }
      cin >> t;
      if (t % 2) {
        if (a == 0 || b == 0)
          continue;
        if (c > d)
          d--;
        else
          c--;
      } else {
        if (c == 0 || d == 0)
          continue;
        if (a > b)
          b--;
        else
          a--;
      }

      if (a <= 0) {
        cout << "Flower";
        t = -1;
      } else if (c <= 0) {
        cout << "Gellyfish";
        t = -1;
      }
    }
  }
}
