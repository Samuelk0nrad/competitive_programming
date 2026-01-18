#include <bits/stdc++.h>
#include <exception>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    map<int, int> s;

    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;

      try {
        s.at(e);
      } catch (exception err) {
        s.insert({e, 0});
      }

      s[e]++;
    }

    map<int, int> m;

    for (auto e : s) {
      try {
        m.at(e.second);
      } catch (exception err) {
        m.insert({e.second, 0});
      }

      m[e.second]++;
    }

    int lenght = s.size();
    int max = 0;
    for (auto e : m) {
      if (max < e.first * lenght) {
        max = e.first * lenght;
      }
      lenght -= e.second;
    }

    cout << max << "\n";
  }
}
