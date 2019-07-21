// TestcontolDlg.h : header file
//

#pragma once
#include "MyEdit.h"
#include "mydefine.h"

#include "EmoStateDLL.h"
#include "edk.h"
#include "edkErrorCode.h"

#include "string.h"
#include "TrainDlg.h"

#pragma comment(lib, "lib/edk.lib")


// CTestcontolDlg dialog
class CTestcontolDlg : public CDialog
{
// Construction
public:
	CTestcontolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TESTCONTOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType,int cx,int cy);
	afx_msg HBRUSH OnCtlColor(CDC *pDC,CWnd *pWnd,UINT nCtlColor);

public:                 /////////////////////////variables

	CBitmap m_bmp; 
	CRect m_rect;
	CBrush  m_brush;
	int count;
	CFont m_font1,m_font2,m_font3;///////m_font1 for question,option1&2, m_font2 for instruction and reward,m_font3 for large
								//////// "wrong" and "right"

	///////////////interface edit control variables
	static const int trialtotal=15;
	char question[trialtotal][50];
	char option1[trialtotal][50];
	char option2[trialtotal][50];
	char answer[trialtotal][50];
	int trialnum;

	//emotiv variables
	DataHandle hData;
	bool readytocollect,readytoanalysis;
	bool TrainingTag,TrainingIdleTag,TrainingUpTag,TrainingDownTag;
	bool UnfinishedTag;
	EmoEngineEventHandle eEvent;
	EmoStateHandle eState;
	unsigned int userID;
	float secs;
	static const int buffersize=128;
	int lastsample;
	double buffer[buffersize],dealdata[buffersize];
	double statethreshod,meanIdle, meanUp,meanDown,meanNonIdle;//statethreshod=(meanIdle+meanNonIdel)/2
	EE_DataChannel_t targetChannel; 
	HANDLE m_hEvReadytoAnalysis;
	HANDLE m_hThEmotivReadData;
	HANDLE m_hThEmotivAnalysisData;
	int lastoption,optionduration,currentoption;
	int selectanswer,correctanswer;
	int totalreward;
	bool ShiftColorTag,SelectColorTag,RightAnswerColorTag,IncreaseIndexTag,RewardInstructionTag;
	bool updatequestionTag,ShowblankTag;
	bool changebkTag;

	//test
	CBitmap m_bmp2;
	int bkchangecount;

public:   ///////////////////////////////function
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	BOOL  OnEraseBkgnd(CDC* pDC) ;
	COLORREF m_colorEditBK;  
	CBrush* m_pEditBkBrush;

	//////////emotiv functions
	static DWORD WINAPI  Emotiv_ReadDataThread(LPVOID pParam);
	static DWORD WINAPI  Emotiv_AnalysisDataThread(LPVOID pParam);
	void ChangeTextColor(int choose,int nchoose);
	double mean_fre(double *data);
	double std_fre(double *data);
	afx_msg LRESULT selectoption(WPARAM wParam,LPARAM lParam);
	void highlightselect(int option);
	void highlightanswer(int option);
	void showblank();
	void shownewquestion();
	afx_msg void OnBnClickedButtonstarttrain();
	afx_msg void OnBnClickedButtonretry();

};
