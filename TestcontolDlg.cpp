// TestcontolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Testcontol.h"
#include "TestcontolDlg.h"

#include "stdio.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestcontolDlg dialog




CTestcontolDlg::CTestcontolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestcontolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
//	m_colorEditBK=RGB(0,255,255);
//	m_pEditBkBrush = new CBrush(RGB(0,0,0));
}

void CTestcontolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestcontolDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CTestcontolDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTestcontolDlg::OnBnClickedCancel)
	ON_MESSAGE(MYWM_SELECTOPTION,&CTestcontolDlg::selectoption)
	ON_BN_CLICKED(IDC_BUTTONStartTrain, &CTestcontolDlg::OnBnClickedButtonstarttrain)
	ON_BN_CLICKED(IDC_BUTTONRetry, &CTestcontolDlg::OnBnClickedButtonretry)
END_MESSAGE_MAP()


// CTestcontolDlg message handlers

BOOL CTestcontolDlg::OnInitDialog()
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
//	m_rect=new CRect();
	GetClientRect(&m_rect);
	CMyEdit *editquestion,*editoption1,*editoption2;
	editquestion=new CMyEdit();
	editoption1=new CMyEdit();
	editoption2=new CMyEdit();
	CRect rectquestion(questionposition);
	CRect rectoption1(option1position);
	CRect rectoption2(option2position);
	editquestion->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP |ES_AUTOHSCROLL|ES_MULTILINE|ES_CENTER  ,rectquestion,this,IDC_EDITQUESTION);
	editoption1->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP |ES_AUTOHSCROLL|ES_MULTILINE|ES_CENTER  ,rectoption1,this,IDC_EDITOPTION1);//|WS_BORDER
	editoption2->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP |ES_AUTOHSCROLL|ES_MULTILINE |ES_CENTER,rectoption2,this,IDC_EDITOPTION2);
	
	///////reward show using CRichEdit
	/*CRect rectreward(reward1position);
	CRichEditCtrl *editreward;
	editreward=new CRichEditCtrl();
	editreward->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP |ES_AUTOHSCROLL|ES_MULTILINE,rectreward,this,IDC_EDITREWARD);
	editreward->SetWindowTextW(_T("$1000\r\n$900\r\n$800\r\n$700\r\n$600\r\n$500\r\n$400\r\n$300\r\n$200\r\n$100\r\n Your Score"));
	
	CHARFORMAT cfm;  
	editreward->SetSel(0,-1);
	editreward->GetSelectionCharFormat(cfm);
	cfm.crTextColor   = rewardtext;     //set   the   color   here 
	cfm.yHeight=200;
	cfm.dwMask   =  CFM_COLOR|CFM_SIZE;
	//strcpy(cfm.szFaceName,_T("Arial"));//设置字体
	editreward->SetSelectionCharFormat(cfm);
	editreward->SetBackgroundColor(FALSE,rewardbk);
	rewardindex=trialtotal;
	///set $0
	int lineStart = editreward->LineIndex(rewardindex);//取第11行的第一个字符的索引 
	int lineEnd = editreward->LineIndex(rewardindex+1)-1;//取第11行的最后一个字符的索引——用第12行的第一个索引减1来实现
	cfm.crTextColor   = chooserewardtext; 
	editreward->SetSel(lineStart,lineEnd);
	cfm.dwMask   =  CFM_COLOR;
	editreward->SetSelectionCharFormat(cfm);*/

	//////////////////////reward edit using CMyEdit::CEdit
	CRect rectreward(reward1position);
	CMyEdit *editreward1;
	editreward1=new CMyEdit();
	editreward1->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD1);
	editreward1->SetWindowTextW(_T("$100"));

	CMyEdit *editreward2;
	CMyEdit *editreward3;
	CMyEdit *editreward4;
	CMyEdit *editreward5;
	CMyEdit *editreward6;
	CMyEdit *editreward7;
	CMyEdit *editreward8;
	CMyEdit *editreward9;
	CMyEdit *editreward10;
	CMyEdit *editreward11;
	CMyEdit *editreward12;
	CMyEdit *editreward13;
	CMyEdit *editreward14;
	CMyEdit *editreward15;

	editreward2=new CMyEdit();
	editreward3=new CMyEdit();
	editreward4=new CMyEdit();
	editreward5=new CMyEdit();
	editreward6=new CMyEdit();
	editreward7=new CMyEdit();
	editreward8=new CMyEdit();
	editreward9=new CMyEdit();
	editreward10=new CMyEdit();
	editreward11=new CMyEdit();
	editreward12=new CMyEdit();
	editreward13=new CMyEdit();
	editreward14=new CMyEdit();
	editreward15=new CMyEdit();


	rectreward.SetRect(reward2position);
	editreward2->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD2);
	rectreward.SetRect(reward3position);
	editreward3->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD3);
	rectreward.SetRect(reward4position);
	editreward4->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD4);
	rectreward.SetRect(reward5position);
	editreward5->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD5);
	rectreward.SetRect(reward6position);
	editreward6->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD6);
	rectreward.SetRect(reward7position);
	editreward7->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD7);
	rectreward.SetRect(reward8position);
	editreward8->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD8);
	rectreward.SetRect(reward9position);
	editreward9->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD9);
	rectreward.SetRect(reward10position);
	editreward10->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD10);
	rectreward.SetRect(reward11position);
	editreward11->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD11);
	rectreward.SetRect(reward12position);
	editreward12->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD12);
	rectreward.SetRect(reward13position);
	editreward13->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD13);
	rectreward.SetRect(reward14position);
	editreward14->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD14);
	rectreward.SetRect(reward15position);
	editreward15->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE|ES_CENTER ,rectreward,this,IDC_EDITREWARD15);

	editreward2->SetWindowTextW(_T("$200"));
	editreward3->SetWindowTextW(_T("$300"));
	editreward4->SetWindowTextW(_T("$500"));
	editreward5->SetWindowTextW(_T("$1000"));
	editreward6->SetWindowTextW(_T("$2000"));
	editreward7->SetWindowTextW(_T("$4000"));
	editreward8->SetWindowTextW(_T("$8000"));
	editreward9->SetWindowTextW(_T("$16000"));
	editreward10->SetWindowTextW(_T("$32000"));
	editreward11->SetWindowTextW(_T("$64000"));
	editreward12->SetWindowTextW(_T("$125000"));
	editreward13->SetWindowTextW(_T("$250000"));
	editreward14->SetWindowTextW(_T("$500000"));
	editreward15->SetWindowTextW(_T("$1 MILLION"));





	


	//////////////////Instruction Show
	CRect rectinstruction(instructionposition);
	CMyEdit *editinstruction;
	editinstruction=new CMyEdit();
	editinstruction->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP|ES_MULTILINE,rectinstruction,this,IDC_EDITINSTRUCTION);
	editinstruction->SetWindowTextW(_T("1 -Think 'change' to change choice.\r\n2 - Relax for 3 seconds to confirm choice.\r\n3- Blue:Current choice.\r\n    Orange:Your final answer\r\n    Green:Correct answer."));

