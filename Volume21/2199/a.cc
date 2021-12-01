// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2199&lang=jp

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 255 * 255 * 20000 + 1;

void testcase(int N, int M) {
  vector<int> C(M);
  for (int m = 0; m < M; m++) {
    cin >> C.at(m);
  }
  vector<int> x(N, 0);
  for (int n = 0; n < N; n++) {
    cin >> x.at(n);
  }
  const int Y = 256;
  vector<vector<int> > dp(N, vector<int>(Y, INF));
  // n = 0
  for (int m = 0; m < M; m++) {
    int y = 128 + C[m];
    y = max(y, 0);
    y = min(y, 255);
    dp[0][y] = (y - x[0]) * (y - x[0]);
  }
  for (int n = 0; n < N - 1; n++) {
    for (int y = 0; y < Y; y++) {
      for (int m = 0; m < M; m++) {
        int ny = y + C[m];
        ny = max(ny, 0);
        ny = min(ny, 255);
        int ne = dp[n][y] + (ny - x[n + 1]) * (ny - x[n + 1]);
        dp[n + 1][ny] = min(dp[n + 1][ny], ne);
      }
    }
  }
  cout << *min_element(dp[N - 1].begin(), dp[N - 1].end()) << endl;
}

int main() {
  while (true) {
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) {
      break;
    }
    testcase(N, M);
  }
  return 0;
}
