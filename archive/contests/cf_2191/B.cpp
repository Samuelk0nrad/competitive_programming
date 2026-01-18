#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  bool one = false;
  bool zero = false;
  bool twoz = false;
  for (int i = 0; i < n; ++i) {
    int e;
    cin >> e;
    if (e == 0)
      if (zero)
        twoz = true;
      else
        zero = true;
    else if (e == 1)
      one = true;
  }

  if (one && zero) {
    cout << "yes";
  } else if (zero && !twoz) {
    cout << "yes";
  } else {
    cout << "no";
  }

  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
