#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int c = 0;
  if (n == 1 && k > 0) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (c >= k) {
      break;
    }
    if (i == 0) {
      if (s[i] != '1') {
        s[i] = '1';
        c++;
      }
    } else {
      if (s[i] != '0') {
        s[i] = '0';
        c++;
      }
    }
  }
  cout << s;
}
