#include "wind.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int diff(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long calculate_days(int x1, int y1, int x2, int y2, int n, std::string s) {

  bool ok = true;

  int fd = diff(x1, y1, x2, y2);
  if (fd % 2 != 0) {
    return -1;
  }
  int md = fd;

  int x = x1;
  int y = y1;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'U')
      y++;
    else if (s[i] == 'D')
      y--;
    else if (s[i] == 'L')
      x--;
    else if (s[i] == 'R')
      x++;

    int d = diff(x, y, x2, y2);
    if (md > d) {
      md = d;
    }
  }
  int dd = diff(x, y, x1, y1) - n;

  if (fd <= dd) {
    ok = false;
  }

  if (!ok) {
    return -1;
  } else {
    return 0;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int x1, y1, x2, y2, n;
  std::string s;
  std::cin >> x1 >> y1 >> x2 >> y2 >> n >> s;

  std::cout << calculate_days(x1, y1, x2, y2, n, s) << std::endl;
  return 0;
}
