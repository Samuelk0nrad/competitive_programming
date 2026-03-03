#include <bits/stdc++.h>
#include <deque>
#include <vector>

using namespace std;

struct thema {
  vector<int> before;
  vector<int> after;
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<thema> a(n + 5);

  for (int i = 0; i < m; i++) {
    int t, b;
    cin >> t >> b;
    a[t].after.push_back(b);
    a[b].before.push_back(t);
  }

  vector<int> res;
  deque<int> dq;

  for (int i = 1; i <= n; i++) {
    if (a[i].before.size() == 0) {
      dq.push_back(i);
    }
  }

  while (!dq.empty()) {
    int i = dq.back();
    dq.pop_back();
    res.push_back(i);
    for (int e : a[i].after) {
      bool ok = true;
      for (int &b : a[e].before) {
        if (b == i) {
          b = -1;
        } else if (b != -1) {
          ok = false;
        }
      }
      if (ok) {
        dq.push_back(e);
      }
    }
  }
  for (int i : res) {
    cout << i << " ";
  }
}
