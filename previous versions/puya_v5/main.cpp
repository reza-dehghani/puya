//include class
#include "person.h"
#include "student.h"
#include "professor.h"
#include "lesson.h"	
#include "booking.h"
#include "booking.cpp"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>

//برای کنترل صفحه
#ifdef _WIN32
#include<Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

//from booking.cpp
	vector <lesson> term_lessons;
	vector <lesson> final_lessons;
	vector <lesson> pishnevis;
	vector <student> stus;
	vector <professor> profs;

void update_lesson();

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

booking::select_lessons(student stu){
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

//functions
void add_new_stu();
void add_new_lesson();
void	add_new_prof();
void report();

int main(){
	int input, login;
	//INITIAL TIME
   // current date/time based on current system
   time_t now = time(0);
   tm *ltm = localtime(&now);
   // print various components of tm structure.
   int now_m = 1 + ltm->tm_mon;
   int now_d = ltm->tm_mday;
   cout << "Month: "<< now_m<< endl;
   cout << "Day: "<<  now_d << endl;
   	//END INITIAL TIME
	//Read programming Data from files
	
	//MENU
	bool turn=1;
	while(turn){
	cout << "Welcome to The <Birjand UT Store>";
	Sleep(1000);
	cout<<system("cls");
	cout<<"Please LOGIN as: \n 1. ADMIN 2. Student 3. Professor\n";
	string username, pass;
	string cusername="111", cpass = "111";
	int a=1;
	cin>>login;
	switch(login){
		case 1:{
			cout<<"Enter username: ";
			cin>> username;
			cout<<endl;
			cout<<"Enter pass: ";
			cin>> pass;
			if(cusername ==username && cpass == pass){
				system("cls");
				while(turn){
						system("cls");
					cout<<"1.Add New Student\n 2.Add New lesson\n 3.Add New professor 4.Report of all roles on the system\n20.return back\n";
				int inputadmin;
				cin >> inputadmin;
				switch(inputadmin){
					case 1:{
					system("cls");
					add_new_stu();
						break;
					}
		case 2:
		{
			system("cls");
				add_new_lesson();
		break;
		}
		case 3:{
				system("cls");
					add_new_prof();
		break;
		}
				case 4:{
					system("cls");
					report();
		break;
		}
		case 20:{
			turn = 0;
		break;
		}
		default:{
		cout<<"Enter num between (1-20)";
		continue;
		}
}
				}
			}
				else{
				cout<<"your password is wrong!";
				exit(1);
			}
			}
		case 2:
		{
			string susername = "222", spass = "222";
			cout<<"Enter username: ";
			cin>> username;
			cout<<endl;
			cout<<"Enter pass: ";
			cin>> pass;
			if(susername ==username && susername == pass){
				system("cls");
				while(1){
				cout<<"1.Show Info of Student\n 2.Booking\n 3.accept Booking 4.Class program \n 5.exam program\n 6.Scores\n 7.hozor/ghiab";
				int inputstudent;
				cin >> inputstudent;
				switch(inputstudent){
					int k;
					case 1:
					{
						for(int i=0 ; i<stus.size(); i++){
							if(stus[i].get_id()== susername)
							{
								k = i;
							}
							else {
								cout<<"not found!";
							}
							stus[k].print();
						}
						
						break;
					}
					case 2:{
						break;
					}
					default:
					{
						cout<<"Enter numb (1-7)";
						continue;
					}
				}
				}
			}
			else{
					system("cls");
					cout<<"Wrong!";
					exit(1);
				}
			break;
		}
	
	}
	}

//	booking book1;
//	book1.select_lessons(stu);
//	
	for(int i= 0 ; i<final_lessons.size(); i++)
		final_lessons[i].print();	
}

void add_new_lesson(){
	cout<<"Enter New lesson: ";
	bool enter=1;
	int  i=0, capacity, code, gender, time;
	string teacher;
	while(enter){
	cout<<"lessonCODE["<<i<<"]: ";
	cout<<"LessonCODE, capacity, gender, time, teacher";
	cin>> code >>capacity>> gender>> time>> teacher;
	lesson temp_lesson(code, capacity, gender , time, teacher);
	term_lessons.push_back(temp_lesson);
	cout<<"continue (1/0)?";
	i++;
	cin>>enter;			
}
}
void add_new_stu(){
	int a=1;
					while(a==1){
	string firstname, lastname, id, field;
					int enter_year, gender;
					bool status;
					cout<<"Name: "; cin >> firstname;
					cout<<"Family name: "; cin >> lastname;
					cout<<"id: "; cin >> id;
					cout<<"enter_year: "; cin >> enter_year;
					cout<<"Field: ";
					cin.ignore();
					getline(cin, field);
					cout<<"status: "; cin >> status;
					cout<<"jensiat: "; cin >> gender;
					student temp_stu(firstname, lastname, id, enter_year, field, status, gender);
					stus.push_back(temp_stu);
					cout<<"continue (1/0)?";
					cin >> a;
					}
}
void	add_new_prof(){
	cout<<"Enter New professor: ";
	bool enter=1, status;
	string firstname, lastname,  id,  field;
	while(enter){
	cout<<"Enter firstname, lastname, id,  field, status";
	cin>>firstname >> lastname >> id>> field >> status;
	professor temp_prof(firstname, lastname, id, field, status);
	profs.push_back(temp_prof);
	cout<<"continue (1/0)?";
	cin>>enter;			
}
}
void report(){
	cout<<"Professors: \n";
	cout<<"Tedad kol asatid"<<profs.size()<<endl;
	cout<<"Student: \n";
	cout<<"Tedad kol asatid"<<stus.size()<<endl;
}