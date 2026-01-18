#include <bits/stdc++.h>
#include <set>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    set<int> a;

    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;

      a.insert(e);
    }

    cout << a.size() << "\n";
  }
}
