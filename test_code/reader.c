// This file will read the 8 bit map and analyze the data.
#include<stdio.h>
#include"writer.h"
#include "converter.h"

// This is a method to open the files and read the input bmp file
void read_file(const char* name, struct header *h, struct info_header *ih)
{
	// Opening the file
	FILE *img_ptr = NULL;
	img_ptr = fopen(name, "rb");
	// Initializing the required data structures to read the data
	// from the file.

	// Reading the information from the file to the data structures.
	read_metadata(img_ptr, h, ih);
	struct rgb image[ih->height][ih->width];
	read_imagedata(img_ptr, ih->height, ih->width, image, h);
	struct greyscale converted[ih->height][ih->width];
	struct color_table ct[256];
	print(*h, *ih);
	convert(h, ih, image, converted, ct);
	write_file("lena_bw.bmp", *h, *ih, converted, ct);
	print(*h, *ih);
	//fread(ct, sizeof(struct color_table), 256, file_ptr);
	
	// Preparing to write the file in a txt format to analize the data.
	// FILE *write_ptr = NULL;
	// write_ptr = fopen("data.txt", "w");

	// FILE *img_ptr = NULL;
	// img_ptr = fopen("lena24.bmp", "wb");
	
	// fwrite(&h, sizeof(struct header), 1, img_ptr);
	// fwrite(&ih, sizeof(struct info_header),1, img_ptr);
	// Reading the image data from the bmp file.
	// struct rgb image[ih.height][ih.width];
	// fread(image, sizeof(struct rgb), 512*512, file_ptr);

	// printf("%ld", ftell(file_ptr));
	// fclose(file_ptr);
	/* for(int i = 0; i < ih.height; i++)
	{
		for(int j = 0; j < ih.width; j++){
			char buff[25];
			snprintf(buff, 25, "p[%d][%d] %u %u %u ", i, j, image[i][j].r, image[i][j].g, image[i][j].b);
			fprintf(write_ptr,"%s" ,buff);
			fwrite(&image[i][j], sizeof(struct rgb), 1, img_ptr);
		}
		fprintf(write_ptr, "\n");
	}
	*/
	// printing the image header and other data
	fclose(img_ptr);
}

void read_imagedata(FILE *img_ptr, int height, int width, struct rgb image[height][width], struct header *h)
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
