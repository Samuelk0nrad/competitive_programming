#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int s1 = 0, s2 = 0, sm = 0;

    vector<int> a;
    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;
      a.push_back(e);

      sm += e;
    }

    int s3 = 0;

    bool res = false;

    for (int l = 0; l < n - 1; l++) {
      s1 += a[l];

      if (res)
        break;
      for (int r = l + 1; r < n; r++) {
        s2 += a[r];
        s3 = sm - (s1 + s2);

        if (s1 % 3 == s2 % 3 && s2 % 3 == s3 % 3) {
          res = true;

          cout << l + 1 << ' ' << r + 1 << "\n";

          break;
        } else if (s1 % 3 != s2 % 3 && s1 % 3 != s3 % 3 && s2 % 3 != s3 % 3) {
          res = true;
          cout << l + 1 << ' ' << r + 1 << "\n";
          break;
        }
      }

      s2 = 0;
    }

    if (!res)
      cout << "0 0" << "\n";
  }
}
