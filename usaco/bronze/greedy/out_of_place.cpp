#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int n;
  freopen("outofplace.in", "r", stdin);
  cin >> n;
  vector<int> a(n);
  int b = -1;
  int d = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0 || b != -1) {
      continue;
    }
    if (a[i - 1] > a[i]) {
      if (i == 1) {
        b = 0;
        d = 1;
      } else {
        if (a[i - 2] > a[i]) {
          b = i;
          d = -1;
        } else {
          b = i - 1;
          d = 1;
        }
      }
    }
  }
  int res = 0;
  if (d == 1) {
    for (int i = b + 1; i < n; i++) {
      if (a[i] >= a[b]) {
        break;
      }
      if (a[i] != a[i - 1]) {
        res++;
      }
    }
  } else if (d == -1) {
    for (int i = b - 1; i >= 0; i--) {
      if (a[i] <= a[b]) {
        break;
      }
      if (a[i] != a[i + 1]) {
        res++;
      }
    }
  }
  freopen("outofplace.out", "w", stdout);
  cout << res;
}
