#include "StdAfx.h"
#include "MyEdit.h"


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_PAINT()
END_MESSAGE_MAP()
CMyEdit::CMyEdit(void)
{
}

CMyEdit::~CMyEdit(void)
{
}
/*BOOL CMyEdit::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)//CString  strNc,
{
	//useless
	dwStyle |= ES_MULTILINE | ES_AUTOHSCROLL;
   //不能加ES_AUTOVSCROLL | ES_WANTRETURN属性
 if(CEdit::Create(dwStyle, rect, pParentWnd, nID))
	{
	//	m_strNc=strNc;
		CRect rc ;
		GetClientRect(&rc) ;
		CDC* pDC = GetDC();
		TEXTMETRIC tm;
		pDC->GetTextMetrics(&tm);
		pDC->SetBkColor(RGB(255,0,0));
		int nFontHeight = tm.tmHeight + tm.tmExternalLeading;
		int nMargin = (rc.Height() - nFontHeight) / 2;

		rc.DeflateRect(0,nMargin);
		SetRectNP(&rc);
		ReleaseDC(pDC) ;
		return true ;
	}
	else
		 return false ;
}*/

void CMyEdit::OnPaint() 
{ 
    CPaintDC dc(this);       // device context for painting 
     
         // TODO: Add your message handler code here 
    CRect rect; 
    GetWindowRect(rect); 
   rect.left += 1; 
    rect.right -= 1; 
    rect.top += 1; 
    rect.bottom -= 1; 
     
    ScreenToClient(rect); 
   // dc.Draw3dRect(rect, RGB(250,0,250), RGB(250,0,250)); 
	CRgn rgn;
//	rgn.CreateRectRgn(rect.left,rect.top,rect.right,rect.bottom);
	CBrush br(RGB(240,224,230));
//	dc.FrameRgn(&rgn,&br,3,3);
	//CPoint point;
	//point.x=(rect.right-rect.left)/10;
	//point.y=(rect.bottom-rect.top)/10;
	//dc.RoundRect(&rect,point);
	//CBrush br(RGB(240,224,230));
	//dc.FrameRect(&rect,&br);
	/*CRgn rgn;
	CPoint point[6];
	point[0].x=rect.left;
	point[1].x=rect.right;
	point[2].x=rect.right+(rect.right-rect.left)/100;
	point[3].x=rect.right;
	point[4].x=rect.left;
	point[5].x=rect.left-(rect.right-rect.left)/100;
	point[0].y=rect.top;
	point[1].y=rect.top;
	point[2].y=(rect.top+rect.bottom)/2;
	point[3].y=rect.bottom;
	point[4].y=rect.bottom;
	point[5].y=(rect.top+rect.bottom)/2;
	//rgn.CreatePolygonRgn(point,6,WINDING);
	rgn.CreateRoundRectRgn(rect.left,rect.top,rect.right,rect.bottom,50,50);
	dc.FrameRgn(&rgn,&br,3,3);
	//dc.Draw3dRect(rect, RGB(255, 0, 0), RGB(255, 0, 0));*/
    Invalidate(); 
    Default(); 
} 