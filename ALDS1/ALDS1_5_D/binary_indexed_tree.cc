// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja
// https://atcoder.jp/contests/abc221/editorial/2718
// https://algo-logic.info/binary-indexed-tree/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct binary_indexed_tree {
  int N;
  vector<int> bit;
  binary_indexed_tree() {}
  binary_indexed_tree(int n) : N(n) {
    bit.resize(N + 1, 0);
  }
  void resize(int n) {
    N = n;
    bit.resize(N + 1, 0);
  }
  // Add x to a[k], O(logN)
  // k: 1-indexed
  void add(int k, int x) {
    for (; k <= N; k += (k & -k)) {
      bit[k] += x;
    }
  }
  // Returns a[1] + a[2] + ... + a[k], O(logN)
  // k: 1-indexed
  int sum(int k) {
    int ret = 0;
    for (; k > 0; k -= (k & -k)) {
      ret += bit[k];
    }
    return ret;
  }
};

// Return 0-order compressed vector whose size is same as A
vector<int> compress(vector<int> A) {
  vector<int> a(A);
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  map<int, int> m;
  for (size_t i = 0; i < a.size(); i++) {
    m[a[i]] = i;
  }
  vector<int> ans(A.size());
  for (size_t i = 0; i < A.size(); i++) {
    ans[i] = m[A[i]];
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  binary_indexed_tree bit(n);
  vector<int> a(n);
  for (int j = 0; j < n; j++) {
    cin >> a.at(j);
  }
  vector<int> A = compress(a);
  long long ans = 0;
  for (int j = 0; j < n; j++) {
    ans += (j - bit.sum(A.at(j) + 1));
    bit.add(A.at(j) + 1, 1);
  }
  cout << ans << endl;
  return 0;
}
