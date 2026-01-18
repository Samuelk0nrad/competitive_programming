#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a;

    for (int i = 0; i < n; ++i) {
      int e;
      cin >> e;

      a.push_back(e);
    }

    sort(a.begin(), a.end());

    int res = 0;

    for (auto e : a) {
      if (res == e) {
        res++;
      } else if (res < e) {
        break;
      }
    }

    cout << res << "\n";
  }
}
