#include <stdio.h>

int main(int argc, char const *argv[])
{
    char n[3];
    n[3] = 0;
    int header[3];
    FILE *bmp_24 = NULL;

    bmp_24 = fopen("bmp_24.bmp", "rb");
    fread(&n, 2, 1, bmp_24);
    fread(&header, sizeof(header), 1, bmp_24);
    printf("Header:");
    printf("%s\n", n);
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", header[i]);
    }

    return 0;
}
