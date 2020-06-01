#include "afxwin.h"
#include"LittleTool.h"
#include"Managment.h"
#pragma once

// dialog1 dialog

class dialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(dialog1)

	void refresh();		//update the student student_munber and list box's date
	int get_edit();		//check and update the date in edit contral if ok than return 1;
public:
	LittleTool Tool;
	Managment Manage;
	int gander = 0;  //0 behalf boy and 1 behalf girl
	dialog1(CWnd* pParent = NULL);   // standard constructor
	virtual ~dialog1();
// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox combobox;
	CString name;
	long id;
	int age;
	double math;
	double cpp;
	afx_msg void OnBnClickedButton2();
	int student_munber;
	CListBox listbox;
	afx_msg void OnBnClickedButton1();
	CString adress;
	afx_msg void OnBnClickedButton3();
	BOOL group1;		//BOOL in MFC is int in c++
};
