// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainView.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) { }

// ---------------------------------------------------------------------------
void __fastcall TMainForm::InterpolateButtonClick(TObject *Sender) {
	double aValue = AValueEdit->Text.ToDouble();
	double bValue = BValueEdit->Text.ToDouble();
	size_t NValue = NValueEdit->Text.ToInt();

	std::wstring strFunction(FunctionsComboBox->Text.c_str());
	std::wstring strPolynomial(PolynomialsComboBox->Text.c_str());

	ChildForm->initialize( { strFunction, strPolynomial, aValue, bValue, NValue } );
	ChildForm->ShowModal();
}
// ---------------------------------------------------------------------------
