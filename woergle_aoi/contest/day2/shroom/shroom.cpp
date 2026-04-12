#include <bits/stdc++.h>

using namespace std;

int g[505][505];
int p[505][505];

int sum(int x, int y, int m) {
  int v = p[x][y];
  if (x - m < 0 && y - m < 0) {
    return v;
  } else if (x - m < 0) {
    return v - p[x][y - m];
  } else if (y - m < 0) {
    return v - p[x - m][y];
  } else {
    return ((v - p[x][y - m]) - p[x - m][y]) + p[x - m][y - m];
  }
}

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  int w, n, m;
  cin >> w >> n >> m;

  int ix, iy, mi;
  for (int i = 0; i < n; i++) {
    cin >> ix >> iy >> mi;
    g[ix][iy] = mi;
  }

  for (int x = 0; x < w; x++) {
    for (int y = 0; y < w; y++) {
      if (x == 0 && y == 0) {
        p[0][0] = g[0][0];
        continue;
      }
      if (x == 0) {
        p[0][y] = g[0][y] + p[0][y - 1];
        continue;
      }
      if (y == 0) {
        p[x][0] = g[x][0] + p[x - 1][y];
        continue;
      }
      p[x][y] = p[x - 1][y] + p[x][y - 1] - p[x - 1][y - 1] + g[x][y];
    }
  }

  pair<int, int> res = {INT_MAX, 0};

  for (int x = 0; x < w; x++) {
    for (int y = 0; y < w; y++) {
      int v = p[x][y];

      int l = 1;
      int r = min(y, x) + 2;
      while (l != r - 1) {
        int p = (r - l) / 2 + l;
        int s = sum(x, y, p);

        if (s == m) {
          l = p;
          r = p - 1;
        } else if (s > m) {
          r = p - 1;
        } else {
          l = p;
        }
      }

      int s = sum(x, y, l);
      if (res.second < s) {
        res = {l, s};
      } else if (res.second == s) {
        res.first = min(l, res.first);
      }
    }
  }

  cout << res.second << " " << res.first;
}

/*
5 10 25
0 0 3
0 3 2
0 4 6
1 1 1
1 3 5
1 4 1
2 2 20
3 2 10
4 0 5
4 4 1
*/
