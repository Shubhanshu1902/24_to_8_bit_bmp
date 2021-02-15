#include <stdio.h>
#include "writer.h"
#include "converter.h"
#include "reader.h"

int main()
{
	struct header h;
	struct info_header ih;
	read_file("lena_color.bmp", &h, &ih);
	return 0;
}

