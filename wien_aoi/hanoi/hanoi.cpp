#include "hanoi.h"
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void hanoi(int n) {
  vector<int> sp(n + 1, 1);
  int g = n % 2;

  for (uint i = 1; i < 5; i++) {
    int s = __countr_zero(i) + 1;

    int np = sp[s];
    if (s % 2 == g) {
      np -= 1;
    } else {
      np += 1;
    }

    if (np < 1)
      np = 3;
    else if (np > 3)
      np = 1;

    cout << "move: " << sp[s] << " " << np << '\n';
    move(sp[s], np);

    status();

    cout << '\n\n\n\n';
    bool ok = true;
    for (int i : sp) {
      if (i != 3) {
        ok = false;
      }
    }

    if (ok)
      break;
  }
}
