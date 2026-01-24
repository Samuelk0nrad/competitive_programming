// https://codeforces.com/problemset/problem/2173/A

#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  int res = 0;
  int li = -k - 10;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0' && li + k < i) {
      res++;
    }
    if (s[i] == '1') {
      li = i;
    }
  }

  cout << res << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
