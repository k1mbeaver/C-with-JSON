#include "menu.h"

char* Menu::returnName()
{
	char* chName = NULL;

	cout << "�̸��� �Է��Ͽ� �ּ��� : ";
	cin >> chName;
	cout << endl;

	return chName;
}

int Menu::returnAge()
{
	int nAge;

	cout << "���̸� �Է��Ͽ� �ּ��� : ";
	cin >> nAge;
	cout << endl;

	return nAge;
}

char* Menu::returnAdress()
{
	char* chAdress = NULL;

	cout << "�ּҸ� �Է��Ͽ� �ּ���(����, ���ֽ�) : ";
	cin >> chAdress;
	cout << endl;

	return chAdress;
}

char* Menu::returnSchool()
{
	char* chSchool = NULL;

	cout << "�б��� �Է��Ͽ� �ּ��� : ";
	cin >> chSchool;
	cout << endl;

	return chSchool;
}

char* Menu::returnFamilyChar()
{
	char* chFamily = NULL;

	cout << "������ �̸�, ����( �� : ��¿�(��) ) :";
	cin >> chFamily;
	cout << endl;

	return chFamily;
}

int Menu::selectMenu()
{
	int nSelect;

	cout << "1. �л�" << endl;
	cout << "2. ����" << endl;
	cout << "3. �б�����" << endl;
	cout << "4. ����" << endl;
 	cout << "���ϴ� �޴��� �����Ͽ� �ּ��� : ";
	cin >> nSelect;

	return nSelect;
}