#include"stdafx.h"
#include<string>
using namespace std;
#define height 13
#define wide 44
#pragma once

struct grap_str{
	string grap[height+1];
};


class LittleTool{
public:
	LittleTool();
	string fraction(int, int); //make a fraction by two integer
	void testmessage();
	CString stocs(string a);	//string to CString
	string cstos(CString);		//CString to string
	int cstoi(CString);			//CString to int
	void success(int);			//use Messagebox to show the result
	//the string array that put int listbox
	grap_str make_grap_str(int a,int b,int c,int e,int f);	
};

