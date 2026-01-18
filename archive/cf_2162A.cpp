#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t = 0;
  cin >> t;

  for(int i = 0; i < t; i++){
    int n = 0;
    cin >> n;
    
    int max = 0;

    for(int j = 0; j < n; j++){
      int a = 0;
      cin >> a;

      if(a > max) max = a;
    }

    cout << max << "\n";
  }
}
