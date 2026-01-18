#include "munzen.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
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

vector<pair<int, int>> points(int n) {
  vector<int> s;
  int sum = 0;
  int c = 1;
  while (sum + c <= n) {
    s.push_back(c);
    sum += c;

    c *= 2;
  }
  if (sum < n) {
    s.push_back(n - sum);
  }
  sort(s.rbegin(), s.rend());
  vector<pair<int, int>> res;
  int l = 0;
  for (int e : s) {
    res.push_back({l, 1});
    l += e;
  }
  return res;
}

std::vector<int> bestimme_werte(int n) {
  // implementiere hier deine Lösung.
  // Mit wiege(std::vector<std::vector<int>> paket) kannst du Abfragen machen.
  vector<int> res(n, 0);
  auto st = points(n);

  int count = 0;
  while (count < n) {
    vector<vector<int>> p;
    int l = 2e9;
    for (int i = 0; i < st.size(); ++i) {
      int lenght = st[i].second;
      if (i == st.size() - 1) {
        if (lenght > n - st[i].first) {
          continue;
        }
      } else {
        if (lenght > st[i + 1].first - st[i].first) {
          continue;
        }
      }
      if (l >= lenght) {
        vector<int> t;
        bool ok = false;
        for (int j = st[i].first; j < st[i].first + lenght; ++j) {
          t.push_back(j);
          ok = true;
        }
        if (ok) {
          p.push_back(t);
          l = floor(lenght / 2.0);
          st[i].second++;
        }
      }
    }

    auto r = wiege(p);
    sort(r.rbegin(), r.rend());
    for (int i = 0; i < r.size(); ++i) {
      int v = r[i];
      int l = p[i][0];
      for (int j = 0; j < p[i].size(); ++j) {
        if (j >= p[i].size() - 1) {
          l = p[i][j];
        } else {
          v -= res[p[i][j]];
        }
      }
      res[l] = v;
      count++;
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
