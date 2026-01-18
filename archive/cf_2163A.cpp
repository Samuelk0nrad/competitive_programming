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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    bool ok = true;
    for (int i = 1; i < n - 1; i += 2) {
      if (a[i] != a[i + 1]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "yes";
    } else {
      cout << "no";
    }
    cout << "\n";
  }
}
