#include <bits/stdc++.h>

using namespace std;

int f[1005][1005];

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 1; j <= n; j++) {
      int a = 0;
      if (s[j - 1] == '*')
        a = 1;
      f[i][j] = (f[i][j - 1] + f[i - 1][j]) + a - f[i - 1][j - 1];
    }
  }

  int y1, x1, y2, x2;
  for (int i = 0; i < q; i++) {
    cin >> y1 >> x1 >> y2 >> x2;
    cout << ((f[y2][x2] - f[y1 - 1][x2]) - f[y2][x1 - 1]) + f[y1 - 1][x1 - 1]
         << "\n";
  }
}
