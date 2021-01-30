#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll N, ans = 0;
    cin >> N;
    for (ll i = 1; i * i <= N; i++)
    {
        if (N % i != 0)
        {
            continue;
        }
        ll t = N / i;
        t--;
        if (i < t)
        {
            ans += t;
        }
    }
    cout << ans << endl;
    return 0;
}