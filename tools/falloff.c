#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, d;
    
    for (i = 0; i < 64; i++)
    {
        printf("        BYTE ");
        for (j = 0; j < 16; j++)
        {
            d = i * 16 + j;
            
            if (d > 0)
                k = 128 / d;
            else
                k = 7;
            
            if (d > 64) k = 0;
            
            if (k >= 0)
                printf("%d", k > 7 ? 7 : k);
            else
                printf("7");
            
            if (j != 15)
                printf(", ");
        }
        printf("\n");
    }
}