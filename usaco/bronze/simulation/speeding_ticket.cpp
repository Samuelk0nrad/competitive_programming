#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  freopen("speeding.in", "r", stdin);
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> a(n);
  vector<pair<int, int>> b(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
  }

  int al = a[0].first;
  int ai = 0;
  int bl = b[0].first;
  int bi = 0;
  int mdiff = 0;
  for (int i = 1; i <= 100; i++) {
    if (al < i) {
      ai++;
      al += a[ai].first;
    }
    if (bl < i) {
      bi++;
      bl += b[bi].first;
    }
    if (a[ai].second < b[bi].second) {
      mdiff = max(mdiff, b[bi].second - a[ai].second);
    }
  }
  freopen("speeding.out", "w", stdout);
  cout << mdiff;
}
