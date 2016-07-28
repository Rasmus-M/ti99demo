#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    unsigned char b;
    int c = 0;
    if (argc != 2)
    {
        printf("usgae: %s file\n", argv[0]);
        exit(1);
    }
    FILE *f = fopen(argv[1], "rb");
    while (fread(&b, 1, 1, f))
    {
        // Prepend the first byte with the BYTE directive
        if (c % 16 == 0)
        {
            printf("       BYTE >%02X", b);
        }
        else
        {
            printf(",>%02X", b);
        }
        // Print a newline after 15 bytes have been written out
        if (c % 16 == 15)
        {
            printf("\n");
        }
        c++;
    }
    // If we didn't just print a newline, then print one
    if (c % 16 != 15)
    {
        printf("\n");
    }
    fclose(f);
    return 0;
}