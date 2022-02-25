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
	/// Summary for EngineForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class EngineForm : public System::Windows::Forms::Form
	{
	private:
		Engine^ m_Engine;
		String^ m_EngineName;
	public:
		EngineForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		EngineForm(Engine^ engineData, String^ engineName)
		{
			InitializeComponent();

			this->Text = String::Concat("Engine: ", engineName);

			m_Engine = gcnew CompLib::Engine;
			m_Engine->Merge(engineData);

			m_EngineName = engineName;

			LoadData();
			UpdateGUI();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EngineForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  EngineFormLabel;
	private: System::Windows::Forms::Label^  E_SpeedLabel;
	private: System::Windows::Forms::Label^  E_RollLabel;
	private: System::Windows::Forms::Label^  E_YawLabel;
	private: System::Windows::Forms::Label^  E_PitchLabel;
	private: System::Windows::Forms::Label^  E_DrainLabel;
	private: System::Windows::Forms::Label^  E_MassLabel;
	private: System::Windows::Forms::Label^  E_ArmorLabel;
	private: System::Windows::Forms::TextBox^  EngineFormArmorTextBox;
	private: System::Windows::Forms::TextBox^  EngineFormMassTextBox;
	private: System::Windows::Forms::TextBox^  EngineFormPitchTextBox;
	private: System::Windows::Forms::TextBox^  EngineFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  EngineFormRollTextBox;
	private: System::Windows::Forms::TextBox^  EngineFormYawTextBox;
	private: System::Windows::Forms::TextBox^  EngineFormSpeedTextBox;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  SaveButton;


	public:
		property Engine^ EngineList
		{
			Engine^ get() { return m_Engine; }
			void set (Engine^ value) { m_Engine = value; }
		}
		property String^ EngineName
		{
			String^ get() { return m_EngineName; }
			void set (String^ value) { m_EngineName = value; }
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(EngineForm::typeid));
			this->EngineFormLabel = (gcnew System::Windows::Forms::Label());
			this->E_SpeedLabel = (gcnew System::Windows::Forms::Label());
			this->E_RollLabel = (gcnew System::Windows::Forms::Label());
			this->E_YawLabel = (gcnew System::Windows::Forms::Label());
			this->E_PitchLabel = (gcnew System::Windows::Forms::Label());
			this->E_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->E_MassLabel = (gcnew System::Windows::Forms::Label());
			this->E_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->EngineFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EngineFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EngineFormPitchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EngineFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EngineFormRollTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EngineFormYawTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EngineFormSpeedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// EngineFormLabel
			// 
			this->EngineFormLabel->AutoSize = true;
			this->EngineFormLabel->BackColor = System::Drawing::Color::Transparent;
			this->EngineFormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineFormLabel->Location = System::Drawing::Point(108, 9);
			this->EngineFormLabel->Name = L"EngineFormLabel";
			this->EngineFormLabel->Size = System::Drawing::Size(77, 16);
			this->EngineFormLabel->TabIndex = 62;
			this->EngineFormLabel->Text = L"E n g i n e";
			// 
			// E_SpeedLabel
			// 
			this->E_SpeedLabel->AutoSize = true;
			this->E_SpeedLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_SpeedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_SpeedLabel->Location = System::Drawing::Point(46, 201);
			this->E_SpeedLabel->Name = L"E_SpeedLabel";
			this->E_SpeedLabel->Size = System::Drawing::Size(55, 16);
			this->E_SpeedLabel->TabIndex = 75;
			this->E_SpeedLabel->Text = L"Speed:";
			// 
			// E_RollLabel
			// 
			this->E_RollLabel->AutoSize = true;
			this->E_RollLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_RollLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_RollLabel->Location = System::Drawing::Point(46, 175);
			this->E_RollLabel->Name = L"E_RollLabel";
			this->E_RollLabel->Size = System::Drawing::Size(36, 16);
			this->E_RollLabel->TabIndex = 74;
			this->E_RollLabel->Text = L"Roll:";
			// 
			// E_YawLabel
			// 
			this->E_YawLabel->AutoSize = true;
			this->E_YawLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_YawLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_YawLabel->Location = System::Drawing::Point(46, 149);
			this->E_YawLabel->Name = L"E_YawLabel";
			this->E_YawLabel->Size = System::Drawing::Size(42, 16);
			this->E_YawLabel->TabIndex = 73;
			this->E_YawLabel->Text = L"Yaw:";
			// 
			// E_PitchLabel
			// 
			this->E_PitchLabel->AutoSize = true;
			this->E_PitchLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_PitchLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_PitchLabel->Location = System::Drawing::Point(46, 123);
			this->E_PitchLabel->Name = L"E_PitchLabel";
			this->E_PitchLabel->Size = System::Drawing::Size(47, 16);
			this->E_PitchLabel->TabIndex = 72;
			this->E_PitchLabel->Text = L"Pitch:";
			// 
			// E_DrainLabel
			// 
			this->E_DrainLabel->AutoSize = true;
			this->E_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_DrainLabel->Location = System::Drawing::Point(46, 71);
			this->E_DrainLabel->Name = L"E_DrainLabel";
			this->E_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->E_DrainLabel->TabIndex = 71;
			this->E_DrainLabel->Text = L"Drain:";
			// 
			// E_MassLabel
			// 
			this->E_MassLabel->AutoSize = true;
			this->E_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_MassLabel->Location = System::Drawing::Point(46, 97);
			this->E_MassLabel->Name = L"E_MassLabel";
			this->E_MassLabel->Size = System::Drawing::Size(47, 16);
			this->E_MassLabel->TabIndex = 70;
			this->E_MassLabel->Text = L"Mass:";
			// 
			// E_ArmorLabel
			// 
			this->E_ArmorLabel->AutoSize = true;
			this->E_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_ArmorLabel->Location = System::Drawing::Point(46, 45);
			this->E_ArmorLabel->Name = L"E_ArmorLabel";
			this->E_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->E_ArmorLabel->TabIndex = 69;
			this->E_ArmorLabel->Text = L"Armor:";
			// 
			// EngineFormArmorTextBox
			// 
			this->EngineFormArmorTextBox->Location = System::Drawing::Point(147, 44);
			this->EngineFormArmorTextBox->MaxLength = 10;
			this->EngineFormArmorTextBox->Name = L"EngineFormArmorTextBox";
			this->EngineFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormArmorTextBox->TabIndex = 1;
			this->EngineFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EngineForm::EngineFormArmorTextBox_KeyPress);
			this->EngineFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &EngineForm::EngineFormArmorTextBox_TextChanged);
			// 
			// EngineFormMassTextBox
			// 
			this->EngineFormMassTextBox->Location = System::Drawing::Point(147, 96);
			this->EngineFormMassTextBox->MaxLength = 10;
			this->EngineFormMassTextBox->Name = L"EngineFormMassTextBox";
			this->EngineFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormMassTextBox->TabIndex = 3;
			this->EngineFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EngineForm::EngineFormMassTextBox_KeyPress);
			this->EngineFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &EngineForm::EngineFormMassTextBox_TextChanged);
			// 
			// EngineFormPitchTextBox
			// 
			this->EngineFormPitchTextBox->Location = System::Drawing::Point(147, 122);
			this->EngineFormPitchTextBox->MaxLength = 10;
			this->EngineFormPitchTextBox->Name = L"EngineFormPitchTextBox";
			this->EngineFormPitchTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormPitchTextBox->TabIndex = 4;
			this->EngineFormPitchTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EngineForm::EngineFormPitchTextBox_KeyPress);
			this->EngineFormPitchTextBox->TextChanged += gcnew System::EventHandler(this, &EngineForm::EngineFormPitchTextBox_TextChanged);
			// 
			// EngineFormDrainTextBox
			// 
			this->EngineFormDrainTextBox->Location = System::Drawing::Point(147, 70);
			this->EngineFormDrainTextBox->MaxLength = 10;
			this->EngineFormDrainTextBox->Name = L"EngineFormDrainTextBox";
			this->EngineFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormDrainTextBox->TabIndex = 2;
			this->EngineFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EngineForm::EngineFormDrainTextBox_KeyPress);
			this->EngineFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &EngineForm::EngineFormDrainTextBox_TextChanged);
			// 
			// EngineFormRollTextBox
			// 
			this->EngineFormRollTextBox->Location = System::Drawing::Point(147, 174);
			this->EngineFormRollTextBox->MaxLength = 10;
			this->EngineFormRollTextBox->Name = L"EngineFormRollTextBox";
			this->EngineFormRollTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormRollTextBox->TabIndex = 6;
			this->EngineFormRollTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EngineForm::EngineFormRollTextBox_KeyPress);
			this->EngineFormRollTextBox->TextChanged += gcnew System::EventHandler(this, &EngineForm::EngineFormRollTextBox_TextChanged);
			// 
			// EngineFormYawTextBox
			// 
			this->EngineFormYawTextBox->Location = System::Drawing::Point(147, 148);
			this->EngineFormYawTextBox->MaxLength = 10;
			this->EngineFormYawTextBox->Name = L"EngineFormYawTextBox";
			this->EngineFormYawTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormYawTextBox->TabIndex = 5;
			this->EngineFormYawTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EngineForm::EngineFormYawTextBox_KeyPress);
			this->EngineFormYawTextBox->TextChanged += gcnew System::EventHandler(this, &EngineForm::EngineFormYawTextBox_TextChanged);
			// 
			// EngineFormSpeedTextBox
			// 
			this->EngineFormSpeedTextBox->Location = System::Drawing::Point(147, 200);
			this->EngineFormSpeedTextBox->MaxLength = 10;
			this->EngineFormSpeedTextBox->Name = L"EngineFormSpeedTextBox";
			this->EngineFormSpeedTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormSpeedTextBox->TabIndex = 7;
			this->EngineFormSpeedTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EngineForm::EngineFormSpeedTextBox_KeyPress);
			this->EngineFormSpeedTextBox->TextChanged += gcnew System::EventHandler(this, &EngineForm::EngineFormSpeedTextBox_TextChanged);
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 241);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 9;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &EngineForm::CancelButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->SaveButton->ForeColor = System::Drawing::Color::Black;
			this->SaveButton->Location = System::Drawing::Point(68, 241);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 8;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &EngineForm::SaveButton_Click);
			// 
			// EngineForm
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(292, 276);
			this->ControlBox = false;
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->EngineFormSpeedTextBox);
			this->Controls->Add(this->EngineFormRollTextBox);
			this->Controls->Add(this->EngineFormYawTextBox);
			this->Controls->Add(this->EngineFormPitchTextBox);
			this->Controls->Add(this->EngineFormDrainTextBox);
			this->Controls->Add(this->EngineFormMassTextBox);
			this->Controls->Add(this->EngineFormArmorTextBox);
			this->Controls->Add(this->E_SpeedLabel);
			this->Controls->Add(this->E_RollLabel);
			this->Controls->Add(this->E_YawLabel);
			this->Controls->Add(this->E_PitchLabel);
			this->Controls->Add(this->E_DrainLabel);
			this->Controls->Add(this->E_MassLabel);
			this->Controls->Add(this->E_ArmorLabel);
			this->Controls->Add(this->EngineFormLabel);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"EngineForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Engine";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void LoadData(){
			 System::Data::DataRow^ rowEngine;

			 if (m_Engine->Rows->Count != 0)
			 {
				 rowEngine = m_Engine[0];

				 EngineFormArmorTextBox->Text = rowEngine["Armor"]->ToString();
				 EngineFormMassTextBox->Text = rowEngine["Mass"]->ToString();
				 EngineFormDrainTextBox->Text = rowEngine["Drain"]->ToString();
				 EngineFormPitchTextBox->Text = rowEngine["Pitch"]->ToString();
				 EngineFormYawTextBox->Text = rowEngine["Yaw"]->ToString();
				 EngineFormRollTextBox->Text = rowEngine["Roll"]->ToString();
				 EngineFormSpeedTextBox->Text = rowEngine["Top Speed"]->ToString();
			 }
		 }

