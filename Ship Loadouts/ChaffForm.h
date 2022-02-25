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
	/// Summary for ChaffForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ChaffForm : public System::Windows::Forms::Form
	{
	private:
		Chaff^ m_Chaff;
		String^ m_ChaffName;
	public:
		ChaffForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		ChaffForm(Chaff^ chaffData, String^ chaffName)
		{
			InitializeComponent();

			this->Text = String::Concat("Countermeasure: ", chaffName);

			m_Chaff = gcnew CompLib::Chaff;
			m_Chaff->Merge(chaffData);

			m_ChaffName = chaffName;

			LoadData();
			UpdateGUI();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChaffForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::TextBox^  ChaffFormDrainTextBox;
	protected: 


	private: System::Windows::Forms::TextBox^  ChaffFormMassTextBox;

	private: System::Windows::Forms::TextBox^  ChaffFormArmorTextBox;

	private: System::Windows::Forms::Label^  CountermeasureFormLabel;
	private: System::Windows::Forms::Label^  CM_DrainLabel;
	private: System::Windows::Forms::Label^  CM_MassLabel;
	private: System::Windows::Forms::Label^  CM_ArmorLabel;

	public:
		property Chaff^ ChaffList
		{
			Chaff^ get() { return m_Chaff; }
			void set (Chaff^ value) { m_Chaff = value; }
		}
		property String^ ChaffName
		{
			String^ get() { return m_ChaffName; }
			void set (String^ value) { m_ChaffName = value; }
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChaffForm::typeid));
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->ChaffFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ChaffFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ChaffFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CountermeasureFormLabel = (gcnew System::Windows::Forms::Label());
			this->CM_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->CM_MassLabel = (gcnew System::Windows::Forms::Label());
			this->CM_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 228);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 5;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &ChaffForm::CancelButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->SaveButton->ForeColor = System::Drawing::Color::Black;
			this->SaveButton->Location = System::Drawing::Point(68, 228);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 4;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &ChaffForm::SaveButton_Click);
			// 
			// ChaffFormDrainTextBox
			// 
			this->ChaffFormDrainTextBox->Location = System::Drawing::Point(166, 116);
			this->ChaffFormDrainTextBox->MaxLength = 10;
			this->ChaffFormDrainTextBox->Name = L"ChaffFormDrainTextBox";
			this->ChaffFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->ChaffFormDrainTextBox->TabIndex = 2;
			this->ChaffFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ChaffForm::ChaffFormDrainTextBox_KeyPress);
			this->ChaffFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &ChaffForm::CountermeasureFormDrainTextBox_TextChanged);
			// 
			// ChaffFormMassTextBox
			// 
			this->ChaffFormMassTextBox->Location = System::Drawing::Point(166, 156);
			this->ChaffFormMassTextBox->MaxLength = 10;
			this->ChaffFormMassTextBox->Name = L"ChaffFormMassTextBox";
			this->ChaffFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->ChaffFormMassTextBox->TabIndex = 3;
			this->ChaffFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ChaffForm::ChaffFormMassTextBox_KeyPress);
			this->ChaffFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &ChaffForm::CountermeasureFormMassTextBox_TextChanged);
			// 
			// ChaffFormArmorTextBox
			// 
			this->ChaffFormArmorTextBox->Location = System::Drawing::Point(166, 76);
			this->ChaffFormArmorTextBox->MaxLength = 10;
			this->ChaffFormArmorTextBox->Name = L"ChaffFormArmorTextBox";
			this->ChaffFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->ChaffFormArmorTextBox->TabIndex = 1;
			this->ChaffFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ChaffForm::ChaffFormArmorTextBox_KeyPress);
			this->ChaffFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &ChaffForm::CountermeasureFormArmorTextBox_TextChanged);
			// 
			// CountermeasureFormLabel
			// 
			this->CountermeasureFormLabel->AutoSize = true;
			this->CountermeasureFormLabel->BackColor = System::Drawing::Color::Transparent;
			this->CountermeasureFormLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->CountermeasureFormLabel->Location = System::Drawing::Point(54, 15);
			this->CountermeasureFormLabel->Name = L"CountermeasureFormLabel";
			this->CountermeasureFormLabel->Size = System::Drawing::Size(185, 16);
			this->CountermeasureFormLabel->TabIndex = 70;
			this->CountermeasureFormLabel->Text = L"C o u n t e r m e a s u r e s";
			// 
			// CM_DrainLabel
			// 
			this->CM_DrainLabel->AutoSize = true;
			this->CM_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->CM_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CM_DrainLabel->Location = System::Drawing::Point(26, 117);
			this->CM_DrainLabel->Name = L"CM_DrainLabel";
			this->CM_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->CM_DrainLabel->TabIndex = 69;
			this->CM_DrainLabel->Text = L"Drain:";
			// 
			// CM_MassLabel
			// 
			this->CM_MassLabel->AutoSize = true;
			this->CM_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->CM_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CM_MassLabel->Location = System::Drawing::Point(26, 157);
			this->CM_MassLabel->Name = L"CM_MassLabel";
			this->CM_MassLabel->Size = System::Drawing::Size(47, 16);
			this->CM_MassLabel->TabIndex = 68;
			this->CM_MassLabel->Text = L"Mass:";
			// 
			// CM_ArmorLabel
			// 
			this->CM_ArmorLabel->AutoSize = true;
			this->CM_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->CM_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CM_ArmorLabel->Location = System::Drawing::Point(26, 77);
			this->CM_ArmorLabel->Name = L"CM_ArmorLabel";
			this->CM_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->CM_ArmorLabel->TabIndex = 67;
			this->CM_ArmorLabel->Text = L"Armor:";
			// 
			// ChaffForm
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
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->ChaffFormDrainTextBox);
			this->Controls->Add(this->ChaffFormMassTextBox);
			this->Controls->Add(this->ChaffFormArmorTextBox);
			this->Controls->Add(this->CountermeasureFormLabel);
			this->Controls->Add(this->CM_DrainLabel);
			this->Controls->Add(this->CM_MassLabel);
			this->Controls->Add(this->CM_ArmorLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ChaffForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Countermeasures";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void LoadData(){
			 System::Data::DataRow^ rowChaff;

			 if (m_Chaff->Rows->Count != 0)
			 {
				 rowChaff = m_Chaff[0];

				 ChaffFormArmorTextBox->Text = rowChaff["Armor"]->ToString();
				 ChaffFormMassTextBox->Text = rowChaff["Mass"]->ToString();
				 ChaffFormDrainTextBox->Text = rowChaff["Drain"]->ToString();
			 }
		 }

