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
	/// Summary for BoosterForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class BoosterForm : public System::Windows::Forms::Form
	{
	private:
		Booster^ m_Booster;
		String^ m_BoosterName;
	public:
		BoosterForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		BoosterForm(Booster^ boosterData, String^ boosterName)
		{
			InitializeComponent();

			this->Text = String::Concat("Booster: ", boosterName);

			m_Booster = gcnew CompLib::Booster;
			m_Booster->Merge(boosterData);

			m_BoosterName = boosterName;

			LoadData();
			UpdateGUI();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BoosterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  SaveButton;
	protected: 
	private: System::Windows::Forms::TextBox^  BoosterFormAccelerationTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormConsumptionTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormRechargeTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormEnergyTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormMassTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormArmorTextBox;
	private: System::Windows::Forms::Label^  E_AccelerationLabel;
	private: System::Windows::Forms::Label^  E_ConsumptionLabel;
	private: System::Windows::Forms::Label^  E_RechargeLabel;
	private: System::Windows::Forms::Label^  B_EnergyLabel;
	private: System::Windows::Forms::Label^  B_DrainLabel;
	private: System::Windows::Forms::Label^  B_MassLabel;
	private: System::Windows::Forms::Label^  B_ArmorLabel;
	private: System::Windows::Forms::Label^  BoosterFormLabel;
	private: System::Windows::Forms::TextBox^  BoosterFormSpeedTextBox;
	private: System::Windows::Forms::Label^  B_SpeedLabel;

	public:
		property Booster^ BoosterList
		{
			Booster^ get() { return m_Booster; }
			void set (Booster^ value) { m_Booster = value; }
		}
		property String^ BoosterName
		{
			String^ get() { return m_BoosterName; }
			void set (String^ value) { m_BoosterName = value; }
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(BoosterForm::typeid));
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->BoosterFormAccelerationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormConsumptionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormRechargeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormEnergyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->E_AccelerationLabel = (gcnew System::Windows::Forms::Label());
			this->E_ConsumptionLabel = (gcnew System::Windows::Forms::Label());
			this->E_RechargeLabel = (gcnew System::Windows::Forms::Label());
			this->B_EnergyLabel = (gcnew System::Windows::Forms::Label());
			this->B_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->B_MassLabel = (gcnew System::Windows::Forms::Label());
			this->B_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterFormLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterFormSpeedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->B_SpeedLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 238);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 10;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &BoosterForm::CancelButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->SaveButton->ForeColor = System::Drawing::Color::Black;
			this->SaveButton->Location = System::Drawing::Point(68, 238);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 9;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &BoosterForm::SaveButton_Click);
			// 
			// BoosterFormAccelerationTextBox
			// 
			this->BoosterFormAccelerationTextBox->Location = System::Drawing::Point(147, 182);
			this->BoosterFormAccelerationTextBox->MaxLength = 10;
			this->BoosterFormAccelerationTextBox->Name = L"BoosterFormAccelerationTextBox";
			this->BoosterFormAccelerationTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormAccelerationTextBox->TabIndex = 7;
			this->BoosterFormAccelerationTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &BoosterForm::BoosterFormAccelerationTextBox_KeyPress);
			this->BoosterFormAccelerationTextBox->TextChanged += gcnew System::EventHandler(this, &BoosterForm::BoosterFormAccelerationTextBox_TextChanged);
			// 
			// BoosterFormConsumptionTextBox
			// 
			this->BoosterFormConsumptionTextBox->Location = System::Drawing::Point(147, 156);
			this->BoosterFormConsumptionTextBox->MaxLength = 10;
			this->BoosterFormConsumptionTextBox->Name = L"BoosterFormConsumptionTextBox";
			this->BoosterFormConsumptionTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormConsumptionTextBox->TabIndex = 6;
			this->BoosterFormConsumptionTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &BoosterForm::BoosterFormConsumptionTextBox_KeyPress);
			this->BoosterFormConsumptionTextBox->TextChanged += gcnew System::EventHandler(this, &BoosterForm::BoosterFormConsumptionTextBox_TextChanged);
			// 
			// BoosterFormRechargeTextBox
			// 
			this->BoosterFormRechargeTextBox->Location = System::Drawing::Point(147, 130);
			this->BoosterFormRechargeTextBox->MaxLength = 10;
			this->BoosterFormRechargeTextBox->Name = L"BoosterFormRechargeTextBox";
			this->BoosterFormRechargeTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormRechargeTextBox->TabIndex = 5;
			this->BoosterFormRechargeTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &BoosterForm::BoosterFormRechargeTextBox_KeyPress);
			this->BoosterFormRechargeTextBox->TextChanged += gcnew System::EventHandler(this, &BoosterForm::BoosterFormRechargeTextBox_TextChanged);
			// 
			// BoosterFormEnergyTextBox
			// 
			this->BoosterFormEnergyTextBox->Location = System::Drawing::Point(147, 104);
			this->BoosterFormEnergyTextBox->MaxLength = 10;
			this->BoosterFormEnergyTextBox->Name = L"BoosterFormEnergyTextBox";
			this->BoosterFormEnergyTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormEnergyTextBox->TabIndex = 4;
			this->BoosterFormEnergyTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &BoosterForm::BoosterFormEnergyTextBox_KeyPress);
			this->BoosterFormEnergyTextBox->TextChanged += gcnew System::EventHandler(this, &BoosterForm::BoosterFormEnergyTextBox_TextChanged);
			// 
			// BoosterFormDrainTextBox
			// 
			this->BoosterFormDrainTextBox->Location = System::Drawing::Point(147, 52);
			this->BoosterFormDrainTextBox->MaxLength = 10;
			this->BoosterFormDrainTextBox->Name = L"BoosterFormDrainTextBox";
			this->BoosterFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormDrainTextBox->TabIndex = 2;
			this->BoosterFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &BoosterForm::BoosterFormDrainTextBox_KeyPress);
			this->BoosterFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &BoosterForm::BoosterFormDrainTextBox_TextChanged);
			// 
			// BoosterFormMassTextBox
			// 
			this->BoosterFormMassTextBox->Location = System::Drawing::Point(147, 78);
			this->BoosterFormMassTextBox->MaxLength = 10;
			this->BoosterFormMassTextBox->Name = L"BoosterFormMassTextBox";
			this->BoosterFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormMassTextBox->TabIndex = 3;
			this->BoosterFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &BoosterForm::BoosterFormMassTextBox_KeyPress);
			this->BoosterFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &BoosterForm::BoosterFormMassTextBox_TextChanged);
			// 
			// BoosterFormArmorTextBox
			// 
			this->BoosterFormArmorTextBox->Location = System::Drawing::Point(147, 26);
			this->BoosterFormArmorTextBox->MaxLength = 10;
			this->BoosterFormArmorTextBox->Name = L"BoosterFormArmorTextBox";
			this->BoosterFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormArmorTextBox->TabIndex = 1;
			this->BoosterFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &BoosterForm::BoosterFormArmorTextBox_KeyPress);
			this->BoosterFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &BoosterForm::BoosterFormArmorTextBox_TextChanged);
			// 
			// E_AccelerationLabel
			// 
			this->E_AccelerationLabel->AutoSize = true;
			this->E_AccelerationLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_AccelerationLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_AccelerationLabel->Location = System::Drawing::Point(46, 183);
			this->E_AccelerationLabel->Name = L"E_AccelerationLabel";
			this->E_AccelerationLabel->Size = System::Drawing::Size(96, 16);
			this->E_AccelerationLabel->TabIndex = 92;
			this->E_AccelerationLabel->Text = L"Acceleration:";
			// 
			// E_ConsumptionLabel
			// 
			this->E_ConsumptionLabel->AutoSize = true;
			this->E_ConsumptionLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_ConsumptionLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_ConsumptionLabel->Location = System::Drawing::Point(46, 157);
			this->E_ConsumptionLabel->Name = L"E_ConsumptionLabel";
			this->E_ConsumptionLabel->Size = System::Drawing::Size(98, 16);
			this->E_ConsumptionLabel->TabIndex = 91;
			this->E_ConsumptionLabel->Text = L"Consumption:";
			// 
			// E_RechargeLabel
			// 
			this->E_RechargeLabel->AutoSize = true;
			this->E_RechargeLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_RechargeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_RechargeLabel->Location = System::Drawing::Point(46, 131);
			this->E_RechargeLabel->Name = L"E_RechargeLabel";
			this->E_RechargeLabel->Size = System::Drawing::Size(75, 16);
			this->E_RechargeLabel->TabIndex = 90;
			this->E_RechargeLabel->Text = L"Recharge:";
			// 
			// B_EnergyLabel
			// 
			this->B_EnergyLabel->AutoSize = true;
			this->B_EnergyLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_EnergyLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_EnergyLabel->Location = System::Drawing::Point(46, 105);
			this->B_EnergyLabel->Name = L"B_EnergyLabel";
			this->B_EnergyLabel->Size = System::Drawing::Size(59, 16);
			this->B_EnergyLabel->TabIndex = 89;
			this->B_EnergyLabel->Text = L"Energy:";
			// 
			// B_DrainLabel
			// 
			this->B_DrainLabel->AutoSize = true;
			this->B_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_DrainLabel->Location = System::Drawing::Point(46, 53);
			this->B_DrainLabel->Name = L"B_DrainLabel";
			this->B_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->B_DrainLabel->TabIndex = 88;
			this->B_DrainLabel->Text = L"Drain:";
			// 
			// B_MassLabel
			// 
			this->B_MassLabel->AutoSize = true;
			this->B_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_MassLabel->Location = System::Drawing::Point(46, 79);
			this->B_MassLabel->Name = L"B_MassLabel";
			this->B_MassLabel->Size = System::Drawing::Size(47, 16);
			this->B_MassLabel->TabIndex = 87;
			this->B_MassLabel->Text = L"Mass:";
			// 
			// B_ArmorLabel
			// 
			this->B_ArmorLabel->AutoSize = true;
			this->B_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_ArmorLabel->Location = System::Drawing::Point(46, 27);
			this->B_ArmorLabel->Name = L"B_ArmorLabel";
			this->B_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->B_ArmorLabel->TabIndex = 86;
			this->B_ArmorLabel->Text = L"Armor:";
			// 
			// BoosterFormLabel
			// 
			this->BoosterFormLabel->AutoSize = true;
			this->BoosterFormLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterFormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterFormLabel->Location = System::Drawing::Point(102, 6);
			this->BoosterFormLabel->Name = L"BoosterFormLabel";
			this->BoosterFormLabel->Size = System::Drawing::Size(89, 16);
			this->BoosterFormLabel->TabIndex = 85;
			this->BoosterFormLabel->Text = L"B o o s t e r";
			// 
			// BoosterFormSpeedTextBox
			// 
			this->BoosterFormSpeedTextBox->Location = System::Drawing::Point(147, 208);
			this->BoosterFormSpeedTextBox->MaxLength = 10;
			this->BoosterFormSpeedTextBox->Name = L"BoosterFormSpeedTextBox";
			this->BoosterFormSpeedTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormSpeedTextBox->TabIndex = 8;
			this->BoosterFormSpeedTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &BoosterForm::BoosterFormSpeedTextBox_KeyPress);
			this->BoosterFormSpeedTextBox->TextChanged += gcnew System::EventHandler(this, &BoosterForm::BoosterFormSpeedTextBox_TextChanged);
			// 
			// B_SpeedLabel
			// 
			this->B_SpeedLabel->AutoSize = true;
			this->B_SpeedLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_SpeedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_SpeedLabel->Location = System::Drawing::Point(46, 209);
			this->B_SpeedLabel->Name = L"B_SpeedLabel";
			this->B_SpeedLabel->Size = System::Drawing::Size(55, 16);
			this->B_SpeedLabel->TabIndex = 103;
			this->B_SpeedLabel->Text = L"Speed:";
			// 
			// BoosterForm
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(292, 277);
			this->ControlBox = false;
			this->Controls->Add(this->B_SpeedLabel);
			this->Controls->Add(this->BoosterFormSpeedTextBox);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->BoosterFormAccelerationTextBox);
			this->Controls->Add(this->BoosterFormConsumptionTextBox);
			this->Controls->Add(this->BoosterFormRechargeTextBox);
			this->Controls->Add(this->BoosterFormEnergyTextBox);
			this->Controls->Add(this->BoosterFormDrainTextBox);
			this->Controls->Add(this->BoosterFormMassTextBox);
			this->Controls->Add(this->BoosterFormArmorTextBox);
			this->Controls->Add(this->E_AccelerationLabel);
			this->Controls->Add(this->E_ConsumptionLabel);
			this->Controls->Add(this->E_RechargeLabel);
			this->Controls->Add(this->B_EnergyLabel);
			this->Controls->Add(this->B_DrainLabel);
			this->Controls->Add(this->B_MassLabel);
			this->Controls->Add(this->B_ArmorLabel);
			this->Controls->Add(this->BoosterFormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"BoosterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Booster";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void LoadData(){
			 System::Data::DataRow^ rowBooster;

			 if (m_Booster->Rows->Count != 0)
			 {
				 rowBooster = m_Booster[0];

				 BoosterFormArmorTextBox->Text = rowBooster["Armor"]->ToString();
				 BoosterFormMassTextBox->Text = rowBooster["Mass"]->ToString();
				 BoosterFormDrainTextBox->Text = rowBooster["Drain"]->ToString();
				 BoosterFormEnergyTextBox->Text = rowBooster["Energy"]->ToString();
				 BoosterFormRechargeTextBox->Text = rowBooster["Recharge"]->ToString();
				 BoosterFormConsumptionTextBox->Text = rowBooster["Consumption"]->ToString();
				 BoosterFormAccelerationTextBox->Text = rowBooster["Acceleration"]->ToString();
				 BoosterFormSpeedTextBox->Text = rowBooster["Top Speed"]->ToString();
			 }
		 }

private: System::Void UpdateGUI(){
			 if (BoosterFormArmorTextBox->Text != "" && BoosterFormMassTextBox->Text != "" && 
				 BoosterFormDrainTextBox->Text != "" && BoosterFormEnergyTextBox->Text != "" &&
				 BoosterFormRechargeTextBox->Text != "" && BoosterFormConsumptionTextBox->Text != "" &&
				 BoosterFormAccelerationTextBox->Text != "" && BoosterFormSpeedTextBox->Text != "")
			 {
				 SaveButton->Enabled = true;
			 }
			 else
			 {
				 SaveButton->Enabled = false;
			 }
		 }
	private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (m_Booster->Rows->Count == 0)
				 {
					 m_Booster->AddBooster(m_BoosterName, Convert::ToDouble(BoosterFormArmorTextBox->Text->ToString()), 
						 Convert::ToDouble(BoosterFormMassTextBox->Text->ToString()), 
						 Convert::ToDouble(BoosterFormDrainTextBox->Text->ToString()),
						 Convert::ToDouble(BoosterFormEnergyTextBox->Text->ToString()),
						 Convert::ToDouble(BoosterFormRechargeTextBox->Text->ToString()),
						 Convert::ToDouble(BoosterFormConsumptionTextBox->Text->ToString()),
						 Convert::ToDouble(BoosterFormAccelerationTextBox->Text->ToString()),
						 Convert::ToDouble(BoosterFormSpeedTextBox->Text->ToString()));

					 m_Booster->TableName = String::Concat("Booster_", m_BoosterName);

					 this->Close();
				 }
				 else
				 {
					 m_Booster->RemoveBooster(m_BoosterName);

					 m_Booster->AddBooster(m_BoosterName, Convert::ToDouble(BoosterFormArmorTextBox->Text->ToString()), 
						 Convert::ToDouble(BoosterFormMassTextBox->Text->ToString()), 
						 Convert::ToDouble(BoosterFormDrainTextBox->Text->ToString()),
						 Convert::ToDouble(BoosterFormEnergyTextBox->Text->ToString()),
						 Convert::ToDouble(BoosterFormRechargeTextBox->Text->ToString()),
						 Convert::ToDouble(BoosterFormConsumptionTextBox->Text->ToString()),
						 Convert::ToDouble(BoosterFormAccelerationTextBox->Text->ToString()),
						 Convert::ToDouble(BoosterFormSpeedTextBox->Text->ToString()));

					 m_Booster->TableName = String::Concat("Booster_", m_BoosterName);

					 this->Close();
				 }
			 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void BoosterFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void BoosterFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void BoosterFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void BoosterFormEnergyTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void BoosterFormRechargeTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void BoosterFormConsumptionTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void BoosterFormAccelerationTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void BoosterFormSpeedTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void BoosterFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormEnergyTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormRechargeTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormConsumptionTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormAccelerationTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormSpeedTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
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
