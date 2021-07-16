#include <iostream>
#include <string>
#include <ctime>
#include <vector>
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
};
class professor : protected person {
	string field;
	bool status;
public:
	professor(string firstname, string lastname, string id, string field, bool status){
			person::firstname = firstname;
			person::lastname = lastname;
			person::id = id;
			professor::field = field;
			professor::status = status;
		}
	lessons();
};
class lesson{
	int capacity;
	int gender;
	int time;
	string teacher;
public:
	lesson(int capacity, int gender, int time, string teacher){
		lesson::capacity = capacity;
		lesson::gender = gender;
		lesson::time = time;
		lesson::teacher = teacher;
	}
	check();
	void print(){
		cout<<"capacity:"<<lesson::capacity <<"\t";
		cout<<"gender:"<<lesson::gender<<"\t";
		cout<<"time:"<<lesson::time<<"\t";
		cout<<"teacher:"<<lesson::teacher<<"\t";
	}
};
	vector <lesson> term_lessons;
void print_term_lessons(){
	cout<<"Enter lessons of this term: ";
	int i=1;
	bool enter=1;
	int capacity;
	int gender;
	int time;
	string teacher;
	while(enter){
	cout<<"lesson["<<i<<"]: ";
	cout<<"capacity, gender, time, teacher";
	cin>>capacity>> gender>> time>> teacher;
	lesson temp_lesson(capacity, gender, time, teacher);
	term_lessons.push_back(temp_lesson);
	cout<<"continue (1/0)?";
	i++;
	cin>>enter;
	}
	for(int j =0; j<term_lessons.size(); j++){
		cout<<"lesson[" << j <<"]: ";
		term_lessons[j].print();
	}
}

class booking{
	int time;
public:
	select_lessons(){
		cout<<"Select lessons from buttom:\n";
		print_term_lessons();
		vector <lesson> final_lessons;
		bool enter = 1;
		int k;
		while(enter){
			cin>>k;
			final_lessons.push_back(term_lessons[k]);
			cout<<"continue (1/0)?";
			cin>>enter;
		}
	}
	change();
	cancel();
};

int main(){
   // current date/time based on current system
   time_t now = time(0);
   tm *ltm = localtime(&now);
   // print various components of tm structure.
   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<<  ltm->tm_mday << endl;
   
	student student1("REza", "dehghani", "13516" , 1400 , "Computer", 1);
	student1.print();
	professor prof1("OStad", "Ostadi" , "123456", "AI", 1);
	lesson programming(40, 0, 2021, "Ostadi");
	vector <lesson> lessons;
	lessons.push_back(programming);
	booking book1;
	book1.select_lessons();
	return 0;
}
