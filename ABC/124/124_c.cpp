#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
    int N, cnta = 0, cntb = 0;
    string S;
    cin >> S;
    N = S.length();
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            if (S[i] == '1')
            {
                cnta++;
            }
        }
        else
        {
            if (S[i] == '0')
            {
                cnta++;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 1)
        {
            if (S[i] == '1')
            {
                cntb++;
            }
        }
        else
        {
            if (S[i] == '0')
            {
                cntb++;
            }
        }
    }
    cout << min(cnta, cntb) << endl;
    return 0;
}