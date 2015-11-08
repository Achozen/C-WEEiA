// Derived class
#include "stdafx.h"
#include "rectangle.h"
#include "image.h"
	 

Rectangle::Rectangle(int* parameters){
	internalParameters = parameters;
}
bool Rectangle::validate(Image &image, int *parameters){
	printf("Validate test "+parameters[0]);
	system("pause");
	if (parameters[0] < 1|| 
		parameters[1] < 1||
		parameters[2] < 1||
		parameters[3] < 1  ){
		return false;
	}
	else if (image.x > parameters[0] + parameters[2]-2 &&
		image.y > parameters[1] + parameters[3]-2){
		return true;
	}
	else{
		return false;
	}
}
void Rectangle::draw(Image &image, BYTE grayLevel){
	if (!validate(image, internalParameters)){
		printf("Parameters are incorrect !!!");
		return;
	}
	drawARectangle(image, grayLevel, internalParameters);

}



void Rectangle::drawARectangle(Image &image, BYTE grayLevel, int* parameters){
	for (int i = internalParameters[1] - 1; i < (internalParameters[1] + internalParameters[3]) - 1; i++){
		for (int j = internalParameters[0] - 1; j < (internalParameters[0] + internalParameters[2]) - 1; j++){
			image.tab[i][j] = grayLevel;
		}
	}
}
void Rectangle::drawWithBorder(Image& image, BYTE grayLevel, BYTE borderGrayLevel){

	internalParameters[0]--;//increasing radius by one to draw bigger circle
	internalParameters[1]--;//increasing radius by one to draw bigger circle
	internalParameters[2] += 2;//decreasing radius by one to draw bigger circle
	internalParameters[3] += 2;//decreasing radius by one to draw bigger circle

	if (!validate(image, internalParameters)){
		printf("Parameters are incorrect !!!");
		return;
	}


	drawARectangle(image, borderGrayLevel, internalParameters);
	internalParameters[0]++;//increasing radius by one to draw bigger circle
	internalParameters[1]++;//increasing radius by one to draw bigger circle
	internalParameters[2] -= 2;//decreasing radius by one to draw bigger circle
	internalParameters[3] -= 2;//decreasing radius by one to draw bigger circle

	drawARectangle(image, grayLevel, internalParameters);

}




