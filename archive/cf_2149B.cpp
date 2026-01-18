#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n = 0;

    cin >> n;

    vector<int> a;

    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;

      a.push_back(e);
    }

    sort(a.begin(), a.end());

    int maxdiff = 0;

    for (int i = 1; i < n; i += 2) {
      if (abs(a[i - 1] - a[i]) > maxdiff)
        maxdiff = abs(a[i - 1] - a[i]);
    }

    cout << maxdiff << "\n";
  }
}
