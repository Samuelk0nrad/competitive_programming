#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

vector<string> g;
vector<vector<pair<int, int>>> grid;

vector<vector<int>> adjy;
vector<vector<int>> adjx;
vector<int> adx;
vector<int> ady;

vector<vector<bool>> v;
void dfs(int x, int y, int dx, int dy) {
  if (g[y][x] == '.') {
    return;
  }
  if (!v[y - 1][x] && grid[y - 1][x].first != -1) {
    v[y - 1][x] = true;
    int i = 0;
    if (adjy[grid[y - 1][x].first][0] == -1) {
      adjy[grid[y - 1][x].first][0] = grid[y][x].first;
      dy += 1;
      ady[grid[y - 1][x].first] = dy;
    }
    dfs(x, y - 1, dx, dy);
  }
  if (!v[y + 1][x] && grid[y + 1][x].first != -1) {
    v[y + 1][x] = true;
    int i = 0;
    if (adjy[grid[y + 1][x].first][0] == -1) {
      adjy[grid[y + 1][x].first][0] = grid[y][x].first;
      dy += 1;
      ady[grid[y + 1][x].first] = dy;
    }
    dfs(x, y + 1, dx, dy);
  }
  if (!v[y][x - 1] && grid[y][x - 1].second != -1) {
    v[y][x - 1] = true;
    int i = 0;
    if (adjx[grid[y][x - 1].second][0] == -1) {
      adjx[grid[y][x - 1].second][0] = grid[y][x].second;
      dx += 1;
      adx[grid[y][x - 1].second] = dx;
    }
    dfs(x - 1, y, dx, dy);
  }
  if (!v[y][x + 1] && grid[y][x + 1].second != -1) {
    v[y][x + 1] = true;
    if (adjx[grid[y][x + 1].second][0] == -1) {
      adjx[grid[y][x + 1].second][0] = grid[y][x].second;
      dx += 1;
      adx[grid[y][x + 1].second] = dx;
    }
    dfs(x + 1, y, dx, dy);
  }
}

int query(vector<int> &deph, vector<vector<int>> &arr, int a, int b) {
  if (deph[a] < deph[b]) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  int res = 0;
  if (a != b) {
    int d = deph[a] - deph[b];
    for (int i = 30; i >= 0; i--) {
      if (d >= 1 << i) {
        d -= 1 << i;
        res += 1 << i;
        a = arr[a][i];
      } else if (d == 0) {
        break;
      }
    }
  }
  for (int i = 30; i >= 0; i--) {
    if (arr[a][i] != arr[b][i]) {
      res += (1 << i) * 2;
      a = arr[a][i];
      b = arr[b][i];
    }
    if (a == b) {
      break;
    }
    if (arr[a][0] == arr[b][0]) {
      res += 2;
      break;
    }
  }
  return res;
}

int main() {
  int n, q;
  cin >> n >> q;

  grid.resize(n + 5, vector<pair<int, int>>(n + 5, {-1, -1}));
  g.resize(n + 5);

  pair<int, int> root = {-1, -1};
  string s;
  int nx = 0, ny = 0;
  for (int i = 0; i < n; i++) {
    cin >> s;
    g[i] = s;
    if (i != 0) {
      for (int j = 0; j < n; j++) {
        if (s[j] == '#') {
          if (root.first == -1) {
            root = {i, j};
          }
          if (s[j - 1] != '#') {
            nx++;
          }
          grid[i][j].first = nx;
          if (g[i - 1][j] != '#') {
            ny++;
            grid[i][j].second = ny;
          } else {
            grid[i][j].second = grid[i - 1][j].second;
          }
        }
      }
    }
  }

  adjy.resize(nx + 5, vector<int>(34, -1));
  adjx.resize(ny + 5, vector<int>(34, -1));
  v.resize(ny, vector<bool>(nx, false));
  adx.resize(ny + 5);
  ady.resize(nx + 5);

  v[root.first][root.second] = true;
  adjy[grid[root.first][root.second].first][0] = 0;
  adjx[grid[root.first][root.second].second][0] = 0;
  adjx[0][0] = 0;
  adjy[0][0] = 0;
  dfs(root.second, root.first, 0, 0);

  for (int i = 1; i < 30; i++) {
    for (int j = 0; j < ny; j++) {
      if (adjx[j][i - 1] == -1) {
        adjx[j][i - 1] = 0;
      }
      adjx[j][i] = adjx[adjx[j][i - 1]][i - 1];
    }
    for (int j = 0; j < nx; j++) {
      if (adjy[j][i - 1] == -1) {
        adjy[j][i - 1] = 0;
      }
      adjy[j][i] = adjy[adjy[j][i - 1]][i - 1];
    }
  }

  int r1, c1, r2, c2;
  for (int i = 0; i < q; i++) {
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;
    int sy = grid[r1][c1].first;
    int sx = grid[r1][c1].second;

    int gy = grid[r2][c2].first;
    int gx = grid[r2][c2].second;

    int rx = query(adx, adjx, sx, gx);
    int ry = query(ady, adjy, sy, gy);
    cout << rx + ry << "\n";
  }
  return 0;
}

// 8 4
// ........
// ..##....
// .#####..
// ...###..
// ..#####.
// .####...
// ...####.
// ........
// 2 3 3 6
// 2 3 6 2
// 4 5 4 5
//
//
// 10 10
// ..........
// .##.......
// .########.
// .......#..
// ....####..
// .####.....
// ..###.....
// ...###....
// ....#.....
// ..........
// 2 2 9 6
// 3 9 2 2
//
//
//
// 40 25
// ........................................
// .##################################.....
// .##################################.....
// .............................######.....
// .............................#########..
// ....##########################..........
// ....######..............................
// .........#####################..........
// ........................######..........
// ...######################...............
// ...#....................................
// ...#################....................
// ...................#....................
// ...................##################...
// ....................................#...
// .......##############################...
// .......#................................
// .......#########################........
// ...............................#........
// ..##############################........
// ..#############.........................
// ..............#####################.....
// ..................................#.....
// .....##############################.....
// .....#..................................
// .....#############################......
// ...........................#######......
// ...........................#............
// .........###################............
// .........#..............................
// .........###########################....
// ...................................#....
// .###################################....
// .########################...............
// ........................#...............
// ........................##############..
// ...........##############...............
// ...........#............................
// ...........###################..........
// ........................................
// 16 36 10 25
