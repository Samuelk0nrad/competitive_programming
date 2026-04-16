#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  ll sum = 0;
  ll res = 0;
  deque<ll> q;
  ll x, a, b, c;
  cin >> x >> a >> b >> c;
  ll lx = x;
  ll e = lx;
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      e = (a * lx + b) % c;
    }
    sum += e;
    q.push_back(e);
    if (i >= k - 1) {
      res ^= sum;
      sum -= q.front();
      q.pop_front();
    }
    lx = e;
  }
  cout << res;
}
