#pragma warning(disable : 4996)

#include <iostream>
#include <json/json.h>
#include <fstream>
using namespace std;

int main()
{
	
}

void print_json() {
	Json::Value root;					// 기본 json document
	root["name"] = "Lee";
	root["age"] = 28;
	root["hasCar"] = true;

	Json::Value items;					// list를 위한 value
	items.append("nootbook");				// append를 이용하여 추가
	items.append("iphone");
	items.append("apple-watch");
	root["items"] = items;

	Json::Value friends;
	Json::Value tom;
	tom["name"] = "Park";
	tom["age"] = 30;
	Json::Value jane;					// 각 Object에 대해서도 append로 추가
	jane["name"] = "Kim";
	jane["age"] = 25;
	friends.append(tom);
	friends.append(jane);
	root["friends"] = friends;

	Json::StyledWriter writer;				// json format으로 출력하기 위해 사용
	str = writer.write(root);
	std::cout << str << std::endl << std::endl;
}

void parsing_json() {
	std::ifstream json_file(path, std::ifstream::binary);
	// 생성하면서 바로 path와 open mode를 parameter로 전달 가능

	std::ifstream json_file;
	json_file.open(path, std::ifstream::in | std::ifstream::binary);
	// 이처럼 open함수를 이용할 수 있으며, open mode는 | 연산자를 이용하여 여러 모드 가능

	Json::Value root;
	json_file >> root;
	json_file.close();
	// open한 file에서 얻어온 내용을 root에 대입하여 Json::Value로 사용

	// 원하는 수정을 거친 후 formating json
	Json::StyledWriter writer;
	str = writer.write(root);

	// output to json file
	std::ofstream output_file("output.json");
	output_file << str;
	output_file.close();
}

void read_json() {
	// 수정할때와 마찬가지로 가장 바깥쪽의 Json::Value의 Key에 접근시
	// root[Key]로 value를 가져올 수 있다.
	std::cout << "name : " << root["name"].asString() << std::endl;
	std::cout << "age : " << root["age"].asInt() << std::endl;

	// "friends", "items"와 같은 list를 접근할 경우에는 iterator를 사용
	// .asString(), .asInt()를 사용하는 이유는, Json::Value에서 출력시 typecasting 필요
	Json::Value friend_list = root["friends"];
	for (Json::ValueIterator it = friend_list.begin(); it != friend_list.end(); it++) {
		std::cout << "friend name : " << (*it)["name"].asString() << std::endl;
		std::cout << "firend age : " << (*it)["age"].asInt() << std::endl;
	}

	// Vector와 비슷한 자료구조라고 생각하면 되는게, direct indexing도 가능하다.
	for (int index = 0; index < (int)friend_list.size(); index++) {
		std::cout << "friend name : " << friend_list[index]["name"].asString() << std::endl;
		std::cout << "firend age : " << friend_list[index]["age"].asInt() << std::endl;

		// 아래 처럼 get() method를 사용하면, 만약 해당 Key가 없다면 2번째 인자를 return한다.  
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