#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, X;
    long long sum = 0;

    cin >> n >> X;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }

    sort(a.begin(), a.end());

    int x = sum / X;
    vector<int> res;
    long long p = 0;

    for (int i = n - 1; i >= n - x; i--) {
      p += a[i];
    }

    long long ls = 0;
    int ll = 0;
    int low = 0;
    int heigh = n - 1;
    while (res.size() < n) {
      long long nl = (ls + a[heigh]) / X;
      long long e = 0;
      if (nl > ll) {
        e = a[heigh];
        heigh--;
      } else {
        e = a[low];
        low++;
      }
      res.push_back(e);
      ls += e;
      ll = (ls) / X;
    }

    cout << p << "\n";
    for (int e : res) {
      cout << e << " ";
    }
    cout << "\n";
  }
}
