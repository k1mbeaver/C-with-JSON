#include "JsonParse.h"

void JsonParse::makeJson()
{
	std::ifstream json_file("test.json", std::ifstream::binary);
	// �����ϸ鼭 �ٷ� path�� open mode�� parameter�� ���� ����

	json_file.open("test.json", std::ifstream::in | std::ifstream::binary);
	// ��ó�� open�Լ��� �̿��� �� ������, open mode�� | �����ڸ� �̿��Ͽ� ���� ��� ����

	Json::Value root;
	json_file >> root;
	json_file.close();
	// open�� file���� ���� ������ root�� �����Ͽ� Json::Value�� ���

	// ���ϴ� ������ ��ģ �� formating json
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
		cout << line["width"].asString() << endl;
	}

	system("pause");
	return;
}