#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int c = 0;
  int m = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      c++;
      continue;
    }
    if (a[i] != a[i - 1] + 1 && a[i] != a[i - 1]) {
      if (c > m) {
        m = c;
      }
      c = 1;
    } else if (a[i] == a[i - 1] + 1) {
      c++;
    }
  }

  if (c > m) {
    m = c;
  }
  cout << m << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
