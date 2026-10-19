#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;
const ll M = 1000000007;

struct Fen {
  int n;
  vector<int> t;

  Fen(int n) : n(n), t(n + 5, 0) {}

  void add(int i, int d) {
    while (i <= n) {
      t[i] += d;
      i += i & -i;
    }
  }

  ll ps(int i) {
    ll res = 0;
    while (i > 0) {
      res += t[i];
      i -= i & -i;
    }
    return res;
  }
};

int main() {
  ll n = 1;
  ll a, b;
  char c;

  cin >> a >> c >> b;
  n = b + 1;

  vector<ll> p2(n + 1);
  p2[0] = 1;
  for (ll i = 1; i < n; i++) {
    p2[i] = p2[i - 1] * 2 % M;
  }

  vector<int> s;
  Fen tree(n);
  s.push_back(0);
  ll ld = 0;
  ll res = 1;
  for (int i = 1; i < n; i++) {
    cin >> a >> c >> b;
    if (ld + 1 != a) {
      for (ll j = 0; j <= ld - a; j++) {
        int x = s.back();
        tree.add(x + 1, -1);
        s.pop_back();
      }
    }
    int x = tree.ps(b + 1);
    res = res * p2[x] % M;
    tree.add(b + 1, 1);
    s.push_back(b);
    ld = a;
  }
  cout << res;
}

// 0/5
// 1/0
// 2/1
// 3/2
// 4/3
// 5/4
