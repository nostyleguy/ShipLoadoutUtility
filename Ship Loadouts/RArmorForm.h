#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ShipLoadouts {

	/// <summary>
	/// Summary for RArmorForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class RArmorForm : public System::Windows::Forms::Form
	{
	public:
		RArmorForm(void)
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
		~RArmorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  CancelButton;
	protected: 
	private: System::Windows::Forms::Button^  UpdateButton;
	private: System::Windows::Forms::TextBox^  RArmorFormMassTextBox;

	private: System::Windows::Forms::TextBox^  RArmorFormArmorTextBox;

	private: System::Windows::Forms::Label^  RArmorFormLabel;
	private: System::Windows::Forms::Label^  RA_MassLabel;


	private: System::Windows::Forms::Label^  RA_ArmorLabel;


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
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->RArmorFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RArmorFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RArmorFormLabel = (gcnew System::Windows::Forms::Label());
			this->RA_MassLabel = (gcnew System::Windows::Forms::Label());
			this->RA_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// CancelButton
			// 
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 228);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 82;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			// 
			// UpdateButton
			// 
			this->UpdateButton->ForeColor = System::Drawing::Color::Black;
			this->UpdateButton->Location = System::Drawing::Point(68, 228);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(75, 23);
			this->UpdateButton->TabIndex = 81;
			this->UpdateButton->Text = L"Update";
			this->UpdateButton->UseVisualStyleBackColor = true;
			// 
			// RArmorFormMassTextBox
			// 
			this->RArmorFormMassTextBox->Location = System::Drawing::Point(166, 141);
			this->RArmorFormMassTextBox->Name = L"RArmorFormMassTextBox";
			this->RArmorFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->RArmorFormMassTextBox->TabIndex = 80;
			// 
			// RArmorFormArmorTextBox
			// 
			this->RArmorFormArmorTextBox->Location = System::Drawing::Point(166, 105);
			this->RArmorFormArmorTextBox->Name = L"RArmorFormArmorTextBox";
			this->RArmorFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->RArmorFormArmorTextBox->TabIndex = 79;
			// 
			// RArmorFormLabel
			// 
			this->RArmorFormLabel->AutoSize = true;
			this->RArmorFormLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RArmorFormLabel->Location = System::Drawing::Point(87, 15);
			this->RArmorFormLabel->Name = L"RArmorFormLabel";
			this->RArmorFormLabel->Size = System::Drawing::Size(119, 16);
			this->RArmorFormLabel->TabIndex = 78;
			this->RArmorFormLabel->Text = L"R e a r  A r m o r";
			// 
			// RA_MassLabel
			// 
			this->RA_MassLabel->AutoSize = true;
			this->RA_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RA_MassLabel->Location = System::Drawing::Point(26, 143);
			this->RA_MassLabel->Name = L"RA_MassLabel";
			this->RA_MassLabel->Size = System::Drawing::Size(47, 16);
			this->RA_MassLabel->TabIndex = 77;
			this->RA_MassLabel->Text = L"Mass:";
			// 
			// RA_ArmorLabel
			// 
			this->RA_ArmorLabel->AutoSize = true;
			this->RA_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RA_ArmorLabel->Location = System::Drawing::Point(26, 107);
			this->RA_ArmorLabel->Name = L"RA_ArmorLabel";
			this->RA_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->RA_ArmorLabel->TabIndex = 76;
			this->RA_ArmorLabel->Text = L"Armor:";
			// 
			// RArmorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(292, 266);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->RArmorFormMassTextBox);
			this->Controls->Add(this->RArmorFormArmorTextBox);
			this->Controls->Add(this->RArmorFormLabel);
			this->Controls->Add(this->RA_MassLabel);
			this->Controls->Add(this->RA_ArmorLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"RArmorForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Armor (Rear)";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
