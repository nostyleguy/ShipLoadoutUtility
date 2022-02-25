#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace CompLib;


namespace ShipLoadouts {

	/// <summary>
	/// Summary for WeaponForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class WeaponForm : public System::Windows::Forms::Form
	{
	private:
		Weapon^ m_Weapon;
		String^ m_WeaponName;
	public:
		WeaponForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		WeaponForm(Weapon^ weaponData, String^ weaponName)
		{
			InitializeComponent();

			this->Text = String::Concat("Weapon: ", weaponName);

			m_Weapon = gcnew CompLib::Weapon;
			m_Weapon->Merge(weaponData);

			m_WeaponName = weaponName;

			LoadData();
			UpdateGUI();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WeaponForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  W_EPSLabel;
	private: System::Windows::Forms::TextBox^  WeaponFormEPSTextBox;
	protected: 
	protected: 
	protected: 
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  SaveButton;

	private: System::Windows::Forms::TextBox^  WeaponFormvsATextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormvsSTextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormMaxDTextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormMinDTextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormMassTextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormArmorTextBox;
	private: System::Windows::Forms::Label^  W_vsALabel;
	private: System::Windows::Forms::Label^  W_vsSLabel;
	private: System::Windows::Forms::Label^  W_MaxDLabel;
	private: System::Windows::Forms::Label^  W_MinDLabel;
	private: System::Windows::Forms::Label^  W_DrainLabel;
	private: System::Windows::Forms::Label^  W_MassLabel;
	private: System::Windows::Forms::Label^  W_ArmorLabel;
	private: System::Windows::Forms::Label^  WeaponFormLabel;
	private: System::Windows::Forms::Label^  W_RefireLabel;
	private: System::Windows::Forms::TextBox^  WeaponFormRefireTextBox;

	public:
		property Weapon^ WeaponList
			{
				Weapon^ get() { return m_Weapon; }
				void set (Weapon^ value) { m_Weapon = value; }
			}
		property String^ WeaponName
		{
			String^ get() { return m_WeaponName; }
			void set (String^ value) { m_WeaponName = value; }
		}

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(WeaponForm::typeid));
			this->W_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->WeaponFormEPSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->WeaponFormvsATextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormvsSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormMaxDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormMinDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->W_vsALabel = (gcnew System::Windows::Forms::Label());
			this->W_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->W_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->W_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->W_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->W_MassLabel = (gcnew System::Windows::Forms::Label());
			this->W_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->WeaponFormLabel = (gcnew System::Windows::Forms::Label());
			this->W_RefireLabel = (gcnew System::Windows::Forms::Label());
			this->WeaponFormRefireTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// W_EPSLabel
			// 
			this->W_EPSLabel->AutoSize = true;
			this->W_EPSLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_EPSLabel->Location = System::Drawing::Point(46, 209);
			this->W_EPSLabel->Name = L"W_EPSLabel";
			this->W_EPSLabel->Size = System::Drawing::Size(39, 16);
			this->W_EPSLabel->TabIndex = 122;
			this->W_EPSLabel->Text = L"EPS:";
			// 
			// WeaponFormEPSTextBox
			// 
			this->WeaponFormEPSTextBox->Location = System::Drawing::Point(147, 208);
			this->WeaponFormEPSTextBox->MaxLength = 10;
			this->WeaponFormEPSTextBox->Name = L"WeaponFormEPSTextBox";
			this->WeaponFormEPSTextBox->Size = System::Drawing::Size(100, 20);
			this->WeaponFormEPSTextBox->TabIndex = 8;
			this->WeaponFormEPSTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeaponForm::WeaponFormEPSTextBox_KeyPress);
			this->WeaponFormEPSTextBox->TextChanged += gcnew System::EventHandler(this, &WeaponForm::WeaponFormEPSTextBox_TextChanged);
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 265);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 11;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &WeaponForm::CancelButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->SaveButton->ForeColor = System::Drawing::Color::Black;
			this->SaveButton->Location = System::Drawing::Point(68, 265);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 10;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &WeaponForm::SaveButton_Click);
			// 
			// WeaponFormvsATextBox
			// 
			this->WeaponFormvsATextBox->Location = System::Drawing::Point(147, 182);
			this->WeaponFormvsATextBox->MaxLength = 10;
			this->WeaponFormvsATextBox->Name = L"WeaponFormvsATextBox";
			this->WeaponFormvsATextBox->Size = System::Drawing::Size(100, 20);
			this->WeaponFormvsATextBox->TabIndex = 7;
			this->WeaponFormvsATextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeaponForm::WeaponFormvsATextBox_KeyPress);
			this->WeaponFormvsATextBox->TextChanged += gcnew System::EventHandler(this, &WeaponForm::WeaponFormvsATextBox_TextChanged);
			// 
			// WeaponFormvsSTextBox
			// 
			this->WeaponFormvsSTextBox->Location = System::Drawing::Point(147, 156);
			this->WeaponFormvsSTextBox->MaxLength = 10;
			this->WeaponFormvsSTextBox->Name = L"WeaponFormvsSTextBox";
			this->WeaponFormvsSTextBox->Size = System::Drawing::Size(100, 20);
			this->WeaponFormvsSTextBox->TabIndex = 6;
			this->WeaponFormvsSTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeaponForm::WeaponFormvsSTextBox_KeyPress);
			this->WeaponFormvsSTextBox->TextChanged += gcnew System::EventHandler(this, &WeaponForm::WeaponFormvsSTextBox_TextChanged);
			// 
			// WeaponFormMaxDTextBox
			// 
			this->WeaponFormMaxDTextBox->Location = System::Drawing::Point(147, 130);
			this->WeaponFormMaxDTextBox->MaxLength = 10;
			this->WeaponFormMaxDTextBox->Name = L"WeaponFormMaxDTextBox";
			this->WeaponFormMaxDTextBox->Size = System::Drawing::Size(100, 20);
			this->WeaponFormMaxDTextBox->TabIndex = 5;
			this->WeaponFormMaxDTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeaponForm::WeaponFormMaxDTextBox_KeyPress);
			this->WeaponFormMaxDTextBox->TextChanged += gcnew System::EventHandler(this, &WeaponForm::WeaponFormMaxDTextBox_TextChanged);
			// 
			// WeaponFormMinDTextBox
			// 
			this->WeaponFormMinDTextBox->Location = System::Drawing::Point(147, 104);
			this->WeaponFormMinDTextBox->MaxLength = 10;
			this->WeaponFormMinDTextBox->Name = L"WeaponFormMinDTextBox";
			this->WeaponFormMinDTextBox->Size = System::Drawing::Size(100, 20);
			this->WeaponFormMinDTextBox->TabIndex = 4;
			this->WeaponFormMinDTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeaponForm::WeaponFormMinDTextBox_KeyPress);
			this->WeaponFormMinDTextBox->TextChanged += gcnew System::EventHandler(this, &WeaponForm::WeaponFormMinDTextBox_TextChanged);
			// 
			// WeaponFormDrainTextBox
			// 
			this->WeaponFormDrainTextBox->Location = System::Drawing::Point(147, 52);
			this->WeaponFormDrainTextBox->MaxLength = 10;
			this->WeaponFormDrainTextBox->Name = L"WeaponFormDrainTextBox";
			this->WeaponFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->WeaponFormDrainTextBox->TabIndex = 2;
			this->WeaponFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeaponForm::WeaponFormDrainTextBox_KeyPress);
			this->WeaponFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &WeaponForm::WeaponFormDrainTextBox_TextChanged);
			// 
			// WeaponFormMassTextBox
			// 
			this->WeaponFormMassTextBox->Location = System::Drawing::Point(147, 78);
			this->WeaponFormMassTextBox->MaxLength = 10;
			this->WeaponFormMassTextBox->Name = L"WeaponFormMassTextBox";
			this->WeaponFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->WeaponFormMassTextBox->TabIndex = 3;
			this->WeaponFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeaponForm::WeaponFormMassTextBox_KeyPress);
			this->WeaponFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &WeaponForm::WeaponFormMassTextBox_TextChanged);
			// 
			// WeaponFormArmorTextBox
			// 
			this->WeaponFormArmorTextBox->Location = System::Drawing::Point(147, 26);
			this->WeaponFormArmorTextBox->MaxLength = 10;
			this->WeaponFormArmorTextBox->Name = L"WeaponFormArmorTextBox";
			this->WeaponFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->WeaponFormArmorTextBox->TabIndex = 1;
			this->WeaponFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeaponForm::WeaponFormArmorTextBox_KeyPress);
			this->WeaponFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &WeaponForm::WeaponFormArmorTextBox_TextChanged);
			// 
			// W_vsALabel
			// 
			this->W_vsALabel->AutoSize = true;
			this->W_vsALabel->BackColor = System::Drawing::Color::Transparent;
			this->W_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_vsALabel->Location = System::Drawing::Point(46, 183);
			this->W_vsALabel->Name = L"W_vsALabel";
			this->W_vsALabel->Size = System::Drawing::Size(72, 16);
			this->W_vsALabel->TabIndex = 111;
			this->W_vsALabel->Text = L"vs Armor:";
			// 
			// W_vsSLabel
			// 
			this->W_vsSLabel->AutoSize = true;
			this->W_vsSLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_vsSLabel->Location = System::Drawing::Point(46, 157);
			this->W_vsSLabel->Name = L"W_vsSLabel";
			this->W_vsSLabel->Size = System::Drawing::Size(80, 16);
			this->W_vsSLabel->TabIndex = 110;
			this->W_vsSLabel->Text = L"vs Shields:";
			// 
			// W_MaxDLabel
			// 
			this->W_MaxDLabel->AutoSize = true;
			this->W_MaxDLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_MaxDLabel->Location = System::Drawing::Point(46, 131);
			this->W_MaxDLabel->Name = L"W_MaxDLabel";
			this->W_MaxDLabel->Size = System::Drawing::Size(97, 16);
			this->W_MaxDLabel->TabIndex = 109;
			this->W_MaxDLabel->Text = L"Max Damage:";
			// 
			// W_MinDLabel
			// 
			this->W_MinDLabel->AutoSize = true;
			this->W_MinDLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_MinDLabel->Location = System::Drawing::Point(46, 105);
			this->W_MinDLabel->Name = L"W_MinDLabel";
			this->W_MinDLabel->Size = System::Drawing::Size(93, 16);
			this->W_MinDLabel->TabIndex = 108;
			this->W_MinDLabel->Text = L"Min Damage:";
			// 
			// W_DrainLabel
			// 
			this->W_DrainLabel->AutoSize = true;
			this->W_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_DrainLabel->Location = System::Drawing::Point(46, 53);
			this->W_DrainLabel->Name = L"W_DrainLabel";
			this->W_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->W_DrainLabel->TabIndex = 107;
			this->W_DrainLabel->Text = L"Drain:";
			// 
			// W_MassLabel
			// 
			this->W_MassLabel->AutoSize = true;
			this->W_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_MassLabel->Location = System::Drawing::Point(46, 79);
			this->W_MassLabel->Name = L"W_MassLabel";
			this->W_MassLabel->Size = System::Drawing::Size(47, 16);
			this->W_MassLabel->TabIndex = 106;
			this->W_MassLabel->Text = L"Mass:";
			// 
			// W_ArmorLabel
			// 
			this->W_ArmorLabel->AutoSize = true;
			this->W_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_ArmorLabel->Location = System::Drawing::Point(46, 27);
			this->W_ArmorLabel->Name = L"W_ArmorLabel";
			this->W_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->W_ArmorLabel->TabIndex = 105;
			this->W_ArmorLabel->Text = L"Armor:";
			// 
			// WeaponFormLabel
			// 
			this->WeaponFormLabel->AutoSize = true;
			this->WeaponFormLabel->BackColor = System::Drawing::Color::Transparent;
			this->WeaponFormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->WeaponFormLabel->Location = System::Drawing::Point(103, 7);
			this->WeaponFormLabel->Name = L"WeaponFormLabel";
			this->WeaponFormLabel->Size = System::Drawing::Size(87, 16);
			this->WeaponFormLabel->TabIndex = 104;
			this->WeaponFormLabel->Text = L"W e a p o n";
			// 
			// W_RefireLabel
			// 
			this->W_RefireLabel->AutoSize = true;
			this->W_RefireLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_RefireLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_RefireLabel->Location = System::Drawing::Point(46, 235);
			this->W_RefireLabel->Name = L"W_RefireLabel";
			this->W_RefireLabel->Size = System::Drawing::Size(51, 16);
			this->W_RefireLabel->TabIndex = 124;
			this->W_RefireLabel->Text = L"Refire:";
			// 
			// WeaponFormRefireTextBox
			// 
			this->WeaponFormRefireTextBox->Location = System::Drawing::Point(147, 234);
			this->WeaponFormRefireTextBox->MaxLength = 10;
			this->WeaponFormRefireTextBox->Name = L"WeaponFormRefireTextBox";
			this->WeaponFormRefireTextBox->Size = System::Drawing::Size(100, 20);
			this->WeaponFormRefireTextBox->TabIndex = 9;
			this->WeaponFormRefireTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WeaponForm::WeaponFormRefireTextBox_KeyPress);
			this->WeaponFormRefireTextBox->TextChanged += gcnew System::EventHandler(this, &WeaponForm::WeaponFormRefireTextBox_TextChanged);
			// 
			// WeaponForm
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(292, 298);
			this->ControlBox = false;
			this->Controls->Add(this->W_RefireLabel);
			this->Controls->Add(this->WeaponFormRefireTextBox);
			this->Controls->Add(this->W_EPSLabel);
			this->Controls->Add(this->WeaponFormEPSTextBox);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->WeaponFormvsATextBox);
			this->Controls->Add(this->WeaponFormvsSTextBox);
			this->Controls->Add(this->WeaponFormMaxDTextBox);
			this->Controls->Add(this->WeaponFormMinDTextBox);
			this->Controls->Add(this->WeaponFormDrainTextBox);
			this->Controls->Add(this->WeaponFormMassTextBox);
			this->Controls->Add(this->WeaponFormArmorTextBox);
			this->Controls->Add(this->W_vsALabel);
			this->Controls->Add(this->W_vsSLabel);
			this->Controls->Add(this->W_MaxDLabel);
			this->Controls->Add(this->W_MinDLabel);
			this->Controls->Add(this->W_DrainLabel);
			this->Controls->Add(this->W_MassLabel);
			this->Controls->Add(this->W_ArmorLabel);
			this->Controls->Add(this->WeaponFormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"WeaponForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Weapon";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void LoadData(){
			 System::Data::DataRow^ rowWeapon;

			 if (m_Weapon->Rows->Count != 0)
			 {
				 rowWeapon = m_Weapon[0];

				 WeaponFormArmorTextBox->Text = rowWeapon["Armor"]->ToString();
				 WeaponFormMassTextBox->Text = rowWeapon["Mass"]->ToString();
				 WeaponFormDrainTextBox->Text = rowWeapon["Drain"]->ToString();
				 WeaponFormMinDTextBox->Text = rowWeapon["Min Damage"]->ToString();
				 WeaponFormMaxDTextBox->Text = rowWeapon["Max Damage"]->ToString();
				 WeaponFormvsSTextBox->Text = rowWeapon["vs Sheilds"]->ToString();
				 WeaponFormvsATextBox->Text = rowWeapon["vs Armor"]->ToString();
				 WeaponFormEPSTextBox->Text = rowWeapon["EPS"]->ToString();
				 WeaponFormRefireTextBox->Text = rowWeapon["Refire"]->ToString();
			 }
		 }

private: System::Void UpdateGUI(){
			 if (WeaponFormArmorTextBox->Text != "" && WeaponFormMassTextBox->Text != "" && 
				 WeaponFormDrainTextBox->Text != "" && WeaponFormMinDTextBox->Text != "" &&
				 WeaponFormMaxDTextBox->Text != "" && WeaponFormvsSTextBox->Text != "" &&
				 WeaponFormvsATextBox->Text != "" && WeaponFormEPSTextBox->Text != "" &&
				 WeaponFormRefireTextBox->Text != "")
			 {
				 SaveButton->Enabled = true;
			 }
			 else
			 {
				 SaveButton->Enabled = false;
			 }
		 }
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 	 if (m_Weapon->Rows->Count == 0)
				 {
					 m_Weapon->AddWeapon(m_WeaponName, Convert::ToDouble(WeaponFormArmorTextBox->Text->ToString()), 
						 Convert::ToDouble(WeaponFormMassTextBox->Text->ToString()), 
						 Convert::ToDouble(WeaponFormDrainTextBox->Text->ToString()),
						 Convert::ToDouble(WeaponFormMinDTextBox->Text->ToString()),
						 Convert::ToDouble(WeaponFormMaxDTextBox->Text->ToString()),
						 Convert::ToDouble(WeaponFormvsSTextBox->Text->ToString()),
						 Convert::ToDouble(WeaponFormvsATextBox->Text->ToString()),
						 Convert::ToDouble(WeaponFormEPSTextBox->Text->ToString()),
						 Convert::ToDouble(WeaponFormRefireTextBox->Text->ToString()));

					 m_Weapon->TableName = String::Concat("Weapon_", m_WeaponName);

					 this->Close();
				 }
				 else
				 {
					 m_Weapon->RemoveWeapon(m_WeaponName);

					 m_Weapon->AddWeapon(m_WeaponName, Convert::ToDouble(WeaponFormArmorTextBox->Text->ToString()), 
						 Convert::ToDouble(WeaponFormMassTextBox->Text->ToString()), 
						 Convert::ToDouble(WeaponFormDrainTextBox->Text->ToString()),
						 Convert::ToDouble(WeaponFormMinDTextBox->Text->ToString()),
						 Convert::ToDouble(WeaponFormMaxDTextBox->Text->ToString()),
						 Convert::ToDouble(WeaponFormvsSTextBox->Text->ToString()),
						 Convert::ToDouble(WeaponFormvsATextBox->Text->ToString()),
						 Convert::ToDouble(WeaponFormEPSTextBox->Text->ToString()),
						 Convert::ToDouble(WeaponFormRefireTextBox->Text->ToString()));

					 m_Weapon->TableName = String::Concat("Weapon_", m_WeaponName);

					 this->Close();
				 }
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void WeaponFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void WeaponFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void WeaponFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void WeaponFormMinDTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void WeaponFormMaxDTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void WeaponFormvsSTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void WeaponFormvsATextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void WeaponFormEPSTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void WeaponFormRefireTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void WeaponFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormMinDTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormMaxDTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormvsSTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormvsATextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormEPSTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormRefireTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
};
}
