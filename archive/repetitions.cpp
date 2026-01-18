#include <bits/stdc++.h>

using namespace std;

int main() {
  string dna = "";
  cin >> dna;

  int currentLength = 0;
  char lastChar = ' ';
  int longest = 0;

  for (int i = 0; i < dna.length(); i++) {
    if (lastChar == dna[i]) {
      currentLength++;
    } else {
      if (currentLength > longest) {
        longest = currentLength;
      }

      currentLength = 1;
    }
    lastChar = dna[i];
  }

  if (currentLength > longest) {
    longest = currentLength;
  }

  cout << longest;

  return 0;
}
