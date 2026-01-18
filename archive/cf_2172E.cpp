#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, j, k;
    cin >> n >> j >> k;

    vector<int> nv;
    if (n == 1) {
      nv.push_back(1);
    } else if (n == 12) {
      nv.push_back(1);
      nv.push_back(2);
    } else if (n == 123) {
      nv.push_back(1);
      nv.push_back(2);
      nv.push_back(3);
    } else if (n == 1234) {
      nv.push_back(1);
      nv.push_back(2);
      nv.push_back(3);
      nv.push_back(4);
    }

    vector<int> first(nv.begin(), nv.end());
    for (int i = 1; i < j; i++) {
      next_permutation(first.begin(), first.end());
    }
    vector<int> second(nv.begin(), nv.end());

    for (int i = 1; i < k; i++) {
      next_permutation(second.begin(), second.end());
    }

    int A = 0;
    int B = nv.size();

    for (int i = 0; i < nv.size(); i++) {
      if (first[i] == second[i]) {
        A++;
        B--;
      }
    }

    cout << A << "A" << B << "B\n";
  }
}
