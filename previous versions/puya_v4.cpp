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
		int gender;
		//constructor
		student(string firstname, string lastname, string id, int enter_year, string field, bool status, int gender){
			person::firstname = firstname;
			person::lastname = lastname;
			person::id = id;
			student::enter_year = enter_year;
			student::field = field;
			student::status = status;
			student::gender = gender;
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

public:
	int code;
	int capacity;
	//جنیست
	// مرد = 2 و زن = 1 و هر دو = 0
	int gender;
	int time;
	string teacher;
	
	lesson(int code ,int capacity, int gender, int time, string teacher){
		lesson::code = code;
		lesson::capacity = capacity;
		lesson::gender = gender;
		lesson::time = time;
		lesson::teacher = teacher;
	}
	check();
	
	void print(){
		cout<<"LessonCODE:"<<lesson::code <<"\t";
		cout<<"capacity:"<<lesson::capacity <<"\t";
		cout<<"gender:"<<lesson::gender<<"\t";
		cout<<"time:"<<lesson::time<<"\t";
		cout<<"teacher:"<<lesson::teacher<<"\n";
		
	}
};
	vector <lesson> term_lessons;
	vector <lesson> final_lessons;
	vector <lesson> pishnevis;
void print_term_lessons(){
	cout<<"Enter lessons of this term: ";
	bool enter=1;
	int  i=0, capacity, code, gender, time;
	string teacher;
	while(enter){
	cout<<"lessonCODE["<<i<<"]: ";
	cout<<"LessonCODE, capacity, gender, time, teacher";
	cin>> code >>capacity>> gender>> time>> teacher;
	lesson temp_lesson(code, capacity, gender, time, teacher);
	term_lessons.push_back(temp_lesson);
	cout<<"continue (1/0)?";
	i++;
	cin>>enter;
	}
	for(int j =0; j<term_lessons.size(); j++){
		cout<<"lessonCODE[" << term_lessons[j].code <<"]: ";
		term_lessons[j].print();
	}
}

class booking{
public:
	select_lessons(student stu){
	    cout<<"Select lessons from buttom with lesson CODE:\n";
		print_term_lessons();
		bool enter = 1;
		int k;
		while(enter){
			int tedad=0;
			bool tadakhol = 0;
			
			cin>>k;
			for(int i =0 ; term_lessons.size(); i++){
				if(k == term_lessons[i].code){
					k = term_lessons[i].code;
					break;
				}
			}
			if(pishnevis.size()>0 && term_lessons.empty()){
			//بررسی تکراری نبودن درس انتخابی
			for(int r=0; r <pishnevis.size(); r++){
				//اگر کد د2رس به کد درس پیش نویس انتخاب واحد برابر بود
				if (term_lessons[k].code == pishnevis[r].code) {
					cout<<"\n Error:Dars entekhabi tekrari mibashad, lotfan dars digari entekhab konid!\n";
					continue;
			}
			}
			}
			//بررسی تداخل ساعات دروس
			pishnevis.push_back(term_lessons[k]);
			for(int h=0; h< term_lessons.size(); h++){
			if(term_lessons[k].time == pishnevis[h].time){
				tedad++;
			}
			}
			//تداخل جنسیت
			if(term_lessons[k].gender == 1 || term_lessons[k].gender == 2){
				if(term_lessons[k].gender != stu.gender)
					tadakhol = 1;
			}
			//بررسی شرط تداخل ساعت درس
			if(tedad>1){
				cout<<"\n Error: Saat Dars entekhabi tadakhol darad!\n";
				continue;
			}
			//بررسی شرط تداخل ساعت درس
			if(tadakhol == 1){
				cout<<"\n Error: jensiat entekhabi tadakhol darad!\n";
				continue;
			}
			final_lessons.push_back(term_lessons[k]);
			cout<<"\ncontinue (1/0): ";
			cin>>enter;
		}
	}
};

int main(){
   // current date/time based on current system
   time_t now = time(0);
   tm *ltm = localtime(&now);
   // print various components of tm structure.
   int now_m = 1 + ltm->tm_mon;
   int now_d = ltm->tm_mday;
   cout << "Month: "<< now_m<< endl;
   cout << "Day: "<<  now_d << endl;
	
	student student1("Reza", "Dehghani", "0001112222" , 1400 , "Computer", 1, 2);

	booking book1;
	book1.select_lessons(student1);
	
	for(int i= 0 ; i<final_lessons.size(); i++)
		final_lessons[i].print();
	
	return 0;
}