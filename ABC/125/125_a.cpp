#include <iostream>
using namespace std;
int main()
{
    int A, B, T, sum = 0;
    cin >> A >> B >> T;
    for (int i = A; i <= T; i += A)
    {
        sum += B;
    }
    cout << sum << endl;
}