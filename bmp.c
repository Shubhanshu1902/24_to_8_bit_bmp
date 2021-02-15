#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"


struct BIT_MapHeader bitmapheader(FILE *fp)                          //to read bitmapheader of bmp
{
    struct BIT_MapHeader header;
    fread(&header, sizeof(struct BIT_MapHeader), 1, fp);
    return header;
}

struct DIB_Header dibheader(FILE *fp)                                //to read dibheader of bmp
{
    struct DIB_Header dib_header;
    fread(&dib_header, sizeof(struct DIB_Header), 1, fp);
    return dib_header;
}

struct image readimage(FILE *fp, int height, int width)                //to calculate rgb date
{
    struct image pic;
    pic.rgb = (struct pixelarray**)malloc(height * sizeof(void *));
    pic.height = height;
    pic.width = width;
    for (int i = height - 1; i>= 0; i--)
    {
        pic.rgb[i] = (struct pixelarray*)malloc(width * sizeof(struct pixelarray));
        fread(pic.rgb[i],width,sizeof(struct pixelarray),fp);
    }
    return pic;
}

void freedata(struct image pic)                                         //to free the excess data
{
    for (int i = pic.height - 1; i= 0; i--)
    {
        free(pic.rgb[i]);
    }
    free(pic.rgb);
}

void open(const char *argv)
{
    FILE *fp=fopen(argv,"rb");
}