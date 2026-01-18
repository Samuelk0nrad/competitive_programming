#include <cstdio>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(true);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);

    long long mz = 0, mo = 0;

    for (int i = 0; i < n; ++i) {
      int a, b, c, d;
      scanf("%d %d %d %d", &a, &b, &c, &d);

      if (b > d) {
        mz += c;
      } else {
        mo += d - b;
        if (a > c) {
        } else {
          mz += c - a;
        }
      }
    }

    printf("%lld\n", mz + mo);
  }
}
