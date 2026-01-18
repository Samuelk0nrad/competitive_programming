#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, n;
    cin >> a >> b >> n;

    if (a <= b) {
      cout << 1;
    } else if (n * b <= a) {
      cout << 1;
    } else {
      cout << 2;
    }
    cout << "\n";
  }
}
