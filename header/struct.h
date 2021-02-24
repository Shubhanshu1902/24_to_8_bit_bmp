#pragma once
//done to ensure that the signature[2] is read as 2 bytes and not 4 bytes
#pragma pack(1)

typedef unsigned char UC;

typedef struct
{ //"BM"
	char signature[2];
	//file size : size of file ; reserved : Garbage value
	unsigned int file_size, reserved;
	//data_offset : signifies the start of image data after 'data_offset' bytes
	int data_offset;
} header; //Total size of Header struct : 14 bytes

typedef struct
{
	//size : size of header(40 bytes)
	unsigned int size, width, height;
	//planes=1, (bits per pixel) here it is 24
	unsigned short planes, bpp;
	//compression=0 for bmp files, set to 0 if compression=0, horizontal and vertical resolution(pixels per metre), 16M colors for 24bit bmp
	unsigned int compression, image_size, xppm, yppm, colors_used;
	//there's no priority assigned to any color hence its a 0
	unsigned int important_colors;
} info_header; //Total size of InfoHeader struct : 40 bytes

typedef struct
{
	//info about the rgb values per pixel
	unsigned char red, green, blue, reserved;
} color_table; //Total size of ColorTable struct : 4 bytes

typedef struct
{
	//rgb values of each pixel
	unsigned char r, g, b;
} rgb;

typedef struct
{
	//grayscale value of each pixel
	char unsigned value;
} greyscale;

typedef struct
{
	//'converted' is a 2d array that stores grayscale values of each pixel
	greyscale **converted;
	//palette of 256 shades of gray in 8bit bmp
	color_table ct[256];
} imadata;

typedef struct
{
	header bitmap;
	info_header dibheader;
	//'pic' is a 2d array that stores rgb values of each pixel
	rgb **pic;
} full_image; //user defined struct that consists of all the bmp headers
