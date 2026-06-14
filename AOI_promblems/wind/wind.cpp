#include <bits/stdc++.h>
#include <cstdlib>
#ifdef EVAL
#include "wind.h"
#else
#include "grader.cpp"
#endif
#define ll long long

using namespace std;

// x / y
vector<pair<ll, ll>> p;
ll N;
ll diffx;
ll diffy;

bool f(ll i) {
  ll d = i;
  ll t = 0;
  t = i / N;
  i %= N;
  pair<ll, ll> m = {p[N].first * t, p[N].second * t};
  m.first += p[i].first;
  m.second += p[i].second;
  return abs(m.first - diffx) + abs(m.second - diffy) <= d;
}

ll calculate_days(int x1, int y1, int x2, int y2, int n, std::string s) {
  N = n;
  p.assign(n + 5, {0, 0});

  diffx = x2 - x1;
  diffy = y2 - y1;

  for (ll i = 0; i < n; i++) {
    if (s[i] == 'U') {
      p[i + 1] = {p[i].first, p[i].second + 1};
    } else if (s[i] == 'D') {
      p[i + 1] = {p[i].first, p[i].second - 1};
    } else if (s[i] == 'R') {
      p[i + 1] = {p[i].first + 1, p[i].second};
    } else if (s[i] == 'L') {
      p[i + 1] = {p[i].first - 1, p[i].second};
    }
  }

  ll diff = abs(diffx) + abs(diffy);
  ll fdiff = abs(p[n].first - diffx) + abs(p[n].second - diffy) - n;

  ll l = 0;
  ll h = N;
  if (fdiff > 0) {
    h = 4e18;
  }

  while (h - 1 > l) {
    ll m = (h - l) / 2 + l;
    if (f(m)) {
      h = m;
    } else {
      l = m;
    }
  }
  if (f(h)) {
    return h;
  }
  return -1;
}
