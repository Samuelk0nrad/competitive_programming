#include "grader.cpp"
#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

const ll M = 1e9 + 9;

vector<ll> up;
vector<ll> down;
// range / hight
vector<pair<ll, ll>> range;

struct Node {
  vector<ll> arr;
};

vector<Node> seg;

void build(vector<ll> &arr, int p, int l, int r) {
  if (r - 1 == l) {
    seg[p] = Node{arr = {arr[p]}};
    return;
  }
  build(arr, 2 * p, l, (r - l) / 2 + l);
  build(arr, 2 * p + 1, (r - l) / 2 + l, r);
  vector<ll> n;
  int id = 0;
  int iu = 0;
  while (true) {
    if (id >= seg[2 * p].arr.size() && iu >= seg[2 * p + 1].arr.size()) {
      break;
    } else if (id >= seg[2 * p].arr.size()) {
      n.push_back(seg[2 * p + 1].arr[iu]);
    } else if (iu >= seg[2 * p + 1].arr.size()) {
      n.push_back(seg[2 * p].arr[id]);
    } else if (seg[2 * p].arr.size() > seg[2 * p + 1].arr.size()) {
      n.push_back(seg[2 * p + 1].arr.size());
    } else {
      n.push_back(seg[2 * p].arr.size());
    }
  }
}

int calculate(vector<pair<long, long>> &intervals) {
  for (auto e : intervals) {
    up.push_back(e.first);
    down.push_back(++e.second);
  }
  sort(up.begin(), up.end());
  sort(down.begin(), down.end());
  ll v = 0;
  ll i = 0;
  ll iu = 0;
  ll id = 0;
  ll lc = 0;
  ll mv = 0;
  while (iu < intervals.size() || id < intervals.size()) {
    if (iu < intervals.size() && i == up[iu]) {
      v++;
      iu++;
      continue;
    }
    if (id < intervals.size() && i == down[id]) {
      v--;
      id++;
      continue;
    }
    if (iu < intervals.size() &&
        (id >= intervals.size() || up[iu] <= down[id])) {
      i = up[iu];
    } else if (id < intervals.size()) {
      i = down[id];
    }
    mv = max(mv, v);
    range.push_back({i - lc, v});
    lc = i;
  }

  ll best1 = 1e18, best2 = 1e18;
  bool exists = false;
  for (auto [len, h] : range) {
    if (h <= best1) {
      best1 = h;
    } else if (h <= best2) {
      best2 = h;
    } else {
      exists = true;
      break;
    }
  }
  if (!exists)
    return -1;

  seg.resize(range.size() * 4, 0);

  return 0;
}
