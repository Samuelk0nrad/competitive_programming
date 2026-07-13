#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    ll k;
    cin >> k;
    ll n = k;
    ll i = 1;
    while (true) {
      n = k * i;
      i++;
      bool ok = false;
      string s = to_string(n);
      for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == '0' && s[i + 1] == '0') {
          ok = true;
          break;
        }
      }
      if (ok) {
        break;
      }
    }
    cout << n << "\n";
  }
}
