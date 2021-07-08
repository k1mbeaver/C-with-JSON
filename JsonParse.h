#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <json\json.h>
#include <fstream>

using namespace std;

class JsonParse {
public:
	string str;
	Json::Value root;
	Json::Value family;
	Json::Reader reader;
	Json::StyledWriter writer;

	void addStudent();
	void addTeacher();
	void addSchool();
	void parseJsonStudent();
	void parseJsonTeacher();
	void parseJsonSchool();
};