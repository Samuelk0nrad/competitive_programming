#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int t = 0;

  cin >> t;

  for (int i = 0; i < t; i++) {
    int n = 0;
    int a = 0;
    int b = 0;
    int c = 0;

    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;

    int r = a + b + c;
    int d = 3;

    int times = ceil((float)n / r);
    d *= times;
    r *= times;

    // cout << r << endl;

    while (n <= r) {
      if (d % 3 == 0) {
        r -= a;
      } else if (d % 3 == 1) {
        r -= b;
      } else {
        r -= c;
      }
      d--;
    }
    cout << d + 1 << endl;
  }
}
