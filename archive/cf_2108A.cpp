#include <iostream>

using namespace std;

int main() {
  int t = 0;
  cin >> t;

  for (int j = 0; j < t; j++) {
    int n = 0;
    cin >> n;

    int count = (n * n / 4) + 1;
    cout << count << endl;
  }
}
