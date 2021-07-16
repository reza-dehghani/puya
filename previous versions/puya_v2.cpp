#include <iostream>
#include <string>
using namespace std;

class person{
	protected:
	string firstname;
	string lastname;
	string id;
};
// تعریف فرزند برای کلاس پرسون (کلاس دانشجو)
class student : protected person{
		int enter_year;
		string field;
		bool status;
public:
		//constructor
		student(string firstname, string lastname, string id, int enter_year, string field, bool status){
			person::firstname = firstname;
			person::lastname = lastname;
			person::id = id;
			student::enter_year = enter_year;
			student::field = field;
			student::status = status;
		}
		void print(){
			//چاپ 
			// اینجا خصوصیت های کلاس پدر رو می تونیم حتی از کلاس فرزند چاپ کنیم
			//student::firstname مثلا
			cout<<"Print Student Data\n"<< "First Name: "<< student::firstname
				<<"\nLast name: "<<student::lastname << "\nID: "<< student::id
				<<"\nEnter year: "<< student::enter_year << "\nField: " << student::field << "\nStatus: ";
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
	student student1("REza", "dehghani", "13516" , 1400 , "Computer", 1);
	student1.print();
	return 0;
}