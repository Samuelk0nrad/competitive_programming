#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return a.first > b.first;
  }
  return a.second < b.second;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n + 1, -1);
    vector<pair<int, int>> p;
    vector<int> sm(n + 1);
    vector<int> em(n + 1);
    vector<bool> m(n + 1, false);

    for (int i = 1; i <= q; ++i) {
      int c, l, r;
      cin >> c >> l >> r;

      if (c == 1) {
        sm[l]++;
        em[r]++;
      } else {
        p.push_back({l, r});
      }
    }

    int min = 0;
    for (int i = 1; i <= n; ++i) {
      min += sm[i];

      if (min >= 1) {
        a[i] = k;
        m[i] = true;
      }

      min -= em[i];
    }

    sort(p.begin(), p.end(), comp);

    for (auto e : p) {
      int c = -1;
      set<int> f;
      bool next = true;

      for (int i = e.first; i <= e.second; ++i) {
        if (a[i] != -1 && a[i] < k) {
          f.insert(a[i]);
        }
      }

      for (int i = e.first; i <= e.second; ++i) {
        if (next) {
          if (c >= k) {
            c = k + 1;
          }
          bool ok = false;
          for (int i = c + 1; i < k; ++i) {
            if (f.count(i) == 0) {
              c = i;
              ok = true;
              break;
            }
          }
          if (!ok)
            c = k + 1;
          next = false;
        }
        if (m[i]) {
          a[i] = k + 1;
        } else if (a[i] == -1 || a[i] > k) {
          a[i] = c;
          next = true;
        } else {
          f.insert(a[i]);
        }
      }
    }
    bool first = true;
    for (int e : a) {
      if (first) {
        first = false;
        continue;
      }
      if (e == -1) {
        cout << 0 << " ";
      } else
        cout << e << " ";
    }
    cout << "\n";
  }
}
