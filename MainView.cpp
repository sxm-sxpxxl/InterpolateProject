//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner) { }
//---------------------------------------------------------------------------
void __fastcall TMainForm::InterpolateButtonClick(TObject *Sender)
{
	double aValue = AValueEdit->Text.ToDouble();
	double bValue = BValueEdit->Text.ToDouble();
	double NValue = NValueEdit->Text.ToInt();

	InterpInfo* info = new InterpInfo;
	std::wstring strFunction(FunctionsComboBox->Text.c_str());
	std::wstring strPolynomial(PolynomialsComboBox->Text.c_str());

	info->functionStr = strFunction;
    info->polynomialStr = strPolynomial;
	info->a = aValue;
	info->b = bValue;
	info->N = NValue;

    ChildForm->initializeInterpInfo(info);
	ChildForm->ShowModal();
}
//---------------------------------------------------------------------------
