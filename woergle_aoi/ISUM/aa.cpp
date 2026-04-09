#include "grader.cpp"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
vector<ll> sg;
vector<ll> lazy;

void init(int N) {
  n = N;
  sg.assign(4 * n, 0);
  lazy.assign(4 * n, 0);
}

void push(int p, int l, int r) {
  if (lazy[p] == 0)
    return;

  sg[p] += (r - l) * lazy[p];

  if (r - l > 1) {
    lazy[2 * p] += lazy[p];
    lazy[2 * p + 1] += lazy[p];
  }

  lazy[p] = 0;
}

void updateSg(int p, int l, int r, int ql, int qr, ll v) {
  push(p, l, r);

  if (qr <= l || r <= ql)
    return;

  if (ql <= l && r <= qr) {
    lazy[p] += v;
    push(p, l, r);
    return;
  }

  int mid = (l + r) / 2;
  updateSg(2 * p, l, mid, ql, qr, v);
  updateSg(2 * p + 1, mid, r, ql, qr, v);

  sg[p] = sg[2 * p] + sg[2 * p + 1];
}

ll querySg(int p, int l, int r, int ql, int qr) {
  push(p, l, r);

  if (qr <= l || r <= ql)
    return 0;

  if (ql <= l && r <= qr) {
    return sg[p];
  }

  int mid = (l + r) / 2;
  return querySg(2 * p, l, mid, ql, qr) + querySg(2 * p + 1, mid, r, ql, qr);
}

void update(int p, int q, int v) { updateSg(1, 1, n + 1, p, q + 1, v); }

ll query(int p, int q) { return querySg(1, 1, n + 1, p, q + 1); }
