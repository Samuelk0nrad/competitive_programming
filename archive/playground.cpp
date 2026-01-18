#include <bits/stdc++.h>

using namespace std;

int main() {
  int m = 1000000;
  int a = 900219;
  int b = 3012;

  cout << (a + b) % m << "=" << ((a % m) + (b % m)) % m;
  return 0;
}
