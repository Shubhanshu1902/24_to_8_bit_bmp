#pragma once
#pragma pack(1)
struct header
{
        char signature[2];
        unsigned int file_size, reserved;
        int data_offset;
};

struct info_header
{
        unsigned int size, width, height;
        unsigned short planes, bpp;
        unsigned int compression, image_size, xppm, yppm, colors_used;
        unsigned int important_colors;
};


struct color_table
{
        unsigned char red, green, blue, reserved;
};

struct rgb
{
        unsigned char r, g, b;
};


void read_metadata(FILE *img_pointer, struct header *h, struct info_header *ih);
void read_imagedata(FILE *img_ptr, int height, int width, struct rgb[height][width], struct header *h);
void print(struct header h, struct info_header ih);
void read_file(const char* name, struct header *h, struct info_header *ih);

