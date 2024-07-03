// DH.cpp : implementation file
//

#include "stdafx.h"
#include "Virtual Robot.h"
#include "DH.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDH

IMPLEMENT_DYNCREATE(CDH, CView)

CDH::CDH()
{
	m_TLInitialized=false;
}

CDH::~CDH()
{

}


BEGIN_MESSAGE_MAP(CDH, CView)
	//{{AFX_MSG_MAP(CDH)
	ON_WM_SIZE()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDH drawing

void CDH::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CDH diagnostics

#ifdef _DEBUG
void CDH::AssertValid() const
{
	CView::AssertValid();
}

void CDH::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDH message handlers

void CDH::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	//init
	
	CRect m_wndRect;
	GetWindowRect(&m_wndRect);
	CRect m_headerRect;

	// create the header
	{
		m_headerRect.left = m_headerRect.top = -1;
		m_headerRect.right = m_wndRect.Width();

		m_tree.m_wndHeader.Create(WS_CHILD | WS_VISIBLE | HDS_BUTTONS | HDS_HORZ, m_headerRect, this, 600);
	}

	CSize textSize;
	// set header's pos, dimensions and image list
	{
		CDC *pDC = m_tree.m_wndHeader.GetDC();
		pDC->SelectObject(&m_tree.m_headerFont);
		textSize = pDC->GetTextExtent("A");
		m_tree.m_wndHeader.ReleaseDC(pDC); 

		m_tree.m_wndHeader.SetWindowPos(&wndTop, -1, -1, m_headerRect.Width(), textSize.cy+4, SWP_SHOWWINDOW);

		m_tree.m_cImageList.Create(DHC, 18, 18, RGB(255,255,255));
		m_tree.m_wndHeader.SetImageList(&m_tree.m_cImageList);		
	}

	CRect m_treeRect;

	// create the tree itself
	{
		GetWindowRect(&m_wndRect);

		m_treeRect.left=0;
		m_treeRect.top = textSize.cy+4;
		m_treeRect.right = m_headerRect.Width()-5;
		m_treeRect.bottom = m_wndRect.Height()-GetSystemMetrics(SM_CYHSCROLL)-4;

		m_tree.Create(WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_SHOWSELALWAYS,m_treeRect, this, 601);
	}

	// finally, create the horizontal scroll bar
	{
		CRect m_scrollRect;
		m_scrollRect.left=0;
		m_scrollRect.top = m_treeRect.bottom;
		m_scrollRect.right = m_treeRect.Width()-GetSystemMetrics(SM_CXVSCROLL);
		m_scrollRect.bottom = m_wndRect.bottom;

		m_horScrollBar.Create(WS_CHILD | WS_VISIBLE | WS_DISABLED | SBS_HORZ | SBS_TOPALIGN, m_scrollRect, this,602);
	}

	SortTree(0, TRUE, m_tree.GetRootItem());	
	//end init


	m_cImageList.Create(LINK, 18, 18, RGB(255, 255, 255));
	m_tree.SetImageList(&m_cImageList, TVSIL_NORMAL);

	
	GetClientRect(&m_wndRect);
	MoveWindow(0, 0, m_wndRect.Width(), m_wndRect.Height());

	m_tree.InsertColumn(0, "Link", LVCFMT_LEFT, 120);
	m_tree.InsertColumn(1, "a", LVCFMT_RIGHT, 50);
	m_tree.InsertColumn(2, "Alfa", LVCFMT_RIGHT, 50);
	m_tree.InsertColumn(3, "d", LVCFMT_RIGHT, 50);
	m_tree.InsertColumn(4, "Theta", LVCFMT_RIGHT, 50);
	m_tree.InsertColumn(5, "q", LVCFMT_RIGHT, 50);
		
	//THE TREE
	
	CWnd* pTT = FromHandle((HWND)SendMessage(TVM_GETTOOLTIPS));
    if (pTT != NULL)
		pTT->SetWindowPos(&wndTopMost, 0, 0, 0, 0,
		SWP_NOMOVE|SWP_NOSIZE|SWP_NOACTIVATE);
	
	HTREEITEM hTmp;
		
	hTmp = m_tree.InsertItem("Links",0,0,0,0);
	HTREEITEM hTmp1;

	hTmp1=m_tree.InsertItem("Link 1",hTmp);
	m_tree.SetItemText(hTmp1,1,"0");
	m_tree.SetItemText(hTmp1,2,"0");
	m_tree.SetItemText(hTmp1,3,"d(1)");
	m_tree.SetItemText(hTmp1,4,"Theta(1)");
	m_tree.SetItemText(hTmp1,5,"Theta(1)");

	hTmp1=m_tree.InsertItem("Link 2",hTmp);	
	m_tree.SetItemText(hTmp1,1,"0");
	m_tree.SetItemText(hTmp1,2,"0");
	m_tree.SetItemText(hTmp1,3,"d(2)");
	m_tree.SetItemText(hTmp1,4,"Theta(2)");
	m_tree.SetItemText(hTmp1,5,"Theta(2)");

	hTmp1=m_tree.InsertItem("Link 3",hTmp);	
	m_tree.SetItemText(hTmp1,1,"0");
	m_tree.SetItemText(hTmp1,2,"0");
	m_tree.SetItemText(hTmp1,3,"d(3)");
	m_tree.SetItemText(hTmp1,4,"Theta(3)");
	m_tree.SetItemText(hTmp1,5,"Theta(3)");

	hTmp1=m_tree.InsertItem("Link 4",hTmp);	
	m_tree.SetItemText(hTmp1,1,"-");
	m_tree.SetItemText(hTmp1,2,"-");
	m_tree.SetItemText(hTmp1,3,"-");
	m_tree.SetItemText(hTmp1,4,"-");
	m_tree.SetItemText(hTmp1,5,"-");

