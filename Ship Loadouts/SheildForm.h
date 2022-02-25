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
	/// Summary for SheildForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class SheildForm : public System::Windows::Forms::Form
	{
	private:
		Sheild^ m_Sheild;
		String^ m_SheildName;
	public:
		SheildForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		SheildForm(Sheild^ sheildData, String^ sheildName)
		{
			InitializeComponent();

			this->Text = String::Concat("Shield: ", sheildName);

			m_Sheild = gcnew CompLib::Sheild;
			m_Sheild->Merge(sheildData);

			m_SheildName = sheildName;

			SheildAdjustmentComboBox->SelectedIndex = 4;

			LoadData();
			UpdateGUI();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SheildForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  SaveButton;
	protected: 

	private: System::Windows::Forms::TextBox^  SheildFormRechargeTextBox;
	private: System::Windows::Forms::TextBox^  SheildFormBackHPTextBox;
	private: System::Windows::Forms::TextBox^  SheildFormFrontHPTextBox;
	private: System::Windows::Forms::TextBox^  SheildFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  SheildFormMassTextBox;
	private: System::Windows::Forms::TextBox^  SheildFormArmorTextBox;
	private: System::Windows::Forms::Label^  S_AdjustmentLabel;
	private: System::Windows::Forms::Label^  S_RechargeLabel;
	private: System::Windows::Forms::Label^  S_RearHPLabel;
	private: System::Windows::Forms::Label^  S_FrontHPLabel;
	private: System::Windows::Forms::Label^  S_DrainLabel;
	private: System::Windows::Forms::Label^  S_MassLabel;
	private: System::Windows::Forms::Label^  S_ArmorLabel;
	private: System::Windows::Forms::Label^  ShieldFormLabel;
	private: System::Windows::Forms::ComboBox^  SheildAdjustmentComboBox;

	public:
		property Sheild^ SheildList
		{
			Sheild^ get() { return m_Sheild; }
			void set (Sheild^ value) { m_Sheild = value; }
		}
		property String^ SheildName
		{
			String^ get() { return m_SheildName; }
			void set (String^ value) { m_SheildName = value; }
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SheildForm::typeid));
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->SheildFormRechargeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SheildFormBackHPTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SheildFormFrontHPTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SheildFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SheildFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SheildFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->S_AdjustmentLabel = (gcnew System::Windows::Forms::Label());
			this->S_RechargeLabel = (gcnew System::Windows::Forms::Label());
			this->S_RearHPLabel = (gcnew System::Windows::Forms::Label());
			this->S_FrontHPLabel = (gcnew System::Windows::Forms::Label());
			this->S_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->S_MassLabel = (gcnew System::Windows::Forms::Label());
			this->S_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->ShieldFormLabel = (gcnew System::Windows::Forms::Label());
			this->SheildAdjustmentComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 238);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 9;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &SheildForm::CancelButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->SaveButton->ForeColor = System::Drawing::Color::Black;
			this->SaveButton->Location = System::Drawing::Point(68, 238);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 8;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &SheildForm::SaveButton_Click);
			// 
			// SheildFormRechargeTextBox
			// 
			this->SheildFormRechargeTextBox->Location = System::Drawing::Point(147, 171);
			this->SheildFormRechargeTextBox->MaxLength = 10;
			this->SheildFormRechargeTextBox->Name = L"SheildFormRechargeTextBox";
			this->SheildFormRechargeTextBox->Size = System::Drawing::Size(100, 20);
			this->SheildFormRechargeTextBox->TabIndex = 6;
			this->SheildFormRechargeTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SheildForm::SheildFormRechargeTextBox_KeyPress);
			this->SheildFormRechargeTextBox->TextChanged += gcnew System::EventHandler(this, &SheildForm::SheildFormRechargeTextBox_TextChanged);
			// 
			// SheildFormBackHPTextBox
			// 
			this->SheildFormBackHPTextBox->Location = System::Drawing::Point(147, 145);
			this->SheildFormBackHPTextBox->MaxLength = 10;
			this->SheildFormBackHPTextBox->Name = L"SheildFormBackHPTextBox";
			this->SheildFormBackHPTextBox->Size = System::Drawing::Size(100, 20);
			this->SheildFormBackHPTextBox->TabIndex = 5;
			this->SheildFormBackHPTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SheildForm::SheildFormBackHPTextBox_KeyPress);
			this->SheildFormBackHPTextBox->TextChanged += gcnew System::EventHandler(this, &SheildForm::SheildFormBackHPTextBox_TextChanged);
			// 
			// SheildFormFrontHPTextBox
			// 
			this->SheildFormFrontHPTextBox->Location = System::Drawing::Point(147, 119);
			this->SheildFormFrontHPTextBox->MaxLength = 10;
			this->SheildFormFrontHPTextBox->Name = L"SheildFormFrontHPTextBox";
			this->SheildFormFrontHPTextBox->Size = System::Drawing::Size(100, 20);
			this->SheildFormFrontHPTextBox->TabIndex = 4;
			this->SheildFormFrontHPTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SheildForm::SheildFormFrontHPTextBox_KeyPress);
			this->SheildFormFrontHPTextBox->TextChanged += gcnew System::EventHandler(this, &SheildForm::SheildFormFrontHPTextBox_TextChanged);
			// 
			// SheildFormDrainTextBox
			// 
			this->SheildFormDrainTextBox->Location = System::Drawing::Point(147, 67);
			this->SheildFormDrainTextBox->MaxLength = 10;
			this->SheildFormDrainTextBox->Name = L"SheildFormDrainTextBox";
			this->SheildFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->SheildFormDrainTextBox->TabIndex = 2;
			this->SheildFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SheildForm::SheildFormDrainTextBox_KeyPress);
			this->SheildFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &SheildForm::SheildFormDrainTextBox_TextChanged);
			// 
			// SheildFormMassTextBox
			// 
			this->SheildFormMassTextBox->Location = System::Drawing::Point(147, 93);
			this->SheildFormMassTextBox->MaxLength = 10;
			this->SheildFormMassTextBox->Name = L"SheildFormMassTextBox";
			this->SheildFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->SheildFormMassTextBox->TabIndex = 3;
			this->SheildFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SheildForm::SheildFormMassTextBox_KeyPress);
			this->SheildFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &SheildForm::SheildFormMassTextBox_TextChanged);
			// 
			// SheildFormArmorTextBox
			// 
			this->SheildFormArmorTextBox->Location = System::Drawing::Point(147, 41);
			this->SheildFormArmorTextBox->MaxLength = 10;
			this->SheildFormArmorTextBox->Name = L"SheildFormArmorTextBox";
			this->SheildFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->SheildFormArmorTextBox->TabIndex = 1;
			this->SheildFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SheildForm::SheildFormArmorTextBox_KeyPress);
			this->SheildFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &SheildForm::SheildFormArmorTextBox_TextChanged);
			// 
			// S_AdjustmentLabel
			// 
			this->S_AdjustmentLabel->AutoSize = true;
			this->S_AdjustmentLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_AdjustmentLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_AdjustmentLabel->Location = System::Drawing::Point(46, 198);
			this->S_AdjustmentLabel->Name = L"S_AdjustmentLabel";
			this->S_AdjustmentLabel->Size = System::Drawing::Size(89, 16);
			this->S_AdjustmentLabel->TabIndex = 92;
			this->S_AdjustmentLabel->Text = L"Adjustment:";
			// 
			// S_RechargeLabel
			// 
			this->S_RechargeLabel->AutoSize = true;
			this->S_RechargeLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_RechargeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_RechargeLabel->Location = System::Drawing::Point(46, 172);
			this->S_RechargeLabel->Name = L"S_RechargeLabel";
			this->S_RechargeLabel->Size = System::Drawing::Size(75, 16);
			this->S_RechargeLabel->TabIndex = 91;
			this->S_RechargeLabel->Text = L"Recharge:";
			// 
			// S_RearHPLabel
			// 
			this->S_RearHPLabel->AutoSize = true;
			this->S_RearHPLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_RearHPLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_RearHPLabel->Location = System::Drawing::Point(46, 146);
			this->S_RearHPLabel->Name = L"S_RearHPLabel";
			this->S_RearHPLabel->Size = System::Drawing::Size(65, 16);
			this->S_RearHPLabel->TabIndex = 90;
			this->S_RearHPLabel->Text = L"Rear HP:";
			// 
			// S_FrontHPLabel
			// 
			this->S_FrontHPLabel->AutoSize = true;
			this->S_FrontHPLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_FrontHPLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_FrontHPLabel->Location = System::Drawing::Point(46, 120);
			this->S_FrontHPLabel->Name = L"S_FrontHPLabel";
			this->S_FrontHPLabel->Size = System::Drawing::Size(71, 16);
			this->S_FrontHPLabel->TabIndex = 89;
			this->S_FrontHPLabel->Text = L"Front HP:";
			// 
			// S_DrainLabel
			// 
			this->S_DrainLabel->AutoSize = true;
			this->S_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_DrainLabel->Location = System::Drawing::Point(46, 68);
			this->S_DrainLabel->Name = L"S_DrainLabel";
			this->S_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->S_DrainLabel->TabIndex = 88;
			this->S_DrainLabel->Text = L"Drain:";
			// 
			// S_MassLabel
			// 
			this->S_MassLabel->AutoSize = true;
			this->S_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_MassLabel->Location = System::Drawing::Point(46, 94);
			this->S_MassLabel->Name = L"S_MassLabel";
			this->S_MassLabel->Size = System::Drawing::Size(47, 16);
			this->S_MassLabel->TabIndex = 87;
			this->S_MassLabel->Text = L"Mass:";
			// 
			// S_ArmorLabel
			// 
			this->S_ArmorLabel->AutoSize = true;
			this->S_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_ArmorLabel->Location = System::Drawing::Point(46, 42);
			this->S_ArmorLabel->Name = L"S_ArmorLabel";
			this->S_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->S_ArmorLabel->TabIndex = 86;
			this->S_ArmorLabel->Text = L"Armor:";
			// 
			// ShieldFormLabel
			// 
			this->ShieldFormLabel->AutoSize = true;
			this->ShieldFormLabel->BackColor = System::Drawing::Color::Transparent;
			this->ShieldFormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ShieldFormLabel->Location = System::Drawing::Point(108, 6);
			this->ShieldFormLabel->Name = L"ShieldFormLabel";
			this->ShieldFormLabel->Size = System::Drawing::Size(72, 16);
			this->ShieldFormLabel->TabIndex = 85;
			this->ShieldFormLabel->Text = L"S h i e l d";
			// 
			// SheildAdjustmentComboBox
			// 
			this->SheildAdjustmentComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->SheildAdjustmentComboBox->FormattingEnabled = true;
			this->SheildAdjustmentComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {L"Front Extreme", L"Front Heavy", 
				L"Front Moderate", L"Front Light", L"None", L"Rear Light", L"Rear Moderate", L"Rear Heavy", L"Rear Extreme"});
			this->SheildAdjustmentComboBox->Location = System::Drawing::Point(147, 197);
			this->SheildAdjustmentComboBox->Name = L"SheildAdjustmentComboBox";
			this->SheildAdjustmentComboBox->Size = System::Drawing::Size(100, 21);
			this->SheildAdjustmentComboBox->TabIndex = 7;
			this->SheildAdjustmentComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &SheildForm::SheildAdjustmentComboBox_SelectedIndexChanged);
			// 
			// SheildForm
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(292, 266);
			this->ControlBox = false;
			this->Controls->Add(this->SheildAdjustmentComboBox);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->SheildFormRechargeTextBox);
			this->Controls->Add(this->SheildFormBackHPTextBox);
			this->Controls->Add(this->SheildFormFrontHPTextBox);
			this->Controls->Add(this->SheildFormDrainTextBox);
			this->Controls->Add(this->SheildFormMassTextBox);
			this->Controls->Add(this->SheildFormArmorTextBox);
			this->Controls->Add(this->S_AdjustmentLabel);
			this->Controls->Add(this->S_RechargeLabel);
			this->Controls->Add(this->S_RearHPLabel);
			this->Controls->Add(this->S_FrontHPLabel);
			this->Controls->Add(this->S_DrainLabel);
			this->Controls->Add(this->S_MassLabel);
			this->Controls->Add(this->S_ArmorLabel);
			this->Controls->Add(this->ShieldFormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SheildForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Shield";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void LoadData(){
			 System::Data::DataRow^ rowSheild;

			 if (m_Sheild->Rows->Count != 0)
			 {
				 rowSheild = m_Sheild[0];

				 SheildFormArmorTextBox->Text = rowSheild["Armor"]->ToString();
				 SheildFormMassTextBox->Text = rowSheild["Mass"]->ToString();
				 SheildFormDrainTextBox->Text = rowSheild["Drain"]->ToString();
				 SheildFormFrontHPTextBox->Text = rowSheild["Front HP"]->ToString();
				 SheildFormBackHPTextBox->Text = rowSheild["Back HP"]->ToString();
				 SheildFormRechargeTextBox->Text = rowSheild["Recharge"]->ToString();
				 SheildAdjustmentComboBox->SelectedIndex = System::Convert::ToInt32(rowSheild["Adjustment"]->ToString());
			 }
		 }

