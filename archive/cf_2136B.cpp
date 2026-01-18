#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int o = 0, z = 0;

    for (char e : s) {
      if (e == '1')
        o++;
      else
        z++;
    }

    if (s[n - 1] == '1') {
      cout << "no" << "\n";
    } else {
      int min = n / k;
      if (o < min) {
        cout << "no" << "\n";
      } else {
      }
    }
  }
}
