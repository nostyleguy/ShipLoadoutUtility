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
	/// Summary for DroidForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class DroidForm : public System::Windows::Forms::Form
	{
	private:
		Droid^ m_Droid;
		String^ m_DroidName;
	public:
		DroidForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		DroidForm(Droid^ droidData, String^ droidName)
		{
			InitializeComponent();

			this->Text = String::Concat("Droid Interface: ", droidName);

			m_Droid = gcnew CompLib::Droid;
			m_Droid->Merge(droidData);

			m_DroidName = droidName;

			LoadData();
			UpdateGUI();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DroidForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  SaveButton;
	protected: 

	private: System::Windows::Forms::TextBox^  DroidFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  DroidFormMassTextBox;
	private: System::Windows::Forms::TextBox^  DroidFormArmorTextBox;
	private: System::Windows::Forms::Label^  DroidFormLabel;
	private: System::Windows::Forms::Label^  D_DrainLabel;
	private: System::Windows::Forms::Label^  D_MassLabel;
	private: System::Windows::Forms::Label^  D_ArmorLabel;
	private: System::Windows::Forms::Label^  D_SpeedLabel;
	private: System::Windows::Forms::TextBox^  DroidFormSpeedTextBox;

	public:
		property Droid^ DroidList
		{
			Droid^ get() { return m_Droid; }
			void set (Droid^ value) { m_Droid = value; }
		}
		property String^ DroidName
		{
			String^ get() { return m_DroidName; }
			void set (String^ value) { m_DroidName = value; }
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(DroidForm::typeid));
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->DroidFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DroidFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DroidFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DroidFormLabel = (gcnew System::Windows::Forms::Label());
			this->D_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->D_MassLabel = (gcnew System::Windows::Forms::Label());
			this->D_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->D_SpeedLabel = (gcnew System::Windows::Forms::Label());
			this->DroidFormSpeedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 228);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 6;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &DroidForm::CancelButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->SaveButton->ForeColor = System::Drawing::Color::Black;
			this->SaveButton->Location = System::Drawing::Point(68, 228);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 5;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &DroidForm::SaveButton_Click);
			// 
			// DroidFormDrainTextBox
			// 
			this->DroidFormDrainTextBox->Location = System::Drawing::Point(166, 101);
			this->DroidFormDrainTextBox->MaxLength = 10;
			this->DroidFormDrainTextBox->Name = L"DroidFormDrainTextBox";
			this->DroidFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->DroidFormDrainTextBox->TabIndex = 2;
			this->DroidFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &DroidForm::DroidFormDrainTextBox_KeyPress);
			this->DroidFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &DroidForm::DroidFormDrainTextBox_TextChanged);
			// 
			// DroidFormMassTextBox
			// 
			this->DroidFormMassTextBox->Location = System::Drawing::Point(166, 136);
			this->DroidFormMassTextBox->MaxLength = 10;
			this->DroidFormMassTextBox->Name = L"DroidFormMassTextBox";
			this->DroidFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->DroidFormMassTextBox->TabIndex = 3;
			this->DroidFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &DroidForm::DroidFormMassTextBox_KeyPress);
			this->DroidFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &DroidForm::DroidFormMassTextBox_TextChanged);
			// 
			// DroidFormArmorTextBox
			// 
			this->DroidFormArmorTextBox->Location = System::Drawing::Point(166, 66);
			this->DroidFormArmorTextBox->MaxLength = 10;
			this->DroidFormArmorTextBox->Name = L"DroidFormArmorTextBox";
			this->DroidFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->DroidFormArmorTextBox->TabIndex = 1;
			this->DroidFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &DroidForm::DroidFormArmorTextBox_KeyPress);
			this->DroidFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &DroidForm::DroidFormArmorTextBox_TextChanged);
			// 
			// DroidFormLabel
			// 
			this->DroidFormLabel->AutoSize = true;
			this->DroidFormLabel->BackColor = System::Drawing::Color::Transparent;
			this->DroidFormLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DroidFormLabel->Location = System::Drawing::Point(65, 15);
			this->DroidFormLabel->Name = L"DroidFormLabel";
			this->DroidFormLabel->Size = System::Drawing::Size(162, 16);
			this->DroidFormLabel->TabIndex = 70;
			this->DroidFormLabel->Text = L"D r o i d  I n t e r f a c e";
			// 
			// D_DrainLabel
			// 
			this->D_DrainLabel->AutoSize = true;
			this->D_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_DrainLabel->Location = System::Drawing::Point(26, 102);
			this->D_DrainLabel->Name = L"D_DrainLabel";
			this->D_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->D_DrainLabel->TabIndex = 69;
			this->D_DrainLabel->Text = L"Drain:";
			// 
			// D_MassLabel
			// 
			this->D_MassLabel->AutoSize = true;
			this->D_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_MassLabel->Location = System::Drawing::Point(26, 137);
			this->D_MassLabel->Name = L"D_MassLabel";
			this->D_MassLabel->Size = System::Drawing::Size(47, 16);
			this->D_MassLabel->TabIndex = 68;
			this->D_MassLabel->Text = L"Mass:";
			// 
			// D_ArmorLabel
			// 
			this->D_ArmorLabel->AutoSize = true;
			this->D_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_ArmorLabel->Location = System::Drawing::Point(26, 67);
			this->D_ArmorLabel->Name = L"D_ArmorLabel";
			this->D_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->D_ArmorLabel->TabIndex = 67;
			this->D_ArmorLabel->Text = L"Armor:";
			// 
			// D_SpeedLabel
			// 
			this->D_SpeedLabel->AutoSize = true;
			this->D_SpeedLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_SpeedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_SpeedLabel->Location = System::Drawing::Point(26, 172);
			this->D_SpeedLabel->Name = L"D_SpeedLabel";
			this->D_SpeedLabel->Size = System::Drawing::Size(55, 16);
			this->D_SpeedLabel->TabIndex = 76;
			this->D_SpeedLabel->Text = L"Speed:";
			// 
			// DroidFormSpeedTextBox
			// 
			this->DroidFormSpeedTextBox->Location = System::Drawing::Point(166, 171);
			this->DroidFormSpeedTextBox->MaxLength = 10;
			this->DroidFormSpeedTextBox->Name = L"DroidFormSpeedTextBox";
			this->DroidFormSpeedTextBox->Size = System::Drawing::Size(100, 20);
			this->DroidFormSpeedTextBox->TabIndex = 4;
			this->DroidFormSpeedTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &DroidForm::DroidFormSpeedTextBox_KeyPress);
			this->DroidFormSpeedTextBox->TextChanged += gcnew System::EventHandler(this, &DroidForm::DroidFormSpeedTextBox_TextChanged);
			// 
			// DroidForm
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
			this->Controls->Add(this->DroidFormSpeedTextBox);
			this->Controls->Add(this->D_SpeedLabel);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->DroidFormDrainTextBox);
			this->Controls->Add(this->DroidFormMassTextBox);
			this->Controls->Add(this->DroidFormArmorTextBox);
			this->Controls->Add(this->DroidFormLabel);
			this->Controls->Add(this->D_DrainLabel);
			this->Controls->Add(this->D_MassLabel);
			this->Controls->Add(this->D_ArmorLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"DroidForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Droid Interface";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void LoadData(){
			 System::Data::DataRow^ rowDroid;

			 if (m_Droid->Rows->Count != 0)
			 {
				 rowDroid = m_Droid[0];

				 DroidFormArmorTextBox->Text = rowDroid["Armor"]->ToString();
				 DroidFormMassTextBox->Text = rowDroid["Mass"]->ToString();
				 DroidFormDrainTextBox->Text = rowDroid["Drain"]->ToString();
				 DroidFormSpeedTextBox->Text = rowDroid["Command Speed"]->ToString();
			 }
		 }

private: System::Void UpdateGUI(){
			 if (DroidFormArmorTextBox->Text != "" && DroidFormMassTextBox->Text != "" && 
				 DroidFormDrainTextBox->Text != "" && DroidFormSpeedTextBox->Text != "")
			 {
				 SaveButton->Enabled = true;
			 }
			 else
			 {
				 SaveButton->Enabled = false;
			 }
		 }
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (m_Droid->Rows->Count == 0)
			 {
				 m_Droid->AddDroid(m_DroidName, Convert::ToDouble(DroidFormArmorTextBox->Text->ToString()), 
					 Convert::ToDouble(DroidFormMassTextBox->Text->ToString()), 
					 Convert::ToDouble(DroidFormDrainTextBox->Text->ToString()),
					 Convert::ToDouble(DroidFormSpeedTextBox->Text->ToString()));

				 m_Droid->TableName = String::Concat("Droid_", m_DroidName);

				 this->Close();
			 }
			 else
			 {
				 m_Droid->RemoveDroid(m_DroidName);

				 m_Droid->AddDroid(m_DroidName, Convert::ToDouble(DroidFormArmorTextBox->Text->ToString()), 
					 Convert::ToDouble(DroidFormMassTextBox->Text->ToString()), 
					 Convert::ToDouble(DroidFormDrainTextBox->Text->ToString()),
					 Convert::ToDouble(DroidFormSpeedTextBox->Text->ToString()));

				 m_Droid->TableName = String::Concat("Droid_", m_DroidName);

				 this->Close();
			 }
		 }

private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void DroidFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void DroidFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void DroidFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void DroidFormSpeedTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void DroidFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void DroidFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void DroidFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void DroidFormSpeedTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
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
