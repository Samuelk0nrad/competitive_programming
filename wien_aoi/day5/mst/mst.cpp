#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

struct edge {
  int to;
  int from;
  ll wight;
  bool operator<(const edge &x) const { return wight < x.wight; }
};

struct node {
  int size;
  int perent;
  vector<edge> e;
};
vector<edge> e;
vector<node> a;

int find(int i) {
  while (a[i].perent != i) {
    i = a[i].perent;
  }
  return i;
}

bool same(int f, int b) { return find(f) == find(b); }

void comp(int f, int b) {
  f = find(f);
  b = find(b);
  if (a[f].size > a[b].size) {
    a[b].perent = f;
    a[f].size += a[b].size + 1;
  } else {
    a[f].perent = b;
    a[b].size += a[f].size + 1;
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  e.resize(m + 5);
  a.resize(n + 5);

  int from, to, wight;
  for (int i = 0; i < m; i++) {
    cin >> from >> to >> wight;
    e[i] = {to, from, wight};
  }
  sort(e.begin(), e.end());
  for (int i = 1; i <= n; i++) {
    a[i].perent = i;
  }

  ll res = 0;

  for (auto i : e) {
    if (!same(i.from, i.to)) {
      comp(i.from, i.to);
      res += i.wight;
    }
  }
  cout << res << " ";
}
