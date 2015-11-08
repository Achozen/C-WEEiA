// MonoImage.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "rectangle.h"
#include "square.h"
#include "circle.h"
#include "utils.h"
#include "image.h"



inline bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}
bool isInputIntPositive(int input){

	if (input <= 0){
		cout << "Shame on you ! Write a positive number you filthy bastard! ";
		return false;
	}
	else{
		return true;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int x = 0, y = 0;
	int g = 0, bg = 0;
	int parameters[4];
	int exit = 0;
	int menuDecision;
	int colorValue = 0,temp=0;

	cout << "Write height of table";
		do{
	scanf("%i",&x);
		} while (isInputIntPositive(x) == false);
	cout << "Write width of table";

		do{
			scanf("%i",&y);
		} while (isInputIntPositive(y) == false);
	Image img(x, y, colorValue);
	Image img2 = img;
	Image img3(img);

	img.printImage();//wyswietlenie
	do{
		cout << "\nWhat would you like to do?\n\n0-exit\n1-renderImage\n2-set color of al pixels\n3-set color of single pixel\n4-get color of single pixel\n5-draw a rectangle\n6-draw a square\n7-draw a circle\n8-draw a rectangle with border\n9-draw a square with border\n10-draw a circle with border\n";
		scanf("%i",&menuDecision);
		switch (menuDecision){
		case 0:
			img.~Image();
			img2.~Image();
			exit = 1;
			break;
		case 1:
			system("cls");
			img.printImage();//wyswietlanie
			break;
		case 2:
			system("cls");
			cout << "Write new number of desired color (0-255)";
			scanf("%i", &colorValue);
			img.fillInImage(colorValue);
			system("cls");
			img.printImage();//wyswietlanie
			break;
		case 3:
			system("cls");
			cout << "Change a single pixel col , row and color (0-255)";
			scanf("%i", &x);
			scanf("%i", &y);
			scanf("%i", &colorValue);
			img.setSinglePixel(x, y, colorValue);
			system("cls");
			img.printImage();//wyswietlanie
			break;
		case 4:
			system("cls");
			cout << "Print a single pixel col , row";
			scanf("%i", &x);
			scanf("%i", &y);
			system("cls");
			temp = img.getSinglePixel(x, y);
			if (temp != -1){
				printf("This pixel s: %i\n\n", temp);
			}
			system("pause");
			system("cls");
			img.printImage();//wyswietlanie
			break;
		case 5:
		{
				  system("cls");
				  cout << "Write coordinates of upper left corner(x,y), lenghts of edges(a,b), and grey level(g) ";
				  scanf("%i", &parameters[0]);
				  scanf("%i", &parameters[1]);
				  scanf("%i", &parameters[2]);
				  scanf("%i", &parameters[3]);
				  scanf("%i", &g);
				  Rectangle rect(parameters);
				  rect.draw(img, g);
				  img.printImage();//wyswietlanie
				  break;
		}
		case 6:
		{
				  system("cls");
				  cout << "Write coordinates of upper left corner(x,y), lenght of edge(a) and grey level(g) ";
				  scanf("%i", &parameters[0]);
				  scanf("%i", &parameters[1]);
				  scanf("%i", &parameters[2]);
				  scanf("%i", &g);
				  Square square(parameters);
				  square.draw(img, g);
				  img.printImage();//wyswietlanie
				  break;
		}
		case 7:
		{
			system("cls");
			cout << "Write coordinates of middle point of circle(x,y), the radius(r) and gray level(g) ";
			scanf("%i", &parameters[0]);
			scanf("%i", &parameters[1]);
			scanf("%i", &parameters[2]);
			scanf("%i", &g);
			Circle circle(parameters);
			circle.draw(img, g);
			img.printImage();//wyswietlanie
			break;
		}
		case 8:
		{
				  system("cls");
				  cout << "Write coordinates of upper left corner(x,y), lenghts of edges(a,b), gray level(g), and boder gray lever ";
				  scanf("%i", &parameters[0]);
				  scanf("%i", &parameters[1]);
				  scanf("%i", &parameters[2]);
				  scanf("%i", &parameters[3]);
				  scanf("%i", &g);
				  scanf("%i", &bg);
				  Rectangle rect(parameters);
				  rect.drawWithBorder(img, g, bg);
				  img.printImage();//wyswietlanie
				  break;
		}
		case 9:
		{
				  system("cls");
				  cout << "Write coordinates of upper left corner(x,y), lenght of edge(a), gray level(g), and boder gray lever  ";
				  scanf("%i", &parameters[0]);
				  scanf("%i", &parameters[1]);
				  scanf("%i", &parameters[2]);
				  scanf("%i", &g);
				  scanf("%i", &bg);
				  Square square(parameters);
				  square.drawWithBorder(img, g, bg);
				  img.printImage();//wyswietlanie
				  break;
		}
		case 10:
		{
				  system("cls");
				  cout << "Write coordinates of middle point of circle(x,y), the radius(r), gray level(g), and boder gray lever  ";
				  scanf("%i", &parameters[0]);
				  scanf("%i", &parameters[1]);
				  scanf("%i", &parameters[2]);
				  scanf("%i", &g);
				  scanf("%i", &bg);
				  Circle circle(parameters);
				  circle.drawWithBorder(img, g, bg);
				  img.printImage();//wyswietlanie
				  break;
		}
		}
	//	img2.fillInImage(5);
	//	img2.printImage();

	//	img3.fillInImage(5);
	//	img3.printImage();
	} while (exit == 0);
	system("pause");
	return 0;
}
	


