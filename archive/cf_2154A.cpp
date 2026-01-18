#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int p = 0;

    int last = (k * (-1)) - 12;

    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (i - last >= k) {
          p++;
        }
        last = i;
      }
    }

    cout << p << "\n";
  }
}
