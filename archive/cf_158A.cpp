#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  int ak = 0;
  for (int i = 0; i < n; i++) {
    int x = 0;
    cin >> x;
    a[i] = x;
    if (i == k - 1)
      ak = x;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (ak <= a[i] && a[i] > 0)
      res++;
  }
  cout << res;
}
