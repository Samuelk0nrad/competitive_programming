#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct SegTree {
  int n;
  vector<ll> st, lazy;

  SegTree(int n) : n(n) {
    st.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
  }

  void build(int p, int l, int r, const vector<ll> &a) {
    if (r - l == 1) {
      st[p] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m, a);
    build(2 * p + 1, m, r, a);
    st[p] = st[2 * p] + st[2 * p + 1];
  }

  void apply(int p, int l, int r, ll val) {
    st[p] += (r - l) * val;
    lazy[p] += val;
  }

  void push(int p, int l, int r) {
    if (lazy[p] == 0)
      return;
    int m = (l + r) / 2;
    apply(2 * p, l, m, lazy[p]);
    apply(2 * p + 1, m, r, lazy[p]);
    lazy[p] = 0;
  }

  void update(int p, int l, int r, int i, int j, ll val) {
    if (j <= l || r <= i)
      return; // no overlap
    if (i <= l && r <= j) {
      apply(p, l, r, val);
      return;
    }
    push(p, l, r);
    int m = (l + r) / 2;
    update(2 * p, l, m, i, j, val);
    update(2 * p + 1, m, r, i, j, val);
    st[p] = st[2 * p] + st[2 * p + 1];
  }

  ll query(int p, int l, int r, int i, int j) {
    if (j <= l || r <= i)
      return 0; // no overlap
    if (i <= l && r <= j)
      return st[p];
    push(p, l, r);
    int m = (l + r) / 2;
    return query(2 * p, l, m, i, j) + query(2 * p + 1, m, r, i, j);
  }
};
