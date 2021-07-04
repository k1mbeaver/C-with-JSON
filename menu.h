#pragma once
#include <iostream>
using namespace std;

class Menu {
public:
	char* returnName();
	int returnAge();
	char* returnAdress();
	char* returnSchool();
	char* returnFamilyChar();
	int selectMenu();
};