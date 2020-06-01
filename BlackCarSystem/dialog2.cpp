// dialog2.cpp : implementation file
#include "stdafx.h"
#include "BlackCarSystem.h"
#include "dialog2.h"
#include "afxdialogex.h"
#define error -1
#define faill 0
#define succed 1
#define unable  (Manage.get_end())

using namespace std;
#pragma once

IMPLEMENT_DYNAMIC(dialog2, CDialogEx)

dialog2::dialog2(CWnd* pParent /*=NULL*/)
: CDialogEx(dialog2::IDD, pParent)
, group2(FALSE)
, find_name(_T(""))
, adress2(_T(""))
, csfraction(_T(""))
{
	
}

dialog2::~dialog2(){}

void dialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, combobox2);
	DDX_Radio(pDX, IDC_RADIO1, group2);
	DDX_Text(pDX, IDC_EDIT1, find_name);
	DDX_Text(pDX, IDC_name2, name2);
	DDX_Text(pDX, IDC_id2, id2);
	DDX_Text(pDX, IDC_adress2, adress2);
	DDX_Text(pDX, IDC_age2, age2);
	DDX_Text(pDX, IDC_math2, math2);
	DDX_Text(pDX, IDC_cpp2, cpp2);
	DDX_Text(pDX, IDC_munber_of_name, csfraction);
	DDX_Control(pDX, IDC_graph, graphbox);
}

BEGIN_MESSAGE_MAP(dialog2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &dialog2::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_preStu, &dialog2::OnBnClickedprestu)
	ON_BN_CLICKED(IDC_nextStu, &dialog2::OnBnClickedprestu2)
	ON_BN_CLICKED(IDC_Remove2, &dialog2::OnBnClickedRemove2)
	ON_BN_CLICKED(IDC_Update2, &dialog2::OnBnClickedUpdate2)
	ON_BN_CLICKED(IDC_cancel2, &dialog2::OnBnClickedcancel2)
	ON_BN_CLICKED(IDC_creat, &dialog2::OnBnClickedcreat)
	ON_BN_CLICKED(IDC_graph2, &dialog2::OnBnClickedgraph2)
	ON_BN_CLICKED(IDC_graph1, &dialog2::OnBnClickedgraph1)
END_MESSAGE_MAP()


BOOL dialog2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	combobox2.AddString(L"meal");
	combobox2.AddString(L"femeal");
	change_button_state(0);  
	update_name_munber(0, 0);
	showing = unable;
	return TRUE; 
}

// search button : rind studnts by id or name and show then in edit box
void dialog2::OnBnClickedButton3(){	
	UpdateData(TRUE);
	Pointer TSP;			//temp student pointer, use for argument
	if (group2 == 0) {		//find by name
		SameNameStudent.clear();
		Manage.find_by_name(SameNameStudent,Tool.cstos(find_name));
		if (!SameNameStudent.empty()){
			Tool.success(1);
			index_of_name = 0;
			refresh(SameNameStudent[0]);	
			update_name_munber(1, SameNameStudent.size());
			change_button_state(1);
		}	
		else MessageBox(L"Can't find the student with it name.");
	}		
	else if (group2 == 1){		//find by id	
		change_button_state(0);
		int id = Tool.cstoi(find_name);
		if (id == error){
			MessageBox(L"ID input might wrong, pleace check.");
			return;
		}
		else{
			TSP = Manage.find_by_id(id);
			if (TSP != unable){
				refresh(TSP);
				Tool.success(1);
			}
			else MessageBox(L"Can't find the studnet with it id.");
		}
	}
	return;
}

// last_student button
void dialog2::OnBnClickedprestu(){
	if (index_of_name <= 0)
		MessageBox(L"It is already the first one.");
	else{
		index_of_name -= 1;
		refresh(SameNameStudent[index_of_name]);
		update_name_munber(index_of_name + 1, SameNameStudent.size());
	}
	return;
}

// next_student button
void dialog2::OnBnClickedprestu2(){
	if (index_of_name + 1  >= SameNameStudent.size())
		MessageBox(L"It is already the last one.");
	else{
		index_of_name += 1;
		refresh(SameNameStudent[index_of_name]);
		update_name_munber(index_of_name + 1, SameNameStudent.size());		//index is 0 mean the first student
	}
}

//reomve_button : remove the student which showing point to if showing is correct;
void dialog2::OnBnClickedRemove2(){
	if (showing >= unable){		//notice that it is unsafe if use (showing==unable)
		MessageBox(L"You cant remove a null date.");
		return;
	}
	else{	//can remove
		if (MessageBox(L"Are you sure to remove it student ?", L"BlackCarSysetm", MB_OKCANCEL) == IDCANCEL)
			return;
		//UpdateData(TRUE);
		if (Manage.remove_date(showing)){	//already remove the student frome Date
			if (group2 == 0){				//if it is search by name
				index_of_name = 0;
				SameNameStudent.clear();
				change_button_state(0);
				clear();
			}
		}
	}
	Tool.success(1);
	clear();
	showing = unable;
	return;
}

