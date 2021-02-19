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

struct greyscale
{
        char unsigned value;
};

struct image_data
{
	struct greyscale** converted;
	struct color_table* ct;
};
