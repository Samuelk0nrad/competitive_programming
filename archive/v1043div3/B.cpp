#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;

    string s = to_string(n);

    set<char> d(s.begin(), s.end());

    if (d.size() == 1 && !(s.size() & 1)) {

      string res1(s.begin(), s.begin() + s.size() / 2);
      cout << res1;

    } else {
      cout << 0;
    }

    cout << "\n";
  }
}