//Update button	: erase the student date which is showing in the edit box
void dialog2::OnBnClickedUpdate2(){
	if (showing == unable){
		MessageBox(L"You can't erase a null student date.");
		return;
	}
	if (MessageBox(L"Are you sure to update it student date?", L"BlackCarSysetm", MB_OKCANCEL) == IDCANCEL)
		return;
	if (get_edit()==succed){
	bool t = Manage.erase_date(showing, 
			Tool.cstos(name2),
			Tool.cstos(adress2),
			gander2,
			id2,
			age2,
			math2,
			cpp2
		);
	if (t != 1) Tool.success(0);
	else Tool.success(1);
	}
	return;
}

//cancel button	: reinti dialog2
void dialog2::OnBnClickedcancel2(){
	clear();
	showing = unable;
	SameNameStudent.clear();
	update_name_munber(0, 0);
	change_button_state(0);
	find_name = "";
	UpdateData(FALSE);
}

//show the precial student date in the edit box contral, need to make sure use it Pointer is safe 
void dialog2::refresh(Pointer stu){
	if (stu == unable) return;
	showing = stu;			//notied that showing is update in it funtion
	name2 = Tool.stocs(stu->name);
	adress2 = Tool.stocs(stu->adress);
	combobox2.SetCurSel((stu->gander == 0) ? 1 : 0);
	id2 = (long)(stu->id);
	age2 = stu->age;
	math2 = stu->math;
	cpp2 = stu->cpp;
	UpdateData(FALSE);
}

//change the state of next_button and last_button
void dialog2::change_button_state(int state){
	if (state==0){
		GetDlgItem(IDC_preStu)->EnableWindow(FALSE);
		GetDlgItem(IDC_munber_of_name)->EnableWindow(FALSE);
		GetDlgItem(IDC_nextStu)->EnableWindow(FALSE);
	}
	else{
		GetDlgItem(IDC_preStu)->EnableWindow(TRUE);
		GetDlgItem(IDC_munber_of_name)->EnableWindow(TRUE);
		GetDlgItem(IDC_nextStu)->EnableWindow(TRUE);
	}
	return;
}

//clear the edit box that show the student date, use after delete a student date.
void dialog2::clear(){
	name2 = "";
	adress2 = "";
	combobox2.SetCurSel(1);
	id2 = 0;
	age2 = 0;
	math2 = 0.0;
	cpp2 = 0.0;
	UpdateData(FALSE);
}

//get the student message after erase from the edit box
int dialog2::get_edit(){
	UpdateData(TRUE);
	int index = ((CComboBox*)GetDlgItem(IDC_gander2))->GetCurSel();
	gander2 = !index;  //boy or girl
	if (name2 == "" || name2.GetLength() >
		30){
		MessageBox(L"name input might uncorrect, please check.");
		return faill;
	}
	if (id2 < 1000000000 || id2 > 3000000000){
		MessageBox(L"id input might uncorrect, please check.");
		return faill;
	}
	if (age2 < 1 || age2 >140){
		MessageBox(L"age input might uncorrect, please check.");
		return faill;
	}
	if (math2 < 0.0 || math2  >100.0){
		MessageBox(L"math score input might uncorrect, please check.");
		return faill;
	}
	if (cpp2 < 0.0 || cpp2  >100.0){
		MessageBox(L"c++ score input might uncorrect, please check.");
		return faill;
	}
	if (adress2.GetLength() <= 0 || adress2.GetLength() > 50){
		MessageBox(L"adress input is null or is too long, please check.");
		return faill;
	}
	return succed;
}

//a is the present student, b is the total munber of students
void dialog2::update_name_munber(int a, int b){
	string fraction = Tool.fraction(a, b);
	csfraction = Tool.stocs(fraction);
	UpdateData(FALSE);
}



void dialog2::OnBnClickedcreat()
{
	graphbox.ResetContent();
	grap_str graph = Tool.make_grap_str(
		Manage.cpp_score.score[0],
		Manage.cpp_score.score[1],
		Manage.cpp_score.score[2],
		Manage.cpp_score.score[3],
		Manage.cpp_score.score[4]
		);
	for (int i = 0; i < height; i++)
		graphbox.AddString(Tool.stocs(graph.grap[i]));
	graphbox.AddString(L" 01~20        21~40       41~60      61~80      81~100");
	return;
}



// show the graph of cpp score in list box
void dialog2::OnBnClickedgraph2()
{

}

// show the graph of math score in list box
void dialog2::OnBnClickedgraph1()
{
	graphbox.ResetContent();
	grap_str graph = Tool.make_grap_str(
		Manage.math_score.score[0],
		Manage.math_score.score[1],
		Manage.math_score.score[2],
		Manage.math_score.score[3],
		Manage.math_score.score[4]
		);
	for (int i = 0; i < height; i++)
		graphbox.AddString(Tool.stocs(graph.grap[i]));
	graphbox.AddString(L" 01~20        21~40       41~60      61~80      81~100");
	return;
}
