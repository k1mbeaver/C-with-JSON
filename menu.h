#pragma once
#include <iostream>
#include "JsonParse.h"
using namespace std;

class Menu {
public:
	string str;
	Json::Reader reader;
	Json::Value root;
	int selectMenu();
	int selectAdd();
};