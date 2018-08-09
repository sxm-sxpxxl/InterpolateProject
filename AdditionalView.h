// ---------------------------------------------------------------------------

#ifndef AdditionalViewH
#define AdditionalViewH
// ---------------------------------------------------------------------------
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

#include "PolynomialAndInterpInfo.h"
#include <Vcl.Dialogs.hpp>
// ---------------------------------------------------------------------------
const double STEP = 0.1;

class TChildForm : public TForm {
__published: // IDE-managed Components
	TPageControl *PageControl;
	TTabSheet *FunctionsTabSheet;
	TTabSheet *ExTabSheet;
	TTabSheet *ValueTabSheet;
	TTabSheet *CoeffTableSheet;
	TChart *Graphic;
	TFastLineSeries *FSeries;
	TLineSeries *PSeries;
	TLabel *emoLabel;
	TLabel *ecoLabel;
	TButton *GraphicFigureSaveButton;
	TMemo *ValueTableMemo;
	TButton *ValueTableSaveButton;
	TButton *CoeffTableSaveButton;
	TMemo *CoeffTableMemo;
	TChart *ErrorChart;
	TFastLineSeries *ESeries;
	TButton *ErrorSaveButton;
	TLabel *EmoValueLabel;
	TLabel *EcoValueLabel;
	TGroupBox *GroupBox1;
	TSaveDialog *SaveChartDialog_FP;
	TSaveDialog *SaveChartDialog_E;

	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall GraphicFigureSaveButtonClick(TObject *Sender);
	void __fastcall ErrorSaveButtonClick(TObject *Sender);

private: // User declarations
	const InterpInfo* itsInterpInfo;
	BasePolynomial* itsPoly;

	void drawFunctionsOnGraph();
    void saveChart(TChart* pChart, TSaveDialog* pSaveDialog);
public: // User declarations
	__fastcall TChildForm(TComponent* Owner);
	void initialize(const InterpInfo & info);
};

// ---------------------------------------------------------------------------
extern PACKAGE TChildForm *ChildForm;
// ---------------------------------------------------------------------------
#endif
