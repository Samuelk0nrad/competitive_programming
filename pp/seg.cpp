#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> num;
vector<int> seg;
vector<int> lazy;

void build(int p, int l, int r) {
  if (r - 1 == l) {
    seg[p] = num[l];
    return;
  }

  int m = (r - l) / 2 + l;
  build(p * 2, m, r);
  build(p * 2 + 1, l, m);
  seg[p] = min(seg[p * 2], seg[2 * p + 1]);
}

void prop(int p, int l, int r) {
  if (r - 1 == l) {
    seg[p] += lazy[p];
    lazy[p] = 0;
  } else {
    seg[p] += lazy[p] * (r - l);
    lazy[p * 2 + 1] += lazy[p];
    lazy[p * 2] += lazy[p];
    lazy[p] = 0;
  }
}

int query(int p, int l, int r, int ql, int qr) {
  prop(p, l, r);
  if (ql <= l && qr >= r) {
    return seg[p];
  }
  if (r <= ql || l >= qr) {
    return 0;
  }

  int m = (r - l) / 2 + l;
  return query(p * 2, m, r, ql, qr) + query(p * 2 + 1, l, m, ql, qr);
}

void update(int p, int l, int r, int ql, int qr, int diff) {
  if (r <= qr || l >= ql) {
    return;
  }
  if (ql <= l && qr >= r) {
    lazy[p] += diff;
    prop(p, l, r);
    return;
  }
  prop(p, l, r);
  int m = (r - l) / 2 + l;
  update(p * 2, m, r, ql, qr, diff);
  update(p * 2 + 1, l, m, ql, qr, diff);
  seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

int main() {
  int n, q;
  cin >> n >> q;
  num.resize(n + 5);
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }

  seg.resize(4 * n, 0);
  lazy.resize(4 * n, 0);
  build(1, 0, n);

  int a, b, u, k;
  int t;
  for (int i = 0; i < q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> a >> b >> u;
      update(1, 0, n, a - 1, b, u);
    } else {
      cin >> k;
      cout << query(1, 0, n, k - 1, k);
    }
  }
}
