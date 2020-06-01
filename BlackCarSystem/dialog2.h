#include "afxwin.h"
#include"LittleTool.h"
#include"Managment.h"
#include<vector>;
#pragma once
// dialog2 dialog

class dialog2 : public CDialogEx
{
	DECLARE_DYNAMIC(dialog2)
	LittleTool Tool;
	vector<Pointer> SameNameStudent;
	Pointer showing;		//the student which is showing, asinged in fresh(Pointer);

	void refresh(Pointer);		//show the precial student date to edit box contral
	void clear();			//clear the edit box that show the student date.
	void update_name_munber(int, int);
	void change_button_state(int);
	int index_of_name;		//the index of SameNameStudent include 0 to SamNameStudent.end()-1
	int get_edit();
public:
	Managment Manage;

	dialog2(CWnd* pParent = NULL);   // standard constructor
	virtual ~dialog2();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	CComboBox combobox2;
	int gander2;
	CString name2;
	long id2;
	int age2;
	double math2;
	double cpp2;
	BOOL group2;		//kind of sceach method 0-name, 1-id
	afx_msg void OnBnClickedButton3();
	CString find_name;	// use a CString to record name and id
	CString adress2;
	CString csfraction;
	afx_msg void OnBnClickedprestu();
	afx_msg void OnBnClickedprestu2();
	afx_msg void OnBnClickedRemove2();
	afx_msg void OnBnClickedUpdate2();
	afx_msg void OnBnClickedcancel2();
	afx_msg void OnBnClickedcreat();
	CListBox graphbox;		//listbox
	afx_msg void OnBnClickedgraph2();
	afx_msg void OnBnClickedgraph1();
};
