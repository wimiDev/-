// 电阻读数器Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "电阻读数器.h"
#include "电阻读数器Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	int Getfive();
	int Getfour();
	int Getthree();
	int Gettwo();
	int Getone();
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_out = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_COMBO5, m_five);
	DDX_Control(pDX, IDC_COMBO4, m_four);
	DDX_Control(pDX, IDC_COMBO3, m_three);
	DDX_Control(pDX, IDC_COMBO2, m_two);
	DDX_Control(pDX, IDC_COMBO1, m_one);
	DDX_Text(pDX, IDC_OUT, m_out);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnOk() 
{
	/*获取用户输入数据*/
	int t1,t2,t3,t4,t5;
	CString range="";
	t1=Getone();
	t2=Gettwo();
	t3=Getthree();
	t4=Getfour();
	t5=Getfive();
	if(t5==1)
	{
		range="+-1";
	}
			else if(t5==2)
		{
			range="+-2";
		}
		else if(t5==5)
		{
			range="+-0.5";
		}
		else if(t5==6)
		{
			range="+-0.25";
		}
		else if(t5==7)
		{
			range="+-0.1";
		}
		else if(t5==10)
		{
			range="+-5";
		}
		else if(t5==11)
		{
			range="+-10";
		}
	
	
	m_out.Format("%d欧<%s>",FAdd(t1,t2,t3,t4),range);
UpdateData(FALSE);
}

int CMyDlg::Getone()
{/*获取第一环*/
	CString Snum1="";
	int num1=0;
GetDlgItem(IDC_COMBO1)->GetWindowText(Snum1);

if(Snum1=="黑")
	{
	num1=0;
	}
 if(Snum1=="棕")
	{
		num1=1;
	}
if(Snum1=="红")
	{
	num1=2;
	}
 if(Snum1=="橙")
	{
		num1=3;
	}
if(Snum1=="黄")
	{
	num1=4;
	}
 if(Snum1=="绿")
	{
		num1=5;
	}if(Snum1=="蓝")
	{
	num1=6;
	}
 if(Snum1=="紫")
	{
		num1=7;
	}
if(Snum1=="灰")
	{
	num1=8;
	}
 if(Snum1=="白")
	{
		num1=9;
	}
 return num1;


}

int CMyDlg::Gettwo()
{/*获取第二环*/
	CString Snum2="";
	int num2=0;
GetDlgItem(IDC_COMBO2)->GetWindowText(Snum2);

if(Snum2=="黑")
	{
	num2=0;
	}
 if(Snum2=="棕")
	{
		num2=1;
	}
if(Snum2=="红")
	{
	num2=2;
	}
 if(Snum2=="橙")
	{
		num2=3;
	}
if(Snum2=="黄")
	{
	num2=4;
	}
 if(Snum2=="绿")
	{
		num2=5;
	}if(Snum2=="蓝")
	{
	num2=6;
	}
 if(Snum2=="紫")
	{
		num2=7;
	}
if(Snum2=="灰")
	{
	num2=8;
	}
 if(Snum2=="白")
	{
		num2=9;
	}
 return num2;

}

int CMyDlg::Getthree()
{
/*获取第三环*/
	CString Snum3="";
	int num3=0;
	GetDlgItem(IDC_COMBO3)->GetWindowText(Snum3);

if(Snum3=="黑")
	{
	num3=0;
	}
 if(Snum3=="棕")
	{
		num3=1;
	}
if(Snum3=="红")
	{
	num3=2;
	}
 if(Snum3=="橙")
	{
		num3=3;
	}
if(Snum3=="黄")
	{
	num3=4;
	}
 if(Snum3=="绿")
	{
		num3=5;
	}if(Snum3=="蓝")
	{
	num3=6;
	}
 if(Snum3=="紫")
	{
		num3=7;
	}
if(Snum3=="灰")
	{
	num3=8;
	}
 if(Snum3=="白")
	{
		num3=9;
	}
 return num3;

}

int CMyDlg::Getfour()
{/*获取第四环*/
	CString Snum4="";
	int num4=0;
GetDlgItem(IDC_COMBO4)->GetWindowText(Snum4);

if(Snum4=="黑")
	{
	num4=0;
	}
 if(Snum4=="棕")
	{
		num4=1;
	}
if(Snum4=="红")
	{
	num4=2;
	}
 if(Snum4=="橙")
	{
		num4=3;
	}
if(Snum4=="黄")
	{
	num4=4;
	}
 if(Snum4=="绿")
	{
		num4=5;
	}if(Snum4=="蓝")
	{
	num4=6;
	}
 if(Snum4=="紫")
	{
		num4=7;
	}
if(Snum4=="灰")
	{
	num4=8;
	}
 if(Snum4=="白")
	{
		num4=9;
	}
 return num4;

}

int CMyDlg::Getfive()
{/*获取第五环*/
CString Snum5="";
int num5=0;
GetDlgItem(IDC_COMBO5)->GetWindowText(Snum5);

if(Snum5=="黑")
	{
	num5=0;
	}
 if(Snum5=="棕")
	{
		num5=1;
	}
if(Snum5=="红")
	{
	num5=2;
	}
 if(Snum5=="橙")
	{
		num5=3;
	}
if(Snum5=="黄")
	{
	num5=4;
	}
 if(Snum5=="绿")
	{
		num5=5;
	}if(Snum5=="蓝")
	{
	num5=6;
	}
 if(Snum5=="紫")
	{
		num5=7;
	}
if(Snum5=="灰")
	{
	num5=8;
	}
 if(Snum5=="白")
	{
		num5=9;
	}
 if(Snum5=="金")
 {
	 num5=10;
 }
 if(Snum5=="银")
 {
	 num5=11;
 }
return num5;

}

int CMyDlg::FAdd(int n1,int n2,int n3,int n4)
{
	long int temp=1,sum;
	n1=n1*100;
	n2=n2*10;
	for(int i=1;i<=n4;i++)
	{
		temp=temp*10;
	}
	sum=(n1+n2+n3)*temp;
	return sum;

}
