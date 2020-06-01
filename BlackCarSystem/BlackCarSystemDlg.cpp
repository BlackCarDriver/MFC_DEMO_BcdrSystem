
// BlackCarSystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BlackCarSystem.h"
#include "BlackCarSystemDlg.h"
#include "afxdialogex.h"
#include "dialog1.h"
#include "dialog2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//=================================the following is "about_dilog" class===========
// the class of the dialog that press 'about' then show
class CAboutDlg : public CDialogEx{
public:
	CAboutDlg();
	enum { IDD = IDD_ABOUTBOX };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    

protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD){		

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX){
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

 //==========================================================================^ 





// ===============the following is mainly dialog class=======================

CBlackCarSystemDlg::CBlackCarSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBlackCarSystemDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}  

void CBlackCarSystemDlg::DoDataExchange(CDataExchange* pDX){
	DDX_Control(pDX, IDC_TAB, m_tab);			//...
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBlackCarSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CBlackCarSystemDlg::OnTcnSelchangeTab)
END_MESSAGE_MAP()

// ==================================================================^



//this funtion is use for init the dialog and only call one times....
BOOL CBlackCarSystemDlg::OnInitDialog(){		// OnInitDiaoh()
	CDialogEx::OnInitDialog();

//---------------   the following is ready for the tap_contral--------------
	m_tab.InsertItem(0, _T("Add Date"));
	m_tab.InsertItem(1, _T("Find date"));		//add tow page of tab contral
	page1.Create(IDD_DIALOG1, &m_tab);
	page2.Create(IDD_DIALOG2, &m_tab);			//create two  dialog in tab contral
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	page1.MoveWindow(&rc);
	page2.MoveWindow(&rc);
	p_dialog[0] = &page1;
	p_dialog[1] = &page2;
	p_dialog[0]->ShowWindow(SW_SHOW);
	p_dialog[1]->ShowWindow(SW_HIDE);
	m_CurSelTab = 0;
// ------------------------------------------------------------------------^
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}


//it funtion will called when the user selects a command from the control menu
void CBlackCarSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

//it funtion called when it need to refresh the window of program
void CBlackCarSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//query the message of mouse's icon when dray the mouse in to Cwnd
HCURSOR CBlackCarSystemDlg::OnQueryDragIcon()
{	
	return static_cast<HCURSOR>(m_hIcon);
}

void CBlackCarSystemDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult){		//when tab_contral have been choice
	p_dialog[m_CurSelTab]->ShowWindow(SW_HIDE);  //Hide the dialog
	m_CurSelTab = m_tab.GetCurSel();			//change a new page
	p_dialog[m_CurSelTab]->ShowWindow(SW_SHOW);	//show the diaslog 
	m_CurSelTab = m_tab.GetCurSel();
	*pResult = 0;
}
