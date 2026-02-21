#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  // cout << (1 << n) << '\n';
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 1; j <= n; j++) {
      // cout << "\n";
      // cout << "i j" << i << " " << j << "\n";
      if ((i >> (j - 1)) & 1) {
        cout << j << " ";
      }
    }
    cout << '\n';
  }
}