//  创建字体
	CFont *fontText;
	fontText=   new   CFont();   
	fontText->CreateFont(20,15,0,0,400,FALSE,FALSE,0,ANSI_CHARSET,   
	OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,   
	DEFAULT_PITCH|FF_SWISS,_T("Copperplate Gothic"));
	editquestion->SetFont(fontText);
	editoption1->SetFont(fontText);
	editoption2->SetFont(fontText);

	CFont *fontTextInstruction   =   new   CFont(); 
	fontTextInstruction->CreateFont(16,4,0,0,400,FALSE,FALSE,0,ANSI_CHARSET,   
	OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,   
	DEFAULT_PITCH|FF_SWISS,_T("Copperplate Gothic"));
	editinstruction->SetFont(fontTextInstruction);

	CFont *fontTextReward   =   new   CFont(); 
	fontTextReward->CreateFont(20,10,0,0,400,FALSE,FALSE,0,ANSI_CHARSET,   
	OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,   
	DEFAULT_PITCH|FF_SWISS,_T("Copperplate Gothic Bold"));
	editreward1->SetFont(fontTextReward);
	editreward2->SetFont(fontTextReward);
	editreward3->SetFont(fontTextReward);
	editreward4->SetFont(fontTextReward);
	editreward5->SetFont(fontTextReward);
	editreward6->SetFont(fontTextReward);
	editreward7->SetFont(fontTextReward);
	editreward8->SetFont(fontTextReward);
	editreward9->SetFont(fontTextReward);
	editreward10->SetFont(fontTextReward);
	editreward11->SetFont(fontTextReward);
	editreward12->SetFont(fontTextReward);
	editreward13->SetFont(fontTextReward);
	editreward14->SetFont(fontTextReward);
	editreward15->SetFont(fontTextReward);

	

	////////useless
	/*CClientDC dc(this);
	CBrush br(RGB(255,0,0));
	dc.SelectObject(&br);
	dc.SetBkColor(RGB(0,0,255));
	dc.SetBkMode(TRANSPARENT);*/
	m_bmp.LoadBitmap(IDB_BITMAP3);
	bkchangecount=0;
	m_bmp2.LoadBitmapW(IDB_BITMAP4);

	ShowWindow(SW_SHOWMAXIMIZED); 

	FILE *fques,*foption1,*foption2,*fanswer;
	fques=fopen("question.txt","r");
	foption1=fopen("option1.txt","r");
	foption2=fopen("option2.txt","r");
	fanswer=fopen("answer.txt","r");
	for(int i=0;i<trialtotal;i++)
	{
		fgets(question[i],30,fques);
		fgets(option1[i],30,foption1);
		fgets(option2[i],30,foption2);
		fgets(answer[i],3,fanswer);
	}
	fclose(fques);
	fclose(foption1);
	fclose(foption2);
	fclose(fanswer);
	trialnum=0;
	CString str=(CString)question[trialnum];
	editquestion->SetWindowTextW((LPCTSTR)str);
	str=(CString)option1[trialnum];
	editoption1->SetWindowTextW((LPCTSTR)str);
	str=(CString)option2[trialnum];
	editoption2->SetWindowTextW((LPCTSTR)str);
	TrainingTag=false;
	TrainingIdleTag=false;
	TrainingUpTag=false;
	TrainingDownTag=false;
	UnfinishedTag=true;
	ShiftColorTag=false;
	SelectColorTag=false;
	RightAnswerColorTag=false;
	IncreaseIndexTag=false;
	updatequestionTag=false;
	RewardInstructionTag=false;
	changebkTag=false;
	selectanswer=0;
	totalreward=0;
	correctanswer=atoi(answer[trialnum]);


	////////////////////emotiv code
	eEvent= EE_EmoEngineEventCreate();
	eState= EE_EmoStateCreate();

	if (EE_EngineConnect() != EDK_OK) 
	{
		TCHAR array[]= _T("Emotiv Engine start up failed");
		CString str;
		str.Format(_T("%s"), array);
		AfxMessageBox(str);
	}
	else
	{
		hData = EE_DataCreate();
		secs=1;
		EE_DataSetBufferSizeInSec(secs);
		userID=0;
		readytocollect = true;
		readytoanalysis=false;
		targetChannel=ED_FC5;
		lastsample=0;
		statethreshod=0;
		meanIdle=0;
		meanUp=0;
		meanDown=0;
		meanNonIdle=0;
		currentoption=0;
		lastoption=0;
		optionduration=0;;


		//Start the Emotiv read data thread 

	//	m_hThEmotivReadData=AfxBeginThread(Emotiv_ReadDataThread,this);
		m_hThEmotivReadData=CreateThread(NULL,0,Emotiv_ReadDataThread,this,FALSE,FALSE);
		m_hThEmotivAnalysisData=CreateThread(NULL,0,Emotiv_AnalysisDataThread,this,FALSE,FALSE);
		m_hEvReadytoAnalysis=CreateEvent(NULL,FALSE,FALSE,NULL);
		// set training tag;

	}





	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestcontolDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestcontolDlg::OnPaint()
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
	
		CPaintDC dc(this);
