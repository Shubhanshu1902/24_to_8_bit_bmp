#include <stdio.h>
<<<<<<< HEAD
#include "struct.h"
=======
#include "writer.h"
#include "converter.h"
#include "reader.h"
>>>>>>> 54e28f620c238421f8779a56bbcfc538fcd8caf0

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

