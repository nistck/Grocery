
// GroceryView.cpp: CGroceryView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Grocery.h"
#endif

#include "GroceryDoc.h"
#include "GroceryView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGroceryView

IMPLEMENT_DYNCREATE(CGroceryView, CView)

BEGIN_MESSAGE_MAP(CGroceryView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGroceryView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CGroceryView 构造/析构

CGroceryView::CGroceryView()
{
	// TODO: 在此处添加构造代码

}

CGroceryView::~CGroceryView()
{
}

BOOL CGroceryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGroceryView 绘图

void CGroceryView::OnDraw(CDC* /*pDC*/)
{
	CGroceryDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CGroceryView 打印


void CGroceryView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGroceryView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGroceryView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CGroceryView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CGroceryView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGroceryView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGroceryView 诊断

#ifdef _DEBUG
void CGroceryView::AssertValid() const
{
	CView::AssertValid();
}

void CGroceryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGroceryDoc* CGroceryView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGroceryDoc)));
	return (CGroceryDoc*)m_pDocument;
}
#endif //_DEBUG


// CGroceryView 消息处理程序
