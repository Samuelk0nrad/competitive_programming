#include <bits/stdc++.h>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  int ok = true;
  for (int i = 0; i < n; ++i) {
    int e;
    cin >> e;

    if (i != 0 && abs(a[i - 1] - e) % 2 == 0) {
      ok = false;
    }
    a[i] = e;
  }

  if (ok) {
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