//		dc.DrawState(CPoint(0,1500), CSize(512,512), m_bmp, DST_BITMAP);
		CDialog::OnPaint();

	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestcontolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTestcontolDlg::OnSize( UINT nType,int cx,int cy)
{
	//////////////////////IDC_EDITQUESTION
	CWnd *pWnd=GetDlgItem(IDC_EDITQUESTION);
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
		CFont *font=pWnd->GetFont();
		LOGFONT logfont;
		font->GetLogFont(&logfont);
		logfont.lfWeight=logfont.lfWeight*cx/m_rect.Width();
		logfont.lfHeight=logfont.lfHeight*cy/m_rect.Height();
		m_font1.CreateFontIndirectW(&logfont);
		pWnd->SetFont(&m_font1);
	}
	//change size of character
	//CFont *font=pWnd->GetFont();
	/*LOGFONT logfont;
	font->GetLogFont(&logfont);
	logfont.lfWeight=logfont.lfWeight*cx/m_rect.Width();
	logfont.lfHeight=logfont.lfHeight*cy/m_rect.Height();
	m_font1.CreateFontIndirectW(&logfont);

	pWnd->SetFont(&m_font1);*/

	//////////////////////////////IDC_EDITOPTION1
	pWnd=GetDlgItem(IDC_EDITOPTION1);
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
		pWnd->SetFont(&m_font1);
	}
//	pWnd->SetFont(&m_font1);

	////////////////////IDC_EDITOPTION2
	pWnd=GetDlgItem(IDC_EDITOPTION2);
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
		pWnd->SetFont(&m_font1);
	}
//	pWnd->SetFont(&m_font1);

	////////////////////IDOK
	pWnd=GetDlgItem(IDOK);
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
		pWnd->SetFont(&m_font1);
	}

	


	//////////////////////IDC_EDITINSTRUCTION 
	pWnd=GetDlgItem(IDC_EDITINSTRUCTION );
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
		CFont *font=pWnd->GetFont();
		LOGFONT logfont;
		font=pWnd->GetFont();
		font->GetLogFont(&logfont);
		logfont.lfWidth=logfont.lfWidth*cx/m_rect.Width();
		logfont.lfHeight=logfont.lfHeight*cy/m_rect.Height();
		m_font2.CreateFontIndirectW(&logfont);
		logfont.lfWidth=2*logfont.lfWidth;
		logfont.lfHeight=2*logfont.lfHeight;
		m_font3.CreateFontIndirectW(&logfont);
		pWnd->SetFont(&m_font2);

	}
//	pWnd->SetFont(&m_font1);

	/*font=pWnd->GetFont();
	font->GetLogFont(&logfont);
	logfont.lfWeight=logfont.lfWeight*cx/m_rect.Width();
	logfont.lfHeight=logfont.lfHeight*cy/m_rect.Height();
	m_font2.CreateFontIndirectW(&logfont);
	pWnd->SetFont(&m_font2);*/

			//////////////////////////IDC_EDITREWARD
	pWnd=GetDlgItem(IDC_EDITREWARD1 );
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD2 );
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD3 );
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD4 );
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD5 );
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD6 );
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD7 );
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD8 );
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD9 );
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD10 );
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD11 );
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD12);
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD13);
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD14);
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	pWnd=GetDlgItem(IDC_EDITREWARD15);
	if(pWnd)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top =rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();
		pWnd->MoveWindow(rect);
	}
	GetClientRect(&m_rect);

		

	
}

