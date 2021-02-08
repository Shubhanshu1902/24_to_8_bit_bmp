#include <stdio.h>
#include <stdlib.h>

struct BIT_MapHeader
{
	char name[2];                  //Name 
	int size;
    int garbage;
	unsigned int offset;    
}__attribute__((packed));

struct DIB_Header
{
	unsigned int header_size;        //size of the header
    unsigned int width;              //width of image 
    unsigned int height;             //height of image
    unsigned short int color_planer;
    unsigned short int bitsperpixel;
    unsigned int compression;
    unsigned int image_size;
    unsigned int horizontal_resolution;
    unsigned int vertical_resolution;
    int no_of_colors;
    int no_of_imp_colors;
};

struct BIT_MapHeader bitmapheader(FILE *fp)
{
	struct BIT_MapHeader header;
	fread(&header,sizeof(struct BIT_MapHeader),1,fp);
	return header;
}

struct DIB_Header dibheader(FILE *fp)
{
	struct DIB_Header dib_header;
	fread(&dib_header,sizeof(struct DIB_Header),1,fp);
 	return dib_header;  
}

void open()
{
	FILE *fp=fopen("lena_color.bmp","rb");
	struct BIT_MapHeader header=bitmapheader(fp);
    printf("%ld\n",sizeof(struct BIT_MapHeader));
	printf("First two character:%c%c\n",header.name[0],header.name[1]);
    printf("Size:%u\n",header.size);
    printf("Image offset:%u\n",header.offset);
    struct DIB_Header dib_header=dibheader(fp);
    printf("Header size:%d\nwhidth:%d\nheight:%d\ncolor_planer:%d\nbitsperpixel:%d\ncompression:%d\nimage_size:%d\nhorizontal_resolution:%d\nvertical_resolution:%d\nno_of_colors:-%d\nno_of_imp_colors:%d\n",dib_header.header_size,
    	dib_header.width,dib_header.height,dib_header.color_planer,
    	dib_header.bitsperpixel,dib_header.compression,dib_header.image_size,dib_header.horizontal_resolution,
    	dib_header.vertical_resolution,dib_header.no_of_colors,dib_header.no_of_imp_colors);
}

int main()
{
    open();
}


