#include<stdio.h>
#include<stdlib.h>

typedef unsigned int UI;
typedef unsigned char UC;
int main()
{
    struct RGB {
        UC blue;
        UC green;
        UC red;
    };

    struct Image {
        int height;
        int width;
        struct RGB** rgb;
    };


    struct Image readImage(FILE *fp, int height, int width){
        int i;
        struct Image pic;
        
        pic.height = height;
        pic.width = width;

        for(i=0;i<height;i++){
        
            fread(pic.rgb[i],width,sizeof(struct RGB),fp);
        }
        return pic;
        }

    unsigned char grayscale(struct RGB rgb)
    {
        return(rgb.red*0.3 + rgb.green*0.59 + rgb.blue*0.11);
    }

    void RGBtoGrayscale(struct Image pic)
    {
        int i,j;
        for(i=0;i<pic.height;i++)
            for(j=0;j<pic.width;j++)
                {
                    pic.rgb[i][j].red = pic.rgb[i][j].green = pic.rgb[i][j].blue = grayscale(pic.rgb[i][j]);
                }

    }
}
