#include <bits/stdc++.h>
#include <vector>

using namespace std;

int subtask1(int a, int b) {
  // hier deine lösung zu teilaufgabe 1
  return a + b;
}

int subtask2(int n) { return (n * n + n) / 2; }

bool subtask3(std::vector<int> &v, int x) {
  int lo = 0, hi = v.size();
  cout << "x: " << x << "\n";

  do {
    cout << "lo: " << lo << "\n";
    cout << "hi: " << hi << "\n";
    int m = lo + floor((hi - lo) / 2.0);
    cout << "m: " << m << "\n";
    int e = v[m];
    cout << "e: " << e << "\n";
    if (e == x) {
      return true;
    } else if (e < x) {
      lo = m + 1;
    } else {
      hi = m;
    }
  } while (lo < hi);

  return false;
}

int main() {
  int x = 15;
  vector<int> a = {1, 4, 7, 8, 12, 14, 16, 18};
  cout << subtask3(a, x);
}
