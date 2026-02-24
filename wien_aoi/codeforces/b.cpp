#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, k;
    cin >> x >> y >> k;

    bool d = false;
    if (x > y) {
      d = true;
      int tmp = x;
      x = y;
      y = tmp;
    }
    int ans = ((y + k - 1) / k) * 2;
    // cout << y << " ak: " << y + k - 1 << " ans: " << ans << " ";

    if (d) {
      ans--;
    }
    cout << ans << " \n";
  }
}
