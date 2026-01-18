#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string name = "";
  cin >> name;
  sort(name.begin(), name.end());
  char last = ' ';
  int res = 0;
  for (int i = 0; i < name.size(); i++) {
    if (name[i] != last) {
      last = name[i];
      res++;
    }
  }
  cout << (res % 2 ? "IGNORE HIM!" : "CHAT WITH HER!");
}
