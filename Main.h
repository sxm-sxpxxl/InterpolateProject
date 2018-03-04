//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VCLTee.TeeFunci.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>

#include "InterpolateInfo.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TComboBox *FunctionsComboBox;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *AValueEdit;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *BValueEdit;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *NValueEdit;
	TButton *InterpolateButton;
	TChart *Chart1;
	TFastLineSeries *FSeries;
	TLineSeries *PSeries;
	void __fastcall InterpolateButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