private: System::Void UpdateGUI(){
			 if (SheildFormArmorTextBox->Text != "" && SheildFormMassTextBox->Text != "" && 
				 SheildFormDrainTextBox->Text != "" && SheildFormFrontHPTextBox->Text != "" &&
				 SheildFormBackHPTextBox->Text != "" && SheildFormRechargeTextBox->Text != "" &&
				 SheildAdjustmentComboBox->SelectedIndex != -1)
			 {
				 SaveButton->Enabled = true;
			 }
			 else
			 {
				 SaveButton->Enabled = false;
			 }
		 }
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (m_Sheild->Rows->Count == 0)
				 {
					 m_Sheild->AddSheild(m_SheildName, Convert::ToDouble(SheildFormArmorTextBox->Text->ToString()), 
						 Convert::ToDouble(SheildFormMassTextBox->Text->ToString()), 
						 Convert::ToDouble(SheildFormDrainTextBox->Text->ToString()),
						 Convert::ToDouble(SheildFormFrontHPTextBox->Text->ToString()),
						 Convert::ToDouble(SheildFormBackHPTextBox->Text->ToString()),
						 Convert::ToDouble(SheildFormRechargeTextBox->Text->ToString()),
						 Convert::ToInt32(SheildAdjustmentComboBox->SelectedIndex));

					 m_Sheild->TableName = String::Concat("Sheild_", m_SheildName);

					 this->Close();
				 }
				 else
				 {
					 m_Sheild->RemoveSheild(m_SheildName);

					 m_Sheild->AddSheild(m_SheildName, Convert::ToDouble(SheildFormArmorTextBox->Text->ToString()), 
						 Convert::ToDouble(SheildFormMassTextBox->Text->ToString()), 
						 Convert::ToDouble(SheildFormDrainTextBox->Text->ToString()),
						 Convert::ToDouble(SheildFormFrontHPTextBox->Text->ToString()),
						 Convert::ToDouble(SheildFormBackHPTextBox->Text->ToString()),
						 Convert::ToDouble(SheildFormRechargeTextBox->Text->ToString()),
						 Convert::ToInt32(SheildAdjustmentComboBox->SelectedIndex));

					 m_Sheild->TableName = String::Concat("Sheild_", m_SheildName);

					 this->Close();
				 }
		 }

private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void SheildFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void SheildFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void SheildFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void SheildFormFrontHPTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void SheildFormBackHPTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void SheildFormRechargeTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void SheildAdjustmentComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void SheildFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void SheildFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void SheildFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void SheildFormFrontHPTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void SheildFormBackHPTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void SheildFormRechargeTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
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
