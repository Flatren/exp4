#include <FreeImage.h>
#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <FreeImage.h>
//#pragma comment(lib, "C:\\Users\\FLATREN\\Documents\\Visual Studio 2015\\Projects\\exp4\\FreeImage.lib")
#pragma comment(lib, "FreeImage.lib")
extern "C"  __declspec (dllexport) char*  load_image(const char*	filename, int*	width, int*	height)
{
	
	FreeImage_Initialise();
	FIBITMAP* img = FreeImage_Load(FIF_PNG, filename, JPEG_DEFAULT);
		if(!img) img = FreeImage_Load(FIF_JPEG, filename, JPEG_DEFAULT);
	FIBITMAP* img1 = FreeImage_ConvertTo32Bits(img);
	FreeImage_Unload(img);
	int bytespp = FreeImage_GetLine(img1) / FreeImage_GetWidth(img1);
	 *width = FreeImage_GetWidth(img1);
	 *height = FreeImage_GetHeight(img1);
	 int* image = new int[*width**height];
	 int max = *width**height-1;
	 for (unsigned y = 0; y < *height; y++)
	 {
		 BYTE *bits = FreeImage_GetScanLine(img1, y);
		 for (unsigned x = 0,ii=0; x < *width; x++)
		 {
			 ii = y**width;
			 image[max-(ii + x)]=bits[FI_RGBA_ALPHA]<<24;
			 image[max - (ii + x)] += bits[FI_RGBA_RED] << 16;
			 image[max - (ii + x)] += bits[FI_RGBA_GREEN] << 8;
			 image[max - (ii + x)] += bits[FI_RGBA_BLUE];

			 bits += bytespp;
		 }
	 }



	FreeImage_Unload(img1);
	FreeImage_DeInitialise();
	return (char*)image;

}
/*void main()
{
	FreeImage_Initialise();


	FIBITMAP* img = FreeImage_Load(FIF_JPEG, "image01_res3.jpg", JPEG_DEFAULT);
	/*for (int i = 0; i < 300; i++)
		for (int j = 0; j < 300; j++)
			img[i * 300 + j]
	FREE_IMAGE_TYPE ty = FreeImage_GetImageType(img);
	FIBITMAP* img1 = FreeImage_ConvertToRGBA16(img);
	int bytespp = FreeImage_GetLine(img1) / FreeImage_GetWidth(img1);
	int width = FreeImage_GetWidth(img1);
	int height = FreeImage_GetHeight(img1);
	ty = FreeImage_GetImageType(img1);
	FreeImage_Save(FIF_PNG, img1, "image01_res3.png", 0);

	FreeImage_DestroyICCProfile(img);
	FreeImage_DeInitialise();

}*/