#include "JsonParse.h"

void JsonParse::makeJson()
{
	std::ifstream json_file("test.json", std::ifstream::binary);
	// 생성하면서 바로 path와 open mode를 parameter로 전달 가능

	json_file.open("test.json", std::ifstream::in | std::ifstream::binary);
	// 이처럼 open함수를 이용할 수 있으며, open mode는 | 연산자를 이용하여 여러 모드 가능

	Json::Value root;
	json_file >> root;
	json_file.close();
	// open한 file에서 얻어온 내용을 root에 대입하여 Json::Value로 사용

	// 원하는 수정을 거친 후 formating json
	Json::StyledWriter writer;
	str = writer.write(root);

	// output to json file
	std::ofstream output_file("output.json");
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
	for (int i = 0; i < 2; i++)
	{
		cout << "이름 : " << student[i]["name"].asString() << endl;
		cout << "나이 : " << student[i]["age"] << endl;
		cout << "주소 : " << student[i]["address"].asString() << endl;
		cout << "학교 : " << student[i]["School"].asString() << endl;

		cout << endl;

		cout << "가족 구성" << endl;
		for (int nIndex = 0; nIndex < 2; nIndex++)
		{
			cout << student[i]["family"][nIndex].asString() << endl;
		}

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

	for (int i = 0; i < 2; i++)
	{
		cout << "이름 : " << teacher[i]["name"].asString() << endl;
		cout << "강의 이름 : " << teacher[i]["Class"].asString() << endl;
		cout << "날짜 : " << teacher[i]["Date"].asString() << endl;
		cout << "학점 : " << teacher[i]["Point"].asString() << endl;
		cout << "전공 / 비전공 : " << teacher[i]["major"].asString() << endl;

		cout << endl;

		cout << "강의실" << endl;

		for (int nIndex = 0; nIndex < 2; nIndex++)
		{
			cout << teacher[i]["room"][nIndex].asString() << endl;
		}

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

	for (int i = 0; i < 1; i++)
	{
		cout << "이름 : " << school[i]["name"].asString() << endl;
		cout << "위치 : " << school[i]["locate"].asString() << endl;
		cout << "국립 / 사립 : " << school[i]["national/private"].asString() << endl;

		cout << endl;

		cout << "년제" << endl;

		for (int nIndex = 0; nIndex < 2; nIndex++)
		{
			cout << school[i]["grade"][nIndex].asString() << endl;
		}

		cout << endl;
		cout << line["width"].asString() << endl;
	}

	system("pause");
	return;
}