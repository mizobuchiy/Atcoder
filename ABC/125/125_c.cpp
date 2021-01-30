#include <iostream>
#include <algorithm>
#define N 100005
using namespace std;

int n;
int a[N];
int l[N], r[N];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        l[i] = gcd(l[i - 1], a[i]);
    for (int i = n; i >= 1; i--)
        r[i] = gcd(r[i + 1], a[i]);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, gcd(l[i - 1], r[i + 1]));
    }
    cout << ans << endl;
    return 0;
}
