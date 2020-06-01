#include"stdafx.h"
#include"Student.h"
#include<string>
#include<string.h>
using namespace std;
#pragma once

Student::Student(string name, string adress, int gender, int id, int age, double math, double cpp){
	strcpy_s(this->name, SmallSize, name.substr(0, SmallSize - 1).c_str());
	strcpy_s(this->adress, SmallSize, adress.substr(0, BigSize - 1).c_str());
	this->gander = gender;
	this->id = id;
	this->age = age;
	this->math = math;
	this->cpp = cpp;
	return;
}

Student::Student(){ } //Null

//erase the student message
void Student::reset(string name, string adress, int gender, int id, int age, double math, double cpp){
	strcpy_s(this->name, SmallSize, name.substr(0, SmallSize - 1).c_str());
	strcpy_s(this->adress, SmallSize, adress.substr(0, BigSize - 1).c_str());
	this->gander = gender;
	this->id = id;
	this->age = age;
	this->math = math;
	this->cpp = cpp;
	return;
}

// return the message format: 1705100108  balckcardriver  20  male  100.0  100.0  guangzhoudaxue
string Student::tostring(){
	string temp = string(220,' ');
	string tid = "id: " + (to_string(id));
	string tname = "name: " + string(name);
	string tage = "age: " + to_string(age);
	string tgander = "gander: " + string((gander == 0 )? "male" : "female");
	string tcpp = "cpp: " + to_string(cpp).substr(0,5);
	string tmath = "math: " + to_string(math).substr(0,5);
	string tadree = "adress: " + string(adress);
	temp.insert(3, tid);
	temp.insert(25, tname);
	temp.insert(55, tage);
	temp.insert(70, tgander);
	temp.insert(90, tcpp);
	temp.insert(110, tmath);
	temp.insert(130, tadree);
	return temp.substr(0,160);
}