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

void JsonParse::parseJson(int nFamily)
{
	ifstream ist("test.json");
	for (char p; ist >> p;)
		str += p;

	bool parsingRet = reader.parse(str, root);


	cout << root["name"] << endl;
	cout << root["age"] << endl;
	cout << root["address"] << endl;
	cout << root["School"] << endl;

	Json::Value family = root["family"];
	for (int nIndex = 0; nIndex < nFamily; nIndex++)
	{
		cout << family[nIndex].asString() << endl;
	}

	system("pause");
	return;
}