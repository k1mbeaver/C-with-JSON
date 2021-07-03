#include "menu.h"

char* Menu::returnName()
{
	char* chName = NULL;

	cout << "이름을 입력하여 주세요 : ";
	cin >> chName;
	cout << endl;

	return chName;
}

int Menu::returnAge()
{
	int nAge;

	cout << "나이를 입력하여 주세요 : ";
	cin >> nAge;
	cout << endl;

	return nAge;
}

char* Menu::returnAdress()
{
	char* chAdress = NULL;

	cout << "주소를 입력하여 주세요(나라, 거주시) : ";
	cin >> chAdress;
	cout << endl;

	return chAdress;
}

char* Menu::returnSchool()
{
	char* chSchool = NULL;

	cout << "학교를 입력하여 주세요 : ";
	cin >> chSchool;
	cout << endl;

	return chSchool;
}

int Menu::returnFamilyInt()
{
	int nCount;

	cout << "가족 수를 입력하여 주세요( 본인 제외 ) : ";
	cin >> nCount;
	cout << endl;

	return nCount;
}

char* Menu::returnFamilyChar()
{
	char* chFamily = NULL;

	cout << "가족의 이름, 관계( 예 : 김승욱(부) ) :";
	cin >> chFamily;
	cout << endl;

	return chFamily;
}

int Menu::selectMenu()
{
	int nSelect;

	cout << "1. 입력" << endl;
	cout << "2. 출력" << endl;
	cout << "원하는 메뉴를 선택하여 주세요 : ";
	cin >> nSelect;

	return nSelect;
}