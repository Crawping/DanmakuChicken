#pragma once
#include "Danmaku.h"


// COverlayDlg �Ի���

class COverlayDlg : public CDialog
{
	DECLARE_DYNAMIC(COverlayDlg)

public:
	COverlayDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COverlayDlg();

// �Ի�������
	enum { IDD = IDD_OVERLAY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	virtual void UpdateUI();


	DanmakuManager m_danmakuManager;
	SIZE m_size;
	CImage m_dc;
	std::thread* m_renderThread = NULL;
	BOOL m_stopThreads = FALSE;
};
