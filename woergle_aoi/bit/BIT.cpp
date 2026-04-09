#include "grader.cpp"
#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

int n;
vector<ll> sg;

void init(int N) {
  n = N;
  sg.resize(N * 4, 0);
}

void updateSg(int i, int v, int p, int l, int r) {
  if (l > i || r <= i) {
    return;
  }
  if (l == r - 1 && l == i) {
    sg[p] += v;
    return;
  }
  updateSg(i, v, 2 * p, l, (r - l) / 2 + l);
  updateSg(i, v, 2 * p + 1, (r - l) / 2 + l, r);
  sg[p] = sg[2 * p] + sg[2 * p + 1];
}

void update(int i, int v) { updateSg(i, v, 1, 1, n + 1); }

ll querySg(int p, int ql, int qr, int l, int r) {
  if (qr <= l || ql >= r) {
    return 0;
  }
  if (l >= ql && r <= qr) {
    return sg[p];
  }
  return querySg(2 * p, ql, qr, l, (r - l) / 2 + l) +
         querySg(2 * p + 1, ql, qr, (r - l) / 2 + l, r);
}

ll query(int a, int b) { return querySg(1, a, b + 1, 1, n + 1); }
