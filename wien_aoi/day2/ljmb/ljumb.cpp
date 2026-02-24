#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

ll n, m;
vector<ll> a;

bool f(ll t) {
  ll c = 0;
  for (ll i = 0; i < m; ++i) {
    ll nc = (a[i] + t - 1) / t;
    c += nc;
    if (c > n) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> m;

  a.assign(m, 0);
  ll sum = 0;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    sum += a[i];
  }

  ll l = 1;
  ll r = sum;
  while (l < r) {
    ll m = ((r - l) / 2) + l;
    if (f(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  cout << r;
}
