//include class
#include "person.h"
#include "student.h"
#include "professor.h"
#include "lesson.h"
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

	vector <lesson> term_lessons;
	vector <lesson> pishnevis;
	vector <student> stus;
	vector <professor> profs;
	vector <lesson> final_lessons;
	vector <lesson> lessons;

void update_lesson();

void print_term_lessons(){
	if(term_lessons.size() == 0){
		cout<<"darsi vojood nadarad!@!";
	}
	for(int j =0; j<term_lessons.size(); j++){
		cout<<"lessonCODE[" << term_lessons[j].code <<"]: ";
		term_lessons[j].print();
	}
}

void select_lessons(student stu, int v){
	    cout<<"Select lessons from buttom with lesson CODE:\n";
		print_term_lessons();
		final_lessons.clear();
		pishnevis.clear();
		bool enter = 1;
		int k;
		while(enter){
			int tedad=0;
			bool tadakhol = 0;
			
			cin>>k;
			for(int i =0 ; term_lessons.size(); i++){
				if(k == term_lessons[i].code){
					k = i;
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
			if(pishnevis.size()>0){
			for(int h=0; h< pishnevis.size(); h++){
			if(term_lessons[k].time == pishnevis[h].time){
				tedad++;
			}
			}
			//تداخل جنسیت
			if(term_lessons[k].gender == 1 || term_lessons[k].gender == 2){
				if(term_lessons[k].gender != stu.gender)
					tadakhol = 1;
			}
			}
		
			//بررسی شرط تداخل ساعت درس
			if(tedad>1){
				cout<<"\n Error: Saat Dars entekhabi tadakhol darad!\n";
				break;
			}
			//بررسی شرط تداخل ساعت درس
			if(tadakhol == 1){
				cout<<"\n Error: jensiat entekhabi tadakhol darad!\n";
				continue;
			}
			pishnevis.push_back(term_lessons[k]);
			final_lessons.push_back(term_lessons[k]);
			stus[v].lessons.push_back(term_lessons[k]);
			cout<<"\ncontinue (1/0): ";
			cin>>enter;
		}
				// اضافه کردن دروس به وکتور دانشجو
	}

//functions
void add_new_stu();
void add_new_lesson();
void	add_new_prof();
void report();

int main()
{
	int input, login;
	int start_month, start_day;
	//INITIAL TIME
   // current date/time based on current system
   time_t now = time(0);
   tm *ltm = localtime(&now);
   // print various components of tm structure.
   int month = 1 + ltm->tm_mon;
   int day = ltm->tm_mday;
   cout << "Month: "<< month<< endl;
   cout << "Day: "<<  day << endl;
   	//END INITIAL TIME
	//Read programming Data from files
	
	//MENU
	bool turn=1, turnb=1;
	while(turn)
		{
	cout << "Welcome to The <Birjand UT Store>";
	Sleep(1000);
	cout<<system("cls");
	cout<<"Please LOGIN as: \n 1. ADMIN 2. Student 3. Professor\n";
	string username, pass;
	string cusername="1", cpass = "1";
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
			turnb = 1;
			while(turnb)
					{
						system("cls");
					cout<<"1.Add New Student\n 2.Add New lesson\n 3.Add New professor 4.Report of all roles on the system\n 5.set day % month of booking \n20.return back\n";
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
				case 5:{
				system("cls");
					cout<<"Enter month & day: \n";
					cin>>start_month;
					cin>>start_day;
		break;
		}
		case 20:{
			turnb = 0;
		continue;
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
			}
			}
break;
		case 2:
		{
			string susername, spass;
			cout<<"Enter username: ";
			cin>> susername;
			cout<<endl;
			cout<<"Enter pass: ";
			cin>> spass;
			turnb = 1;
			for(int i=0 ; i<stus.size(); i++){
					if(stus[i].get_id()== susername && stus[i].get_id() == spass)
					{
									while(turnb)
									{
				cout<<"1.Show Info of Student\n 2.Booking\n 3.accept Booking\n4.Class program \n 5.exam program\n 6.Scores\n 7.hozor/ghiab 20.return\n";
				int inputstudent;
				cin >> inputstudent;
				switch(inputstudent){
					int k;
					case 1:
					{
					system("cls");
						for(int i=0 ; i<stus.size(); i++){
							if(stus[i].get_id()== susername)
							{
								k = i;
							}
							else {
								cout<<"not found!";
							}
						}
					stus[k].print();
						break;
					}
					case 2:{
					system("cls");
					for(int v=0 ; v<stus.size(); v++){
							if(stus[v].get_id()== susername)
							{
								if(month == start_month && day == start_day)
									select_lessons(stus[v].create_object(), v);
									else
										cout<<"zaman entekhab vahaed naresida ast!";
							}
					}
						break;
					}
					case 3:{
						system("cls");
						for(int i=0 ; i<stus.size(); i++){
							if(stus[i].get_id()== susername)
							{
								for(int o=0; o<stus[i].lessons.size(); o++){
									cout<<"#" << o <<'":';
									stus[i].lessons[o].print();
									cout<<endl;
								}
								break;
							}
						}
						break;
					}
						case 4:
					{
					system("cls");
					for(int i=0 ; i<stus.size(); i++){
							if(stus[i].get_id()== susername)
							{
								for(int y=0; y<stus[i].lessons.size() ; y++)
								{
								cout<<"#" << " lesson code: " << stus[i].lessons[y].code
								<< "\tTime: " << stus[i].lessons[y].time
								<< endl;
								}
							}
					}
					break;
					}
					case 6:
					{
					system("cls");
					for(int i=0 ; i<stus.size(); i++){
							if(stus[i].get_id()== susername)
							{
								for(int y=0; y<stus[i].lessons.size() ; y++)
								{
								cout<<"#" << " lesson code: " << stus[i].lessons[y].code
								<< "\tScore: " << stus[i].lessons[y].score
								<< endl;
								}
							}
					}
					break;
					}
			case 20:{
			turnb = 0;
		continue;
		}
					default:
					{
					system("cls");
						cout<<"Enter numb (1-7)";
						continue;
					}
				}
				}
				}
			else{
					system("cls");
					cout<<"Wrong username or password!";
					continue;
				}
			break;
		}
		}
break;
	case 3:{
			string pusername, ppass;
			cout<<"Enter username: ";
			cin>> pusername;
			cout<<endl;
			cout<<"Enter pass: ";
			cin>> ppass;
			turnb = 1;
			for(int i=0 ; i<profs.size(); i++){
					if(profs[i].get_id()== pusername && profs[i].get_id() == ppass)
						{
					while(turnb)
									{
				system("cls");
				cout<<"1.submit scores\n 20.return\n";
				int inputprof;
				cin >> inputprof;
				switch(inputprof){
					case 1:
					{
						system("cls");
						cout<<"enter scores: \n";
							for(int i=0 ; i<profs.size(); i++){
								if(profs[i].get_id() == pusername){
							for(int f=0 ; f<stus.size(); f++){
								for(int y=0; y<stus[i].lessons.size() ; y++){
										if(stus[f].lessons[y].teacher == profs[i].print_name())
								{
								cout<<"#" << " lesson code: " << stus[i].lessons[y].code
								<< " Student name: " << stus[i].get_name()
								<< "\score: ";
								cin>>stus[i].lessons[y].score;
								cout<< endl;
								}
							}
					}
								}
						break;
					}
	}
		case 20:{
			turnb = 0;
		continue;
		}
					}
				}
				}
				}
						}
	}
		}
}


void add_new_lesson()
{
	int score =0;
	cout<<"Enter New lesson: ";
	bool enter=1;
	int  i=0, capacity, code, gender, time;
	string teacher;
	while(enter){
	cout<<"lessonCODE["<<i<<"]: ";
	cout<<"LessonCODE, capacity, gender, time, teacher";
	cin>> code >>capacity>> gender>> time>> teacher;
	lesson temp_lesson(code, capacity, gender , time, teacher, score);
	term_lessons.push_back(temp_lesson);
	cout<<"continue (1/0)?";
	i++;
	cin>>enter;			
}
}
void add_new_stu(){
	int a=1, t=0;
					while(a==1){
	string firstname, lastname, id, field;
					int enter_year, gender;
					bool status;
					cout<<"id: "; cin >> id;
					t=0;
						for(int i=0 ; i<stus.size(); i++){
							if(stus[i].get_id()== id)
							{
								cout<<"ID tekrari mibashad!";
								t =1;
							}
						}
						if(t==1)
							continue;
					cout<<"Name: "; cin >> firstname;
					cout<<"Family name: "; cin >> lastname;
					cout<<"enter_year: "; cin >> enter_year;
					cout<<"Field: ";
					cin.ignore();
					getline(cin, field);
					cout<<"status: "; cin >> status;
					cout<<"jensiat: "; cin >> gender;
					student temp_stu(firstname, lastname, id, enter_year, field, status, gender, lessons);
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