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
    vector<int> W(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> W[i];
    }
    int S1 = 0, S2 = 0;
    int ptr_left = 1, ptr_right = N;
    while (ptr_right >= ptr_left)
    {
        if (S1 < S2)
        {
            S1 += W[ptr_left];
            ptr_left++;
        }
        else
        {
            S2 += W[ptr_right];
            ptr_right--;
        }
    }
    cout << abs(S1 - S2) << endl;
}