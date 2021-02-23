#include <stdio.h>
#include <stdlib.h>
#include "header/function.h"


header bitmapheader(FILE *fp)                           //to read bitmapheader of bmp
{
    header header1;
    fread(&header1, sizeof(header), 1, fp);           
    return header1;
}

info_header dibheader(FILE *fp){                               //to read dibheader of bmp
    info_header dib_header;
    fread(&dib_header, sizeof(info_header), 1, fp);
    return dib_header;
}

rgb** readimage(FILE *fp,unsigned int height, unsigned int width, int offset)                //to calculate rgb data
{  
    fseek(fp,offset,SEEK_SET);                                      //to go to the pixel data part 
    rgb** pic;                                                  // defining pic as 2d rgb array
//To allocate the data to pic array and reading the data accordingly
    pic = (rgb**)malloc(height * sizeof(void *));                 
    for(int i = 0; i < height; i++)
    {
        pic[i] = (rgb*)malloc(width * sizeof(rgb));
        fread(pic[i], sizeof(rgb), width, fp);
    }
    return pic;
}

full_image open(const char *argv)
{
    FILE *fp = fopen(argv,"rb");
//if file is not present it will give error
    if(!fp)
    {
        printf("Wrong file name\n");
        exit(0);
    }
//storing whole image data in one struct
    full_image image_data;
    image_data.bitmap = bitmapheader(fp); 
    image_data.dibheader=dibheader(fp);
    rgb** pic = readimage(fp,image_data.dibheader.height,image_data.dibheader.width,image_data.bitmap.data_offset);
    image_data.pic = pic;
    fclose(fp);
    return image_data;
}
