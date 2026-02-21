#include <bits/stdc++.h>
#include <vector>

using namespace std;

int n;

void perm(vector<bool> &used, vector<int> &num, vector<int> &ans, int fix) {
  if (fix >= n) {
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    used[i] = true;
    ans.push_back(num[i]);
    perm(used, num, ans, fix + 1);
    ans.pop_back();
    used[i] = false;
  }
}

int main() {
  cin >> n;

  vector<int> a(n);
  for (int i = 1; i <= n; i++) {
    a[i - 1] = i;
  }
  vector<bool> u(n, false);
  vector<int> ans;
  perm(u, a, ans, 0);
}
