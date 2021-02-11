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

inline int ctoi(const char ch) { return ch - '0'; }

bool solve(string s) {
  const int n = SZ(s);
  if (n == 1) {
    return s == "8";
  }
  if (n == 2) {
    if (stoi(s) % 8 == 0) {
      return true;
    }
    swap(s[0], s[1]);
    return stoi(s) % 8 == 0;
  }
  vector<int> cnt(10);
  for (char ch : s) {
    cnt[ctoi(ch)]++;
  }
  
  for (int i = 112; i < 1000; i += 8) {
    auto c = cnt;
    
    for (char ch : to_string(i)) {
      c[ctoi(ch)]--;
    }

    if (all_of(ALL(c), [](int x) { return x >= 0; })) {
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  cout << (solve(s) ? "Yes" : "No") << "\n";
  return 0;
}
