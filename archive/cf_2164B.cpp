#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    int x = 0;
    int y = 1;
    bool ok = false;

    for (; x < n; ++x) {
      for (y = x + 1; y < n; ++y) {
        if (((a[y] % a[x]) % 2) == 0) {
          ok = true;
          break;
        }
      }
      if (ok) {
        break;
      }
    }

    if (ok) {
      cout << a[x] << " " << a[y];
    } else {
      cout << -1;
    }
    cout << "\n";
  }
}
