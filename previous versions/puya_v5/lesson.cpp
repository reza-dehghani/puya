#include "lesson.h"

lesson::lesson(int code ,int capacity, int gender, int time, string teacher){
		lesson::code = code;
		lesson::capacity = capacity;
		lesson::gender = gender;
		lesson::time = time;
		lesson::teacher = teacher;
	}

void lesson::print(){
		cout<<"LessonCODE:"<<lesson::code <<"\t";
		cout<<"capacity:"<<lesson::capacity <<"\t";
		cout<<"gender:"<<lesson::gender<<"\t";
		cout<<"time:"<<lesson::time<<"\t";
		cout<<"teacher:"<<lesson::teacher<<"\n";
	}