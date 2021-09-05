// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B&lang=ja
// https://github.com/drken1215/book_algorithm_solution/blob/master/codes/chap13/code_13_2.cpp

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > graph;
vector<int> d;
vector<int> f;
int tm;

void dfs(int u) {
  d[u] = tm;
  tm++;
  for (size_t i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (d[v] >= 0) {
      continue;
    }
    dfs(v);
  }
  f[u] = tm;
  tm++;
}

int main() {
  int n;
  cin >> n;
  graph.resize(n);
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      graph[u - 1].push_back(v - 1);
    }
  }
  // DFS
  d.assign(n, -1);
  f.assign(n, -1);
  tm = 1;
  for (int i = 0; i < n; i++) {
    if (d[i] >= 0) {
      continue;
    }
    dfs(i);
  }
  for (int i = 0; i < n; i++) {
    cout << (i + 1) << ' ' << d[i] << ' ' << f[i] << endl;
  }
  return 0;
}
