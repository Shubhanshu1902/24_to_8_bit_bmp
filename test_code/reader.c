// This file will read the 8 bit map and analyze the data.
#include<stdio.h>
#include<stdlib.h>
#include"struct.h"

// This is a method to open the files and read the input bmp file
void read_imagedata(FILE *img_ptr, int height, int width, struct rgb **image, struct header *h)
{	
	fseek(img_ptr, h->data_offset, SEEK_SET);
	for(int i = 0; i < height; i++)
	{
		fread(image[i], sizeof(struct rgb), width, img_ptr);
	}
//	printf("%ld", ftell(img_ptr));
	fseek(img_ptr, 0, SEEK_SET);
}

void read_imagedata_arr(FILE *img_ptr, int height, int width, struct rgb image[height][width], struct header *h)
{	
	fseek(img_ptr, h->data_offset, SEEK_SET);
	fread(image, sizeof(struct rgb), height * width, img_ptr);
//	printf("%ld", ftell(img_ptr));
	fseek(img_ptr, 0, SEEK_SET);
}

// Reading the header
void read_metadata(FILE *img_ptr, struct header *h, struct info_header *ih)
{
	fseek(img_ptr, 0, SEEK_SET);
	fread(h, sizeof(struct header), 1, img_ptr);
	fread(ih, sizeof(struct info_header), 1, img_ptr);
	fseek(img_ptr, 0, SEEK_SET);
}

void print(struct header h, struct info_header ih)
{
	printf("Signatur = %c%c\nFile Size =  %u\nUseless Data =  %u %d\n", h.signature[0], h.signature[1], h.file_size, h.reserved, h.data_offset);
	printf("Size = %u\nWidth =  %u\nHeight = %u\nUseless Data = %u %u %u %u %u %u %u %u\n", ih.size, ih.width, ih.height, ih.planes, ih.bpp, ih.compression, ih.image_size, ih.xppm, ih.yppm, ih.colors_used, ih.important_colors);
}
struct rgb** read_file(const char* name, struct header *h, struct info_header *ih)
{
	// Opening the file
	FILE *img_ptr = NULL;
	img_ptr = fopen(name, "rb");
	// Initializing the required data structures to read the data
	// from the file.

	// Reading the information from the file to the data structures.
	read_metadata(img_ptr, h, ih);
	
	// trying using malloc 
	struct rgb *(*image) = (struct rgb **)malloc(ih->height * sizeof(void *));
	for(int i = 0; i < ih->height; i++)
	{
		image[i] = (struct rgb *)malloc(sizeof(struct rgb) * ih->width);
	}
	read_imagedata(img_ptr, ih->height, ih->width, image, h);
	print(*h, *ih);
	fclose(img_ptr);
	return image;
}


