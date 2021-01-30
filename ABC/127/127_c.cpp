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
    vector<int> L(M + 1);
    vector<int> R(M + 1);
    for (int i = 1; i <= M; i++)
    {
        cin >> L[i] >> R[i];
    }
    int maxL = L[1], minR = R[1];
    for (int i = 1; i <= M; i++)
    {
        maxL = max(maxL, L[i]);
        minR = min(minR, R[i]);
    }
    if (minR - maxL < 0)
    {
        cout << 0;
    }
    else
    {
        cout << minR - maxL + 1 << endl;
    }
}
