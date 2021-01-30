//include
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

// conversion
inline int
toInt(string s)
{
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}
template <class T>
inline string toString(T x)
{
    ostringstream sout;
    sout << x;
    return sout.str();
}

//change
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

//math
template <class T>
inline T sqr(T x) { return x * x; }

template <class T>
inline T nCr(T n, T r)
{
    T num = 1;
    for (int i = 1; i <= r; ++i)
    {
        num *= (n - i + 1) / i;
    }
    return num;
}
template <class T>
inline T nPr(T n, T r)
{
    r = n - r;
    T sum = 1;
    int i;
    for (i = n; i >= r + 1; --i)
        sum *= i;
    return sum;
}

template <class T>
inline T facctorial(T k)
{
    T sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

//numeric
template <class T>
inline T gcd(T a, T b)
{
    if (a < b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    return b ? gcd(b, a % b) : a;
}

template <class T>
inline T lcm(T a, T b)
{
    return a * b / gcd(a, b);
}

//typedef
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())

//repetition
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define REP(i, n) FOR(i, 0, n)

//constant
constexpr double EPS = 1e-10;
const double PI = acos(-1.0);
constexpr LL INF = 1e10;

//clear memory
#define CLR(a) memset((a), 0, sizeof(a))

//debug
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;

int n, q;
vector<int> a;
vector<int> b;
vector<int> p;
vector<int> x;
vector<int> cnt;
vector<int> flag;
vector<vector<int>> child;

void dfs(int pointer, int score)
{
    flag[pointer - 1] = 1;
    cnt[pointer - 1] += score;
    int m = child[pointer - 1].size();
    for (int j = 0; j < m; ++j)
    {
        if (flag[child[pointer - 1][j] - 1] == 0)
        {
            dfs(child[pointer - 1][j], score);
        }
    }
}

int main()
{

    cin >> n >> q;
    a.resize(n - 1);
    b.resize(n - 1);
    p.resize(q);
    x.resize(q);
    cnt.resize(n);
    flag.resize(n);
    child.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a[i] >> b[i];
        cnt[i] = 0;
        flag[i] = 0;
        child[a[i] - 1].push_back(b[i]);
    }
    cnt[n - 1] = 0;
    flag[n - 1] = 0;
    for (int i = 0; i < q; ++i)
    {
        cin >> p[i] >> x[i];
    }
    for (int i = 0; i < q; ++i)
    {
        dfs(p[i], x[i]);
        for (int j = 0; j < n; ++j)
        {
            flag[j] = 0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << cnt[i] << " ";
    }
    cout << endl;
}
