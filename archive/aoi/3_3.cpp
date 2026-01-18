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

  vector<tuple<int, int, int>> rounds(m + 1);

  vector<int> w_start(m + 1, 0);
  vector<int> w_end(m + 1, 0);

  for (int i = 1; i <= m; i++) {
    int t, l, r;
    std::cin >> t >> l >> r;
    if (t == 1) {
      w_start[i]++;
      w_end[i]++;
    } else if (t == 2) {
      w_start[l]++;
      w_end[r]++;
    }
    rounds[i] = {t, l, r};
  }

  int w = 0;
  for (int i = m; i > 0; i--) {
    w += w_end[i];

    auto [t, l, r] = rounds[i];
    if (t == 1) {
      u_start[l] += w;
      u_end[r] += w;
    } else {
      w_start[l] += w;
      w_end[r] += w;
    }
    w -= w_start[i];
  }

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += u_start[i];
    cout << sum << " ";
    sum -= u_end[i];
  }
  return 0;
}
