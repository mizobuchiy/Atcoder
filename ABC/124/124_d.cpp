#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
    int N, K, l, r, cnt = 0, temp = 0, templ = 0, tempr = 0;
    string S, T;
    cin >> N >> K >> S;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == '0')
        {
            if (cnt == 0)
            {
                templ = i;
            }
            cnt++;
        }
        else
        {
            if (cnt > temp)
            {
                l = templ;
                r = i - 1;
                temp = max(cnt, temp);
            }
            cnt = 0;
        }
    }

    return 0;
}