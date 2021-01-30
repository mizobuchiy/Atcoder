#include <stdio.h>
int a[100000], b[100000];
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main(void)
{
    int i, j, min, key, cnt = 0, cntb;
    long long sum = 0;
    int N, M;
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (i = 0; i < N; i++)
    {
        min = a[i];
        key = i;
        for (j = i; j < N; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                swap(&a[key], &a[j]);
                swap(&b[key], &b[j]);
                key = j;
            }
        }
    }
    for (i = 0; i < N; i++)
    {
        if (cnt + b[i] < M)
        {
            sum += a[i] * b[i];
            cnt += b[i];
        }
        else
        {
            cntb = 1;
            while (cnt < M)
            {
                sum += a[i];
                cnt++;
                cntb++;
                if (cntb > b[i])
                {
                    break;
                }
            }
        }
    }
    printf("%lld\n", sum);
    return 0;
}