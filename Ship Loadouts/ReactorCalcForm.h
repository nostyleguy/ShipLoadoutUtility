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
	/// Summary for ReactorCalcForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ReactorCalcForm : public System::Windows::Forms::Form
	{
	public:
		ReactorCalcForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		ReactorCalcForm(Reactor^ loadedReactor, int selectedReactorOverload, double currentDrainTotal)
		{
			InitializeComponent();

			TotalDrainOverloadedValueLabel->Text = currentDrainTotal.ToString(".##");

			CalculateBaseGenNeeded(currentDrainTotal, selectedReactorOverload);
			CalculateREValues();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ReactorCalcForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  ReactorCalcStatsFormLabel;
	private: System::Windows::Forms::Label^  TotalDrainLabel1;
	private: System::Windows::Forms::Label^  TotalDrainLabel2;
	private: System::Windows::Forms::Label^  BaseGenNeededLabel;
	private: System::Windows::Forms::Label^  PreREGenNeededLabel;
	private: System::Windows::Forms::Label^  Level1ReactorLabel;
	private: System::Windows::Forms::Label^  Level10ReactorLabel;
	private: System::Windows::Forms::Label^  Level6and7ReactorLabel;
	private: System::Windows::Forms::Label^  Level2and3ReactorLabel;
	private: System::Windows::Forms::Label^  Level4and5ReactorLabel;
	private: System::Windows::Forms::Label^  Level8and9ReactorLabel;
	private: System::Windows::Forms::Button^  CloseButton;
	private: System::Windows::Forms::Label^  TotalDrainOverloadedValueLabel;
	private: System::Windows::Forms::Label^  BaseGenerationValueLabel;
	private: System::Windows::Forms::Label^  Level1ReactorValueLabel;
	private: System::Windows::Forms::Label^  Level2and3ReactorValueLabel;
	private: System::Windows::Forms::Label^  Level4and5ReactorValueLabel;
	private: System::Windows::Forms::Label^  Level6and7ReactorValueLabel;
	private: System::Windows::Forms::Label^  Level8and9ReactorValueLabel;
	private: System::Windows::Forms::Label^  Level10ReactorValueLabel;
	private: System::Windows::Forms::Panel^  ReactorCalcPanel;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ReactorCalcForm::typeid));
			this->ReactorCalcStatsFormLabel = (gcnew System::Windows::Forms::Label());
			this->TotalDrainLabel1 = (gcnew System::Windows::Forms::Label());
			this->TotalDrainLabel2 = (gcnew System::Windows::Forms::Label());
			this->BaseGenNeededLabel = (gcnew System::Windows::Forms::Label());
			this->PreREGenNeededLabel = (gcnew System::Windows::Forms::Label());
			this->Level1ReactorLabel = (gcnew System::Windows::Forms::Label());
			this->Level10ReactorLabel = (gcnew System::Windows::Forms::Label());
			this->Level6and7ReactorLabel = (gcnew System::Windows::Forms::Label());
			this->Level2and3ReactorLabel = (gcnew System::Windows::Forms::Label());
			this->Level4and5ReactorLabel = (gcnew System::Windows::Forms::Label());
			this->Level8and9ReactorLabel = (gcnew System::Windows::Forms::Label());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->TotalDrainOverloadedValueLabel = (gcnew System::Windows::Forms::Label());
			this->BaseGenerationValueLabel = (gcnew System::Windows::Forms::Label());
			this->Level1ReactorValueLabel = (gcnew System::Windows::Forms::Label());
			this->Level2and3ReactorValueLabel = (gcnew System::Windows::Forms::Label());
			this->Level4and5ReactorValueLabel = (gcnew System::Windows::Forms::Label());
			this->Level6and7ReactorValueLabel = (gcnew System::Windows::Forms::Label());
			this->Level8and9ReactorValueLabel = (gcnew System::Windows::Forms::Label());
			this->Level10ReactorValueLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorCalcPanel = (gcnew System::Windows::Forms::Panel());
			this->ReactorCalcPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// ReactorCalcStatsFormLabel
			// 
			this->ReactorCalcStatsFormLabel->AutoSize = true;
			this->ReactorCalcStatsFormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorCalcStatsFormLabel->Location = System::Drawing::Point(43, 9);
			this->ReactorCalcStatsFormLabel->Name = L"ReactorCalcStatsFormLabel";
			this->ReactorCalcStatsFormLabel->Size = System::Drawing::Size(206, 16);
			this->ReactorCalcStatsFormLabel->TabIndex = 3;
			this->ReactorCalcStatsFormLabel->Text = L"R e a c t o r  C a l c u l a t o r";
			// 
			// TotalDrainLabel1
			// 
			this->TotalDrainLabel1->AutoSize = true;
			this->TotalDrainLabel1->BackColor = System::Drawing::Color::Transparent;
			this->TotalDrainLabel1->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalDrainLabel1->Location = System::Drawing::Point(3, 3);
			this->TotalDrainLabel1->Name = L"TotalDrainLabel1";
			this->TotalDrainLabel1->Size = System::Drawing::Size(114, 13);
			this->TotalDrainLabel1->TabIndex = 4;
			this->TotalDrainLabel1->Text = L"Total Drain with all";
			// 
			// TotalDrainLabel2
			// 
			this->TotalDrainLabel2->AutoSize = true;
			this->TotalDrainLabel2->BackColor = System::Drawing::Color::Transparent;
			this->TotalDrainLabel2->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalDrainLabel2->Location = System::Drawing::Point(3, 16);
			this->TotalDrainLabel2->Name = L"TotalDrainLabel2";
			this->TotalDrainLabel2->Size = System::Drawing::Size(176, 13);
			this->TotalDrainLabel2->TabIndex = 5;
			this->TotalDrainLabel2->Text = L"Specified Overloads Running:";
			// 
			// BaseGenNeededLabel
			// 
			this->BaseGenNeededLabel->AutoSize = true;
			this->BaseGenNeededLabel->BackColor = System::Drawing::Color::Transparent;
			this->BaseGenNeededLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BaseGenNeededLabel->Location = System::Drawing::Point(3, 42);
			this->BaseGenNeededLabel->Name = L"BaseGenNeededLabel";
			this->BaseGenNeededLabel->Size = System::Drawing::Size(154, 13);
			this->BaseGenNeededLabel->TabIndex = 8;
			this->BaseGenNeededLabel->Text = L"Base Generation Needed:";
			// 
			// PreREGenNeededLabel
			// 
			this->PreREGenNeededLabel->AutoSize = true;
			this->PreREGenNeededLabel->BackColor = System::Drawing::Color::Transparent;
			this->PreREGenNeededLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->PreREGenNeededLabel->Location = System::Drawing::Point(47, 68);
			this->PreREGenNeededLabel->Name = L"PreREGenNeededLabel";
			this->PreREGenNeededLabel->Size = System::Drawing::Size(180, 13);
			this->PreREGenNeededLabel->TabIndex = 10;
			this->PreREGenNeededLabel->Text = L"Pre-RE Generation Needed";
			// 
			// Level1ReactorLabel
			// 
			this->Level1ReactorLabel->AutoSize = true;
			this->Level1ReactorLabel->BackColor = System::Drawing::Color::Transparent;
			this->Level1ReactorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Level1ReactorLabel->Location = System::Drawing::Point(3, 93);
			this->Level1ReactorLabel->Name = L"Level1ReactorLabel";
			this->Level1ReactorLabel->Size = System::Drawing::Size(101, 13);
			this->Level1ReactorLabel->TabIndex = 11;
			this->Level1ReactorLabel->Text = L"Level 1 Reactor:";
			// 
			// Level10ReactorLabel
			// 
			this->Level10ReactorLabel->AutoSize = true;
			this->Level10ReactorLabel->BackColor = System::Drawing::Color::Transparent;
			this->Level10ReactorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Level10ReactorLabel->Location = System::Drawing::Point(3, 223);
			this->Level10ReactorLabel->Name = L"Level10ReactorLabel";
			this->Level10ReactorLabel->Size = System::Drawing::Size(108, 13);
			this->Level10ReactorLabel->TabIndex = 12;
			this->Level10ReactorLabel->Text = L"Level 10 Reactor:";
			// 
			// Level6and7ReactorLabel
			// 
			this->Level6and7ReactorLabel->AutoSize = true;
			this->Level6and7ReactorLabel->BackColor = System::Drawing::Color::Transparent;
			this->Level6and7ReactorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Level6and7ReactorLabel->Location = System::Drawing::Point(3, 171);
			this->Level6and7ReactorLabel->Name = L"Level6and7ReactorLabel";
			this->Level6and7ReactorLabel->Size = System::Drawing::Size(128, 13);
			this->Level6and7ReactorLabel->TabIndex = 13;
			this->Level6and7ReactorLabel->Text = L"Level 6 or 7 Reactor:";
			// 
			// Level2and3ReactorLabel
			// 
			this->Level2and3ReactorLabel->AutoSize = true;
			this->Level2and3ReactorLabel->BackColor = System::Drawing::Color::Transparent;
			this->Level2and3ReactorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Level2and3ReactorLabel->Location = System::Drawing::Point(3, 119);
			this->Level2and3ReactorLabel->Name = L"Level2and3ReactorLabel";
			this->Level2and3ReactorLabel->Size = System::Drawing::Size(128, 13);
			this->Level2and3ReactorLabel->TabIndex = 14;
			this->Level2and3ReactorLabel->Text = L"Level 2 or 3 Reactor:";
			// 
			// Level4and5ReactorLabel
			// 
			this->Level4and5ReactorLabel->AutoSize = true;
			this->Level4and5ReactorLabel->BackColor = System::Drawing::Color::Transparent;
			this->Level4and5ReactorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Level4and5ReactorLabel->Location = System::Drawing::Point(3, 145);
			this->Level4and5ReactorLabel->Name = L"Level4and5ReactorLabel";
			this->Level4and5ReactorLabel->Size = System::Drawing::Size(128, 13);
			this->Level4and5ReactorLabel->TabIndex = 15;
			this->Level4and5ReactorLabel->Text = L"Level 4 or 5 Reactor:";
			// 
			// Level8and9ReactorLabel
			// 
			this->Level8and9ReactorLabel->AutoSize = true;
			this->Level8and9ReactorLabel->BackColor = System::Drawing::Color::Transparent;
			this->Level8and9ReactorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Level8and9ReactorLabel->Location = System::Drawing::Point(3, 197);
			this->Level8and9ReactorLabel->Name = L"Level8and9ReactorLabel";
			this->Level8and9ReactorLabel->Size = System::Drawing::Size(128, 13);
			this->Level8and9ReactorLabel->TabIndex = 16;
			this->Level8and9ReactorLabel->Text = L"Level 8 or 9 Reactor:";
			// 
			// CloseButton
			// 
			this->CloseButton->ForeColor = System::Drawing::Color::Black;
			this->CloseButton->Location = System::Drawing::Point(109, 299);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 23;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &ReactorCalcForm::CloseButton_Click);
			// 
			// TotalDrainOverloadedValueLabel
			// 
			this->TotalDrainOverloadedValueLabel->AutoSize = true;
			this->TotalDrainOverloadedValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->TotalDrainOverloadedValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->TotalDrainOverloadedValueLabel->Location = System::Drawing::Point(201, 16);
			this->TotalDrainOverloadedValueLabel->Name = L"TotalDrainOverloadedValueLabel";
			this->TotalDrainOverloadedValueLabel->Size = System::Drawing::Size(70, 13);
			this->TotalDrainOverloadedValueLabel->TabIndex = 24;
			this->TotalDrainOverloadedValueLabel->Text = L"No Reactor";
			// 
			// BaseGenerationValueLabel
			// 
			this->BaseGenerationValueLabel->AutoSize = true;
			this->BaseGenerationValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->BaseGenerationValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BaseGenerationValueLabel->Location = System::Drawing::Point(201, 42);
			this->BaseGenerationValueLabel->Name = L"BaseGenerationValueLabel";
			this->BaseGenerationValueLabel->Size = System::Drawing::Size(70, 13);
			this->BaseGenerationValueLabel->TabIndex = 25;
			this->BaseGenerationValueLabel->Text = L"No Reactor";
			// 
			// Level1ReactorValueLabel
			// 
			this->Level1ReactorValueLabel->AutoSize = true;
			this->Level1ReactorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->Level1ReactorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Level1ReactorValueLabel->Location = System::Drawing::Point(201, 93);
			this->Level1ReactorValueLabel->Name = L"Level1ReactorValueLabel";
			this->Level1ReactorValueLabel->Size = System::Drawing::Size(70, 13);
			this->Level1ReactorValueLabel->TabIndex = 26;
			this->Level1ReactorValueLabel->Text = L"No Reactor";
			// 
			// Level2and3ReactorValueLabel
			// 
			this->Level2and3ReactorValueLabel->AutoSize = true;
			this->Level2and3ReactorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->Level2and3ReactorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Level2and3ReactorValueLabel->Location = System::Drawing::Point(201, 119);
			this->Level2and3ReactorValueLabel->Name = L"Level2and3ReactorValueLabel";
			this->Level2and3ReactorValueLabel->Size = System::Drawing::Size(70, 13);
			this->Level2and3ReactorValueLabel->TabIndex = 27;
			this->Level2and3ReactorValueLabel->Text = L"No Reactor";
			// 
			// Level4and5ReactorValueLabel
			// 
			this->Level4and5ReactorValueLabel->AutoSize = true;
			this->Level4and5ReactorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->Level4and5ReactorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Level4and5ReactorValueLabel->Location = System::Drawing::Point(201, 145);
			this->Level4and5ReactorValueLabel->Name = L"Level4and5ReactorValueLabel";
			this->Level4and5ReactorValueLabel->Size = System::Drawing::Size(70, 13);
			this->Level4and5ReactorValueLabel->TabIndex = 28;
			this->Level4and5ReactorValueLabel->Text = L"No Reactor";
			// 
			// Level6and7ReactorValueLabel
			// 
			this->Level6and7ReactorValueLabel->AutoSize = true;
			this->Level6and7ReactorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->Level6and7ReactorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Level6and7ReactorValueLabel->Location = System::Drawing::Point(201, 171);
			this->Level6and7ReactorValueLabel->Name = L"Level6and7ReactorValueLabel";
			this->Level6and7ReactorValueLabel->Size = System::Drawing::Size(70, 13);
			this->Level6and7ReactorValueLabel->TabIndex = 29;
			this->Level6and7ReactorValueLabel->Text = L"No Reactor";
			// 
			// Level8and9ReactorValueLabel
			// 
			this->Level8and9ReactorValueLabel->AutoSize = true;
			this->Level8and9ReactorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->Level8and9ReactorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Level8and9ReactorValueLabel->Location = System::Drawing::Point(201, 197);
			this->Level8and9ReactorValueLabel->Name = L"Level8and9ReactorValueLabel";
			this->Level8and9ReactorValueLabel->Size = System::Drawing::Size(70, 13);
			this->Level8and9ReactorValueLabel->TabIndex = 30;
			this->Level8and9ReactorValueLabel->Text = L"No Reactor";
			// 
			// Level10ReactorValueLabel
			// 
			this->Level10ReactorValueLabel->AutoSize = true;
			this->Level10ReactorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->Level10ReactorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Level10ReactorValueLabel->Location = System::Drawing::Point(201, 223);
			this->Level10ReactorValueLabel->Name = L"Level10ReactorValueLabel";
			this->Level10ReactorValueLabel->Size = System::Drawing::Size(70, 13);
			this->Level10ReactorValueLabel->TabIndex = 31;
			this->Level10ReactorValueLabel->Text = L"No Reactor";
			// 
			// ReactorCalcPanel
			// 
			this->ReactorCalcPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ReactorCalcPanel.BackgroundImage")));
			this->ReactorCalcPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ReactorCalcPanel->Controls->Add(this->Level10ReactorValueLabel);
			this->ReactorCalcPanel->Controls->Add(this->PreREGenNeededLabel);
			this->ReactorCalcPanel->Controls->Add(this->Level8and9ReactorValueLabel);
			this->ReactorCalcPanel->Controls->Add(this->TotalDrainLabel1);
			this->ReactorCalcPanel->Controls->Add(this->Level6and7ReactorValueLabel);
			this->ReactorCalcPanel->Controls->Add(this->TotalDrainLabel2);
			this->ReactorCalcPanel->Controls->Add(this->Level4and5ReactorValueLabel);
			this->ReactorCalcPanel->Controls->Add(this->BaseGenNeededLabel);
			this->ReactorCalcPanel->Controls->Add(this->Level2and3ReactorValueLabel);
			this->ReactorCalcPanel->Controls->Add(this->Level1ReactorLabel);
			this->ReactorCalcPanel->Controls->Add(this->Level1ReactorValueLabel);
			this->ReactorCalcPanel->Controls->Add(this->Level10ReactorLabel);
			this->ReactorCalcPanel->Controls->Add(this->BaseGenerationValueLabel);
			this->ReactorCalcPanel->Controls->Add(this->Level6and7ReactorLabel);
			this->ReactorCalcPanel->Controls->Add(this->TotalDrainOverloadedValueLabel);
			this->ReactorCalcPanel->Controls->Add(this->Level2and3ReactorLabel);
			this->ReactorCalcPanel->Controls->Add(this->Level4and5ReactorLabel);
			this->ReactorCalcPanel->Controls->Add(this->Level8and9ReactorLabel);
			this->ReactorCalcPanel->Location = System::Drawing::Point(9, 36);
			this->ReactorCalcPanel->Name = L"ReactorCalcPanel";
			this->ReactorCalcPanel->Size = System::Drawing::Size(275, 243);
			this->ReactorCalcPanel->TabIndex = 32;
			// 
			// ReactorCalcForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->ClientSize = System::Drawing::Size(292, 336);
			this->Controls->Add(this->ReactorCalcPanel);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->ReactorCalcStatsFormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ReactorCalcForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Reactor Calculator";
			this->ReactorCalcPanel->ResumeLayout(false);
			this->ReactorCalcPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void CalculateBaseGenNeeded(double currentDrainTotal, int selectedReactorOverload){
			switch (selectedReactorOverload)
			{
			case 0: BaseGenerationValueLabel->Text = (currentDrainTotal / 1).ToString(".##");
				break;
			case 1: BaseGenerationValueLabel->Text = (currentDrainTotal / 1.1).ToString(".##");
				break;
			case 2: BaseGenerationValueLabel->Text = (currentDrainTotal / 1.3).ToString(".##");
				break;
			case 3: BaseGenerationValueLabel->Text = (currentDrainTotal / 1.6).ToString(".##");
				break;
			case 4: BaseGenerationValueLabel->Text = (currentDrainTotal / 1.9).ToString(".##");
				break;
			}
		 }
private: System::Void CalculateREValues(){
			 Level1ReactorValueLabel->Text = (Convert::ToDouble(BaseGenerationValueLabel->Text->ToString()) * 0.98).ToString(".##");
			 Level2and3ReactorValueLabel->Text = (Convert::ToDouble(BaseGenerationValueLabel->Text->ToString()) * 0.97).ToString(".##");
			 Level4and5ReactorValueLabel->Text = (Convert::ToDouble(BaseGenerationValueLabel->Text->ToString()) * 0.96).ToString(".##");
			 Level6and7ReactorValueLabel->Text = (Convert::ToDouble(BaseGenerationValueLabel->Text->ToString()) * 0.95).ToString(".##");
			 Level8and9ReactorValueLabel->Text = (Convert::ToDouble(BaseGenerationValueLabel->Text->ToString()) * 0.94).ToString(".##");
			 Level10ReactorValueLabel->Text = (Convert::ToDouble(BaseGenerationValueLabel->Text->ToString()) * 0.93).ToString(".##");
		 }
private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
};
}
