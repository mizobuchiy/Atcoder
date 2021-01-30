#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pint;
#define ALL(v) v.begin(), v.end()

bool compare_by_b(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

int main()
{
    ll N, M, b, c;
    cin >> N >> M;
    vector<ll> A(N + 1);
    vector<pint> BC(M);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> b >> c;
        BC[i] = {b, c};
    }
    sort(ALL(BC), compare_by_b);
    int cntM = M;
    int j = M;
    while (cntM > 0 && j > 0)
    {
        int cnt = BC[j].first;
        int ptr = 1;
        int k = ptr;
        while (cnt > 0 && k <= N)
        {
            if (A[k] < BC[j].second)
            {
                A[k] = BC[j].second;
                cnt--;
                ptr++;
            }
            k++;
        }
        cntM--;
        j--;
    }
    ll sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += A[i];
    }
    A.clear();
    BC.clear();
    cout << sum;
}
