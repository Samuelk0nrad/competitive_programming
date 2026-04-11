#include <bits/stdc++.h>

using namespace std;

int g[505][505];
int p[505][505];

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

      for (int i = 1; i <= min(y, x) + 1; i++) {
        if (x - i < 0 && y - i < 0) {
          int sum = v;
          if (sum <= m) {
            if (res.second < sum) {
              res = {i, sum};
            } else if (res.second == sum) {
              res.first = min(i, res.first);
            }
          }
          continue;
        } else if (x - i < 0) {
          int sum = v - p[x][y - i];
          if (sum <= m) {
            if (res.second < sum) {
              res = {i, sum};
            } else if (res.second == sum) {
              res.first = min(i, res.first);
            }
          }
          continue;
        } else if (y - i < 0) {
          int sum = v - p[x - i][y];
          if (sum <= m) {
            if (res.second < sum) {
              res = {i, sum};
            } else if (res.second == sum) {
              res.first = min(i, res.first);
            }
          }
          continue;
        }
        int sum = ((v - p[x][y - i]) - p[x - i][y]) + p[x - i][y - i];
        if (sum <= m) {
          if (res.second < sum) {
            res = {i, sum};
          } else if (res.second == sum) {
            res.first = min(i, res.first);
          }
        }
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
