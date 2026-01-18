#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int main() {
  long long t;
  cin >> t;

  while (t--) {
    long long a, b, k;
    cin >> a >> b >> k;

    if (a < b) {
      long long temp = a;
      a = b;
      b = temp;
    }

    if (a <= k && b <= k) {
      cout << 1 << "\n";
      continue;
    } else if (gcd(a, b) > 1 && (a / gcd(a, b)) <= k) {
      cout << 1 << "\n";
    } else {
      cout << 2 << "\n";
    }
  }
}
