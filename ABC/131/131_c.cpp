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

LL my_gcd(LL a, LL b)
{
    LL tmp, r;
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    LL A, B, C, D;
    cin >> A >> B >> C >> D;
    LL sum = B - A + 1;
    //dump(sum);
    LL cnt_c = B / C - (A - 1) / C;
    //dump(cnt_c);
    LL cnt_d = B / D - (A - 1) / D;
    //dump(cnt_d);
    LL cd = (C * D) / my_gcd(C, D);
    LL cnt_cd = B / cd - (A - 1) / cd;
    //dump(cnt_cd);
    sum = sum - (cnt_c + cnt_d) + cnt_cd;
    cout << sum << endl;
}