/*
HTREEITEM Parent1=hTmp;

	hTmp = m_tree.InsertItem("child1ofparent1",hTmp);	
	m_tree.SetItemText(hTmp,1,"child1col2text");
	m_tree.SetItemText(hTmp,2,"child1col3text");
	hTmp = m_tree.InsertItem("child1ofchild1",hTmp);	
	m_tree.SetItemText(hTmp,1,"col2text");
	m_tree.SetItemText(hTmp,2,"col3text");
	hTmp = m_tree.InsertItem("child2ofparent1",Parent1);	
	m_tree.SetItemText(hTmp,1,"child2col2text");
	m_tree.SetItemText(hTmp,2,"child2col3text");
	hTmp = m_tree.InsertItem("child1ofchild2",hTmp);	
	m_tree.SetItemText(hTmp,1,"col2text");
	m_tree.SetItemText(hTmp,2,"col3text"	
*/



	m_TLInitialized=true;
}

void CDH::SortTree(int nCol, BOOL bAscending, HTREEITEM hParent)
{
	HTREEITEM hChild=NULL;
	HTREEITEM hPa = hParent;
	
	while(hPa!=NULL)
	{
		if(m_tree.ItemHasChildren(hPa))
		{			
			m_tree.SortItems(nCol, bAscending, hPa);
			SortTree(nCol, bAscending, hChild);			
		}			

		hPa = m_tree.GetNextSiblingItem(hPa);
	}
	
}

void CDH::ResetScrollBar()
{
	// resetting the horizontal scroll bar

	int m_nTotalWidth=0, m_nPageWidth;

	CRect m_treeRect;
	m_tree.GetClientRect(&m_treeRect);

	CRect m_wndRect;
	GetClientRect(&m_wndRect);

	CRect m_headerRect;
	m_tree.m_wndHeader.GetClientRect(&m_headerRect);

	CRect m_barRect;
	m_horScrollBar.GetClientRect(m_barRect);

	m_nPageWidth = m_treeRect.Width();

	m_nTotalWidth = m_tree.GetColumnsWidth();

	if(m_nTotalWidth > m_nPageWidth)
	{
		// show the scroll bar and adjust it's size
		{
			m_horScrollBar.EnableWindow(TRUE);

			m_horScrollBar.ShowWindow(SW_SHOW);

			// the tree becomes smaller
			m_tree.SetWindowPos(&wndTop, 0, 0, m_wndRect.Width(), m_wndRect.Height()-m_barRect.Height()-m_headerRect.Height(), SWP_NOMOVE);

			if(!VerticalScrollVisible())
				// i.e. vertical scroll bar isn't visible
			{
				m_horScrollBar.SetWindowPos(&wndTop, 0, 0, m_wndRect.Width(), m_barRect.Height(), SWP_NOMOVE);
			}
			else
			{
				m_horScrollBar.SetWindowPos(&wndTop, 0, 0, m_wndRect.Width() - GetSystemMetrics(SM_CXVSCROLL), m_barRect.Height(), SWP_NOMOVE);
			}
		}

		m_horScrollBar.SetScrollRange(0, m_nTotalWidth-m_nPageWidth);

		// recalculate the offset
		{
			CRect m_wndHeaderRect;
			m_tree.m_wndHeader.GetWindowRect(&m_wndHeaderRect);
			ScreenToClient(&m_wndHeaderRect);

			m_tree.m_nOffset = m_wndHeaderRect.left;
			m_horScrollBar.SetScrollPos(-m_tree.m_nOffset);
		}
	}
	else
	{
		m_horScrollBar.EnableWindow(FALSE);

		// we no longer need it, so hide it!
		{
			m_horScrollBar.ShowWindow(SW_HIDE);

			m_tree.SetWindowPos(&wndTop, 0, 0, m_wndRect.Width(), m_wndRect.Height() - m_headerRect.Height(), SWP_NOMOVE);
			// the tree takes scroll's place
		}

		m_horScrollBar.SetScrollRange(0, 0);

		// set scroll offset to zero
		{
			m_tree.m_nOffset = 0;
			m_tree.Invalidate();
			CRect m_headerRect;
			m_tree.m_wndHeader.GetWindowRect(&m_headerRect);
			CRect m_wndRect;
			GetClientRect(&m_wndRect);
			m_tree.m_wndHeader.SetWindowPos(&wndTop, m_tree.m_nOffset, 0, max(StretchWidth(m_tree.GetColumnsWidth(),m_wndRect.Width()),m_wndRect.Width()), m_headerRect.Height(), SWP_SHOWWINDOW);
		}
	}
}

