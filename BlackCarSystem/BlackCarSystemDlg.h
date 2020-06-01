#include"stdafx.h"
#include "LittleTool.h"
#include "dialog1.h"
#include "dialog2.h"
#pragma once


// CBlackCarSystemDlg dialog
class CBlackCarSystemDlg : public CDialogEx{
public:
	CBlackCarSystemDlg(CWnd* pParent = NULL);	// standard constructor
	//============== the following is ready for the tan_contral================
	int m_CurSelTab;
	CTabCtrl m_tab;				//a class's munber of tab_contral
	dialog1 page1;
	dialog2 page2;
	CDialog* p_dialog[2];		//dialog's pointer to tow pages
	//========================================================================^

	enum { IDD = IDD_BLACKCARSYSTEM_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);	//called when tab_contral have been change;
};
