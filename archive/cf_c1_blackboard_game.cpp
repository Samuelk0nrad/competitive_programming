#include <iostream>

using namespace std;

int main() {
  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0;
    cin >> n;

    if (!(n % 2)) {
      if (!(n % 4)) {
        cout << "Bob";
      } else {
        cout << "Alice";
      }
    } else {
      cout << "Alice";
    }
    cout << endl;
  }
}
