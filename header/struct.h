#pragma once
#pragma pack(1)

typedef unsigned char UC;

typedef struct
{
        char signature[2];                      //"BM"
        unsigned int file_size, reserved;       //File size:size of file ; Reserved:-Garbage value
        int data_offset;                        //offset  :-54
}header;                        //14 bytes

typedef struct{
        unsigned int size, width, height;       //size
        unsigned short planes, bpp;       //
        unsigned int compression, image_size, xppm, yppm, colors_used;
        unsigned int important_colors;
} info_header;    //DIB_Header      //40 bytes

typedef struct {
        unsigned char red, green, blue, reserved;
}color_table;

typedef struct {
        unsigned char r, g, b;
}rgb;

typedef struct {
        char unsigned value;
}greyscale;

typedef struct {
	greyscale** converted;
	color_table ct[256];
}imadata;

typedef struct 
{
        header bitmap;
        info_header dibheader;
        rgb** pic;
}full_image;