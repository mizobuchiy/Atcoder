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

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> vec(M);

    for (int i = 0; i < M; ++i)
    {
        int k;
        cin >> k;
        vec[i].resize(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> vec[i][j];
            --vec[i][j];
        }
    }

    vector<int> p(M);
    for (int i = 0; i < M; ++i)
        cin >> p[i];

    int ans = 0;
    for (int i = 0; i < (1 << N); ++i)
    {
        bool ok = true;
        for (int j = 0; j < M; ++j)
        {
            int c = 0;
            for (int id : vec[j])
            {
                if ((i >> id) & 1)
                {
                    ++c;
                }
            }
            c %= 2;
            if (c != p[j])
            {
                ok = false;
            }
        }
        if (ok)
        {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
