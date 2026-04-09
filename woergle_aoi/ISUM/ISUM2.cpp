#include "grader.cpp"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
vector<ll> sg;
vector<ll> lazy;

void init(int N) {
  n = N;
  sg.resize(N * 4, 0);
  lazy.resize(N * 4, 0);
}

void LP(int p, int l, int r) {
  if (lazy[p] == 0)
    return;

  sg[p] += (r - l) * lazy[p];

  if (l + 1 != r) {
    lazy[2 * p] += lazy[p];
    lazy[2 * p + 1] += lazy[p];
  }
  lazy[p] = 0;
}

void updateSg(int p, int l, int r, int ql, int qr, ll v) {
  LP(p, l, r);
  if (qr <= l || ql >= r) {
    return;
  }
  if (l >= ql && r <= qr) {
    lazy[p] += v;
    LP(p, l, r);
    return;
  }

  int mid = (r - l) / 2 + l;
  updateSg(2 * p, l, mid, ql, qr, v);
  updateSg(2 * p + 1, mid, r, ql, qr, v);
  sg[p] = sg[2 * p] + sg[2 * p + 1];
}

void update(int p, int q, int v) { updateSg(1, 1, n + 1, p, q + 1, v); }

ll querySg(int p, int l, int r, int ql, int qr) {
  LP(p, l, r);

  if (qr <= l || ql >= r) {
    return 0;
  }
  if (l >= ql && r <= qr) {
    return sg[p];
  }
  int mid = (r - l) / 2 + l;
  return querySg(2 * p, l, mid, ql, qr) + querySg(2 * p + 1, mid, r, ql, qr);
}

ll query(int p, int q) { return querySg(1, 1, n + 1, p, q + 1); }
