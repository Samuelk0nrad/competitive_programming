#include <bits/stdc++.h>

using namespace std;

vector<int> s;

int main() {
  // freopen("censor.in", "r", stdin);
  // freopen("censor.out", "w", stdout);
  string S, T;
  cin >> S >> T;

  s.push_back(0);

  string res = "";
  for (auto c : S) {
    int *t = &s.back();
    res.push_back(c);
    if (c == T[*t]) {
      *t += 1;
      if (*t >= T.size()) {
        for (int i = 0; i < T.size(); i++) {
          res.pop_back();
        }
        s.pop_back();
        if (s.size() == 0) {
          s.push_back(0);
        }
      }
    } else if (c == T[0]) {
      s.push_back(1);
    } else {
      *t = 0;
    }
  }

  cout << res;
}
