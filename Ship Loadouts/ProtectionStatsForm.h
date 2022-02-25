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
	/// Summary for ProtectionStatsForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ProtectionStatsForm : public System::Windows::Forms::Form
	{
	public:
		ProtectionStatsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		ProtectionStatsForm(Reactor^ loadedReactor, Engine^ loadedEngine, Booster^ loadedBooster, Sheild^ loadedSheild, 
			Droid^ loadedDroid, Capacitor^ loadedCapacitor, Armor^ loadedFArmor, Armor^ loadedRArmor, Ordinance^ loadedOrdinance1, 
			Ordinance^ loadedOrdinance2, Ordinance^ loadedOrdinance3, Weapon^ loadedWeapon1, Weapon^ loadedWeapon2, Weapon^ loadedWeapon3, 
			Weapon^ loadedWeapon4, Chaff^ loadedChaff)
		{
			InitializeComponent();

			RetriveValues(loadedReactor, loadedEngine, loadedBooster, loadedSheild, loadedDroid, loadedCapacitor, 
				loadedFArmor, loadedRArmor, loadedOrdinance1, loadedOrdinance2, loadedOrdinance3, loadedWeapon1, 
				loadedWeapon2, loadedWeapon3, loadedWeapon4, loadedChaff);

			CalculateTotalProtections();

			CalculateFrontCompProtections();
			CalculateRearCompProtections();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProtectionStatsForm()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region ProtectionStatsForm Item Declerations

	private: System::Windows::Forms::Label^  ProtectionStatsFormLabel;
	private: System::Windows::Forms::Label^  CountermeasuresLabel;
	private: System::Windows::Forms::Label^  Ordinance3Label;
	private: System::Windows::Forms::Label^  Ordinance2Label;
	private: System::Windows::Forms::Label^  Ordinance1Label;
	private: System::Windows::Forms::Label^  Weapon4Label;
	private: System::Windows::Forms::Label^  Weapon3Label;
	private: System::Windows::Forms::Label^  Weapon2Label;
	private: System::Windows::Forms::Label^  Weapon1Label;
	private: System::Windows::Forms::Label^  DriodLabel;
	private: System::Windows::Forms::Label^  BoosterLabel;
	private: System::Windows::Forms::Label^  CapacitorStatusLabel;
	private: System::Windows::Forms::Label^  EngineLabel;
	private: System::Windows::Forms::Label^  ReactorLabel;
	private: System::Windows::Forms::Label^  SheildandArmorLabel;
	private: System::Windows::Forms::Label^  ArmorLabel;
	private: System::Windows::Forms::Label^  SheildingLabel;
	private: System::Windows::Forms::Label^  CompProtectionsLabel;
	private: System::Windows::Forms::Label^  FCountermeasuresValueLabel;
	private: System::Windows::Forms::Label^  FOrdinance3ValueLabel;
	private: System::Windows::Forms::Label^  FOrdinance2ValueLabel;
	private: System::Windows::Forms::Label^  FOrdinance1ValueLabel;
	private: System::Windows::Forms::Label^  FWeapon4ValueLabel;
	private: System::Windows::Forms::Label^  FWeapon3ValueLabel;
	private: System::Windows::Forms::Label^  FWeapon2ValueLabel;
	private: System::Windows::Forms::Label^  FWeapon1ValueLabel;
	private: System::Windows::Forms::Label^  FDroidValueLabel;

	private: System::Windows::Forms::Label^  FBoosterValueLabel;
	private: System::Windows::Forms::Label^  FCapacitorValueLabel;
	private: System::Windows::Forms::Label^  FEngineValueLabel;
	private: System::Windows::Forms::Label^  FReactorValueLabel;
	private: System::Windows::Forms::Label^  FrontLabel;
	private: System::Windows::Forms::Label^  BackLabel;
	private: System::Windows::Forms::Label^  FSheildandArmorValueLabel;
	private: System::Windows::Forms::Label^  FArmorValueLabel;
	private: System::Windows::Forms::Label^  FSheildingValueLabel;
	private: System::Windows::Forms::Label^  RSheildandArmorValueLabel;

	private: System::Windows::Forms::Label^  RArmorValueLabel;
	private: System::Windows::Forms::Label^  RSheildingValueLabel;
	private: System::Windows::Forms::Label^  RCountermeasuresValueLabel;
	private: System::Windows::Forms::Label^  ROrdinance3ValueLabel;
	private: System::Windows::Forms::Label^  ROrdinance2ValueLabel;
	private: System::Windows::Forms::Label^  ROrdinance1ValueLabel;
	private: System::Windows::Forms::Label^  RWeapon4ValueLabel;
	private: System::Windows::Forms::Label^  RWeapon3ValueLabel;
	private: System::Windows::Forms::Label^  RWeapon2ValueLabel;
	private: System::Windows::Forms::Label^  RWeapon1ValueLabel;
	private: System::Windows::Forms::Label^  RDroidValueLabel;

	private: System::Windows::Forms::Label^  RBoosterValueLabel;
	private: System::Windows::Forms::Label^  RCapacitorValueLabel;
	private: System::Windows::Forms::Label^  REngineValueLabel;
	private: System::Windows::Forms::Label^  RReactorValueLabel;
	private: System::Windows::Forms::Label^  AdjustLabel;
	private: System::Windows::Forms::Label^  AdjustValueLabel;
	private: System::Windows::Forms::Button^  CloseButton;
	protected: 

#pragma endregion

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		static String^ adjustmentUsed;
		static int adjustmentUsedIndex;
		static double sheildFrontHP;
		static double sheildBackHP;

		static double fSheilding;
		static double rSheilding;

		static double totalFront;
		static double totalRear;

		static double loadedReactorArmor;
		static double loadedEngineArmor;
		static double loadedBoosterArmor;
		static double loadedSheildArmor;
		static double loadedDroidArmor;
		static double loadedCapacitorArmor;
		static double loadedFArmorArmor;
		static double loadedRArmorArmor;
		static double loadedOrdinance1Armor;
		static double loadedOrdinance2Armor;
		static double loadedOrdinance3Armor;
		static double loadedWeapon1Armor;
		static double loadedWeapon2Armor;
		static double loadedWeapon3Armor;
		static double loadedWeapon4Armor;
private: System::Windows::Forms::Panel^  panel1;
		 static double loadedChaffArmor;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ProtectionStatsForm::typeid));
			this->ProtectionStatsFormLabel = (gcnew System::Windows::Forms::Label());
			this->CountermeasuresLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance3Label = (gcnew System::Windows::Forms::Label());
			this->Ordinance2Label = (gcnew System::Windows::Forms::Label());
			this->Ordinance1Label = (gcnew System::Windows::Forms::Label());
			this->Weapon4Label = (gcnew System::Windows::Forms::Label());
			this->Weapon3Label = (gcnew System::Windows::Forms::Label());
			this->Weapon2Label = (gcnew System::Windows::Forms::Label());
			this->Weapon1Label = (gcnew System::Windows::Forms::Label());
			this->DriodLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorStatusLabel = (gcnew System::Windows::Forms::Label());
			this->EngineLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorLabel = (gcnew System::Windows::Forms::Label());
			this->SheildandArmorLabel = (gcnew System::Windows::Forms::Label());
			this->ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->SheildingLabel = (gcnew System::Windows::Forms::Label());
			this->CompProtectionsLabel = (gcnew System::Windows::Forms::Label());
			this->FCountermeasuresValueLabel = (gcnew System::Windows::Forms::Label());
			this->FOrdinance3ValueLabel = (gcnew System::Windows::Forms::Label());
			this->FOrdinance2ValueLabel = (gcnew System::Windows::Forms::Label());
			this->FOrdinance1ValueLabel = (gcnew System::Windows::Forms::Label());
			this->FWeapon4ValueLabel = (gcnew System::Windows::Forms::Label());
			this->FWeapon3ValueLabel = (gcnew System::Windows::Forms::Label());
			this->FWeapon2ValueLabel = (gcnew System::Windows::Forms::Label());
			this->FWeapon1ValueLabel = (gcnew System::Windows::Forms::Label());
			this->FDroidValueLabel = (gcnew System::Windows::Forms::Label());
			this->FBoosterValueLabel = (gcnew System::Windows::Forms::Label());
			this->FCapacitorValueLabel = (gcnew System::Windows::Forms::Label());
			this->FEngineValueLabel = (gcnew System::Windows::Forms::Label());
			this->FReactorValueLabel = (gcnew System::Windows::Forms::Label());
			this->FrontLabel = (gcnew System::Windows::Forms::Label());
			this->BackLabel = (gcnew System::Windows::Forms::Label());
			this->FSheildandArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->FArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->FSheildingValueLabel = (gcnew System::Windows::Forms::Label());
			this->RSheildandArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->RArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->RSheildingValueLabel = (gcnew System::Windows::Forms::Label());
			this->RCountermeasuresValueLabel = (gcnew System::Windows::Forms::Label());
			this->ROrdinance3ValueLabel = (gcnew System::Windows::Forms::Label());
			this->ROrdinance2ValueLabel = (gcnew System::Windows::Forms::Label());
			this->ROrdinance1ValueLabel = (gcnew System::Windows::Forms::Label());
			this->RWeapon4ValueLabel = (gcnew System::Windows::Forms::Label());
			this->RWeapon3ValueLabel = (gcnew System::Windows::Forms::Label());
			this->RWeapon2ValueLabel = (gcnew System::Windows::Forms::Label());
			this->RWeapon1ValueLabel = (gcnew System::Windows::Forms::Label());
			this->RDroidValueLabel = (gcnew System::Windows::Forms::Label());
			this->RBoosterValueLabel = (gcnew System::Windows::Forms::Label());
			this->RCapacitorValueLabel = (gcnew System::Windows::Forms::Label());
			this->REngineValueLabel = (gcnew System::Windows::Forms::Label());
			this->RReactorValueLabel = (gcnew System::Windows::Forms::Label());
			this->AdjustLabel = (gcnew System::Windows::Forms::Label());
			this->AdjustValueLabel = (gcnew System::Windows::Forms::Label());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ProtectionStatsFormLabel
			// 
			this->ProtectionStatsFormLabel->AutoSize = true;
			this->ProtectionStatsFormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ProtectionStatsFormLabel->Location = System::Drawing::Point(61, 9);
			this->ProtectionStatsFormLabel->Name = L"ProtectionStatsFormLabel";
			this->ProtectionStatsFormLabel->Size = System::Drawing::Size(231, 16);
			this->ProtectionStatsFormLabel->TabIndex = 1;
			this->ProtectionStatsFormLabel->Text = L"P r o t e c t i o n  S t a t i s t i c s";
			// 
			// CountermeasuresLabel
			// 
			this->CountermeasuresLabel->AutoSize = true;
			this->CountermeasuresLabel->BackColor = System::Drawing::Color::Transparent;
			this->CountermeasuresLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CountermeasuresLabel->Location = System::Drawing::Point(6, 275);
			this->CountermeasuresLabel->Name = L"CountermeasuresLabel";
			this->CountermeasuresLabel->Size = System::Drawing::Size(114, 13);
			this->CountermeasuresLabel->TabIndex = 60;
			this->CountermeasuresLabel->Text = L"Countermeasures:";
			// 
			// Ordinance3Label
			// 
			this->Ordinance3Label->AutoSize = true;
			this->Ordinance3Label->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance3Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance3Label->Location = System::Drawing::Point(6, 262);
			this->Ordinance3Label->Name = L"Ordinance3Label";
			this->Ordinance3Label->Size = System::Drawing::Size(81, 13);
			this->Ordinance3Label->TabIndex = 59;
			this->Ordinance3Label->Text = L"Ordinance 3:";
			// 
			// Ordinance2Label
			// 
			this->Ordinance2Label->AutoSize = true;
			this->Ordinance2Label->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance2Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance2Label->Location = System::Drawing::Point(6, 249);
			this->Ordinance2Label->Name = L"Ordinance2Label";
			this->Ordinance2Label->Size = System::Drawing::Size(81, 13);
			this->Ordinance2Label->TabIndex = 58;
			this->Ordinance2Label->Text = L"Ordinance 2:";
			// 
			// Ordinance1Label
			// 
			this->Ordinance1Label->AutoSize = true;
			this->Ordinance1Label->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance1Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance1Label->Location = System::Drawing::Point(6, 236);
			this->Ordinance1Label->Name = L"Ordinance1Label";
			this->Ordinance1Label->Size = System::Drawing::Size(81, 13);
			this->Ordinance1Label->TabIndex = 57;
			this->Ordinance1Label->Text = L"Ordinance 1:";
			// 
			// Weapon4Label
			// 
			this->Weapon4Label->AutoSize = true;
			this->Weapon4Label->BackColor = System::Drawing::Color::Transparent;
			this->Weapon4Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon4Label->Location = System::Drawing::Point(6, 223);
			this->Weapon4Label->Name = L"Weapon4Label";
			this->Weapon4Label->Size = System::Drawing::Size(69, 13);
			this->Weapon4Label->TabIndex = 56;
			this->Weapon4Label->Text = L"Weapon 4:";
			// 
			// Weapon3Label
			// 
			this->Weapon3Label->AutoSize = true;
			this->Weapon3Label->BackColor = System::Drawing::Color::Transparent;
			this->Weapon3Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon3Label->Location = System::Drawing::Point(6, 210);
			this->Weapon3Label->Name = L"Weapon3Label";
			this->Weapon3Label->Size = System::Drawing::Size(69, 13);
			this->Weapon3Label->TabIndex = 55;
			this->Weapon3Label->Text = L"Weapon 3:";
			// 
			// Weapon2Label
			// 
			this->Weapon2Label->AutoSize = true;
			this->Weapon2Label->BackColor = System::Drawing::Color::Transparent;
			this->Weapon2Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon2Label->Location = System::Drawing::Point(6, 197);
			this->Weapon2Label->Name = L"Weapon2Label";
			this->Weapon2Label->Size = System::Drawing::Size(69, 13);
			this->Weapon2Label->TabIndex = 54;
			this->Weapon2Label->Text = L"Weapon 2:";
			// 
			// Weapon1Label
			// 
			this->Weapon1Label->AutoSize = true;
			this->Weapon1Label->BackColor = System::Drawing::Color::Transparent;
			this->Weapon1Label->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon1Label->Location = System::Drawing::Point(6, 184);
			this->Weapon1Label->Name = L"Weapon1Label";
			this->Weapon1Label->Size = System::Drawing::Size(69, 13);
			this->Weapon1Label->TabIndex = 53;
			this->Weapon1Label->Text = L"Weapon 1:";
			// 
			// DriodLabel
			// 
			this->DriodLabel->AutoSize = true;
			this->DriodLabel->BackColor = System::Drawing::Color::Transparent;
			this->DriodLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DriodLabel->Location = System::Drawing::Point(5, 171);
			this->DriodLabel->Name = L"DriodLabel";
			this->DriodLabel->Size = System::Drawing::Size(99, 13);
			this->DriodLabel->TabIndex = 52;
			this->DriodLabel->Text = L"Droid Interface:";
			// 
			// BoosterLabel
			// 
			this->BoosterLabel->AutoSize = true;
			this->BoosterLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterLabel->Location = System::Drawing::Point(5, 158);
			this->BoosterLabel->Name = L"BoosterLabel";
			this->BoosterLabel->Size = System::Drawing::Size(56, 13);
			this->BoosterLabel->TabIndex = 51;
			this->BoosterLabel->Text = L"Booster:";
			// 
			// CapacitorStatusLabel
			// 
			this->CapacitorStatusLabel->AutoSize = true;
			this->CapacitorStatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->CapacitorStatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorStatusLabel->Location = System::Drawing::Point(5, 145);
			this->CapacitorStatusLabel->Name = L"CapacitorStatusLabel";
			this->CapacitorStatusLabel->Size = System::Drawing::Size(67, 13);
			this->CapacitorStatusLabel->TabIndex = 50;
			this->CapacitorStatusLabel->Text = L"Capacitor:";
			// 
			// EngineLabel
			// 
			this->EngineLabel->AutoSize = true;
			this->EngineLabel->BackColor = System::Drawing::Color::Transparent;
			this->EngineLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineLabel->Location = System::Drawing::Point(5, 132);
			this->EngineLabel->Name = L"EngineLabel";
			this->EngineLabel->Size = System::Drawing::Size(50, 13);
			this->EngineLabel->TabIndex = 46;
			this->EngineLabel->Text = L"Engine:";
			// 
			// ReactorLabel
			// 
			this->ReactorLabel->AutoSize = true;
			this->ReactorLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReactorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorLabel->Location = System::Drawing::Point(5, 119);
			this->ReactorLabel->Name = L"ReactorLabel";
			this->ReactorLabel->Size = System::Drawing::Size(56, 13);
			this->ReactorLabel->TabIndex = 45;
			this->ReactorLabel->Text = L"Reactor:";
			// 
			// SheildandArmorLabel
			// 
			this->SheildandArmorLabel->AutoSize = true;
			this->SheildandArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->SheildandArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildandArmorLabel->Location = System::Drawing::Point(6, 73);
			this->SheildandArmorLabel->Name = L"SheildandArmorLabel";
			this->SheildandArmorLabel->Size = System::Drawing::Size(100, 13);
			this->SheildandArmorLabel->TabIndex = 61;
			this->SheildandArmorLabel->Text = L"Shield + Armor:";
			// 
			// ArmorLabel
			// 
			this->ArmorLabel->AutoSize = true;
			this->ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ArmorLabel->Location = System::Drawing::Point(6, 60);
			this->ArmorLabel->Name = L"ArmorLabel";
			this->ArmorLabel->Size = System::Drawing::Size(48, 13);
			this->ArmorLabel->TabIndex = 62;
			this->ArmorLabel->Text = L"Armor:";
			// 
			// SheildingLabel
			// 
			this->SheildingLabel->AutoSize = true;
			this->SheildingLabel->BackColor = System::Drawing::Color::Transparent;
			this->SheildingLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildingLabel->Location = System::Drawing::Point(6, 47);
			this->SheildingLabel->Name = L"SheildingLabel";
			this->SheildingLabel->Size = System::Drawing::Size(64, 13);
			this->SheildingLabel->TabIndex = 63;
			this->SheildingLabel->Text = L"Shielding:";
			// 
			// CompProtectionsLabel
			// 
			this->CompProtectionsLabel->AutoSize = true;
			this->CompProtectionsLabel->BackColor = System::Drawing::Color::Transparent;
			this->CompProtectionsLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CompProtectionsLabel->Location = System::Drawing::Point(90, 96);
			this->CompProtectionsLabel->Name = L"CompProtectionsLabel";
			this->CompProtectionsLabel->Size = System::Drawing::Size(158, 13);
			this->CompProtectionsLabel->TabIndex = 64;
			this->CompProtectionsLabel->Text = L"Component Protections";
			// 
			// FCountermeasuresValueLabel
			// 
			this->FCountermeasuresValueLabel->AutoSize = true;
			this->FCountermeasuresValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FCountermeasuresValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FCountermeasuresValueLabel->Location = System::Drawing::Point(142, 275);
			this->FCountermeasuresValueLabel->Name = L"FCountermeasuresValueLabel";
			this->FCountermeasuresValueLabel->Size = System::Drawing::Size(81, 13);
			this->FCountermeasuresValueLabel->TabIndex = 81;
			this->FCountermeasuresValueLabel->Text = L"None Loaded";
			// 
			// FOrdinance3ValueLabel
			// 
			this->FOrdinance3ValueLabel->AutoSize = true;
			this->FOrdinance3ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FOrdinance3ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FOrdinance3ValueLabel->Location = System::Drawing::Point(142, 262);
			this->FOrdinance3ValueLabel->Name = L"FOrdinance3ValueLabel";
			this->FOrdinance3ValueLabel->Size = System::Drawing::Size(81, 13);
			this->FOrdinance3ValueLabel->TabIndex = 80;
			this->FOrdinance3ValueLabel->Text = L"None Loaded";
			// 
			// FOrdinance2ValueLabel
			// 
			this->FOrdinance2ValueLabel->AutoSize = true;
			this->FOrdinance2ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FOrdinance2ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FOrdinance2ValueLabel->Location = System::Drawing::Point(142, 249);
			this->FOrdinance2ValueLabel->Name = L"FOrdinance2ValueLabel";
			this->FOrdinance2ValueLabel->Size = System::Drawing::Size(81, 13);
			this->FOrdinance2ValueLabel->TabIndex = 79;
			this->FOrdinance2ValueLabel->Text = L"None Loaded";
			// 
			// FOrdinance1ValueLabel
			// 
			this->FOrdinance1ValueLabel->AutoSize = true;
			this->FOrdinance1ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FOrdinance1ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FOrdinance1ValueLabel->Location = System::Drawing::Point(142, 236);
			this->FOrdinance1ValueLabel->Name = L"FOrdinance1ValueLabel";
			this->FOrdinance1ValueLabel->Size = System::Drawing::Size(81, 13);
			this->FOrdinance1ValueLabel->TabIndex = 78;
			this->FOrdinance1ValueLabel->Text = L"None Loaded";
			// 
			// FWeapon4ValueLabel
			// 
			this->FWeapon4ValueLabel->AutoSize = true;
			this->FWeapon4ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FWeapon4ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FWeapon4ValueLabel->Location = System::Drawing::Point(142, 223);
			this->FWeapon4ValueLabel->Name = L"FWeapon4ValueLabel";
			this->FWeapon4ValueLabel->Size = System::Drawing::Size(81, 13);
			this->FWeapon4ValueLabel->TabIndex = 77;
			this->FWeapon4ValueLabel->Text = L"None Loaded";
			// 
			// FWeapon3ValueLabel
			// 
			this->FWeapon3ValueLabel->AutoSize = true;
			this->FWeapon3ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FWeapon3ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FWeapon3ValueLabel->Location = System::Drawing::Point(142, 210);
			this->FWeapon3ValueLabel->Name = L"FWeapon3ValueLabel";
			this->FWeapon3ValueLabel->Size = System::Drawing::Size(81, 13);
			this->FWeapon3ValueLabel->TabIndex = 76;
			this->FWeapon3ValueLabel->Text = L"None Loaded";
			// 
			// FWeapon2ValueLabel
			// 
			this->FWeapon2ValueLabel->AutoSize = true;
			this->FWeapon2ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FWeapon2ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FWeapon2ValueLabel->Location = System::Drawing::Point(142, 197);
			this->FWeapon2ValueLabel->Name = L"FWeapon2ValueLabel";
			this->FWeapon2ValueLabel->Size = System::Drawing::Size(81, 13);
			this->FWeapon2ValueLabel->TabIndex = 75;
			this->FWeapon2ValueLabel->Text = L"None Loaded";
			// 
			// FWeapon1ValueLabel
			// 
			this->FWeapon1ValueLabel->AutoSize = true;
			this->FWeapon1ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FWeapon1ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FWeapon1ValueLabel->Location = System::Drawing::Point(142, 184);
			this->FWeapon1ValueLabel->Name = L"FWeapon1ValueLabel";
			this->FWeapon1ValueLabel->Size = System::Drawing::Size(81, 13);
			this->FWeapon1ValueLabel->TabIndex = 74;
			this->FWeapon1ValueLabel->Text = L"None Loaded";
			// 
			// FDroidValueLabel
			// 
			this->FDroidValueLabel->AutoSize = true;
			this->FDroidValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FDroidValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FDroidValueLabel->Location = System::Drawing::Point(142, 171);
			this->FDroidValueLabel->Name = L"FDroidValueLabel";
			this->FDroidValueLabel->Size = System::Drawing::Size(81, 13);
			this->FDroidValueLabel->TabIndex = 73;
			this->FDroidValueLabel->Text = L"None Loaded";
			// 
			// FBoosterValueLabel
			// 
			this->FBoosterValueLabel->AutoSize = true;
			this->FBoosterValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FBoosterValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FBoosterValueLabel->Location = System::Drawing::Point(142, 158);
			this->FBoosterValueLabel->Name = L"FBoosterValueLabel";
			this->FBoosterValueLabel->Size = System::Drawing::Size(81, 13);
			this->FBoosterValueLabel->TabIndex = 72;
			this->FBoosterValueLabel->Text = L"None Loaded";
			// 
			// FCapacitorValueLabel
			// 
			this->FCapacitorValueLabel->AutoSize = true;
			this->FCapacitorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FCapacitorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FCapacitorValueLabel->Location = System::Drawing::Point(142, 145);
			this->FCapacitorValueLabel->Name = L"FCapacitorValueLabel";
			this->FCapacitorValueLabel->Size = System::Drawing::Size(81, 13);
			this->FCapacitorValueLabel->TabIndex = 71;
			this->FCapacitorValueLabel->Text = L"None Loaded";
			// 
			// FEngineValueLabel
			// 
			this->FEngineValueLabel->AutoSize = true;
			this->FEngineValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FEngineValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FEngineValueLabel->Location = System::Drawing::Point(142, 131);
			this->FEngineValueLabel->Name = L"FEngineValueLabel";
			this->FEngineValueLabel->Size = System::Drawing::Size(81, 13);
			this->FEngineValueLabel->TabIndex = 67;
			this->FEngineValueLabel->Text = L"None Loaded";
			// 
			// FReactorValueLabel
			// 
			this->FReactorValueLabel->AutoSize = true;
			this->FReactorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FReactorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FReactorValueLabel->Location = System::Drawing::Point(142, 118);
			this->FReactorValueLabel->Name = L"FReactorValueLabel";
			this->FReactorValueLabel->Size = System::Drawing::Size(81, 13);
			this->FReactorValueLabel->TabIndex = 66;
			this->FReactorValueLabel->Text = L"None Loaded";
			// 
			// FrontLabel
			// 
			this->FrontLabel->AutoSize = true;
			this->FrontLabel->BackColor = System::Drawing::Color::Transparent;
			this->FrontLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FrontLabel->Location = System::Drawing::Point(155, 32);
			this->FrontLabel->Name = L"FrontLabel";
			this->FrontLabel->Size = System::Drawing::Size(42, 13);
			this->FrontLabel->TabIndex = 82;
			this->FrontLabel->Text = L"Front";
			// 
			// BackLabel
			// 
			this->BackLabel->AutoSize = true;
			this->BackLabel->BackColor = System::Drawing::Color::Transparent;
			this->BackLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BackLabel->Location = System::Drawing::Point(266, 32);
			this->BackLabel->Name = L"BackLabel";
			this->BackLabel->Size = System::Drawing::Size(38, 13);
			this->BackLabel->TabIndex = 83;
			this->BackLabel->Text = L"Back";
			// 
			// FSheildandArmorValueLabel
			// 
			this->FSheildandArmorValueLabel->AutoSize = true;
			this->FSheildandArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FSheildandArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FSheildandArmorValueLabel->Location = System::Drawing::Point(142, 74);
			this->FSheildandArmorValueLabel->Name = L"FSheildandArmorValueLabel";
			this->FSheildandArmorValueLabel->Size = System::Drawing::Size(81, 13);
			this->FSheildandArmorValueLabel->TabIndex = 86;
			this->FSheildandArmorValueLabel->Text = L"None Loaded";
			// 
			// FArmorValueLabel
			// 
			this->FArmorValueLabel->AutoSize = true;
			this->FArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FArmorValueLabel->Location = System::Drawing::Point(142, 60);
			this->FArmorValueLabel->Name = L"FArmorValueLabel";
			this->FArmorValueLabel->Size = System::Drawing::Size(81, 13);
			this->FArmorValueLabel->TabIndex = 85;
			this->FArmorValueLabel->Text = L"None Loaded";
			// 
			// FSheildingValueLabel
			// 
			this->FSheildingValueLabel->AutoSize = true;
			this->FSheildingValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FSheildingValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FSheildingValueLabel->Location = System::Drawing::Point(142, 47);
			this->FSheildingValueLabel->Name = L"FSheildingValueLabel";
			this->FSheildingValueLabel->Size = System::Drawing::Size(81, 13);
			this->FSheildingValueLabel->TabIndex = 84;
			this->FSheildingValueLabel->Text = L"None Loaded";
			// 
			// RSheildandArmorValueLabel
			// 
			this->RSheildandArmorValueLabel->AutoSize = true;
			this->RSheildandArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RSheildandArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RSheildandArmorValueLabel->Location = System::Drawing::Point(250, 74);
			this->RSheildandArmorValueLabel->Name = L"RSheildandArmorValueLabel";
			this->RSheildandArmorValueLabel->Size = System::Drawing::Size(81, 13);
			this->RSheildandArmorValueLabel->TabIndex = 89;
			this->RSheildandArmorValueLabel->Text = L"None Loaded";
			// 
			// RArmorValueLabel
			// 
			this->RArmorValueLabel->AutoSize = true;
			this->RArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RArmorValueLabel->Location = System::Drawing::Point(250, 60);
			this->RArmorValueLabel->Name = L"RArmorValueLabel";
			this->RArmorValueLabel->Size = System::Drawing::Size(81, 13);
			this->RArmorValueLabel->TabIndex = 88;
			this->RArmorValueLabel->Text = L"None Loaded";
			// 
			// RSheildingValueLabel
			// 
			this->RSheildingValueLabel->AutoSize = true;
			this->RSheildingValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RSheildingValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RSheildingValueLabel->Location = System::Drawing::Point(250, 47);
			this->RSheildingValueLabel->Name = L"RSheildingValueLabel";
			this->RSheildingValueLabel->Size = System::Drawing::Size(81, 13);
			this->RSheildingValueLabel->TabIndex = 87;
			this->RSheildingValueLabel->Text = L"None Loaded";
			// 
			// RCountermeasuresValueLabel
			// 
			this->RCountermeasuresValueLabel->AutoSize = true;
			this->RCountermeasuresValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RCountermeasuresValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RCountermeasuresValueLabel->Location = System::Drawing::Point(250, 275);
			this->RCountermeasuresValueLabel->Name = L"RCountermeasuresValueLabel";
			this->RCountermeasuresValueLabel->Size = System::Drawing::Size(81, 13);
			this->RCountermeasuresValueLabel->TabIndex = 102;
			this->RCountermeasuresValueLabel->Text = L"None Loaded";
			// 
			// ROrdinance3ValueLabel
			// 
			this->ROrdinance3ValueLabel->AutoSize = true;
			this->ROrdinance3ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->ROrdinance3ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ROrdinance3ValueLabel->Location = System::Drawing::Point(250, 262);
			this->ROrdinance3ValueLabel->Name = L"ROrdinance3ValueLabel";
			this->ROrdinance3ValueLabel->Size = System::Drawing::Size(81, 13);
			this->ROrdinance3ValueLabel->TabIndex = 101;
			this->ROrdinance3ValueLabel->Text = L"None Loaded";
			// 
			// ROrdinance2ValueLabel
			// 
			this->ROrdinance2ValueLabel->AutoSize = true;
			this->ROrdinance2ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->ROrdinance2ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ROrdinance2ValueLabel->Location = System::Drawing::Point(250, 249);
			this->ROrdinance2ValueLabel->Name = L"ROrdinance2ValueLabel";
			this->ROrdinance2ValueLabel->Size = System::Drawing::Size(81, 13);
			this->ROrdinance2ValueLabel->TabIndex = 100;
			this->ROrdinance2ValueLabel->Text = L"None Loaded";
			// 
			// ROrdinance1ValueLabel
			// 
			this->ROrdinance1ValueLabel->AutoSize = true;
			this->ROrdinance1ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->ROrdinance1ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ROrdinance1ValueLabel->Location = System::Drawing::Point(250, 236);
			this->ROrdinance1ValueLabel->Name = L"ROrdinance1ValueLabel";
			this->ROrdinance1ValueLabel->Size = System::Drawing::Size(81, 13);
			this->ROrdinance1ValueLabel->TabIndex = 99;
			this->ROrdinance1ValueLabel->Text = L"None Loaded";
			// 
			// RWeapon4ValueLabel
			// 
			this->RWeapon4ValueLabel->AutoSize = true;
			this->RWeapon4ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RWeapon4ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RWeapon4ValueLabel->Location = System::Drawing::Point(250, 223);
			this->RWeapon4ValueLabel->Name = L"RWeapon4ValueLabel";
			this->RWeapon4ValueLabel->Size = System::Drawing::Size(81, 13);
			this->RWeapon4ValueLabel->TabIndex = 98;
			this->RWeapon4ValueLabel->Text = L"None Loaded";
			// 
			// RWeapon3ValueLabel
			// 
			this->RWeapon3ValueLabel->AutoSize = true;
			this->RWeapon3ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RWeapon3ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RWeapon3ValueLabel->Location = System::Drawing::Point(250, 210);
			this->RWeapon3ValueLabel->Name = L"RWeapon3ValueLabel";
			this->RWeapon3ValueLabel->Size = System::Drawing::Size(81, 13);
			this->RWeapon3ValueLabel->TabIndex = 97;
			this->RWeapon3ValueLabel->Text = L"None Loaded";
			// 
			// RWeapon2ValueLabel
			// 
			this->RWeapon2ValueLabel->AutoSize = true;
			this->RWeapon2ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RWeapon2ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RWeapon2ValueLabel->Location = System::Drawing::Point(250, 197);
			this->RWeapon2ValueLabel->Name = L"RWeapon2ValueLabel";
			this->RWeapon2ValueLabel->Size = System::Drawing::Size(81, 13);
			this->RWeapon2ValueLabel->TabIndex = 96;
			this->RWeapon2ValueLabel->Text = L"None Loaded";
			// 
			// RWeapon1ValueLabel
			// 
			this->RWeapon1ValueLabel->AutoSize = true;
			this->RWeapon1ValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RWeapon1ValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RWeapon1ValueLabel->Location = System::Drawing::Point(250, 184);
			this->RWeapon1ValueLabel->Name = L"RWeapon1ValueLabel";
			this->RWeapon1ValueLabel->Size = System::Drawing::Size(81, 13);
			this->RWeapon1ValueLabel->TabIndex = 95;
			this->RWeapon1ValueLabel->Text = L"None Loaded";
			// 
			// RDroidValueLabel
			// 
			this->RDroidValueLabel->AutoSize = true;
			this->RDroidValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RDroidValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RDroidValueLabel->Location = System::Drawing::Point(250, 171);
			this->RDroidValueLabel->Name = L"RDroidValueLabel";
			this->RDroidValueLabel->Size = System::Drawing::Size(81, 13);
			this->RDroidValueLabel->TabIndex = 94;
			this->RDroidValueLabel->Text = L"None Loaded";
			// 
			// RBoosterValueLabel
			// 
			this->RBoosterValueLabel->AutoSize = true;
			this->RBoosterValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RBoosterValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RBoosterValueLabel->Location = System::Drawing::Point(250, 158);
			this->RBoosterValueLabel->Name = L"RBoosterValueLabel";
			this->RBoosterValueLabel->Size = System::Drawing::Size(81, 13);
			this->RBoosterValueLabel->TabIndex = 93;
			this->RBoosterValueLabel->Text = L"None Loaded";
			// 
			// RCapacitorValueLabel
			// 
			this->RCapacitorValueLabel->AutoSize = true;
			this->RCapacitorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RCapacitorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RCapacitorValueLabel->Location = System::Drawing::Point(250, 145);
			this->RCapacitorValueLabel->Name = L"RCapacitorValueLabel";
			this->RCapacitorValueLabel->Size = System::Drawing::Size(81, 13);
			this->RCapacitorValueLabel->TabIndex = 92;
			this->RCapacitorValueLabel->Text = L"None Loaded";
			// 
			// REngineValueLabel
			// 
			this->REngineValueLabel->AutoSize = true;
			this->REngineValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->REngineValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->REngineValueLabel->Location = System::Drawing::Point(250, 131);
			this->REngineValueLabel->Name = L"REngineValueLabel";
			this->REngineValueLabel->Size = System::Drawing::Size(81, 13);
			this->REngineValueLabel->TabIndex = 91;
			this->REngineValueLabel->Text = L"None Loaded";
			// 
			// RReactorValueLabel
			// 
			this->RReactorValueLabel->AutoSize = true;
			this->RReactorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RReactorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RReactorValueLabel->Location = System::Drawing::Point(250, 118);
			this->RReactorValueLabel->Name = L"RReactorValueLabel";
			this->RReactorValueLabel->Size = System::Drawing::Size(81, 13);
			this->RReactorValueLabel->TabIndex = 90;
			this->RReactorValueLabel->Text = L"None Loaded";
			// 
			// AdjustLabel
			// 
			this->AdjustLabel->AutoSize = true;
			this->AdjustLabel->BackColor = System::Drawing::Color::Transparent;
			this->AdjustLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->AdjustLabel->Location = System::Drawing::Point(6, 11);
			this->AdjustLabel->Name = L"AdjustLabel";
			this->AdjustLabel->Size = System::Drawing::Size(80, 13);
			this->AdjustLabel->TabIndex = 103;
			this->AdjustLabel->Text = L"Adjust Used:";
			// 
			// AdjustValueLabel
			// 
			this->AdjustValueLabel->AutoSize = true;
			this->AdjustValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->AdjustValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->AdjustValueLabel->Location = System::Drawing::Point(92, 11);
			this->AdjustValueLabel->Name = L"AdjustValueLabel";
			this->AdjustValueLabel->Size = System::Drawing::Size(36, 13);
			this->AdjustValueLabel->TabIndex = 104;
			this->AdjustValueLabel->Text = L"None";
			// 
			// CloseButton
			// 
			this->CloseButton->ForeColor = System::Drawing::Color::Black;
			this->CloseButton->Location = System::Drawing::Point(139, 335);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 105;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &ProtectionStatsForm::CloseButton_Click);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->AdjustLabel);
			this->panel1->Controls->Add(this->AdjustValueLabel);
			this->panel1->Controls->Add(this->ReactorLabel);
			this->panel1->Controls->Add(this->EngineLabel);
			this->panel1->Controls->Add(this->RCountermeasuresValueLabel);
			this->panel1->Controls->Add(this->CapacitorStatusLabel);
			this->panel1->Controls->Add(this->ROrdinance3ValueLabel);
			this->panel1->Controls->Add(this->BoosterLabel);
			this->panel1->Controls->Add(this->ROrdinance2ValueLabel);
			this->panel1->Controls->Add(this->DriodLabel);
			this->panel1->Controls->Add(this->ROrdinance1ValueLabel);
			this->panel1->Controls->Add(this->Weapon1Label);
			this->panel1->Controls->Add(this->RWeapon4ValueLabel);
			this->panel1->Controls->Add(this->Weapon2Label);
			this->panel1->Controls->Add(this->RWeapon3ValueLabel);
			this->panel1->Controls->Add(this->Weapon3Label);
			this->panel1->Controls->Add(this->RWeapon2ValueLabel);
			this->panel1->Controls->Add(this->Weapon4Label);
			this->panel1->Controls->Add(this->RWeapon1ValueLabel);
			this->panel1->Controls->Add(this->Ordinance1Label);
			this->panel1->Controls->Add(this->RDroidValueLabel);
			this->panel1->Controls->Add(this->Ordinance2Label);
			this->panel1->Controls->Add(this->RBoosterValueLabel);
			this->panel1->Controls->Add(this->Ordinance3Label);
			this->panel1->Controls->Add(this->RCapacitorValueLabel);
			this->panel1->Controls->Add(this->CountermeasuresLabel);
			this->panel1->Controls->Add(this->REngineValueLabel);
			this->panel1->Controls->Add(this->SheildandArmorLabel);
			this->panel1->Controls->Add(this->RReactorValueLabel);
			this->panel1->Controls->Add(this->ArmorLabel);
			this->panel1->Controls->Add(this->RSheildandArmorValueLabel);
			this->panel1->Controls->Add(this->SheildingLabel);
			this->panel1->Controls->Add(this->RArmorValueLabel);
			this->panel1->Controls->Add(this->CompProtectionsLabel);
			this->panel1->Controls->Add(this->RSheildingValueLabel);
			this->panel1->Controls->Add(this->FReactorValueLabel);
			this->panel1->Controls->Add(this->FSheildandArmorValueLabel);
			this->panel1->Controls->Add(this->FEngineValueLabel);
			this->panel1->Controls->Add(this->FArmorValueLabel);
			this->panel1->Controls->Add(this->FCapacitorValueLabel);
			this->panel1->Controls->Add(this->FSheildingValueLabel);
			this->panel1->Controls->Add(this->FBoosterValueLabel);
			this->panel1->Controls->Add(this->BackLabel);
			this->panel1->Controls->Add(this->FDroidValueLabel);
			this->panel1->Controls->Add(this->FrontLabel);
			this->panel1->Controls->Add(this->FWeapon1ValueLabel);
			this->panel1->Controls->Add(this->FCountermeasuresValueLabel);
			this->panel1->Controls->Add(this->FWeapon2ValueLabel);
			this->panel1->Controls->Add(this->FOrdinance3ValueLabel);
			this->panel1->Controls->Add(this->FWeapon3ValueLabel);
			this->panel1->Controls->Add(this->FOrdinance2ValueLabel);
			this->panel1->Controls->Add(this->FWeapon4ValueLabel);
			this->panel1->Controls->Add(this->FOrdinance1ValueLabel);
			this->panel1->Location = System::Drawing::Point(7, 32);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(338, 298);
			this->panel1->TabIndex = 106;
			// 
			// ProtectionStatsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->ClientSize = System::Drawing::Size(352, 370);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->ProtectionStatsFormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ProtectionStatsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Protection Statistics";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void RetriveValues(Reactor^ loadedReactor, Engine^ loadedEngine, Booster^ loadedBooster, Sheild^ loadedSheild, 
			Droid^ loadedDroid, Capacitor^ loadedCapacitor, Armor^ loadedFArmor, Armor^ loadedRArmor, Ordinance^ loadedOrdinance1, 
			Ordinance^ loadedOrdinance2, Ordinance^ loadedOrdinance3, Weapon^ loadedWeapon1, Weapon^ loadedWeapon2, Weapon^ loadedWeapon3, 
			Weapon^ loadedWeapon4, Chaff^ loadedChaff){
				// Reactor
				System::Data::DataRow^ rowReactor;

				Reactor^ tempReactor = gcnew Reactor();
				tempReactor = loadedReactor;
				rowReactor = tempReactor[0];

				loadedReactorArmor = Convert::ToDouble(rowReactor["Armor"]->ToString());

				// Engine
				System::Data::DataRow^ rowEngine;

				Engine^ tempEngine = gcnew Engine();
				tempEngine = loadedEngine;
				rowEngine = tempEngine[0];

				loadedEngineArmor = Convert::ToDouble(rowEngine["Armor"]->ToString());

				// Booster
				System::Data::DataRow^ rowBooster;

				Booster^ tempBooster = gcnew Booster();
				tempBooster = loadedBooster;
				rowBooster = tempBooster[0];

				loadedBoosterArmor = Convert::ToDouble(rowBooster["Armor"]->ToString());

				// Sheild
				System::Data::DataRow^ rowSheild;

				Sheild^ tempSheild = gcnew Sheild();
				tempSheild = loadedSheild;
				rowSheild = tempSheild[0];

				loadedSheildArmor = Convert::ToDouble(rowSheild["Armor"]->ToString());
				adjustmentUsedIndex = Convert::ToInt32(rowSheild["Adjustment"]->ToString());
				sheildFrontHP = Convert::ToDouble(rowSheild["Front HP"]->ToString());
				sheildBackHP = Convert::ToDouble(rowSheild["Back HP"]->ToString());

				switch (adjustmentUsedIndex)
				{
				case 0: adjustmentUsed = "Front Extreme";
					break;
				case 1: adjustmentUsed = "Front Heavy";
					break;
				case 2: adjustmentUsed = "Front Moderate";
					break;
				case 3: adjustmentUsed = "Front Light";
					break;
				case 4: adjustmentUsed = "None";
					break;
				case 5: adjustmentUsed = "Rear Light";
					break;
				case 6: adjustmentUsed = "Rear Moderate";
					break;
				case 7: adjustmentUsed = "Rear Heavy";
					break;
				case 8: adjustmentUsed = "Rear Extreme";
					break;
				}

				// Droid
				System::Data::DataRow^ rowDroid;

				Droid^ tempDroid = gcnew Droid();
				tempDroid = loadedDroid;
				rowDroid = tempDroid[0];

				loadedDroidArmor = Convert::ToDouble(rowDroid["Armor"]->ToString());

				// Capacitor
				System::Data::DataRow^ rowCapacitor;

				Capacitor^ tempCapacitor = gcnew Capacitor();
				tempCapacitor = loadedCapacitor;
				rowCapacitor = tempCapacitor[0];

				loadedCapacitorArmor = Convert::ToDouble(rowCapacitor["Armor"]->ToString());

				// Front Armor
				System::Data::DataRow^ rowFArmor;

				Armor^ tempFArmor = gcnew Armor();
				tempFArmor = loadedFArmor;
				rowFArmor = tempFArmor[0];

				loadedFArmorArmor = Convert::ToDouble(rowFArmor["Armor"]->ToString());

				// Rear Armor
				System::Data::DataRow^ rowRArmor;

				Armor^ tempRArmor = gcnew Armor();
				tempRArmor = loadedRArmor;
				rowRArmor = tempRArmor[0];

				loadedRArmorArmor = Convert::ToDouble(rowRArmor["Armor"]->ToString());

				// Ordinance 1
				System::Data::DataRow^ rowOrdinance1;

				Ordinance^ tempOrdinance1 = gcnew Ordinance();
				tempOrdinance1 = loadedOrdinance1;
				rowOrdinance1 = tempOrdinance1[0];

				loadedOrdinance1Armor = Convert::ToDouble(rowOrdinance1["Armor"]->ToString());

				// Ordinance 2
				System::Data::DataRow^ rowOrdinance2;

				Ordinance^ tempOrdinance2 = gcnew Ordinance();
				tempOrdinance2 = loadedOrdinance2;
				rowOrdinance2 = tempOrdinance2[0];

				loadedOrdinance2Armor = Convert::ToDouble(rowOrdinance2["Armor"]->ToString());

				// Ordinance 3
				System::Data::DataRow^ rowOrdinance3;

				Ordinance^ tempOrdinance3 = gcnew Ordinance();
				tempOrdinance3 = loadedOrdinance3;
				rowOrdinance3 = tempOrdinance3[0];

				loadedOrdinance3Armor = Convert::ToDouble(rowOrdinance3["Armor"]->ToString());

				// Weapon 1
				System::Data::DataRow^ rowWeapon1;

				Weapon^ tempWeapon1 = gcnew Weapon();
				tempWeapon1 = loadedWeapon1;
				rowWeapon1 = tempWeapon1[0];

				loadedWeapon1Armor = Convert::ToDouble(rowWeapon1["Armor"]->ToString());

				// Weapon 2
				System::Data::DataRow^ rowWeapon2;

				Weapon^ tempWeapon2 = gcnew Weapon();
				tempWeapon2= loadedWeapon2;
				rowWeapon2 = tempWeapon2[0];

				loadedWeapon2Armor = Convert::ToDouble(rowWeapon2["Armor"]->ToString());

				// Weapon 3
				System::Data::DataRow^ rowWeapon3;

				Weapon^ tempWeapon3 = gcnew Weapon();
				tempWeapon3 = loadedWeapon3;
				rowWeapon3 = tempWeapon3[0];

				loadedWeapon3Armor = Convert::ToDouble(rowWeapon3["Armor"]->ToString());

				// Weapon 4
				System::Data::DataRow^ rowWeapon4;

				Weapon^ tempWeapon4 = gcnew Weapon();
				tempWeapon4 = loadedWeapon4;
				rowWeapon4 = tempWeapon4[0];

				loadedWeapon4Armor = Convert::ToDouble(rowWeapon4["Armor"]->ToString());

				// Chaff
				System::Data::DataRow^ rowChaff;

				Chaff^ tempChaff = gcnew Chaff();
				tempChaff = loadedChaff;
				rowChaff = tempChaff[0];

				loadedChaffArmor = Convert::ToDouble(rowChaff["Armor"]->ToString());
		 }
