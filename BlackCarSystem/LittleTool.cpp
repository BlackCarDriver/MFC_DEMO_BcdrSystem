#include"stdafx.h"
#include"LittleTool.h"
#include"Managment.h"
#include"Student.h"
#include<Windows.h>
#include<iostream>
#include<string>
#define error -1

#define OTT(j) (j>=0 && j<6)
#define TTF(j) (j>=9 && j<15)
#define FTS(j) (j>=18 && j<24)
#define STE(j) (j>=27 && j<33)
#define ETT(j) (j>=36 && j<42)

using namespace std;
#pragma once

LittleTool::LittleTool(){

}

//it funtion only use for test.
void LittleTool::testmessage(){
	MessageBox(NULL,L"sucess",L"BlackCarSystem",0);
	return;
}

//change string to CString
CString LittleTool::stocs(string str){
	return (CString)str.c_str();
}

//change CString to string
string LittleTool::cstos(CString str){
	string s(CW2A(str.GetString()));
	return s.substr(0, 180); //at most 180 
}

// use messagebox to show the result or operatortion
void LittleTool::success(int i){
	if (i) MessageBox(NULL,L"Succeed !",L"Result",0);
	else MessageBox(NULL, L"Something worng happened !", L"Result", 0);
	return;
}

//change CString to int, if CString is not a munber return -1
int LittleTool::cstoi(CString cs){
	string temp = cstos(cs);
	for (int i = 0; i < temp.length(); i++)
		if (temp[i]>'9' || temp[i] < '0') return error;
	return atoi(temp.c_str());
}

//build up a fraction, a is numberator, b is denominator, then return a / b 
string LittleTool::fraction(int a, int b){
	string temp = to_string(a);
	temp += " / ";
	temp += to_string(b);
	return temp;
}


//draw a graph basis on five integer and return the string array behalf of the graph
grap_str LittleTool::make_grap_str(int a, int b, int c, int d, int e){
	char graph[height + 1][wide+1];		//height is the munber of array layer
	string str[height + 1];
	int maxlen = height;
	int length[6];
	double sum = a + b + c + d + e;
	double af = a / sum, bf = b / sum, cf = c / sum, df = d / sum, ef = e / sum;
	double maxf = max(max(af, bf), max(cf, max(df, ef)));
	length[1] = (af / maxf)*maxlen;
	length[2] = (bf / maxf)*maxlen;
	length[3] = (cf / maxf)*maxlen;
	length[4] = (df / maxf)*maxlen;
	length[5] = (ef / maxf)*maxlen;
	char s = 'o', n='`';
	for (int i = 0; i <= height; i++){
		for (int j = 0; j<wide; j++)
			graph[i][j] = n;
	}
	for (int i = 1; i < height; i++){
		for (int j = 0; j<wide; j++){
			if (OTT(j) && length[1] >= maxlen - i) graph[i][j] = s;
			if (TTF(j) && length[2] >= maxlen - i) graph[i][j] = s;
			if (FTS(j) && length[3] >= maxlen - i) graph[i][j] = s;
			if (STE(j) && length[4] >= maxlen - i) graph[i][j] = s;
			if (ETT(j) && length[5] >= maxlen - i) graph[i][j] = s;
		}
	}
	string Os = to_string(a);
	string Ss = to_string(b);
	string Ts = to_string(c);
	string Fs = to_string(d);
	string Fis = to_string(e);
	grap_str garph;
	for (int i = 0; i < height; i++){
		garph.grap[i] = "";
		garph.grap[i] = string(graph[i], wide);
	}
	for (int i = 0; i < height-1; i++){
		if (garph.grap[i][1] == n && (garph.grap[i + 1][1] == s || i+3>height)){
			garph.grap[i].replace(garph.grap[i].begin() + 1, garph.grap[i].begin()+1+Os.length(), Os.begin(), Os.end());
		}
		if (garph.grap[i][10] == n && (garph.grap[i + 1][10] == s || i+3 >height)){
			garph.grap[i].replace(garph.grap[i].begin() + 10, garph.grap[i].begin() + 10 + Os.length(), Ss.begin(), Ss.end());
		}
		if (garph.grap[i][19] == n && ( garph.grap[i + 1][19] == s || i+3 >height)){
			garph.grap[i].replace(garph.grap[i].begin() + 19, garph.grap[i].begin() + 19 + Os.length(), Ts.begin(), Ts.end());
		}
		if (garph.grap[i][28] == n && (garph.grap[i + 1][28] == s || i+3 > height)){
			garph.grap[i].replace(garph.grap[i].begin() + 28, garph.grap[i].begin() + 28 + Os.length(), Fs.begin(), Fs.end());
		}
		if (garph.grap[i][38] == n && (garph.grap[i + 1][38] == s || i+3 > height)){
			garph.grap[i].replace(garph.grap[i].begin() + 38, garph.grap[i].begin() + 38 + Os.length(), Fis.begin(), Fis.end());
		}
	}
	return garph;
}
