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
    int S;
    cin >> S;
    if (0 < S / 100 && S / 100 < 13)
    {
        if (0 < S % 100 && S % 100 < 13)
        {
            cout << "AMBIGUOUS";
        }
        else
        {
            cout << "MMYY";
        }
    }
    else if (0 < S % 100 && S % 100 < 13)
    {
        cout << "YYMM";
    }
    else
    {
        cout << "NA";
    }
}