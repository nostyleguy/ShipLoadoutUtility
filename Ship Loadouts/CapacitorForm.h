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
	/// Summary for CapacitorForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class CapacitorForm : public System::Windows::Forms::Form
	{
	private:
		Capacitor^ m_Capacitor;
		String^ m_CapacitorName;
	public:
		CapacitorForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		CapacitorForm(Capacitor^ capacitorData, String^ capacitorName)
		{
			InitializeComponent();

			this->Text = String::Concat("Capacitor: ", capacitorName);

			m_Capacitor = gcnew CompLib::Capacitor;
			m_Capacitor->Merge(capacitorData);

			m_CapacitorName = capacitorName;

			LoadData();
			UpdateGUI();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CapacitorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  CapacitorFormEnergyTextBox;
	protected: 
	private: System::Windows::Forms::Label^  C_EnergyLabel;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  SaveButton;

	private: System::Windows::Forms::TextBox^  CapacitorFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  CapacitorFormMassTextBox;
	private: System::Windows::Forms::TextBox^  CapacitorFormArmorTextBox;
	private: System::Windows::Forms::Label^  CapacitorFormLabel;
	private: System::Windows::Forms::Label^  C_DrainLabel;
	private: System::Windows::Forms::Label^  C_MassLabel;
	private: System::Windows::Forms::Label^  C_ArmorLabel;
	private: System::Windows::Forms::TextBox^  CapacitorFormRechargeTextBox;
	private: System::Windows::Forms::Label^  C_RechargeLabel;

	public:
		property Capacitor^ CapacitorList
		{
			Capacitor^ get() { return m_Capacitor; }
			void set (Capacitor^ value) { m_Capacitor = value; }
		}
		property String^ CapacitorName
		{
			String^ get() { return m_CapacitorName; }
			void set (String^ value) { m_CapacitorName = value; }
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CapacitorForm::typeid));
			this->CapacitorFormEnergyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->C_EnergyLabel = (gcnew System::Windows::Forms::Label());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->CapacitorFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CapacitorFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CapacitorFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CapacitorFormLabel = (gcnew System::Windows::Forms::Label());
			this->C_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->C_MassLabel = (gcnew System::Windows::Forms::Label());
			this->C_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorFormRechargeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->C_RechargeLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// CapacitorFormEnergyTextBox
			// 
			this->CapacitorFormEnergyTextBox->Location = System::Drawing::Point(166, 153);
			this->CapacitorFormEnergyTextBox->MaxLength = 10;
			this->CapacitorFormEnergyTextBox->Name = L"CapacitorFormEnergyTextBox";
			this->CapacitorFormEnergyTextBox->Size = System::Drawing::Size(100, 20);
			this->CapacitorFormEnergyTextBox->TabIndex = 4;
			this->CapacitorFormEnergyTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &CapacitorForm::CapacitorFormEnergyTextBox_KeyPress);
			this->CapacitorFormEnergyTextBox->TextChanged += gcnew System::EventHandler(this, &CapacitorForm::CapacitorFormEnergyTextBox_TextChanged);
			// 
			// C_EnergyLabel
			// 
			this->C_EnergyLabel->AutoSize = true;
			this->C_EnergyLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_EnergyLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_EnergyLabel->Location = System::Drawing::Point(26, 154);
			this->C_EnergyLabel->Name = L"C_EnergyLabel";
			this->C_EnergyLabel->Size = System::Drawing::Size(59, 16);
			this->C_EnergyLabel->TabIndex = 87;
			this->C_EnergyLabel->Text = L"Energy:";
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 228);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 7;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &CapacitorForm::CancelButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->SaveButton->ForeColor = System::Drawing::Color::Black;
			this->SaveButton->Location = System::Drawing::Point(68, 228);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 6;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &CapacitorForm::SaveButton_Click);
			// 
			// CapacitorFormDrainTextBox
			// 
			this->CapacitorFormDrainTextBox->Location = System::Drawing::Point(166, 85);
			this->CapacitorFormDrainTextBox->MaxLength = 10;
			this->CapacitorFormDrainTextBox->Name = L"CapacitorFormDrainTextBox";
			this->CapacitorFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->CapacitorFormDrainTextBox->TabIndex = 2;
			this->CapacitorFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &CapacitorForm::CapacitorFormDrainTextBox_KeyPress);
			this->CapacitorFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &CapacitorForm::CapacitorFormDrainTextBox_TextChanged);
			// 
			// CapacitorFormMassTextBox
			// 
			this->CapacitorFormMassTextBox->Location = System::Drawing::Point(166, 119);
			this->CapacitorFormMassTextBox->MaxLength = 10;
			this->CapacitorFormMassTextBox->Name = L"CapacitorFormMassTextBox";
			this->CapacitorFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->CapacitorFormMassTextBox->TabIndex = 3;
			this->CapacitorFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &CapacitorForm::CapacitorFormMassTextBox_KeyPress);
			this->CapacitorFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &CapacitorForm::CapacitorFormMassTextBox_TextChanged);
			// 
			// CapacitorFormArmorTextBox
			// 
			this->CapacitorFormArmorTextBox->Location = System::Drawing::Point(166, 51);
			this->CapacitorFormArmorTextBox->MaxLength = 10;
			this->CapacitorFormArmorTextBox->Name = L"CapacitorFormArmorTextBox";
			this->CapacitorFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->CapacitorFormArmorTextBox->TabIndex = 1;
			this->CapacitorFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &CapacitorForm::CapacitorFormArmorTextBox_KeyPress);
			this->CapacitorFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &CapacitorForm::CapacitorFormArmorTextBox_TextChanged);
			// 
			// CapacitorFormLabel
			// 
			this->CapacitorFormLabel->AutoSize = true;
			this->CapacitorFormLabel->BackColor = System::Drawing::Color::Transparent;
			this->CapacitorFormLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorFormLabel->Location = System::Drawing::Point(93, 15);
			this->CapacitorFormLabel->Name = L"CapacitorFormLabel";
			this->CapacitorFormLabel->Size = System::Drawing::Size(107, 16);
			this->CapacitorFormLabel->TabIndex = 81;
			this->CapacitorFormLabel->Text = L"C a p a c i t o r";
			// 
			// C_DrainLabel
			// 
			this->C_DrainLabel->AutoSize = true;
			this->C_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_DrainLabel->Location = System::Drawing::Point(26, 86);
			this->C_DrainLabel->Name = L"C_DrainLabel";
			this->C_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->C_DrainLabel->TabIndex = 80;
			this->C_DrainLabel->Text = L"Drain:";
			this->C_DrainLabel->Click += gcnew System::EventHandler(this, &CapacitorForm::C_DrainLabel_Click);
			// 
			// C_MassLabel
			// 
			this->C_MassLabel->AutoSize = true;
			this->C_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_MassLabel->Location = System::Drawing::Point(26, 120);
			this->C_MassLabel->Name = L"C_MassLabel";
			this->C_MassLabel->Size = System::Drawing::Size(47, 16);
			this->C_MassLabel->TabIndex = 79;
			this->C_MassLabel->Text = L"Mass:";
			// 
			// C_ArmorLabel
			// 
			this->C_ArmorLabel->AutoSize = true;
			this->C_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_ArmorLabel->Location = System::Drawing::Point(26, 52);
			this->C_ArmorLabel->Name = L"C_ArmorLabel";
			this->C_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->C_ArmorLabel->TabIndex = 78;
			this->C_ArmorLabel->Text = L"Armor:";
			// 
			// CapacitorFormRechargeTextBox
			// 
			this->CapacitorFormRechargeTextBox->Location = System::Drawing::Point(166, 187);
			this->CapacitorFormRechargeTextBox->MaxLength = 10;
			this->CapacitorFormRechargeTextBox->Name = L"CapacitorFormRechargeTextBox";
			this->CapacitorFormRechargeTextBox->Size = System::Drawing::Size(100, 20);
			this->CapacitorFormRechargeTextBox->TabIndex = 5;
			this->CapacitorFormRechargeTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &CapacitorForm::CapacitorFormRechargeTextBox_KeyPress);
			this->CapacitorFormRechargeTextBox->TextChanged += gcnew System::EventHandler(this, &CapacitorForm::CapacitorFormRechargeTextBox_TextChanged);
			// 
			// C_RechargeLabel
			// 
			this->C_RechargeLabel->AutoSize = true;
			this->C_RechargeLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_RechargeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_RechargeLabel->Location = System::Drawing::Point(26, 188);
			this->C_RechargeLabel->Name = L"C_RechargeLabel";
			this->C_RechargeLabel->Size = System::Drawing::Size(75, 16);
			this->C_RechargeLabel->TabIndex = 90;
			this->C_RechargeLabel->Text = L"Recharge:";
			// 
			// CapacitorForm
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
			this->Controls->Add(this->C_RechargeLabel);
			this->Controls->Add(this->CapacitorFormRechargeTextBox);
			this->Controls->Add(this->CapacitorFormEnergyTextBox);
			this->Controls->Add(this->C_EnergyLabel);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->CapacitorFormDrainTextBox);
			this->Controls->Add(this->CapacitorFormMassTextBox);
			this->Controls->Add(this->CapacitorFormArmorTextBox);
			this->Controls->Add(this->CapacitorFormLabel);
			this->Controls->Add(this->C_DrainLabel);
			this->Controls->Add(this->C_MassLabel);
			this->Controls->Add(this->C_ArmorLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"CapacitorForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Capacitor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void LoadData(){
			 System::Data::DataRow^ rowCapacitor;

			 if (m_Capacitor->Rows->Count != 0)
			 {
				 rowCapacitor = m_Capacitor[0];

				 CapacitorFormArmorTextBox->Text = rowCapacitor["Armor"]->ToString();
				 CapacitorFormMassTextBox->Text = rowCapacitor["Mass"]->ToString();
				 CapacitorFormDrainTextBox->Text = rowCapacitor["Drain"]->ToString();
				 CapacitorFormEnergyTextBox->Text = rowCapacitor["Energy"]->ToString();
				 CapacitorFormRechargeTextBox->Text = rowCapacitor["Recharge"]->ToString();
			 }
		 }

