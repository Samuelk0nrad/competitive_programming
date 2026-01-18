#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t = 0;
  cin >> t;

  for (int i = 0; i < t; i++) {
    long long n = 0;
    cin >> n;
    vector<long long> numbers;
    bool res = false;
    int l = -1;
    int mx = 0;
    for (long long j = 0; j < n; j++) {
      long long x = 0;
      cin >> x;
      if (l == -1)
        l = x;
      else if (!(l == x)) {
        res = true;
      }
      l = x;
      if (mx < x)
        mx = x;
      numbers.push_back(x);
    }
    if (res)
      cout << "yes" << endl;
    else {
      cout << "no" << endl;
      continue;
    }
    for (int j = 0; j < n; j++) {
      if (numbers[j] == mx)
        cout << 2 << " ";
      else
        cout << 1 << " ";
    }
    cout << endl;
  }
}
