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
	/// Summary for OrdinanceForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class OrdinanceForm : public System::Windows::Forms::Form
	{
	private:
		Ordinance^ m_Ordinance;
		String^ m_OrdinanceName;
	public:
		OrdinanceForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		OrdinanceForm(Ordinance^ ordinanceData, String^ ordinanceName)
		{
			InitializeComponent();

			this->Text = String::Concat("Ordinance: ", ordinanceName);

			m_Ordinance = gcnew CompLib::Ordinance;
			m_Ordinance->Merge(ordinanceData);

			m_OrdinanceName = ordinanceName;

			LoadData();
			UpdateGUI();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OrdinanceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  O_AmmoLabel;
	private: System::Windows::Forms::TextBox^  OrdinanceFormAmmoTextBox;
	protected: 

	protected: 
	protected: 
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  SaveButton;

	private: System::Windows::Forms::TextBox^  OrdinanceFormvsATextBox;
	private: System::Windows::Forms::TextBox^  OrdinanceFormvsSTextBox;
	private: System::Windows::Forms::TextBox^  OrdinanceFormMaxDTextBox;
	private: System::Windows::Forms::TextBox^  OrdinanceFormMinDTextBox;
	private: System::Windows::Forms::TextBox^  OrdinanceFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  OrdinanceFormMassTextBox;
	private: System::Windows::Forms::TextBox^  OrdinanceFormArmorTextBox;
	private: System::Windows::Forms::Label^  O_vsALabel;
	private: System::Windows::Forms::Label^  O_vsSLabel;
	private: System::Windows::Forms::Label^  O_MaxDLabel;
	private: System::Windows::Forms::Label^  O_MinDLabel;
	private: System::Windows::Forms::Label^  O_DrainLabel;
	private: System::Windows::Forms::Label^  O_MassLabel;
	private: System::Windows::Forms::Label^  O_ArmorLabel;
	private: System::Windows::Forms::Label^  OrdinanceFormLabel;

	public:
		property Ordinance^ OrdinanceList
		{
			Ordinance^ get() { return m_Ordinance; }
			void set (Ordinance^ value) { m_Ordinance = value; }
		}
		property String^ OrdinanceName
		{
			String^ get() { return m_OrdinanceName; }
			void set (String^ value) { m_OrdinanceName = value; }
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(OrdinanceForm::typeid));
			this->O_AmmoLabel = (gcnew System::Windows::Forms::Label());
			this->OrdinanceFormAmmoTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->OrdinanceFormvsATextBox = (gcnew System::Windows::Forms::TextBox());
			this->OrdinanceFormvsSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OrdinanceFormMaxDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OrdinanceFormMinDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OrdinanceFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OrdinanceFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OrdinanceFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->O_vsALabel = (gcnew System::Windows::Forms::Label());
			this->O_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->O_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->O_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->O_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->O_MassLabel = (gcnew System::Windows::Forms::Label());
			this->O_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->OrdinanceFormLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// O_AmmoLabel
			// 
			this->O_AmmoLabel->AutoSize = true;
			this->O_AmmoLabel->BackColor = System::Drawing::Color::Transparent;
			this->O_AmmoLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O_AmmoLabel->Location = System::Drawing::Point(46, 225);
			this->O_AmmoLabel->Name = L"O_AmmoLabel";
			this->O_AmmoLabel->Size = System::Drawing::Size(53, 16);
			this->O_AmmoLabel->TabIndex = 143;
			this->O_AmmoLabel->Text = L"Ammo:";
			// 
			// OrdinanceFormAmmoTextBox
			// 
			this->OrdinanceFormAmmoTextBox->Location = System::Drawing::Point(147, 224);
			this->OrdinanceFormAmmoTextBox->MaxLength = 10;
			this->OrdinanceFormAmmoTextBox->Name = L"OrdinanceFormAmmoTextBox";
			this->OrdinanceFormAmmoTextBox->Size = System::Drawing::Size(100, 20);
			this->OrdinanceFormAmmoTextBox->TabIndex = 8;
			this->OrdinanceFormAmmoTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &OrdinanceForm::OrdinanceFormAmmoTextBox_KeyPress);
			this->OrdinanceFormAmmoTextBox->TextChanged += gcnew System::EventHandler(this, &OrdinanceForm::OrdinanceFormAmmoTextBox_TextChanged);
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 267);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 10;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &OrdinanceForm::CancelButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->SaveButton->ForeColor = System::Drawing::Color::Black;
			this->SaveButton->Location = System::Drawing::Point(68, 267);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 9;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &OrdinanceForm::SaveButton_Click);
			// 
			// OrdinanceFormvsATextBox
			// 
			this->OrdinanceFormvsATextBox->Location = System::Drawing::Point(147, 198);
			this->OrdinanceFormvsATextBox->MaxLength = 10;
			this->OrdinanceFormvsATextBox->Name = L"OrdinanceFormvsATextBox";
			this->OrdinanceFormvsATextBox->Size = System::Drawing::Size(100, 20);
			this->OrdinanceFormvsATextBox->TabIndex = 7;
			this->OrdinanceFormvsATextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &OrdinanceForm::OrdinanceFormvsATextBox_KeyPress);
			this->OrdinanceFormvsATextBox->TextChanged += gcnew System::EventHandler(this, &OrdinanceForm::OrdinanceFormvsATextBox_TextChanged);
			// 
			// OrdinanceFormvsSTextBox
			// 
			this->OrdinanceFormvsSTextBox->Location = System::Drawing::Point(147, 172);
			this->OrdinanceFormvsSTextBox->MaxLength = 10;
			this->OrdinanceFormvsSTextBox->Name = L"OrdinanceFormvsSTextBox";
			this->OrdinanceFormvsSTextBox->Size = System::Drawing::Size(100, 20);
			this->OrdinanceFormvsSTextBox->TabIndex = 6;
			this->OrdinanceFormvsSTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &OrdinanceForm::OrdinanceFormvsSTextBox_KeyPress);
			this->OrdinanceFormvsSTextBox->TextChanged += gcnew System::EventHandler(this, &OrdinanceForm::OrdinanceFormvsSTextBox_TextChanged);
			// 
			// OrdinanceFormMaxDTextBox
			// 
			this->OrdinanceFormMaxDTextBox->Location = System::Drawing::Point(147, 146);
			this->OrdinanceFormMaxDTextBox->MaxLength = 10;
			this->OrdinanceFormMaxDTextBox->Name = L"OrdinanceFormMaxDTextBox";
			this->OrdinanceFormMaxDTextBox->Size = System::Drawing::Size(100, 20);
			this->OrdinanceFormMaxDTextBox->TabIndex = 5;
			this->OrdinanceFormMaxDTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &OrdinanceForm::OrdinanceFormMaxDTextBox_KeyPress);
			this->OrdinanceFormMaxDTextBox->TextChanged += gcnew System::EventHandler(this, &OrdinanceForm::OrdinanceFormMaxDTextBox_TextChanged);
			// 
			// OrdinanceFormMinDTextBox
			// 
			this->OrdinanceFormMinDTextBox->Location = System::Drawing::Point(147, 120);
			this->OrdinanceFormMinDTextBox->MaxLength = 10;
			this->OrdinanceFormMinDTextBox->Name = L"OrdinanceFormMinDTextBox";
			this->OrdinanceFormMinDTextBox->Size = System::Drawing::Size(100, 20);
			this->OrdinanceFormMinDTextBox->TabIndex = 4;
			this->OrdinanceFormMinDTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &OrdinanceForm::OrdinanceFormMinDTextBox_KeyPress);
			this->OrdinanceFormMinDTextBox->TextChanged += gcnew System::EventHandler(this, &OrdinanceForm::OrdinanceFormMinDTextBox_TextChanged);
			// 
			// OrdinanceFormDrainTextBox
			// 
			this->OrdinanceFormDrainTextBox->Location = System::Drawing::Point(147, 68);
			this->OrdinanceFormDrainTextBox->MaxLength = 10;
			this->OrdinanceFormDrainTextBox->Name = L"OrdinanceFormDrainTextBox";
			this->OrdinanceFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->OrdinanceFormDrainTextBox->TabIndex = 2;
			this->OrdinanceFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &OrdinanceForm::OrdinanceFormDrainTextBox_KeyPress);
			this->OrdinanceFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &OrdinanceForm::OrdinanceFormDrainTextBox_TextChanged);
			// 
			// OrdinanceFormMassTextBox
			// 
			this->OrdinanceFormMassTextBox->Location = System::Drawing::Point(147, 94);
			this->OrdinanceFormMassTextBox->MaxLength = 10;
			this->OrdinanceFormMassTextBox->Name = L"OrdinanceFormMassTextBox";
			this->OrdinanceFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->OrdinanceFormMassTextBox->TabIndex = 3;
			this->OrdinanceFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &OrdinanceForm::OrdinanceFormMassTextBox_KeyPress);
			this->OrdinanceFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &OrdinanceForm::OrdinanceFormMassTextBox_TextChanged);
			// 
			// OrdinanceFormArmorTextBox
			// 
			this->OrdinanceFormArmorTextBox->Location = System::Drawing::Point(147, 42);
			this->OrdinanceFormArmorTextBox->MaxLength = 10;
			this->OrdinanceFormArmorTextBox->Name = L"OrdinanceFormArmorTextBox";
			this->OrdinanceFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->OrdinanceFormArmorTextBox->TabIndex = 1;
			this->OrdinanceFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &OrdinanceForm::OrdinanceFormArmorTextBox_KeyPress);
			this->OrdinanceFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &OrdinanceForm::OrdinanceFormArmorTextBox_TextChanged);
			// 
			// O_vsALabel
			// 
			this->O_vsALabel->AutoSize = true;
			this->O_vsALabel->BackColor = System::Drawing::Color::Transparent;
			this->O_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O_vsALabel->Location = System::Drawing::Point(46, 199);
			this->O_vsALabel->Name = L"O_vsALabel";
			this->O_vsALabel->Size = System::Drawing::Size(72, 16);
			this->O_vsALabel->TabIndex = 132;
			this->O_vsALabel->Text = L"vs Armor:";
			// 
			// O_vsSLabel
			// 
			this->O_vsSLabel->AutoSize = true;
			this->O_vsSLabel->BackColor = System::Drawing::Color::Transparent;
			this->O_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O_vsSLabel->Location = System::Drawing::Point(46, 173);
			this->O_vsSLabel->Name = L"O_vsSLabel";
			this->O_vsSLabel->Size = System::Drawing::Size(80, 16);
			this->O_vsSLabel->TabIndex = 131;
			this->O_vsSLabel->Text = L"vs Shields:";
			// 
			// O_MaxDLabel
			// 
			this->O_MaxDLabel->AutoSize = true;
			this->O_MaxDLabel->BackColor = System::Drawing::Color::Transparent;
			this->O_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O_MaxDLabel->Location = System::Drawing::Point(46, 147);
			this->O_MaxDLabel->Name = L"O_MaxDLabel";
			this->O_MaxDLabel->Size = System::Drawing::Size(97, 16);
			this->O_MaxDLabel->TabIndex = 130;
			this->O_MaxDLabel->Text = L"Max Damage:";
			// 
			// O_MinDLabel
			// 
			this->O_MinDLabel->AutoSize = true;
			this->O_MinDLabel->BackColor = System::Drawing::Color::Transparent;
			this->O_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O_MinDLabel->Location = System::Drawing::Point(46, 121);
			this->O_MinDLabel->Name = L"O_MinDLabel";
			this->O_MinDLabel->Size = System::Drawing::Size(93, 16);
			this->O_MinDLabel->TabIndex = 129;
			this->O_MinDLabel->Text = L"Min Damage:";
			// 
			// O_DrainLabel
			// 
			this->O_DrainLabel->AutoSize = true;
			this->O_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->O_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O_DrainLabel->Location = System::Drawing::Point(46, 69);
			this->O_DrainLabel->Name = L"O_DrainLabel";
			this->O_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->O_DrainLabel->TabIndex = 128;
			this->O_DrainLabel->Text = L"Drain:";
			// 
			// O_MassLabel
			// 
			this->O_MassLabel->AutoSize = true;
			this->O_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->O_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O_MassLabel->Location = System::Drawing::Point(46, 95);
			this->O_MassLabel->Name = L"O_MassLabel";
			this->O_MassLabel->Size = System::Drawing::Size(47, 16);
			this->O_MassLabel->TabIndex = 127;
			this->O_MassLabel->Text = L"Mass:";
			// 
			// O_ArmorLabel
			// 
			this->O_ArmorLabel->AutoSize = true;
			this->O_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->O_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O_ArmorLabel->Location = System::Drawing::Point(46, 43);
			this->O_ArmorLabel->Name = L"O_ArmorLabel";
			this->O_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->O_ArmorLabel->TabIndex = 126;
			this->O_ArmorLabel->Text = L"Armor:";
			// 
			// OrdinanceFormLabel
			// 
			this->OrdinanceFormLabel->AutoSize = true;
			this->OrdinanceFormLabel->BackColor = System::Drawing::Color::Transparent;
			this->OrdinanceFormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OrdinanceFormLabel->Location = System::Drawing::Point(87, 8);
			this->OrdinanceFormLabel->Name = L"OrdinanceFormLabel";
			this->OrdinanceFormLabel->Size = System::Drawing::Size(118, 16);
			this->OrdinanceFormLabel->TabIndex = 125;
			this->OrdinanceFormLabel->Text = L"O r d i n a n c e ";
			// 
			// OrdinanceForm
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
			this->Controls->Add(this->O_AmmoLabel);
			this->Controls->Add(this->OrdinanceFormAmmoTextBox);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->OrdinanceFormvsATextBox);
			this->Controls->Add(this->OrdinanceFormvsSTextBox);
			this->Controls->Add(this->OrdinanceFormMaxDTextBox);
			this->Controls->Add(this->OrdinanceFormMinDTextBox);
			this->Controls->Add(this->OrdinanceFormDrainTextBox);
			this->Controls->Add(this->OrdinanceFormMassTextBox);
			this->Controls->Add(this->OrdinanceFormArmorTextBox);
			this->Controls->Add(this->O_vsALabel);
			this->Controls->Add(this->O_vsSLabel);
			this->Controls->Add(this->O_MaxDLabel);
			this->Controls->Add(this->O_MinDLabel);
			this->Controls->Add(this->O_DrainLabel);
			this->Controls->Add(this->O_MassLabel);
			this->Controls->Add(this->O_ArmorLabel);
			this->Controls->Add(this->OrdinanceFormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"OrdinanceForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ordinance";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void LoadData(){
			 System::Data::DataRow^ rowOrdinance;

			 if (m_Ordinance->Rows->Count != 0)
			 {
				 rowOrdinance = m_Ordinance[0];

				 OrdinanceFormArmorTextBox->Text = rowOrdinance["Armor"]->ToString();
				 OrdinanceFormMassTextBox->Text = rowOrdinance["Mass"]->ToString();
				 OrdinanceFormDrainTextBox->Text = rowOrdinance["Drain"]->ToString();
				 OrdinanceFormMinDTextBox->Text = rowOrdinance["Min Damage"]->ToString();
				 OrdinanceFormMaxDTextBox->Text = rowOrdinance["Max Damage"]->ToString();
				 OrdinanceFormvsSTextBox->Text = rowOrdinance["vs Sheilds"]->ToString();
				 OrdinanceFormvsATextBox->Text = rowOrdinance["vs Armor"]->ToString();
				 OrdinanceFormAmmoTextBox->Text = rowOrdinance["Ammo"]->ToString();
			 }
		 }

private: System::Void UpdateGUI(){
			 if (OrdinanceFormArmorTextBox->Text != "" && OrdinanceFormMassTextBox->Text != "" && 
				 OrdinanceFormDrainTextBox->Text != "" && OrdinanceFormMinDTextBox->Text != "" &&
				 OrdinanceFormMaxDTextBox->Text != "" && OrdinanceFormvsSTextBox->Text != "" &&
				 OrdinanceFormvsATextBox->Text != "" && OrdinanceFormAmmoTextBox->Text != "")
			 {
				 SaveButton->Enabled = true;
			 }
			 else
			 {
				 SaveButton->Enabled = false;
			 }
		 }
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 	 if (m_Ordinance->Rows->Count == 0)
				 {
					 m_Ordinance->AddOrdinance(m_OrdinanceName, Convert::ToDouble(OrdinanceFormArmorTextBox->Text->ToString()), 
						 Convert::ToDouble(OrdinanceFormMassTextBox->Text->ToString()), 
						 Convert::ToDouble(OrdinanceFormDrainTextBox->Text->ToString()),
						 Convert::ToDouble(OrdinanceFormMinDTextBox->Text->ToString()),
						 Convert::ToDouble(OrdinanceFormMaxDTextBox->Text->ToString()),
						 Convert::ToDouble(OrdinanceFormvsSTextBox->Text->ToString()),
						 Convert::ToDouble(OrdinanceFormvsATextBox->Text->ToString()),
						 Convert::ToInt32(OrdinanceFormAmmoTextBox->Text->ToString()));

					 m_Ordinance->TableName = String::Concat("Ordinance_", m_OrdinanceName);

					 this->Close();
				 }
				 else
				 {
					 m_Ordinance->RemoveOrdinance(m_OrdinanceName);

					 m_Ordinance->AddOrdinance(m_OrdinanceName, Convert::ToDouble(OrdinanceFormArmorTextBox->Text->ToString()), 
						 Convert::ToDouble(OrdinanceFormMassTextBox->Text->ToString()), 
						 Convert::ToDouble(OrdinanceFormDrainTextBox->Text->ToString()),
						 Convert::ToDouble(OrdinanceFormMinDTextBox->Text->ToString()),
						 Convert::ToDouble(OrdinanceFormMaxDTextBox->Text->ToString()),
						 Convert::ToDouble(OrdinanceFormvsSTextBox->Text->ToString()),
						 Convert::ToDouble(OrdinanceFormvsATextBox->Text->ToString()),
						 Convert::ToInt32(OrdinanceFormAmmoTextBox->Text->ToString()));

					 m_Ordinance->TableName = String::Concat("Ordinance_", m_OrdinanceName);

					 this->Close();
				 }
		 }

private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void OrdinanceFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void OrdinanceFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void OrdinanceFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void OrdinanceFormMinDTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void OrdinanceFormMaxDTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void OrdinanceFormvsSTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void OrdinanceFormvsATextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void OrdinanceFormAmmoTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void OrdinanceFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void OrdinanceFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void OrdinanceFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void OrdinanceFormMinDTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void OrdinanceFormMaxDTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void OrdinanceFormvsSTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void OrdinanceFormvsATextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void OrdinanceFormAmmoTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
};
}
