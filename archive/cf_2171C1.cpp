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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    int mc = 0;
    int ac = 0;
    int last = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        last = i;
        if (i & 1) {
          mc++;
        } else {
          ac++;
        }
      }
    }

    if (last == -1 || mc == ac) {
      cout << "Tie";
    } else if (last & 1) {
      cout << "Mai";
    } else {
      cout << "Ajisai";
    }
    cout << "\n";
  }
}
