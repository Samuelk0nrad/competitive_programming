#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  freopen("billboard.in", "r", stdin);
  int lx1, ly1, lx2, ly2;
  cin >> lx1 >> ly1 >> lx2 >> ly2;

  int bx1, by1, bx2, by2;
  cin >> bx1 >> by1 >> bx2 >> by2;

  int res = (lx2 - lx1) * (ly2 - ly1);

  if ((bx1 <= lx1 && bx2 >= lx2) || (by1 <= ly1 && by2 >= ly2)) {
    if (!(ly2 <= by1 || ly1 >= by2 || lx1 >= bx2 || lx2 <= bx1)) {
      int insx1 = max(lx1, bx1);
      int insy1 = max(ly1, by1);

      int insx2 = min(lx2, bx2);
      int insy2 = min(ly2, by2);

      res -= (insx2 - insx1) * (insy2 - insy1);
    }
  }
  freopen("billboard.out", "w", stdout);
  cout << res;
}
