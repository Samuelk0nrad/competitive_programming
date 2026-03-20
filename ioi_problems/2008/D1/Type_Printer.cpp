#include <bits/stdc++.h>

using namespace std;

struct Letter {
  char letter = ' ';
  int n = 0;
  bool last = false;
  vector<Letter> next;
};

vector<Letter> words;
string lword;
string res;

void dfs(Letter &start, int l) {
  res += start.letter;
  if (start.last) {
    res += "P";
  }
  for (Letter &e : start.next) {
    if (l != -1 && e.letter == lword[l])
      continue;
    if (e.n != 0) {
      dfs(e, -1);
      e.n = 0;
    }
    if (e.last) {
      dfs(e, -1);
    }
  }
  if (l != -1 && lword.size() > l) {
    dfs(start.next[lword[l] - 97], l + 1);
  }
  res += "-";
}

int main() {
  int n;
  cin >> n;
  words.resize(27);
  string word;
  for (int i = 0; i < n; i++) {
    cin >> word;
    if (word.size() > lword.size()) {
      lword = word;
    }
    Letter *l = 0;
    for (char e : word) {
      if (l == 0) {
        l = &words[e - 97];
      } else {
        l->n++;
        l = &l->next[e - 97];
      }
      if (l->next.size() != 27) {
        l->next.resize(27);
        l->letter = e;
      }
    }
    l->last = true;
  }

  for (Letter &e : words) {
    if (e.letter == lword[0])
      continue;
    if (e.n != 0) {
      dfs(e, -1);
      e.n = 0;
    }
    if (e.last) {
      dfs(e, -1);
    }
  }
  dfs(words[lword[0] - 97], 1);

  int size = res.size() - lword.size();
  cout << size << "\n";
  for (int i = 0; i < size; i++) {
    cout << res[i] << "\n";
  }
}
