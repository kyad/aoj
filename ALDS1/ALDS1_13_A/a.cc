// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_A&lang=ja

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int k;
  cin >> k;
  vector<int> r(k), c(k);
  for (int i = 0; i < k; i++) {
    cin >> r.at(i) >> c.at(i);
  }
  vector<int> perm(8);
  for (int i = 0; i < 8; i++) {
    perm.at(i) = i;
  }
  do {
    bool ok = true;
    for (int i = 0; i < k; i++) {
      if (perm[r.at(i)] != c.at(i)) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    ok = true;
    for (int i = 0; i < 8; i++) {
      for (int j = i + 1; j < 8; j++) {
        int r0 = i;
        int c0 = perm.at(i);
        int r1 = j;
        int c1 = perm.at(j);
        int dr = r1 - r0;
        int dc = c1 - c0;
        if (abs(dr) == abs(dc)) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        break;
      }
    }
    if (ok) {
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          cout << (j == perm.at(i) ? 'Q' : '.');
        }
        cout << endl;
      }
      return 0;
    }
  } while (next_permutation(perm.begin(), perm.end()));
  return 0;
}
