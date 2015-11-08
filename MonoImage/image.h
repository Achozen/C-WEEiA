#include "stdafx.h"
#include "rectangle.h"
#include "square.h"
#include "circle.h"
using namespace std;
typedef unsigned char BYTE;

class Image{

public:
	//Image(BYTE, BYTE);
	friend class Rectangle;
	friend class Square;
	friend class Circle;
	Image();
	Image(const Image& source);// konstruktor kopiujacy
	Image(int, int, BYTE);
	~Image();
	void innitialize();
	void fillInImage(int);
	BYTE getSinglePixel(int,int);
	void setSinglePixel(int,int,int);
	int getWidth();
	int getHeight();
	void printImage();
	bool validateInputInt(int);

private:
	int x;
	int y;
	BYTE colorValue;
	BYTE **tab;
	
};