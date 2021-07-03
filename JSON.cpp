#include "JsonParse.h"
#include "menu.h"

int main()
{
	Menu mymenu;
	JsonParse myJson;
	char chName[10] = "\0";
	int nAge;
	char chAdress[10] = "\0";
	char chSchool[10] = "\0";
	int nFamily;
	while (1)
	{
		system("cls");
		int nSelect = 0;
		nSelect = mymenu.selectMenu();
		if (nSelect == 1)
		{
			myJson.makeJson();
			continue;
		}

		else if (nSelect == 2)
		{
			system("cls");
			int nFamily = mymenu.returnFamilyInt();
			system("cls");
			myJson.parseJson(nFamily);

			continue;
		}
	}
}
