#pragma once
#include <iostream>
#include <string>
#include <person.h>
#include <vector>
#include "lesson.h"
using namespace std;

// تعریف فرزند برای کلاس پرسون (کلاس دانشجو)
class student : protected person{
		int enter_year;
		string field;
		bool status;
public:
//		lesson lessons[20];
		int gender;
		vector <lesson> lessons;
		//constructor
		student(string firstname, string lastname, string id, int enter_year, string field, bool status, int gender,vector <lesson> lessons);
		void print();
		string get_id(){
			return id;
		}
		string get_name(){
			return firstname+lastname;
		}
		student create_object();
};