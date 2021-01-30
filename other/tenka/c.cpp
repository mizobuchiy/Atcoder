#include <iostream>
#include <string>
using namespace std;
int main()
{
    string S;
    int N, cnt = 0;
    cin >> N >> S;
    for (int i = 1; i < N; i += 2)
    {
        if (S[i - 1] == '#')
        {
            if (S[i] == '#')
            {
                if (S[i + 1] == '.')
                {
                    cnt++;
                }
            }
            else
            {
                if (S[i + 1] == '\0' && S[i] == '.')
                {
                    cnt++;
                }
                cnt++;
            }
        }
        else
        {
            if (S[i] == '#' && S[i + 1] == '.')
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}