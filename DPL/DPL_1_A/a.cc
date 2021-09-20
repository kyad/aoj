// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=ja

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(m);
  for (int j = 0; j < m; j++) {
    cin >> c.at(j);
  }
  const int INF = 50001;
  vector<int> dp(n + 1, INF);
  dp.at(0) = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      int k = i - c[j];
      if (k < 0) {
        continue;
      }
      dp.at(i) = min(dp.at(i), dp.at(k) + 1);
    }
  }
  cout << dp.at(n) << endl;
  return 0;
}
