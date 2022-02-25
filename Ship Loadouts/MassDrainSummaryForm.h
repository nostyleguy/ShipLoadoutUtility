#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ShipLoadouts {

	/// <summary>
	/// Summary for MassDrainSummaryForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class MassDrainSummaryForm : public System::Windows::Forms::Form
	{
	public:
		MassDrainSummaryForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		MassDrainSummaryForm(double currentReactorMass, double currentEngineMass, double currentBoosterMass, double currentSheildMass, double currentFArmorMass, 
			double currentRArmorMass, double currentDroidMass, double currentCapacitorMass, double currentOrdinance1Mass, double currentOrdinance2Mass, 
			double currentOrdinance3Mass, double currentWeapon1Mass, double currentWeapon2Mass, double currentWeapon3Mass, double currentWeapon4Mass, 
			double currentChaffMass, double currentReactorGeneration, double currentReactorOverloadedGeneration, double currentEngineDrain, double currentEngineOverloadedDrain,
			double currentBoosterDrain, double currentSheildDrain,
			double currentDroidDrain, double currentCapacitorDrain, double currentOrdinance1Drain, double currentOrdinance1OverloadedDrain, double currentOrdinance2Drain, 
			double currentOrdinance2OverloadedDrain, double currentOrdinance3Drain, double currentOrdinance3OverloadedDrain, double currentWeapon1Drain, 
			double currentWeapon1OverloadedDrain, double currentWeapon2Drain, double currentWeapon2OverloadedDrain, double currentWeapon3Drain, 
			double currentWeapon3OverloadedDrain, double currentWeapon4Drain, double currentWeapon4OverloadedDrain, double currentChaffDrain)
		{
			InitializeComponent();

			CalculateMasses(currentReactorMass, currentEngineMass, currentBoosterMass, currentSheildMass, currentFArmorMass, 
				currentRArmorMass, currentDroidMass, currentCapacitorMass, currentOrdinance1Mass, currentOrdinance2Mass, 
				currentOrdinance3Mass, currentWeapon1Mass, currentWeapon2Mass, currentWeapon3Mass, currentWeapon4Mass, 
				currentChaffMass);

			CalculateDrains(currentEngineDrain, currentEngineOverloadedDrain, 
				 currentBoosterDrain, currentSheildDrain, currentDroidDrain, currentCapacitorDrain, 
				 currentOrdinance1Drain, currentOrdinance1OverloadedDrain, currentOrdinance2Drain, currentOrdinance2OverloadedDrain, 
				 currentOrdinance3Drain, currentOrdinance3OverloadedDrain, currentWeapon1Drain, currentWeapon1OverloadedDrain, 
				 currentWeapon2Drain, currentWeapon2OverloadedDrain, currentWeapon3Drain, currentWeapon3OverloadedDrain, 
				 currentWeapon4Drain, currentWeapon4OverloadedDrain, currentChaffDrain);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MassDrainSummaryForm()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region MassDrainSummaryForm Item Declerations

	private: System::Windows::Forms::Label^  MassDrainStatsFormLabel;
	private: System::Windows::Forms::Label^  DriodLabel;
	private: System::Windows::Forms::Label^  BoosterLabel;
	private: System::Windows::Forms::Label^  CapacitorStatusLabel;
	private: System::Windows::Forms::Label^  RArmorLabel;
	private: System::Windows::Forms::Label^  FArmorLabel;
	private: System::Windows::Forms::Label^  SheildLabel;
	private: System::Windows::Forms::Label^  EngineLabel;
	private: System::Windows::Forms::Label^  ReactorLabel;
	private: System::Windows::Forms::Label^  CountermeasuresLabel;
	private: System::Windows::Forms::Label^  Ordinance3Label;
	private: System::Windows::Forms::Label^  Ordinance2Label;
	private: System::Windows::Forms::Label^  Ordinance1Label;
	private: System::Windows::Forms::Label^  Weapon4Label;
	private: System::Windows::Forms::Label^  Weapon3Label;
	private: System::Windows::Forms::Label^  Weapon2Label;
	private: System::Windows::Forms::Label^  Weapon1Label;
	private: System::Windows::Forms::Button^  CloseButton;
	private: System::Windows::Forms::Label^  MassLabel;
	private: System::Windows::Forms::Label^  DrainLabel;
	private: System::Windows::Forms::Label^  DrainOverloadedLabel1;
	private: System::Windows::Forms::Label^  DrainOverloadedLabel2;
	private: System::Windows::Forms::Label^  DroidMassLabel;
	private: System::Windows::Forms::Label^  BoosterMassLabel;
	private: System::Windows::Forms::Label^  CapacitorMassLabel;
	private: System::Windows::Forms::Label^  RArmorMassLabel;
	private: System::Windows::Forms::Label^  FArmorMassLabel;
	private: System::Windows::Forms::Label^  SheildMassLabel;
	private: System::Windows::Forms::Label^  EngineMassLabel;
	private: System::Windows::Forms::Label^  ReactorMassLabel;
	private: System::Windows::Forms::Label^  CountermeasuresMassLabel;
	private: System::Windows::Forms::Label^  Ordinance3MassLabel;
	private: System::Windows::Forms::Label^  Ordinance2MassLabel;
	private: System::Windows::Forms::Label^  Ordinance1MassLabel;

	private: System::Windows::Forms::Label^  Weapon4MassLabel;
	private: System::Windows::Forms::Label^  Weapon3MassLabel;
	private: System::Windows::Forms::Label^  Weapon2MassLabel;
	private: System::Windows::Forms::Label^  Weapon1MassLabel;
	private: System::Windows::Forms::Label^  TotalsLabel;
	private: System::Windows::Forms::Label^  TotalMassLabel;
	private: System::Windows::Forms::Label^  DroidDrainLabel;
	private: System::Windows::Forms::Label^  BoosterDrainLabel;
	private: System::Windows::Forms::Label^  CapacitorDrainLabel;
	private: System::Windows::Forms::Label^  RArmorDrainLabel;
	private: System::Windows::Forms::Label^  FArmorDrainLabel;
	private: System::Windows::Forms::Label^  SheildDrainLabel;
	private: System::Windows::Forms::Label^  EngineDrainLabel;
	private: System::Windows::Forms::Label^  ReactorDrainLabel;
	private: System::Windows::Forms::Label^  CountermeasuresDrainLabel;
	private: System::Windows::Forms::Label^  Ordinance3DrainLabel;
	private: System::Windows::Forms::Label^  Ordinance2DrainLabel;
	private: System::Windows::Forms::Label^  Ordinance1DrainLabel;

	private: System::Windows::Forms::Label^  Weapon4DrainLabel;
	private: System::Windows::Forms::Label^  Weapon3DrainLabel;
	private: System::Windows::Forms::Label^  Weapon2DrainLabel;
	private: System::Windows::Forms::Label^  Weapon1DrainLabel;
	private: System::Windows::Forms::Label^  TotalDrainLabel;
	private: System::Windows::Forms::Label^  DroidODrainLabel;
	private: System::Windows::Forms::Label^  BoosterODrainLabel;
	private: System::Windows::Forms::Label^  CapacitorODrainLabel;
	private: System::Windows::Forms::Label^  RArmorODrainLabel;
	private: System::Windows::Forms::Label^  FArmorODrainLabel;
	private: System::Windows::Forms::Label^  SheildODrainLabel;
	private: System::Windows::Forms::Label^  EngineODrainLabel;
	private: System::Windows::Forms::Label^  ReactorODrainLabel;
	private: System::Windows::Forms::Label^  CountermeasuresODrainLabel;
	private: System::Windows::Forms::Label^  Ordinance3ODrainLabel;
	private: System::Windows::Forms::Label^  Ordinance2ODrainLabel;
private: System::Windows::Forms::Label^  Ordinance1ODrainLabel;

	private: System::Windows::Forms::Label^  Weapon4ODrainLabel;
	private: System::Windows::Forms::Label^  Weapon3ODrainLabel;
	private: System::Windows::Forms::Label^  Weapon2ODrainLabel;
	private: System::Windows::Forms::Label^  Weapon1ODrainLabel;
	private: System::Windows::Forms::Label^  ODrainTotalLabel;
private: System::Windows::Forms::Panel^  MassDrainPanel;

#pragma endregion

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MassDrainSummaryForm::typeid));
			this->MassDrainStatsFormLabel = (gcnew System::Windows::Forms::Label());
			this->DriodLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorStatusLabel = (gcnew System::Windows::Forms::Label());
			this->RArmorLabel = (gcnew System::Windows::Forms::Label());
			this->FArmorLabel = (gcnew System::Windows::Forms::Label());
			this->SheildLabel = (gcnew System::Windows::Forms::Label());
			this->EngineLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorLabel = (gcnew System::Windows::Forms::Label());
			this->CountermeasuresLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance3Label = (gcnew System::Windows::Forms::Label());
			this->Ordinance2Label = (gcnew System::Windows::Forms::Label());
			this->Ordinance1Label = (gcnew System::Windows::Forms::Label());
			this->Weapon4Label = (gcnew System::Windows::Forms::Label());
			this->Weapon3Label = (gcnew System::Windows::Forms::Label());
			this->Weapon2Label = (gcnew System::Windows::Forms::Label());
			this->Weapon1Label = (gcnew System::Windows::Forms::Label());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->MassLabel = (gcnew System::Windows::Forms::Label());
			this->DrainLabel = (gcnew System::Windows::Forms::Label());
			this->DrainOverloadedLabel1 = (gcnew System::Windows::Forms::Label());
			this->DrainOverloadedLabel2 = (gcnew System::Windows::Forms::Label());
			this->DroidMassLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterMassLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorMassLabel = (gcnew System::Windows::Forms::Label());
			this->RArmorMassLabel = (gcnew System::Windows::Forms::Label());
			this->FArmorMassLabel = (gcnew System::Windows::Forms::Label());
			this->SheildMassLabel = (gcnew System::Windows::Forms::Label());
			this->EngineMassLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorMassLabel = (gcnew System::Windows::Forms::Label());
			this->CountermeasuresMassLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance3MassLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance2MassLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance1MassLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon4MassLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon3MassLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon2MassLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon1MassLabel = (gcnew System::Windows::Forms::Label());
			this->TotalsLabel = (gcnew System::Windows::Forms::Label());
			this->TotalMassLabel = (gcnew System::Windows::Forms::Label());
			this->DroidDrainLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterDrainLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorDrainLabel = (gcnew System::Windows::Forms::Label());
			this->RArmorDrainLabel = (gcnew System::Windows::Forms::Label());
			this->FArmorDrainLabel = (gcnew System::Windows::Forms::Label());
			this->SheildDrainLabel = (gcnew System::Windows::Forms::Label());
			this->EngineDrainLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorDrainLabel = (gcnew System::Windows::Forms::Label());
			this->CountermeasuresDrainLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance3DrainLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance2DrainLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance1DrainLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon4DrainLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon3DrainLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon2DrainLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon1DrainLabel = (gcnew System::Windows::Forms::Label());
			this->TotalDrainLabel = (gcnew System::Windows::Forms::Label());
			this->DroidODrainLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterODrainLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorODrainLabel = (gcnew System::Windows::Forms::Label());
			this->RArmorODrainLabel = (gcnew System::Windows::Forms::Label());
			this->FArmorODrainLabel = (gcnew System::Windows::Forms::Label());
			this->SheildODrainLabel = (gcnew System::Windows::Forms::Label());
			this->EngineODrainLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorODrainLabel = (gcnew System::Windows::Forms::Label());
			this->CountermeasuresODrainLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance3ODrainLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance2ODrainLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance1ODrainLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon4ODrainLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon3ODrainLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon2ODrainLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon1ODrainLabel = (gcnew System::Windows::Forms::Label());
			this->ODrainTotalLabel = (gcnew System::Windows::Forms::Label());
			this->MassDrainPanel = (gcnew System::Windows::Forms::Panel());
			this->MassDrainPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// MassDrainStatsFormLabel
			// 
			this->MassDrainStatsFormLabel->AutoSize = true;
			this->MassDrainStatsFormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->MassDrainStatsFormLabel->Location = System::Drawing::Point(90, 9);
			this->MassDrainStatsFormLabel->Name = L"MassDrainStatsFormLabel";
			this->MassDrainStatsFormLabel->Size = System::Drawing::Size(230, 16);
			this->MassDrainStatsFormLabel->TabIndex = 3;
			this->MassDrainStatsFormLabel->Text = L"M a s s / D r a i n  S u m m a r y";
			// 
			// DriodLabel
			// 
			this->DriodLabel->AutoSize = true;
			this->DriodLabel->BackColor = System::Drawing::Color::Transparent;
			this->DriodLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DriodLabel->Location = System::Drawing::Point(4, 124);
			this->DriodLabel->Name = L"DriodLabel";
			this->DriodLabel->Size = System::Drawing::Size(99, 13);
			this->DriodLabel->TabIndex = 36;
			this->DriodLabel->Text = L"Droid Interface:";
			// 
			// BoosterLabel
			// 
			this->BoosterLabel->AutoSize = true;
			this->BoosterLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterLabel->Location = System::Drawing::Point(4, 111);
			this->BoosterLabel->Name = L"BoosterLabel";
			this->BoosterLabel->Size = System::Drawing::Size(56, 13);
			this->BoosterLabel->TabIndex = 35;
			this->BoosterLabel->Text = L"Booster:";
			// 
			// CapacitorStatusLabel
			// 
			this->CapacitorStatusLabel->AutoSize = true;
			this->CapacitorStatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->CapacitorStatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorStatusLabel->Location = System::Drawing::Point(4, 98);
			this->CapacitorStatusLabel->Name = L"CapacitorStatusLabel";
			this->CapacitorStatusLabel->Size = System::Drawing::Size(67, 13);
			this->CapacitorStatusLabel->TabIndex = 34;
			this->CapacitorStatusLabel->Text = L"Capacitor:";
			// 
			// RArmorLabel
			// 
			this->RArmorLabel->AutoSize = true;
			this->RArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->RArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RArmorLabel->Location = System::Drawing::Point(4, 85);
			this->RArmorLabel->Name = L"RArmorLabel";
			this->RArmorLabel->Size = System::Drawing::Size(70, 13);
			this->RArmorLabel->TabIndex = 33;
			this->RArmorLabel->Text = L"Armor (R):";
			// 
			// FArmorLabel
			// 
			this->FArmorLabel->AutoSize = true;
			this->FArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->FArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FArmorLabel->Location = System::Drawing::Point(4, 72);
			this->FArmorLabel->Name = L"FArmorLabel";
			this->FArmorLabel->Size = System::Drawing::Size(68, 13);
			this->FArmorLabel->TabIndex = 32;
			this->FArmorLabel->Text = L"Armor (F):";
			// 
			// SheildLabel
			// 
			this->SheildLabel->AutoSize = true;
			this->SheildLabel->BackColor = System::Drawing::Color::Transparent;
			this->SheildLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildLabel->Location = System::Drawing::Point(4, 59);
			this->SheildLabel->Name = L"SheildLabel";
			this->SheildLabel->Size = System::Drawing::Size(47, 13);
			this->SheildLabel->TabIndex = 31;
			this->SheildLabel->Text = L"Shield:";
			// 
			// EngineLabel
			// 
			this->EngineLabel->AutoSize = true;
			this->EngineLabel->BackColor = System::Drawing::Color::Transparent;
			this->EngineLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineLabel->Location = System::Drawing::Point(4, 46);
			this->EngineLabel->Name = L"EngineLabel";
			this->EngineLabel->Size = System::Drawing::Size(50, 13);
			this->EngineLabel->TabIndex = 30;
			this->EngineLabel->Text = L"Engine:";
			// 
			// ReactorLabel
			// 
			this->ReactorLabel->AutoSize = true;
			this->ReactorLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReactorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorLabel->Location = System::Drawing::Point(4, 33);
			this->ReactorLabel->Name = L"ReactorLabel";
			this->ReactorLabel->Size = System::Drawing::Size(56, 13);
			this->ReactorLabel->TabIndex = 29;
			this->ReactorLabel->Text = L"Reactor:";
			// 
			// CountermeasuresLabel
			// 
			this->CountermeasuresLabel->AutoSize = true;
			this->CountermeasuresLabel->BackColor = System::Drawing::Color::Transparent;
			this->CountermeasuresLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CountermeasuresLabel->Location = System::Drawing::Point(5, 228);
			this->CountermeasuresLabel->Name = L"CountermeasuresLabel";
			this->CountermeasuresLabel->Size = System::Drawing::Size(114, 13);
			this->CountermeasuresLabel->TabIndex = 44;
			this->CountermeasuresLabel->Text = L"Countermeasures:";
			// 
			// Ordinance3Label
			// 
			this->Ordinance3Label->AutoSize = true;
			this->Ordinance3Label->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance3Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance3Label->Location = System::Drawing::Point(5, 215);
			this->Ordinance3Label->Name = L"Ordinance3Label";
			this->Ordinance3Label->Size = System::Drawing::Size(81, 13);
			this->Ordinance3Label->TabIndex = 43;
			this->Ordinance3Label->Text = L"Ordinance 3:";
			// 
			// Ordinance2Label
			// 
			this->Ordinance2Label->AutoSize = true;
			this->Ordinance2Label->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance2Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance2Label->Location = System::Drawing::Point(5, 202);
			this->Ordinance2Label->Name = L"Ordinance2Label";
			this->Ordinance2Label->Size = System::Drawing::Size(81, 13);
			this->Ordinance2Label->TabIndex = 42;
			this->Ordinance2Label->Text = L"Ordinance 2:";
			// 
			// Ordinance1Label
			// 
			this->Ordinance1Label->AutoSize = true;
			this->Ordinance1Label->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance1Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance1Label->Location = System::Drawing::Point(5, 189);
			this->Ordinance1Label->Name = L"Ordinance1Label";
			this->Ordinance1Label->Size = System::Drawing::Size(81, 13);
			this->Ordinance1Label->TabIndex = 41;
			this->Ordinance1Label->Text = L"Ordinance 1:";
			// 
			// Weapon4Label
			// 
			this->Weapon4Label->AutoSize = true;
			this->Weapon4Label->BackColor = System::Drawing::Color::Transparent;
			this->Weapon4Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon4Label->Location = System::Drawing::Point(5, 176);
			this->Weapon4Label->Name = L"Weapon4Label";
			this->Weapon4Label->Size = System::Drawing::Size(69, 13);
			this->Weapon4Label->TabIndex = 40;
			this->Weapon4Label->Text = L"Weapon 4:";
			// 
			// Weapon3Label
			// 
			this->Weapon3Label->AutoSize = true;
			this->Weapon3Label->BackColor = System::Drawing::Color::Transparent;
			this->Weapon3Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon3Label->Location = System::Drawing::Point(5, 163);
			this->Weapon3Label->Name = L"Weapon3Label";
			this->Weapon3Label->Size = System::Drawing::Size(69, 13);
			this->Weapon3Label->TabIndex = 39;
			this->Weapon3Label->Text = L"Weapon 3:";
			// 
			// Weapon2Label
			// 
			this->Weapon2Label->AutoSize = true;
			this->Weapon2Label->BackColor = System::Drawing::Color::Transparent;
			this->Weapon2Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon2Label->Location = System::Drawing::Point(5, 150);
			this->Weapon2Label->Name = L"Weapon2Label";
			this->Weapon2Label->Size = System::Drawing::Size(69, 13);
			this->Weapon2Label->TabIndex = 38;
			this->Weapon2Label->Text = L"Weapon 2:";
			// 
			// Weapon1Label
			// 
			this->Weapon1Label->AutoSize = true;
			this->Weapon1Label->BackColor = System::Drawing::Color::Transparent;
			this->Weapon1Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon1Label->Location = System::Drawing::Point(5, 137);
			this->Weapon1Label->Name = L"Weapon1Label";
			this->Weapon1Label->Size = System::Drawing::Size(69, 13);
			this->Weapon1Label->TabIndex = 37;
			this->Weapon1Label->Text = L"Weapon 1:";
			// 
			// CloseButton
			// 
			this->CloseButton->ForeColor = System::Drawing::Color::Black;
			this->CloseButton->Location = System::Drawing::Point(168, 327);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 45;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &MassDrainSummaryForm::CloseButton_Click);
			// 
			// MassLabel
			// 
			this->MassLabel->AutoSize = true;
			this->MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->MassLabel->Location = System::Drawing::Point(156, 18);
			this->MassLabel->Name = L"MassLabel";
			this->MassLabel->Size = System::Drawing::Size(39, 13);
			this->MassLabel->TabIndex = 46;
			this->MassLabel->Text = L"Mass";
			// 
			// DrainLabel
			// 
			this->DrainLabel->AutoSize = true;
			this->DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DrainLabel->Location = System::Drawing::Point(241, 18);
			this->DrainLabel->Name = L"DrainLabel";
			this->DrainLabel->Size = System::Drawing::Size(42, 13);
			this->DrainLabel->TabIndex = 47;
			this->DrainLabel->Text = L"Drain";
			// 
			// DrainOverloadedLabel1
			// 
			this->DrainOverloadedLabel1->AutoSize = true;
			this->DrainOverloadedLabel1->BackColor = System::Drawing::Color::Transparent;
			this->DrainOverloadedLabel1->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DrainOverloadedLabel1->Location = System::Drawing::Point(330, 5);
			this->DrainOverloadedLabel1->Name = L"DrainOverloadedLabel1";
			this->DrainOverloadedLabel1->Size = System::Drawing::Size(42, 13);
			this->DrainOverloadedLabel1->TabIndex = 48;
			this->DrainOverloadedLabel1->Text = L"Drain";
			// 
			// DrainOverloadedLabel2
			// 
			this->DrainOverloadedLabel2->AutoSize = true;
			this->DrainOverloadedLabel2->BackColor = System::Drawing::Color::Transparent;
			this->DrainOverloadedLabel2->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DrainOverloadedLabel2->Location = System::Drawing::Point(311, 18);
			this->DrainOverloadedLabel2->Name = L"DrainOverloadedLabel2";
			this->DrainOverloadedLabel2->Size = System::Drawing::Size(82, 13);
			this->DrainOverloadedLabel2->TabIndex = 49;
			this->DrainOverloadedLabel2->Text = L"Overloaded";
			// 
			// DroidMassLabel
			// 
			this->DroidMassLabel->AutoSize = true;
			this->DroidMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->DroidMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DroidMassLabel->Location = System::Drawing::Point(136, 124);
			this->DroidMassLabel->Name = L"DroidMassLabel";
			this->DroidMassLabel->Size = System::Drawing::Size(81, 13);
			this->DroidMassLabel->TabIndex = 57;
			this->DroidMassLabel->Text = L"None Loaded";
			// 
			// BoosterMassLabel
			// 
			this->BoosterMassLabel->AutoSize = true;
			this->BoosterMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterMassLabel->Location = System::Drawing::Point(136, 111);
			this->BoosterMassLabel->Name = L"BoosterMassLabel";
			this->BoosterMassLabel->Size = System::Drawing::Size(81, 13);
			this->BoosterMassLabel->TabIndex = 56;
			this->BoosterMassLabel->Text = L"None Loaded";
			// 
			// CapacitorMassLabel
			// 
			this->CapacitorMassLabel->AutoSize = true;
			this->CapacitorMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->CapacitorMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorMassLabel->Location = System::Drawing::Point(136, 98);
			this->CapacitorMassLabel->Name = L"CapacitorMassLabel";
			this->CapacitorMassLabel->Size = System::Drawing::Size(81, 13);
			this->CapacitorMassLabel->TabIndex = 55;
			this->CapacitorMassLabel->Text = L"None Loaded";
			// 
			// RArmorMassLabel
			// 
			this->RArmorMassLabel->AutoSize = true;
			this->RArmorMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->RArmorMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RArmorMassLabel->Location = System::Drawing::Point(136, 85);
			this->RArmorMassLabel->Name = L"RArmorMassLabel";
			this->RArmorMassLabel->Size = System::Drawing::Size(81, 13);
			this->RArmorMassLabel->TabIndex = 54;
			this->RArmorMassLabel->Text = L"None Loaded";
			// 
			// FArmorMassLabel
			// 
			this->FArmorMassLabel->AutoSize = true;
			this->FArmorMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->FArmorMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FArmorMassLabel->Location = System::Drawing::Point(136, 72);
			this->FArmorMassLabel->Name = L"FArmorMassLabel";
			this->FArmorMassLabel->Size = System::Drawing::Size(81, 13);
			this->FArmorMassLabel->TabIndex = 53;
			this->FArmorMassLabel->Text = L"None Loaded";
			// 
			// SheildMassLabel
			// 
			this->SheildMassLabel->AutoSize = true;
			this->SheildMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->SheildMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildMassLabel->Location = System::Drawing::Point(136, 59);
			this->SheildMassLabel->Name = L"SheildMassLabel";
			this->SheildMassLabel->Size = System::Drawing::Size(81, 13);
			this->SheildMassLabel->TabIndex = 52;
			this->SheildMassLabel->Text = L"None Loaded";
			// 
			// EngineMassLabel
			// 
			this->EngineMassLabel->AutoSize = true;
			this->EngineMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->EngineMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineMassLabel->Location = System::Drawing::Point(136, 46);
			this->EngineMassLabel->Name = L"EngineMassLabel";
			this->EngineMassLabel->Size = System::Drawing::Size(81, 13);
			this->EngineMassLabel->TabIndex = 51;
			this->EngineMassLabel->Text = L"None Loaded";
			// 
			// ReactorMassLabel
			// 
			this->ReactorMassLabel->AutoSize = true;
			this->ReactorMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReactorMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorMassLabel->Location = System::Drawing::Point(136, 33);
			this->ReactorMassLabel->Name = L"ReactorMassLabel";
			this->ReactorMassLabel->Size = System::Drawing::Size(81, 13);
			this->ReactorMassLabel->TabIndex = 50;
			this->ReactorMassLabel->Text = L"None Loaded";
			// 
			// CountermeasuresMassLabel
			// 
			this->CountermeasuresMassLabel->AutoSize = true;
			this->CountermeasuresMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->CountermeasuresMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CountermeasuresMassLabel->Location = System::Drawing::Point(136, 228);
			this->CountermeasuresMassLabel->Name = L"CountermeasuresMassLabel";
			this->CountermeasuresMassLabel->Size = System::Drawing::Size(81, 13);
			this->CountermeasuresMassLabel->TabIndex = 65;
			this->CountermeasuresMassLabel->Text = L"None Loaded";
			// 
			// Ordinance3MassLabel
			// 
			this->Ordinance3MassLabel->AutoSize = true;
			this->Ordinance3MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance3MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance3MassLabel->Location = System::Drawing::Point(136, 215);
			this->Ordinance3MassLabel->Name = L"Ordinance3MassLabel";
			this->Ordinance3MassLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance3MassLabel->TabIndex = 64;
			this->Ordinance3MassLabel->Text = L"None Loaded";
			// 
			// Ordinance2MassLabel
			// 
			this->Ordinance2MassLabel->AutoSize = true;
			this->Ordinance2MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance2MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance2MassLabel->Location = System::Drawing::Point(136, 202);
			this->Ordinance2MassLabel->Name = L"Ordinance2MassLabel";
			this->Ordinance2MassLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance2MassLabel->TabIndex = 63;
			this->Ordinance2MassLabel->Text = L"None Loaded";
			// 
			// Ordinance1MassLabel
			// 
			this->Ordinance1MassLabel->AutoSize = true;
			this->Ordinance1MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance1MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance1MassLabel->Location = System::Drawing::Point(136, 189);
			this->Ordinance1MassLabel->Name = L"Ordinance1MassLabel";
			this->Ordinance1MassLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance1MassLabel->TabIndex = 62;
			this->Ordinance1MassLabel->Text = L"None Loaded";
			// 
			// Weapon4MassLabel
			// 
			this->Weapon4MassLabel->AutoSize = true;
			this->Weapon4MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon4MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon4MassLabel->Location = System::Drawing::Point(136, 176);
			this->Weapon4MassLabel->Name = L"Weapon4MassLabel";
			this->Weapon4MassLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon4MassLabel->TabIndex = 61;
			this->Weapon4MassLabel->Text = L"None Loaded";
			// 
			// Weapon3MassLabel
			// 
			this->Weapon3MassLabel->AutoSize = true;
			this->Weapon3MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon3MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon3MassLabel->Location = System::Drawing::Point(136, 163);
			this->Weapon3MassLabel->Name = L"Weapon3MassLabel";
			this->Weapon3MassLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon3MassLabel->TabIndex = 60;
			this->Weapon3MassLabel->Text = L"None Loaded";
			// 
			// Weapon2MassLabel
			// 
			this->Weapon2MassLabel->AutoSize = true;
			this->Weapon2MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon2MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon2MassLabel->Location = System::Drawing::Point(136, 150);
			this->Weapon2MassLabel->Name = L"Weapon2MassLabel";
			this->Weapon2MassLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon2MassLabel->TabIndex = 59;
			this->Weapon2MassLabel->Text = L"None Loaded";
			// 
			// Weapon1MassLabel
			// 
			this->Weapon1MassLabel->AutoSize = true;
			this->Weapon1MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon1MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon1MassLabel->Location = System::Drawing::Point(136, 137);
			this->Weapon1MassLabel->Name = L"Weapon1MassLabel";
			this->Weapon1MassLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon1MassLabel->TabIndex = 58;
			this->Weapon1MassLabel->Text = L"None Loaded";
			// 
			// TotalsLabel
			// 
			this->TotalsLabel->AutoSize = true;
			this->TotalsLabel->BackColor = System::Drawing::Color::Transparent;
			this->TotalsLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalsLabel->Location = System::Drawing::Point(4, 254);
			this->TotalsLabel->Name = L"TotalsLabel";
			this->TotalsLabel->Size = System::Drawing::Size(51, 13);
			this->TotalsLabel->TabIndex = 67;
			this->TotalsLabel->Text = L"Totals:";
			// 
			// TotalMassLabel
			// 
			this->TotalMassLabel->AutoSize = true;
			this->TotalMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->TotalMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalMassLabel->Location = System::Drawing::Point(136, 254);
			this->TotalMassLabel->Name = L"TotalMassLabel";
			this->TotalMassLabel->Size = System::Drawing::Size(81, 13);
			this->TotalMassLabel->TabIndex = 68;
			this->TotalMassLabel->Text = L"None Loaded";
			// 
			// DroidDrainLabel
			// 
			this->DroidDrainLabel->AutoSize = true;
			this->DroidDrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->DroidDrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DroidDrainLabel->Location = System::Drawing::Point(223, 124);
			this->DroidDrainLabel->Name = L"DroidDrainLabel";
			this->DroidDrainLabel->Size = System::Drawing::Size(81, 13);
			this->DroidDrainLabel->TabIndex = 76;
			this->DroidDrainLabel->Text = L"None Loaded";
			// 
			// BoosterDrainLabel
			// 
			this->BoosterDrainLabel->AutoSize = true;
			this->BoosterDrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterDrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterDrainLabel->Location = System::Drawing::Point(223, 111);
			this->BoosterDrainLabel->Name = L"BoosterDrainLabel";
			this->BoosterDrainLabel->Size = System::Drawing::Size(81, 13);
			this->BoosterDrainLabel->TabIndex = 75;
			this->BoosterDrainLabel->Text = L"None Loaded";
			// 
			// CapacitorDrainLabel
			// 
			this->CapacitorDrainLabel->AutoSize = true;
			this->CapacitorDrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->CapacitorDrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorDrainLabel->Location = System::Drawing::Point(223, 98);
			this->CapacitorDrainLabel->Name = L"CapacitorDrainLabel";
			this->CapacitorDrainLabel->Size = System::Drawing::Size(81, 13);
			this->CapacitorDrainLabel->TabIndex = 74;
			this->CapacitorDrainLabel->Text = L"None Loaded";
			// 
			// RArmorDrainLabel
			// 
			this->RArmorDrainLabel->AutoSize = true;
			this->RArmorDrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->RArmorDrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RArmorDrainLabel->Location = System::Drawing::Point(223, 85);
			this->RArmorDrainLabel->Name = L"RArmorDrainLabel";
			this->RArmorDrainLabel->Size = System::Drawing::Size(28, 13);
			this->RArmorDrainLabel->TabIndex = 73;
			this->RArmorDrainLabel->Text = L"N/A";
			// 
			// FArmorDrainLabel
			// 
			this->FArmorDrainLabel->AutoSize = true;
			this->FArmorDrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->FArmorDrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FArmorDrainLabel->Location = System::Drawing::Point(223, 72);
			this->FArmorDrainLabel->Name = L"FArmorDrainLabel";
			this->FArmorDrainLabel->Size = System::Drawing::Size(28, 13);
			this->FArmorDrainLabel->TabIndex = 72;
			this->FArmorDrainLabel->Text = L"N/A";
			// 
			// SheildDrainLabel
			// 
			this->SheildDrainLabel->AutoSize = true;
			this->SheildDrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->SheildDrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildDrainLabel->Location = System::Drawing::Point(223, 59);
			this->SheildDrainLabel->Name = L"SheildDrainLabel";
			this->SheildDrainLabel->Size = System::Drawing::Size(81, 13);
			this->SheildDrainLabel->TabIndex = 71;
			this->SheildDrainLabel->Text = L"None Loaded";
			// 
			// EngineDrainLabel
			// 
			this->EngineDrainLabel->AutoSize = true;
			this->EngineDrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->EngineDrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineDrainLabel->Location = System::Drawing::Point(223, 46);
			this->EngineDrainLabel->Name = L"EngineDrainLabel";
			this->EngineDrainLabel->Size = System::Drawing::Size(81, 13);
			this->EngineDrainLabel->TabIndex = 70;
			this->EngineDrainLabel->Text = L"None Loaded";
			// 
			// ReactorDrainLabel
			// 
			this->ReactorDrainLabel->AutoSize = true;
			this->ReactorDrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReactorDrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorDrainLabel->Location = System::Drawing::Point(223, 33);
			this->ReactorDrainLabel->Name = L"ReactorDrainLabel";
			this->ReactorDrainLabel->Size = System::Drawing::Size(28, 13);
			this->ReactorDrainLabel->TabIndex = 69;
			this->ReactorDrainLabel->Text = L"N/A";
			// 
			// CountermeasuresDrainLabel
			// 
			this->CountermeasuresDrainLabel->AutoSize = true;
			this->CountermeasuresDrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->CountermeasuresDrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CountermeasuresDrainLabel->Location = System::Drawing::Point(223, 228);
			this->CountermeasuresDrainLabel->Name = L"CountermeasuresDrainLabel";
			this->CountermeasuresDrainLabel->Size = System::Drawing::Size(81, 13);
			this->CountermeasuresDrainLabel->TabIndex = 84;
			this->CountermeasuresDrainLabel->Text = L"None Loaded";
			// 
			// Ordinance3DrainLabel
			// 
			this->Ordinance3DrainLabel->AutoSize = true;
			this->Ordinance3DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance3DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance3DrainLabel->Location = System::Drawing::Point(223, 215);
			this->Ordinance3DrainLabel->Name = L"Ordinance3DrainLabel";
			this->Ordinance3DrainLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance3DrainLabel->TabIndex = 83;
			this->Ordinance3DrainLabel->Text = L"None Loaded";
			// 
			// Ordinance2DrainLabel
			// 
			this->Ordinance2DrainLabel->AutoSize = true;
			this->Ordinance2DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance2DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance2DrainLabel->Location = System::Drawing::Point(223, 202);
			this->Ordinance2DrainLabel->Name = L"Ordinance2DrainLabel";
			this->Ordinance2DrainLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance2DrainLabel->TabIndex = 82;
			this->Ordinance2DrainLabel->Text = L"None Loaded";
			// 
			// Ordinance1DrainLabel
			// 
			this->Ordinance1DrainLabel->AutoSize = true;
			this->Ordinance1DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance1DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance1DrainLabel->Location = System::Drawing::Point(223, 189);
			this->Ordinance1DrainLabel->Name = L"Ordinance1DrainLabel";
			this->Ordinance1DrainLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance1DrainLabel->TabIndex = 81;
			this->Ordinance1DrainLabel->Text = L"None Loaded";
			// 
			// Weapon4DrainLabel
			// 
			this->Weapon4DrainLabel->AutoSize = true;
			this->Weapon4DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon4DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon4DrainLabel->Location = System::Drawing::Point(223, 176);
			this->Weapon4DrainLabel->Name = L"Weapon4DrainLabel";
			this->Weapon4DrainLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon4DrainLabel->TabIndex = 80;
			this->Weapon4DrainLabel->Text = L"None Loaded";
			// 
			// Weapon3DrainLabel
			// 
			this->Weapon3DrainLabel->AutoSize = true;
			this->Weapon3DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon3DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon3DrainLabel->Location = System::Drawing::Point(223, 163);
			this->Weapon3DrainLabel->Name = L"Weapon3DrainLabel";
			this->Weapon3DrainLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon3DrainLabel->TabIndex = 79;
			this->Weapon3DrainLabel->Text = L"None Loaded";
			// 
			// Weapon2DrainLabel
			// 
			this->Weapon2DrainLabel->AutoSize = true;
			this->Weapon2DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon2DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon2DrainLabel->Location = System::Drawing::Point(223, 150);
			this->Weapon2DrainLabel->Name = L"Weapon2DrainLabel";
			this->Weapon2DrainLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon2DrainLabel->TabIndex = 78;
			this->Weapon2DrainLabel->Text = L"None Loaded";
			// 
			// Weapon1DrainLabel
			// 
			this->Weapon1DrainLabel->AutoSize = true;
			this->Weapon1DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon1DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon1DrainLabel->Location = System::Drawing::Point(223, 137);
			this->Weapon1DrainLabel->Name = L"Weapon1DrainLabel";
			this->Weapon1DrainLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon1DrainLabel->TabIndex = 77;
			this->Weapon1DrainLabel->Text = L"None Loaded";
			// 
			// TotalDrainLabel
			// 
			this->TotalDrainLabel->AutoSize = true;
			this->TotalDrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->TotalDrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalDrainLabel->Location = System::Drawing::Point(223, 254);
			this->TotalDrainLabel->Name = L"TotalDrainLabel";
			this->TotalDrainLabel->Size = System::Drawing::Size(81, 13);
			this->TotalDrainLabel->TabIndex = 85;
			this->TotalDrainLabel->Text = L"None Loaded";
			// 
			// DroidODrainLabel
			// 
			this->DroidODrainLabel->AutoSize = true;
			this->DroidODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->DroidODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DroidODrainLabel->Location = System::Drawing::Point(309, 124);
			this->DroidODrainLabel->Name = L"DroidODrainLabel";
			this->DroidODrainLabel->Size = System::Drawing::Size(81, 13);
			this->DroidODrainLabel->TabIndex = 93;
			this->DroidODrainLabel->Text = L"None Loaded";
			// 
			// BoosterODrainLabel
			// 
			this->BoosterODrainLabel->AutoSize = true;
			this->BoosterODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterODrainLabel->Location = System::Drawing::Point(309, 111);
			this->BoosterODrainLabel->Name = L"BoosterODrainLabel";
			this->BoosterODrainLabel->Size = System::Drawing::Size(81, 13);
			this->BoosterODrainLabel->TabIndex = 92;
			this->BoosterODrainLabel->Text = L"None Loaded";
			// 
			// CapacitorODrainLabel
			// 
			this->CapacitorODrainLabel->AutoSize = true;
			this->CapacitorODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->CapacitorODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorODrainLabel->Location = System::Drawing::Point(309, 98);
			this->CapacitorODrainLabel->Name = L"CapacitorODrainLabel";
			this->CapacitorODrainLabel->Size = System::Drawing::Size(81, 13);
			this->CapacitorODrainLabel->TabIndex = 91;
			this->CapacitorODrainLabel->Text = L"None Loaded";
			// 
			// RArmorODrainLabel
			// 
			this->RArmorODrainLabel->AutoSize = true;
			this->RArmorODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->RArmorODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RArmorODrainLabel->Location = System::Drawing::Point(309, 85);
			this->RArmorODrainLabel->Name = L"RArmorODrainLabel";
			this->RArmorODrainLabel->Size = System::Drawing::Size(28, 13);
			this->RArmorODrainLabel->TabIndex = 90;
			this->RArmorODrainLabel->Text = L"N/A";
			// 
			// FArmorODrainLabel
			// 
			this->FArmorODrainLabel->AutoSize = true;
			this->FArmorODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->FArmorODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FArmorODrainLabel->Location = System::Drawing::Point(309, 72);
			this->FArmorODrainLabel->Name = L"FArmorODrainLabel";
			this->FArmorODrainLabel->Size = System::Drawing::Size(28, 13);
			this->FArmorODrainLabel->TabIndex = 89;
			this->FArmorODrainLabel->Text = L"N/A";
			// 
			// SheildODrainLabel
			// 
			this->SheildODrainLabel->AutoSize = true;
			this->SheildODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->SheildODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildODrainLabel->Location = System::Drawing::Point(309, 59);
			this->SheildODrainLabel->Name = L"SheildODrainLabel";
			this->SheildODrainLabel->Size = System::Drawing::Size(81, 13);
			this->SheildODrainLabel->TabIndex = 88;
			this->SheildODrainLabel->Text = L"None Loaded";
			// 
			// EngineODrainLabel
			// 
			this->EngineODrainLabel->AutoSize = true;
			this->EngineODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->EngineODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineODrainLabel->Location = System::Drawing::Point(309, 46);
			this->EngineODrainLabel->Name = L"EngineODrainLabel";
			this->EngineODrainLabel->Size = System::Drawing::Size(81, 13);
			this->EngineODrainLabel->TabIndex = 87;
			this->EngineODrainLabel->Text = L"None Loaded";
			// 
			// ReactorODrainLabel
			// 
			this->ReactorODrainLabel->AutoSize = true;
			this->ReactorODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReactorODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorODrainLabel->Location = System::Drawing::Point(309, 33);
			this->ReactorODrainLabel->Name = L"ReactorODrainLabel";
			this->ReactorODrainLabel->Size = System::Drawing::Size(28, 13);
			this->ReactorODrainLabel->TabIndex = 86;
			this->ReactorODrainLabel->Text = L"N/A";
			// 
			// CountermeasuresODrainLabel
			// 
			this->CountermeasuresODrainLabel->AutoSize = true;
			this->CountermeasuresODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->CountermeasuresODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CountermeasuresODrainLabel->Location = System::Drawing::Point(309, 228);
			this->CountermeasuresODrainLabel->Name = L"CountermeasuresODrainLabel";
			this->CountermeasuresODrainLabel->Size = System::Drawing::Size(81, 13);
			this->CountermeasuresODrainLabel->TabIndex = 101;
			this->CountermeasuresODrainLabel->Text = L"None Loaded";
			// 
			// Ordinance3ODrainLabel
			// 
			this->Ordinance3ODrainLabel->AutoSize = true;
			this->Ordinance3ODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance3ODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance3ODrainLabel->Location = System::Drawing::Point(309, 215);
			this->Ordinance3ODrainLabel->Name = L"Ordinance3ODrainLabel";
			this->Ordinance3ODrainLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance3ODrainLabel->TabIndex = 100;
			this->Ordinance3ODrainLabel->Text = L"None Loaded";
			// 
			// Ordinance2ODrainLabel
			// 
			this->Ordinance2ODrainLabel->AutoSize = true;
			this->Ordinance2ODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance2ODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance2ODrainLabel->Location = System::Drawing::Point(309, 202);
			this->Ordinance2ODrainLabel->Name = L"Ordinance2ODrainLabel";
			this->Ordinance2ODrainLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance2ODrainLabel->TabIndex = 99;
			this->Ordinance2ODrainLabel->Text = L"None Loaded";
			// 
			// Ordinance1ODrainLabel
			// 
			this->Ordinance1ODrainLabel->AutoSize = true;
			this->Ordinance1ODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance1ODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance1ODrainLabel->Location = System::Drawing::Point(309, 189);
			this->Ordinance1ODrainLabel->Name = L"Ordinance1ODrainLabel";
			this->Ordinance1ODrainLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance1ODrainLabel->TabIndex = 98;
			this->Ordinance1ODrainLabel->Text = L"None Loaded";
			// 
			// Weapon4ODrainLabel
			// 
			this->Weapon4ODrainLabel->AutoSize = true;
			this->Weapon4ODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon4ODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon4ODrainLabel->Location = System::Drawing::Point(309, 176);
			this->Weapon4ODrainLabel->Name = L"Weapon4ODrainLabel";
			this->Weapon4ODrainLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon4ODrainLabel->TabIndex = 97;
			this->Weapon4ODrainLabel->Text = L"None Loaded";
			// 
			// Weapon3ODrainLabel
			// 
			this->Weapon3ODrainLabel->AutoSize = true;
			this->Weapon3ODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon3ODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon3ODrainLabel->Location = System::Drawing::Point(309, 163);
			this->Weapon3ODrainLabel->Name = L"Weapon3ODrainLabel";
			this->Weapon3ODrainLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon3ODrainLabel->TabIndex = 96;
			this->Weapon3ODrainLabel->Text = L"None Loaded";
			// 
			// Weapon2ODrainLabel
			// 
			this->Weapon2ODrainLabel->AutoSize = true;
			this->Weapon2ODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon2ODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon2ODrainLabel->Location = System::Drawing::Point(309, 150);
			this->Weapon2ODrainLabel->Name = L"Weapon2ODrainLabel";
			this->Weapon2ODrainLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon2ODrainLabel->TabIndex = 95;
			this->Weapon2ODrainLabel->Text = L"None Loaded";
			// 
			// Weapon1ODrainLabel
			// 
			this->Weapon1ODrainLabel->AutoSize = true;
			this->Weapon1ODrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon1ODrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon1ODrainLabel->Location = System::Drawing::Point(309, 137);
			this->Weapon1ODrainLabel->Name = L"Weapon1ODrainLabel";
			this->Weapon1ODrainLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon1ODrainLabel->TabIndex = 94;
			this->Weapon1ODrainLabel->Text = L"None Loaded";
			// 
			// ODrainTotalLabel
			// 
			this->ODrainTotalLabel->AutoSize = true;
			this->ODrainTotalLabel->BackColor = System::Drawing::Color::Transparent;
			this->ODrainTotalLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ODrainTotalLabel->Location = System::Drawing::Point(309, 254);
			this->ODrainTotalLabel->Name = L"ODrainTotalLabel";
			this->ODrainTotalLabel->Size = System::Drawing::Size(81, 13);
			this->ODrainTotalLabel->TabIndex = 102;
			this->ODrainTotalLabel->Text = L"None Loaded";
			// 
			// MassDrainPanel
			// 
			this->MassDrainPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"MassDrainPanel.BackgroundImage")));
			this->MassDrainPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->MassDrainPanel->Controls->Add(this->ReactorLabel);
			this->MassDrainPanel->Controls->Add(this->DrainOverloadedLabel1);
			this->MassDrainPanel->Controls->Add(this->ODrainTotalLabel);
			this->MassDrainPanel->Controls->Add(this->EngineLabel);
			this->MassDrainPanel->Controls->Add(this->CountermeasuresODrainLabel);
			this->MassDrainPanel->Controls->Add(this->SheildLabel);
			this->MassDrainPanel->Controls->Add(this->Ordinance3ODrainLabel);
			this->MassDrainPanel->Controls->Add(this->FArmorLabel);
			this->MassDrainPanel->Controls->Add(this->Ordinance2ODrainLabel);
			this->MassDrainPanel->Controls->Add(this->RArmorLabel);
			this->MassDrainPanel->Controls->Add(this->Ordinance1ODrainLabel);
			this->MassDrainPanel->Controls->Add(this->CapacitorStatusLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon4ODrainLabel);
			this->MassDrainPanel->Controls->Add(this->BoosterLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon3ODrainLabel);
			this->MassDrainPanel->Controls->Add(this->DriodLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon2ODrainLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon1Label);
			this->MassDrainPanel->Controls->Add(this->Weapon1ODrainLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon2Label);
			this->MassDrainPanel->Controls->Add(this->DroidODrainLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon3Label);
			this->MassDrainPanel->Controls->Add(this->BoosterODrainLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon4Label);
			this->MassDrainPanel->Controls->Add(this->CapacitorODrainLabel);
			this->MassDrainPanel->Controls->Add(this->Ordinance1Label);
			this->MassDrainPanel->Controls->Add(this->RArmorODrainLabel);
			this->MassDrainPanel->Controls->Add(this->Ordinance2Label);
			this->MassDrainPanel->Controls->Add(this->FArmorODrainLabel);
			this->MassDrainPanel->Controls->Add(this->Ordinance3Label);
			this->MassDrainPanel->Controls->Add(this->SheildODrainLabel);
			this->MassDrainPanel->Controls->Add(this->CountermeasuresLabel);
			this->MassDrainPanel->Controls->Add(this->EngineODrainLabel);
			this->MassDrainPanel->Controls->Add(this->MassLabel);
			this->MassDrainPanel->Controls->Add(this->ReactorODrainLabel);
			this->MassDrainPanel->Controls->Add(this->DrainLabel);
			this->MassDrainPanel->Controls->Add(this->TotalDrainLabel);
			this->MassDrainPanel->Controls->Add(this->DrainOverloadedLabel2);
			this->MassDrainPanel->Controls->Add(this->CountermeasuresDrainLabel);
			this->MassDrainPanel->Controls->Add(this->ReactorMassLabel);
			this->MassDrainPanel->Controls->Add(this->Ordinance3DrainLabel);
			this->MassDrainPanel->Controls->Add(this->EngineMassLabel);
			this->MassDrainPanel->Controls->Add(this->Ordinance2DrainLabel);
			this->MassDrainPanel->Controls->Add(this->SheildMassLabel);
			this->MassDrainPanel->Controls->Add(this->Ordinance1DrainLabel);
			this->MassDrainPanel->Controls->Add(this->FArmorMassLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon4DrainLabel);
			this->MassDrainPanel->Controls->Add(this->RArmorMassLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon3DrainLabel);
			this->MassDrainPanel->Controls->Add(this->CapacitorMassLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon2DrainLabel);
			this->MassDrainPanel->Controls->Add(this->BoosterMassLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon1DrainLabel);
			this->MassDrainPanel->Controls->Add(this->DroidMassLabel);
			this->MassDrainPanel->Controls->Add(this->DroidDrainLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon1MassLabel);
			this->MassDrainPanel->Controls->Add(this->BoosterDrainLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon2MassLabel);
			this->MassDrainPanel->Controls->Add(this->CapacitorDrainLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon3MassLabel);
			this->MassDrainPanel->Controls->Add(this->RArmorDrainLabel);
			this->MassDrainPanel->Controls->Add(this->Weapon4MassLabel);
			this->MassDrainPanel->Controls->Add(this->FArmorDrainLabel);
			this->MassDrainPanel->Controls->Add(this->Ordinance1MassLabel);
			this->MassDrainPanel->Controls->Add(this->SheildDrainLabel);
			this->MassDrainPanel->Controls->Add(this->Ordinance2MassLabel);
			this->MassDrainPanel->Controls->Add(this->EngineDrainLabel);
			this->MassDrainPanel->Controls->Add(this->Ordinance3MassLabel);
			this->MassDrainPanel->Controls->Add(this->ReactorDrainLabel);
			this->MassDrainPanel->Controls->Add(this->CountermeasuresMassLabel);
			this->MassDrainPanel->Controls->Add(this->TotalMassLabel);
			this->MassDrainPanel->Controls->Add(this->TotalsLabel);
			this->MassDrainPanel->Location = System::Drawing::Point(5, 33);
			this->MassDrainPanel->Name = L"MassDrainPanel";
			this->MassDrainPanel->Size = System::Drawing::Size(400, 284);
			this->MassDrainPanel->TabIndex = 103;
			// 
			// MassDrainSummaryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->ClientSize = System::Drawing::Size(410, 362);
			this->ControlBox = false;
			this->Controls->Add(this->MassDrainPanel);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->MassDrainStatsFormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MassDrainSummaryForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Mass/Drain Summary";
			this->MassDrainPanel->ResumeLayout(false);
			this->MassDrainPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void CalculateMasses(double currentReactorMass, double currentEngineMass, double currentBoosterMass, double currentSheildMass, double currentFArmorMass, 
			double currentRArmorMass, double currentDroidMass, double currentCapacitorMass, double currentOrdinance1Mass, double currentOrdinance2Mass, 
			double currentOrdinance3Mass, double currentWeapon1Mass, double currentWeapon2Mass, double currentWeapon3Mass, double currentWeapon4Mass, 
			double currentChaffMass){

				// Reactor
				if (currentReactorMass != 0)
				{
					ReactorMassLabel->Text = currentReactorMass.ToString(".##");
				}
				else
				{
					ReactorMassLabel->Text = "None Loaded";
				}

				// Engine
				if (currentEngineMass != 0)
				{
					EngineMassLabel->Text = currentEngineMass.ToString(".##");
				}
				else
				{
					EngineMassLabel->Text = "None Loaded";
				}

				// Booster
				if (currentBoosterMass != 0)
				{
					BoosterMassLabel->Text = currentBoosterMass.ToString(".##");
				}
				else
				{
					BoosterMassLabel->Text = "None Loaded";
				}

				// Sheild
				if (currentSheildMass != 0)
				{
					SheildMassLabel->Text = currentSheildMass.ToString(".##");
				}
				else
				{
					SheildMassLabel->Text = "None Loaded";
				}

				// Front Armor
				if (currentFArmorMass != 0)
				{
					FArmorMassLabel->Text = currentFArmorMass.ToString(".##");
				}
				else
				{
					FArmorMassLabel->Text = "None Loaded";
				}

				// Rear Armor
				if (currentRArmorMass != 0)
				{
					RArmorMassLabel->Text = currentRArmorMass.ToString(".##");
				}
				else
				{
					RArmorMassLabel->Text = "None Loaded";
				}

				// Droid
				if (currentDroidMass != 0)
				{
					DroidMassLabel->Text = currentDroidMass.ToString(".##");
				}
				else
				{
					DroidMassLabel->Text = "None Loaded";
				}

				// Capacitor
				if (currentCapacitorMass != 0)
				{
					CapacitorMassLabel->Text = currentCapacitorMass.ToString(".##");
				}
				else
				{
					CapacitorMassLabel->Text = "None Loaded";
				}

				// Ordinance 1
				if (currentOrdinance1Mass != 0)
				{
					Ordinance1MassLabel->Text = currentOrdinance1Mass.ToString(".##");
				}
				else
				{
					Ordinance1MassLabel->Text = "None Loaded";
				}

				// Ordinance 2
				if (currentOrdinance2Mass != 0)
				{
					Ordinance2MassLabel->Text = currentOrdinance2Mass.ToString(".##");
				}
				else
				{
					Ordinance2MassLabel->Text = "None Loaded";
				}

				// Ordinance 3
				if (currentOrdinance3Mass != 0)
				{
					Ordinance3MassLabel->Text = currentOrdinance3Mass.ToString(".##");
				}
				else
				{
					Ordinance3MassLabel->Text = "None Loaded";
				}

				// Weapon 1
				if (currentWeapon1Mass != 0)
				{
					Weapon1MassLabel->Text = currentWeapon1Mass.ToString(".##");
				}
				else
				{
					Weapon1MassLabel->Text = "None Loaded";
				}

				// Weapon 2
				if (currentWeapon2Mass != 0)
				{
					Weapon2MassLabel->Text = currentWeapon2Mass.ToString(".##");
				}
				else
				{
					Weapon2MassLabel->Text = "None Loaded";
				}

				// Weapon 3
				if (currentWeapon3Mass != 0)
				{
					Weapon3MassLabel->Text = currentWeapon3Mass.ToString(".##");
				}
				else
				{
					Weapon3MassLabel->Text = "None Loaded";
				}

				// Weapon 4
				if (currentWeapon4Mass != 0)
				{
					Weapon4MassLabel->Text = currentWeapon4Mass.ToString(".##");
				}
				else
				{
					Weapon4MassLabel->Text = "None Loaded";
				}

				// Chaff
				if (currentChaffMass != 0)
				{
					CountermeasuresMassLabel->Text = currentChaffMass.ToString(".##");
				}
				else
				{
					CountermeasuresMassLabel->Text = "None Loaded";
				}

				TotalMassLabel->Text = (currentReactorMass + currentEngineMass + currentBoosterMass + currentSheildMass + currentFArmorMass + 
					currentRArmorMass + currentDroidMass + currentCapacitorMass + currentOrdinance1Mass + currentOrdinance2Mass + 
					currentOrdinance3Mass + currentWeapon1Mass + currentWeapon2Mass + currentWeapon3Mass + currentWeapon4Mass + 
					currentChaffMass).ToString(".##");
		 }
