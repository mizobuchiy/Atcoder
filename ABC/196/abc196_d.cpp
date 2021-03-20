#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
// include
#include <bits/stdc++.h>

using namespace std;

// conversion
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
// change
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
// math
template <class T>
inline T sqr(T x) {
  return x * x;
}

template <class T>
inline T nCr(T n, T r) {
  T num = 1;
  for (int i = 1; i <= r; ++i) {
    num *= (n - i + 1) / i;
  }
  return num;
}
template <class T>
inline T nPr(T n, T r) {
  r = n - r;
  T sum = 1;
  int i;
  for (i = n; i >= r + 1; --i) sum *= i;
  return sum;
}

template <class T>
inline T facctorial(T k) {
  T sum = 1;
  for (int i = 1; i <= k; ++i) {
    sum *= i;
  }
  return sum;
}
// numeric
template <class T>
inline T gcd(T a, T b) {
  if (a < b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return b ? gcd(b, a % b) : a;
}

template <class T>
inline T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
// using
using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using PII = pair<int, int>;
using LL = int64_t;

// container util
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) static_cast<int>((a).size())
#define EACH(i, c) \
  for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())

// repetition
#define FOR(i, a, b) for (int i = (a); i < static_cast<int>(b); ++i)
#define REP(i, n) FOR(i, 0, n)

// constant
constexpr double EPS = 1e-10;
const double PI = acos(-1.0);
constexpr LL INF = 1e10;

// clear memory
#define CLR(a) memset((a), 0, sizeof(a))

// debug
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x)                                         \
  cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
       << " " << __FILE__ << endl;

void debug_vec2(auto vec2) {
  for (auto &&vec : vec2) {
    for (auto &&elem : vec) {
      cerr << elem << " ";
    }
    cerr << "\n";
  }
}

int dfs(int H, int W, int i, int j, int A, int B,
        vector<vector<bool>> &can_put) {
  if (A < 0 || B < 0) {
    return 0;
  }
  if (j == W) {
    j = 0;
    ++i;
  }
  if (i == H) {
    return 1;
  }
  if (!can_put[i][j]) {
    return dfs(H, W, i, j + 1, A, B, can_put);
  }
  int res = 0;
  can_put[i][j] = false;
  res += dfs(H, W, i, j + 1, A, B - 1, can_put);
  if (j < W - 1 && can_put[i][j + 1]) {
    can_put[i][j + 1] = false;
    res += dfs(H, W, i, j + 1, A - 1, B, can_put);
    can_put[i][j + 1] = true;
  }
  if (i < H - 1 && can_put[i + 1][j]) {
    can_put[i + 1][j] = false;
    res += dfs(H, W, i, j + 1, A - 1, B, can_put);
    can_put[i + 1][j] = true;
  }
  can_put[i][j] = true;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  vector<vector<bool>> can_put(H, vector<bool>(W, true));
  cout << dfs(H, W, 0, 0, A, B, can_put) << "\n";
  return 0;
}
