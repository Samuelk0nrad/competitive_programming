#include <bits/stdc++.h>
#include <vector>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n, 0);
  int im = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[im] < a[i])
      im = i;
  }
  cout << a[im] * n << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
