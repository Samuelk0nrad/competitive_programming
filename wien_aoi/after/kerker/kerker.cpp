#include "kerker.h"
#include "grader.cpp"
#include <bits/stdc++.h>
#include <cmath>
#include <vector>

using namespace std;

struct node {
  set<int> list;
  int l = -1;
  int r = -1;
};

int n;
vector<node> seg;

void build(int p, int r, int l) {
  seg[p].l = l;
  seg[p].r = r;
  if (r == l) {
    return;
  }
  build(p * 2, r, l / 2);
  build(p * 2 + 1, r / 2 + 1, l);
}

std::vector<int> find_combination(int n) {
  vector<int> res(n);

  seg.reserve(n * 4 + 5);
  build(1, 1, n);

  for (int i = 1; i <= n; i++) {
    seg[0].list.insert(i);
  }

  for (int i = 1; i <= ceil(log(n)); i++) {
  }

  return res;
}
