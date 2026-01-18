#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    char last = s[n - 1];

    int res = 0;
    for (auto e : s) {
      if (e != last)
        res++;
    }
    cout << res << "\n";
  }
}
