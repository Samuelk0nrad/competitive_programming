#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n + 5);
  a[0] = 0;
  ll e;
  for (int i = 1; i <= n; i++) {
    cin >> e;
    a[i] = e + a[i - 1];
  }
  ll c, b;
  for (int i = 0; i < q; i++) {
    cin >> c >> b;
    c--;
    cout << a[b] - a[c] << "\n";
  }
}
