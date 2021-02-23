#include<stdio.h>
#include "header/function.h"

void write_imagedata(FILE *img_ptr, unsigned int height, unsigned int width, greyscale** image, header* h)
{
    fseek(img_ptr, h->data_offset, SEEK_SET);
	for(int i = 0; i < height; i++)
	{
        	fwrite(image[i], sizeof(greyscale), width, img_ptr);
	}
//      printf("%ld", ftell(img_ptr));
    fseek(img_ptr, 0, SEEK_SET);
}

void write_header(FILE *img_ptr, header *h, info_header *ih)
{
	fseek(img_ptr, 0, SEEK_SET);
	fwrite(h, sizeof(header), 1, img_ptr);
	fwrite(ih, sizeof(info_header), 1, img_ptr);
	fseek(img_ptr, 0, SEEK_SET);
}

void write_ct(FILE *img_ptr, color_table *ct)
{
	fseek(img_ptr, sizeof(header) + sizeof(info_header), SEEK_SET);
	fwrite(ct, sizeof(color_table), 256, img_ptr);
	fseek(img_ptr, 0, SEEK_SET);
}

void write_file(const char* target_name, header h, info_header ih, greyscale** image, color_table ct[256])
{
	FILE *img_ptr = NULL;
	img_ptr = fopen(target_name, "wb");
	write_header(img_ptr, &h, &ih);
	write_imagedata(img_ptr, ih.height, ih.width, image, &h);
	write_ct(img_ptr, ct);
	fclose(img_ptr);
}