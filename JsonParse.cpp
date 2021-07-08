#include "JsonParse.h"

void JsonParse::addStudent()
{
	char chName[30] = {"\0"};
	char chSchool[30] = { "\0" };
	char chAddress[30] = { "\0" };
	int nAge = 0;
	char chHobby[30] = { "\0" };
	std::ifstream json_file("test.json", std::ifstream::binary);
	// 생성하면서 바로 path와 open mode를 parameter로 전달 가능

	json_file.open("test.json", std::ifstream::in | std::ifstream::binary);
	// 이처럼 open함수를 이용할 수 있으며, open mode는 | 연산자를 이용하여 여러 모드 가능

	Json::Value root;
	json_file >> root;
	json_file.close();
	// open한 file에서 얻어온 내용을 root에 대입하여 Json::Value로 사용

	Json::Value student = root["Student"];
	Json::Value add;
	cout << root["NAME"].asString();
	cin >> chName;
	add["Name"] = chName;
	cout << root["SCHOOLNAME"].asString();
	cin >> chSchool;
	add["School"] = chSchool;
	cout << root["NATIONALITY"].asString();
	cin >> chAddress;
	add["Address"] = chAddress;
	cout << root["AGE"].asString();
	cin >> nAge;
	add["Age"] = nAge;
	cout << root["HOBBY"].asString();;
	cin >> chHobby;
	add["Hobby"] = chHobby;
	student.append(add);
	root["Student"] = student;

	// 원하는 수정을 거친 후 formating json
	Json::StyledWriter writer;
	str = writer.write(root);

	// output to json file
	std::ofstream output_file("test.json");
	output_file << str;
	output_file.close();
}

void JsonParse::addTeacher()
{
	char chName[30] = { "\0" };
	char chClass[30] = { "\0" };
	char chDate[30] = { "\0" };
	int nPoint = 0;
	char chMajor[30] = { "\0" };
	char chRoom[30] = { "\0" };
	std::ifstream json_file("test.json", std::ifstream::binary);
	// 생성하면서 바로 path와 open mode를 parameter로 전달 가능

	json_file.open("test.json", std::ifstream::in | std::ifstream::binary);
	// 이처럼 open함수를 이용할 수 있으며, open mode는 | 연산자를 이용하여 여러 모드 가능

	Json::Value root;
	json_file >> root;
	json_file.close();
	// open한 file에서 얻어온 내용을 root에 대입하여 Json::Value로 사용

	Json::Value teacher = root["Teacher"];
	Json::Value add;
	cout << root["NAME"].asString();
	cin >> chName;
	add["Name"] = chName;
	cout << root["CLASSNAME"].asString();
	cin >> chClass;
	add["Class"] = chClass;
	cout << root["DATE"].asString();
	cin >> chDate;
	add["Date"] = chDate;
	cout << root["POINT"].asString();
	cin >> nPoint;
	add["Point"] = nPoint;
	cout << root["MAJOR"].asString();
	cin >> chMajor;
	add["Major"] = chMajor;
	cout << root["ROOM"].asString();
	cin >> chRoom;
	add["Room"] = chRoom;
	teacher.append(add);
	root["Teacher"] = teacher;

	// 원하는 수정을 거친 후 formating json
	Json::StyledWriter writer;
	str = writer.write(root);

	// output to json file
	std::ofstream output_file("test.json");
	output_file << str;
	output_file.close();
}

void JsonParse::addSchool()
{
	char chName[30] = { "\0" };
	char chLocate[30] = { "\0" };
	char chNationorPrivate[30] = { "\0" };
	int nGrade = 0;
	std::ifstream json_file("test.json", std::ifstream::binary);
	// 생성하면서 바로 path와 open mode를 parameter로 전달 가능

	json_file.open("test.json", std::ifstream::in | std::ifstream::binary);
	// 이처럼 open함수를 이용할 수 있으며, open mode는 | 연산자를 이용하여 여러 모드 가능

	Json::Value root;
	json_file >> root;
	json_file.close();
	// open한 file에서 얻어온 내용을 root에 대입하여 Json::Value로 사용

	Json::Value school = root["SchoolInformation"];
	Json::Value add;
	cout << root["SCHOOLNAME"].asString();
	cin >> chName;
	add["Name"] = chName;
	cout << root["LOCATE"].asString();
	cin >> chLocate;
	add["Locate"] = chLocate;
	cout << root["NATIONAL/PRIVATE"].asString();
	cin >> chNationorPrivate;
	add["National/Private"] = chNationorPrivate;
	cout << root["GRADE"].asString();
	cin >> nGrade;
	add["Grade"] = nGrade;
	school.append(add);
	root["SchoolInformation"] = school;

	// 원하는 수정을 거친 후 formating json
	Json::StyledWriter writer;
	str = writer.write(root);

	// output to json file
	std::ofstream output_file("test.json");
	output_file << str;
	output_file.close();
}

void JsonParse::parseJsonStudent()
{
	ifstream ist("test.json");
	for (char p; ist >> p;)
		str += p;

	bool parsingRet = reader.parse(str, root);
	Json::Value student = root["Student"];
	Json::Value line = root["Line"];

	for (Json::ValueIterator it = student.begin(); it != student.end(); it++)
	{
		cout << root["parsename"].asString() << (*it)["Name"].asString() << endl;
		cout << root["parseage"].asString() << (*it)["Age"].asString() << endl;
		cout << root["parseaddress"].asString() << (*it)["Address"].asString() << endl;
		cout << root["parseschool"].asString() << (*it)["School"].asString() << endl;
		cout << root["parsehobby"].asString() << (*it)["Hobby"].asString() << endl;

		cout << endl;
		cout << line["width"].asString() << endl;
	}
	system("pause");
	return;
}

void JsonParse::parseJsonTeacher()
{
	ifstream ist("test.json");
	for (char p; ist >> p;)
		str += p;

	bool parsingRet = reader.parse(str, root);
	Json::Value teacher = root["Teacher"];
	Json::Value line = root["Line"];
	
	for (Json::ValueIterator it = teacher.begin(); it != teacher.end(); it++)
	{
		cout << root["parsename"].asString() << (*it)["Name"].asString() << endl;
		cout << root["parseclassname"].asString() << (*it)["Class"].asString() << endl;
		cout << root["parsedate"].asString() << (*it)["Date"].asString() << endl;
		cout << root["parsepoint"].asString() << (*it)["Point"].asString() << endl;
		cout << root["parsemajor"].asString() << (*it)["Major"].asString() << endl;
		cout << root["parseroom"].asString() << (*it)["Room"].asString() << endl;

		cout << endl;
		cout << line["width"].asString() << endl;
	}
	system("pause");
	return;
}

void JsonParse::parseJsonSchool()
{
	ifstream ist("test.json");
	for (char p; ist >> p;)
		str += p;

	bool parsingRet = reader.parse(str, root);
	Json::Value school = root["SchoolInformation"];
	Json::Value line = root["Line"];

	for (Json::ValueIterator it = school.begin(); it != school.end(); it++)
	{
		cout << root["parsename"].asString() << (*it)["Name"].asString() << endl;
		cout << root["parselocate"].asString() << (*it)["Locate"].asString() << endl;
		cout << root["parsenational"].asString() << (*it)["National/Private"].asString() << endl;
		cout << root["parsegrade"].asString() << (*it)["Grade"].asString() << endl;

		cout << endl;
		cout << line["width"].asString() << endl;
	}

	system("pause");
	return;
}