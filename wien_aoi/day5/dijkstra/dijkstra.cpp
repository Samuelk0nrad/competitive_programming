#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

struct edge {
  int to;
  ll d;
  int from;
};

struct node {
  int i;
  bool fix;
  ll mind;
  int min_from;
  vector<edge> e;
  bool operator<(const node &x) const { return mind > x.mind; }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<node> s(n + 5);

  priority_queue<node> dq;
  for (int i = 0; i < m; i++) {
    int a, b;
    ll w;
    cin >> a >> b >> w;
    s[a].i = a;
    s[a].fix = false;
    s[a].e.push_back(edge{b, w, a});

    s[b].i = b;
    s[b].fix = false;
    s[b].e.push_back(edge{a, w, b});
  }
  for (int i = 1; i <= n; i++) {
    s[i].mind = LONG_LONG_MAX;
  }
  s[1].mind = 0;

  dq.push(s[1]);

  while (!dq.empty()) {
    auto e = dq.top();
    dq.pop();
    if (e.fix) {
      continue;
    }
    e.fix = true;

    for (auto i : s[e.i].e) {
      node *sn = &s[i.to];
      if (sn->fix) {
        continue;
      }
      if (sn->mind > e.mind + i.d) {
        sn->mind = e.mind + i.d;
        sn->min_from = e.i;
        dq.push(s[i.to]);
      }
    }
  }
  if (s[n].mind == LONG_LONG_MAX) {
    cout << -1 << "\n";
  }
  cout << s[n].mind << "\n";
  int i = n;
  vector<int> path;
  while (i > 0) {
    path.push_back(i);
    i = s[i].min_from;
  }
  for (int i = path.size() - 1; i >= 0; i--) {
    cout << path[i] << " ";
  }
}
