#include <stdio.h>
#include <stdlib.h>
#include "include/file_reader.h"


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

void readimage(FILE *fp, int height, int width,struct image pic[height][width])                //to calculate rgb date
{  
    fread(pic, sizeof(struct image), height * width, fp);
}



int main()
{
    FILE *fp=fopen("try.bmp","rb");
    FILE *fnew=fopen("tt.bmp","wb");
    struct BIT_MapHeader new_bmap =bitmapheader(fp);
    printf("%c%c\n%d\n%d\n%d",new_bmap.name[0],new_bmap.name[1],new_bmap.size,new_bmap.garbage,new_bmap.offset);
    fwrite(&new_bmap,sizeof(struct BIT_MapHeader),1,fnew);
    struct DIB_Header dib_new=dibheader(fp);
    fwrite(&dib_new,sizeof(struct DIB_Header),1,fnew);
    fseek(fp,new_bmap.offset,SEEK_SET); 
    struct image pic[dib_new.height][dib_new.width];
    readimage(fp,dib_new.height,dib_new.width,pic);
    fwrite(pic,sizeof(struct pixelarray),dib_new.height*dib_new.width,fnew);
    fclose(fp);
    fclose(fnew);
    return 0;
}