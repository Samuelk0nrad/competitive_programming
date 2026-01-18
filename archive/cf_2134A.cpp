#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;

    if (b % 2 != n % 2) {
      cout << "no";
    } else if (a % 2 == n % 2) {
      cout << "yes";
    } else if (b > a) {
      cout << "yes";
    } else {
      cout << "no";
    }
    cout << "\n";
  }
}
