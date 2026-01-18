#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<long long> a(n);

    long long last = 0;
    long long max = 0;

    for (int i = 0; i < n; ++i) {
      long long e;
      cin >> e;

      if ((i - (e - last)) < 0) {
        if (i == 0) {
          a[i] = 1;
        } else {
          a[i] = max + 1;
        }
        max = a[i];
      } else {
        a[i] = a[i - (e - last)];
      }

      last = e;

      cout << a[i] << " ";
    }
    cout << "\n";
  }
}