BOOL CDH::HorizontalScrollVisible()
{
int sMin, sMax;
	m_horScrollBar.GetScrollRange(&sMin, &sMax);
	return sMax!=0;
}

BOOL CDH::VerticalScrollVisible()
{
	int sMin, sMax;
	m_tree.GetScrollRange(SB_VERT, &sMin, &sMax);	
	return sMax!=0;
}

int CDH::StretchWidth(int m_nWidth, int m_nMeasure)
{
return ((m_nWidth/m_nMeasure)+1)*m_nMeasure;
}

void CDH::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
SetScrollRange(SB_HORZ, 0, 0);
	SetScrollRange(SB_VERT, 0, 0);

	if(m_TLInitialized)
	{	
		// resize all the controls	
		CRect m_wndRect;
		GetClientRect(&m_wndRect);

		CRect m_headerRect;
		m_tree.m_wndHeader.GetClientRect(&m_headerRect);
		m_tree.m_wndHeader.SetWindowPos(&wndTop, 0, 0, m_wndRect.Width(), m_headerRect.Height(), SWP_NOMOVE);

		CRect m_scrollRect;
		m_horScrollBar.GetClientRect(&m_scrollRect);

		m_tree.SetWindowPos(&wndTop, 0, 0, m_wndRect.Width(), m_wndRect.Height() - m_scrollRect.Height(), SWP_NOMOVE);

		CRect m_treeRect;
		m_tree.GetClientRect(&m_treeRect);
		m_horScrollBar.MoveWindow(0, m_treeRect.bottom, m_wndRect.Width(), m_scrollRect.Height());

		if(m_tree.GetColumnsWidth() > m_treeRect.Width())
		{
			// show the horz scroll bar
			{
				CRect m_barRect;
				m_horScrollBar.GetClientRect(&m_barRect);			

				m_horScrollBar.EnableWindow(TRUE);

				m_horScrollBar.ShowWindow(SW_SHOW);

				// the tree becomes smaller
				m_tree.SetWindowPos(&wndTop, 0, 0, m_wndRect.Width(), m_wndRect.Height()-m_barRect.Height()-m_headerRect.Height(), SWP_NOMOVE);

				int tfdsfsd=m_wndRect.Width() - GetSystemMetrics(SM_CXVSCROLL);
				m_horScrollBar.SetWindowPos(&wndTop, 0, 0, m_wndRect.Width() - GetSystemMetrics(SM_CXVSCROLL), m_barRect.Height(), SWP_NOMOVE);
				
			}

			m_horScrollBar.SetScrollRange(0, m_tree.GetColumnsWidth()-m_treeRect.Width());

		}
		else
		{
			// hide the scroll bar
			{
				m_horScrollBar.EnableWindow(FALSE);

				m_horScrollBar.ShowWindow(SW_HIDE);

				// the tree becomes larger
				m_tree.SetWindowPos(&wndTop, 0, 0, m_wndRect.Width(), m_wndRect.Height()-m_headerRect.Height(), SWP_NOMOVE);				
			}

			m_horScrollBar.SetScrollRange(0, 0);
		}

		m_tree.ResetVertScrollBar();
		
		// Reset the header control position and scroll
		// the tree control as required.
		int m_nCurPos = m_horScrollBar.GetScrollPos();
		m_tree.m_nOffset = -m_nCurPos;
	
		// smoothly scroll the tree control
	    {
		CRect m_scrollRect;
		m_tree.GetClientRect(&m_scrollRect);
		m_tree.ScrollWindow(m_nCurPos, 0, &m_scrollRect, &m_scrollRect);
		}
		m_tree.m_wndHeader.GetWindowRect(&m_headerRect);	
		GetClientRect(&m_wndRect);

		m_tree.m_wndHeader.SetWindowPos(&wndTop, m_tree.m_nOffset, 0,max(StretchWidth(m_tree.GetColumnsWidth(),m_treeRect.Width()),m_wndRect.Width()), m_headerRect.Height(),SWP_SHOWWINDOW);			
	}		
}

