#include <bits/stdc++.h>

using namespace std;

vector<int> bales;

bool f(int s, double r) {
  double a = s - r, b = s + r;
  bool l = false, h = false;
  while (!l && !h) {
    r--;
    int br = 0, bl = bales.size();
    while (br < bl - 1) {
      int bm = (bl - br) / 2 + br;
      if (bales[bm] > b) {
        bl = bm;
      } else {
        br = bm;
      }
    }

    int ar = 0, al = bales.size() - 1;
    while (ar < al) {
      int am = (al - 1 - ar) / 2 + ar;
      if (bales[am] >= a) {
        al = am;
      } else {
        ar = am + 1;
      }
    }

    // br
    // al
    if (ar <= 0 && br >= bales.size() - 1) {
      return true;
    }
    if (a <= bales[al] - r && al != 0) {
      l = true;
    }
    if (b >= bales[br] + r && br != bales.size() - 1) {
      h = true;
    }
    a = bales[al] - r;
    b = bales[br] + r;
  }
  return false;
}

int main() {
  ifstream fin("angry.in");
  ofstream fout("angry.out");

  int n;
  fin >> n;

  bales.resize(n);

  for (int i = 0; i < n; i++) {
    fin >> bales[i];
  }
  sort(bales.begin(), bales.end());

  int heighest = 0;
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    if (heighest < bales[i + 1] - bales[i]) {
      heighest = bales[i + 1] - bales[i];
      a = i;
      b = i + 1;
    }
  }

  int l = 0;
  int h = 1e9;
  while (l < h - 1) {
    int m = (h - l) / 2 + l;
    if (f((bales[b] - bales[a]) / 2 + bales[a], m)) {
      h = m;
    } else {
      l = m;
    }
  }

  double res = h;

  if (f((bales[b] - bales[a]) / 2 + bales[a], res - 0.5)) {
    fout << h - 1 << ".5";
  } else {
    fout << h << ".0";
  }
}
