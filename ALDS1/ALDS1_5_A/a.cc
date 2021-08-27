// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<int> sum(1 << n, 0);
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        sum.at(i) += A[j];
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int m;
    cin >> m;
    string ans = "no";
    for (int j = 0; j < (1 << n); j++) {
      if (m == sum.at(j)) {
        ans = "yes";
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
