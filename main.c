#include <stdio.h>
#include "header/function.h" //including the header file which contains the functions required for i)reading ii)converting iii)writing

void free_data(full_image data); //freeing any previous data stored in the memory

int main(int argc, char *argv[]) //taking arguments( i)filename {which is to be converted} ii)filename {the name of the converted file} ) from the command line and keeping a count of them
{
	if (argc == 3)
	{ //case where both the file names are given i.e both the input file name and the destination file name

		color_table ct[256];																	   //defining color table
		full_image data = open(argv[1]);														   //opening and reading the file which is to be converted
		greyscale **image = RGBtoGrayscale(data.dibheader.height, data.dibheader.width, data.pic); //extracting the pixel data from the given file and passing it for further conversions
		get_ct(ct);																				   //creating a color table of 256 bits
		convert_data(&data.bitmap, &data.dibheader);											   //converting data of the header and dibheader of 24-bit format to 8-bit format
		write_file(argv[2], data.bitmap, data.dibheader, image, ct);							   //file which writes into the duplicate file created whose name is as given by the user
		free_data(data);																		   //freeing data so that the memory is free for the next conversion
	}
	else if (argc == 2)
	{ //case when only the input file name is given
		color_table ct[256];
		full_image data = open(argv[1]);
		greyscale **image = RGBtoGrayscale(data.dibheader.height, data.dibheader.width, data.pic);
		get_ct(ct);
		convert_data(&data.bitmap, &data.dibheader);
		write_file("result.bmp", data.bitmap, data.dibheader, image, ct); //we are giving a default name for the converted file as the user didnt input any file
		free_data(data);
	}
	else //case when no file name is given
	{
		printf("Give 2 parameters");
	}
}

void free_data(full_image data) //function defined to free data
{
	free(data.pic);
}
