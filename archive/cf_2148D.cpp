#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long res = 0;
    cin >> n;

    vector<int> o;

    for (int i = 0; i < n; ++i) {
      int el;
      cin >> el;

      if (el % 2 == 1) {
        // cout << " " << el << " " << el % 2 << " ";
        o.push_back(el);
      } else {
        // cout << el << " ";
        res += el;
      }
    }

    if (o.size() == 0) {
      cout << "0\n";
      continue;
    }

    sort(o.begin(), o.end());

    bool b = false;
    int hi = o.size();
    int lo = 0;
    while (lo < hi) {
      b = !b;
      if (b) {
        hi--;
        res += o[hi];
      } else {
        lo++;
      }
    }

    cout << res << "\n";
  }
}
