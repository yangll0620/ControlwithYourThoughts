#pragma once
#include "afxwin.h"

class CMyEdit :
	public CEdit
{
public:
	CMyEdit(void);
	//BOOL 	Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	afx_msg void OnPaint();
	~CMyEdit(void);
	DECLARE_MESSAGE_MAP()
};