private: System::Void UpdateGUI(){
			 if (CapacitorFormArmorTextBox->Text != "" && CapacitorFormMassTextBox->Text != "" && 
				 CapacitorFormDrainTextBox->Text != "" && CapacitorFormEnergyTextBox->Text != "" &&
				 CapacitorFormRechargeTextBox->Text != "")
			 {
				 SaveButton->Enabled = true;
			 }
			 else
			 {
				 SaveButton->Enabled = false;
			 }
		 }
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (m_Capacitor->Rows->Count == 0)
			 {
				 m_Capacitor->AddCapacitor(m_CapacitorName, Convert::ToDouble(CapacitorFormArmorTextBox->Text->ToString()), 
					 Convert::ToDouble(CapacitorFormMassTextBox->Text->ToString()), 
					 Convert::ToDouble(CapacitorFormDrainTextBox->Text->ToString()),
					 Convert::ToDouble(CapacitorFormEnergyTextBox->Text->ToString()),
					 Convert::ToDouble(CapacitorFormRechargeTextBox->Text->ToString()));

				 m_Capacitor->TableName = String::Concat("Capacitor_", m_CapacitorName);

				 this->Close();
			 }
			 else
			 {
				 m_Capacitor->RemoveCapacitor(m_CapacitorName);

				 m_Capacitor->AddCapacitor(m_CapacitorName, Convert::ToDouble(CapacitorFormArmorTextBox->Text->ToString()), 
					 Convert::ToDouble(CapacitorFormMassTextBox->Text->ToString()), 
					 Convert::ToDouble(CapacitorFormDrainTextBox->Text->ToString()),
					 Convert::ToDouble(CapacitorFormEnergyTextBox->Text->ToString()),
					 Convert::ToDouble(CapacitorFormRechargeTextBox->Text->ToString()));

				 m_Capacitor->TableName = String::Concat("Capacitor_", m_CapacitorName);

				 this->Close();
			 }
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void CapacitorFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void CapacitorFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void CapacitorFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void CapacitorFormEnergyTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void CapacitorFormRechargeTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void CapacitorFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void CapacitorFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void CapacitorFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void CapacitorFormEnergyTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void CapacitorFormRechargeTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void C_DrainLabel_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
