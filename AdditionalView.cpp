// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AdditionalView.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChildForm *ChildForm;

// ---------------------------------------------------------------------------
__fastcall TChildForm::TChildForm(TComponent* Owner) : TForm(Owner) {
    itsInterpInfo = nullptr;
	itsPoly = nullptr;
}

// ---------------------------------------------------------------------------
void __fastcall TChildForm::FormShow(TObject *Sender) {
	this->Caption = L"Интерполирование функции F(x) = " + (UnicodeString)
		itsInterpInfo->functionStr.c_str() + L" на интервале [" +
		(UnicodeString)itsInterpInfo->a + L" ; " + (UnicodeString)
		itsInterpInfo->b + L"]";
	drawFunctionsOnGraph();
	PageControl->ActivePage = FunctionsTabSheet;
}

// ---------------------------------------------------------------------------
void TChildForm::initialize(const InterpInfo & info) {
    itsInterpInfo = new InterpInfo(info);
}

// ---------------------------------------------------------------------------
void TChildForm::drawFunctionsOnGraph() {
	{
		double xCurrent = itsInterpInfo->a;
		for (int i = 0; i <= (int) (abs(itsInterpInfo->b - itsInterpInfo->a) / STEP) + 1; i++) {
			FSeries->AddXY(xCurrent, func(xCurrent), NULL, FSeries->Color);
			xVec.push_back(xCurrent);
			xCurrent += STEP;
		}
	}

	if (itsInterpInfo->polynomialStr.compare(LAGRANGE_POLYNOMIAL_STR) == 0)
		itsPoly = new LagrangePolynomial(itsInterpInfo);
	else if (itsInterpInfo->polynomialStr.compare(NEWTON_I_POLYNOMIAL_STR) == 0)
		itsPoly = new NewtonIPoly(itsInterpInfo);
	else if (itsInterpInfo->polynomialStr.compare(NEWTON_II_POLYNOMIAL_STR) == 0)
		itsPoly = new NewtonIIPoly(itsInterpInfo);

	if (itsPoly == nullptr)
		throw 1;

	for (int i = 0; i <= (int)(abs(itsInterpInfo->b - itsInterpInfo->a) / STEP) + 1; i++) {
        double x = xVec[i];
		double val = itsPoly->functionPolynomial(xVec[i]);
		PSeries->AddXY(
			xVec[i],
			itsPoly->functionPolynomial(xVec[i]),
			NULL,
			PSeries->Color
		);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TChildForm::FormClose(TObject *Sender, TCloseAction &Action) {
	PSeries->Clear();
	FSeries->Clear();
    xVec.clear();
	delete itsPoly;
    delete itsInterpInfo;
}
// ---------------------------------------------------------------------------
