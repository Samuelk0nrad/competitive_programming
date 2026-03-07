#include "kerker.h"
#include "grader.cpp"
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

struct node {
  vector<int> list;
  int l = -1;
  int r = -1;
};

int n;
vector<node> seg;

void build(int p, int l, int r) {
  seg[p].l = l;
  seg[p].r = r;
  if (r == l) {
    return;
  }
  build(p * 2, l, (r - l) / 2 + l);
  build(p * 2 + 1, (r - l) / 2 + l + 1, r);
}

std::vector<int> find_combination(int n) {
  vector<int> res(n);

  seg.resize(n * 4 + 5);
  build(1, 1, n);

  for (int i = 1; i <= n; i++) {
    seg[1].list.push_back(i);
  }

  vector<int> mark;
  vector<int> ans;
  for (int d = 0; d < ceil(log2(n)); d++) {
    int start = (1 << d);
    int end = (1 << (d + 1)) - 1;
    for (int p = start; p <= end; p++) {
      if (seg[p].l == -1 || seg[p].l == seg[p].r) {
        continue;
      }
      int m = (seg[p].r - seg[p].l) / 2 + seg[p].l;
      for (int i = seg[p].l; i <= m; i++) {
        mark.push_back(i);
      }
    }

    ans = mark_lock(mark);
    sort(ans.begin(), ans.end());

    for (int p = start; p <= end; p++) {
      if (seg[p].l == -1)
        continue;
      if (seg[p].l == seg[p].r) {
        res[seg[p].l - 1] = seg[p].list[0];
        continue;
      }
      for (int i : seg[p].list) {
        if (binary_search(ans.begin(), ans.end(), i)) {
          seg[p * 2].list.push_back(i);
        } else {
          seg[p * 2 + 1].list.push_back(i);
        }
      }
    }

    mark.resize(0);
  }

  for (node &i : seg) {
    if (i.l == -1)
      continue;
    if (i.l == i.r && !i.list.empty()) {
      res[i.l - 1] = i.list[0];
    }
  }

  return res;
}
