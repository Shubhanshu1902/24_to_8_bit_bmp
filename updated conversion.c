#include<stdio.h>
#include<stdlib.h>

typedef unsigned char UC;

struct pixel_data {
        UC blue;
        UC green;           
        UC red;
    };
struct Image{
        int height;
        int width;
        struct pixel_data** arr;      //arr is a 2D array where its each element is of type struct pixel_data
    };
struct new_pixel_data{
      UC grey;
    };
int main()
{
   
    struct image pic=read Image(fp,height,width);
    RGBtograyscale(pic);  
    for(i=0;i<pic.height;i++)
    {
        for(j=0;j<pic.width;j++) 
            arr2[i][j].grey=grayscale(pic.arr[i][j])
    }
    return 0;
}
struct Image readImage(FILE *fp, int height, int width){
      int i;
      struct Image pic;
      //pic.arr = (struct pixel_data**) malloc(height*sizeof(void*));
      pic.height = height;
      pic.width = width;

      for(i=height-1;i>=0;i--){
            //pic.arr[i] = (struct pixel_data*) malloc(width*sizeof(struct pixel_data));
            fread(pic.arr[i],pic.width,sizeof(struct pixel_data),fp);
        }
      return pic;
        }

unsigned char grayscale(struct pixel_data rgb)
{
        return(rgb.red*0.299 + rgb.green*0.587 + rgb.blue*0.114);       //each component of the pixel is converted into a grayscale value
}

void RGBtoGrayscale(struct Image pic)
{
    int i,j;
    for(i=0;i<pic.height;i++)
        for(j=0;j<pic.width;j++)
             pic.arr[i][j].red = pic.arr[i][j].green = pic.arr[i][j].blue = grayscale(pic.arr[i][j]);       
}

