#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n = 0;
  cin >> n;
  cout << n << " ";

  while (n != 1) {
    n = (n % 2) ? (n * 3) + 1 : n / 2;
    cout << n << " ";
  }

  return 0;
}
