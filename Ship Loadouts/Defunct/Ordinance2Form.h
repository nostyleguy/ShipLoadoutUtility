#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ShipLoadouts {

	/// <summary>
	/// Summary for Ordinance2Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Ordinance2Form : public System::Windows::Forms::Form
	{
	public:
		Ordinance2Form(void)
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
		~Ordinance2Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  O2_AmmoLabel;
	private: System::Windows::Forms::TextBox^  Ordinance2FormEPSTextBox;
	protected: 

	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  UpdateButton;
	private: System::Windows::Forms::TextBox^  Ordinance2FormvsATextBox;

	private: System::Windows::Forms::TextBox^  Ordinance2FormvsSTextBox;

	private: System::Windows::Forms::TextBox^  Ordinance2FormMaxDTextBox;

	private: System::Windows::Forms::TextBox^  Ordinance2FormMinDTextBox;

	private: System::Windows::Forms::TextBox^  Ordinance2FormDrainTextBox;

	private: System::Windows::Forms::TextBox^  Ordinance2FormMassTextBox;

	private: System::Windows::Forms::TextBox^  Ordinance2FormArmorTextBox;

	private: System::Windows::Forms::Label^  O2_vsALabel;
	private: System::Windows::Forms::Label^  O2_vsSLabel;
	private: System::Windows::Forms::Label^  O2_MaxDLabel;
	private: System::Windows::Forms::Label^  O2_MinDLabel;
	private: System::Windows::Forms::Label^  O2_DrainLabel;
	private: System::Windows::Forms::Label^  O2_MassLabel;
	private: System::Windows::Forms::Label^  O2_ArmorLabel;
	private: System::Windows::Forms::Label^  Ordinance2FormLabel;

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
			this->O2_AmmoLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance2FormEPSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->Ordinance2FormvsATextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ordinance2FormvsSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ordinance2FormMaxDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ordinance2FormMinDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ordinance2FormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ordinance2FormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ordinance2FormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->O2_vsALabel = (gcnew System::Windows::Forms::Label());
			this->O2_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->O2_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->O2_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->O2_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->O2_MassLabel = (gcnew System::Windows::Forms::Label());
			this->O2_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance2FormLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// O2_AmmoLabel
			// 
			this->O2_AmmoLabel->AutoSize = true;
			this->O2_AmmoLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_AmmoLabel->Location = System::Drawing::Point(46, 225);
			this->O2_AmmoLabel->Name = L"O2_AmmoLabel";
			this->O2_AmmoLabel->Size = System::Drawing::Size(53, 16);
			this->O2_AmmoLabel->TabIndex = 162;
			this->O2_AmmoLabel->Text = L"Ammo:";
			// 
			// Ordinance2FormEPSTextBox
			// 
			this->Ordinance2FormEPSTextBox->Location = System::Drawing::Point(147, 224);
			this->Ordinance2FormEPSTextBox->Name = L"Ordinance2FormEPSTextBox";
			this->Ordinance2FormEPSTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance2FormEPSTextBox->TabIndex = 161;
			// 
			// CancelButton
			// 
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 267);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 160;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			// 
			// UpdateButton
			// 
			this->UpdateButton->ForeColor = System::Drawing::Color::Black;
			this->UpdateButton->Location = System::Drawing::Point(68, 267);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(75, 23);
			this->UpdateButton->TabIndex = 159;
			this->UpdateButton->Text = L"Update";
			this->UpdateButton->UseVisualStyleBackColor = true;
			// 
			// Ordinance2FormvsATextBox
			// 
			this->Ordinance2FormvsATextBox->Location = System::Drawing::Point(147, 198);
			this->Ordinance2FormvsATextBox->Name = L"Ordinance2FormvsATextBox";
			this->Ordinance2FormvsATextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance2FormvsATextBox->TabIndex = 158;
			// 
			// Ordinance2FormvsSTextBox
			// 
			this->Ordinance2FormvsSTextBox->Location = System::Drawing::Point(147, 172);
			this->Ordinance2FormvsSTextBox->Name = L"Ordinance2FormvsSTextBox";
			this->Ordinance2FormvsSTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance2FormvsSTextBox->TabIndex = 157;
			// 
			// Ordinance2FormMaxDTextBox
			// 
			this->Ordinance2FormMaxDTextBox->Location = System::Drawing::Point(147, 146);
			this->Ordinance2FormMaxDTextBox->Name = L"Ordinance2FormMaxDTextBox";
			this->Ordinance2FormMaxDTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance2FormMaxDTextBox->TabIndex = 156;
			// 
			// Ordinance2FormMinDTextBox
			// 
			this->Ordinance2FormMinDTextBox->Location = System::Drawing::Point(147, 120);
			this->Ordinance2FormMinDTextBox->Name = L"Ordinance2FormMinDTextBox";
			this->Ordinance2FormMinDTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance2FormMinDTextBox->TabIndex = 155;
			// 
			// Ordinance2FormDrainTextBox
			// 
			this->Ordinance2FormDrainTextBox->Location = System::Drawing::Point(147, 94);
			this->Ordinance2FormDrainTextBox->Name = L"Ordinance2FormDrainTextBox";
			this->Ordinance2FormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance2FormDrainTextBox->TabIndex = 154;
			// 
			// Ordinance2FormMassTextBox
			// 
			this->Ordinance2FormMassTextBox->Location = System::Drawing::Point(147, 68);
			this->Ordinance2FormMassTextBox->Name = L"Ordinance2FormMassTextBox";
			this->Ordinance2FormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance2FormMassTextBox->TabIndex = 153;
			// 
			// Ordinance2FormArmorTextBox
			// 
			this->Ordinance2FormArmorTextBox->Location = System::Drawing::Point(147, 42);
			this->Ordinance2FormArmorTextBox->Name = L"Ordinance2FormArmorTextBox";
			this->Ordinance2FormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance2FormArmorTextBox->TabIndex = 152;
			// 
			// O2_vsALabel
			// 
			this->O2_vsALabel->AutoSize = true;
			this->O2_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_vsALabel->Location = System::Drawing::Point(46, 199);
			this->O2_vsALabel->Name = L"O2_vsALabel";
			this->O2_vsALabel->Size = System::Drawing::Size(72, 16);
			this->O2_vsALabel->TabIndex = 151;
			this->O2_vsALabel->Text = L"vs Armor:";
			// 
			// O2_vsSLabel
			// 
			this->O2_vsSLabel->AutoSize = true;
			this->O2_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_vsSLabel->Location = System::Drawing::Point(46, 173);
			this->O2_vsSLabel->Name = L"O2_vsSLabel";
			this->O2_vsSLabel->Size = System::Drawing::Size(80, 16);
			this->O2_vsSLabel->TabIndex = 150;
			this->O2_vsSLabel->Text = L"vs Sheilds:";
			// 
			// O2_MaxDLabel
			// 
			this->O2_MaxDLabel->AutoSize = true;
			this->O2_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_MaxDLabel->Location = System::Drawing::Point(46, 147);
			this->O2_MaxDLabel->Name = L"O2_MaxDLabel";
			this->O2_MaxDLabel->Size = System::Drawing::Size(97, 16);
			this->O2_MaxDLabel->TabIndex = 149;
			this->O2_MaxDLabel->Text = L"Max Damage:";
			// 
			// O2_MinDLabel
			// 
			this->O2_MinDLabel->AutoSize = true;
			this->O2_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_MinDLabel->Location = System::Drawing::Point(46, 121);
			this->O2_MinDLabel->Name = L"O2_MinDLabel";
			this->O2_MinDLabel->Size = System::Drawing::Size(93, 16);
			this->O2_MinDLabel->TabIndex = 148;
			this->O2_MinDLabel->Text = L"Min Damage:";
			// 
			// O2_DrainLabel
			// 
			this->O2_DrainLabel->AutoSize = true;
			this->O2_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_DrainLabel->Location = System::Drawing::Point(46, 95);
			this->O2_DrainLabel->Name = L"O2_DrainLabel";
			this->O2_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->O2_DrainLabel->TabIndex = 147;
			this->O2_DrainLabel->Text = L"Drain:";
			// 
			// O2_MassLabel
			// 
			this->O2_MassLabel->AutoSize = true;
			this->O2_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_MassLabel->Location = System::Drawing::Point(46, 69);
			this->O2_MassLabel->Name = L"O2_MassLabel";
			this->O2_MassLabel->Size = System::Drawing::Size(47, 16);
			this->O2_MassLabel->TabIndex = 146;
			this->O2_MassLabel->Text = L"Mass:";
			// 
			// O2_ArmorLabel
			// 
			this->O2_ArmorLabel->AutoSize = true;
			this->O2_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_ArmorLabel->Location = System::Drawing::Point(46, 43);
			this->O2_ArmorLabel->Name = L"O2_ArmorLabel";
			this->O2_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->O2_ArmorLabel->TabIndex = 145;
			this->O2_ArmorLabel->Text = L"Armor:";
			// 
			// Ordinance2FormLabel
			// 
			this->Ordinance2FormLabel->AutoSize = true;
			this->Ordinance2FormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance2FormLabel->Location = System::Drawing::Point(81, 8);
			this->Ordinance2FormLabel->Name = L"Ordinance2FormLabel";
			this->Ordinance2FormLabel->Size = System::Drawing::Size(131, 16);
			this->Ordinance2FormLabel->TabIndex = 144;
			this->Ordinance2FormLabel->Text = L"O r d i n a n c e  2";
			// 
			// Ordinance2Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(292, 298);
			this->Controls->Add(this->O2_AmmoLabel);
			this->Controls->Add(this->Ordinance2FormEPSTextBox);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->Ordinance2FormvsATextBox);
			this->Controls->Add(this->Ordinance2FormvsSTextBox);
			this->Controls->Add(this->Ordinance2FormMaxDTextBox);
			this->Controls->Add(this->Ordinance2FormMinDTextBox);
			this->Controls->Add(this->Ordinance2FormDrainTextBox);
			this->Controls->Add(this->Ordinance2FormMassTextBox);
			this->Controls->Add(this->Ordinance2FormArmorTextBox);
			this->Controls->Add(this->O2_vsALabel);
			this->Controls->Add(this->O2_vsSLabel);
			this->Controls->Add(this->O2_MaxDLabel);
			this->Controls->Add(this->O2_MinDLabel);
			this->Controls->Add(this->O2_DrainLabel);
			this->Controls->Add(this->O2_MassLabel);
			this->Controls->Add(this->O2_ArmorLabel);
			this->Controls->Add(this->Ordinance2FormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Ordinance2Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ordinance 2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
