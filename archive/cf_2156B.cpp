#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    for (int x = 0; x < q; ++x) {
      int l;
      cin >> l;
      int i = 0;
      while (l != 0) {
        if (s[i % n] == 'A') {
          l--;
        } else {
          l = floor(l / 2.0);
        }
        i++;
      }

      cout << i << " ";
    }

    cout << "\n";
  }
}