BOOL CDH::PreTranslateMessage(MSG* pMsg) 
{
/*
	if(pMsg->message == WM_MOUSEMOVE)
	{		
		CDC* pDC;
		pDC=GetDC();
		HDC hDC=pDC->GetSafeHdc();
		CDC HeadDC;
		HeadDC.Attach(hDC);
		// Save DC
		int nSavedDC = HeadDC.SaveDC();
		CFont font;
		font.CreateFont(14,0,                        // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH,			   // nPitchAndFamily
		NULL);                     // lpszFacename

		HeadDC.SelectObject(font);
		
		TVHITTESTINFO hInfo;
		CPoint point(LOWORD(pMsg->lParam),HIWORD(pMsg->lParam));
		hInfo.pt = point;	
		m_tree.HitTest(&hInfo);				
		
		if (hInfo.hItem!=NULL)
		{
			CArray<RECT,RECT> ColumnRectArray;
			CArray<int,int>	ColumnWidthArray;
			CArray<CString,CString>	ItemTextArray;
			CArray<CSize,CSize>	ItemTextWidthArray;
			
			for (int i=0;i<m_tree.m_wndHeader.GetItemCount();i++)
			{
				RECT ColumnRect;					
				m_tree.m_wndHeader.GetItemRect(i,&ColumnRect);
				ColumnRectArray.Add(ColumnRect);
				int WidthOfColumn=ColumnRect.right-ColumnRect.left;				
				ColumnWidthArray.Add(WidthOfColumn);
				CString Text=m_tree.GetItemText(hInfo.hItem,i);	
				ItemTextArray.Add(Text);
				CSize Width=pDC->GetTextExtent(Text);				
				ItemTextWidthArray.Add(Width);
			}		
			
			for (i=0;i<m_tree.m_wndHeader.GetItemCount();i++)
			{
				if (i==0)
				{					
					CPoint point=GetCurrentMessage()->pt;
					RECT TextItemRect;
					m_tree.GetItemRect(hInfo.hItem,&TextItemRect,TRUE);					
					point.x=TextItemRect.right-int((TextItemRect.right-TextItemRect.left)/2);					
					if ( (hInfo.flags & TVHT_ONITEMRIGHT) && (hInfo.pt.x<ColumnRectArray.GetAt(i).right) && (ItemTextWidthArray.GetAt(i).cx>(ColumnWidthArray.GetAt(i)-TextItemRect.right-4-int((TextItemRect.right-TextItemRect.left)/2))) )					
					{				
						CString colText=m_tree.GetItemText(hInfo.hItem,i);	
						DisplayToolTip(point,hInfo,colText);				
						m_tooltip.RelayEvent(pMsg);	
						break;
					}
					else
						m_tooltip.Pop();					
				}
				else
				{
					if ((hInfo.pt.x>ColumnRectArray.GetAt(i-1).right) && (hInfo.pt.x<ColumnRectArray.GetAt(i).right) && (ItemTextWidthArray.GetAt(i).cx>(ColumnWidthArray.GetAt(i)-8)) )
					{						
						CString colText=m_tree.GetItemText(hInfo.hItem,i);							
						point.x=ColumnRectArray.GetAt(i).left;						
						DisplayToolTip(point,hInfo,colText);				
						m_tooltip.RelayEvent(pMsg);	
						break;
					}
					else 
						m_tooltip.Pop();			
				}
			}		
			
			ColumnRectArray.RemoveAll();
			ColumnWidthArray.RemoveAll();
			ItemTextArray.RemoveAll();
			ItemTextWidthArray.RemoveAll();
		}
		else
			m_tooltip.Pop();					
		
		// Restore dc

		HeadDC.RestoreDC( nSavedDC );

		// Detach the dc before returning
		HeadDC.Detach();

	}	
*/
  return CView::PreTranslateMessage(pMsg);
}

