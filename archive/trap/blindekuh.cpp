#include <bits/stdc++.h>

using namespace std;

static int n, tx, ty, queries;
static long long ld = 1ll << 62;

static long long dist(int x, int y) {
  return (x - tx) * 1LL * (x - tx) + (y - ty) * 1LL * (y - ty);
}

bool hit(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= n) {
    std::cerr << "out of bounds queries\n";
    std::exit(1);
  }
  queries++;
  if (x == tx && y == ty) {
    std::cout << queries << std::endl;
    std::exit(0);
  }
  auto d = dist(x, y);
  bool res = d < ld;
  ld = d;
  return res;
}

void blinde_kuh(int n) {
  hit(0, n / 2);
  int l = 0, r = n - 1;
  bool ll = true;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (ll) {
      if (hit(r, n / 2)) {
        if (l == m)
          m++;
        l = m;
        ll = false;
      } else {
        if (r == m)
          m--;
        r = m;
        hit(l, n / 2);
      }
    } else {
      if (hit(l, n / 2)) {
        if (r == m)
          m--;
        r = m;
        ll = true;
      } else {
        if (l == m)
          m++;
        l = m;
        hit(r, n / 2);
      }
    }
  }

  int col = l;
  l = 0, r = n - 1;
  ll = true;
  hit(col, 0);

  while (l < r) {
    int m = l + (r - l) / 2;
    if (ll) {
      if (hit(col, r)) {
        if (l == m)
          m++;
        l = m;
        ll = false;
      } else {
        if (r == m)
          m--;
        r = m;
        hit(col, l);
      }
    } else {
      if (hit(col, l)) {
        if (r == m)
          m--;
        r = m;
        ll = true;
      } else {
        if (l == m)
          m++;
        l = m;
        hit(col, r);
      }
    }
  }

  cout << "a;sldfka s";
}

int main() {
  cin >> n >> tx >> ty;
  blinde_kuh(n);
  std::cerr << "target not found\n";
  return 1;
}
