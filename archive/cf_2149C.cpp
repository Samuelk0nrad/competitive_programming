#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, res = 0, res2 = 0;
    cin >> n >> k;

    vector<int> b;

    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;
      b.push_back(e);

      if (e == k)
        res2++;
    }

    sort(b.begin(), b.end());

    int last = -1;

    for (int i = 0; i < n; ++i) {
      int e = b[i];
      if (e == last) {
        continue;
      } else if (e >= k) {
        res += k - last - 1;
        break;
      } else if (e == last + 1) {
        last = e;
      } else {
        res += e - last - 1;
        last = e;
      }
    }

    if (b[n - 1] < k) {
      res += k - b[n - 1] - 1;
    }

    cout << max(res, res2) << "\n";
  }
}
