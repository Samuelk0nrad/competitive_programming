#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool comp(int a, int b) { return a > b; }

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    double c;
    cin >> n >> c;

    vector<int> a;

    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;
      a.push_back(e);
    }

    sort(a.begin(), a.end(), comp);

    int res = 0;

    for (int i = 0; i < n; i++) {
      if (a[i] <= c) {
        a[i] = 0;
        c /= 2;
      } else {
        res++;
      }
    }

    cout << res << "\n";
  }
}
