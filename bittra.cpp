#include <iostream>

BitMapClass::BitMapClass(char *fileName)
{
	clrPalette = NULL;
	fin.open(fileName, ios::in | ios::binary);
	
	GetFileHeader();
	GetImgInfo();
	GetRGBPalette();
	GetPixelData();
}
	
void BitMapClass::GetFileHeader()
{
	if (!fin.is_open()) throw string("File Read Error");
	else
	{
		fin.read((char*)&fileHeader.bfType, sizeof(fileHeader.bfType));
		if (fileHeader.bfType != 19778) throw string("Invalid Filetype");
		else
		{
			fin.read((char*)&fileHeader.bfSize, sizeof(fileHeader.bfSize));
			fin.read((char*)&fileHeader.bfRes1, sizeof(fileHeader.bfRes1));
			fin.read((char*)&fileHeader.bfRes2, sizeof(fileHeader.bfRes2));
			fin.read((char*)&fileHeader.bfOffBits, sizeof(fileHeader.bfOffBits));
		}
	}
}

void BitMapClass::GetImgInfo()
{
	if (!fin.is_open()) throw string("File Read Error");
	else
	{
		fin.read((char*)&imgInfo.biSize, sizeof(imgInfo.biSize));
		fin.read((char*)&imgInfo.biWidth, sizeof(imgInfo.biWidth));
		fin.read((char*)&imgInfo.biHeight, sizeof(imgInfo.biHeight));
		fin.read((char*)&imgInfo.biPlanes, sizeof(imgInfo.biPlanes));
		fin.read((char*)&imgInfo.biBitCount, sizeof(imgInfo.biBitCount));
		fin.read((char*)&imgInfo.biCompression, sizeof(imgInfo.biCompression));
		fin.read((char*)&imgInfo.biSizeImage, sizeof(imgInfo.biSizeImage));
		fin.read((char*)&imgInfo.biXPelsPerMeter, sizeof(imgInfo.biXPelsPerMeter));
		fin.read((char*)&imgInfo.biYPelsPerMeter, sizeof(imgInfo.biYPelsPerMeter));
		fin.read((char*)&imgInfo.biClrUsed, sizeof(imgInfo.biClrUsed));
		fin.read((char*)&imgInfo.biClrImportant, sizeof(imgInfo.biClrImportant));
	}
}

void BitMapClass::GetPixelData()
{
	int size = fileHeader.bfSize - fileHeader.bfOffBits;
	char *tempPixelData = new char[size];
	
	for (int i=0; i < size; i++)
		fin.read((char*)&tempPixelData[i], 1);
	
	unsigned long byteWidth, padWidth;
	
	byteWidth = padWidth = (unsigned long)((float)imgInfo.biWidth*(float)imgInfo.biBitCount/8.0);
	while (padWidth % 4 != 0)
		padWidth++;
	
	dword diff;
	int offset;
	long height;
	
	height = imgInfo.biHeight;
	diff = height * byteWidth;
	
	pixelData = new char[diff];
	
	if (height > 0)
	{
		int j = imgInfo.biSize - 3;
		offset = padWidth - byteWidth;
		for (int i=0; i < imgInfo.biSize; i += 3)
		{
			if ((i + 1) % padWidth == 0)
				i += offset;
			*(pixelData + j + 2) = *(tempPixelData + i);
			*(pixelData + j + 1) = *(tempPixelData + i + 1);
			*(pixelData + j) = *(tempPixelData + i + 2);
			j++;
		}
	}
	
	for (int i=0; i < size; i++)
		pixelData[i] = tempPixelData[i];

	fin.close();
}

void BitMapClass::GetRGBPalette()
{
	if (!fin.is_open()) throw string("File Read Error");
	else
	{
		int numColors=1 << imgInfo.biBitCount;
		clrPalette = new RGBPalette[numColors];

 		if (imgInfo.biBitCount < 24)
		{
			for (int i=0; i < numColors; i++)
			{
				fin.read(&clrPalette[i].rgbBlue, 1);
				fin.read(&clrPalette[i].rgbGreen, 1);
				fin.read(&clrPalette[i].rgbRed, 1);
				fin.read(&clrPalette[i].rgbReserved, 1);
			}
		}
	}
}

int main()
{
	string fname="lena_color.bmp"
	BitMapClass(fname)
}