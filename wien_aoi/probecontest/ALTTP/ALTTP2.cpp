#include <bits/stdc++.h>

using namespace std;

struct bedingung {
  set<int> list;
  void finish(int i) { list.erase(i); }
  bool check() { return list.size() == 0; }
};

struct item {
  int i;
  bool found = true;
  vector<bedingung> b;
  vector<int> need;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;

  vector<item> a(n + 5);
  for (int i = 1; i <= n; i++) {
    a[i].i = i;
  }

  int in, k;
  int e;
  for (int i = 0; i < m; i++) {
    cin >> in >> k;
    bedingung b;
    a[in].found = false;
    for (int j = 0; j < k; j++) {
      cin >> e;
      b.list.insert(e);
      a[e].need.push_back(in);
    }
    a[in].b.push_back(b);
    a[in].i = in;
  }

  vector<int> res;

  deque<int> dq;
  for (int i = 1; i <= n; i++) {
    if (a[i].found) {
      dq.push_back(i);
    }
  }

  while (!dq.empty()) {
    int i = dq.back();
    dq.pop_back();

    res.push_back(i);

    for (auto j : a[i].need) {
      item &item = a[j];
      if (item.found)
        continue;
      for (auto &b : item.b) {
        b.finish(i);
        if (b.check()) {
          item.found = true;
          dq.push_front(item.i);
          break;
        }
      }
    }
  }

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (!a[i].found) {
      ok = false;
    }
  }
  if (ok) {
    for (int i : res) {
      cout << i << " ";
    }
  } else {
    cout << -1;
  }
}