private: System::Void UpdateGUI(){
			 if (EngineFormArmorTextBox->Text != "" && EngineFormMassTextBox->Text != "" && 
				 EngineFormDrainTextBox->Text != "" && EngineFormPitchTextBox->Text != "" &&
				 EngineFormYawTextBox->Text != "" && EngineFormRollTextBox->Text != "" &&
				 EngineFormSpeedTextBox->Text != "")
			 {
				 SaveButton->Enabled = true;
			 }
			 else
			 {
				 SaveButton->Enabled = false;
			 }
		 }
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (m_Engine->Rows->Count == 0)
			 {
				 m_Engine->AddEngine(m_EngineName, Convert::ToDouble(EngineFormArmorTextBox->Text->ToString()), 
					 Convert::ToDouble(EngineFormMassTextBox->Text->ToString()), 
					 Convert::ToDouble(EngineFormDrainTextBox->Text->ToString()),
					 Convert::ToDouble(EngineFormPitchTextBox->Text->ToString()),
					 Convert::ToDouble(EngineFormYawTextBox->Text->ToString()),
					 Convert::ToDouble(EngineFormRollTextBox->Text->ToString()),
					 Convert::ToDouble(EngineFormSpeedTextBox->Text->ToString()));

				 m_Engine->TableName = String::Concat("Engine_", m_EngineName);

				 this->Close();
			 }
			 else
			 {
				 m_Engine->RemoveEngine(m_EngineName);

				 m_Engine->AddEngine(m_EngineName, Convert::ToDouble(EngineFormArmorTextBox->Text->ToString()), 
					 Convert::ToDouble(EngineFormMassTextBox->Text->ToString()), 
					 Convert::ToDouble(EngineFormDrainTextBox->Text->ToString()),
					 Convert::ToDouble(EngineFormPitchTextBox->Text->ToString()),
					 Convert::ToDouble(EngineFormYawTextBox->Text->ToString()),
					 Convert::ToDouble(EngineFormRollTextBox->Text->ToString()),
					 Convert::ToDouble(EngineFormSpeedTextBox->Text->ToString()));

				 m_Engine->TableName = String::Concat("Engine_", m_EngineName);

				 this->Close();
			 }
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void EngineFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void EngineFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void EngineFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void EngineFormPitchTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void EngineFormYawTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void EngineFormRollTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void EngineFormSpeedTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void EngineFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void EngineFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void EngineFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void EngineFormPitchTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void EngineFormYawTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void EngineFormRollTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void EngineFormSpeedTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
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
