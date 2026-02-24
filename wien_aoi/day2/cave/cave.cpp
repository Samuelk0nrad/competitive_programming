#include "cave.h"
#include <bits/stdc++.h>

using namespace std;

void exploreCave(int N) {
  int S[5000] = {0};
  for (int i = 0; i < N; ++i) {
    if (tryCombination(S) > i) {

    } else {
      S[i] = 1;
    }
  }
  int D[5000];
  for (int i = 0; i < N; i++)
    D[i] = i;
  answer(S, D);
}
