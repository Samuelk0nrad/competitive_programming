// 35 min
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t = 0;
  cin >> t;
  for (int j = 0; j < t; j++) { // while (t--)
    int n = 0;
    cin >> n;
    vector<int> numbers; // numbers(n)
    string res(n, '0');
    int min = -1;
    for (int i = 0; i < n; i++) {
      int x = 0;
      cin >> x;
      numbers.push_back(x); // numbers[i] = x;
      if (min > x || min == -1) {
        res[i] = '1';
        min = x;
      }
    }

    int max = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (max < numbers[i]) {
        res[i] = '1';
        max = numbers[i];
      }
    }
    cout << res << endl;
  }
}
