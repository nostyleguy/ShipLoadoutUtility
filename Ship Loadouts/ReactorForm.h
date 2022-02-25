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
	/// Summary for ReactorForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ReactorForm : public System::Windows::Forms::Form
	{
	private:
		Reactor^ m_Reactor;
		String^ m_ReactorName;
	public:
		ReactorForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		ReactorForm(Reactor^ reactorData, String^ reactorName)
		{
			InitializeComponent();

			this->Text = String::Concat("Reactor: ", reactorName);

			m_Reactor = gcnew CompLib::Reactor;
			m_Reactor->Merge(reactorData);

			m_ReactorName = reactorName;

			LoadData();
			UpdateGUI();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ReactorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  R_GenerationLabel;
	protected: 
	private: System::Windows::Forms::Label^  R_MassLabel;
	protected: 
	private: System::Windows::Forms::Label^  R_ArmorLabel;
	private: System::Windows::Forms::Label^  ReactorFormLabel;
	private: System::Windows::Forms::TextBox^  ReactorFormArmorTextBox;
	private: System::Windows::Forms::TextBox^  ReactorFormMassTextBox;
	private: System::Windows::Forms::TextBox^  ReactorFormGenerationTextBox;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::Button^  CancelButton;

	public:
		property Reactor^ ReactorList
		{
			Reactor^ get() { return m_Reactor; }
			void set (Reactor^ value) { m_Reactor = value; }
		}
		property String^ ReactorName
		{
			String^ get() { return m_ReactorName; }
			void set (String^ value) { m_ReactorName = value; }
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ReactorForm::typeid));
			this->R_GenerationLabel = (gcnew System::Windows::Forms::Label());
			this->R_MassLabel = (gcnew System::Windows::Forms::Label());
			this->R_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorFormLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ReactorFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ReactorFormGenerationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// R_GenerationLabel
			// 
			this->R_GenerationLabel->AutoSize = true;
			this->R_GenerationLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_GenerationLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_GenerationLabel->Location = System::Drawing::Point(26, 144);
			this->R_GenerationLabel->Name = L"R_GenerationLabel";
			this->R_GenerationLabel->Size = System::Drawing::Size(85, 16);
			this->R_GenerationLabel->TabIndex = 60;
			this->R_GenerationLabel->Text = L"Generation:";
			// 
			// R_MassLabel
			// 
			this->R_MassLabel->AutoSize = true;
			this->R_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_MassLabel->Location = System::Drawing::Point(26, 109);
			this->R_MassLabel->Name = L"R_MassLabel";
			this->R_MassLabel->Size = System::Drawing::Size(47, 16);
			this->R_MassLabel->TabIndex = 59;
			this->R_MassLabel->Text = L"Mass:";
			// 
			// R_ArmorLabel
			// 
			this->R_ArmorLabel->AutoSize = true;
			this->R_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_ArmorLabel->Location = System::Drawing::Point(26, 75);
			this->R_ArmorLabel->Name = L"R_ArmorLabel";
			this->R_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->R_ArmorLabel->TabIndex = 58;
			this->R_ArmorLabel->Text = L"Armor:";
			// 
			// ReactorFormLabel
			// 
			this->ReactorFormLabel->AutoSize = true;
			this->ReactorFormLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReactorFormLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorFormLabel->Location = System::Drawing::Point(103, 9);
			this->ReactorFormLabel->Name = L"ReactorFormLabel";
			this->ReactorFormLabel->Size = System::Drawing::Size(87, 16);
			this->ReactorFormLabel->TabIndex = 61;
			this->ReactorFormLabel->Text = L"R e a c t o r";
			// 
			// ReactorFormArmorTextBox
			// 
			this->ReactorFormArmorTextBox->Location = System::Drawing::Point(166, 71);
			this->ReactorFormArmorTextBox->MaxLength = 10;
			this->ReactorFormArmorTextBox->Name = L"ReactorFormArmorTextBox";
			this->ReactorFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->ReactorFormArmorTextBox->TabIndex = 1;
			this->ReactorFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ReactorForm::ReactorFormArmorTextBox_KeyPress);
			this->ReactorFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &ReactorForm::ReactorFormArmorTextBox_TextChanged);
			// 
			// ReactorFormMassTextBox
			// 
			this->ReactorFormMassTextBox->Location = System::Drawing::Point(166, 108);
			this->ReactorFormMassTextBox->MaxLength = 10;
			this->ReactorFormMassTextBox->Name = L"ReactorFormMassTextBox";
			this->ReactorFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->ReactorFormMassTextBox->TabIndex = 2;
			this->ReactorFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ReactorForm::ReactorFormMassTextBox_KeyPress);
			this->ReactorFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &ReactorForm::ReactorFormMassTextBox_TextChanged);
			// 
			// ReactorFormGenerationTextBox
			// 
			this->ReactorFormGenerationTextBox->Location = System::Drawing::Point(166, 143);
			this->ReactorFormGenerationTextBox->MaxLength = 10;
			this->ReactorFormGenerationTextBox->Name = L"ReactorFormGenerationTextBox";
			this->ReactorFormGenerationTextBox->Size = System::Drawing::Size(100, 20);
			this->ReactorFormGenerationTextBox->TabIndex = 3;
			this->ReactorFormGenerationTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ReactorForm::ReactorFormGenerationTextBox_KeyPress);
			this->ReactorFormGenerationTextBox->TextChanged += gcnew System::EventHandler(this, &ReactorForm::ReactorFormGenerationTextBox_TextChanged);
			// 
			// SaveButton
			// 
			this->SaveButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->SaveButton->ForeColor = System::Drawing::Color::Black;
			this->SaveButton->Location = System::Drawing::Point(68, 222);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 4;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &ReactorForm::SaveButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(149, 222);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 5;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &ReactorForm::CancelButton_Click);
			// 
			// ReactorForm
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
			this->Controls->Add(this->ReactorFormGenerationTextBox);
			this->Controls->Add(this->ReactorFormMassTextBox);
			this->Controls->Add(this->ReactorFormArmorTextBox);
			this->Controls->Add(this->ReactorFormLabel);
			this->Controls->Add(this->R_GenerationLabel);
			this->Controls->Add(this->R_MassLabel);
			this->Controls->Add(this->R_ArmorLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ReactorForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Reactor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void LoadData(){
			 System::Data::DataRow^ rowReactor;

			 if (m_Reactor->Rows->Count != 0)
			 {
				 rowReactor = m_Reactor[0];

				 ReactorFormArmorTextBox->Text = rowReactor["Armor"]->ToString();
				 ReactorFormMassTextBox->Text = rowReactor["Mass"]->ToString();
				 ReactorFormGenerationTextBox->Text = rowReactor["Generation"]->ToString();
			 }
		 }

private: System::Void UpdateGUI(){
			 if (ReactorFormArmorTextBox->Text != "" && ReactorFormMassTextBox->Text != "" && 
				 ReactorFormGenerationTextBox->Text != "")
			 {
				 SaveButton->Enabled = true;
			 }
			 else
			 {
				 SaveButton->Enabled = false;
			 }
		 }
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (m_Reactor->Rows->Count == 0)
			 {
				 m_Reactor->AddReactor(m_ReactorName, Convert::ToDouble(ReactorFormArmorTextBox->Text->ToString()), 
					 Convert::ToDouble(ReactorFormMassTextBox->Text->ToString()), 
					 Convert::ToDouble(ReactorFormGenerationTextBox->Text->ToString()));

				 m_Reactor->TableName = String::Concat("Reactor_", m_ReactorName);

				 this->Close();
			 }
			 else
			 {
				 m_Reactor->RemoveReactor(m_ReactorName);

				 m_Reactor->AddReactor(m_ReactorName, Convert::ToDouble(ReactorFormArmorTextBox->Text->ToString()), 
					 Convert::ToDouble(ReactorFormMassTextBox->Text->ToString()), 
					 Convert::ToDouble(ReactorFormGenerationTextBox->Text->ToString()));

				 m_Reactor->TableName = String::Concat("Reactor_", m_ReactorName);

				 this->Close();
			 }
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void ReactorFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void ReactorFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void ReactorFormGenerationTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateGUI();
		 }
private: System::Void ReactorFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void ReactorFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void ReactorFormGenerationTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
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
