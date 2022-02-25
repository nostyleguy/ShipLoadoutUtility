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
	/// Summary for ArmorForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ArmorForm : public System::Windows::Forms::Form
	{
	private:
		Armor^ m_Armor;
		String^ m_ArmorName;
	public:
		ArmorForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		ArmorForm(Armor^ armorData, String^ armorName)
		{
			InitializeComponent();

			this->Text = String::Concat("Armor: ", armorName);

			m_Armor = gcnew CompLib::Armor;
			m_Armor->Merge(armorData);

			m_ArmorName = armorName;
			
			LoadData();
			UpdateGUI();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ArmorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  SaveButton;
	protected: 

	private: System::Windows::Forms::TextBox^  ArmorFormMassTextBox;

	private: System::Windows::Forms::TextBox^  ArmorFormArmorTextBox;
	private: System::Windows::Forms::Label^  ArmorFormLabel;
	private: System::Windows::Forms::Label^  A_MassLabel;

	private: System::Windows::Forms::Label^  A_ArmorLabel;

	public:
		property Armor^ ArmorData
		{
			Armor^ get() { return m_Armor; }
			void set (Armor^ value) { m_Armor = value; }
		}
		property String^ ArmorName
		{
			String^ get() { return m_ArmorName; }
			void set (String^ value) { m_ArmorName = value; }
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ArmorForm::typeid));
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->ArmorFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ArmorFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ArmorFormLabel = (gcnew System::Windows::Forms::Label());
			this->A_MassLabel = (gcnew System::Windows::Forms::Label());
			this->A_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 228);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 4;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &ArmorForm::CancelButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->SaveButton->ForeColor = System::Drawing::Color::Black;
			this->SaveButton->Location = System::Drawing::Point(68, 228);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 3;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &ArmorForm::SaveButton_Click);
			// 
			// ArmorFormMassTextBox
			// 
			this->ArmorFormMassTextBox->Location = System::Drawing::Point(166, 141);
			this->ArmorFormMassTextBox->MaxLength = 10;
			this->ArmorFormMassTextBox->Name = L"ArmorFormMassTextBox";
			this->ArmorFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->ArmorFormMassTextBox->TabIndex = 2;
			this->ArmorFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ArmorForm::ArmorFormMassTextBox_KeyPress);
			this->ArmorFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &ArmorForm::ArmorFormMassTextBox_TextChanged);
			// 
			// ArmorFormArmorTextBox
			// 
			this->ArmorFormArmorTextBox->Location = System::Drawing::Point(166, 105);
			this->ArmorFormArmorTextBox->MaxLength = 10;
			this->ArmorFormArmorTextBox->Name = L"ArmorFormArmorTextBox";
			this->ArmorFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->ArmorFormArmorTextBox->TabIndex = 1;
			this->ArmorFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ArmorForm::ArmorFormArmorTextBox_KeyPress);
			this->ArmorFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &ArmorForm::ArmorFormArmorTextBox_TextChanged);
			// 
			// ArmorFormLabel
			// 
			this->ArmorFormLabel->AutoSize = true;
			this->ArmorFormLabel->BackColor = System::Drawing::Color::Transparent;
			this->ArmorFormLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ArmorFormLabel->Location = System::Drawing::Point(114, 15);
			this->ArmorFormLabel->Name = L"ArmorFormLabel";
			this->ArmorFormLabel->Size = System::Drawing::Size(65, 16);
			this->ArmorFormLabel->TabIndex = 70;
			this->ArmorFormLabel->Text = L"A r m o r";
			// 
			// A_MassLabel
			// 
			this->A_MassLabel->AutoSize = true;
			this->A_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->A_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->A_MassLabel->Location = System::Drawing::Point(26, 143);
			this->A_MassLabel->Name = L"A_MassLabel";
			this->A_MassLabel->Size = System::Drawing::Size(47, 16);
			this->A_MassLabel->TabIndex = 68;
			this->A_MassLabel->Text = L"Mass:";
			// 
			// A_ArmorLabel
			// 
			this->A_ArmorLabel->AutoSize = true;
			this->A_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->A_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->A_ArmorLabel->Location = System::Drawing::Point(26, 107);
			this->A_ArmorLabel->Name = L"A_ArmorLabel";
			this->A_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->A_ArmorLabel->TabIndex = 67;
			this->A_ArmorLabel->Text = L"Armor:";
			// 
			// ArmorForm
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CancelButton = this->CancelButton;
			this->ClientSize = System::Drawing::Size(292, 266);
			this->ControlBox = false;
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->ArmorFormMassTextBox);
			this->Controls->Add(this->ArmorFormArmorTextBox);
			this->Controls->Add(this->ArmorFormLabel);
			this->Controls->Add(this->A_MassLabel);
			this->Controls->Add(this->A_ArmorLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ArmorForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Armor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void UpdateGUI(){
			 if (ArmorFormArmorTextBox->Text != "" && ArmorFormMassTextBox->Text != "")
			 {
				 SaveButton->Enabled = true;
			 }
			 else
			 {
				 SaveButton->Enabled = false;
			 }
		 }
private: System::Void LoadData(){
			 System::Data::DataRow^ rowArmor;

			 if (m_Armor->Rows->Count != 0)
			 {
				 rowArmor = m_Armor[0];

				 ArmorFormArmorTextBox->Text = rowArmor["Armor"]->ToString();
				 ArmorFormMassTextBox->Text = rowArmor["Mass"]->ToString();
			 }
		 }

private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (m_Armor->Rows->Count == 0)
			 {
				 m_Armor->AddArmor(m_ArmorName, Convert::ToDouble(ArmorFormArmorTextBox->Text->ToString()), 
					 Convert::ToDouble(ArmorFormMassTextBox->Text->ToString()));

				 m_Armor->TableName = String::Concat("Armor_", m_ArmorName);

				 this->Close();
			 }
			 else
			 {
				 m_Armor->RemoveArmor(m_ArmorName);

				 m_Armor->AddArmor(m_ArmorName, Convert::ToDouble(ArmorFormArmorTextBox->Text->ToString()), 
					 Convert::ToDouble(ArmorFormMassTextBox->Text->ToString()));

				 m_Armor->TableName = String::Concat("Armor_", m_ArmorName);

				 this->Close();
			 }
		 }

private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void ArmorFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void ArmorFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void ArmorFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }	
		 }
private: System::Void ArmorFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
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
