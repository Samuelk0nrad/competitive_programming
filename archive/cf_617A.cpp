#include <iostream>

using namespace std;

int main() {
  int x = 0;
  cin >> x;
  int fifes = x / 5;
  x -= fifes * 5;
  int res = fifes;
  int fours = x / 4;
  res += fours;
  x -= fours * 4;
  int threes = x / 3;
  res += threes;
  x -= threes * 3;
  int twos = x / 2;
  res += twos;
  x -= twos * 2;
  res += x;

  cout << res;
}
