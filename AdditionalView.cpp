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
	if (itsInterpInfo->polynomialStr.compare(LAGRANGE_POLYNOMIAL_STR) == 0)
		itsPoly = new LagrangePolynomial(itsInterpInfo);
	else if (itsInterpInfo->polynomialStr.compare(NEWTON_I_POLYNOMIAL_STR) == 0)
		itsPoly = new NewtonIPoly(itsInterpInfo);
	else if (itsInterpInfo->polynomialStr.compare(NEWTON_II_POLYNOMIAL_STR) == 0)
		itsPoly = new NewtonIIPoly(itsInterpInfo);

	if (itsPoly == nullptr)
		throw 1;

	double xCurrent = itsInterpInfo->a;

	for (int i = 0; i <= (int)(abs(itsInterpInfo->b - itsInterpInfo->a) / STEP) + 1; i++, xCurrent += STEP) {
		FSeries->AddXY(
			xCurrent,
			func(xCurrent),
			NULL,
			FSeries->Color
		);

		PSeries->AddXY(
			xCurrent,
			itsPoly->functionPolynomial(xCurrent),
			NULL,
			PSeries->Color
		);

		ESeries->AddXY(
			xCurrent,
			abs(FSeries->YValues->operator[](xCurrent) - PSeries->YValues->operator[](xCurrent)),
			NULL,
			ESeries->Color
		);

        const UnicodeString format_template = L"0.000";
		ValueTableMemo->Lines->Add(
			FormatFloat(format_template, xCurrent) + L"\t\t" + \
			FormatFloat(format_template, FSeries->YValues->operator[](xCurrent)) + L"\t\t" + \
			FormatFloat(format_template, PSeries->YValues->operator[](xCurrent)) + L"\t\t" + \
            FormatFloat(format_template, ESeries->YValues->operator[](xCurrent)) + L"\n"
		);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TChildForm::FormClose(TObject *Sender, TCloseAction &Action) {
	PSeries->Clear();
	FSeries->Clear();
	ESeries->Clear();

	delete itsPoly;
	delete itsInterpInfo;
}

// ---------------------------------------------------------------------------
void __fastcall TChildForm::GraphicFigureSaveButtonClick(TObject *Sender)
{
    saveChart(Graphic, SaveChartDialog_FP);
}

//---------------------------------------------------------------------------
void __fastcall TChildForm::ErrorSaveButtonClick(TObject *Sender)
{
	saveChart(ErrorChart, SaveChartDialog_E);
}
//---------------------------------------------------------------------------

void TChildForm::saveChart(TChart* pChart, TSaveDialog* pSaveDialog) {
	if (pSaveDialog->Execute(this->Handle)) {
		pChart->SaveToBitmapFile(pSaveDialog->FileName);
		ShowMessage(L"Файл \"" + pSaveDialog->FileName + "\" успешно сохранен!");
	}
	else {
        ShowMessage(L"Сохранение не удалось!");
    }
}
