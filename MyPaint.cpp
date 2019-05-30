//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <windows.h>

#include "MyPaint.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
bool penMove=false,EraserMove=false,save=false;
float x,y;
TForm1 *Form1;
//---------------------------------------------------------------------------
Graphics::TBitmap*   Bitmap = new Graphics::TBitmap;
void Clear();
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
	if(OpenPictureDialog1->Execute()) {
		Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
		Bitmap->Assign(Image1->Picture);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if(SBBrush->Down==true)
	{
		penMove=false;
		//Screen->Cursor=crNo;
	}
	if(SBRectangle->Down==true)
	{
	   Image1->Canvas->Rectangle(x,y,X,Y);
	}
	if(SBEraser->Down==true)
	{
		EraserMove=false;
		Image1->Canvas->Pen->Color=clBlack;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	save=true;
	if(SBBrush->Down==true)
	{
		penMove=true;
		Image1->Canvas->MoveTo(X,Y);
	}
	if(SBRectangle->Down==true)
	{
		x=X,y=Y;
	}
	if(SBEraser->Down==true)
	{
		Image1->Canvas->Pen->Color=clWhite;
		penMove=false;
		EraserMove=true;
		Image1->Canvas->MoveTo(X,Y);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	if(penMove==true)
	{
		Image1->Canvas->LineTo(X,Y);
	}
	if(EraserMove==true)
	{
		Image1->Canvas->LineTo(X,Y);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpinEdit1Change(TObject *Sender)
{
	TrackBar1->Position=SpinEdit1->Value;
	Image1->Canvas->Pen->Width=SpinEdit1->Value;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	SpinEdit1->Value=TrackBar1->Position;
	Image1->Canvas->Pen->Width=SpinEdit1->Value;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	if(save==true)
	{
		if(MessageDlg(L"��������� �������?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		{
			if(SavePictureDialog1->Execute()) {
				Image1->Picture->SaveToFile(SavePictureDialog1->FileName);
				save=false;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
	if(SavePictureDialog1->Execute())
	{
		Image1->Picture->SaveToFile(SavePictureDialog1->FileName);
        save=false;
	}
}
//---------------------------------------------------------------------------
void Clear()
{
	Form1->Image1->Canvas->Brush->Color = clWhite;
	Form1->Image1->Canvas->FillRect(Rect(0,0,Form1->Image1->Width,
												Form1->Image1->Height));
	save=false;
}
//---------------------------------------------------------------------------
