#include"stdafx.h"
#include"Managment.h"
#include"LittleTool.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<fstream>
#define sortbyid 0
#define sortbymath 1
#define sortbycpp 2

typedef  vector<Student>::iterator  Pointer;
using namespace std;
#pragma once

Managment::Managment(){
	location = "D:\\BlackCarDriverSystem.bin";
	if (!load) load_date();
	load = true;
	return;
}

Managment::~Managment(){
	if(!save )	save_date();
	save = true;
	return;
}

int Managment::check(int id){  //return 1 if exist it id
	return (id_number.find(id) != id_number.end());
}

Pointer Managment::find_by_id(int id){	//return the index of student with it id, check whether have such id before using it
	if (id_number.find(id) == id_number.end())	//some times dont need to traverse all the Date
		return Date.end();
	Pointer p;
	for (p = Date.begin(); p < Date.end(); p++) if (p->id == id) return p;
	return Date.end();
}

void Managment::find_by_name(vector<Pointer>&vec, string fname){	//push those student with it name into vector
	vec.clear();
	for (Pointer i = Date.begin(); i < Date.end(); i++){
		if (i->name == fname) vec.push_back(i);
	}
	return;
}

int Managment::add_date(argument){  //return 1 if push_back succeedly
	int size = Date.size();
	Date.push_back({ name, adress, gender, id, age, math, cpp });
	id_number.insert(id);
	return (Date.size() > size);
}

int Managment::remove_date(Pointer r){		//return 1 if remove succeed.
	if (r == Date.end()) return -1;			// can't find r in Date
	int size = Date.size();
	id_number.erase(r->id);		//notice that if date.erase(r), r will become useless, then use r is worng!! 
	Date.erase(r);
	return (size > Date.size());			//if remore r succeed return 1
}

int Managment::erase_date(Pointer p, argument){		//return 1 if erase succeed.
	//notice that if id is allow to changed, it need to add some code
	if (p == Date.end()) return -1;
	p->reset(name, adress, gender, id, age, math, cpp);
	return 1;
}

int Managment::load_date(){			// loading the date form local file to program , return 0 if can't not open the file
	ifstream ifs(location, ios::binary);
	if (ifs.fail()) return 0;
	int size = 0;
	memset(cpp_score.score, 0, sizeof(cpp_score.score));
	memset(math_score.score, 0, sizeof(math_score.score));
	Student temp;
	ifs.read((char*)&size, sizeof(int));
	for (int i = 0; i < size; i++){
		ifs.read((char*)&temp, sizeof(Student));
		Date.push_back({ temp.name, temp.adress, temp.gander, temp.id, temp.age, temp.math, temp.cpp });
		id_number.insert(temp.id);	// id_munber init in it time;
		int cppleve = (temp.cpp == 100 ? 4 : temp.cpp / 20);
		int mathleve = (temp.math == 100 ? 4 : temp.math/ 20);
		cpp_score.score[cppleve]++;
		math_score.score[mathleve]++;
	}
	return 1;
}

int Managment::save_date(){			// save the date form program to local file retrn 1 if success.
	ofstream ofs(location, ios::binary);
	if (ofs.fail()) return 0;
	int size = Date.size();
	ofs.write((char*)&size, sizeof(int));
	for (int i = 0; i < size; i++){
		ofs.write((char*)&Date[i], sizeof(Student));
	}
	return 1;			//no precial meaning
}

// only use for test
int Managment::set_date(){
	Date.push_back({ "A", "aaaaaaa", 1, 1706100108, 11, 90, 99 });
	Date.push_back({ "B", "aaaaaaa", 1, 1706100118, 14, 34, 34 });
	Date.push_back({ "c", "aaaaaaa", 1, 1706100208, 15, 77, 44 });
	Date.push_back({ "d", "aaaaaaa", 1, 1706100668, 16, 60, 44 });
	Date.push_back({ "e", "aaaaaaa", 1, 1706100338, 12, 30, 55 });
	Date.push_back({ "f", "aaaaaaa", 1, 1706100111, 19, 10, 32 });
	Date.push_back({ "g", "aaaaaaa", 1, 1706100199, 13, 30, 23 });
	Date.push_back({ "h", "aaaaaaa", 1, 1706100112, 13, 60, 88 });
	Date.push_back({ "i", "aaaaaaa", 1, 1706100133, 13, 90, 44 });
	return 0;
}

//sort the Date by three different ways
void Managment::DateSort(int a){
	if (a == (sortbyid)){
		sort(Date.begin(), Date.end(), [](const Student &a, const Student &b){return a.id > b.id; });
	}
	else if (a == (sortbymath)){
		sort(Date.begin(), Date.end(), [](const Student &a, const Student &b){
			if (a.math != b.math) return (a.math > b.math);
			else return (a.cpp > b.cpp);
		});
	}
	else if (a == (sortbycpp)){
		sort(Date.begin(), Date.end(), [](const Student &a, const Student &b){
			if (a.cpp != b.cpp) return (a.cpp > b.cpp);
			else return (a.math > b.math);
		});
	}
}

Pointer Managment::get_end(){
	return Date.end();
}

// the following is static munber of Management class
vector<Student> Managment::Date;		
set<int> Managment::id_number;	
bool Managment::load = false;
bool Managment::save = false;
score_date Managment::math_score;
score_date Managment::cpp_score;