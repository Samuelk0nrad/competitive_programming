#include <vector>
#ifdef EVAL
#include "potato.h"
#else
#include "grader.cpp"
#endif
#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> v;
vector<vector<bool>> h;

pair<int, int> pc;

pair<vector<char>, bool> dfs(pair<int, int> e, vector<char> &p) {
  if (e == pc) {
    return {p, true};
  }
  if (e.first < 250 && !h[e.first + 250 + 1][e.second + 250]) {
    if (!v[e.first + 250 + 1][e.second + 250]) {
      v[e.first + 1 + 250][e.second + 250] = true;
      p.push_back('R');
      auto res = dfs({e.first + 1, e.second}, p);
      if (res.second) {
        return res;
      }
      p.pop_back();
    }
  }
  if (e.first > -250 && !h[e.first + 250 - 1][e.second + 250]) {
    if (!v[e.first - 1 + 250][e.second + 250]) {
      v[e.first - 1 + 250][e.second + 250] = true;
      p.push_back('L');
      auto res = dfs({e.first - 1, e.second}, p);
      if (res.second) {
        return res;
      }
      p.pop_back();
    }
  }
  if (e.second < 250 && !h[e.first + 250][e.second + 250 + 1]) {
    if (!v[e.first + 250][e.second + 1 + 250]) {
      v[e.first + 250][e.second + 1 + 250] = true;
      p.push_back('U');
      auto res = dfs({e.first, e.second + 1}, p);
      if (res.second) {
        return res;
      }
      p.pop_back();
    }
  }
  if (e.second > -250 && !h[e.first + 250][e.second + 250 - 1]) {
    if (!v[e.first + 250][e.second - 1 + 250]) {
      v[e.first + 250][e.second - 1 + 250] = true;
      p.push_back('D');
      auto res = dfs({e.first, e.second - 1}, p);
      if (res.second) {
        return res;
      }
      p.pop_back();
    }
  }
  return {{}, false};
}

pair<int, int> move(vector<char> &p, pair<int, int> s) {
  for (char m : p) {
    if (m == 'R') {
      s.first++;
      if (!h[pc.first + 1 + 250][pc.second + 250]) {
        pc.first++;
      }
    }
    if (m == 'L') {
      s.first--;
      if (!h[pc.first - 1 + 250][pc.second + 250]) {
        pc.first--;
      }
    }
    if (m == 'U') {
      s.second++;
      if (!h[pc.first + 250][pc.second + 1 + 250]) {
        pc.second++;
      }
    }
    if (m == 'D') {
      s.second--;
      if (!h[pc.first + 250][pc.second - 1 + 250]) {
        pc.second--;
      }
    }
  }
  return s;
}

std::string find_potatocat(pair<int, int> georg, pair<int, int> potatocat,
                           vector<pair<int, int>> houses) {

  string res = "";

  pc = potatocat;
  if (houses.size() == 0) {
    return "";
  }

  h.resize(505, vector<bool>(505, false));
  v.resize(505, vector<bool>(505, false));
  for (auto e : houses) {
    h[e.first + 250][e.second + 250] = true;
  }

  vector<char> p;
  auto ans = dfs(georg, p);

  if (!ans.second) {
    return "";
  }
  vector<char> path = ans.first;

  string r(path.begin(), path.end());
  res += r;

  pair<int, int> s = move(path, georg);
  while (s != pc) {
    v.assign(505, vector<bool>(505, false));
    vector<char> p;
    auto ans = dfs(s, p);
    if (!ans.second) {
      break;
    }
    path = ans.first;
    s = move(path, s);
    string r(path.begin(), path.end());
    res += r;
  }

  // Falls es einen Weg gibt:
  return res;
}
