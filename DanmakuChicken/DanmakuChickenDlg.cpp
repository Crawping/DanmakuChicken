
// DanmakuChickenDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DanmakuChicken.h"
#include "DanmakuChickenDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDanmakuChickenDlg �Ի���



CDanmakuChickenDlg::CDanmakuChickenDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDanmakuChickenDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDanmakuChickenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_danmakuSizeEdit);
	DDX_Control(pDX, IDC_EDIT2, m_danmakuSpeedEdit);
}

BEGIN_MESSAGE_MAP(CDanmakuChickenDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
ON_WM_DESTROY()
ON_BN_CLICKED(IDC_BUTTON1, &CDanmakuChickenDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CDanmakuChickenDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDanmakuChickenDlg ��Ϣ�������

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDanmakuChickenDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDanmakuChickenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CDanmakuChickenDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	m_danmakuSizeEdit.SetWindowText(_T("40"));
	m_danmakuSpeedEdit.SetWindowText(_T("6"));

	// ��ʼ��GDI+
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	// ���뵯Ļ����
	m_overlayDlg = new COverlayDlg();
	m_overlayDlg->Create(m_overlayDlg->IDD, GetDesktopWindow());

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDanmakuChickenDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// �رյ�Ļ����
	if (m_overlayDlg != NULL)
	{
		m_overlayDlg->DestroyWindow();
		delete m_overlayDlg;
		m_overlayDlg = NULL;
	}

	// ж��GDI+
	GdiplusShutdown(m_gdiplusToken);
}

// �޸ĵ�Ļ����
void CDanmakuChickenDlg::OnBnClickedButton1()
{
	CString strBuf;
	m_danmakuSizeEdit.GetWindowText(strBuf);
	m_overlayDlg->m_danmakuManager.m_danmakuSize = (float)_ttof(strBuf);
	m_danmakuSpeedEdit.GetWindowText(strBuf);
	m_overlayDlg->m_danmakuManager.m_danmakuSpeed = _ttoi(strBuf);
}

// ���Ե�Ļ
void CDanmakuChickenDlg::OnBnClickedButton2()
{
	m_overlayDlg->m_danmakuManager.AddDanmaku(_T("����TEST1234asdfasdfasdf������"));
}
