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
#define Nmax 100005

int main()
{
    int N, K;
    cin >> N >> K;
    int temp;
    double a[Nmax];
    for (int i = 1; i <= N; i++)
    {
        temp = i;
        a[i] = (double)1 / N;
        while (temp < K)
        {
            a[i] *= 1 / 2.0;
            temp *= 2;
        }
    }
    double ans;
    for (int i = 1; i <= N; i++)
    {
        ans += a[i];
    }
    //ans /= N;
    printf("%.12lf\n", ans);
}