#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    bool c = false, res = false;
    for (char e : s) {
      if (c && e == '(') {
        res = true;
        break;
      } else if (e == ')') {
        c = true;
      }
    }

    cout << (res ? "yes" : "no") << "\n";
  }
}
