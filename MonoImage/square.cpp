// Derived class
#include "stdafx.h"
#include "square.h"
#include "image.h"
#include "rectangle.h"

class Rectangle;
Square::Square(int* parameters) :Rectangle(parameters){
	internalParameters = parameters;
}
bool Square::validate(Image &image, int *parameters){
	printf("Validate test " + parameters[0]);
	system("pause");
	if (parameters[0] < 1 ||
		parameters[1] < 1 ||
		parameters[2] < 1 ){
		return false;
	}
	else if (image.x > parameters[0] + parameters[2]-2 &&
		image.y > parameters[1] + parameters[2]-2){
		return true;
	}
	else{
		return false;
	}
}
void Square::draw(Image &image, BYTE grayLevel){
	if (!validate(image, internalParameters)){
		printf("Parameters are incorrect !!!");
		return;
	}
	drawASquare(image,grayLevel,internalParameters);
}

void Square::drawASquare(Image &image, BYTE grayLevel, int* parameters){

	for (int i = internalParameters[1] - 1; i < (internalParameters[1] + internalParameters[2]) - 1; i++){
		for (int j = internalParameters[0] - 1; j < (internalParameters[0] + internalParameters[2]) - 1; j++){
			image.tab[i][j] = grayLevel;
		}
	}
}
void Square::drawWithBorder(Image& image, BYTE grayLevel, BYTE borderGrayLevel){
	internalParameters[0]--;//increasing radius by one to draw bigger circle
	internalParameters[1]--;//increasing radius by one to draw bigger circle
	internalParameters[2] += 2;//decreasing radius by one to draw bigger circle

	if (!validate(image, internalParameters)){
		printf("Parameters are incorrect !!!");
		return;
	}

	drawASquare(image, borderGrayLevel, internalParameters);

	internalParameters[0]++;//increasing radius by one to draw bigger circle
	internalParameters[1]++;//increasing radius by one to draw bigger circle
	internalParameters[2] -= 2;//decreasing radius by one to draw bigger circle

	drawASquare(image, grayLevel, internalParameters);

}
