#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a;

    int falseeven = 0;
    int falseodd = 0;

    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;
      a.push_back(e);

      if (i % 2 != e % 2) {
        if (i % 2) {
          falseodd++;
        } else {
          falseeven++;
        }
      }
    }

    if (falseeven == falseodd) {
      cout << falseeven << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}
