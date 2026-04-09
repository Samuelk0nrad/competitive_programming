#include <vector>
#ifdef EVAL
#include "trolls.h"
#else
#include "grader.cpp"
#endif

using namespace std;

struct Node {
  vector<Troll> a;
  int d;
};

vector<Node> sg;

Node comp(const Node &l, const Node &r) {
  Node res = Node{{}, 0};
  Troll last;
  for (auto t : l.a) {
    if (t.h > last.h) {
      res.a.push_back(t);
      last = t;
      res.d += t.s;
    }
  }

  for (auto t : r.a) {
    if (t.h > last.h) {
      res.a.push_back(t);
      last = t;
      res.d += t.s;
    }
  }
  return res;
}

void build(int p, int l, int r, vector<Troll> &t) {
  if (l == r - 1) {
    sg[p] = Node{{t[l]}, t[l].s};
    return;
  }
  int mid = (r - l) / 2 + l;
  build(2 * p, l, mid, t);
  build(2 * p + 1, mid, r, t);
  sg[p] = comp(sg[2 * p], sg[2 * p + 1]);
}

struct Q {
  int h;
  int d;
  bool c;
  int l;
};

Q query(int p, int l, int r, int d, int k, int h) {
  if (r <= k) {
    return Q{0, 0, true, -1};
  }
  if (l == r - 1) {
    if (sg[p].d <= d) {
      return Q{
          sg[p].a[0].h,
          sg[p].d,
          true,
          -1,
      };
    } else {
      return Q{
          0,
          0,
          false,
          r,
      };
    }
  }
  if (l >= k && sg[p].d <= d) {
    int cd = 0;
    int lh = h;
    for (auto t : sg[p].a) {
      if (t.h >= lh) {
        d += t.s;
        lh = t.h;
      }
    }
    return Q{
        lh,
        cd,
        true,
        -1,
    };
  }
  int mid = (r - l) / 2 + l;
  Q s = query(2 * p, l, mid, d, k, h);
  if (s.c) {
    return query(2 * p + 1, mid, r, d - s.d, k, s.h);
  } else {
    return s;
  }
}

vector<int> simulateAttacks(vector<Troll> trolls, vector<Query> queries) {
  int N = trolls.size();
  int Q = queries.size();
  vector<int> results(Q);

  sg.assign(4 * N, Node{});
  build(1, 0, N, trolls);

  for (int j = 0; j < Q; j++) {
    // queries[j].k
    // queries[j].damage
    auto res = query(1, 0, N, queries[j].d, queries[j].k, 0);

    if (res.c) {
      results[j] = 0;
    } else {
      results[j] = res.l;
    }
  }

  return results;
}
