#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  long long n = 0;
  cin >> n;

  cout << n << " ";

  while(n != 1) {
    if(n % 2 == 1){
      n = n * 3 + 1;
      cout << n << " ";
    }
    n /= 2;
    cout << n << " ";
  }
}
