#include"reader.h"
#pragma once

struct greyscale
{
	char unsigned value;
};

void write_imagedata(FILE *img_ptr, unsigned int height, unsigned int width, struct greyscale image[height][width], struct header *h);
void write_header(FILE *img_ptr, struct header *h, struct info_header *ih);
void write_file(const char* target_name, struct header h, struct info_header ih, struct greyscale image[ih.height][ih.width], struct color_table ct[256]);
void write_ct(FILE *img_ptr, struct color_table ct[256]);
