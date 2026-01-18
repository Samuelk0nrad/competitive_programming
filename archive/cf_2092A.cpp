#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int max = 0;
    int min = 1.5e9;

    for (int i = 0; i < n; ++i) {
      int e;
      cin >> e;
      if (max < e)
        max = e;
      if (min > e)
        min = e;
    }

    cout << max - min << "\n";
  }
}