HBRUSH CTestcontolDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

//		if(nCtlColor == CTLCOLOR_EDIT || nCtlColor == CTLCOLOR_BTN)
	//		pDC->SetBkMode(TRANSPARENT);  
	if(ShiftColorTag)
	{
		if(currentoption==1)
		{
			switch(pWnd->GetDlgCtrlID())
			{
			case IDC_EDITOPTION1:
					pDC->SetBkColor(shiftbk);
					pDC->SetTextColor(text);
					break;
			case IDC_EDITOPTION2:
				//	pDC->SetBkColor(optionbk);
				pDC->SetBkMode(TRANSPARENT);
				pDC->SetTextColor(text);
			}
		}
		else if(currentoption==2)
		{
			switch(pWnd->GetDlgCtrlID())
			{
			case IDC_EDITOPTION1:
					//pDC->SetBkColor(optionbk );
				pDC->SetBkMode(TRANSPARENT);
				pDC->SetTextColor(text);
					break;
			case IDC_EDITOPTION2:
					pDC->SetBkColor(shiftbk);
					pDC->SetTextColor(text);
			}
		}
	}
	else if(SelectColorTag)
	{
		if(selectanswer==1)
		{
			switch(pWnd->GetDlgCtrlID())
			{
			case IDC_EDITOPTION1:
					pDC->SetBkColor(selectbk);
					pDC->SetTextColor(text);
					break;
			case IDC_EDITOPTION2:
					//pDC->SetBkColor( optionbk  );
				pDC->SetBkMode(TRANSPARENT);
				pDC->SetTextColor(text);
			}
		}
		else if(selectanswer==2)
		{
			switch(pWnd->GetDlgCtrlID())
			{
			case IDC_EDITOPTION1:
					//pDC->SetBkColor(optionbk );
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
					break;
			case IDC_EDITOPTION2:
					pDC->SetBkColor(selectbk);
					pDC->SetTextColor(text);
			}
		}
	}
		else if(RightAnswerColorTag)
		{
			if(correctanswer==1)
			{
				if(totalreward==0)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}


				}
				if(totalreward==1)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD1:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==2)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD2:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==3)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD3:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==4)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD4:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==5)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD5:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==6)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD6:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==7)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD7:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==8)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD8:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==9)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD9:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==10)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD10:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==11)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD11:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==12)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD12:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==13)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD13:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==14)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD14:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==15)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD15:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION1:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
			}
			else if(correctanswer==2)
			{
				if(totalreward==0)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;

						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==1)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD1:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==2)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD2:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==3)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD3:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==4)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD4:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==5)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD5:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==6)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD6:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==7)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD7:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==8)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD8:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==9)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD9:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==10)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD10:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==11)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD11:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==12)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD12:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==13)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD13:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==14)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD14:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break;
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
				if(totalreward==15)
				{
					switch(pWnd->GetDlgCtrlID())
					{
						case IDC_EDITREWARD15:
							pDC->SetBkColor(rewardbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITOPTION2:
							pDC->SetBkColor(answerbk);
							pDC->SetTextColor(text);
							break;
						case IDC_EDITINSTRUCTION:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(instructionrewardtext);
							break; 
						default:
							pDC->SetBkMode(TRANSPARENT);
							pDC->SetTextColor(text);
					}
				}
			}
	}
	else if(updatequestionTag||ShowblankTag)
	{
		if(totalreward==0)
		{
			switch(nCtlColor)
			{
				case CTLCOLOR_EDIT:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==1)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD1:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==2)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD2:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==3)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD3:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==4)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD4:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==5)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD5:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==6)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD6:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==7)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD7:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==8)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD8:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==9)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD9:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==10)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD10:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==11)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD11:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==12)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD12:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==13)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD13:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==14)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD14:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
		else if(totalreward==15)
		{
			switch(pWnd->GetDlgCtrlID())
			{
				case IDC_EDITREWARD15:
					pDC->SetBkColor(rewardbk);
					pDC->SetTextColor(text);
					break;
				default:
					pDC->SetBkMode(TRANSPARENT);
					pDC->SetTextColor(text);
			}
		}
	}
	else
	{
			pDC->SetBkMode(TRANSPARENT);
			pDC->SetTextColor(text); 
	}
	hbr = m_brush;
	return hbr;
}

void CTestcontolDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//OnOK();
}

void CTestcontolDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();

	/*CPen pen(PS_SOLID,5,RGB(255,0,0));
	CPoint point[6];
	point[0].x=200;
	point[0].y=200;
	point[1].x=400;
	point[1].y=200;
	point[2].x=450;
	point[2].y=300;
	point[3].x=400;
	point[3].y=400;
	point[4].x=200;
	point[4].y=400;
	point[5].x=150;
	point[5].y=300;
	CClientDC   dc(this); 
	dc.SelectObject(&pen);
	dc.Polygon(point,6);*/
	/*CWnd *pWnd=GetDlgItem(IDC_MYEDIT1);
	CRect rect;
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(&rect);
	UpdateWindow();*/
	/*用颜色填充一块矩形
	CBrush brush(RGB(0,255,0));
	CClientDC dc(this);
	dc.SelectObject(&brush);
	CRect rect2(5,200, 450,230);
	dc.FillRect(&rect2,&brush);*/


	//另一种方法改变字体，不能立刻用在动态控件创建后
	/*CWnd *pWnd=GetDlgItem(IDC_MYEDIT1);
	CFont       *pfont       =  pWnd-> GetFont(); 
	LOGFONT       logfont; 
	pfont-> GetLogFont(&logfont); 
	logfont.lfHeight       =       -18; 
	m_font.CreateFontIndirect(&logfont); 
	pWnd-> SetFont(&m_font);*/
	/*CWnd *pWnd=GetDlgItem(IDC_EDITOPTION1);
	CRect rect;
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(&rect);
	pWnd=GetDlgItem(IDC_EDITOPTION2);
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(&rect);
	pWnd=GetDlgItem(IDC_EDITQUESTION);
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(&rect);
	UpdateWindow();*/
}
BOOL CTestcontolDlg::OnEraseBkgnd(CDC* pDC)
{
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	//test
	BITMAP hb;
	if(!changebkTag)
	{
		dc.SelectObject(&m_bmp);
		m_bmp.GetBitmap(&hb);	
	}
	else
	{
		dc.SelectObject(&m_bmp2);
		m_bmp2.GetBitmap(&hb);
	}

	//获取bitmap对象

	//获取窗口大小
	CRect rt;
	GetClientRect(&rt);
	//显示位图
	//pDC->SetBrushOrg(rt.Width()/2,rt.Height()/2);
	pDC->SetStretchBltMode(BLACKONWHITE);
	
	pDC->StretchBlt(0,0,rt.Width(),rt.Height(),&dc,0,0,hb.bmWidth,hb.bmHeight,SRCCOPY);

   return TRUE; 
}

