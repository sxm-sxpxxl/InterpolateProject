//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InterpolateInfo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChildForm *ChildForm;
//---------------------------------------------------------------------------
__fastcall TChildForm::TChildForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TChildForm::FormShow(TObject *Sender)
{
	this->Caption = L"���������������� ������� F(x) = " + (UnicodeString)itsInterpInfo->functionStr.c_str() +
					L" �� ��������� [" + (UnicodeString)itsInterpInfo->a + L" ; " + (UnicodeString)itsInterpInfo->b + L"]";
    drawFunctionsOnGraph();
	PageControl->ActivePage = FunctionsTabSheet;
	//ShowMessage((UnicodeString)func(2));
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

	itsPoly = new Polynomial;
    buildPolynomialNewtonII(itsPoly, itsInterpInfo);
	for(int i = 0; i < abs(itsInterpInfo->b - itsInterpInfo->a) / STEP; i++) {
		PSeries->AddXY(xVec[i], polynomialLagrange(xVec[i], itsPoly, itsInterpInfo), NULL, PSeries->Color);
	}

}

