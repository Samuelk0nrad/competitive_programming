#include <bits/stdc++.h>
using namespace std;

int main() {
  long long k, n, w = 0;
  cin >> k >> n >> w;
  long long costs = ((w / 2.0) * (1 + w)) * k;
  cout << (costs <= n ? 0 : costs - n);
  return 0;
}