private: System::Void CalculateTotalProtections(){
			 AdjustValueLabel->Text = adjustmentUsed;

			 if (sheildFrontHP != 0)
			 {
				 switch (adjustmentUsedIndex)
				 {
				 case 0: fSheilding = (sheildFrontHP * 1.90);
						 rSheilding = (sheildBackHP * 0.10);
					 break;
				 case 1: fSheilding = (sheildFrontHP * 1.75);
						 rSheilding = (sheildBackHP * 0.25);
					 break;
				 case 2: fSheilding = (sheildFrontHP * 1.50);
						 rSheilding = (sheildBackHP * 0.50);
					 break;
				 case 3: fSheilding = (sheildFrontHP * 1.20);
						 rSheilding = (sheildBackHP * 0.80);
					 break;
				 case 4: fSheilding = (sheildFrontHP * 1.00);
						 rSheilding = (sheildBackHP * 1.00);
					 break;
				 case 5: fSheilding = (sheildFrontHP * 0.80);
						 rSheilding = (sheildBackHP * 1.20);
					 break;
				 case 6: fSheilding = (sheildFrontHP * 0.50);
						 rSheilding = (sheildBackHP * 1.50);
					 break;
				 case 7: fSheilding = (sheildFrontHP * 0.25);
						 rSheilding = (sheildBackHP * 1.75);
					 break;
				 case 8: fSheilding = (sheildFrontHP * 0.10);
						 rSheilding = (sheildBackHP * 1.90);
					 break;
				 }

				 FSheildingValueLabel->Text = fSheilding.ToString(".##");
				 RSheildingValueLabel->Text = rSheilding.ToString(".##");
			 }
			 else
			 {
				 fSheilding = 0;
				 rSheilding = 0;

				 FSheildingValueLabel->Text = "None Loaded";
				 RSheildingValueLabel->Text = "None Loaded";
			 }

			 if (loadedFArmorArmor != 0)
			 {
				FArmorValueLabel->Text = loadedFArmorArmor.ToString(".##");
			 }
			 else
			 {
				FArmorValueLabel->Text = "None Loaded";
			 }
			 if (loadedRArmorArmor != 0)
			 {
				RArmorValueLabel->Text = loadedRArmorArmor.ToString(".##");
			 }
			 else
			 {
				RArmorValueLabel->Text = "None Loaded";
			 }

			 totalFront = (loadedFArmorArmor + fSheilding);
			 totalRear = (loadedRArmorArmor + rSheilding);

			 if (totalFront != 0)
			 {
				 FSheildandArmorValueLabel->Text = totalFront.ToString(".##");
			 }
			 else
			 {
				 FSheildandArmorValueLabel->Text = "None Loaded";
			 }
			 if (totalRear != 0)
			 {
				 RSheildandArmorValueLabel->Text = totalRear.ToString(".##");
			 }
			 else
			 {
				 RSheildandArmorValueLabel->Text = "None Loaded";
			 }
		 }
