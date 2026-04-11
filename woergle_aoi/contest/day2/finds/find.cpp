#include "find-scores.h"
#include <bits/stdc++.h>

using namespace std;

std::vector<int> find_scores(int n) {
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    res[i] = query1(i);
  }
  return res;
}
