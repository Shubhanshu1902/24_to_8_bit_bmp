#include <stdio.h>
#include <stdlib.h>

struct BIT_MapHeader
{
    char name[2]; //Name
    unsigned int size;
    unsigned int garbage;
    unsigned int offset;
} __attribute__((packed));

struct DIB_Header
{
    unsigned int header_size; //size of the header
    unsigned int width;       //width of image
    unsigned int height;      //height of image
    unsigned short int color_planer; //color planar of 
    unsigned short int bitsperpixel;
    unsigned int compression;
    unsigned int image_size;
    unsigned int horizontal_resolution;
    unsigned int vertical_resolution;
    unsigned int no_of_colors;
    unsigned int no_of_imp_colors;
} __attribute__((packed));

struct pixelarray
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
    unsigned char reserved;
};

struct image
{
    //unsigned int height;
    //unsigned int width;
    unsigned char r,g,b;
};
void readimage(FILE *fp, int height, int width,struct image pic[height][width]);
//void freedata(struct image pic,int height,int width);
struct BIT_MapHeader bitmapheader(FILE *fp);
struct DIB_Header dibheader(FILE *fp);
//void read();