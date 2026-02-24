#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool isPrime(int n) {}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> p;
    vector<int> res;

    for (int i = 1; i <= n; i++) {
      if (isPrime(i)) {
        p.push_back(i);
      } else {
        res.push_back(i);
      }
    }
  }
}
