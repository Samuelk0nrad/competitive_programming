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

std::vector<int> bestimme_werte(int n) {
  // implementiere hier deine Lösung.
  // Mit wiege(std::vector<std::vector<int>> paket) kannst du Abfragen machen.
  vector<int> res;
  vector<vector<int>> ret;

  int last = -1;
  while (last + 1 < n) {
    vector<vector<int>> p;
    vector<int> vs;
    int l = last;

    bool ok = true;
    int e = 0;
    int lv = 0;
    while (ok && l + 1 < n) {
      vector<int> t;
      t.push_back(l + 1);

      int s = 2;

      while (s <= lv) {
        t.push_back(e);

        if (e > last) {
          ok = false;
          break;
        }
        s += res[e];
        e++;
      }

      if (ok) {
        p.push_back(t);
        vs.push_back(s - 2);
        l++;
        lv = s;
      }
    }

    last = l;
    auto r = wiege(p);
    sort(r.begin(), r.end());
    for (int i = 0; i < r.size(); ++i) {
      res.push_back(r[i] - vs[i]);
    }
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