void CDH::DisplayToolTip(CPoint point, TVHITTESTINFO hInfo, CString colText)
{
/*
	RECT ItemRect;
	CToolInfo ToolInfo;

	if (m_tooltip.GetToolInfo(ToolInfo,GetDlgItem(641)))
	{					
		short height=m_tree.GetItemHeight();
		m_tree.GetItemRect(hInfo.hItem,&ItemRect,TRUE);	
		
		point.y=ItemRect.top+height+3;
		ClientToScreen(&point);

		m_tooltip.SendMessage(TTM_TRACKACTIVATE, TRUE, (LPARAM)&ToolInfo);
		m_tooltip.SendMessage(TTM_TRACKPOSITION, 0, (LPARAM) (DWORD)MAKELONG(point.x, point.y));				
						
		ToolInfo.uFlags|=TTF_TRACK; 
		ToolInfo.uFlags|=TTF_ABSOLUTE; 

		m_tooltip.SetToolInfo(&ToolInfo);
							
		if (hInfo.hItem==m_tree.GetSelectedItem())
		{		
			m_tooltip.SetTipBkColor(RGB(128,128,95));
			m_tooltip.SetTipTextColor(RGB(255,255,255));			
		}
		else
		{
			m_tooltip.SetTipBkColor(RGB(250,254,218));
			m_tooltip.SetTipTextColor(RGB(0,0,0));
		}
		m_tooltip.UpdateTipText(colText,&m_tree);								
		m_tooltip.Update();
	}	*/			
}

void CDH::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
CRect m_treeRect;
	m_tree.GetClientRect(&m_treeRect);
	
	// if horizontal scroll bar 
	if(pScrollBar == &m_horScrollBar)
	{
		int m_nCurPos = m_horScrollBar.GetScrollPos();
		int m_nPrevPos = m_nCurPos;
		// decide what to do for each diffrent scroll event
		switch(nSBCode)
		{
			case SB_LEFT:			m_nCurPos = 0;
									break;
			case SB_RIGHT:			m_nCurPos = m_horScrollBar.GetScrollLimit()-1;
									break;
			case SB_LINELEFT:		m_nCurPos = max(m_nCurPos-6, 0);
									break;
			case SB_LINERIGHT:		m_nCurPos = min(m_nCurPos+6, m_horScrollBar.GetScrollLimit()-1);
									break;
			case SB_PAGELEFT:		m_nCurPos = max(m_nCurPos-m_treeRect.Width(), 0);
									break;
			case SB_PAGERIGHT:		m_nCurPos = min(m_nCurPos+m_treeRect.Width(), m_horScrollBar.GetScrollLimit()-1);
									break;
			case SB_THUMBTRACK:
			case SB_THUMBPOSITION:  if(nPos==0)
									    m_nCurPos = 0;
								    else
									    m_nCurPos = min(StretchWidth(nPos, 6), m_horScrollBar.GetScrollLimit()-1);
								    break;
		}		

		m_horScrollBar.SetScrollPos(m_nCurPos);
		m_tree.m_nOffset = -m_nCurPos;

		// smoothly scroll the tree control
		{
			CRect m_scrollRect;
			m_tree.GetClientRect(&m_scrollRect);
			m_tree.ScrollWindow(m_nPrevPos - m_nCurPos, 0, &m_scrollRect, &m_scrollRect);
		}

		CRect m_headerRect;
		m_tree.m_wndHeader.GetWindowRect(&m_headerRect);
		CRect m_wndRect;
		GetClientRect(&m_wndRect);		

		m_tree.m_wndHeader.SetWindowPos(&wndTop, m_tree.m_nOffset, 0, max(StretchWidth(m_tree.GetColumnsWidth(),m_treeRect.Width()),m_wndRect.Width()), m_headerRect.Height(), SWP_SHOWWINDOW);
	}	
	CView::OnHScroll(nSBCode, nPos, pScrollBar);
}
