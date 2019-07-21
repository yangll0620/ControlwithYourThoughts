// TrainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Testcontol.h"
#include "TrainDlg.h"


// CTrainDlg dialog

IMPLEMENT_DYNAMIC(CTrainDlg, CDialog)

CTrainDlg::CTrainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrainDlg::IDD, pParent)
{
	trainingtime=10;
	segmenttime=1;


}

CTrainDlg::~CTrainDlg()
{
}

void CTrainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_wndTrainProgBar);
}


BEGIN_MESSAGE_MAP(CTrainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTONTrainIdle, &CTrainDlg::OnBnClickedButtontrainidle)
	ON_BN_CLICKED(IDC_BUTTONTrainDown, &CTrainDlg::OnBnClickedButtontraindown)
	ON_BN_CLICKED(IDC_BUTTONTrainUp, &CTrainDlg::OnBnClickedButtontrainup)
	ON_BN_CLICKED(IDOK, &CTrainDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTrainDlg message handlers

void CTrainDlg::OnBnClickedButtontrainidle()
{
	// TODO: Add your control notification handler code here
	int i;
	int trainingcounts=int(trainingtime/segmenttime);
	double temp=0;
	CTestcontolDlg *parent=(CTestcontolDlg *)GetParent();
	parent->meanIdle=0;
	i=1;
	HANDLE hEvent=parent->m_hEvReadytoAnalysis;
	m_wndTrainProgBar.SetRange(0,trainingcounts);
	while(i<=trainingcounts)
	{
		WaitForSingleObject(hEvent,INFINITE);
		temp+=parent->mean_fre(parent->dealdata);
		m_wndTrainProgBar.SetPos(i);
		i++;	
	}
	parent->meanIdle=temp/trainingcounts;
	parent->TrainingIdleTag=true;

}

void CTrainDlg::OnBnClickedButtontraindown()
{
	// TODO: Add your control notification handler code here
	int i;
	int trainingcounts=int(trainingtime/segmenttime);
	double temp=0;
	CTestcontolDlg *parent=(CTestcontolDlg *)GetParent();
	parent->meanDown=0;
	i=1;
	HANDLE hEvent=parent->m_hEvReadytoAnalysis;
	m_wndTrainProgBar.SetRange(0,trainingcounts);
	while(i<=trainingcounts)
	{
		WaitForSingleObject(hEvent,INFINITE);
		temp+=parent->mean_fre(parent->dealdata);
		m_wndTrainProgBar.SetPos(i);
		i++;
	}
	parent->meanDown=temp/trainingcounts;
	parent->TrainingDownTag=true;
}



void CTrainDlg::OnBnClickedButtontrainup()
{
	// TODO: Add your control notification handler code here
	int i;
	int trainingcounts=int(trainingtime/segmenttime);
	double temp=0;
	CTestcontolDlg *parent=(CTestcontolDlg *)GetParent();
	parent->meanUp=0;
	i=1;
	HANDLE hEvent=parent->m_hEvReadytoAnalysis;
	m_wndTrainProgBar.SetRange(0,trainingcounts);
	while(i<=trainingcounts)
	{
		WaitForSingleObject(hEvent,INFINITE);
		temp+=parent->mean_fre(parent->dealdata);
		m_wndTrainProgBar.SetPos(i);
		i++;
	}
	parent->meanUp=temp/trainingcounts;
	parent->TrainingUpTag=true;

}

void CTrainDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
	CTestcontolDlg *parent=(CTestcontolDlg *)GetParent();
	if(parent->TrainingIdleTag)
	{
		if(!parent->TrainingDownTag&&!parent->TrainingUpTag)
		{
			TCHAR array[]=_T("NonIdle State missing");
			CString str;
			str.Format(_T("%s"), array);
			AfxMessageBox(str);

		}
		if(parent->TrainingDownTag||parent->TrainingUpTag)
		{
			if(parent->TrainingDownTag&&parent->TrainingUpTag)
				{
					parent->meanNonIdle=(parent->meanDown+parent->meanUp)/2;
				}
			if(parent->TrainingDownTag&&!parent->TrainingUpTag)
				{
					parent->meanNonIdle=parent->meanDown;
				}
			if (!parent->TrainingDownTag&&parent->TrainingUpTag)
				{
					parent->meanNonIdle=parent->meanUp;
				}
			parent->statethreshod=(parent->meanIdle+parent->meanNonIdle)/2;
			parent->TrainingTag=true;
		}
	}
	else
		{
			TCHAR array[]=_T("Idle State is missing");
			CString str;
			str.Format(_T("%s"), array);
			AfxMessageBox(str);
		}


}

