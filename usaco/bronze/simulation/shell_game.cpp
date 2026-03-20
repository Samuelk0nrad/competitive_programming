#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  freopen("shell.in", "r", stdin);
  int n;
  scanf("%d", &n);

  int p[4] = {0, 1, 2, 3};
  int g[4] = {0, 0, 0, 0};
  int a, b, c;
  int tmp;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &a, &b, &c);
    tmp = p[a];
    p[a] = p[b];
    p[b] = tmp;
    g[p[c]]++;
  }
  freopen("shell.out", "w", stdout);
  printf("%d\n", max(max(g[1], g[2]), g[3]));
}
