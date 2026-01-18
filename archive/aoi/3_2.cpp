#include <bits/stdc++.h>

using namespace std;

/*
 * Diese Datei soll dir nur eine Orientierung und Hilfe sein, wie du mit deinem
 * Programm starten kannst.
 */

int main() {
  int n, m;
  std::cin >> n >> m;

  int c = 1e9 + 7;

  vector<int> u_start(n + 1, 0);
  vector<int> u_end(n + 1, 0);

  for (int i = 1; i <= m; i++) {
    int t, l, r;
    std::cin >> t >> l >> r;
    if (t == 1) {
      u_start[l] = ((u_start[l] % c) + 1) % c;
      u_end[r] = ((u_end[r] % c) + 1) % c;
    }
  }

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += u_start[i];
    cout << sum << " ";
    sum -= u_end[i];
  }
  return 0;
}
