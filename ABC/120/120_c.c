#include <stdio.h>
#include <string.h>
#define N 100000
char s[N];
int main(void)
{
    int i, cnt0 = 0, cnt1 = 0;
    scanf("%s", s);
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '0')
            cnt0++;
    }
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '1')
            cnt1++;
    }
    printf("%d\n", cnt0 < cnt1 ? cnt0 * 2 : cnt1 * 2);
}