// include
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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

// typedef
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

// container util
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define EACH(i, c) \
  for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())

// repetition
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)
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

int main() {
  size_t n;
  cin >> n;
  vector<string> s(n);
  for (auto &&i : s) {
    cin >> i;
  }
  set<string> set_s;
  for (size_t i = 0; i < n; i++) {
    set_s.insert(s[i]);
  }
  for (size_t i = 0; i < n; i++) {
    if (s[i][0] == '!') {
      continue;
    }
    decltype(set_s)::iterator it = set_s.find(s[i]);
    if (it == set_s.end()) {
      continue;
    }
    string tmp = s[i];
    tmp.insert(0, "!");
    decltype(set_s)::iterator it2 = set_s.find(tmp);
    if (it2 == set_s.end()) {
      continue;
    }
    cout << s[i] << "\n";
    return 0;
  }
  cout << "satisfiable"
       << "\n";

  return 0;
}
