#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
      int a;
      cin >> a;
      cout << "YES\n 1";
    } else if (n == 2) {
      int a, b;
      cin >> a >> b;
      if (k == 1) {
        cout << "YES\n";
        cout << "1 1\n";
      } else {
        cout << "NO\n";
      }
    } else if (n == 3) {
      int a, b, c;
      cin >> a >> b >> c;
      if (k >= 3) {
        cout << "NO \n";
      } else {
        cout << "YES\n";
        if (k == 1) {
          cout << "1 1 1\n";
        } else if (k == 2) {
          int o = 0;
          int t = 0;
          if (a == 1)
            o++;
          else
            t++;
          if (b == 1)
            o++;
          else
            t++;
          if (c == 1)
            o++;
          else
            t++;

          if (o > t) {
            cout << "1 2 1\n";
          } else {
            cout << "2 1 2\n";
          }
        }
      }
    }
  }
}
