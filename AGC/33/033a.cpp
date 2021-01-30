#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int H, W, cnt[1000][1000] = {0};
    char A[1000][1000];
    int i, j;

    cin >> H >> W;
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == '#')
            {
                cnt[i][j] = 1;
            }
        }
    }
    int ok = 1, ans = 0;
    while (ok > 0)
    {
        ok = 0;
        for (i = 0; i < H; i++)
        {
            for (j = 0; j < W; j++)
            {
                if (cnt[i][j] == 0)
                {
                    int a, b, c, d, temp = 0;
                    a = b = c = d = 0;
                    if (0 <= i - 1)
                        a = cnt[i - 1][j];
                    if (i + 1 <= H)
                        b = cnt[i + 1][j];
                    if (0 <= j - 1)
                        c = cnt[i][j - 1];
                    if (j + 1 <= W)
                        d = cnt[i][j + 1];
                    if (0 < a)
                        temp = a;
                    if (0 < b)
                        if (temp > 0)
                            temp = min(temp, b);
                        else
                            temp = 0;
                    if (0 < c)
                        if (temp > 0)
                            temp = min(temp, c);
                        else
                            temp = c;
                    if (0 < d)
                        if (0 < temp)
                            temp = min(temp, d);
                        else
                            temp = d;
                    if (0 < temp)
                        cnt[i][j] = temp + 1;
                    ok++;
                }
                ans = max(ans, cnt[i][j]);
            }
        }
    }
    cout << ans - 1 << endl;
}