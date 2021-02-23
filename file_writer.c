#include <stdio.h>
#include "header/function.h"

// Writes the image pixel data into the file.
void write_imagedata(FILE *img_ptr, unsigned int height, unsigned int width, greyscale **image, header *h)
{
	// Skipping to the offset from where the image should start. Taken from header.
	fseek(img_ptr, h->data_offset, SEEK_SET);
	// Running through loop to write the data into each row of the 2d array.
	for (int i = 0; i < height; i++)
	{
		// Writes the data using fwrite function. Each row has size of struct greyscale which has 1 byte of
		// data which includes the value of pixel.
		fwrite(image[i], sizeof(greyscale), width, img_ptr);
	}
	// Seeks to the starting to reset the cursor of the file.
	fseek(img_ptr, 0, SEEK_SET);
}

// Writes the header and info header of the file into it.
void write_header(FILE *img_ptr, header *h, info_header *ih)
{
	// First we seek to the start of the image from where we add header which is followed by info header
	// as these contain critical information.
	fseek(img_ptr, 0, SEEK_SET);

	// Writing the header and info header data to the file of given filepointer.
	fwrite(h, sizeof(header), 1, img_ptr);
	fwrite(ih, sizeof(info_header), 1, img_ptr);

	// Seeks back to the starts of the image to reset the cursor of the file.
	fseek(img_ptr, 0, SEEK_SET);
}

void write_ct(FILE *img_ptr, color_table *ct)
{
	// Writes the color table of the file.
	// Color tables tells the value of 0 to 255 corresponding them to a rgb value. They are added
	// after header and info header part.
	fseek(img_ptr, sizeof(header) + sizeof(info_header), SEEK_SET);
	fwrite(ct, sizeof(color_table), 256, img_ptr);

	// Seeks back to the starts of the image to reset the cursor of the file.
	fseek(img_ptr, 0, SEEK_SET);
}

void write_file(const char *target_name, header h, info_header ih, greyscale **image, color_table ct[256])
{
	FILE *img_ptr = NULL;				// Initializing the image pointer
	img_ptr = fopen(target_name, "wb"); // Creating or overwriting the file in which data is to be written.
	write_header(img_ptr, &h, &ih);		// Calling funtions to write data
	write_imagedata(img_ptr, ih.height, ih.width, image, &h);
	write_ct(img_ptr, ct);
	fclose(img_ptr); // Closing the file after writing all the data.
}