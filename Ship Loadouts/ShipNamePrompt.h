#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ShipLoadouts {

	/// <summary>
	/// Summary for ShipNamePrompt
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ShipNamePrompt : public System::Windows::Forms::Form
	{
	public:
		ShipNamePrompt(void)
		{
			InitializeComponent();
			OKButton->Enabled = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ShipNamePrompt()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::String^ m_ShipName;
	private: System::String^ m_ShipMass;

	private: System::Windows::Forms::Button^  OKButton;
	protected: 
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::TextBox^  NameTextBox;
	private: System::Windows::Forms::Label^  EnterNameLabel;
	private: System::Windows::Forms::TextBox^  MassTextBox;
	private: System::Windows::Forms::Label^  EnterMassLabel;
	private: System::Windows::Forms::Panel^  ShipNamePanel;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ShipNamePrompt::typeid));
			this->OKButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EnterNameLabel = (gcnew System::Windows::Forms::Label());
			this->MassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EnterMassLabel = (gcnew System::Windows::Forms::Label());
			this->ShipNamePanel = (gcnew System::Windows::Forms::Panel());
			this->ShipNamePanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// OKButton
			// 
			this->OKButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->OKButton->ForeColor = System::Drawing::Color::Black;
			this->OKButton->Location = System::Drawing::Point(286, 105);
			this->OKButton->Name = L"OKButton";
			this->OKButton->Size = System::Drawing::Size(75, 23);
			this->OKButton->TabIndex = 3;
			this->OKButton->Text = L"OK";
			this->OKButton->UseVisualStyleBackColor = true;
			this->OKButton->Click += gcnew System::EventHandler(this, &ShipNamePrompt::OKButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(367, 105);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 4;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &ShipNamePrompt::CancelButton_Click);
			// 
			// NameTextBox
			// 
			this->NameTextBox->Location = System::Drawing::Point(254, 12);
			this->NameTextBox->MaxLength = 50;
			this->NameTextBox->Name = L"NameTextBox";
			this->NameTextBox->Size = System::Drawing::Size(183, 21);
			this->NameTextBox->TabIndex = 1;
			this->NameTextBox->TextChanged += gcnew System::EventHandler(this, &ShipNamePrompt::NameTextBox_TextChanged);
			// 
			// EnterNameLabel
			// 
			this->EnterNameLabel->AutoSize = true;
			this->EnterNameLabel->BackColor = System::Drawing::Color::Transparent;
			this->EnterNameLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EnterNameLabel->Location = System::Drawing::Point(11, 13);
			this->EnterNameLabel->Name = L"EnterNameLabel";
			this->EnterNameLabel->Size = System::Drawing::Size(195, 16);
			this->EnterNameLabel->TabIndex = 5;
			this->EnterNameLabel->Text = L"Enter the Name of the Ship:";
			// 
			// MassTextBox
			// 
			this->MassTextBox->Location = System::Drawing::Point(254, 39);
			this->MassTextBox->MaxLength = 10;
			this->MassTextBox->Name = L"MassTextBox";
			this->MassTextBox->Size = System::Drawing::Size(183, 21);
			this->MassTextBox->TabIndex = 2;
			this->MassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ShipNamePrompt::MassTextBox_KeyPress);
			this->MassTextBox->TextChanged += gcnew System::EventHandler(this, &ShipNamePrompt::MassTextBox_TextChanged);
			// 
			// EnterMassLabel
			// 
			this->EnterMassLabel->AutoSize = true;
			this->EnterMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->EnterMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EnterMassLabel->Location = System::Drawing::Point(11, 40);
			this->EnterMassLabel->Name = L"EnterMassLabel";
			this->EnterMassLabel->Size = System::Drawing::Size(192, 16);
			this->EnterMassLabel->TabIndex = 9;
			this->EnterMassLabel->Text = L"Enter the Mass of the Ship:";
			// 
			// ShipNamePanel
			// 
			this->ShipNamePanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ShipNamePanel.BackgroundImage")));
			this->ShipNamePanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ShipNamePanel->Controls->Add(this->EnterMassLabel);
			this->ShipNamePanel->Controls->Add(this->MassTextBox);
			this->ShipNamePanel->Controls->Add(this->EnterNameLabel);
			this->ShipNamePanel->Controls->Add(this->NameTextBox);
			this->ShipNamePanel->Location = System::Drawing::Point(4, 14);
			this->ShipNamePanel->Name = L"ShipNamePanel";
			this->ShipNamePanel->Size = System::Drawing::Size(446, 75);
			this->ShipNamePanel->TabIndex = 1;
			// 
			// ShipNamePrompt
			// 
			this->AcceptButton = this->OKButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->CancelButton = this->CancelButton;
			this->ClientSize = System::Drawing::Size(454, 145);
			this->ControlBox = false;
			this->Controls->Add(this->OKButton);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->ShipNamePanel);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ShipNamePrompt";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Input Ship Name and Mass";
			this->ShipNamePanel->ResumeLayout(false);
			this->ShipNamePanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		///
		/// Properties
		///
public: property String^ ShipName
			{
				String^ get() { return m_ShipName; }
				void set (String^ value) { m_ShipName = value; }
			}
public: property String^ ShipMass
			{
				String^ get() { return m_ShipMass; }
				void set (String^ value) { m_ShipMass = value; }
			}
		///
		/// Functions
		///
private: System::Void UpdateGUI(){
			 if (NameTextBox->Text != "" && MassTextBox->Text != "")
			 {
				 OKButton->Enabled = true;
			 }
		 }
		///
		/// Event Handlers
		///
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 m_ShipName = "";
				 m_ShipMass = "";
				 this->Close();
			 }
private: System::Void NameTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			     UpdateGUI();

				 m_ShipName = NameTextBox->Text;
			 }
private: System::Void OKButton_Click(System::Object^  sender, System::EventArgs^  e) {
		    if (NameTextBox->Text != "" && MassTextBox->Text != "")
			{
				this->Close();
			}
		 }
private: System::Void MassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		     UpdateGUI();

			 m_ShipMass = MassTextBox->Text;
		 }
private: System::Void MassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
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
