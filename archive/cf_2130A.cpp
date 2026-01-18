#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> s;

    int ons = 0;
    int zeros = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;
      s.push_back(e);
      if (e == 1)
        ons++;
      else if (e == 0)
        zeros++;
      else
        sum += e;
    }
    int cuples;
    if (ons <= zeros) {
      cuples = ons;
      zeros -= ons;
      ons = 0;
    } else {
      cuples = zeros;
      ons -= zeros;
      zeros = 0;
    }

    cout << (cuples * 2) + sum + ons + zeros << "\n";
  }
}
