#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

struct Node {
  int m;
  int l;
  int r;
  int a;
  bool v = true;
};

Node comp(Node &l, Node &r) {
  int m = l.m + r.m;
  if (!l.v)
    m = r.m;
  else if (!r.v)
    m = l.m;
  Node res = Node{
      m,
      max(m, max(l.l, r.v && l.v ? l.m + r.l : INT_MIN)),
      max(m, max(r.r, l.v && r.v ? l.r + r.m : INT_MIN)),
      max(l.v && r.v ? l.r + r.l : INT_MIN, max(l.a, r.a)),
      true,
  };
  return res;
}

vector<Node> sg;

void build(int p, int l, int r, vector<int> &a) {
  if (l == r - 1) {
    sg[p].a = a[l];
    sg[p].l = a[l];
    sg[p].r = a[l];
    sg[p].m = a[l];
    sg[p].v = true;
    return;
  }
  int mid = (r - l) / 2 + l;
  build(2 * p, l, mid, a);
  build(2 * p + 1, mid, r, a);
  sg[p] = comp(sg[2 * p], sg[2 * p + 1]);
}

void update(int p, int l, int r, int i, int v) {
  if (i < l || i >= r) {
    return;
  }
  if (l == r - 1 && l == i) {
    sg[p].a = v;
    sg[p].l = v;
    sg[p].r = v;
    sg[p].m = v;
    return;
  }
  int mid = (r - l) / 2 + l;
  update(2 * p, l, mid, i, v);
  update(2 * p + 1, mid, r, i, v);

  sg[p] = comp(sg[2 * p], sg[2 * p + 1]);
}

Node query(int p, int l, int r, int ql, int qr) {
  if (qr <= l || ql >= r) {
    return Node{INT_MIN, INT_MIN, INT_MIN, INT_MIN, false};
  }
  if (l >= ql && r <= qr) {
    return sg[p];
  }
  int mid = (r - l) / 2 + l;
  Node a = query(2 * p, l, mid, ql, qr);
  Node b = query(2 * p + 1, mid, r, ql, qr);
  return comp(a, b);
}

int main() {
  int n;
  cin >> n;
  sg.resize(4 * n, Node{INT_MIN, INT_MIN, INT_MIN, INT_MIN, false});
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(1, 0, n, a);
  int m;
  cin >> m;
  int q, x, y;
  for (int i = 0; i < m; i++) {
    cin >> q >> x >> y;
    if (q == 0) {
      update(1, 0, n, x - 1, y);
    } else if (q == 1) {
      cout << query(1, 0, n, x - 1, y).a << "\n";
    }
  }
}