private: System::Void CalculateFrontCompProtections(){
			 FReactorValueLabel->Text = (totalFront + loadedReactorArmor).ToString(".##");
			 FEngineValueLabel->Text = (totalFront + loadedEngineArmor).ToString(".##");

			 // Booster
			 if (loadedBoosterArmor != 0)
			 {
				 FBoosterValueLabel->Text = (totalFront + loadedBoosterArmor).ToString(".##");
			 }
			 else
			 {
				 FBoosterValueLabel->Text = "None Loaded";
			 }

			 // Droid
			 if (loadedDroidArmor != 0)
			 {
				 FDroidValueLabel->Text = (totalFront + loadedDroidArmor).ToString(".##");
			 }
			 else
			 {
				 FDroidValueLabel->Text = "None Loaded";
			 }

			 // Capactior
			 if (loadedCapacitorArmor != 0)
			 {
				 FCapacitorValueLabel->Text = (totalFront + loadedCapacitorArmor).ToString(".##");
			 }
			 else
			 {
				 FCapacitorValueLabel->Text = "None Loaded";
			 }

			 // Ordinance 1
			 if (loadedOrdinance1Armor != 0)
			 {
				 FOrdinance1ValueLabel->Text = (totalFront + loadedOrdinance1Armor).ToString(".##");
			 }
			 else
			 {
				 FOrdinance1ValueLabel->Text = "None Loaded";
			 }

			 // Ordinance 2
			 if (loadedOrdinance2Armor != 0)
			 {
				 FOrdinance2ValueLabel->Text = (totalFront + loadedOrdinance2Armor).ToString(".##");
			 }
			 else
			 {
				 FOrdinance2ValueLabel->Text = "None Loaded";
			 }

			 // Ordinance 3
			 if (loadedOrdinance3Armor != 0)
			 {
				 FOrdinance3ValueLabel->Text = (totalFront + loadedOrdinance3Armor).ToString(".##");
			 }
			 else
			 {
				 FOrdinance3ValueLabel->Text = "None Loaded";
			 }

			 // Weapon 1
			 if (loadedWeapon1Armor != 0)
			 {
				 FWeapon1ValueLabel->Text = (totalFront + loadedWeapon1Armor).ToString(".##");
			 }
			 else
			 {
				 FWeapon1ValueLabel->Text = "None Loaded";
			 }

			 // Weapon 2
			 if (loadedWeapon2Armor != 0)
			 {
				 FWeapon2ValueLabel->Text = (totalFront + loadedWeapon2Armor).ToString(".##");
			 }
			 else
			 {
				 FWeapon2ValueLabel->Text = "None Loaded";
			 }

			 // Weapon 3
			 if (loadedWeapon3Armor != 0)
			 {
				 FWeapon3ValueLabel->Text = (totalFront + loadedWeapon3Armor).ToString(".##");
			 }
			 else
			 {
				 FWeapon3ValueLabel->Text = "None Loaded";
			 }

			 // Weapon 4
			 if (loadedWeapon4Armor != 0)
			 {
				 FWeapon4ValueLabel->Text = (totalFront + loadedWeapon4Armor).ToString(".##");
			 }
			 else
			 {
				 FWeapon4ValueLabel->Text = "None Loaded";
			 }

			 // Chaff
			 if (loadedChaffArmor != 0)
			 {
				 FCountermeasuresValueLabel->Text = (totalFront + loadedChaffArmor).ToString(".##");
			 }
			 else
			 {
				 FCountermeasuresValueLabel->Text = "None Loaded";
			 }
		 }
