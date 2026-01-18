#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 0;
  cin >> n;

  long long lastNum = 0;
  long long cost = 0;

  for (int i = 0; i < n; ++i) {
    long long num = 0;
    cin >> num;
    long long currentCost = lastNum - num;
    if (currentCost > 0) {
      cost += currentCost;
    } else {
      lastNum = num;
    }
  }
  cout << cost;
}
