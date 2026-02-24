#include <algorithm>
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

    int res = 0;

    int lastB = 0;
    for (int i = n - 1; i >= 0; i--) {
      int b = n - i;
      int bb = min(b, a[i]);
      lastB = max(bb, lastB);
    }
    cout << lastB << "\n";
  }
}
