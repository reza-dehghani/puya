#pragma once
#include <string>
using namespace std;

class person{
	protected:
	string firstname;
	string lastname;
	string id;
public:
		string get_id(){
			return id;
		}
};