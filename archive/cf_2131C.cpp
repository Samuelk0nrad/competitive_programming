#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    multiset<int> S;
    multiset<int> T;

    for (int i = 0; i < n; ++i) {
      int e;
      cin >> e;

      S.insert(min(e % k, k - (e % k)));
    }

    for (int i = 0; i < n; ++i) {
      int e;
      cin >> e;

      T.insert(min(e % k, k - (e % k)));
    }

    multiset<int> diff;

    set_difference(S.begin(), S.end(), T.begin(), T.end(),
                   inserter(diff, diff.begin()));

    if (diff.size() == 0) {
      cout << "yes";
    } else {
      cout << "no";
    }
    cout << "\n";
  }
}
