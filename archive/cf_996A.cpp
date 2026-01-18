#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 0;
  cin >> n;
  int number = 0;
  while (n > 0) {
    number++;
    if (n >= 100) {
      n -= 100;
    } else if (n >= 20) {
      n -= 20;
    } else if (n >= 10) {
      n -= 10;
    } else if (n >= 5) {
      n -= 5;
    } else {
      n--;
    }
  }
  cout << number;
  return 0;
}
