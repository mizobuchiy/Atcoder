#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    bool f = true;
    for (int i = a - 1; i < c - 2; i++)
        if (s[i] == '#' && s[i + 1] == '#')
            f = false;
    for (int i = b - 1; i < d - 2; i++)
        if (s[i] == '#' && s[i + 1] == '#')
            f = false;
    if (d < c)
    {
        f = false;
        for (int i = b - 2; i < d - 1; i++)
            if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.')
                f = true;
    }
    cout << (f ? "Yes" : "No") << endl;
    return 0;
}
