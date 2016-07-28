#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    char outfile[1024];
    
    if (argc != 3)
    {
        printf("usage: %s file size\n", argv[0]);
        exit(1);
    }
    
    FILE *in = fopen(argv[1], "rb");
    if (!in)
    {
        printf("Unable to open file %s for read\n", argv[1]);
        exit(1);
    }
    strcpy(outfile, argv[1]);
    int len = strlen(outfile);
    int i = 0, done = 0;
    
    while (!done)
    {
        int size = atoi(argv[2]);
        outfile[len] = '.';
        outfile[len + 1] = '0' + i;
        outfile[len + 2] = 0;
        FILE *o = fopen(outfile, "wb");
        if (!o)
        {
            printf("Unable to open file %s for write\n", outfile);
            fclose(in);
            exit(1);
        }
        unsigned char byte;
        while (size > 0 && !done)
        {
            if (fread(&byte, 1, 1, in) > 0)
            {
                fwrite(&byte, 1, 1, o);
            }
            else
            {
                done = 1;
            }
            size--;
        }
        fclose(o);
        i++;
    }
    
    fclose(in);
    return 0;
}