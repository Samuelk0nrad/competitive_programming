// https://codeforces.com/problemset/problem/2174/A

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s, t;
  cin >> s >> t;
  sort(t.begin(), t.end());
  string ss = s;
  sort(ss.begin(), ss.end());
  string res;
  string tmp;
  int is = 0;
  bool found = false;
  for (int i = 0; i < t.size(); ++i) {
    if (is < s.size() && t[i] == ss[is]) {
      is++;
    } else {
      tmp.push_back(t[i]);
    }
  }
  if (is < s.size()) {
    cout << "Impossible\n";
    return;
  }
  is = 0;
  for (int i = 0; i < tmp.size(); ++i) {
    if (is < s.size() && tmp[i] >= s[is]) {
      res.push_back(s[is]);
      --i;
      is++;
    } else {
      res.push_back(tmp[i]);
    }
  }
  for (int i = is; i < s.size(); ++i) {
    res.push_back(s[i]);
  }

  cout << res << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
