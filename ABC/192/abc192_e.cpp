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

struct Edge {
  int to;
  LL cost;
  LL time;
};
using Graph = vector<vector<Edge>>;

template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

vector<LL> dijkstra(const Graph &G, int start) {
  int N = SZ(G);
  vector<LL> dis(N, INF);
  min_priority_queue<pair<LL, int>> que;

  dis[start] = 0;
  que.emplace(dis[start], start);

  while (!que.empty()) {
    const auto [distance, from] = que.top();
    que.pop();

    if (dis[from] < distance) {
      continue;
    }

    for (auto &&e : G[from]) {
      LL cur = (distance + e.time - 1) / e.time * e.time + e.cost;
      if (chmin(dis[e.to], cur)) {
        que.emplace(dis[e.to], e.to);
      }
    }
  }
  return dis;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  --X;
  --Y;

  Graph G(N);
  vector<LL> dist(N);

  REP(i, M) {
    int a, b;
    LL t, k;
    cin >> a >> b >> t >> k;
    --a;
    --b;

    G[a].push_back({b, t, k});
    G[b].push_back({a, t, k});
  }
  vector<LL> dis = dijkstra(G, X);
  if (dis[Y] == INF) {
    cout << -1 << "\n";
    return 0;
  }
  cout << dis[Y] << "\n";
  return 0;
}
