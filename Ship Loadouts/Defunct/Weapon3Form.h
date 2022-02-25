#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ShipLoadouts {

	/// <summary>
	/// Summary for Weapon3Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Weapon3Form : public System::Windows::Forms::Form
	{
	public:
		Weapon3Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Weapon3Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  W3_RefireLabel;
	private: System::Windows::Forms::TextBox^  Weapon3FormRefireTextBox;
	protected: 

	private: System::Windows::Forms::Label^  W3_EPSLabel;
	private: System::Windows::Forms::TextBox^  Weapon3FormEPSTextBox;

	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  UpdateButton;
	private: System::Windows::Forms::TextBox^  Weapon3FormvsATextBox;

	private: System::Windows::Forms::TextBox^  Weapon3FormvsSTextBox;

	private: System::Windows::Forms::TextBox^  Weapon3FormMaxDTextBox;

	private: System::Windows::Forms::TextBox^  Weapon3FormMinDTextBox;

	private: System::Windows::Forms::TextBox^  Weapon3FormDrainTextBox;
	private: System::Windows::Forms::TextBox^  Weapon3FormMassTextBox;
	private: System::Windows::Forms::TextBox^  Weapon3FormArmorTextBox;
	private: System::Windows::Forms::Label^  W3_vsALabel;
	private: System::Windows::Forms::Label^  W3_vsSLabel;
	private: System::Windows::Forms::Label^  W3_MaxDLabel;
	private: System::Windows::Forms::Label^  W3_MinDLabel;
	private: System::Windows::Forms::Label^  W3_DrainLabel;
	private: System::Windows::Forms::Label^  W3_MassLabel;
	private: System::Windows::Forms::Label^  W3_ArmorLabel;
	private: System::Windows::Forms::Label^  Weapon3FormLabel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->W3_RefireLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon3FormRefireTextBox = (gcnew System::Windows::Forms::TextBox());
			this->W3_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon3FormEPSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->Weapon3FormvsATextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon3FormvsSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon3FormMaxDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon3FormMinDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon3FormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon3FormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon3FormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->W3_vsALabel = (gcnew System::Windows::Forms::Label());
			this->W3_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->W3_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MassLabel = (gcnew System::Windows::Forms::Label());
			this->W3_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon3FormLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// W3_RefireLabel
			// 
			this->W3_RefireLabel->AutoSize = true;
			this->W3_RefireLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_RefireLabel->Location = System::Drawing::Point(46, 237);
			this->W3_RefireLabel->Name = L"W3_RefireLabel";
			this->W3_RefireLabel->Size = System::Drawing::Size(51, 16);
			this->W3_RefireLabel->TabIndex = 145;
			this->W3_RefireLabel->Text = L"Refire:";
			// 
			// Weapon3FormRefireTextBox
			// 
			this->Weapon3FormRefireTextBox->Location = System::Drawing::Point(147, 236);
			this->Weapon3FormRefireTextBox->Name = L"Weapon3FormRefireTextBox";
			this->Weapon3FormRefireTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon3FormRefireTextBox->TabIndex = 144;
			// 
			// W3_EPSLabel
			// 
			this->W3_EPSLabel->AutoSize = true;
			this->W3_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_EPSLabel->Location = System::Drawing::Point(46, 211);
			this->W3_EPSLabel->Name = L"W3_EPSLabel";
			this->W3_EPSLabel->Size = System::Drawing::Size(39, 16);
			this->W3_EPSLabel->TabIndex = 143;
			this->W3_EPSLabel->Text = L"EPS:";
			// 
			// Weapon3FormEPSTextBox
			// 
			this->Weapon3FormEPSTextBox->Location = System::Drawing::Point(147, 210);
			this->Weapon3FormEPSTextBox->Name = L"Weapon3FormEPSTextBox";
			this->Weapon3FormEPSTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon3FormEPSTextBox->TabIndex = 142;
			// 
			// CancelButton
			// 
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 267);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 141;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			// 
			// UpdateButton
			// 
			this->UpdateButton->ForeColor = System::Drawing::Color::Black;
			this->UpdateButton->Location = System::Drawing::Point(68, 267);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(75, 23);
			this->UpdateButton->TabIndex = 140;
			this->UpdateButton->Text = L"Update";
			this->UpdateButton->UseVisualStyleBackColor = true;
			// 
			// Weapon3FormvsATextBox
			// 
			this->Weapon3FormvsATextBox->Location = System::Drawing::Point(147, 184);
			this->Weapon3FormvsATextBox->Name = L"Weapon3FormvsATextBox";
			this->Weapon3FormvsATextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon3FormvsATextBox->TabIndex = 139;
			// 
			// Weapon3FormvsSTextBox
			// 
			this->Weapon3FormvsSTextBox->Location = System::Drawing::Point(147, 158);
			this->Weapon3FormvsSTextBox->Name = L"Weapon3FormvsSTextBox";
			this->Weapon3FormvsSTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon3FormvsSTextBox->TabIndex = 138;
			// 
			// Weapon3FormMaxDTextBox
			// 
			this->Weapon3FormMaxDTextBox->Location = System::Drawing::Point(147, 132);
			this->Weapon3FormMaxDTextBox->Name = L"Weapon3FormMaxDTextBox";
			this->Weapon3FormMaxDTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon3FormMaxDTextBox->TabIndex = 137;
			// 
			// Weapon3FormMinDTextBox
			// 
			this->Weapon3FormMinDTextBox->Location = System::Drawing::Point(147, 106);
			this->Weapon3FormMinDTextBox->Name = L"Weapon3FormMinDTextBox";
			this->Weapon3FormMinDTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon3FormMinDTextBox->TabIndex = 136;
			// 
			// Weapon3FormDrainTextBox
			// 
			this->Weapon3FormDrainTextBox->Location = System::Drawing::Point(147, 80);
			this->Weapon3FormDrainTextBox->Name = L"Weapon3FormDrainTextBox";
			this->Weapon3FormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon3FormDrainTextBox->TabIndex = 135;
			// 
			// Weapon3FormMassTextBox
			// 
			this->Weapon3FormMassTextBox->Location = System::Drawing::Point(147, 54);
			this->Weapon3FormMassTextBox->Name = L"Weapon3FormMassTextBox";
			this->Weapon3FormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon3FormMassTextBox->TabIndex = 134;
			// 
			// Weapon3FormArmorTextBox
			// 
			this->Weapon3FormArmorTextBox->Location = System::Drawing::Point(147, 28);
			this->Weapon3FormArmorTextBox->Name = L"Weapon3FormArmorTextBox";
			this->Weapon3FormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon3FormArmorTextBox->TabIndex = 133;
			// 
			// W3_vsALabel
			// 
			this->W3_vsALabel->AutoSize = true;
			this->W3_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_vsALabel->Location = System::Drawing::Point(46, 185);
			this->W3_vsALabel->Name = L"W3_vsALabel";
			this->W3_vsALabel->Size = System::Drawing::Size(72, 16);
			this->W3_vsALabel->TabIndex = 132;
			this->W3_vsALabel->Text = L"vs Armor:";
			// 
			// W3_vsSLabel
			// 
			this->W3_vsSLabel->AutoSize = true;
			this->W3_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_vsSLabel->Location = System::Drawing::Point(46, 159);
			this->W3_vsSLabel->Name = L"W3_vsSLabel";
			this->W3_vsSLabel->Size = System::Drawing::Size(80, 16);
			this->W3_vsSLabel->TabIndex = 131;
			this->W3_vsSLabel->Text = L"vs Sheilds:";
			// 
			// W3_MaxDLabel
			// 
			this->W3_MaxDLabel->AutoSize = true;
			this->W3_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MaxDLabel->Location = System::Drawing::Point(46, 133);
			this->W3_MaxDLabel->Name = L"W3_MaxDLabel";
			this->W3_MaxDLabel->Size = System::Drawing::Size(97, 16);
			this->W3_MaxDLabel->TabIndex = 130;
			this->W3_MaxDLabel->Text = L"Max Damage:";
			// 
			// W3_MinDLabel
			// 
			this->W3_MinDLabel->AutoSize = true;
			this->W3_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MinDLabel->Location = System::Drawing::Point(46, 107);
			this->W3_MinDLabel->Name = L"W3_MinDLabel";
			this->W3_MinDLabel->Size = System::Drawing::Size(93, 16);
			this->W3_MinDLabel->TabIndex = 129;
			this->W3_MinDLabel->Text = L"Min Damage:";
			// 
			// W3_DrainLabel
			// 
			this->W3_DrainLabel->AutoSize = true;
			this->W3_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_DrainLabel->Location = System::Drawing::Point(46, 81);
			this->W3_DrainLabel->Name = L"W3_DrainLabel";
			this->W3_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->W3_DrainLabel->TabIndex = 128;
			this->W3_DrainLabel->Text = L"Drain:";
			// 
			// W3_MassLabel
			// 
			this->W3_MassLabel->AutoSize = true;
			this->W3_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MassLabel->Location = System::Drawing::Point(46, 55);
			this->W3_MassLabel->Name = L"W3_MassLabel";
			this->W3_MassLabel->Size = System::Drawing::Size(47, 16);
			this->W3_MassLabel->TabIndex = 127;
			this->W3_MassLabel->Text = L"Mass:";
			// 
			// W3_ArmorLabel
			// 
			this->W3_ArmorLabel->AutoSize = true;
			this->W3_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_ArmorLabel->Location = System::Drawing::Point(46, 29);
			this->W3_ArmorLabel->Name = L"W3_ArmorLabel";
			this->W3_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->W3_ArmorLabel->TabIndex = 126;
			this->W3_ArmorLabel->Text = L"Armor:";
			// 
			// Weapon3FormLabel
			// 
			this->Weapon3FormLabel->AutoSize = true;
			this->Weapon3FormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon3FormLabel->Location = System::Drawing::Point(94, 8);
			this->Weapon3FormLabel->Name = L"Weapon3FormLabel";
			this->Weapon3FormLabel->Size = System::Drawing::Size(104, 16);
			this->Weapon3FormLabel->TabIndex = 125;
			this->Weapon3FormLabel->Text = L"W e a p o n  3";
			// 
			// Weapon3Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(292, 298);
			this->Controls->Add(this->W3_RefireLabel);
			this->Controls->Add(this->Weapon3FormRefireTextBox);
			this->Controls->Add(this->W3_EPSLabel);
			this->Controls->Add(this->Weapon3FormEPSTextBox);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->Weapon3FormvsATextBox);
			this->Controls->Add(this->Weapon3FormvsSTextBox);
			this->Controls->Add(this->Weapon3FormMaxDTextBox);
			this->Controls->Add(this->Weapon3FormMinDTextBox);
			this->Controls->Add(this->Weapon3FormDrainTextBox);
			this->Controls->Add(this->Weapon3FormMassTextBox);
			this->Controls->Add(this->Weapon3FormArmorTextBox);
			this->Controls->Add(this->W3_vsALabel);
			this->Controls->Add(this->W3_vsSLabel);
			this->Controls->Add(this->W3_MaxDLabel);
			this->Controls->Add(this->W3_MinDLabel);
			this->Controls->Add(this->W3_DrainLabel);
			this->Controls->Add(this->W3_MassLabel);
			this->Controls->Add(this->W3_ArmorLabel);
			this->Controls->Add(this->Weapon3FormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Weapon3Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Weapon 3";
//			this->Load += gcnew System::EventHandler(this, &Weapon3Form::Weapon3Form_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}
