#include<stdio.h>
#include<stdlib.h>
#include "header/function.h"

void convert_data(header *h,info_header *ih)
{
    unsigned int size = sizeof(header) + sizeof(info_header) + 256 * sizeof(color_table) + ih->width * ih->height * sizeof(greyscale);
	unsigned int data_offset = size - (ih->width * ih->height * sizeof(greyscale));
	h->file_size = size;                                     //changing file_size to contain the size of 8bit bmp file 
	h->data_offset = data_offset;                            //new data_offset for 8bit bmp file
    ih->bpp = 8;
	ih->colors_used = 256;
}

unsigned char convert(rgb pic)
{
        return(pic.r*0.299  + pic.g*0.587 + pic.b*0.114);        //each component of the pixel is converted into a grayscale value
}

greyscale** RGBtoGrayscale(int height,int width, rgb** pic)
{
    greyscale** image = (greyscale **)malloc(height * sizeof(void *));       //image is a 2D array with its each element of type struct greyscale
    for(int i = 0; i < height; i++)
    {
        image[i] = (greyscale *)malloc(width * sizeof(greyscale));           //allocating memory for each row of 2D array image
    }
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            image[i][j].value = convert(pic[i][j]);               //calling convert function to change data of each pixel
    return image;     
}

void get_ct(color_table ct[256])                                  //ct is a 1D array with its each element of the type struct color_table
{
    for(int i = 0; i < 256; i++)
    {
        ct[i].red = i;                                           //giving required values to red,green,blue of each struct
        ct[i].blue = i;                                          //and reserved is set to zero for all elements of ct 
        ct[i].green = i;
        ct[i].reserved = 0;
    }
}

