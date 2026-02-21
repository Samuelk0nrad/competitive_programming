#include <bits/stdc++.h>
#include <vector>

using namespace std;

int n, k;
void subset(const vector<int> &a, vector<int> &ans, int i) {
  if (i >= n) {
    if (ans.size() != k) {
      return;
    }
    for (int i : ans) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }
  ans.push_back(a[i]);
  subset(a, ans, i + 1);
  ans.pop_back();
  if (k - ans.size() >= n - i) {
    return;
  }
  subset(a, ans, i + 1);
}

int main() {
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 1; i <= n; i++) {
    a[i - 1] = i;
  }

  vector<int> ans;

  subset(a, ans, 0);
}
