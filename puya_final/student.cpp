#include "student.h"
		student::student(string firstname, string lastname, string id, int enter_year, string field, bool status, int gender, vector <lesson> lessons)
		{
			person::firstname = firstname;
			person::lastname = lastname;
			person::id = id;
			student::enter_year = enter_year;
			student::field = field;
			student::status = status;
			student::gender = gender;
//			for(int i=0 ; i<20 ; i++)
			student::lessons = lessons;
		}

void student::print(){
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
		student student::create_object(){
			return student(student::firstname, student::lastname, student::id, student::enter_year, student::field, student::status, student::gender, student::lessons);
		}