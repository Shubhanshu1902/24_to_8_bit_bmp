#include <stdio.h>
#include "struct.h"

struct rgb** read_file(const char* name, struct header *h, struct info_header *ih);
struct image_data convert(struct header *h, struct info_header *ih, struct rgb **image);
void write_file(const char* target_name, struct header h, struct info_header ih, struct greyscale **image, struct color_table *ct);
int main()
{
	struct header h;
	struct info_header ih;
	struct rgb** image = read_file("lena_color.bmp", &h, &ih);
	struct image_data id = convert(&h, &ih, image);
	write_file("hello.bmp", h, ih, id.converted, id.ct);	
	return 0;
}

