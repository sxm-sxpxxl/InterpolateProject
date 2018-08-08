﻿// ---------------------------------------------------------------------------

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
	TLabel *EmoValueLabel;
	TLabel *EcoValueLabel;
	TButton *GraphicFigureSaveButton;
	TMemo *ValueTableMemo;
	TButton *ValueTableSaveButton;
	TButton *CoeffTableSaveButton;
	TMemo *CoeffTableMemo;
	TChart *Chart1;
	TFastLineSeries *ESeries;
	TButton *Button1;

	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private: // User declarations
	const InterpInfo* itsInterpInfo;
	BasePolynomial* itsPoly;

	std::vector<double> xVec;
	void drawFunctionsOnGraph();

public: // User declarations
	__fastcall TChildForm(TComponent* Owner);
	void initialize(const InterpInfo & info);
};

// ---------------------------------------------------------------------------
extern PACKAGE TChildForm *ChildForm;
// ---------------------------------------------------------------------------
#endif
