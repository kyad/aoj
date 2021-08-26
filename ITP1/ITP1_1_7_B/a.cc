// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=ja

#include <iostream>
using namespace std;

int solve(int n, int x) {
  int count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = j + 1; k <= n; k++) {
        if (i + j + k == x) {
          count++;
        }
      }
    }
  }
  cout << count << endl;
}

int main() {
  while (true) {
    int n, x;
    cin >> n >> x;
    if (n == 0 && x == 0) {
      break;
    }
    solve(n, x);
  }
  return 0;
}
