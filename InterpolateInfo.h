//---------------------------------------------------------------------------

#ifndef InterpolateInfoH
#define InterpolateInfoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>

#include "Functions.h"
//---------------------------------------------------------------------------
const double STEP = 0.1;

class TChildForm : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl;
	TTabSheet *FunctionsTabSheet;
	TTabSheet *ExTabSheet;
	TTabSheet *ValueTabSheet;
	TTabSheet *CoeffTableSheet;
	TChart *Graphic;
	TFastLineSeries *FSeries;
	TLineSeries *PSeries;
	TLabel *EmoValueLabel;
	TLabel *EcoValueLabel;
	TButton *GraphicFigureSaveButton;
	TMemo *ValueTableMemo;
	TButton *ValueTableSaveButton;
	TButton *CoeffTableSaveButton;
	TMemo *CoeffTableMemo;
	void __fastcall FormShow(TObject *Sender);

private:	// User declarations
	InterpInfo* itsInterpInfo;
    Polynomial* itsPoly;
	std::vector<double> xVec;
public:		// User declarations
	__fastcall TChildForm(TComponent* Owner);
	void initializeInterpInfo(InterpInfo* info);
    void drawFunctionsOnGraph();
};
//---------------------------------------------------------------------------
extern PACKAGE TChildForm *ChildForm;
//---------------------------------------------------------------------------
#endif
