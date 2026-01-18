#include <iostream>

using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  long long house = 1;
  long long step = 0;
  for (int i = 0; i < m; i++) {
    long long a = 0;
    cin >> a;
    if (a >= house) {
      step += a - house;
    } else {
      step += n - house + a;
    }
    house = a;
  }
  cout << step;
}
