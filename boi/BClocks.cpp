#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> c(k, 0);
    int e;
    for (int i = 0; i < n; i++) {
      cin >> e;
      c[e]++;
    }
    int o = 0;
    int ue = 0;
    for (int e : c) {
      if (e == 1) {
        o++;
      } else if (e % 2 == 1) {
        ue++;
      }
    }
  }
}
