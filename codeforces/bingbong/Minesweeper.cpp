#include <bits/stdc++.h>

using namespace std;

vector<string> s;

int main() {
  int n, m;
  cin >> n >> m;
  s.resize(n + 3, "");
  bool ok = true;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c = s[i][j];
      if (c == '*') {
        continue;
      } else {
        int b = 0;
        if (i > 0 && s[i - 1][j] == '*') {
          b++;
        }
        if (j > 0 && s[i][j - 1] == '*') {
          b++;
        }
        if (i > 0 && j > 0 && s[i - 1][j - 1] == '*') {
          b++;
        }
        if (i < n - 1 && s[i + 1][j] == '*') {
          b++;
        }
        if (j < m - 1 && s[i][j + 1] == '*') {
          b++;
        }
        if (j < m - 1 && i < n - 1 && s[i + 1][j + 1] == '*') {
          b++;
        }
        if (i > 0 && j < m - 1 && s[i - 1][j + 1] == '*') {
          b++;
        }
        if (i < n - 1 && j > 0 && s[i + 1][j - 1] == '*') {
          b++;
        }
        if (c == '.') {
          if (b != 0) {
            ok = false;
            break;
          } else {
            continue;
          }
        } else {
          int n = c - 48;
          if (n != b) {
            ok = false;
            break;
          }
        }
      }
    }
  }
  if (ok) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
