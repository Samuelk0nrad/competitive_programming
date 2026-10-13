#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> c(k + 1, 0);
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
    vector<int> s(n);
    if (o > 1 || (ue % 2 == 1 && o == 1)) {
      cout << "NO\n";
    } else if (n % 2 == 0 && ue + o > 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      int p = 0;
      bool u = false;
      if (n % 2 == 0) {
        u = true;
      }
      vector<int> th;
      for (int i = 0; i <= k; i++) {
        int e = c[i];
        while ((e % 2 == 1 && e > 3) || (e % 2 == 0 && e > 0)) {
          s[p] = i;
          s[(n - 1) - p] = i;
          p++;
          e -= 2;
        }
        if (e == 3) {
          if (o == 0 && !u) {
            u = true;
            s[n / 2] = i;
            s[p] = i;
            s[(n - 1) - p] = i;
            p++;
          } else {
            th.push_back(i);
          }
        } else if (e == 1) {
          s[n / 2] = i;
          u = true;
        }
      }
      for (int i = 0; i < th.size(); i += 2) {
        s[p] = th[i + 1];
        s[p + 1] = th[i];
        s[p + 2] = th[i];

        int po = (n - 1) - p;

        s[po - 2] = th[i + 1];
        s[po - 1] = th[i + 1];
        s[po] = th[i];
        p += 3;
      }
      for (int e : s) {
        cout << e << " ";
      }
      cout << "\n";
    }
  }
}