private: System::Void UpdateGUI(){
			 if (ChaffFormArmorTextBox->Text != "" && ChaffFormMassTextBox->Text != "" && 
				 ChaffFormDrainTextBox->Text != "")
			 {
				 SaveButton->Enabled = true;
			 }
			 else
			 {
				 SaveButton->Enabled = false;
			 }
		 }
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (m_Chaff->Rows->Count == 0)
			 {
				 m_Chaff->AddChaff(m_ChaffName, Convert::ToDouble(ChaffFormArmorTextBox->Text->ToString()), 
					 Convert::ToDouble(ChaffFormMassTextBox->Text->ToString()), 
					 Convert::ToDouble(ChaffFormDrainTextBox->Text->ToString()));

				 m_Chaff->TableName = String::Concat("Chaff_", m_ChaffName);

				 this->Close();
			 }
			 else
			 {
				 m_Chaff->RemoveChaff(m_ChaffName);

				 m_Chaff->AddChaff(m_ChaffName, Convert::ToDouble(ChaffFormArmorTextBox->Text->ToString()), 
					 Convert::ToDouble(ChaffFormMassTextBox->Text->ToString()), 
					 Convert::ToDouble(ChaffFormDrainTextBox->Text->ToString()));

				 m_Chaff->TableName = String::Concat("Chaff_", m_ChaffName);

				 this->Close();
			 }
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void CountermeasureFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void CountermeasureFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void CountermeasureFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void ChaffFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void ChaffFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void ChaffFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
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
