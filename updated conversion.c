#include<stdio.h>
#include<stdlib.h>
#include "function.h"


// struct pixel_data {
//         UC blue;
//         UC green;           
//         UC red;
//     };
// struct Image{
//         int height;
//         int width;
//         struct pixel_data** arr;      //arr is a 2D array where its each element is of type struct pixel_data
//     };
// struct new_pixel_data{
//       UC grey;
//     };
// int main()
// {
   
//     struct Image pic=readImage(fp,height,width);
//     RGBtograyscale(pic);  
//     for(i=0;i<pic.height;i++)
//     {
//         for(j=0;j<pic.width;j++) 
//             arr2[i][j].grey=grayscale(pic.arr[i][j])
//     }
//     return 0;
// }
// struct Image readImage(FILE *fp, int height, int width){
//       int i;
//       struct Image pic;
//       //pic.arr = (struct pixel_data**) malloc(height*sizeof(void*));
//       pic.height = height;
//       pic.width = width;

//       for(i=height-1;i>=0;i--){
//             //pic.arr[i] = (struct pixel_data*) malloc(width*sizeof(struct pixel_data));
//             fread(pic.arr[i],pic.width,sizeof(struct pixel_data),fp);
//         }
//       return pic;
//         }

unsigned char convert(rgb pic)
{
        return(pic.r*0.299 + pic.g*0.587 + pic.b*0.114);       //each component of the pixel is converted into a grayscale value
}

greyscale** RGBtoGrayscale(int height,int width, rgb** pic)
{
    greyscale** image = (greyscale **)malloc(height * (void *));
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

