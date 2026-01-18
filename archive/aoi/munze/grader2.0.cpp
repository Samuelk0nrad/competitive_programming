#include "munzen.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int q = 0;
std::vector<int> muenzen;
std::vector<int> wiege(std::vector<std::vector<int>> paket) {
  q++;

  std::vector<int> gewichte(paket.size());
  for (int i = 0; i < paket.size(); i++) {
    for (int j = 0; j < paket[i].size(); j++) {
      gewichte[i] += muenzen[paket[i][j]];
    }
  }

  std::random_shuffle(gewichte.begin(), gewichte.end());
  return gewichte;
}

vector<vector<int>> paket(int start, int n) {
  vector<vector<int>> res;
  int c = 1;
  int s = 0;
  vector<int> p;
  for (int i = 0; i < n; ++i) {
    int e = (i + start) % n;
    p.push_back(e);
    if (i >= s) {
      c *= 2;
      s += c;
      res.push_back(p);
      vector<int> t;
      p = t;
    }
  }

  return res;
}

std::vector<int> bestimme_werte(int n) {
  // implementiere hier deine Lösung.
  // Mit wiege(std::vector<std::vector<int>> paket) kannst du Abfragen machen.
  vector<int> res;

  vector<vector<int>> p;
  vector<int> w = wiege(p);
  sort(w.begin(), w.end());
  int lastl = -1;

  for (int i = 0; i + 2 < n; i += 2) {
    p = {{i}, {i + 1, i + 2}};
    w = wiege(p);
    sort(w.begin(), w.end());
    if (lastl != -1) {
      res.push_back(lastl - w[0]);
    }
    res.push_back(w[0]);
    lastl = w[1];
  }

  for (int i = res.size(); i < n; ++i) {
    p = {{i}};
    w = wiege(p);

    res.push_back(w[0]);
  }

  return res;
}

int main() {
  int n;
  std::cin >> n;
  muenzen = std::vector<int>(n);
  for (int i = 0; i < n; i++)
    std::cin >> muenzen[i];
  for (int v : bestimme_werte(n))
    std::cout << v << " ";
  std::cout << "\n" << q << " Queries\n";
}
