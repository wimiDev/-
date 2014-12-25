// µç×è¶ÁÊýÆ÷Dlg.h : header file
//

#if !defined(AFX_DLG_H__3FEAB3BB_E974_4FA3_930D_98BCF9C56627__INCLUDED_)
#define AFX_DLG_H__3FEAB3BB_E974_4FA3_930D_98BCF9C56627__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	int FAdd();
	int FAdd(int n1,int n2,int n3,int n4);
	int Getfive();
	int Getfour();
	int Getthree();
	int Gettwo();
	int Getone();
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CComboBox	m_five;
	CComboBox	m_four;
	CComboBox	m_three;
	CComboBox	m_two;
	CComboBox	m_one;
	CString	m_out;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__3FEAB3BB_E974_4FA3_930D_98BCF9C56627__INCLUDED_)
