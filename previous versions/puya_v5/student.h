#pragma once
#include <iostream>
#include <string>
#include <person.h>
using namespace std;

// تعریف فرزند برای کلاس پرسون (کلاس دانشجو)
class student : protected person{
		int enter_year;
		string field;
		bool status;
public:
		int gender;
		//constructor
		student(string firstname, string lastname, string id, int enter_year, string field, bool status, int gender);
		void print();
		string get_id(){
			return id;
		}
};

