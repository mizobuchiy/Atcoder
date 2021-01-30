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

long long fib(int n)
{
    long long f0 = 1, f1 = 2;
    if (n == 1)
    {
        return 1;
    }
    for (int i = 2; i < n; i++)
    {
        long long temp = f1;
        f1 += f0;
        f0 = temp;
    }
    return f1 % MOD;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(M + 1);
    a[0] = 0;
    for (int i = 1; i <= M; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < M; i++)
    {
        if (a[i + 1] - a[i] == 1)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    long long sum = 1;
    long long ptr = 1;
    long long temp;
    int cnt;
    for (int i = 1; i <= M; i++)
    {
        cnt = 1;
        while (ptr < a[i])
        {
            temp = fib(cnt);
            ptr++;
            cnt++;
        }
        sum = ((sum % MOD) * (temp % MOD)) % MOD;
        ptr++;
    }
    cnt = 1;
    while (ptr < N)
    {
        temp = fib(cnt);
        ptr++;
        cnt++;
    }
    sum = ((sum % MOD) * (temp % MOD)) % MOD;
    cout << sum << endl;
    return 0;
}