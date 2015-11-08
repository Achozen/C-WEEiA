#ifndef SHAPE_H
#define SHAPE_H

#include "stdafx.h"
using namespace std;
typedef unsigned char BYTE;
class Image;
 class Shape{

public:
	//Image(BYTE, BYTE);
	virtual void draw(Image& image, BYTE grayLevel) = 0;
	virtual void drawWithBorder(Image& image, BYTE grayLevel, BYTE borderGrayLevel) = 0;


private:
	virtual bool validate(Image &image, int *parameters) = 0;
	int x;
	int y;
	BYTE colorValue;
	BYTE **tab;

};
#endif