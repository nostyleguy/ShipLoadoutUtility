#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ShipLoadouts {

	/// <summary>
	/// Summary for Weapon4Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Weapon4Form : public System::Windows::Forms::Form
	{
	public:
		Weapon4Form(void)
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
		~Weapon4Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  W4_RefireLabel;
	private: System::Windows::Forms::TextBox^  Weapon4FormRefireTextBox;
	protected: 

	protected: 

	private: System::Windows::Forms::Label^  W4_EPSLabel;
	private: System::Windows::Forms::TextBox^  Weapon4FormEPSTextBox;


	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  UpdateButton;
	private: System::Windows::Forms::TextBox^  Weapon4FormvsATextBox;

	private: System::Windows::Forms::TextBox^  Weapon4FormvsSTextBox;

	private: System::Windows::Forms::TextBox^  Weapon4FormMaxDTextBox;

	private: System::Windows::Forms::TextBox^  Weapon4FormMinDTextBox;

	private: System::Windows::Forms::TextBox^  Weapon4FormDrainTextBox;

	private: System::Windows::Forms::TextBox^  Weapon4FormMassTextBox;

	private: System::Windows::Forms::TextBox^  Weapon4FormArmorTextBox;

	private: System::Windows::Forms::Label^  W4_vsALabel;

	private: System::Windows::Forms::Label^  W4_vsSLabel;

	private: System::Windows::Forms::Label^  W4_MaxDLabel;


	private: System::Windows::Forms::Label^  W4_MinDLabel;

	private: System::Windows::Forms::Label^  W4_DrainLabel;

	private: System::Windows::Forms::Label^  W4_MassLabel;

	private: System::Windows::Forms::Label^  W4_ArmorLabel;

	private: System::Windows::Forms::Label^  Weapon4FormLabel;


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
			this->W4_RefireLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon4FormRefireTextBox = (gcnew System::Windows::Forms::TextBox());
			this->W4_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon4FormEPSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->Weapon4FormvsATextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon4FormvsSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon4FormMaxDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon4FormMinDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon4FormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon4FormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Weapon4FormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->W4_vsALabel = (gcnew System::Windows::Forms::Label());
			this->W4_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->W4_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MassLabel = (gcnew System::Windows::Forms::Label());
			this->W4_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon4FormLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// W4_RefireLabel
			// 
			this->W4_RefireLabel->AutoSize = true;
			this->W4_RefireLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_RefireLabel->Location = System::Drawing::Point(46, 237);
			this->W4_RefireLabel->Name = L"W4_RefireLabel";
			this->W4_RefireLabel->Size = System::Drawing::Size(51, 16);
			this->W4_RefireLabel->TabIndex = 145;
			this->W4_RefireLabel->Text = L"Refire:";
			// 
			// Weapon4FormRefireTextBox
			// 
			this->Weapon4FormRefireTextBox->Location = System::Drawing::Point(147, 236);
			this->Weapon4FormRefireTextBox->Name = L"Weapon4FormRefireTextBox";
			this->Weapon4FormRefireTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon4FormRefireTextBox->TabIndex = 144;
			// 
			// W4_EPSLabel
			// 
			this->W4_EPSLabel->AutoSize = true;
			this->W4_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_EPSLabel->Location = System::Drawing::Point(46, 211);
			this->W4_EPSLabel->Name = L"W4_EPSLabel";
			this->W4_EPSLabel->Size = System::Drawing::Size(39, 16);
			this->W4_EPSLabel->TabIndex = 143;
			this->W4_EPSLabel->Text = L"EPS:";
			// 
			// Weapon4FormEPSTextBox
			// 
			this->Weapon4FormEPSTextBox->Location = System::Drawing::Point(147, 210);
			this->Weapon4FormEPSTextBox->Name = L"Weapon4FormEPSTextBox";
			this->Weapon4FormEPSTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon4FormEPSTextBox->TabIndex = 142;
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
			// Weapon4FormvsATextBox
			// 
			this->Weapon4FormvsATextBox->Location = System::Drawing::Point(147, 184);
			this->Weapon4FormvsATextBox->Name = L"Weapon4FormvsATextBox";
			this->Weapon4FormvsATextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon4FormvsATextBox->TabIndex = 139;
			// 
			// Weapon4FormvsSTextBox
			// 
			this->Weapon4FormvsSTextBox->Location = System::Drawing::Point(147, 158);
			this->Weapon4FormvsSTextBox->Name = L"Weapon4FormvsSTextBox";
			this->Weapon4FormvsSTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon4FormvsSTextBox->TabIndex = 138;
			// 
			// Weapon4FormMaxDTextBox
			// 
			this->Weapon4FormMaxDTextBox->Location = System::Drawing::Point(147, 132);
			this->Weapon4FormMaxDTextBox->Name = L"Weapon4FormMaxDTextBox";
			this->Weapon4FormMaxDTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon4FormMaxDTextBox->TabIndex = 137;
			// 
			// Weapon4FormMinDTextBox
			// 
			this->Weapon4FormMinDTextBox->Location = System::Drawing::Point(147, 106);
			this->Weapon4FormMinDTextBox->Name = L"Weapon4FormMinDTextBox";
			this->Weapon4FormMinDTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon4FormMinDTextBox->TabIndex = 136;
			// 
			// Weapon4FormDrainTextBox
			// 
			this->Weapon4FormDrainTextBox->Location = System::Drawing::Point(147, 80);
			this->Weapon4FormDrainTextBox->Name = L"Weapon4FormDrainTextBox";
			this->Weapon4FormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon4FormDrainTextBox->TabIndex = 135;
			// 
			// Weapon4FormMassTextBox
			// 
			this->Weapon4FormMassTextBox->Location = System::Drawing::Point(147, 54);
			this->Weapon4FormMassTextBox->Name = L"Weapon4FormMassTextBox";
			this->Weapon4FormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon4FormMassTextBox->TabIndex = 134;
			// 
			// Weapon4FormArmorTextBox
			// 
			this->Weapon4FormArmorTextBox->Location = System::Drawing::Point(147, 28);
			this->Weapon4FormArmorTextBox->Name = L"Weapon4FormArmorTextBox";
			this->Weapon4FormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->Weapon4FormArmorTextBox->TabIndex = 133;
			// 
			// W4_vsALabel
			// 
			this->W4_vsALabel->AutoSize = true;
			this->W4_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_vsALabel->Location = System::Drawing::Point(46, 185);
			this->W4_vsALabel->Name = L"W4_vsALabel";
			this->W4_vsALabel->Size = System::Drawing::Size(72, 16);
			this->W4_vsALabel->TabIndex = 132;
			this->W4_vsALabel->Text = L"vs Armor:";
			// 
			// W4_vsSLabel
			// 
			this->W4_vsSLabel->AutoSize = true;
			this->W4_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_vsSLabel->Location = System::Drawing::Point(46, 159);
			this->W4_vsSLabel->Name = L"W4_vsSLabel";
			this->W4_vsSLabel->Size = System::Drawing::Size(80, 16);
			this->W4_vsSLabel->TabIndex = 131;
			this->W4_vsSLabel->Text = L"vs Sheilds:";
			// 
			// W4_MaxDLabel
			// 
			this->W4_MaxDLabel->AutoSize = true;
			this->W4_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MaxDLabel->Location = System::Drawing::Point(46, 133);
			this->W4_MaxDLabel->Name = L"W4_MaxDLabel";
			this->W4_MaxDLabel->Size = System::Drawing::Size(97, 16);
			this->W4_MaxDLabel->TabIndex = 130;
			this->W4_MaxDLabel->Text = L"Max Damage:";
			// 
			// W4_MinDLabel
			// 
			this->W4_MinDLabel->AutoSize = true;
			this->W4_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MinDLabel->Location = System::Drawing::Point(46, 107);
			this->W4_MinDLabel->Name = L"W4_MinDLabel";
			this->W4_MinDLabel->Size = System::Drawing::Size(93, 16);
			this->W4_MinDLabel->TabIndex = 129;
			this->W4_MinDLabel->Text = L"Min Damage:";
			// 
			// W4_DrainLabel
			// 
			this->W4_DrainLabel->AutoSize = true;
			this->W4_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_DrainLabel->Location = System::Drawing::Point(46, 81);
			this->W4_DrainLabel->Name = L"W4_DrainLabel";
			this->W4_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->W4_DrainLabel->TabIndex = 128;
			this->W4_DrainLabel->Text = L"Drain:";
			// 
			// W4_MassLabel
			// 
			this->W4_MassLabel->AutoSize = true;
			this->W4_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MassLabel->Location = System::Drawing::Point(46, 55);
			this->W4_MassLabel->Name = L"W4_MassLabel";
			this->W4_MassLabel->Size = System::Drawing::Size(47, 16);
			this->W4_MassLabel->TabIndex = 127;
			this->W4_MassLabel->Text = L"Mass:";
			// 
			// W4_ArmorLabel
			// 
			this->W4_ArmorLabel->AutoSize = true;
			this->W4_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_ArmorLabel->Location = System::Drawing::Point(46, 29);
			this->W4_ArmorLabel->Name = L"W4_ArmorLabel";
			this->W4_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->W4_ArmorLabel->TabIndex = 126;
			this->W4_ArmorLabel->Text = L"Armor:";
			// 
			// Weapon4FormLabel
			// 
			this->Weapon4FormLabel->AutoSize = true;
			this->Weapon4FormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon4FormLabel->Location = System::Drawing::Point(94, 8);
			this->Weapon4FormLabel->Name = L"Weapon4FormLabel";
			this->Weapon4FormLabel->Size = System::Drawing::Size(104, 16);
			this->Weapon4FormLabel->TabIndex = 125;
			this->Weapon4FormLabel->Text = L"W e a p o n  4";
			// 
			// Weapon4Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(292, 298);
			this->Controls->Add(this->W4_RefireLabel);
			this->Controls->Add(this->Weapon4FormRefireTextBox);
			this->Controls->Add(this->W4_EPSLabel);
			this->Controls->Add(this->Weapon4FormEPSTextBox);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->Weapon4FormvsATextBox);
			this->Controls->Add(this->Weapon4FormvsSTextBox);
			this->Controls->Add(this->Weapon4FormMaxDTextBox);
			this->Controls->Add(this->Weapon4FormMinDTextBox);
			this->Controls->Add(this->Weapon4FormDrainTextBox);
			this->Controls->Add(this->Weapon4FormMassTextBox);
			this->Controls->Add(this->Weapon4FormArmorTextBox);
			this->Controls->Add(this->W4_vsALabel);
			this->Controls->Add(this->W4_vsSLabel);
			this->Controls->Add(this->W4_MaxDLabel);
			this->Controls->Add(this->W4_MinDLabel);
			this->Controls->Add(this->W4_DrainLabel);
			this->Controls->Add(this->W4_MassLabel);
			this->Controls->Add(this->W4_ArmorLabel);
			this->Controls->Add(this->Weapon4FormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Weapon4Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Weapon 4";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
