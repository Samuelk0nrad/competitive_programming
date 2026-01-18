#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
  string s;
  getline(cin, s);

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '.') {
      cout << 0;
    } else if (s[i + 1] == '.') {
      cout << 1;
      i++;
    } else {
      cout << 2;
      i++;
    }
  }
}
