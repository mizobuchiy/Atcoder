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

struct Baggage {
  int weight;
  int value;
};

struct Box {
  int capacity;
  int num;
};

struct Query {
  int L;
  int R;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, Q;
  cin >> N >> M >> Q;

  vector<Baggage> baggages(N);
  for (Baggage &baggage : baggages) {
    cin >> baggage.weight >> baggage.value;
  }
  sort(ALL(baggages), [](Baggage const &lhs, Baggage const &rhs) {
    if (lhs.value == rhs.value) {
      return lhs.weight < rhs.weight;
    }
    return lhs.value > rhs.value;
  });

  vector<Box> boxes(M);
  REP(i, M) {
    cin >> boxes[i].capacity;
    boxes[i].num = i;
  }
  sort(ALL(boxes), [](Box const &lhs, Box const &rhs) {
    return lhs.capacity < rhs.capacity;
  });
  vector<Query> queries(Q);
  for (Query &query : queries) {
    cin >> query.L >> query.R;
    --query.L;
    --query.R;
  }

  for (Query &query : queries) {
    vector<bool> can_put(M, true);
    int value_sum = 0;
    for (Baggage &baggage : baggages) {
      for (Box &box : boxes) {
        if (query.L <= box.num && box.num <= query.R) {
          continue;
        }
        if (can_put[box.num] && box.capacity >= baggage.weight) {
          can_put[box.num] = false;
          value_sum += baggage.value;
          break;
        }
      }
    }
    cout << value_sum << "\n";
  }

  return 0;
}
