#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ShipLoadouts {

	/// <summary>
	/// Summary for AboutForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class AboutForm : public System::Windows::Forms::Form
	{
	public:
		AboutForm(void)
		{
			InitializeComponent();

			AboutRichTextBox->SelectionStart = AboutRichTextBox->TextLength;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AboutForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  SigPictureBox;
	protected: 

	private: System::Windows::Forms::RichTextBox^  AboutRichTextBox;
	private: System::Windows::Forms::Label^  About;
	private: System::Windows::Forms::LinkLabel^  EmailAddressLabel;
	private: System::Windows::Forms::Label^  ContactMeLabel;
	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutForm::typeid));
			this->SigPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->AboutRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->About = (gcnew System::Windows::Forms::Label());
			this->EmailAddressLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->ContactMeLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SigPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// SigPictureBox
			// 
			this->SigPictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SigPictureBox->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"SigPictureBox.Image")));
			this->SigPictureBox->Location = System::Drawing::Point(12, 286);
			this->SigPictureBox->Name = L"SigPictureBox";
			this->SigPictureBox->Size = System::Drawing::Size(482, 130);
			this->SigPictureBox->TabIndex = 0;
			this->SigPictureBox->TabStop = false;
			// 
			// AboutRichTextBox
			// 
			this->AboutRichTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->AboutRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->AboutRichTextBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->AboutRichTextBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->AboutRichTextBox->ForeColor = System::Drawing::Color::White;
			this->AboutRichTextBox->Location = System::Drawing::Point(12, 42);
			this->AboutRichTextBox->Name = L"AboutRichTextBox";
			this->AboutRichTextBox->ReadOnly = true;
			this->AboutRichTextBox->Size = System::Drawing::Size(482, 221);
			this->AboutRichTextBox->TabIndex = 1;
			this->AboutRichTextBox->Text = resources->GetString(L"AboutRichTextBox.Text");
			// 
			// About
			// 
			this->About->AutoSize = true;
			this->About->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->About->Location = System::Drawing::Point(7, 9);
			this->About->Name = L"About";
			this->About->Size = System::Drawing::Size(245, 25);
			this->About->TabIndex = 2;
			this->About->Text = L"Ship Loadout Utility";
			// 
			// EmailAddressLabel
			// 
			this->EmailAddressLabel->AutoSize = true;
			this->EmailAddressLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EmailAddressLabel->Location = System::Drawing::Point(91, 266);
			this->EmailAddressLabel->Name = L"EmailAddressLabel";
			this->EmailAddressLabel->Size = System::Drawing::Size(140, 13);
			this->EmailAddressLabel->TabIndex = 2;
			this->EmailAddressLabel->TabStop = true;
			this->EmailAddressLabel->Text = L"Li_Coden@hotmail.com";
			this->EmailAddressLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &AboutForm::EmailAddressLabel_LinkClicked);
			// 
			// ContactMeLabel
			// 
			this->ContactMeLabel->AutoSize = true;
			this->ContactMeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ContactMeLabel->Location = System::Drawing::Point(9, 266);
			this->ContactMeLabel->Name = L"ContactMeLabel";
			this->ContactMeLabel->Size = System::Drawing::Size(76, 13);
			this->ContactMeLabel->TabIndex = 4;
			this->ContactMeLabel->Text = L"Contact Me:";
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->ClientSize = System::Drawing::Size(506, 428);
			this->Controls->Add(this->ContactMeLabel);
			this->Controls->Add(this->EmailAddressLabel);
			this->Controls->Add(this->About);
			this->Controls->Add(this->AboutRichTextBox);
			this->Controls->Add(this->SigPictureBox);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AboutForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"About";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SigPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void EmailAddressLabel_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {	
			 System::Diagnostics::Process::Start("mailto:Li_Coden@hotmail.com");
		 }
};
}
