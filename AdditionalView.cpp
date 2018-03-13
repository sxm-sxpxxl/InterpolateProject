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

// Произвести рефакторинг данного участка кода, разбив ф-цию на процедуры.
// Подумать над целесообразностью хранения указателей на информацию об интерполяции, виде полинома
// и значениях аргумента в контексте TChildForm
void TChildForm::drawFunctionsOnGraph() {
	const double COUNT_ITERATION = abs(itsInterpInfo->b - itsInterpInfo->a) / STEP;
	const int COUNT_SYM_AFTER_DOTE = 3;

	std::vector<double> funcVec;
	double xCurrent = itsInterpInfo->a;
	for(int i = 0; i <= COUNT_ITERATION; i++) {
		funcVec.push_back(func(xCurrent));
		FSeries->AddXY(xCurrent, funcVec[i], NULL, FSeries->Color);
		xVec.push_back(xCurrent);
		xCurrent += STEP;
	}

	if(wcscmp(LAGRANGE_POLYNOMIAL_STR.c_str(), itsInterpInfo->polynomialStr.c_str()) == 0) itsPoly = new LagrangePolynomial(itsInterpInfo);
	if(wcscmp(NEWTON_I_POLYNOMIAL_STR.c_str(), itsInterpInfo->polynomialStr.c_str()) == 0) itsPoly = new NewtonIPoly(itsInterpInfo);
	if(wcscmp(NEWTON_II_POLYNOMIAL_STR.c_str(), itsInterpInfo->polynomialStr.c_str()) == 0) itsPoly = new NewtonIIPoly(itsInterpInfo);

	std::vector<double> polyVec;
	for(int i = 0; i <= COUNT_ITERATION; i++) {
		polyVec.push_back(itsPoly->functionPolynomial(xVec[i]));
		PSeries->AddXY(xVec[i], polyVec.back(), NULL, PSeries->Color);
		ESeries->AddXY(xVec[i], funcVec[i] - polyVec[i], ESeries->Color);

        UnicodeString xStr = (UnicodeString)xVec[i];
		UnicodeString funcStr = (UnicodeString)funcVec[i];
		UnicodeString polyStr = (UnicodeString)polyVec[i];
		UnicodeString diffFuncPoly = (UnicodeString)(funcVec[i] - polyVec[i]);

		funcStr = funcStr.SubString(0, COUNT_SYM_AFTER_DOTE + funcStr.Pos(L","));
		polyStr = polyStr.SubString(0, COUNT_SYM_AFTER_DOTE + polyStr.Pos(L","));
		diffFuncPoly = diffFuncPoly.SubString(0, COUNT_SYM_AFTER_DOTE + diffFuncPoly.Pos(L","));

		UnicodeString offsetStr = L"";
		if(xStr.Pos(L",") == 0) offsetStr = L"  ";

		UnicodeString str = xStr + L"                " + offsetStr + funcStr +
							L"                " + offsetStr + polyStr + L"                " + offsetStr + diffFuncPoly;
		ValueTableMemo->Lines->Add(str);
	}

	double STEP_X = abs(itsInterpInfo->b - itsInterpInfo->a) / (itsInterpInfo->N - 1);
    xCurrent = itsInterpInfo->a;
	for(int i = 0; i < itsInterpInfo->N; i++) {
		UnicodeString funcStr = (UnicodeString)func(xCurrent);
        funcStr = funcStr.SubString(0, COUNT_SYM_AFTER_DOTE + funcStr.Pos(L","));
		CoeffTableMemo->Lines->Add((UnicodeString)xCurrent + L"                " + funcStr);
		xCurrent += STEP_X;
    }

}
void __fastcall TChildForm::FormHide(TObject *Sender)
{
	delete itsPoly;
    itsPoly = NULL;
	delete itsInterpInfo;
    itsInterpInfo = NULL;
	xVec.clear();

	FSeries->Clear();
	PSeries->Clear();
	ESeries->Clear();
	ValueTableMemo->Clear();
    ValueTableMemo->Lines->Add(L"  x                  F(x)                  P(x)                  E(x)");
	CoeffTableMemo->Clear();
	CoeffTableMemo->Lines->Add(L"  X                  Y");
}
//---------------------------------------------------------------------------

