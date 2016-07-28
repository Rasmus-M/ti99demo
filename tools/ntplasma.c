#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y;
    for (y = 0; y < 64; y++)
    {
        printf("       BYTE ");
        for (x = 0; x < 32; x++)
        {
            if (x != 0)
                printf(",");
                
            unsigned char color = (unsigned char)
            (
                128.0 + (128.0 * sin(x / 20.0))
              + 128.0 + (128.0 * sin(y / 10.0))
              + 128.0 + (128.0 * sin((x + y) / 20.0))
              + 128.0 + (128.0 * sin(sqrt((double)(x * x + y * y)) / 10.0))
            ) / 4;
            printf(" >%02X", color);
        }
        printf("\n");
    }
}