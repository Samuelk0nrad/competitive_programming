#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  // freopen("speeding.in", "r", stdin);
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> a(n);
  vector<pair<int, int>> b(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    if (i > 0) {
      a[i].first += a[i - 1].first;
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
    if (i > 0) {
      b[i].first += b[i - 1].first;
    }
  }

  int mdiff = 0;
  int i = 0;
  int ia = 0;
  int ib = 0;
  while (i < 100) {
    mdiff = max(b[ib].second - a[ia].second, mdiff);
    if (b[ib].first < a[ia].first) {
      i = b[ib].first + 1;
      ib++;
    } else if (b[ib].first == a[ia].first) {
      i = a[ia].first + 1;
      ia++;
      ib++;
    } else {
      i = a[ia].first + 1;
      ia++;
    }
  }

  //  freopen("speeding.out", "w", stdout);
  cout << mdiff;
}
