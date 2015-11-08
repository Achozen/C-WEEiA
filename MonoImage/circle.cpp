// Derived class
#include "stdafx.h"
#include "circle.h"
#include "image.h"


Circle::Circle(int* parameters){
	internalParameters = parameters;
}
bool Circle::validate(Image &image, int *parameters){
	printf("Validate test " + parameters[0]);
	if (parameters[0] < 1 ||
		parameters[1] < 1 ||
		parameters[2] < 1 ){
		return false;
	}
	else if (image.x > parameters[0] + parameters[2] - 2 && parameters[0] - parameters[2] >= 0 &&
		image.y > parameters[1] + parameters[2] - 2 && parameters[1] - parameters[2] >= 0 ){
		return true;
	}
	else{
		return false;
	}
}

bool Circle::shouldCellBeDrawn(int a, int b, int radius){
	if ((a*a) + (b*b) <= (radius*radius)){
		return true;
	}
	else{
		return false;
	}
}

void Circle::drawACircle(Image &image, BYTE grayLevel, int* parameters){
	for (int i = 0; i < image.x; i++){
		for (int j = 0; j < image.y; j++){
			if (shouldCellBeDrawn(parameters[0] - i - 1, parameters[1] - j - 1, parameters[2] - 1)){
				image.tab[j][i] = grayLevel;
			}
		}
	}
}
void Circle::draw(Image &image, BYTE grayLevel){
	if (!validate(image, internalParameters)){
		printf("Parameters are incorrect !!!");
		return;
	}
	drawACircle(image, grayLevel, internalParameters);

}

void Circle::drawWithBorder(Image& image, BYTE grayLevel, BYTE borderGrayLevel){
	if (!validate(image, internalParameters)){
		printf("Parameters are incorrect !!!");
		return;
	}

	internalParameters[2]++;//increasing radius by one to draw bigger circle
	drawACircle(image, borderGrayLevel, internalParameters);
	internalParameters[2]--;//decreasing radius by one to draw bigger circle
	drawACircle(image, grayLevel, internalParameters);

}

