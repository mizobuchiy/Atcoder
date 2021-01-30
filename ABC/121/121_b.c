#include <stdio.h>
int main(void)
{
    int N, M, C;
    int b[20], a[20][20];
    int i, j, cnt = 0, sum;
    scanf("%d%d%d", &N, &M, &C);
    for (i = 0; i < M; i++)
    {
        scanf("%d", &b[i]);
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < N; i++)
    {
        sum = C;
        for (j = 0; j < M; j++)
        {
            sum += a[i][j] * b[j];
        }
        if (sum > 0)
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}