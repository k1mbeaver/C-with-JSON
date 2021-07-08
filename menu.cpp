#include "menu.h"

int Menu::selectMenu()
{
	ifstream ist("test.json");
	for (char p; ist >> p;)
		str += p;

	bool parsingRet = reader.parse(str, root);
	int nSelect;

	cout << root["menustudent"].asString() << endl;
	cout << root["menuteacher"].asString() << endl;
	cout << root["menuschool"].asString() << endl;
	cout << root["menuexit"].asString() << endl;
	cout << root["menuadd"].asString() << endl;
 	cout << root["menuselect"].asString();
	cin >> nSelect;

	return nSelect;
}

int Menu::selectAdd()
{
	ifstream ist("test.json");
	for (char p; ist >> p;)
		str += p;

	bool parsingRet = reader.parse(str, root);
	int nSelect;

	cout << root["menustudent"].asString() << endl;
	cout << root["menuteacher"].asString() << endl;
	cout << root["menuschool"].asString() << endl;
	cout << root["menuedit"].asString();
	cin >> nSelect;

	return nSelect;
}