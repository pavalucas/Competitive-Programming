#include <stdio.h>

int main(void)
{
    int kg;

    scanf("%d", &kg);

    if(kg % 2 == 0 && kg != 2)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}