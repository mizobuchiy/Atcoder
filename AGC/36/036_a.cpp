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
#include <random>

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

struct GridPoint
{
    LL x, y;
};

double dis(GridPoint a, GridPoint b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double calc(vector<GridPoint> &t)
{
    double a, b, c, s, d;
    a = dis(t[0], t[1]);
    b = dis(t[1], t[2]);
    c = dis(t[2], t[0]);
    s = (a + b + c) / 2.0;
    d = s * (s - a) * (s - b) * (s - c);
    return d;
}

int main()
{
    long long s;
    cin >> s;
    if (s <= 10e+9)
    {
        cout << "0 0 1 0 0 " << s << endl;
    }
    else
    {
        vector<GridPoint> t(3);
        for (int i = 0; i < 3; ++i)
        {
            t[i].x = rand();
            t[i].y = rand();
        }
        std::mt19937 mt;
        std::random_device rnd;
        mt.seed(rnd());
        while (calc(t) != s / 2)
        {
            for (int i = 0; i < 3; ++i)
            {
                t[i].x = rand();
                t[i].y = rand();
                t[i].x %= 100000000;
                t[i].y %= 100000000;
            }
        }
        cout << t[0].x << " " << t[0].y << " " << t[1].x << " " << t[1].y << " " << t[2].x << " " << t[2].y << endl;
    }
}