#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  string res;

  for (char e : s) {
    if (e < 96)
      e += 97 - 65;

    if (e == 'a' || e == 'o' || e == 'y' || e == 'e' || e == 'u' || e == 'i') {

    } else {
      res += ".";
      res += e;
    }
  }

  cout << res;
}