private: System::Void CalculateDrains(double currentEngineDrain, double currentEngineOverloadedDrain,
			double currentBoosterDrain, double currentSheildDrain,
			double currentDroidDrain, double currentCapacitorDrain, double currentOrdinance1Drain, double currentOrdinance1OverloadedDrain, double currentOrdinance2Drain, 
			double currentOrdinance2OverloadedDrain, double currentOrdinance3Drain, double currentOrdinance3OverloadedDrain, double currentWeapon1Drain, 
			double currentWeapon1OverloadedDrain, double currentWeapon2Drain, double currentWeapon2OverloadedDrain, double currentWeapon3Drain, 
			double currentWeapon3OverloadedDrain, double currentWeapon4Drain, double currentWeapon4OverloadedDrain, double currentChaffDrain){
				
				// Engine
				if (currentEngineDrain != 0)
				{
					EngineDrainLabel->Text = currentEngineDrain.ToString(".##");
				}
				else
				{
					EngineDrainLabel->Text = "None Loaded";
				}

				// Boster
				if (currentBoosterDrain != 0)
				{
					BoosterDrainLabel->Text = currentBoosterDrain.ToString(".##");
				}
				else
				{
					BoosterDrainLabel->Text = "None Loaded";
				}

				// Sheild
				if (currentSheildDrain != 0)
				{
					SheildDrainLabel->Text = currentSheildDrain.ToString(".##");
				}
				else
				{
					SheildDrainLabel->Text = "None Loaded";
				}

				// Droid
				if (currentDroidDrain != 0)
				{
					DroidDrainLabel->Text = currentDroidDrain.ToString(".##");
				}
				else
				{
					DroidDrainLabel->Text = "None Loaded";
				}

				// Capacitor
				if (currentCapacitorDrain != 0)
				{
					CapacitorDrainLabel->Text = currentCapacitorDrain.ToString(".##");
				}
				else
				{
					CapacitorDrainLabel->Text = "None Loaded";
				}

				// Ordinance 1
				if (currentOrdinance1Drain != 0)
				{
					Ordinance1DrainLabel->Text = currentOrdinance1Drain.ToString(".##");
				}
				else
				{
					Ordinance1DrainLabel->Text = "None Loaded";
				}

				// Ordinance 1
				if (currentOrdinance1Drain != 0)
				{
					Ordinance1DrainLabel->Text = currentOrdinance1Drain.ToString(".##");
				}
				else
				{
					Ordinance1DrainLabel->Text = "None Loaded";
				}

				// Ordinance 2
				if (currentOrdinance2Drain != 0)
				{
					Ordinance2DrainLabel->Text = currentOrdinance2Drain.ToString(".##");
				}
				else
				{
					Ordinance2DrainLabel->Text = "None Loaded";
				}

				// Ordinance 3
				if (currentOrdinance3Drain != 0)
				{
					Ordinance3DrainLabel->Text = currentOrdinance3Drain.ToString(".##");
				}
				else
				{
					Ordinance3DrainLabel->Text = "None Loaded";
				}

				// Weapon 1
				if (currentWeapon1Drain != 0)
				{
					Weapon1DrainLabel->Text = currentWeapon1Drain.ToString(".##");
				}
				else
				{
					Weapon1DrainLabel->Text = "None Loaded";
				}

				// Weapon 2
				if (currentWeapon2Drain != 0)
				{
					Weapon2DrainLabel->Text = currentWeapon2Drain.ToString(".##");
				}
				else
				{
					Weapon2DrainLabel->Text = "None Loaded";
				}

				// Weapon 3
				if (currentWeapon3Drain != 0)
				{
					Weapon3DrainLabel->Text = currentWeapon3Drain.ToString(".##");
				}
				else
				{
					Weapon3DrainLabel->Text = "None Loaded";
				}

				// Weapon 4
				if (currentWeapon4Drain != 0)
				{
					Weapon4DrainLabel->Text = currentWeapon4Drain.ToString(".##");
				}
				else
				{
					Weapon4DrainLabel->Text = "None Loaded";
				}

				// Chaff
				if (currentChaffDrain != 0)
				{
					CountermeasuresDrainLabel->Text = currentChaffDrain.ToString(".##");
				}
				else
				{
					CountermeasuresDrainLabel->Text = "None Loaded";
				}

				TotalDrainLabel->Text = (currentEngineDrain + currentBoosterDrain + currentSheildDrain + currentDroidDrain + 
					currentCapacitorDrain + currentOrdinance1Drain + currentOrdinance2Drain + currentOrdinance3Drain + 
					currentWeapon1Drain + currentWeapon2Drain + currentWeapon3Drain + currentWeapon4Drain + currentChaffDrain).ToString(".##");

				///
				/// Overloaded Drains
				///

				// Engine (O)
				if (currentEngineOverloadedDrain != 0)
				{
					EngineODrainLabel->Text = currentEngineOverloadedDrain.ToString(".##");
				}
				else
				{
					EngineODrainLabel->Text = "None Loaded";
				}

				// Boster (O)
				if (currentBoosterDrain != 0)
				{
					BoosterODrainLabel->Text = currentBoosterDrain.ToString(".##");
				}
				else
				{
					BoosterODrainLabel->Text = "None Loaded";
				}

				// Sheild (O)
				if (currentSheildDrain != 0)
				{
					SheildODrainLabel->Text = currentSheildDrain.ToString(".##");
				}
				else
				{
					SheildODrainLabel->Text = "None Loaded";
				}

				// Droid (O)
				if (currentDroidDrain != 0)
				{
					DroidODrainLabel->Text = currentDroidDrain.ToString(".##");
				}
				else
				{
					DroidODrainLabel->Text = "None Loaded";
				}

				// Capacitor (O)
				if (currentCapacitorDrain != 0)
				{
					CapacitorODrainLabel->Text = currentCapacitorDrain.ToString(".##");
				}
				else
				{
					CapacitorODrainLabel->Text = "None Loaded";
				}

				// Ordinance 1 (O)
				if (currentOrdinance1OverloadedDrain != 0)
				{
					Ordinance1ODrainLabel->Text = currentOrdinance1OverloadedDrain.ToString(".##");
				}
				else
				{
					Ordinance1ODrainLabel->Text = "None Loaded";
				}

				// Ordinance 2 (O)
				if (currentOrdinance2OverloadedDrain != 0)
				{
					Ordinance2ODrainLabel->Text = currentOrdinance2OverloadedDrain.ToString(".##");
				}
				else
				{
					Ordinance2ODrainLabel->Text = "None Loaded";
				}

				// Ordinance 3 (O)
				if (currentOrdinance3OverloadedDrain != 0)
				{
					Ordinance3ODrainLabel->Text = currentOrdinance3OverloadedDrain.ToString(".##");
				}
				else
				{
					Ordinance3ODrainLabel->Text = "None Loaded";
				}

				// Weapon 1 (O)
				if (currentWeapon1OverloadedDrain != 0)
				{
					Weapon1ODrainLabel->Text = currentWeapon1OverloadedDrain.ToString(".##");
				}
				else
				{
					Weapon1ODrainLabel->Text = "None Loaded";
				}

				// Weapon 2 (O)
				if (currentWeapon2OverloadedDrain != 0)
				{
					Weapon2ODrainLabel->Text = currentWeapon2OverloadedDrain.ToString(".##");
				}
				else
				{
					Weapon2ODrainLabel->Text = "None Loaded";
				}

				// Weapon 3 (O)
				if (currentWeapon3OverloadedDrain != 0)
				{
					Weapon3ODrainLabel->Text = currentWeapon3OverloadedDrain.ToString(".##");
				}
				else
				{
					Weapon3ODrainLabel->Text = "None Loaded";
				}

				// Weapon 4 (O)
				if (currentWeapon4OverloadedDrain != 0)
				{
					Weapon4ODrainLabel->Text = currentWeapon4OverloadedDrain.ToString(".##");
				}
				else
				{
					Weapon4ODrainLabel->Text = "None Loaded";
				}

				// Chaff (O)
				if (currentChaffDrain != 0)
				{
					CountermeasuresODrainLabel->Text = currentChaffDrain.ToString(".##");
				}
				else
				{
					CountermeasuresODrainLabel->Text = "None Loaded";
				}

				ODrainTotalLabel->Text = (currentEngineOverloadedDrain + currentBoosterDrain + currentSheildDrain + currentDroidDrain + 
					currentCapacitorDrain + currentOrdinance1OverloadedDrain + currentOrdinance2OverloadedDrain + currentOrdinance3OverloadedDrain + 
					currentWeapon1OverloadedDrain + currentWeapon2OverloadedDrain + currentWeapon3OverloadedDrain + currentWeapon4OverloadedDrain + currentChaffDrain).ToString(".##");
		 }
private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
};
}
