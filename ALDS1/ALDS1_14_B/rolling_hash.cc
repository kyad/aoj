// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja
// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
// https://drken1215.hatenablog.com/entry/2019/09/16/014600
// https://www.npca.jp/magazine/2021/maguro
// https://atcoder.jp/contests/abc274/editorial/5026

#include <iostream>
#include <vector>
using namespace std;

// ローリングハッシュ
#include <ctime>
#include <random>
struct RollingHash {
  static const unsigned long long MOD = (1ULL<<61) - 1;  // MOD=2^61-1

  int N;
  unsigned long long base = 10000000007;
  vector<unsigned long long> hash;
  vector<unsigned long long> power;

  // x mod MODを返す
  unsigned long long mod(unsigned long long x) {
    const unsigned long long MASK61 = MOD;
    unsigned long long xu = x>>61;
    unsigned long long xd = x & MASK61;
    unsigned long long ans = xu + xd;
    if (ans >= MOD) {
      ans -= MOD;
    }
    return ans;
  }
    
  // (a * b) mod MODを返す
  unsigned long long mul(unsigned long long a, unsigned long long b) {
    const unsigned long long MASK30 = (1ULL<<30) - 1;
    const unsigned long long MASK31 = (1ULL<<31) - 1;
    unsigned long long au = a>>31;
    unsigned long long ad = a & MASK31;
    unsigned long long bu = b>>31;
    unsigned long long bd = b & MASK31;
    unsigned long long mid = ad * bu + au * bd;
    unsigned long long midu = mid>>30;
    unsigned long long midd = mid & MASK30;
    unsigned long long ans = au * bu * 2 + midu + (midd<<31) + ad * bd;
#if 0  // 各A[i]が2^31以下であればmod無しで高速化可能
    ans = mod(ans);
#endif
    return ans;
  }

  // ランダムなbaseを決めたい時に使う。RollingHash::random_base()で呼ぶ
  static unsigned long long random_base() {
    time_t now = time(nullptr);
    mt19937_64 mt((unsigned long long)now);
    uniform_int_distribution<unsigned long long> dist(1ULL, MOD - 1);
    return dist(mt);
  }

  // 初期化 O(N)
  void build(const string &A) {
    N = A.size();
    hash.resize(N + 1, 0);
    power.resize(N + 1, 1);
    for (int n = 0; n < N; n++) {
      hash.at(n + 1) = mod(mul(hash.at(n), base) + A.at(n));
      power.at(n + 1) = mod(mul(power.at(n), base));
    }
  }

  // コンストラクタ
  RollingHash(const string &A, unsigned long long _base) : base(_base) { build(A); }
  RollingHash(const string &A) { RollingHash(A, random_base()); }

  // [a, b)のハッシュを取得 O(1)
  unsigned long long get(int a, int b) {  // 0-indexed
    const unsigned long long POSITIVIZER = MOD * 4;
    unsigned long long ans = mod(hash.at(b) + POSITIVIZER - mul(hash.at(a), power.at(b - a)));
    return ans;
  }
};

ostream& operator<<(ostream& os, const RollingHash rh) {
  os << "N=" << rh.N << endl;
  os << "base=" << rh.base << endl;
  const int MOD = -1;
  auto print = [&](const vector<unsigned long long> &v) {
    int N = v.size();
    os << '[';
    for (int i = 0; i < N; i++) {
      //os << "["<< i << "]=";
      os << v[i];
      if (i == N - 1) { continue; }
      else if (MOD > 0 && i % MOD == (MOD - 1)) { os << '\n'; }
      else { os << ' '; }
    }
    os << ']';
  };
  os << "hash=";
  print(rh.hash);
  os << endl;
  os << "power=";
  print(rh.power);
  return os;
}

int main() {
  string T;
  cin >> T;
  string P;
  cin >> P;
  unsigned long long base = RollingHash::random_base();
  RollingHash rh_t(T, base);
  RollingHash rh_p(P, base);
  unsigned long long p = rh_p.get(0, P.size());
  for (size_t i = 0; i < T.size(); i++) {
    size_t b = i + P.size();
    if (b > T.size()) {
      continue;
    }
    unsigned long long t = rh_t.get(i, b);
    if (p == t) {
      cout << i << '\n';
    }
  }
  return 0;
}
