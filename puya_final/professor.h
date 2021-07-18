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
			string get_id(){
			return id;
		}
	string print_name(){
		return professor::firstname + professor::lastname;
	}
};
