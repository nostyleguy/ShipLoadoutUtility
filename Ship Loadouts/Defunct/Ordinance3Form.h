#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ShipLoadouts {

	/// <summary>
	/// Summary for Ordinance3Form
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Ordinance3Form : public System::Windows::Forms::Form
	{
	public:
		Ordinance3Form(void)
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
		~Ordinance3Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  O3_AmmoLabel;
	protected: 
	private: System::Windows::Forms::TextBox^  Ordinance3FormEPSTextBox;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  UpdateButton;
	private: System::Windows::Forms::TextBox^  Ordinance3FormvsATextBox;
	private: System::Windows::Forms::TextBox^  Ordinance3FormvsSTextBox;
	private: System::Windows::Forms::TextBox^  Ordinance3FormMaxDTextBox;
	private: System::Windows::Forms::TextBox^  Ordinance3FormMinDTextBox;
	private: System::Windows::Forms::TextBox^  Ordinance3FormDrainTextBox;
	private: System::Windows::Forms::TextBox^  Ordinance3FormMassTextBox;
	private: System::Windows::Forms::TextBox^  Ordinance3FormArmorTextBox;
	private: System::Windows::Forms::Label^  O3_vsALabel;
	private: System::Windows::Forms::Label^  O3_vsSLabel;
	private: System::Windows::Forms::Label^  O3_MaxDLabel;
	private: System::Windows::Forms::Label^  O3_MinDLabel;
	private: System::Windows::Forms::Label^  O3_DrainLabel;
	private: System::Windows::Forms::Label^  O3_MassLabel;
	private: System::Windows::Forms::Label^  O3_ArmorLabel;
	private: System::Windows::Forms::Label^  Ordinance3FormLabel;

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
			this->O3_AmmoLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance3FormEPSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->Ordinance3FormvsATextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ordinance3FormvsSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ordinance3FormMaxDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ordinance3FormMinDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ordinance3FormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ordinance3FormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ordinance3FormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->O3_vsALabel = (gcnew System::Windows::Forms::Label());
			this->O3_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->O3_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->O3_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->O3_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->O3_MassLabel = (gcnew System::Windows::Forms::Label());
			this->O3_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance3FormLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// O3_AmmoLabel
			// 
			this->O3_AmmoLabel->AutoSize = true;
			this->O3_AmmoLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_AmmoLabel->Location = System::Drawing::Point(46, 225);
			this->O3_AmmoLabel->Name = L"O3_AmmoLabel";
			this->O3_AmmoLabel->Size = System::Drawing::Size(53, 16);
			this->O3_AmmoLabel->TabIndex = 181;
			this->O3_AmmoLabel->Text = L"Ammo:";
			// 
			// Ordinance3FormEPSTextBox
			// 
			this->Ordinance3FormEPSTextBox->Location = System::Drawing::Point(147, 224);
			this->Ordinance3FormEPSTextBox->Name = L"Ordinance3FormEPSTextBox";
			this->Ordinance3FormEPSTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance3FormEPSTextBox->TabIndex = 180;
			// 
			// CancelButton
			// 
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 267);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 179;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			// 
			// UpdateButton
			// 
			this->UpdateButton->ForeColor = System::Drawing::Color::Black;
			this->UpdateButton->Location = System::Drawing::Point(68, 267);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(75, 23);
			this->UpdateButton->TabIndex = 178;
			this->UpdateButton->Text = L"Update";
			this->UpdateButton->UseVisualStyleBackColor = true;
			// 
			// Ordinance3FormvsATextBox
			// 
			this->Ordinance3FormvsATextBox->Location = System::Drawing::Point(147, 198);
			this->Ordinance3FormvsATextBox->Name = L"Ordinance3FormvsATextBox";
			this->Ordinance3FormvsATextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance3FormvsATextBox->TabIndex = 177;
			// 
			// Ordinance3FormvsSTextBox
			// 
			this->Ordinance3FormvsSTextBox->Location = System::Drawing::Point(147, 172);
			this->Ordinance3FormvsSTextBox->Name = L"Ordinance3FormvsSTextBox";
			this->Ordinance3FormvsSTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance3FormvsSTextBox->TabIndex = 176;
			// 
			// Ordinance3FormMaxDTextBox
			// 
			this->Ordinance3FormMaxDTextBox->Location = System::Drawing::Point(147, 146);
			this->Ordinance3FormMaxDTextBox->Name = L"Ordinance3FormMaxDTextBox";
			this->Ordinance3FormMaxDTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance3FormMaxDTextBox->TabIndex = 175;
			// 
			// Ordinance3FormMinDTextBox
			// 
			this->Ordinance3FormMinDTextBox->Location = System::Drawing::Point(147, 120);
			this->Ordinance3FormMinDTextBox->Name = L"Ordinance3FormMinDTextBox";
			this->Ordinance3FormMinDTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance3FormMinDTextBox->TabIndex = 174;
			// 
			// Ordinance3FormDrainTextBox
			// 
			this->Ordinance3FormDrainTextBox->Location = System::Drawing::Point(147, 94);
			this->Ordinance3FormDrainTextBox->Name = L"Ordinance3FormDrainTextBox";
			this->Ordinance3FormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance3FormDrainTextBox->TabIndex = 173;
			// 
			// Ordinance3FormMassTextBox
			// 
			this->Ordinance3FormMassTextBox->Location = System::Drawing::Point(147, 68);
			this->Ordinance3FormMassTextBox->Name = L"Ordinance3FormMassTextBox";
			this->Ordinance3FormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance3FormMassTextBox->TabIndex = 172;
			// 
			// Ordinance3FormArmorTextBox
			// 
			this->Ordinance3FormArmorTextBox->Location = System::Drawing::Point(147, 42);
			this->Ordinance3FormArmorTextBox->Name = L"Ordinance3FormArmorTextBox";
			this->Ordinance3FormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->Ordinance3FormArmorTextBox->TabIndex = 171;
			// 
			// O3_vsALabel
			// 
			this->O3_vsALabel->AutoSize = true;
			this->O3_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_vsALabel->Location = System::Drawing::Point(46, 199);
			this->O3_vsALabel->Name = L"O3_vsALabel";
			this->O3_vsALabel->Size = System::Drawing::Size(72, 16);
			this->O3_vsALabel->TabIndex = 170;
			this->O3_vsALabel->Text = L"vs Armor:";
			// 
			// O3_vsSLabel
			// 
			this->O3_vsSLabel->AutoSize = true;
			this->O3_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_vsSLabel->Location = System::Drawing::Point(46, 173);
			this->O3_vsSLabel->Name = L"O3_vsSLabel";
			this->O3_vsSLabel->Size = System::Drawing::Size(80, 16);
			this->O3_vsSLabel->TabIndex = 169;
			this->O3_vsSLabel->Text = L"vs Sheilds:";
			// 
			// O3_MaxDLabel
			// 
			this->O3_MaxDLabel->AutoSize = true;
			this->O3_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_MaxDLabel->Location = System::Drawing::Point(46, 147);
			this->O3_MaxDLabel->Name = L"O3_MaxDLabel";
			this->O3_MaxDLabel->Size = System::Drawing::Size(97, 16);
			this->O3_MaxDLabel->TabIndex = 168;
			this->O3_MaxDLabel->Text = L"Max Damage:";
			// 
			// O3_MinDLabel
			// 
			this->O3_MinDLabel->AutoSize = true;
			this->O3_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_MinDLabel->Location = System::Drawing::Point(46, 121);
			this->O3_MinDLabel->Name = L"O3_MinDLabel";
			this->O3_MinDLabel->Size = System::Drawing::Size(93, 16);
			this->O3_MinDLabel->TabIndex = 167;
			this->O3_MinDLabel->Text = L"Min Damage:";
			// 
			// O3_DrainLabel
			// 
			this->O3_DrainLabel->AutoSize = true;
			this->O3_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_DrainLabel->Location = System::Drawing::Point(46, 95);
			this->O3_DrainLabel->Name = L"O3_DrainLabel";
			this->O3_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->O3_DrainLabel->TabIndex = 166;
			this->O3_DrainLabel->Text = L"Drain:";
			// 
			// O3_MassLabel
			// 
			this->O3_MassLabel->AutoSize = true;
			this->O3_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_MassLabel->Location = System::Drawing::Point(46, 69);
			this->O3_MassLabel->Name = L"O3_MassLabel";
			this->O3_MassLabel->Size = System::Drawing::Size(47, 16);
			this->O3_MassLabel->TabIndex = 165;
			this->O3_MassLabel->Text = L"Mass:";
			// 
			// O3_ArmorLabel
			// 
			this->O3_ArmorLabel->AutoSize = true;
			this->O3_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_ArmorLabel->Location = System::Drawing::Point(46, 43);
			this->O3_ArmorLabel->Name = L"O3_ArmorLabel";
			this->O3_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->O3_ArmorLabel->TabIndex = 164;
			this->O3_ArmorLabel->Text = L"Armor:";
			// 
			// Ordinance3FormLabel
			// 
			this->Ordinance3FormLabel->AutoSize = true;
			this->Ordinance3FormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance3FormLabel->Location = System::Drawing::Point(81, 8);
			this->Ordinance3FormLabel->Name = L"Ordinance3FormLabel";
			this->Ordinance3FormLabel->Size = System::Drawing::Size(131, 16);
			this->Ordinance3FormLabel->TabIndex = 163;
			this->Ordinance3FormLabel->Text = L"O r d i n a n c e  3";
			// 
			// Ordinance3Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(292, 298);
			this->Controls->Add(this->O3_AmmoLabel);
			this->Controls->Add(this->Ordinance3FormEPSTextBox);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->Ordinance3FormvsATextBox);
			this->Controls->Add(this->Ordinance3FormvsSTextBox);
			this->Controls->Add(this->Ordinance3FormMaxDTextBox);
			this->Controls->Add(this->Ordinance3FormMinDTextBox);
			this->Controls->Add(this->Ordinance3FormDrainTextBox);
			this->Controls->Add(this->Ordinance3FormMassTextBox);
			this->Controls->Add(this->Ordinance3FormArmorTextBox);
			this->Controls->Add(this->O3_vsALabel);
			this->Controls->Add(this->O3_vsSLabel);
			this->Controls->Add(this->O3_MaxDLabel);
			this->Controls->Add(this->O3_MinDLabel);
			this->Controls->Add(this->O3_DrainLabel);
			this->Controls->Add(this->O3_MassLabel);
			this->Controls->Add(this->O3_ArmorLabel);
			this->Controls->Add(this->Ordinance3FormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Ordinance3Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ordinance 3";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
