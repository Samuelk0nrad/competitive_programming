// https://cses.fi/problemset/task/3419/
#include <bits/stdc++.h>
#include <sys/types.h>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << (j ^ i) << " ";
    }
    cout << "\n";
  }

  cout << "\n";
}
