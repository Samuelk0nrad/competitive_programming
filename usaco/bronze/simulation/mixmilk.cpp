#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  freopen("mixmilk.in", "r", stdin);
  int c[4];
  int m[4];

  scanf("%d %d", &c[1], &m[1]);
  scanf("%d %d", &c[2], &m[2]);
  scanf("%d %d", &c[3], &m[3]);

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
    if (from > 3) {
      from = 1;
    } else if (to > 3) {
      to = 1;
    }
  }
  freopen("mixmilk.out", "w", stdout);
  cout << m[1] << "\n" << m[2] << "\n" << m[3];
}
