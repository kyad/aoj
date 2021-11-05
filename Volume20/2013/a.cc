// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2013

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void testcase(int n) {
  vector<string> start(n), end(n);
  vector<string> times;
  for (int i = 0; i < n; i++) {
    string _start, _end;
    cin >> _start >> _end;
    start.at(i) = _start;
    end.at(i) = _end;
    times.push_back(_start);
    times.push_back(_end);
  }
  sort(times.begin(), times.end());
  map<string, int> time_to_idx;
  for (size_t i = 0; i < times.size(); i++) {
    if (time_to_idx.count(times[i]) == 0) {
      size_t sz = time_to_idx.size();
      time_to_idx[times[i]] = sz;
    }
  }
  int N = (int)time_to_idx.size();
  vector<int> imos(N, 0);
  for (int i = 0; i < n; i++) {
    imos[time_to_idx[start[i]]]++;
    imos[time_to_idx[end[i]]]--;
  }
  for (int i = 0; i < N - 1; i++) {
    imos[i + 1] += imos[i];
  }
  cout << *max_element(imos.begin(), imos.end()) << endl;
}

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    testcase(n);
  }
  return 0;
}
