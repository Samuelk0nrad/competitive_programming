#include "munzen.h"
#include <bits/stdc++.h>

using namespace std;

struct domino {
  bool left;
  domino *left_d;
  bool right;
  domino *right_d;
  int w;
  bool w_u;
  domino(int wert) {
    w = wert;
    w_u = false;
    left = false;
    right = false;
    right_d = nullptr;
    left_d = nullptr;
    if (wert == 2) {
      w_u = true;
    } else if (wert == 4) {
      left = true;
      right = true;
      w_u = true;
    }
  }
};

vector<domino> dmap(vector<int> w) {
  vector<domino> res(w.size());

  for (int i = 0; i < w.size(); ++i) {
    domino d(w[i]);
    res.push_back(d);
  }

  return res;
}

vector<pair<int, int>> sort(vector<int> ew, vector<int> ow) {
  vector<domino> d = dmap(ew);

  int dk = 0;

  for (int e : ow) {
    if (e == 3) {
      dk++;
      continue;
    }

    domino *left_d = nullptr;
    domino *right_d = nullptr;
    bool left = false;
    bool right = false;

    if (e == 4) {
      left = true;
      right = true;
    }

    for (auto de : d) {
      if (de.w_u) {
        if (left_d == nullptr && de.left == left && de.left_d != nullptr) {
          left_d = &de;
        } else if (right_d == nullptr && de.right == right &&
                   de.right_d != nullptr) {
          right_d = &de;
        }
      }
    }

    left_d->right_d = right_d;
    right_d->left_d = left_d;
  }
}

std::vector<int> bestimme_werte(int n) {
  if (n % 2 == 1)
    return {};

  // implementiere hier deine Lösung.
  // Mit wiege(std::vector<std::vector<int>> paket) kannst du Abfragen machen.

  vector<vector<int>> e_pairs;
  vector<vector<int>> o_pairs;

  for (int p = 1; p < n; p += 2) {
    e_pairs.push_back({p - 1, p});
    if (p != n - 1) {
      o_pairs.push_back({p, p + 1});
    } else {
      o_pairs.push_back({0, p});
    }
  }

  vector<int> e_pairs_res = wiege(e_pairs);
  vector<int> o_pairs_res = wiege(o_pairs);

  sort(e_pairs_res, o_pairs_res);

  return o_pairs_res;
}
