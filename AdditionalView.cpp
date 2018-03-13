//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AdditionalView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChildForm *ChildForm;
//---------------------------------------------------------------------------
__fastcall TChildForm::TChildForm(TComponent* Owner)
	: TForm(Owner) { }
//---------------------------------------------------------------------------
void __fastcall TChildForm::FormShow(TObject *Sender)
{
	this->Caption = L"Интерполирование фукнции F(x) = " + (UnicodeString)itsInterpInfo->functionStr.c_str() +
					L" на интервале [" + (UnicodeString)itsInterpInfo->a + L" ; " + (UnicodeString)itsInterpInfo->b + L"]";
    drawFunctionsOnGraph();
	PageControl->ActivePage = FunctionsTabSheet;
}
//---------------------------------------------------------------------------
void TChildForm::initializeInterpInfo(InterpInfo* info) {
	itsInterpInfo = info;
}
//---------------------------------------------------------------------------
void TChildForm::drawFunctionsOnGraph() {
    double xCurrent = itsInterpInfo->a;
	for(int i = 0; i < abs(itsInterpInfo->b - itsInterpInfo->a) / STEP; i++) {
		FSeries->AddXY(xCurrent, func(xCurrent), NULL, FSeries->Color);
		xVec.push_back(xCurrent);
		xCurrent += STEP;
	}

	itsPoly = new NewtonIIPoly(itsInterpInfo);
	for(int i = 0; i < abs(itsInterpInfo->b - itsInterpInfo->a) / STEP; i++) {
		PSeries->AddXY(xVec[i], itsPoly->functionPolynomial(xVec[i]), NULL, PSeries->Color);
	}

}

