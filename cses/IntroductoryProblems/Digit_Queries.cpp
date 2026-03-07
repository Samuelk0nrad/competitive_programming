// https://cses.fi/problemset/result/16039337/
#include <bits/stdc++.h>
#include <cmath>
#define ll long long

using namespace std;

void solve(ll k) {
  ll r = k;
  char res = 0;
  ll t = 1;
  for (int i = 1; true; ++i) {
    ll z = pow(10l, i - 1);
    ll p = (pow(10l, i) - t) * i;
    if (p < r) {
      r -= p;
      t = p;
      continue;
    }

    ll m = (r - 1) / i;
    ll f = m + z;

    string s = to_string(f);

    res = s[(r - 1) % i];

    t = p;
    break;
  }
  cout << res << "\n";
}

int main() {
  ll q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    ll k;
    cin >> k;
    solve(k);
  }
}
