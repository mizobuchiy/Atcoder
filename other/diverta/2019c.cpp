#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int main()
{
    int N, a, b, ba, cnt;
    a = b = ba = cnt = 0;
    string s;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        int len = (int)s.size();
        for (int j = 0; j + 1 < len; j++)
        {
            if (s[j] == 'A' && s[j + 1] == 'B')
            {
                cnt++;
            }
        }
        if (s[0] == 'B')
        {
            b++;
        }
        if (s[len - 1] == 'A')
        {
            a++;
        }
        if (s[0] == 'B' && s[len - 1] == 'A')
        {
            ba++;
        }
    }
    cnt += min(a, b);
    if (a == ba && b == ba && b > 0)
    {
        cnt--;
    }
    cout << cnt << endl;
    return 0;
}
