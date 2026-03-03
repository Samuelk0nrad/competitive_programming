#include "grf.h"
#include "grader.cpp"
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool f(int v, vector<int> &smaller, vector<int> &larger, int n) {
  int res = 0;

  for (int i = 0; i < n; i++) {
    if (smaller[i] >= res) {
      if (larger[i] >= v - (res + 1)) {
        res++;
      }
    }
  }

  return res >= v;
}

int solve(int n, std::vector<int> smaller, std::vector<int> larger) {
  int l = 1;
  int r = n + 2;
  while (l + 1 < r) {
    int m = ((r - l) / 2) + l;
    if (f(m, smaller, larger, n)) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}