DWORD WINAPI CTestcontolDlg::Emotiv_ReadDataThread(LPVOID pParam)
{
	 CTestcontolDlg *pthis=(CTestcontolDlg *) pParam;
	 	unsigned int nSamplesTaken;
		for(int i=0;i<pthis->buffersize;i++)
		{
			pthis->dealdata[i]=0;
			pthis->buffer[i]=0;
		}
	// TODO: Add your control notification handler code here
		while(pthis->readytocollect)
	{
		EE_DataAcquisitionEnable(pthis->userID,true);
		EE_DataUpdateHandle(pthis->userID, pthis->hData);
		EE_DataGetNumberOfSample(pthis->hData,&nSamplesTaken);
		if (nSamplesTaken != 0)
		{
			double* data = new double[nSamplesTaken];
			EE_DataGet(pthis->hData, pthis->targetChannel, data, nSamplesTaken);
			for(int i=0;i<int(nSamplesTaken);i++)
			{
				pthis->buffer[pthis->lastsample]=data[i];
				(pthis->lastsample)++;
				if(pthis->lastsample>=pthis->buffersize)
				{
					for(int j=0;j<pthis->buffersize;j++)
					{
						pthis->dealdata[j]=pthis->buffer[j];
					}
					pthis->lastsample=0;
					SetEvent(pthis->m_hEvReadytoAnalysis);
				}
			}
		}
	}
	return 0;
}
DWORD WINAPI CTestcontolDlg::Emotiv_AnalysisDataThread(LPVOID pParam)
{
	DWORD EventResult,dw=100;
	CTestcontolDlg *pthis=(CTestcontolDlg *) pParam;
	HANDLE hEvent=pthis->m_hEvReadytoAnalysis;
	double amplitude;
	int count=0;
	while(1)
	{
		count++;
		Sleep(3000);
		while(pthis->TrainingTag&&pthis->UnfinishedTag)
		{
			WaitForSingleObject(hEvent,INFINITE);
			///analysis code
			int choose=0,nchoose=0;
			amplitude=pthis->mean_fre(pthis->dealdata);
			Sleep(500);
///////////////////first method using up and down
			if(pthis->meanNonIdle>pthis->meanIdle)
			{
				if(pthis->lastoption==1)
				{
					if(amplitude>pthis->statethreshod)
					{
						pthis->ChangeTextColor(2,1);
						Sleep(2000);
						pthis->lastoption=2;
						pthis->optionduration=1;
					}
					else if(amplitude<=pthis->statethreshod)
					{
						pthis->ChangeTextColor(1,2);
						Sleep(2000);
						pthis->optionduration++;
						if(pthis->optionduration>=3)
						{
							pthis->selectanswer=1;
							//pthis->SendMessage(MYWM_SELECTOPTION,0,0);
								pthis->highlightselect(pthis->selectanswer);
								pthis->highlightanswer(pthis->selectanswer);
								pthis->trialnum++;
								if(pthis->trialnum<pthis->trialtotal)
								{
									pthis->showblank();
									pthis->shownewquestion();
								}
								else
								{
									CString str;
									switch(pthis->totalreward)
									{
									case 1:
										str=CString("Congratulations,you have got $100.");
										break;
									case 2:
										str=CString("Congratulations,you have got $200.");
										break;
									case 3:
										str=CString("Congratulations,you have got $300.");
										break;
									case 4:
										str=CString("Congratulations,you have got $500.");
										break;
									case 5:
										str=CString("Congratulations,you have got $1,000.");
										break;
									case 6:
										str=CString("Congratulations,you have got $2,000.");
										break;
									case 7:
										str=CString("Congratulations,you have got $4,000.");
										break;
									case 8:
										str=CString("Congratulations,you have got $8,000.");
										break;
									case 9:
										str=CString("Congratulations,you have got $16,000.");
										break;
									case 10:
										str=CString("Congratulations,you have got $32,000.");
										break;
									case 11:
										str=CString("Congratulations,you have got $64,000.");
										break;
									case 12:
										str=CString("Congratulations,you have got $125,000.");
										break;
									case 13:
										str=CString("Congratulations,you have got $250,000.");
										break;
									case 14:
										str=CString("Congratulations,you have got $500,000.");
										break;
									case 15:
										str=CString("Congratulations,you have got $1MILLION.");
									}
									FILE *record;
									record=fopen("record of zhou.txt","at+");
								//	fseek(record,0L,2);
									fprintf(record,"\n%d	%f	%f	%f\n",pthis->totalreward,pthis->meanIdle,pthis->meanNonIdle,pthis->statethreshod);
									fclose(record);
									AfxMessageBox(str);
									pthis->UnfinishedTag=false;
								}
							pthis->optionduration=0;
							pthis->lastoption=1;
						}
					}
				}
				else if(pthis->lastoption!=1)
				{
					if(amplitude>pthis->statethreshod)
					{
						pthis->ChangeTextColor(1,2);
						Sleep(2000);
						pthis->lastoption=1;
						pthis->optionduration=1;
					}
					else if(amplitude<=pthis->statethreshod)
					{
						pthis->ChangeTextColor(2,1);
						Sleep(2000);
						pthis->optionduration++;
						if(pthis->optionduration>=3)
						{
							pthis->selectanswer=2;
							//pthis->SendMessage(MYWM_SELECTOPTION,0,0);
							pthis->highlightselect(pthis->selectanswer);
							pthis->highlightanswer(pthis->selectanswer);
							pthis->trialnum++;
							if(pthis->trialnum<pthis->trialtotal)
							{
								pthis->showblank();
								pthis->shownewquestion();
							}
							else
								{
									CString str;
									switch(pthis->totalreward)
									{
									case 1:
										str=CString("Congratulations,you have got $100.");
										break;
									case 2:
										str=CString("Congratulations,you have got $200.");
										break;
									case 3:
										str=CString("Congratulations,you have got $300.");
										break;
									case 4:
										str=CString("Congratulations,you have got $500.");
										break;
									case 5:
										str=CString("Congratulations,you have got $1,000.");
										break;
									case 6:
										str=CString("Congratulations,you have got $2,000.");
										break;
									case 7:
										str=CString("Congratulations,you have got $4,000.");
										break;
									case 8:
										str=CString("Congratulations,you have got $8,000.");
										break;
									case 9:
										str=CString("Congratulations,you have got $16,000.");
										break;
									case 10:
										str=CString("Congratulations,you have got $32,000.");
										break;
									case 11:
										str=CString("Congratulations,you have got $64,000.");
										break;
									case 12:
										str=CString("Congratulations,you have got $125,000.");
										break;
									case 13:
										str=CString("Congratulations,you have got $250,000.");
										break;
									case 14:
										str=CString("Congratulations,you have got $500,000.");
										break;
									case 15:
										str=CString("Congratulations,you have got $1MILLION.");
									}
									FILE *record;
									record=fopen("record of zhou.txt","at+");
								//	fseek(record,0L,2);
									fprintf(record,"\n%d	%f	%f	%f\n",pthis->totalreward,pthis->meanIdle,pthis->meanNonIdle,pthis->statethreshod);
									fclose(record);
									AfxMessageBox(str);
									pthis->UnfinishedTag=false;
								}
							pthis->optionduration=0;
							pthis->lastoption=1;
						}
					}
				}
			}
			else if(pthis->meanNonIdle<=pthis->meanIdle)
			{				
				if(pthis->lastoption==1)
				{
					if(amplitude<pthis->statethreshod)
					{
						pthis->ChangeTextColor(2,1);
						Sleep(2000);
						pthis->lastoption=2;
						pthis->optionduration=1;
					}
					else if(amplitude>=pthis->statethreshod)
					{
						pthis->ChangeTextColor(1,2);
						Sleep(2000);
						pthis->optionduration++;
						if(pthis->optionduration>=3)
						{
							pthis->selectanswer=1;
							//pthis->SendMessage(MYWM_SELECTOPTION,0,0);
							pthis->highlightselect(pthis->selectanswer);
							pthis->highlightanswer(pthis->selectanswer);
							pthis->trialnum++;
							if(pthis->trialnum<pthis->trialtotal)
							{
								pthis->showblank();
								pthis->shownewquestion();
							}
							else
								{
									CString str;
									switch(pthis->totalreward)
									{
									case 1:
										str=CString("Congratulations,you have got $100.");
										break;
									case 2:
										str=CString("Congratulations,you have got $200.");
										break;
									case 3:
										str=CString("Congratulations,you have got $300.");
										break;
									case 4:
										str=CString("Congratulations,you have got $500.");
										break;
									case 5:
										str=CString("Congratulations,you have got $1,000.");
										break;
									case 6:
										str=CString("Congratulations,you have got $2,000.");
										break;
									case 7:
										str=CString("Congratulations,you have got $4,000.");
										break;
									case 8:
										str=CString("Congratulations,you have got $8,000.");
										break;
									case 9:
										str=CString("Congratulations,you have got $16,000.");
										break;
									case 10:
										str=CString("Congratulations,you have got $32,000.");
										break;
									case 11:
										str=CString("Congratulations,you have got $64,000.");
										break;
									case 12:
										str=CString("Congratulations,you have got $125,000.");
										break;
									case 13:
										str=CString("Congratulations,you have got $250,000.");
										break;
									case 14:
										str=CString("Congratulations,you have got $500,000.");
										break;
									case 15:
										str=CString("Congratulations,you have got $1MILLION.");
									}
									FILE *record;
									record=fopen("record of zhou.txt","at+");
								//	fseek(record,0L,2);
									fprintf(record,"\n%d	%f	%f	%f\n",pthis->totalreward,pthis->meanIdle,pthis->meanNonIdle,pthis->statethreshod);
									fclose(record);
									AfxMessageBox(str);
									pthis->UnfinishedTag=false;
								}
							pthis->optionduration=0;
							pthis->lastoption=1;
						}
					}
				}
				else if(pthis->lastoption!=1)
				{
					if(amplitude<pthis->statethreshod)
					{
						pthis->ChangeTextColor(1,2);
						Sleep(2000);
						pthis->lastoption=1;
						pthis->optionduration=1;
					}
					else if(amplitude>=pthis->statethreshod)
					{
						pthis->ChangeTextColor(2,1);
						Sleep(2000);
						pthis->optionduration++;
						if(pthis->optionduration>=3)
						{
							pthis->selectanswer=2;
							//pthis->SendMessage(MYWM_SELECTOPTION,0,0);
							pthis->highlightselect(pthis->selectanswer);
							pthis->highlightanswer(pthis->selectanswer);
							pthis->trialnum++;
							if(pthis->trialnum<pthis->trialtotal)
							{
								pthis->showblank();
								pthis->shownewquestion();
							}
							else
								{
									CString str;
									switch(pthis->totalreward)
									{
									case 1:
										str=CString("Congratulations,you have got $100.");
										break;
									case 2:
										str=CString("Congratulations,you have got $200.");
										break;
									case 3:
										str=CString("Congratulations,you have got $300.");
										break;
									case 4:
										str=CString("Congratulations,you have got $500.");
										break;
									case 5:
										str=CString("Congratulations,you have got $1,000.");
										break;
									case 6:
										str=CString("Congratulations,you have got $2,000.");
										break;
									case 7:
										str=CString("Congratulations,you have got $4,000.");
										break;
									case 8:
										str=CString("Congratulations,you have got $8,000.");
										break;
									case 9:
										str=CString("Congratulations,you have got $16,000.");
										break;
									case 10:
										str=CString("Congratulations,you have got $32,000.");
										break;
									case 11:
										str=CString("Congratulations,you have got $64,000.");
										break;
									case 12:
										str=CString("Congratulations,you have got $125,000.");
										break;
									case 13:
										str=CString("Congratulations,you have got $250,000.");
										break;
									case 14:
										str=CString("Congratulations,you have got $500,000.");
										break;
									case 15:
										str=CString("Congratulations,you have got $1MILLION.");
									}
									FILE *record;
									record=fopen("record of zhou.txt","at+");
									//fseek(record,0L,2);
									fprintf(record,"\n%d	%f	%f	%f\n",pthis->totalreward,pthis->meanIdle,pthis->meanNonIdle,pthis->statethreshod);
									fclose(record);
									AfxMessageBox(str);
									pthis->UnfinishedTag=false;
								}
							pthis->optionduration=0;
							pthis->lastoption=1;
						}
					}
				}
			}
		}	
	}
	return (0);
}


