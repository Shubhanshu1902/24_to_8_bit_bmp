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
    pic.rgb = (struct pixelarray**)malloc(height * sizeof(void*));
    pic.height = height;
    pic.width = width;
    for (int i =0; i<height; i++)
    {
        pic.rgb[i] = (struct pixelarray*)malloc(width * sizeof(struct pixelarray));
        fread(pic.rgb[i],sizeof(struct pixelarray),width,fp);
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

int main()
{
    FILE *fp=fopen("lena_color.bmp","rb");
    FILE *fnew=fopen("tt.bmp","wb");
    struct BIT_MapHeader new_bmap =bitmapheader(fp);
    printf("%c%c\n%d\n%d\n%d",new_bmap.name[0],new_bmap.name[1],new_bmap.size,new_bmap.garbage,new_bmap.offset);
//    printf("%d", );
    fwrite(&new_bmap,sizeof(struct BIT_MapHeader),1,fnew);
    struct DIB_Header dib_new=dibheader(fp);
    fwrite(&dib_new,sizeof(struct DIB_Header),1,fnew);
    fseek(fp,new_bmap.offset,SEEK_SET);
    struct image new=readimage(fp,dib_new.height,dib_new.width);
    fwrite(new.rgb,sizeof(struct pixelarray),dib_new.height*dib_new.width,fnew);
    freedata(new);
    fclose(fp);
    fclose(fnew);
    return 0;
}