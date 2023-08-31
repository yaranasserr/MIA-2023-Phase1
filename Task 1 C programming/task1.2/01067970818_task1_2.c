#include <stdio.h>
#include <stdlib.h>

int main()

{
    int x;
    printf("Enter number : ");
    scanf("%d",&x);
    for (int i = 1; i <= x; i++) {
        printf("%d\n", i);
    }
    printf("Blast off to the moon!");
    return 0;
}
