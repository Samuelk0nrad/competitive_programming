#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x = 0;
    long long y = 0;
    cin >> x;
    cin >> y;

    long long number = 0;
    bool row = y > x;

    if (y > x) {
      // Y
      bool odd = y % 2;
      long long startNum = 0;
      if (!odd) {
        startNum = (y - 1) * (y - 1) + 1;
        number = x - 1;
      } else {
        startNum = y * y;
        number -= x - 1;
      }
      number += startNum;
    } else {
      // X
      bool odd = x % 2;
      long long startNum = 0;
      if (odd) {
        startNum = (x - 1) * (x - 1) + 1;
        number = y - 1;
      } else {
        startNum = x * x;
        number -= y - 1;
      }
      number += startNum;
    }
    cout << number << "\n";
  }
}
