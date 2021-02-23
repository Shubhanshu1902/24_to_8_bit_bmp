#include <stdio.h>
#include <stdlib.h>
#include "header/function.h"

//to read bitmapheader of bmp
header bitmapheader(FILE *fp)                           
{
    header header1;
    fread(&header1, sizeof(header), 1, fp);             // something is wrong
    return header1;
}

//to read dibheader of bmp
info_header dibheader(FILE *fp){                               
    info_header dib_header;
    fread(&dib_header, sizeof(info_header), 1, fp);
    return dib_header;
}

//to read the rgb data and store it in a buffer
rgb** readimage(FILE *fp,unsigned int height, unsigned int width, int offset)                
{  
    fseek(fp,offset,SEEK_SET);
    rgb** pic;
    //the address of each row of the image is allocated space in memory
    pic = (rgb**)malloc(height * sizeof(void *));
    for(int i = 0; i < height; i++)
    {
      /*now each row address is allocated the address of the actual rgb data of the image per pixel per row
        the number of pixels per row is the width size and each pixel has rgb data defined as a struct*/
        pic[i] = (rgb*)malloc(width * sizeof(rgb));
        //read the pixel data
        fread(pic[i], sizeof(rgb), width, fp);
    }
    //'pic' has the rgb values of every pixel in the bmp file
    return pic;
}

full_image open(const char *argv)
{
    //'argv' gives us the file to be opened
    FILE *fp = fopen(argv,"rb");
    if(!fp)
    {
        printf("Wrong file name\n");
        exit(0);
    }
    //FILE *fnew = fopen("tt.bmp","wb");
    //access the struct 'full_image' using 'image_data'
    full_image image_data;
    image_data.bitmap = bitmapheader(fp); // problem
    //fwrite(&image_data.bitmap,sizeof(header),1,fnew);
    image_data.dibheader=dibheader(fp);
    //fwrite(&image_data.dibheader,sizeof(info_header),1,fnew);
    rgb** pic = readimage(fp,image_data.dibheader.height,image_data.dibheader.width,image_data.bitmap.data_offset);
    image_data.pic = pic;
    //for(int i = 0; i <image_data.dibheader.height; i++ ){
      //  fwrite(image_data.pic[i], sizeof(rgb), image_data.dibheader.width, fnew);
    //}
    //fclose(fnew);
    fclose(fp);
    return image_data;
}