double  CTestcontolDlg::mean_fre(double *data)
{//feature function
	int datalength=buffersize;
	double temp=0,meantemp=0;
	for(int i=0;i<datalength;i++)
	{
//		temp+=data[i];   // feature function=average amplitude in 1 sec
		temp+=fabs(data[i]);//feature function =average abs amplitude in 1 sec
	}
	meantemp=temp/datalength;
	return meantemp;
}



void CTestcontolDlg::ChangeTextColor(int choose,int nchoose)
{
	ShiftColorTag=true;
	if(choose==1)
	{currentoption=1;}
	else 
		currentoption=2;
	CWnd *pWnd=GetDlgItem(IDC_EDITOPTION1);
	CRect rect;
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(&rect);
	pWnd=GetDlgItem(IDC_EDITOPTION2);
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(&rect);
	UpdateWindow();
	ShiftColorTag=false;
}

LRESULT CTestcontolDlg::selectoption(WPARAM wParam,LPARAM lParam)
{
	int option=(int)lParam;
	SuspendThread(m_hThEmotivAnalysisData);
	TCHAR array[]=_T("in select");
		CString str;
		str.Format(_T("%s"), array);
		AfxMessageBox(str);


		TCHAR array1[]=_T("back in select");
		CString str1;
		str1.Format(_T("%s"), array1);
		AfxMessageBox(str1);
	trialnum++;
	if(trialnum<trialtotal)
	{
		shownewquestion();
		ResumeThread(m_hThEmotivAnalysisData);
	}
	else 
	{
		TCHAR array[]=_T("Finish all the exercise");
		CString str;
		str.Format(_T("%s"), array);
		AfxMessageBox(str);
	}
	return 0;
}

