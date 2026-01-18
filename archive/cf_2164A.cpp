#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n;

    int min = 1e9;
    int max = -1e9;

    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;
      if (min > e)
        min = e;
      if (max < e)
        max = e;
    }

    cin >> x;

    if (x >= min && x <= max) {
      cout << "yes";
    } else {
      cout << "no";
    }
    cout << "\n";
  }
}
