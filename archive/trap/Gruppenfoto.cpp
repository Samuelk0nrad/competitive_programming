#include <bits/stdc++.h>

using namespace std;

bool f(int k, int n, vector<int> &larger, vector<int> &smaller) {
  int l = 0;
  for (int i = 0; i < n && l < k; i++) {
    if (smaller[i] >= l && larger[i] >= k - l - 1) {
      l++;
    }
  }
  return l == k;
}

int solve(int n, vector<int> &larger, vector<int> &smaller) {
  int l = 1, r = n;
  while (r > l) {
    int m = l + (r - l + 1) / 2;
    if (f(m, n, larger, smaller)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> smaller(n), larger(n);
  for (int i = 0; i < n; i++)
    cin >> smaller[i];
  for (int i = 0; i < n; i++)
    cin >> larger[i];
  // int solution = solve(n, larger, smaller);
  int solution = solve(n, larger, smaller);
  cout << solution << endl;
  return 0;
}
