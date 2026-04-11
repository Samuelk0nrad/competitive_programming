#include <bits/stdc++.h>
#define ll long long

using namespace std;

int rsum(int x) { return (x * x + x) / 2; }

pair<int, int> s(int x, int st) {
  x = rsum(st) + x;
  int l = st;
  int r = 500;
  while (l != r) {
    int m = (r - l) / 2 + l;
    if (rsum(m) == x) {
      l = m;
      r = m;
      break;
    } else if (rsum(m) < x) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  int res = l;
  int v = rsum(res) - x;
  if (v >= rsum(st) && v <= rsum(res)) {
    return {res, v};
  }
  return {res, 0};
}

int c(int h1, int h2, int h3, int a1, int a2, int a3) {
  pair<int, int> s1 = s(h1, 0);
  pair<int, int> s2;
  if (h2 - s1.second <= 0) {
    s2 = {s1.second, 0};
  }
  pair<int, int> s3;
  if (h3 - s2.second <= 0) {
    s3 = {s2.second, 0};
  }

  return (s1.first * a1 + s2.first * a2 + s3.first * a3);
}

int main() {
  ll h1, h2, h3, a1, a2, a3;
  cin >> h1 >> h2 >> h3 >> a1 >> a2 >> a3;
  int ans = INT_MAX;

  ans = min(ans, c(h1, h2, h3, a1, a2, a3));
  ans = min(ans, c(h1, h3, h2, a1, a3, a2));

  ans = min(ans, c(h2, h1, h3, a2, a1, a3));
  ans = min(ans, c(h2, h3, h1, a2, a3, a1));

  ans = min(ans, c(h3, h1, h2, a3, a1, a2));
  ans = min(ans, c(h3, h2, h1, a3, a2, a1));

  cout << ans;
}
