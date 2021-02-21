#pragma once
#pragma pack(1)

typedef unsigned char UC;

typedef struct
{
        char signature[2];
        unsigned int file_size, reserved;
        int data_offset;
}header;

typedef struct{
        unsigned int size, width, height;
        unsigned short planes, bpp;
        unsigned int compression, image_size, xppm, yppm, colors_used;
        unsigned int important_colors;
} info_header;

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