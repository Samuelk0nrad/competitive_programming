#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int R, X, D, n;
    cin >> R >> X >> D >> n;

    string c;
    cin >> c;

    int res = 0;
    for (int i = 0; i < n; i++) {
      if (c[i] == '1' || R < X) {
        if (R == 0)
          R = 1;
        else
          R -= D;

        if (R < 0)
          R = 0;
        res++;
      }
    }

    cout << res << "\n";
  }
}
