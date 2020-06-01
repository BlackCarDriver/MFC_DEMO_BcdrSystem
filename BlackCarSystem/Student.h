#include"stdafx.h"
#include<string>
using namespace std;
#define SmallSize 30
#define BigSize 200
#pragma once

class Student{
public:
	char name[SmallSize];
	char adress[BigSize];
	int gander;		// 0 behalf boy and 1 behalf girl
	int id;			//1000000000 ~ 30000000000
	int age;		// only accept 0 ~ 140(include)
	double math;	//0.0 ~ 100.0
	double cpp;		//0.0 ~ 100.0
	Student();
	Student (string name, string adress, int gender, int id, int age, double math, double cpp);
	string tostring();
	void reset(string name, string adress, int gender, int id, int age, double math, double cpp);
};