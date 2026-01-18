#include <bits/stdc++.h>

using namespace std;

long long c(multiset<int>) { return 0; }

long long r(int v) {
  if (v == 1) {
    return 1;
  }
  return (r(v - 1) * 2 + 1) % 998244353;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    multiset<int> a;
    set<int> b;

    for (int i = 0; i < n; ++i) {
      int e;
      cin >> e;
      a.insert(e);
      b.insert(e);
    }

    cout << ((r(b.size()) - c(a))) % 998244353 << "\n";
  }
}
