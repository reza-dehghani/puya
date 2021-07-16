#pragma once
#include <string>
#include <person.h>
using namespace std;

class professor : protected person {
	string field;
	bool status;
public:
	professor(string firstname, string lastname, string id, string field, bool status);
	lessons();
};
