/****************************************************************************
* Class name:  CXDialog
* Description: ������ � ������
* File name:   CXDialog.h
* Compilers:   Visual C++ 2008
* String type: Ansi
* Libraries:   WinAPI, Stl, XLib
* Author:      Sergey Shapka
* E-mail:      dr.web.agent@gmail.com
* Created:     23.07.2009 13:10:17
* Version:     1.0.0.0 Debug
*
*****************************************************************************/


#ifndef XLib_Gui_CXDialogH
#define XLib_Gui_CXDialogH
//---------------------------------------------------------------------------
#include <XLib/Gui/CXWindow.h>
//---------------------------------------------------------------------------
class CXDialog : public CxWindow {
	public:
				     CXDialog      ();
				     CXDialog      (SHORT TemplID, SHORT IconID = 0, HWND hParentWnd = NULL);
				    ~CXDialog      ();
				
					 xDECLARE_MSG_MAP();
		
		BOOL         bCreate       (SHORT TemplID, SHORT IconID = 0, HWND hParentWnd = NULL);
		INT          CreateModal   ();

	protected:
		SHORT        _m_siTemplID;
		SHORT        _m_siIconID;

		virtual INT  OnInitial     (WPARAM wParam, LPARAM lParam);
		virtual VOID OnPaint       (WPARAM wParam, LPARAM lParam);
		virtual VOID OnCommand     (WPARAM wParam, LPARAM lParam);
		virtual VOID OnNotify      (WPARAM wParam, LPARAM lParam);
		virtual VOID OnSize        (WPARAM wParam, LPARAM lParam);	
		virtual VOID OnClose       (WPARAM wParam, LPARAM lParam);    
		virtual VOID OnDestroy     (WPARAM wParam, LPARAM lParam);
};
//---------------------------------------------------------------------------
#endif	//XLib_Gui_CXDialogH