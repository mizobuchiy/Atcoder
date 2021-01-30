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
#define MOD 1000000007

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> grid(N + 1);
    int p = 0, q = 0;
    for (int i = 1; i <= N; ++i)
    {
        cin >> grid[i].first >> grid[i].second;
    }
    for (int i = 1; i < N; ++i)
    {
        p += grid[i + 1].first - grid[i].first;
        q += grid[i + 1].second - grid[i].second;
    }
    p /= N - 1;
    q /= N - 1;
    if (p == 0 && q == 0)
    {
        p++;
    }
    pair<int, int> now = {grid[1].first, grid[1].second};
    int point_p = 1;
    vector<bool> ok(N + 1, true);
    ok[1] = false;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = i; j <= N; ++j)
        {
            if (ok[j])
            {
                if (now.first + p == grid[j].first && now.second + q == grid[j].second)
                {
                    cout << "j:" << j << endl;
                    ok[j] = false;
                    now = {grid[j].first,
                           grid[j].second};
                    break;
                }
            }
        }
    }
    for (int i = 2; i <= N; ++i)
    {
        if (ok[i])
        {
            cout << "i:" << i << endl;
            point_p++;
        }
    }
    --p;
    if (p == 0 && q == 0)
    {
        q++;
    }
    now = {grid[1].first, grid[1].second};
    int point_q = 1;
    ok.assign(N + 1, true);
    ok[1] = false;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = i; j <= N; ++j)
        {
            if (ok[j])
            {
                if (now.first + p == grid[j].first && now.second + q == grid[j].second)
                {
                    cout << "j:" << j << endl;
                    ok[j] = false;
                    now = {grid[j].first,
                           grid[j].second};
                    break;
                }
            }
        }
    }
    for (int i = 2; i <= N; ++i)
    {
        if (ok[i])
        {
            cout << "i:" << i << endl;
            point_q++;
        }
    }

    cout << min(point_p, point_q) << endl;
}