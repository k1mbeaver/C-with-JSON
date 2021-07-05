#include "JsonParse.h"
#include "menu.h"

int main()
{
	Menu mymenu;
	JsonParse myJson;
	while (1)
	{
		system("cls");
		int nSelect = 0;
		nSelect = mymenu.selectMenu();
		if (nSelect == 1)
		{
			system("cls");
			myJson.parseJsonStudent();

			continue;
		}

		else if (nSelect == 2)
		{
			system("cls");
			myJson.parseJsonTeacher();

			continue;
		}

		else if (nSelect == 3)
		{
			system("cls");
			myJson.parseJsonSchool();

			continue;
		}

		else if (nSelect == 4)
		{
			system("cls");
			break;
		}

		else if (nSelect == 5)
		{
			system("cls");
			myJson.makeJson();
			break;
		}
	}

	return 0;
}
