#include <stdio.h>
#include <stdlib.h>
#include "header/function.h"

//to read bitmapheader of bmp
header bitmapheader(FILE *fp)
{
    header header1;
    fread(&header1, sizeof(header), 1, fp);
    return header1;
}

//to read dibheader of bmp
info_header dibheader(FILE *fp)
{
    info_header dib_header;
    fread(&dib_header, sizeof(info_header), 1, fp);
    return dib_header;
}

rgb **readimage(FILE *fp, unsigned int height, unsigned int width, int offset)
{
    fseek(fp, offset, SEEK_SET);
    rgb **pic;
    //the address of each row of the image is allocated space in memory
    pic = (rgb **)malloc(height * sizeof(void *));

    for (int i = 0; i < height; i++)
    {
        /*now each row address is allocated the address of the actual rgb data of the image per pixel per row
        the number of pixels per row is the width size and each pixel has rgb data defined as a struct*/
        pic[i] = (rgb *)malloc(width * sizeof(rgb));
        //read the pixel data
        fread(pic[i], sizeof(rgb), width, fp);
    }
    //'pic' has the rgb values of every pixel in the bmp file
    return pic;
}

full_image open(const char *argv)
{
    //'argv' gives us the file to be opened
    FILE *fp = fopen(argv, "rb");
    //if file is not present it will give error
    if (!fp)
    {
        printf("Wrong file name\n");
        exit(0);
    }
    //storing whole image data in one struct
    full_image image_data;
    image_data.bitmap = bitmapheader(fp);
    image_data.dibheader = dibheader(fp);
    rgb **pic = readimage(fp, image_data.dibheader.height, image_data.dibheader.width, image_data.bitmap.data_offset);
    image_data.pic = pic;
    fclose(fp);
    return image_data;
}
