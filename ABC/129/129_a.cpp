#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << min({A + B, B + C, C + A}) << endl;
}