#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#include "TestcontolDlg.h"
class TrainDlg :
	public CDialog
{
public:
	TrainDlg(void);
	~TrainDlg(void);
};
#pragma once


// CTrainDlg dialog

class CTrainDlg : public CDialog
{
	DECLARE_DYNAMIC(CTrainDlg)

public:
	CTrainDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTrainDlg();

// Dialog Data
	enum { IDD = IDD_DIALOGTraining };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtontrainidle();
	afx_msg void OnBnClickedButtontraindown();
	afx_msg void OnBnClickedButtontrainup();
	CProgressCtrl m_wndTrainProgBar;

	int trainingtime,segmenttime;

	afx_msg void OnBnClickedOk();
};
