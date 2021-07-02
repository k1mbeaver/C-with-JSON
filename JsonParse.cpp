#include "JsonParse.h"

void JsonParse::makeJson()
{
	root["name"] = "Kim";
	root["age"] = 21;
	root["address"] = "KOR, GIMHAE";
	root["School"] = "GnTech";

	family.append("Father");
	family.append("Mother");
	family.append("Sister1");
	family.append("Sister2");
	root["family"] = family;

	str = writer.write(root);
	cout << str << endl;

	ofstream ost("test.json");
	ost << str;

	getchar();
	return;
}

void JsonParse::parseJson()
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
	cout << family[0].asString() << endl;
	cout << family[1].asString() << endl;
	cout << family[2].asString() << endl;
	cout << family[3].asString() << endl;

}