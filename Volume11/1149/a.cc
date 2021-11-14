// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1149&lang=jp

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void testcase(int n, int w, int d) {
  vector<pair<int, int> > cakes;
  cakes.push_back(make_pair(w, d));
  for (int i = 0; i < n; i++) {
    int p, s;
    cin >> p >> s;
    p--;
    int w0 = cakes[p].first;
    int h0 = cakes[p].second;
    cakes.erase(cakes.begin() + p);
    s %= (w0 + h0);
    if (s < w0) {
      // Cut vertical
      if (s <= w0 / 2) {
        cakes.push_back(make_pair(s, h0));
        cakes.push_back(make_pair(w0 - s, h0));
      } else {
        cakes.push_back(make_pair(w0 - s, h0));
        cakes.push_back(make_pair(s, h0));
      }
    } else {
      // Cut horizontal
      if (s - w0 <= h0 / 2) {
        cakes.push_back(make_pair(w0, s - w0));
        cakes.push_back(make_pair(w0, h0 - (s - w0)));
      } else {
        cakes.push_back(make_pair(w0, h0 - (s - w0)));
        cakes.push_back(make_pair(w0, s - w0));
      }
    }
  }
  vector<int> areas(n + 1);
  for (int i = 0; i < n + 1; i++) {
    areas[i] = cakes[i].first * cakes[i].second;
  }
  sort(areas.begin(), areas.end());
  for (int i = 0; i < n + 1; i++) {
    cout << areas[i] << (i == n ? '\n' : ' ');
  }
}

int main() {
  int n, w, d;
  while (true) {
    cin >> n >> w >> d;
    if (n == 0 && w == 0 && d == 0) {
      break;
    }
    testcase(n, w, d);
  }
  return 0;
}
