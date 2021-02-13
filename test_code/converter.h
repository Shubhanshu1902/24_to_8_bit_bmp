#pragma once
void convert(struct header *h, struct info_header *ih, struct rgb image[ih->height][ih->width], struct greyscale converted[ih->height][ih->width], struct color_table ct[256]);

void convert_header(struct header *h, unsigned int size, unsigned int data_offset);

void convert_infoheader(struct info_header *ih);

void create_color_table(struct color_table ct[256]);

void convert_imagedata(unsigned int height, unsigned int width, struct rgb image[height][width], struct greyscale converted[height][width]);

