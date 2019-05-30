//---------------------------------------------------------------------------

#ifndef MyPaintH
#define MyPaintH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include "cspin.h"
#include <Vcl.Samples.Spin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TImage *Image1;
	TSpeedButton *SBBrush;
	TSpeedButton *SBRectangle;
	TOpenPictureDialog *OpenPictureDialog1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TSpeedButton *SBEraser;
	TTrackBar *TrackBar1;
	TLabel *Label1;
	TSpinEdit *SpinEdit1;
	TMenuItem *N3;
	TSavePictureDialog *SavePictureDialog1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall SpinEdit1Change(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall N3Click(TObject *Sender);


private:	// User declarations

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
