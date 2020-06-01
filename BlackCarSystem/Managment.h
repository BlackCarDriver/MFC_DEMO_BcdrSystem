#include"stdafx.h"
#include"Student.h"
#include<string>
#include<vector>
#include<set>
using namespace std;
#define argument string name, string adress, int gender, int id, int age, double math, double cpp
typedef  vector<Student>::iterator  Pointer;
#pragma once

struct score_date{
	int score[5]; //student munber of score between 0~20 , 21~40 , 41~60 , 61~80,  81~100
};

class Managment{
	static bool load;			//if the date have been load then load equ 1
	static bool save;			//if the date have been save then save equ 1
public:
	Managment();
	~Managment();
	static score_date cpp_score;
	static  score_date math_score;
	static  set<int> id_number;	//recorde the id of student in the date already exist
	static vector<Student> Date;	//student date save in here
	string location;			// the location of the file that save and take the date
	int load_date();			// load the date from file
	int save_date();			// save the date to file
	int check(int  id);				//check whether already have a date with same id, return 1 if have
	void find_by_name(vector<Pointer>&,string name);		//fill the vector with student have it name
	Pointer find_by_id(int id);		//return the spiceled pointer or end of Date. 
	Pointer get_end();				//return the end of Date
	int add_date(argument);			//retrurn 1 if success
	int erase_date(Pointer, argument);		//erase the student Pointer point to
	int remove_date(Pointer);				//remove a student date from Date
	void test();		//use for debug
	int set_date();		//use for debug
	void DateSort(int);			//sort the Date by different methods
};
