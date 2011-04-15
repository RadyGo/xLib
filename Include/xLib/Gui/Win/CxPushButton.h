/****************************************************************************
* Class name:  CxPushButton
* Description: 
* File name:   CxPushButton.h
* Compilers:   Visual C++ 2008
* String type: Ansi
* Libraries:   WinAPI, Stl, XLib
* Author:      Alca
* E-mail:      dr.web.agent@gmail.com
* Created:     25.07.2009 21:38:38
* Version:     1.0.0.0 Debug
*
*****************************************************************************/


#ifndef XLib_Gui_CxPushButtonH
#define XLib_Gui_CxPushButtonH
//---------------------------------------------------------------------------
#include <XLib/GUI/CxWindow.h>
#include <XLib/GUI/CxButtonBase.h>
//---------------------------------------------------------------------------
class CxPushButton: public CxButtonBase {
	public:
		//-------------------------------------
		//���������

		//���������
		enum ECheckState {
			csUknown     = - 1,
			csChecked	 = BST_CHECKED,
			csUnchecked	 = BST_UNCHECKED,	
		};	
		
		//����� (�����������/�����)
		enum EViewStyle {
			vsText   = BS_TEXT,
			vsBitmap = BS_BITMAP,
			vsIcon   = BS_ICON
		};

		//��� �����������
		enum EImageType {
			itBitmap   = IMAGE_BITMAP,
			itIcon	   = IMAGE_ICON,
			itCursor   = IMAGE_CURSOR,
			itMetaFile = IMAGE_ENHMETAFILE
		};
		
			        CxPushButton (BOOL bRadioButtonLike);
		virtual    ~CxPushButton ();
			
	    BOOL        bCreateRes   (INT iID, CxWindow *pwndParent);

		//-------------------------------------
		//���������
		BOOL        bSetViewStyle(EViewStyle vsViewStyle);	
		BOOL        bSetImage    (EImageType itImageType, HANDLE hImage);
		
		ECheckState csGetState   ();							
		BOOL        bSetState    (CxPushButton::ECheckState csCheckState);	

		//-------------------------------------
		//�������

	private:
		EViewStyle _m_vsViewStyle;
};
//---------------------------------------------------------------------------
#endif	//XLib_Gui_CxPushButtonH