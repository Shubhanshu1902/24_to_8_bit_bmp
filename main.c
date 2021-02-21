#include <stdio.h>
#include "header/function.h"
void free_data(full_image data);
int main(int argc, char* argv[])
{
	if(argc == 3){
		color_table ct[256];
		full_image data = open(argv[1]);
		greyscale** image = RGBtoGrayscale(data.dibheader.height, data.dibheader.width, data.pic);
		get_ct(ct);
		convert_data(&data.bitmap,&data.dibheader);
		write_file(argv[2], data.bitmap, data.dibheader, image, ct);
		free_data(data);
	} else
	{
		printf("Give 2 parameters");
	}
}

void free_data(full_image data)
{
	free(data.pic);
}