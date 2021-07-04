#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <json\json.h>
#include <fstream>
#include "menu.h"

using namespace std;

class JsonParse {
public:
	string str;
	Json::Value root;
	Json::Value family;
	Json::Reader reader;
	Json::StyledWriter writer;
	Menu mymenu;

	void makeJson();
	void parseJsonStudent();
	void parseJsonTeacher();
	void parseJsonSchool();
};