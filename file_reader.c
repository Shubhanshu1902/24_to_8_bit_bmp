#include <stdio.h>
#include <stdlib.h>
#include "header/function.h"


header bitmapheader(FILE *fp)                          //to read bitmapheader of bmp
{
    header header1;
    fread(&header1, sizeof(header), 1, fp); // something is wrong
    return header1;
}

info_header dibheader(FILE *fp){                               //to read dibheader of bmp
    info_header dib_header;
    fread(&dib_header, sizeof(info_header), 1, fp);
    return dib_header;
}

rgb** readimage(FILE *fp,unsigned int height, unsigned int width, int offset)                //to calculate rgb date
{  
    fseek(fp,offset,SEEK_SET);
    rgb** pic;
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
    FILE *fnew = fopen("tt.bmp","wb");
    full_image image_data;
    image_data.bitmap = bitmapheader(fp); // problem
    fwrite(&image_data.bitmap,sizeof(header),1,fnew);
    image_data.dibheader=dibheader(fp);
    fwrite(&image_data.dibheader,sizeof(info_header),1,fnew);
    rgb** pic = readimage(fp,image_data.dibheader.height,image_data.dibheader.width,image_data.bitmap.data_offset);
    image_data.pic = pic;
    for(int i = 0; i <image_data.dibheader.height; i++ ){
        fwrite(image_data.pic[i], sizeof(rgb), image_data.dibheader.width, fnew);
    }
    fclose(fnew);
    fclose(fp);
    return image_data;
}
