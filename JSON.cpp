#pragma warning(disable : 4996)

#include <iostream>
#include <json/json.h>
#include <fstream>
using namespace std;

int main()
{
	
}

void print_json() {
	Json::Value root;					// �⺻ json document
	root["name"] = "Lee";
	root["age"] = 28;
	root["hasCar"] = true;

	Json::Value items;					// list�� ���� value
	items.append("nootbook");				// append�� �̿��Ͽ� �߰�
	items.append("iphone");
	items.append("apple-watch");
	root["items"] = items;

	Json::Value friends;
	Json::Value tom;
	tom["name"] = "Park";
	tom["age"] = 30;
	Json::Value jane;					// �� Object�� ���ؼ��� append�� �߰�
	jane["name"] = "Kim";
	jane["age"] = 25;
	friends.append(tom);
	friends.append(jane);
	root["friends"] = friends;

	Json::StyledWriter writer;				// json format���� ����ϱ� ���� ���
	str = writer.write(root);
	std::cout << str << std::endl << std::endl;
}

void parsing_json() {
	std::ifstream json_file(path, std::ifstream::binary);
	// �����ϸ鼭 �ٷ� path�� open mode�� parameter�� ���� ����

	std::ifstream json_file;
	json_file.open(path, std::ifstream::in | std::ifstream::binary);
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

void read_json() {
	// �����Ҷ��� ���������� ���� �ٱ����� Json::Value�� Key�� ���ٽ�
	// root[Key]�� value�� ������ �� �ִ�.
	std::cout << "name : " << root["name"].asString() << std::endl;
	std::cout << "age : " << root["age"].asInt() << std::endl;

	// "friends", "items"�� ���� list�� ������ ��쿡�� iterator�� ���
	// .asString(), .asInt()�� ����ϴ� ������, Json::Value���� ��½� typecasting �ʿ�
	Json::Value friend_list = root["friends"];
	for (Json::ValueIterator it = friend_list.begin(); it != friend_list.end(); it++) {
		std::cout << "friend name : " << (*it)["name"].asString() << std::endl;
		std::cout << "firend age : " << (*it)["age"].asInt() << std::endl;
	}

	// Vector�� ����� �ڷᱸ����� �����ϸ� �Ǵ°�, direct indexing�� �����ϴ�.
	for (int index = 0; index < (int)friend_list.size(); index++) {
		std::cout << "friend name : " << friend_list[index]["name"].asString() << std::endl;
		std::cout << "firend age : " << friend_list[index]["age"].asInt() << std::endl;

		// �Ʒ� ó�� get() method�� ����ϸ�, ���� �ش� Key�� ���ٸ� 2��° ���ڸ� return�Ѵ�.  
		std::cout << "friend name : " << friend_list[index].get("name", "empty").asString() << std::endl;
		std::cout << "firend age : " << friend_list[index].get("age", -1).asInt() << std::endl;
	}
}

void read_json() {
	Json::CharReaderBuilder builder;
	builder["collectComments"] = false;

	Json::Value value;
	Json::JSONCPP_STRING errs;
	bool ok = parseFromStream(builder, std::cin, &value, &errs);

	if (ok == true) {
		// access json value ...
	}
}