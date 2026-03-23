#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct node {
  int last, current, i, deeph;
  bool operator<(const node &x) const { return deeph < x.deeph; }
  bool operator>(const node &x) const { return deeph > x.deeph; }
};

int main() {
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // last, current, i, deeph
    priority_queue<node> s;
    s.push({-1, a[0], 0, 0});
    int res = INT_MAX;

    while (!s.empty()) {
      auto e = s.top();
      s.pop();

      if (e.i + 1 < n && (e.last == e.current || e.last == -1)) {
        res = e.deeph;
      } else if (e.i + 1 < n) {
        continue;
      }

      if (e.last < e.current && e.last != -1) {
        continue;
      }

      if (e.i + 1 < n && (e.last == e.current || e.last == -1)) {
        s.push(node{e.current, a[e.i + 1], e.i + 1, e.deeph});
      }

      if (e.i + 1 < n) {
        s.push(node{e.last, e.current + a[e.i + 1], e.i + 1, e.deeph + 1});
      }
    }

    cout << res << "\n";
  }
}