void CTestcontolDlg::highlightselect(int option)
{
	//highlight selected option
	SelectColorTag=true;
	CWnd *pWnd;
	CRect rect;
	pWnd=GetDlgItem(IDC_EDITOPTION1);
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(&rect);
	pWnd=GetDlgItem(IDC_EDITOPTION2);
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(&rect);
	UpdateWindow();
	SelectColorTag=false;
	Sleep(3000);
}
void  CTestcontolDlg::highlightanswer(int option)
{
	//identify choose right or wrong
	int correctanswer=atoi(answer[trialnum]);
	CRect rect;
	RightAnswerColorTag=true;
	changebkTag=true;
	CWnd *pWnd;
	pWnd=GetDlgItem(IDC_EDITINSTRUCTION);
	pWnd->SetFont(&m_font3);
	if(option==correctanswer)
	{	
		totalreward++;
		pWnd->SetWindowTextW(_T("\r\nCorrect!"));
	}
	else 
	{
		pWnd->SetWindowTextW(_T("\r\n Wrong!"));
	}
	this->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(&rect);
	UpdateWindow();
	RightAnswerColorTag=false;
//	IncreaseIndexTag=false;
//	RewardInstructionTag=false;
	changebkTag=false;
	Sleep(2000);


}


/////////////show the new question
void CTestcontolDlg::shownewquestion()
{
	updatequestionTag=true;
	CMyEdit *editquestion,*editoption1,*editoption2,*editinstruction;
	editquestion =(CMyEdit *)GetDlgItem(IDC_EDITQUESTION);
	editoption1 =(CMyEdit *)GetDlgItem(IDC_EDITOPTION1);
	editoption2 =(CMyEdit *)GetDlgItem(IDC_EDITOPTION2);
	CString str=(CString)question[trialnum];
	editquestion->SetWindowTextW((LPCTSTR)str);
	str=(CString)option1[trialnum];
	editoption1->SetWindowTextW((LPCTSTR)str);
	str=(CString)option2[trialnum];
	editoption2->SetWindowTextW((LPCTSTR)str);
	correctanswer=atoi(answer[trialnum]);
	editinstruction=(CMyEdit *)GetDlgItem(IDC_EDITINSTRUCTION);
	editinstruction->SetFont(&m_font2);
	editinstruction->SetWindowTextW(_T("1 -Think 'change' to change choice.\r\n2 - Relax for 3 seconds to confirm choice.\r\n3- Blue:Current choice.\r\n    Orange:Your final answer\r\n    Green:Correct answer."));
	CRect rect;
	this->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(&rect);
	UpdateWindow();
	Sleep(3000);
	updatequestionTag=false;
}
void CTestcontolDlg::showblank()
{
	ShowblankTag=true;
	CMyEdit *editquestion,*editoption1,*editoption2,*editinstruction;
	editquestion =(CMyEdit *)GetDlgItem(IDC_EDITQUESTION);
	editoption1 =(CMyEdit *)GetDlgItem(IDC_EDITOPTION1);
	editoption2 =(CMyEdit *)GetDlgItem(IDC_EDITOPTION2);
	editquestion->SetWindowTextW(_T(""));
	editoption1->SetWindowTextW(_T(""));
	editoption2->SetWindowTextW(_T(""));
	editinstruction=(CMyEdit *)GetDlgItem(IDC_EDITINSTRUCTION);
	editinstruction->SetFont(&m_font2);
	editinstruction->SetWindowTextW(_T("1 -Think 'change' to change choice.\r\n2 - Relax for 3 seconds to confirm choice.\r\n3- Blue:Current choice.\r\n    Orange:Your final answer\r\n    Green:Correct answer."));
	CRect rect;
	this->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(&rect);
	UpdateWindow();
	Sleep(2000);
	ShowblankTag=false;

}
void CTestcontolDlg::OnBnClickedButtonstarttrain()
{
	//test
	/*bkchangecount++;
	CRect rect;
	this->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(&rect);
	UpdateWindow();*/
	
	// TODO: Add your control notification handler code here
	TrainingTag=false;
	CTrainDlg dlg;
	dlg.DoModal();
	Sleep(3000);
	TrainingTag=true;
}

void CTestcontolDlg::OnBnClickedButtonretry()
{
	// TODO: Add your control notification handler code here
}
