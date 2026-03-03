#include <bits/stdc++.h>

using namespace std;

void f(int b, int e, int offset) {
  if (b == e) {
    if (b > offset) {
      cout << b << " ";
    }
    return;
  } else if (b > e) {
    return;
  }
  int mid = (b + e) / 2;
  if (mid > offset) {
    cout << mid << " ";
  }
  f(b, mid - 1, offset);
  f(mid + 1, e, offset);
}

int main() {
  int n, k;

  cin >> n >> k;

  if (k == n) {
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
  } else {
    int optimal = ceil(log2(n + 1));
    int offset = k - optimal;
    if (k - optimal < 0) {
      cout << -1;
      return 0;
    }
    for (int i = 1; i <= offset; i++) {
      cout << i << " ";
    }
    f(1, n, offset);
  }
}
