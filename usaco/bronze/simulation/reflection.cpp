#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int>> paint;

vector<string> pp;

int mi(int i, int n) {
  if (i > n) {
    return n - (i - (n + 1));
  } else {
    return i;
  }
}

int rr(int e) {
  if (e >= 2) {
    return 4 - e;
  } else {
    return e;
  }
}

int main() {
  int N, u;
  cin >> N >> u;
  int n = N / 2;

  paint.resize(n + 5, vector<int>(n + 5));
  pp.resize(N + 5);

  for (int r = 1; r <= N; r++) {
    cin >> pp[r - 1];
    for (int c = 1; c <= N; c++) {
      if (pp[r - 1][c - 1] == '.')
        continue;
      paint[mi(r, n)][mi(c, n)]++;
    }
  }

  int res = 0;

  for (auto &i : paint) {
    for (int &e : i) {
      if (e >= 2) {
        res += 4 - e;
      } else {
        res += e;
      }
    }
  }

  cout << res << endl;

  int r, c;
  for (int i = 0; i < u; i++) {
    cin >> r >> c;

    int ra = rr(paint[mi(r, n)][mi(c, n)]);
    int rn = 0;

    if (pp[r - 1][c - 1] == '.') {
      pp[r - 1][c - 1] = '#';
      paint[mi(r, n)][mi(c, n)]++;
      rn = rr(paint[mi(r, n)][mi(c, n)]);
    } else {
      pp[r - 1][c - 1] = '.';
      paint[mi(r, n)][mi(c, n)]--;
      rn = rr(paint[mi(r, n)][mi(c, n)]);
    }
    res += rn - ra;
    cout << res << endl;
  }
}
