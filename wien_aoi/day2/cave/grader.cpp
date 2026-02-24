#include "cave.h"
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5000
#define MAX_CALLS 70000

#define fail(s, x...)                                                          \
  do {                                                                         \
    fprintf(stderr, s "\n", ##x);                                              \
    exit(1);                                                                   \
  } while (0)

/* Symbol obfuscation */
#define N koala
#define realS kangaroo
#define realD possum
#define inv platypus
#define num_calls echidna

static int N;
static int realS[MAX_N];
static int realD[MAX_N];
static int inv[MAX_N];
static int num_calls;

void answer(int S[], int D[]) {
  int i;
  int correct = 1;
  for (i = 0; i < N; ++i)
    if (S[i] != realS[i] || D[i] != realD[i]) {
      correct = 0;
      break;
    }

  if (correct)
    printf("CORRECT\n");
  else
    printf("INCORRECT\n");

  for (i = 0; i < N; ++i) {
    if (i > 0)
      printf(" ");
    printf("%d", S[i]);
  }
  printf("\n");

  for (i = 0; i < N; ++i) {
    if (i > 0)
      printf(" ");
    printf("%d", D[i]);
  }
  printf("\n");

  exit(0);
}

int tryCombination(int S[]) {
  int i;

  if (num_calls >= MAX_CALLS) {
    printf("INCORRECT\nToo many calls to tryCombination().\n");
    exit(0);
  }
  ++num_calls;

  for (i = 0; i < N; ++i)
    if (S[inv[i]] != realS[inv[i]])
      return i;
  return -1;
}

using namespace std;

void exploreCave(int N) {
  int S[5000];
  bool used[5000];
  int D[5000];

  int la = tryCombination(S);
  for (int j = 0; j < N; ++j) {
    int l = 0;
    int r = N;
    int ans = -2;
    while (l < r - 1) {
      int m = ((r - l + 1) / 2) + l;
      for (int i = l; i < m; i++) {
        if (!used[i]) {
          S[i] = 1;
        }
      }
      ans = tryCombination(S);
      for (int i = l; i < m; i++) {
        if (!used[i]) {
          S[i] = 0;
        }
      }
      if (ans != la) {
        if (la == j && (ans > j || ans == -1)) {
          r = m;
        } else if ((la > j || la == -1) && ans == j) {
          r = m;
        } else {
          l = m;
        }
      } else {
        l = m;
      }
    }

    r--;

    if (la == j) {
      D[r] = j;
      used[r] = true;
      S[r] = 1;
    } else if (j == N - 1) {
      D[r] = j;
      if (la == -1) {
        S[r] = 0;
      }
      used[r] = true;
    } else {
      D[r] = j;
      S[r] = 0;
      used[r] = true;
    }
    ans = tryCombination(S);
    la = ans;
  }
  answer(S, D);
}

int init() {
  int i, res;

  res = scanf("%d", &N);

  for (i = 0; i < N; ++i) {
    res = scanf("%d", &realS[i]);
  }
  for (i = 0; i < N; ++i) {
    res = scanf("%d", &realD[i]);
    inv[realD[i]] = i;
  }

  num_calls = 0;
  return N;
}

int main() {
  int N;
  N = init();
  exploreCave(N);
  printf("INCORRECT\nYour solution did not call answer().\n");
  return 0;
}
