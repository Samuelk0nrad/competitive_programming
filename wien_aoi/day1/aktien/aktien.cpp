#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  int b = 0;
  int s = 1;
  int bt = -1;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    a[i] = e;
    if (a[s] < e && !(i < 1)) {
      // cout << "s set to " << i << "\n";
      s = i;
    }

    if (bt != -1 && !(i < 1)) {
      // cout << "b switch " << a[s] - a[bt] << " " << a[s] - a[b] << "\n";
      if (e - a[bt] > a[s] - a[b]) {
        // cout << "s set to" << i << "\n";
        b = bt;
        s = i;
        bt = -1;
      }
    }

    if (a[b] > e) {
      if (bt == -1) {
        bt = i;
      } else if (a[bt] > e) {
        bt = i;
      }
    }
  }
  cout << a[s] - a[b] << "\n";
}
