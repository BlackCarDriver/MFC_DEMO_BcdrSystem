// dialog1.cpp : implementation file
#include "stdafx.h"
#include"LittleTool.h"
#include "BlackCarSystem.h"
#include "dialog1.h"
#include "afxdialogex.h"
#define faill 0
#define succed 1
IMPLEMENT_DYNAMIC(dialog1, CDialogEx)


dialog1::dialog1(CWnd* pParent /*=NULL*/)
	: CDialogEx(dialog1::IDD, pParent)
	, student_munber(0)
	, adress(_T(""))
	, group1(FALSE)
{
	
	
	
}

dialog1::~dialog1()
{

}

void dialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_gender, combobox);
	DDX_Text(pDX, IDC_name, name);
	DDV_MaxChars(pDX, name, 40);	//at more 30 character
	DDX_Text(pDX, IDC_id, id);		//1000000000 ~ 2000000000
	DDX_Text(pDX, IDC_age, age);
	DDV_MinMaxInt(pDX, age, 0, 140);
	DDX_Text(pDX, IDC_math, math);
	DDX_Text(pDX, IDC_cpp, cpp);
	DDX_Text(pDX, IDC_studnet_munber, student_munber);
	DDX_Control(pDX, IDC_listbox, listbox);
	DDX_Text(pDX, IDC_adress, adress);
	DDX_Radio(pDX, IDC_s_id, group1);
}


BEGIN_MESSAGE_MAP(dialog1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &dialog1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &dialog1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &dialog1::OnBnClickedButton3)
END_MESSAGE_MAP()



BOOL dialog1::OnInitDialog(){
	CDialogEx::OnInitDialog();
	combobox.AddString(L"meal");
	combobox.AddString(L"femeal");
	listbox.SetHorizontalExtent(1100);
	combobox.SetCurSel(1);
	refresh();
	return TRUE;
}

//refresh refresh the munber in Date and refreshe the list,useed by other funtion
void dialog1::refresh(){	
	student_munber = Manage.Date.size();
	UpdateData(false);
	listbox.ResetContent();		//clear the listbox
	for (int i = 0; i < Manage.Date.size(); i++){ //refresh the listbox
		listbox.AddString(Tool.stocs(Manage.Date[i].tostring().c_str()));
	}
	return;
}

//check and update the date in edit contral return 1 if the date is right
int dialog1::get_edit(){
	UpdateData(true);
	if (Manage.check(id)){
		MessageBox(L"There already have a student with it ip !");
		return faill;
	}
	int index = ((CComboBox*)GetDlgItem(IDC_gender))->GetCurSel();
	gander = !index;  //boy or girl
	if (name == "" || name.GetLength() >
		30 ){
		MessageBox(L"name input might uncorrect, please check.");
		return faill;
	}
	if (id < 1000000000 || id > 3000000000){
		MessageBox(L"id input might uncorrect, please check.");
		return faill;
	}
	if (age < 1 || age >140){
		MessageBox(L"age input might uncorrect, please check.");
		return faill;
	}
	if (math < 0.0 || math  >100.0){
		MessageBox(L"math score input might uncorrect, please check.");
		return faill;
	}
	if (cpp < 0.0 || cpp  >100.0){
		MessageBox(L"c++ score input might uncorrect, please check.");
		return faill;
	}
	if (adress.GetLength()<=0 || adress.GetLength() > 50){
		MessageBox(L"adress input is null or is too long, please check.");
		return faill;
	}
	return succed;	
}

//Add_date button: check the input and add a date if input is right
void dialog1::OnBnClickedButton1(){
	if (get_edit()){
		//name, adress, gender, id, age, math,  cpp
		int suc = Manage.add_date(
			Tool.cstos(name),
			Tool.cstos(adress),
			gander,
			id,
			age,
			math,
			cpp
			);
		Tool.success(1);
	}		
	return;
}


//clear button: clear the input in edit contral
void dialog1::OnBnClickedButton2(){
	name = adress = "";
	id = 0.0;
	math = 0.0;
	cpp = 0;
	age = 0;
	combobox.SetCurSel(1);
	UpdateData(FALSE);
}


// refresh button : refresh the munber in Date and refreshe the list
void dialog1::OnBnClickedButton3(){
	UpdateData(TRUE);
	Manage.DateSort(group1);	//0-by id 1-by math 2-by c++
	refresh();
}
