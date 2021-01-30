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
    int N;
    cin >> N;
    vector<int> u(N + 1);
    vector<int> v(N + 1);
    vector<int> w(N + 1);
    vector<int> t(N + 1);
    for (int i = 1; i < N; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
    for (int i = 1; i < N; i++)
    {
        t[i] = 0;
    }
    for (int i = 1; i <= N; i++)
    {
        if (w[i] % 2 == 0)
        {
        }
        else
        {
            if (t[u[i]] == t[v[i]])
            {
                t[u[i]] = 1;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout << t[i] << endl;
    }
}