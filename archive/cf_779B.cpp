#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n = 0;
  int k = 0;
  cin >> n;
  cin >> k;

  int p = 0;
  int count = 0;
  while (p < k) {
    if (n % 10) {
      count++;
    } else {
      p++;
    }
    n /= 10;
    if (n == 0)
      break;
  }
  if (n == 0) {
    cout << count + p - 1;
    return 0;
  }
  cout << count;
}
