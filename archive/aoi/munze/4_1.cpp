#include "munzen.h"
#include <bits/stdc++.h>

using namespace std;

std::vector<int> bestimme_werte(int n) {

  // implementiere hier deine Lösung.
  // Mit wiege(std::vector<std::vector<int>> paket) kannst du Abfragen machen.
  vector<int> res(n, 1);

  for (int i = 0; i < n; ++i) {
    vector<int> w = wiege({{i}});
    res[i] = w[0];
  }

  return std::vector<int>(n, 1);
}
