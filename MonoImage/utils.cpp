#include "stdafx.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include "utils.h"

using namespace std;
typedef unsigned char BYTE;
BYTE table[];

bool Utils::isNumber(int input){
	if (input <= 0){
		cout << "Shame on you ! Write a proper number you filthy bastard! ";
		return false;
	}
	else{
		cout << "Proper number registered";
		return true;
	}
}