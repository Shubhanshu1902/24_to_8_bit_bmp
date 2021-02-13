#include<stdio.h>
#include"writer.h"
#include"converter.h"

void convert(struct header *h, struct info_header *ih, struct rgb image[ih->height][ih->width], struct greyscale converted[ih->height][ih->width], struct color_table ct[256])
{
	convert_imagedata(ih->height, ih->width, image, converted);
	create_color_table(ct);
	unsigned int size = sizeof(struct header) + sizeof(struct info_header) + 256 * sizeof(struct color_table) + ih->width * ih->height * sizeof(struct greyscale);
	unsigned int data_offset = size - (ih->width * ih->height * sizeof(struct greyscale));
	convert_header(h, size, data_offset);
	convert_infoheader(ih);
}

// Y = 0.299R + 0.587G + 0.114G
void convert_header(struct header *h, unsigned int size, unsigned int data_offset)
{
	h->file_size = size;
	h->data_offset = data_offset;
}

void convert_infoheader(struct info_header *ih)
{
	ih->bpp = 8;
	ih->colors_used = 256;
}

void create_color_table(struct color_table ct[256])
{
	for(int i = 0; i < 255; i++)
	{
		ct[i].red = i;
		ct[i].blue = i;
		ct[i].green = i;
		ct[i].reserved = 0;
	}
}

void convert_imagedata(unsigned int height, unsigned int width, struct rgb image[height][width], struct greyscale converted[height][width])
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			converted[i][j].value = 0.299 * image[i][j].r + 0.587 * image[i][j].g + 0.114 * image[i][j].b;
		}
	}
}
