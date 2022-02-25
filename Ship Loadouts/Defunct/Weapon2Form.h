#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ShipLoadouts {

	/// <summary>
	/// Summary for Weapon2Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Weapon2Form : public System::Windows::Forms::Form
	{
	public:
		Weapon2Form(void)
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
		~Weapon2Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  W2_RefireLabel;
	private: System::Windows::Forms::TextBox^  Weapon2FormRefireTextBox;
	protected: 

	private: System::Windows::Forms::Label^  W2_EPSLabel;
	private: System::Windows::Forms::TextBox^  Weapon2FormEPSTextBox;

	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  UpdateButton;
	private: System::Windows::Forms::TextBox^  Weapon2FormvsATextBox;
	private: System::Windows::Forms::TextBox^  Weapon2FormvsSTextBox;
	private: System::Windows::Forms::TextBox^  Weapon2FormMaxDTextBox;
	private: System::Windows::Forms::TextBox^  Weapon2FormMinDTextBox;
	private: System::Windows::Forms::TextBox^  Weapon2FormDrainTextBox;
	private: System::Windows::Forms::TextBox^  Weapon2FormMassTextBox;
	private: System::Windows::Forms::TextBox^  Weapon2FormArmorTextBox;
	private: System::Windows::Forms::Label^  W2_vsALabel;
	private: System::Windows::Forms::Label^  W2_vsSLabel;
	private: System::Windows::Forms::Label^  W2_MaxDLabel;
	private: System::Windows::Forms::Label^  W2_MinDLabel;
	private: System::Windows::Forms::Label^  W2_DrainLabel;
	private: System::Windows::Forms::Label^  W2_MassLabel;
	private: System::Windows::Forms::Label^  W2_ArmorLabel;
	private: System::Windows::Forms::Label^  Weapon2FormLabel;

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
			this->W2_RefireLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon2FormRefireTextBox = (gcnew System::Windows::Forms::TextBox());
			this->W2_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon2FormEPSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->Weapon2FormvsATextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon2FormvsSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon2FormMaxDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon2FormMinDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon2FormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon2FormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon2FormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->W2_vsALabel = (gcnew System::Windows::Forms::Label());
			this->W2_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->W2_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MassLabel = (gcnew System::Windows::Forms::Label());
			this->W2_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon2FormLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// W2_RefireLabel
			// 
			this->W2_RefireLabel->AutoSize = true;
			this->W2_RefireLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_RefireLabel->Location = System::Drawing::Point(46, 237);
			this->W2_RefireLabel->Name = L"W2_RefireLabel";
			this->W2_RefireLabel->Size = System::Drawing::Size(51, 16);
			this->W2_RefireLabel->TabIndex = 145;
			this->W2_RefireLabel->Text = L"Refire:";
			// 
			// Weapon2FormRefireTextBox
			// 
			this->Weapon2FormRefireTextBox->Location = System::Drawing::Point(147, 236);
			this->Weapon2FormRefireTextBox->Name = L"Weapon2FormRefireTextBox";
			this->Weapon2FormRefireTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon2FormRefireTextBox->TabIndex = 144;
			// 
			// W2_EPSLabel
			// 
			this->W2_EPSLabel->AutoSize = true;
			this->W2_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_EPSLabel->Location = System::Drawing::Point(46, 211);
			this->W2_EPSLabel->Name = L"W2_EPSLabel";
			this->W2_EPSLabel->Size = System::Drawing::Size(39, 16);
			this->W2_EPSLabel->TabIndex = 143;
			this->W2_EPSLabel->Text = L"EPS:";
			// 
			// Weapon2FormEPSTextBox
			// 
			this->Weapon2FormEPSTextBox->Location = System::Drawing::Point(147, 210);
			this->Weapon2FormEPSTextBox->Name = L"Weapon2FormEPSTextBox";
			this->Weapon2FormEPSTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon2FormEPSTextBox->TabIndex = 142;
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
			// Weapon2FormvsATextBox
			// 
			this->Weapon2FormvsATextBox->Location = System::Drawing::Point(147, 184);
			this->Weapon2FormvsATextBox->Name = L"Weapon2FormvsATextBox";
			this->Weapon2FormvsATextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon2FormvsATextBox->TabIndex = 139;
			// 
			// Weapon2FormvsSTextBox
			// 
			this->Weapon2FormvsSTextBox->Location = System::Drawing::Point(147, 158);
			this->Weapon2FormvsSTextBox->Name = L"Weapon2FormvsSTextBox";
			this->Weapon2FormvsSTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon2FormvsSTextBox->TabIndex = 138;
			// 
			// Weapon2FormMaxDTextBox
			// 
			this->Weapon2FormMaxDTextBox->Location = System::Drawing::Point(147, 132);
			this->Weapon2FormMaxDTextBox->Name = L"Weapon2FormMaxDTextBox";
			this->Weapon2FormMaxDTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon2FormMaxDTextBox->TabIndex = 137;
			// 
			// Weapon2FormMinDTextBox
			// 
			this->Weapon2FormMinDTextBox->Location = System::Drawing::Point(147, 106);
			this->Weapon2FormMinDTextBox->Name = L"Weapon2FormMinDTextBox";
			this->Weapon2FormMinDTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon2FormMinDTextBox->TabIndex = 136;
			// 
			// Weapon2FormDrainTextBox
			// 
			this->Weapon2FormDrainTextBox->Location = System::Drawing::Point(147, 80);
			this->Weapon2FormDrainTextBox->Name = L"Weapon2FormDrainTextBox";
			this->Weapon2FormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon2FormDrainTextBox->TabIndex = 135;
			// 
			// Weapon2FormMassTextBox
			// 
			this->Weapon2FormMassTextBox->Location = System::Drawing::Point(147, 54);
			this->Weapon2FormMassTextBox->Name = L"Weapon2FormMassTextBox";
			this->Weapon2FormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon2FormMassTextBox->TabIndex = 134;
			// 
			// Weapon2FormArmorTextBox
			// 
			this->Weapon2FormArmorTextBox->Location = System::Drawing::Point(147, 28);
			this->Weapon2FormArmorTextBox->Name = L"Weapon2FormArmorTextBox";
			this->Weapon2FormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon2FormArmorTextBox->TabIndex = 133;
			// 
			// W2_vsALabel
			// 
			this->W2_vsALabel->AutoSize = true;
			this->W2_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_vsALabel->Location = System::Drawing::Point(46, 185);
			this->W2_vsALabel->Name = L"W2_vsALabel";
			this->W2_vsALabel->Size = System::Drawing::Size(72, 16);
			this->W2_vsALabel->TabIndex = 132;
			this->W2_vsALabel->Text = L"vs Armor:";
			// 
			// W2_vsSLabel
			// 
			this->W2_vsSLabel->AutoSize = true;
			this->W2_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_vsSLabel->Location = System::Drawing::Point(46, 159);
			this->W2_vsSLabel->Name = L"W2_vsSLabel";
			this->W2_vsSLabel->Size = System::Drawing::Size(80, 16);
			this->W2_vsSLabel->TabIndex = 131;
			this->W2_vsSLabel->Text = L"vs Sheilds:";
			// 
			// W2_MaxDLabel
			// 
			this->W2_MaxDLabel->AutoSize = true;
			this->W2_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MaxDLabel->Location = System::Drawing::Point(46, 133);
			this->W2_MaxDLabel->Name = L"W2_MaxDLabel";
			this->W2_MaxDLabel->Size = System::Drawing::Size(97, 16);
			this->W2_MaxDLabel->TabIndex = 130;
			this->W2_MaxDLabel->Text = L"Max Damage:";
			// 
			// W2_MinDLabel
			// 
			this->W2_MinDLabel->AutoSize = true;
			this->W2_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MinDLabel->Location = System::Drawing::Point(46, 107);
			this->W2_MinDLabel->Name = L"W2_MinDLabel";
			this->W2_MinDLabel->Size = System::Drawing::Size(93, 16);
			this->W2_MinDLabel->TabIndex = 129;
			this->W2_MinDLabel->Text = L"Min Damage:";
			// 
			// W2_DrainLabel
			// 
			this->W2_DrainLabel->AutoSize = true;
			this->W2_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_DrainLabel->Location = System::Drawing::Point(46, 81);
			this->W2_DrainLabel->Name = L"W2_DrainLabel";
			this->W2_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->W2_DrainLabel->TabIndex = 128;
			this->W2_DrainLabel->Text = L"Drain:";
			// 
			// W2_MassLabel
			// 
			this->W2_MassLabel->AutoSize = true;
			this->W2_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MassLabel->Location = System::Drawing::Point(46, 55);
			this->W2_MassLabel->Name = L"W2_MassLabel";
			this->W2_MassLabel->Size = System::Drawing::Size(47, 16);
			this->W2_MassLabel->TabIndex = 127;
			this->W2_MassLabel->Text = L"Mass:";
			// 
			// W2_ArmorLabel
			// 
			this->W2_ArmorLabel->AutoSize = true;
			this->W2_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_ArmorLabel->Location = System::Drawing::Point(46, 29);
			this->W2_ArmorLabel->Name = L"W2_ArmorLabel";
			this->W2_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->W2_ArmorLabel->TabIndex = 126;
			this->W2_ArmorLabel->Text = L"Armor:";
			// 
			// Weapon2FormLabel
			// 
			this->Weapon2FormLabel->AutoSize = true;
			this->Weapon2FormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon2FormLabel->Location = System::Drawing::Point(94, 8);
			this->Weapon2FormLabel->Name = L"Weapon2FormLabel";
			this->Weapon2FormLabel->Size = System::Drawing::Size(104, 16);
			this->Weapon2FormLabel->TabIndex = 125;
			this->Weapon2FormLabel->Text = L"W e a p o n  2";
			// 
			// Weapon2Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(292, 298);
			this->Controls->Add(this->W2_RefireLabel);
			this->Controls->Add(this->Weapon2FormRefireTextBox);
			this->Controls->Add(this->W2_EPSLabel);
			this->Controls->Add(this->Weapon2FormEPSTextBox);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->Weapon2FormvsATextBox);
			this->Controls->Add(this->Weapon2FormvsSTextBox);
			this->Controls->Add(this->Weapon2FormMaxDTextBox);
			this->Controls->Add(this->Weapon2FormMinDTextBox);
			this->Controls->Add(this->Weapon2FormDrainTextBox);
			this->Controls->Add(this->Weapon2FormMassTextBox);
			this->Controls->Add(this->Weapon2FormArmorTextBox);
			this->Controls->Add(this->W2_vsALabel);
			this->Controls->Add(this->W2_vsSLabel);
			this->Controls->Add(this->W2_MaxDLabel);
			this->Controls->Add(this->W2_MinDLabel);
			this->Controls->Add(this->W2_DrainLabel);
			this->Controls->Add(this->W2_MassLabel);
			this->Controls->Add(this->W2_ArmorLabel);
			this->Controls->Add(this->Weapon2FormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Weapon2Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Weapon 2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
