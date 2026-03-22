#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct Cow {
  char dir;
  int x;
  int y;
  int eat = INT_MAX;
};

struct Ins {
  int active = false;
  int a;
  int b;
  int x;
  int y;
  int diff;
  bool operator<(const Ins *x) const { return diff < x->diff; }
  bool operator>(const Ins *x) const { return diff > x->diff; }
};

int main() {
  int n;
  cin >> n;
  vector<Cow> c(n);
  priority_queue<Ins> ins;

  for (int i = 0; i < n; i++) {
    cin >> c[i].dir >> c[i].x >> c[i].y;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (c[i].dir == 'E') {
        if (c[j].dir == 'N') {
        } else if (c[i].y == c[j].y) {
          Ins g = Ins{
              false, i, j, max(c[i].x, c[j].x), c[i].y, abs(c[i].x - c[j].x)};
          ins.push(g);
        }
      } else {
        if (c[j].dir == 'E') {
        } else if (c[i].x == c[j].x) {
          Ins g = Ins{
              false, i, j, c[i].x, max(c[i].y, c[j].y), abs(c[i].y - c[j].y)};
          ins.push(g);
        }
      }
    }
  }
}
