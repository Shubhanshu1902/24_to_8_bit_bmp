#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

full_image open(const char *argv);
greyscale** RGBtoGrayscale(int height,int width, rgb** pic);
void get_ct(color_table ct[256]);
void write_file(const char* target_name, header h, info_header ih, greyscale** image, color_table ct[256]);
void convert_data(header *h,info_header *ih);