#include <iostream>
using namespace std;
int main()
{
    int N, sum = 0, V[20], C[20];
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
        if (V[i] > C[i])
        {
            sum += V[i] - C[i];
        }
    }
    cout << sum << endl;
}