#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int res = n;

    for (int a = 0; a < n / 2; a++) {
      int b = (n - 1) - a;

      if (s[a] != s[b] && a != b) {
        res -= 2;
      } else {
        break;
      }
    }

    cout << res << '\n';
  }
}
