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
#define MAX 10001

int main()
{
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    int min_p = MAX, min_m = -MAX;
    for (int i = 1; i <= N; ++i)
    {
        if (min_p > A[i])
        {
            min_p = A[i];
        }
        if (min_m < -A[i])
        {
            min_m = -A[i];
        }
    }
}