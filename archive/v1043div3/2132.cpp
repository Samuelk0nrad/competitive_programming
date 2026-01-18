#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string a, b, c;
    cin >> n >> a >> m >> b >> c;

    vector<char> d, v;

    for (int i = 0; i < m; ++i) {
      if (c[i] == 'D') {
        d.push_back(b[i]);
      } else {
        v.push_back(b[i]);
      }
    }

    reverse(v.begin(), v.end());

    for (auto e : v) {
      cout << e;
    }

    cout << a;

    for (auto e : d) {
      cout << e;
    }

    cout << "\n";
  }
}
