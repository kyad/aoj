// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1127

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> parent, _size;

  UnionFind(int n) : parent(n, -1), _size(n, 1) {}

  int root(int x) {
    if (parent[x] == -1) {
      return x;
    } else {
      //return root(parent[x]);  // O(logN)
      return parent[x] = root(parent[x]);  // O(alpha(N))
    }
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return false;
    }
    if (_size[x] < _size[y]) {
      swap(x, y);  // Union by size
    }
    parent[y] = x;
    _size[x] += _size[y];
    return true;
  }

  int size(int x) {
    return _size[root(x)];
  }
};

double dist(double x0, double y0, double z0, double x1, double y1, double z1) {
  double sum = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) + (z1 - z0) * (z1 - z0);
  return sqrt(sum);
}

void testcase(int n) {
  vector<double> x(n), y(n), z(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> x.at(i) >> y.at(i) >> z.at(i) >> r.at(i);
  }
  UnionFind uf(n);
  vector<tuple<double, int, int> > edges;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double d = dist(x[i], y[i], z[i], x[j], y[j], z[j]);
      double cost = max(0., d - (r[i] + r[j]));
      edges.push_back(make_tuple(cost, i, j));
    }
  }
  sort(edges.begin(), edges.end());
  double ans = 0.;
  for (size_t k = 0; k < edges.size(); k++) {
    if (uf.size(0) == n) {
      break;
    }
    double cost = get<0>(edges[k]);
    int i = get<1>(edges[k]);
    int j = get<2>(edges[k]);
    if (uf.issame(i, j)) {
      continue;
    }
    ans += cost;
    uf.unite(i, j);
  }
  cout << fixed << setprecision(3) << ans << endl;
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
