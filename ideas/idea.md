For Info about the BMP - http://paulbourke.net/dataformats/bitmaps/
For Info about the make - https://www.gnu.org/software/make/manual/make.html#Reading
Very important BMP file structure - http://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm#:~:text=BMPs%20use%20a%20very%20simple,the%20color%20for%20this%20index.
How To read and write binary files using C - https://www.codingunit.com/c-tutorial-binary-file-io


https://www.mathworks.com/matlabcentral/answers/93196-how-do-i-convert-a-24-bit-depth-image-file-to-an-8-bit-depth-image-file
    this is the explaination of how to convert 24bit bmp to 8bit bmp

https://www.geeksforgeeks.org/c-program-to-write-an-image-in-pgm-format/

http://www.cplusplus.com/forum/general/33301/ 
This is C++ code but we can try to convert to C.

So what i understood is the we need to convert 24 bit rgb into 8bit grayscale bmp image.
well need to use 2d arrays ig cause bitmapping is neccessary
well need a function to get the binary value of a number which is used to get the values of rgb from the source image and then using the formulas we find convert into white and black 
and each pixel is an 2d array ig of 3bytes in rgb where each color takes up one byte and the grayscale is of one byte