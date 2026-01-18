#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int i = 1;
    for (; i < n; ++i) {
      if (i % 2 == 1) {
        cout << "-1 ";
      } else {
        cout << "3 ";
      }
    }
    if (i % 2 == 1) {
      cout << "-1";
    } else {
      cout << "2";
    }
    cout << "\n";
  }
}
