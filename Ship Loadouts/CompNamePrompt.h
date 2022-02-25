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
	/// Summary for CompNamePrompt
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class CompNamePrompt : public System::Windows::Forms::Form
	{
	public:
		CompNamePrompt(void)
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
		~CompNamePrompt()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::String^ m_CompName;

	private: System::Windows::Forms::Label^  EnterNameLabel;
	protected: 
	private: System::Windows::Forms::TextBox^  NameTextBox;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  OKButton;
	private: System::Windows::Forms::Panel^  CompNamePanel;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CompNamePrompt::typeid));
			this->EnterNameLabel = (gcnew System::Windows::Forms::Label());
			this->NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->OKButton = (gcnew System::Windows::Forms::Button());
			this->CompNamePanel = (gcnew System::Windows::Forms::Panel());
			this->CompNamePanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// EnterNameLabel
			// 
			this->EnterNameLabel->AutoSize = true;
			this->EnterNameLabel->BackColor = System::Drawing::Color::Transparent;
			this->EnterNameLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EnterNameLabel->Location = System::Drawing::Point(6, 18);
			this->EnterNameLabel->Name = L"EnterNameLabel";
			this->EnterNameLabel->Size = System::Drawing::Size(241, 16);
			this->EnterNameLabel->TabIndex = 0;
			this->EnterNameLabel->Text = L"Enter the Name of the Component:";
			// 
			// NameTextBox
			// 
			this->NameTextBox->Location = System::Drawing::Point(250, 17);
			this->NameTextBox->MaxLength = 50;
			this->NameTextBox->Name = L"NameTextBox";
			this->NameTextBox->Size = System::Drawing::Size(183, 20);
			this->NameTextBox->TabIndex = 1;
			this->NameTextBox->TextChanged += gcnew System::EventHandler(this, &CompNamePrompt::NameTextBox_TextChanged);
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->ForeColor = System::Drawing::Color::Black;
			this->CancelButton->Location = System::Drawing::Point(367, 87);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 3;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &CompNamePrompt::CancelButton_Click);
			// 
			// OKButton
			// 
			this->OKButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->OKButton->ForeColor = System::Drawing::Color::Black;
			this->OKButton->Location = System::Drawing::Point(286, 87);
			this->OKButton->Name = L"OKButton";
			this->OKButton->Size = System::Drawing::Size(75, 23);
			this->OKButton->TabIndex = 4;
			this->OKButton->Text = L"OK";
			this->OKButton->UseVisualStyleBackColor = true;
			this->OKButton->Click += gcnew System::EventHandler(this, &CompNamePrompt::OKButton_Click);
			// 
			// CompNamePanel
			// 
			this->CompNamePanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"CompNamePanel.BackgroundImage")));
			this->CompNamePanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CompNamePanel->Controls->Add(this->EnterNameLabel);
			this->CompNamePanel->Controls->Add(this->NameTextBox);
			this->CompNamePanel->Location = System::Drawing::Point(7, 18);
			this->CompNamePanel->Name = L"CompNamePanel";
			this->CompNamePanel->Size = System::Drawing::Size(441, 55);
			this->CompNamePanel->TabIndex = 1;
			// 
			// CompNamePrompt
			// 
			this->AcceptButton = this->OKButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->CancelButton = this->CancelButton;
			this->ClientSize = System::Drawing::Size(454, 122);
			this->ControlBox = false;
			this->Controls->Add(this->OKButton);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->CompNamePanel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"CompNamePrompt";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Input Component Name";
			this->CompNamePanel->ResumeLayout(false);
			this->CompNamePanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

public: property String^ CompName
			{
				String^ get() { return m_CompName; }
				void set (String^ value) { m_CompName = value; }
			}
private: System::Void OKButton_Click(System::Object^  sender, System::EventArgs^  e) {
				if (NameTextBox->Text != ""){
					this->Close();
				}
		 }

private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 m_CompName = "";
				 this->Close();
		 }

private: System::Void NameTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (NameTextBox->Text == "")
				 {
					 OKButton->Enabled = false;
				 }
				 else
				 {
					 OKButton->Enabled = true;
				 }

				 m_CompName = NameTextBox->Text;
		 }
};
}
