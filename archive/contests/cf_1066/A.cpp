#include <bits/stdc++.h>
#include <set>
#include <vector>

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

    int res = 0;
    int last = -1;
    int lastCount = 0;
    for (auto e : a) {
      if (e == last) {
        lastCount++;
      } else {
        if (last == -1) {
        } else if (last < lastCount) {
          res += lastCount - last;
        } else if (last != lastCount) {
          res += lastCount;
        }
        lastCount = 1;
        last = e;
      }
    }

    if (last < lastCount) {
      res += lastCount - last;
    } else if (last != lastCount) {
      res += lastCount;
    }
    cout << res << "\n";
  }
}
