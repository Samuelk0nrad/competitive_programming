#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int o = 0, z = 0;

    for (int i = 0; i < n; ++i) {
      if (s[i] == '1')
        z++;
      else
        o++;
    }

    int p = n / 2;
    int diff = abs(o - z) / 2;

    if (diff > k) {
      cout << "no\n";
    } else if (diff == k) {
      cout << "yes\n";
    } else if ((k - diff) % 2 == 0) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}
