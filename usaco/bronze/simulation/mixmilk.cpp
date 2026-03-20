#include <bits/stdc++.h>

using namespace std;

int main() {
  int c[4];
  int m[4];

  cin >> c[1] >> m[1];
  cin >> c[2] >> m[2];
  cin >> c[3] >> m[3];

  int from = 1, to = 2;
  for (int i = 0; i < 100; i++) {
    m[to] += m[from];
    if (m[to] > c[to]) {
      m[from] = m[to] - c[to];
      m[to] = c[to];
    } else {
      m[from] = 0;
    }
    from++;
    to++;
    if (from == 3) {
      from = 1;
    } else if (to == 3) {
      from = 1;
    }
  }
  cout << m[1] << " " << m[2] << " " << m[3];
}
