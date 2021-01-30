#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, temp, cnt = 0;
    vector<int> A;
    vector<int> B;
    long long int sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        A.push_back(temp);
        if (temp < 0)
            cnt++;
    }
}