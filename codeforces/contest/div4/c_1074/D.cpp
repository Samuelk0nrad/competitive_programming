#include <bits/stdc++.h>
#include <vector>

#define ll long long

using namespace std;

void solve() {
  ll n, m, h;
  cin >> n >> m >> h;

  vector<int> a(n + 10, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> res(a.begin(), a.end());
  int reset = 0;
  vector<int> lre(n + 10, 0);
  for (int i = 0; i < m; ++i) {
    ll b, c;
    cin >> b >> c;
    if (lre[b] < reset) {
      lre[b] = reset;
      res[b] = a[b];
    }
    ll s = res[b] + c;
    if (s > h) {
      reset++;
    } else {
      res[b] += c;
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (lre[i] < reset) {
      cout << a[i] << " ";
    } else {
      cout << res[i] << " ";
    }
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