private: System::Void CalculateRearCompProtections(){
			 RReactorValueLabel->Text = (totalRear + loadedReactorArmor).ToString(".##");
			 REngineValueLabel->Text = (totalRear + loadedEngineArmor).ToString(".##");

			 // Booster
			 if (loadedBoosterArmor != 0)
			 {
				 RBoosterValueLabel->Text = (totalRear + loadedBoosterArmor).ToString(".##");
			 }
			 else
			 {
				 RBoosterValueLabel->Text = "None Loaded";
			 }

			 // Droid
			 if (loadedDroidArmor != 0)
			 {
				 RDroidValueLabel->Text = (totalRear + loadedDroidArmor).ToString(".##");
			 }
			 else
			 {
				 RDroidValueLabel->Text = "None Loaded";
			 }

			 // Capactior
			 if (loadedCapacitorArmor != 0)
			 {
				 RCapacitorValueLabel->Text = (totalRear + loadedCapacitorArmor).ToString(".##");
			 }
			 else
			 {
				 RCapacitorValueLabel->Text = "None Loaded";
			 }

			 // Ordinance 1
			 if (loadedOrdinance1Armor != 0)
			 {
				 ROrdinance1ValueLabel->Text = (totalRear + loadedOrdinance1Armor).ToString(".##");
			 }
			 else
			 {
				 ROrdinance1ValueLabel->Text = "None Loaded";
			 }

			 // Ordinance 2
			 if (loadedOrdinance2Armor != 0)
			 {
				 ROrdinance2ValueLabel->Text = (totalRear + loadedOrdinance2Armor).ToString(".##");
			 }
			 else
			 {
				 ROrdinance2ValueLabel->Text = "None Loaded";
			 }

			 // Ordinance 3
			 if (loadedOrdinance3Armor != 0)
			 {
				 ROrdinance3ValueLabel->Text = (totalRear + loadedOrdinance3Armor).ToString(".##");
			 }
			 else
			 {
				 ROrdinance3ValueLabel->Text = "None Loaded";
			 }

			 // Weapon 1
			 if (loadedWeapon1Armor != 0)
			 {
				 RWeapon1ValueLabel->Text = (totalRear + loadedWeapon1Armor).ToString(".##");
			 }
			 else
			 {
				 RWeapon1ValueLabel->Text = "None Loaded";
			 }

			 // Weapon 2
			 if (loadedWeapon2Armor != 0)
			 {
				 RWeapon2ValueLabel->Text = (totalRear + loadedWeapon2Armor).ToString(".##");
			 }
			 else
			 {
				 RWeapon2ValueLabel->Text = "None Loaded";
			 }

	
			 // Weapon 3
			 if (loadedWeapon3Armor != 0)
			 {
				 RWeapon3ValueLabel->Text = (totalRear + loadedWeapon3Armor).ToString(".##");
			 }
			 else
			 {
				 RWeapon3ValueLabel->Text = "None Loaded";
			 }

			 // Weapon 4
			 if (loadedWeapon4Armor != 0)
			 {
				 RWeapon4ValueLabel->Text = (totalRear + loadedWeapon4Armor).ToString(".##");
			 }
			 else
			 {
				 RWeapon4ValueLabel->Text = "None Loaded";
			 }

			 // Chaff
			 if (loadedChaffArmor != 0)
			 {
				 RCountermeasuresValueLabel->Text = (totalRear + loadedChaffArmor).ToString(".##");
			 }
			 else
			 {
				 RCountermeasuresValueLabel->Text = "None Loaded";
			 }
		 }
private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
};
}
