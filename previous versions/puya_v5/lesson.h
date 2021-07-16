#pragma once
#include <iostream>
#include <string>
using namespace std;

class lesson{

public:
	int code;
	int capacity;
	//جنیست
	// مرد = 2 و زن = 1 و هر دو = 0
	int gender;
	int time;
	string teacher;
	
	lesson(int code ,int capacity, int gender, int time, string teacher);
	lesson();
	check();
	void print();
};
