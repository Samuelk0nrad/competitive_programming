#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 0;
  cin >> n;
  vector<bool> exist(n);

  for (int i = 0; i < n - 1; ++i) {
    int current = 0;
    cin >> current;
    exist[current - 1] = true;
  }

  for (int i = 0; i < n; ++i) {
    if (!exist[i]) {
      cout << i + 1;
    }
  }
}
