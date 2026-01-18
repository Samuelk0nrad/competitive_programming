#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    multiset<int> a;

    for (int i = 0; i < n; ++i) {
      int e;
      cin >> e;
      a.insert(e);
    }

    long long res = -1;

    for (auto e : a) {
      if (res == -1) {
        res = e + 1;
      } else {
        res *= e;
      }
    }

    cout << res << "\n";
  }
}
