#include "ISUM.h"
#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

struct Node {
  ll sum;
  ll l;
};

int n;
vector<Node> sg;

void init(int N) {
  n = N;
  sg.resize(N * 4, Node{0});
}

void lazy(int p, int l, int r) {
  if (sg[p].l == 0)
    return;
  if (l == r - 1) {
    return;
  }
  sg[2 * p].l += sg[p].l;
  sg[2 * p].sum += sg[p].l;
  sg[2 * p + 1].l += sg[p].l;
  sg[2 * p + 1].sum += sg[p].l;
  sg[p].l = 0;
}

void updateSg(int p, int ul, int ur, int l, int r, int v) {
  lazy(p, l, r);
  if (ur <= l || ul >= r) {
    return;
  }
  if (l >= ul && r <= ur) {
    sg[p].l += v;
    sg[p].sum += v * (r - l);
    return;
  }
  updateSg(2 * p, ul, ur, l, (r - l) / 2 + l, v);
  updateSg(2 * p + 1, ul, ur, (r - l) / 2 + l, r, v);
  sg[p].sum = sg[2 * p].sum + sg[2 * p + 1].sum;
}

void update(int p, int q, int v) { updateSg(1, p, q + 1, 1, n + 1, v); }

ll querySg(int p, int ql, int qr, int l, int r) {
  lazy(p, l, r);
  if (qr <= l || ql >= r) {
    return 0;
  }
  if (l >= ql && r <= qr) {
    return sg[p].sum;
  }
  return querySg(2 * p, ql, qr, l, (r - l) / 2 + l) +
         querySg(2 * p + 1, ql, qr, (r - l) / 2 + l, r);
}

ll query(int a, int b) { return querySg(1, a, b + 1, 1, n + 1); }
