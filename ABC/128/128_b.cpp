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
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)

bool mycompare(const tuple<string, int, int> &lhs, const tuple<string, int, int> &rhs)
{
    if (get<0>(lhs) == get<0>(rhs))
    {
        return get<1>(lhs) > get<1>(rhs);
    }
    else
    {
        return get<0>(lhs) < get<0>(rhs);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<tuple<string, int, int>> S(N + 1);
    string temps;
    int temp;
    for (int i = 1; i <= N; i++)
    {
        cin >> temps >> temp;
        S[i] = make_tuple(temps, temp, i);
    }
    sort(ALL(S), mycompare);
    for (int i = 1; i <= N; i++)
    {
        cout << get<2>(S[i]) << endl;
    }
}