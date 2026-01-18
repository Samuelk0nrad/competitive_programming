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
    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == -1) {
        ar[i] = 0;
      } else {
        ar[i] = a[i];
      }
    }

    int b = 0;
    for (int i = 0; i < n - 1; i++) {
      b += ar[i + 1] - ar[i];
    }

    if (b > 0) {
      if (a[0] == -1) {
        ar[0] = abs(b);
        b = 0;
      }
    } else if (b < 0) {
      if (a[n - 1] == -1) {
        ar[n - 1] = abs(b);
        b = 0;
      }
    }

    cout << abs(b) << "\n";
    for (int e : ar) {
      cout << e << " ";
    }
    cout << "\n";
  }
}
