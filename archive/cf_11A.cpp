#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  vector<int> b;

  int max = 0;
  int res = 0;

  for (int i = 0; i < n; ++i) {
    int e;
    cin >> e;

    if (e > max) {
      max = e;
    } else {
      int diff = max - e;
      int m = ceil(diff / d);
      m += 1;
      res += m;
      max = e + m * d;
    }
  }

  cout << res;
}
