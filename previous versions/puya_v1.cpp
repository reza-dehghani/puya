#include <iostream>
#include <string>
using namespace std;

class person{
	string firstname;
	string lastname;
	string id;
public:
//ستر ها :) setter
	void set_firstname(string firstname){ 
		person::firstname = firstname;
	}
	void set_lastname(string lastname){
		person::lastname = lastname;
	}
	void set_id(string id){
		person::id = id;
	}
	//گتر ها getters
	string get_firstname(){
		return firstname;
	}
	string get_lastname(){
		return lastname;
	}
	string get_id(){
		return id;
	}
};
// تعریف فرزند برای کلاس پرسون (کلاس دانشجو)
class student : public person{ 
		int enter_year;
		string field;
		bool status;
public:
		//ستر ها :) setter
	void set_enter_year(int enter_year){ 
		student::enter_year = enter_year;
	}
	void set_field(string field){
		student::field = field;
	}
	void set_status(bool status){
		student::status = status;
	}
	//گتر ها getters
	int set_enter_year(){
		return enter_year;
	}
	string set_field(){
		return field;
	}
	bool set_status(){
		return status;
	}
		void print(){
			cout<<"Print Student Data\n"<< "First Name: "<< get_firstname()
				<<"\nLast name: "<<get_lastname() << "\nID: "<< get_id()
				<<"\nEnter year: "<< enter_year << "\nField: " << field << "\nStatus: ";
				if(status) // or if (status == 1 ) یعنی وضعیت استاتوس که متغیر بولین هست یک باشه
				{
					cout<<"Dar hal tahsil";
				}
				else{
					cout<<"Faregh az tahsil";
				}
				cout<<endl;
		}
		//متود انتخاب واحد
		bool select_lesson(){};
};

int main(){
	student student1;
	student1.set_firstname("Amir");
	student1.set_lastname("Amiri");
	student1.set_id("123456987");
	student1.set_field("Java developer");
	student1.set_status(1);
	student1.set_enter_year(99);
	student1.print();
	return 0;
}