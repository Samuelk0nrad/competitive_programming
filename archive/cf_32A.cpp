#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  vector<int> a;

  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    a.push_back(e);
  }

  int res = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      else if (abs(a[i] - a[j]) <= d)
        res++;
    }
  }

  cout << res;
}
