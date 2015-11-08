#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "stdafx.h"
#include "shape.h"
using namespace std;
typedef unsigned char BYTE;
class Image;
class Rectangle : public Shape{

public:
	Rectangle();
	Rectangle(int* parameters);
	virtual void draw(Image& image, BYTE grayLevel);
	virtual void drawWithBorder(Image& image, BYTE grayLevel, BYTE borderGrayLevel);

private:
	int* internalParameters;
	void drawARectangle(Image &image, BYTE grayLevel, int* parameters);
	virtual bool validate(Image &image, int *parameters);
};
#endif