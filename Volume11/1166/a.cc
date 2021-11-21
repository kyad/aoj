// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1166&lang=jp

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void testcase(int w, int h) {
  vector<vector<int> > wall_right(h, vector<int>(w - 1));
  vector<vector<int> > wall_down(h - 1, vector<int>(w));
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w - 1; x++) {
      cin >> wall_right[y][x];
    }
    if (y == h - 1) {
      continue;
    }
    for (int x = 0; x < w; x++) {
      cin >> wall_down[y][x];
    }
  }
  // BFS
  queue<pair<int, int> > todo;
  vector<vector<int> > dist(h, vector<int>(w, -1));
  dist[0][0] = 1;
  todo.push(make_pair(0, 0));
  while (!todo.empty()) {
    int y = todo.front().first;
    int x = todo.front().second;
    todo.pop();
    // up, left, down, right
    const int dy[4] = {-1, 0, 1, 0};
    const int dx[4] = {0, -1, 0, 1};
    for (int k = 0; k < 4; k++) {
      if (k == 0) {  // up
        if (y == 0 || wall_down[y - 1][x]) {
          continue;
        }
      } else if (k == 1) { // left
        if (x == 0 || wall_right[y][x - 1]) {
          continue;
        }
      } else if (k == 2) { // down
        if (y == h - 1 || wall_down[y][x]) {
          continue;
        }
      } else { // right
        if (x == w - 1 || wall_right[y][x]) {
          continue;
        }
      }
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (dist[ny][nx] >= 0) {
        continue;
      }
      dist[ny][nx] = dist[y][x] + 1;
      todo.push(make_pair(ny, nx));
    }
  }
  int ans = max(0, dist[h - 1][w - 1]);
  cout << ans << endl;
}

int main() {
  while (true) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }
    testcase(w, h);
  }
  return 0;
}
