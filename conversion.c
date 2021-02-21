#include<stdio.h>
#include<stdlib.h>
#include "header/function.h"

void convert_data(header *h,info_header *ih)
{
    unsigned int size = sizeof(header) + sizeof(info_header) + 256 * sizeof(color_table) + ih->width * ih->height * sizeof(greyscale);
	unsigned int data_offset = size - (ih->width * ih->height * sizeof(greyscale));
	h->file_size = size;
	h->data_offset = data_offset;
    ih->bpp = 8;
	ih->colors_used = 256;
}

unsigned char convert(rgb pic)
{
        return(pic.r*0.299 + pic.g*0.587 + pic.b*0.114);       //each component of the pixel is converted into a grayscale value
}

greyscale** RGBtoGrayscale(int height,int width, rgb** pic)
{
    greyscale** image = (greyscale **)malloc(height * sizeof(void *));
    for(int i = 0; i < height; i++)
    {
        image[i] = (greyscale *)malloc(width * sizeof(greyscale));
    }
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            image[i][j].value = convert(pic[i][j]);
    return image;     
}

void get_ct(color_table ct[256])
{
    for(int i = 0; i < 256; i++)
    {
        ct[i].red = i;
        ct[i].blue = i;
        ct[i].green = i;
        ct[i].reserved = 0;
    }
}

