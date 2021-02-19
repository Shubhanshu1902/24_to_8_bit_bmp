#include <stdio.h>
#include "struct.h"
#include <stdlib.h>

struct rgb** read_file(const char* name, struct header *h, struct info_header *ih);
struct image_data convert(struct header *h, struct info_header *ih, struct rgb **image);
void write_file(const char* target_name, struct header h, struct info_header ih, struct greyscale **image, struct color_table *ct);
void freedata(struct rgb **image, struct image_data id, unsigned int height);
int main(int argc, char* argv[])
{
	if(argc == 3)
	{
		struct header h;
		struct info_header ih;
		struct rgb** image = read_file(argv[1], &h, &ih);
		struct image_data id = convert(&h, &ih, image);
		write_file(argv[2], h, ih, id.converted, id.ct);
		freedata(image, id, ih.height);
		return 0;
	} else
		printf("2 arguments expected");
}

void freedata(struct rgb **image, struct image_data id, unsigned int height)
{
	for(int i = 0; i < height; i++)
	{
		free(image[i]);
	}
	free(image);
	for(int i = 0; i < height; i++)
	{
		free(id.converted[i]);
	}
	free(id.converted);
	free(id.ct);
}
