#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  int n, s, x;
  while (t--) {
    cin >> n >> s >> x;
    int sum = 0, e;
    for (int i = 0; i < n; i++) {
      cin >> e;
      sum += e;
    }
    if (sum > s) {
      cout << "no";
    } else {
      sum -= s;
      if (sum % x == 0) {
        cout << "yes";
      } else {
        cout << "no";
      }
    }
    cout << "\n";
  }
}
