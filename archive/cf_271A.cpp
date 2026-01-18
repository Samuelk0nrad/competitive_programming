#include <iostream>
#include <set>

using namespace std;

int main() {
  int y = 0;
  cin >> y;
  while (true) {
    int year = ++y;
    set<int> d;
    bool e = false;
    while (year > 0) {
      int n = year % 10;
      if (d.count(n)) {
        e = true;
        break;
      } else {
        d.insert(n);
        year = (year - n) / 10;
      }
    }
    if (!e) {
      cout << y;
      break;
    }
  }
  return 0;
}
