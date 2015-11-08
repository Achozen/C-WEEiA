#include "stdafx.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include "image.h"

using namespace std;
typedef unsigned char BYTE;
BYTE table[];

void Image::printImage(){
	for (int i = 0; i < x; i++){
		cout << endl;
		for (int j = 0; j < y; j++){
			printf("%4i",tab[i][j]);
		}
	}
}
BYTE Image::getSinglePixel(int col,int row){
	if (col < x && row < y){
		return (BYTE)tab[row - 1][col - 1];
	}
	else{

		printf("Your coordinates are out of Image.\n Maximum number of colums is: %i", x);
		printf("Maximum number of colums is : %i", y);
		system("pause");
		return -1;
	}

}
int Image::getWidth(){
	
	return x;
}
int Image::getHeight(){

	return y;

}

void Image::setSinglePixel(int col, int row,int val){
	if (val<256 & val>0){
		if (col < x & row < y){
			tab[row-1][col-1]=val;
		}
		else{ printf("You have provided wrong column or row number");
		system("pause");
		}
	}
	else{ printf("You have provided wrong color"); 
	system("pause");
	}
			
}
void Image::fillInImage(int newColor){ 
	if (newColor<256 && newColor>0){
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				tab[i][j] = newColor;
			}
		}
	}
	else{
		printf("Your number is out of range [0-255]");
		system("pause");
	}



}
Image::Image(const Image& source){//konstr kopiujacy
	this->x = source.x;
	this->y = source.y;

	this->tab = new BYTE *[this->x];
	for (int i = 0; i < x; i++){
		this->tab[i] = new BYTE[this->y];
	}
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			this->tab[i][j] = source.tab[i][j];
		}
	}
}
Image::Image(int xVal,int yVal,BYTE colorVal){
	x = xVal;
	y = yVal;
	tab = new BYTE *[x];
	for (int i = 0; i < x; i++){
		tab[i] = new BYTE[y];
	}
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			tab[i][j] = 0;
		}
	}

}
Image::~Image(){

//	for (int i = 0; i < y; i++)
//	{
//		delete[] tab[i];
//	}
//	delete[] tab;

}