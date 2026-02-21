#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll M = 1e9 + 7;

int main() {
  ll n;
  cin >> n;

  ll a = 1, b = 1;
  for (ll i = 3; i <= n; i++) {
    ll tmp = a;
    a = b;
    b += tmp;
    b %= M;
  }

  cout << b;
}
