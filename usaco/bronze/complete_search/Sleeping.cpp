#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct node {
  int last, cur, i, w;
  bool operator<(const node &x) const { return w + cur > x.w + cur; }
  bool operator>(const node &x) const { return w + cur < x.w + cur; }
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
    s.push({-1, a[0], 1, 0});

    while (!s.empty()) {
      auto e = s.top();
      s.pop();

      cout << e.i << " " << e.w << " " << e.last << " " << e.cur << "\n";
      if (e.i >= n) {
        if (e.last == e.cur || e.last == -1) {
          cout << e.w << "\n";
          break;
        }
        continue;
      }

      if (e.last < e.cur && e.last != -1) {
        continue;
      }

      if (e.i < n && (e.last == e.cur || e.last == -1)) {
        s.push(node{e.cur, a[e.i], e.i + 1, e.w});
      }

      if (e.i < n) {
        s.push(node{e.last, e.cur + a[e.i], e.i + 1, e.w + 1});
      }
    }
  }
}
