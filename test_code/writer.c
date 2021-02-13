#include<stdio.h>
#include"writer.h"
void write_file(const char* target_name, struct header h, struct info_header ih, struct greyscale image[ih.height][ih.width], struct color_table ct[256])
{
	FILE *img_ptr = NULL;
	img_ptr = fopen(target_name, "wb");

	write_header(img_ptr, &h, &ih);
	write_imagedata(img_ptr, ih.height, ih.width, image, &h);
	write_ct(img_ptr, ct);
}

void write_imagedata(FILE *img_ptr, unsigned int height, unsigned int width, struct greyscale image[height][width], struct header *h)
{
        fseek(img_ptr, h->data_offset, SEEK_SET);
        fwrite(image, sizeof(struct greyscale), height * width, img_ptr);
//      printf("%ld", ftell(img_ptr));
        fseek(img_ptr, 0, SEEK_SET);
}

void write_header(FILE *img_ptr, struct header *h, struct info_header *ih)
{
	fseek(img_ptr, 0, SEEK_SET);
	fwrite(h, sizeof(struct header), 1, img_ptr);
	fwrite(ih, sizeof(struct info_header), 1, img_ptr);
	fseek(img_ptr, 0, SEEK_SET);
}

void write_ct(FILE *img_ptr, struct color_table ct[256])
{
	fseek(img_ptr, sizeof(struct header) + sizeof(struct info_header), SEEK_SET);
	fwrite(ct, sizeof(struct color_table), 256, img_ptr);
	fseek(img_ptr, 0, SEEK_SET);
}
