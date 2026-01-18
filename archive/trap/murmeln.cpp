#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool f(int k, int children, vector<int> *murmeln) {
  int need = 0;
  for (int i : *murmeln) {
    need += i / k;
    if (i % k != 0) {
      need++;
    }
  }
  return children >= need;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> murmeln(m);
  for (int i = 0; i < m; i++) {
    int e;
    cin >> e;
    murmeln[i] = e;
  }

  long long l = 1, r = (*max_element(murmeln.begin(), murmeln.end())) + 10;
  while (r > l) {
    int mid = l + (r - l) / 2;

    if (f(mid, n, &murmeln)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << l;
}
