#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n + 1);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
  }
  int position = 1;
  while (position < t) {
    position += a[position];
  }
  cout << (position == t ? "YES" : "NO");
}
