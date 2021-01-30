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
    int N, K;
    string S;
    cin >> N >> K >> S;
    for (int i = 0; i < N; i++)
    {
        if ((i + 1) == K)
        {
            if (S[i] == 'A')
            {
                cout << 'a';
            }
            if (S[i] == 'B')
            {
                cout << 'b';
            }
            if (S[i] == 'C')
            {
                cout << 'c';
            }
        }
        else
        {
            cout << S[i];
        }
    }
}