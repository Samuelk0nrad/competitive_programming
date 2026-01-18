// 15 min
#include <iostream>

using namespace std;

int main() {
  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++) { // while (t--)
    // int n, j, k, max, js = 0;
    int n = 0;
    int j = 0;
    int k = 0;
    int max = 0;
    int js = 0;

    cin >> n;
    cin >> j;
    cin >> k;

    for (int x = 0; x < n; x++) {
      int s = 0;
      cin >> s;
      if (max < s)
        max = s;
      if (x + 1 == j)
        js = s;
    }
    // cout << (k == 1 && max > js ? "no" : "yes" ) << endl;
    if (k == 1) {
      if (max <= js)
        cout << "yes";
      else
        cout << "no";
    } else {
      cout << "yes";
    }
    cout << endl;
  }
}
