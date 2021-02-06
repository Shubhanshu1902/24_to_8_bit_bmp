#include <stdio.h>

struct header
{
    char id[2];
    int file_size, reserved, data_offset;
} __attribute__((packed));

struct info_header
{
    int size, width, height;
    short planes, bits_per_pixel;
    int compression, image_size, x_pp_m, y_pp_m, colors_used, important_colors;
};

struct pixel_data
{
    char red, blue, green;
};

void logh(struct header *h);
void logih(struct info_header *ih);

int init()
{
    struct header h;
    struct info_header ih;
    FILE *bmp_24 = NULL;

    bmp_24 = fopen("bmp_24.bmp", "rb");
    printf("%lu\n", sizeof(h));
    fread(&h, sizeof(h), 1, bmp_24);
    fread(&ih, sizeof(struct info_header), 1, bmp_24);
    logh(&h);
    logih(&ih);
    return 0;
}

void logh(struct header *h)
{
    printf("%c%c %d %d %d\n", (*h).id[0], (*h).id[1], (*h).file_size, (*h).reserved, (*h).data_offset);
}

void logih(struct info_header *ih)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d\n", (*ih).size, (*ih).width, (*ih).height, (*ih).planes, (*ih).bits_per_pixel, (*ih).compression, (*ih).image_size, (*ih).x_pp_m, (*ih).y_pp_m, (*ih).colors_used, (*ih).important_colors);
}