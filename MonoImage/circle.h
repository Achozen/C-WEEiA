#ifndef CIRCLE_H
#define CIRCLE_H

#include "stdafx.h"
#include "shape.h"
using namespace std;
typedef unsigned char BYTE;
class Image;
class Circle : public Shape{

public:
	Circle();
	Circle(int* parameters);
	virtual void draw(Image& image, BYTE grayLevel);
	virtual void drawWithBorder(Image& image, BYTE grayLevel, BYTE borderGrayLevel);

private:
	int* internalParameters;
	void drawACircle(Image &image, BYTE grayLevel,int* parameters);
	virtual bool validate(Image &image, int *parameters);
	bool shouldCellBeDrawn(int x,int y, int radius);
};
#endif