#ifndef SQUARE_H
#define SQUARE_H

#include "stdafx.h"
#include "rectangle.h"
using namespace std;
typedef unsigned char BYTE;
class Image;
class Square : public Rectangle{

public:
	Square(int* parameters);
	virtual void draw(Image& image, BYTE grayLevel);
	virtual void drawWithBorder(Image& image, BYTE grayLevel, BYTE borderGrayLevel);


private:
	int* internalParameters;
	void drawASquare(Image &image, BYTE grayLevel, int* parameters);
	virtual bool validate(Image &image, int *parameters);
};
#endif