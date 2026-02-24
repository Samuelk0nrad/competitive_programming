#include <algorithm>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#ifdef LOG
#define log(...) fprintf(stderr, "LOG: " __VA_ARGS__)
#else
#define log(...)
#endif

#define error(...)                                                             \
  do {                                                                         \
    fprintf(stderr, "Fehler: " __VA_ARGS__);                                   \
    exit(1);                                                                   \
  } while (0)

static std::vector<int> v[3];
static int moves;

void move(int a, int b) {
  moves++;
  log("%d -> %d\n", a, b);
  if (a == b || a > 3 || b > 3 || a < 1 || b < 1)
    error("Invalide Parameter\n");
  a--, b--;
  if (v[a].empty())
    error("Stab %d leer\n", a);
  if (!v[b].empty() && v[b].back() < v[a].back())
    error("Oberstes Element von Stab %d zu gross\n", b);
  v[b].push_back(v[a].back());
  v[a].pop_back();
}

void status() {
  int h = std::max(v[0].size(), std::max(v[1].size(), v[2].size()));
  for (int i = h - 1; i >= 0; i--, printf("\n"))
    for (int j = 0; j < 3; j++, printf("\t"))
      if (v[j].size() > i)
        printf("%d", v[j][i]);
  printf("---------\n1\t2\t3\n\n");
}

using namespace std;

void mvTop(int s, int f, int t) {
  int m = 0;
  if (s == 1) {
    move(f, t);
    return;
  }

  if (f != 1 && t != 1)
    m = 1;
  else if (f != 2 && t != 2)
    m = 2;
  else
    m = 3;
  mvTop(s - 1, f, m);
  move(f, t);
  mvTop(s - 1, m, t);
}

void hanoi(int n) {
  vector<int> sp(n + 1, 1);
  mvTop(n, 1, 2);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = n; i >= 1; i--)
    v[0].push_back(i);
  hanoi(n);
  if (!v[0].empty() || !v[2].empty()) {
    printf("wrong answer\n");
  } else
    printf("ok\n");
  return 0;
}
