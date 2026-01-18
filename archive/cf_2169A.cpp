#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a;
    cin >> n >> a;

    int more = 0;
    int less = 0;

    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;
      if (e > a)
        more++;
      else if (e < a)
        less++;
    }

    if (more > less) {
      cout << a + 1;
    } else {
      cout << a - 1;
    }
    cout << "\n";
  }
}
