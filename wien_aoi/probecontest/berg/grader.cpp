#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

long long solve(vector<int> a) {
  // a hat länge n
  int n = a.size();
  vector<ll> p(n, 0);

  for (int i = 0; i < n; i++) {
    if (i == 0)
      continue;
    for (int j = i - 1; j >= 0; j--) {
      if (a[i] == a[j]) {
        p[i] = p[j] + 1;
        break;
      } else if (a[i] < a[j]) {
        break;
      }
    }
  }

  ll res = 0;
  for (ll i : p) {
    res += i;
  }

  return res * 2;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  long long res = solve(a);
  cout << res << endl;
  return 0;
}
