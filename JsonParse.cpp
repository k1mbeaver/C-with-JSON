#include "JsonParse.h"

void JsonParse::makeJson()
{
	root["name"] = "ksw";
	root["age"] = 2;
	root["address"] = "KOR";
	root["School"] = "GnTEch";
	family.append("Father");
	family.append("Mother");
	family.append("Sister");
	family.append("Broter");
	root["family"] = family;

	str = writer.write(root);
	cout << str << endl;

	ofstream ost("test.json");
	ost << str;

	getchar();
	return;
}

void JsonParse::parseJsonStudent()
{
	ifstream ist("test.json");
	for (char p; ist >> p;)
		str += p;

	bool parsingRet = reader.parse(str, root);
	Json::Value student = root["Student"];
	for (int i = 0; i < 2; i++)
	{
		cout << "�̸� : " << student[i]["name"].asString() << endl;
		cout << "���� : " << student[i]["age"] << endl;
		cout << "�ּ� : " << student[i]["address"].asString() << endl;
		cout << "�б� : " << student[i]["School"].asString() << endl;

		cout << endl;

		cout << "���� ����" << endl;
		for (int nIndex = 0; nIndex < 2; nIndex++)
		{
			cout << student[i]["family"][nIndex].asString() << endl;
		}

		cout << endl;
		cout << root["Line"] << endl;
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

	for (int i = 0; i < 2; i++)
	{
		cout << "�̸� : " << teacher[i]["name"].asString() << endl;
		cout << "���� �̸� : " << teacher[i]["Class"].asString() << endl;
		cout << "��¥ : " << teacher[i]["Date"].asString() << endl;
		cout << "���� : " << teacher[i]["Point"].asString() << endl;
		cout << "���� / ������ : " << teacher[i]["major"].asString() << endl;

		cout << endl;

		cout << "���ǽ�" << endl;

		for (int nIndex = 0; nIndex < 2; nIndex++)
		{
			cout << teacher[i]["room"][nIndex].asString() << endl;
		}

		cout << endl;
		cout << root["Line"] << endl;
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

	for (int i = 0; i < 1; i++)
	{
		cout << "�̸� : " << school[i]["name"].asString() << endl;
		cout << "��ġ : " << school[i]["locate"].asString() << endl;
		cout << "���� / �縳 : " << school[i]["national/private"].asString() << endl;

		cout << endl;

		cout << "����" << endl;

		for (int nIndex = 0; nIndex < 2; nIndex++)
		{
			cout << school[i]["grade"][nIndex].asString() << endl;
		}

		cout << endl;
		cout << root["Line"] << endl;
	}

	system("pause");
	return;
}