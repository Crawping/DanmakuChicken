
// DanmakuChickenDlg.h : ͷ�ļ�
//

#pragma once
#include "OverlayDlg.h"
#include "afxwin.h"


// CDanmakuChickenDlg �Ի���
class CDanmakuChickenDlg : public CDialogEx
{
// ����
public:
	CDanmakuChickenDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DANMAKUCHICKEN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();


	ULONG_PTR m_gdiplusToken;
	COverlayDlg* m_overlayDlg = NULL;

	CEdit m_danmakuSizeEdit;
	CEdit m_danmakuSpeedEdit;
};
