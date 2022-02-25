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
	/// Summary for WeaponStatsForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class WeaponStatsForm : public System::Windows::Forms::Form
	{
	public:
		WeaponStatsForm(void)
		{
			InitializeComponent();

			Weapon1GroupBox->ForeColor = Color::White;
			Weapon2GroupBox->ForeColor = Color::White;
			Weapon3GroupBox->ForeColor = Color::White;
			Weapon4GroupBox->ForeColor = Color::White;
			TotalsGroupBox->ForeColor = Color::White;
			//
			//TODO: Add the constructor code here
			//
		}

		WeaponStatsForm(Weapon^ loadedWeapon1, Weapon^ loadedWeapon2, Weapon^ loadedWeapon3, Weapon^ loadedWeapon4,
			Capacitor^ loadedCapacitor, int selectedWeaponOverload, int selectedCapacitorOverload)
		{
			InitializeComponent();

			Weapon1GroupBox->ForeColor = Color::White;
			Weapon2GroupBox->ForeColor = Color::White;
			Weapon3GroupBox->ForeColor = Color::White;
			Weapon4GroupBox->ForeColor = Color::White;
			TotalsGroupBox->ForeColor = Color::White;

			CalculateWeapon1Damages(loadedWeapon1, selectedWeaponOverload);
			CalculateWeapon2Damages(loadedWeapon2, selectedWeaponOverload);
			CalculateWeapon3Damages(loadedWeapon3, selectedWeaponOverload);
			CalculateWeapon4Damages(loadedWeapon4, selectedWeaponOverload);

			SetWeapon1Zero(loadedWeapon1);
			SetWeapon2Zero(loadedWeapon2);
			SetWeapon3Zero(loadedWeapon3);
			SetWeapon4Zero(loadedWeapon4);

			CalculateTotals();
			CalculateAverageDmg(selectedWeaponOverload);
			CalculateCapacitorValues(loadedCapacitor, selectedCapacitorOverload);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WeaponStatsForm()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region WeaponStatsForm Item Declarations

	private: System::Windows::Forms::Label^  WeaponStatsFormLabel;

	private: System::Windows::Forms::Label^  Weapon1OverloadedLabel;
	private: System::Windows::Forms::Label^  W1_MinDvsSLabel;
	private: System::Windows::Forms::Label^  W1_MinDvsALabel;
	private: System::Windows::Forms::Label^  W1_MaxDvsSLabel;
	private: System::Windows::Forms::Label^  W1_PvPMinDvsSLabel;
	private: System::Windows::Forms::Label^  W1_PvPDamageLabel;
	private: System::Windows::Forms::Label^  W1_EPSLabel;
	private: System::Windows::Forms::Label^  W1_MaxDvsALabel;
	private: System::Windows::Forms::Label^  W1_PvPMaxDvsSLabel;
	private: System::Windows::Forms::Label^  W1_PvPMaxDvsALabel;
	private: System::Windows::Forms::Label^  W1_PvPMinDvsA;
	private: System::Windows::Forms::Label^  W1_MinDvsSValueLabel;
	private: System::Windows::Forms::Label^  W1_MaxDvsSValueLabel;
	private: System::Windows::Forms::Label^  W1_MaxDvsAValueLabel;
	private: System::Windows::Forms::Label^  W1_MinDvsAValueLabel;
	private: System::Windows::Forms::Label^  W1_PvPMaxDvsAValueLabel;
	private: System::Windows::Forms::Label^  W1_PvPMinDvsAValueLabel;
	private: System::Windows::Forms::Label^  W1_PvPMaxDvsSValueLabel;
	private: System::Windows::Forms::Label^  W1_PvPMinDvsSValueLabel;
	private: System::Windows::Forms::Label^  W1_EPSValueLabel;

	private: System::Windows::Forms::Label^  W2_EPSValueLabel;
	private: System::Windows::Forms::Label^  W2_PvPMaxDvsAValueLabel;
	private: System::Windows::Forms::Label^  W2_PvPMinDvsAValueLabel;
	private: System::Windows::Forms::Label^  W2_PvPMaxDvsSValueLabel;
	private: System::Windows::Forms::Label^  W2_PvPMinDvsSValueLabel;
	private: System::Windows::Forms::Label^  W2_MaxDvsAValueLabel;
	private: System::Windows::Forms::Label^  W2_MinDvsAValueLabel;
	private: System::Windows::Forms::Label^  W2_MaxDvsSValueLabel;
	private: System::Windows::Forms::Label^  W2_MinDvsSValueLabel;
	private: System::Windows::Forms::Label^  W2_PvPMaxDvsSLabel;
	private: System::Windows::Forms::Label^  W2_PvPMaxDvsALabel;
	private: System::Windows::Forms::Label^  W2_PvPMinDvsALabel;
	private: System::Windows::Forms::Label^  W2_PvPMinDvsSLabel;
	private: System::Windows::Forms::Label^  W2_PvPDamageLabel;
	private: System::Windows::Forms::Label^  W2_EPSLabel;
	private: System::Windows::Forms::Label^  W2_MaxDvsALabel;
	private: System::Windows::Forms::Label^  W2_MinDvsALabel;
	private: System::Windows::Forms::Label^  W2_MaxDvsSLabel;
	private: System::Windows::Forms::Label^  W2_MinDvsSLabel;
	private: System::Windows::Forms::Label^  Weapon2OverloadedLabel;
	private: System::Windows::Forms::Label^  W3_EPSValueLabel;


	private: System::Windows::Forms::Label^  W3_PvPMaxDvsAValueLabel;
	private: System::Windows::Forms::Label^  W3_PvPMinDvsAValueLabel;
	private: System::Windows::Forms::Label^  W3_PvPMaxDvsSValueLabel;
	private: System::Windows::Forms::Label^  W3_PvPMinDvsSValueLabel;
	private: System::Windows::Forms::Label^  W3_MaxDvsAValueLabel;

	private: System::Windows::Forms::Label^  W3_MinDvsAValueLabel;
	private: System::Windows::Forms::Label^  W3_MaxDvsSValueLabel;
	private: System::Windows::Forms::Label^  W3_MinDvsSValueLabel;
	private: System::Windows::Forms::Label^  W3_PvPMaxDvsSLabel;
	private: System::Windows::Forms::Label^  W3_PvPMaxDvsALabel;
	private: System::Windows::Forms::Label^  W3_PvPMinDvsALabel;
	private: System::Windows::Forms::Label^  W3_PvPMinDvsSLabel;
	private: System::Windows::Forms::Label^  W3_PvPDamageLabel;
	private: System::Windows::Forms::Label^  W3_EPSLabel;
	private: System::Windows::Forms::Label^  W3_MaxDvsALabel;
	private: System::Windows::Forms::Label^  W3_MinDvsALabel;
	private: System::Windows::Forms::Label^  W3_MaxDvsSLabel;
	private: System::Windows::Forms::Label^  W3_MinDvsSLabel;
	private: System::Windows::Forms::Label^  Weapon3OverloadedLabel;

	private: System::Windows::Forms::Label^  W4_EPSValueLabel;
	private: System::Windows::Forms::Label^  W4_PvPMaxDvsAValueLabel;
	private: System::Windows::Forms::Label^  W4_PvPMinDvsAValueLabel;
	private: System::Windows::Forms::Label^  W4_PvPMaxDvsSValueLabel;
	private: System::Windows::Forms::Label^  W4_PvPMinDvsSValueLabel;
	private: System::Windows::Forms::Label^  W4_MaxDvsAValueLabel;
	private: System::Windows::Forms::Label^  W4_MinDvsAValueLabel;
	private: System::Windows::Forms::Label^  W4_MaxDvsSValueLabel;
	private: System::Windows::Forms::Label^  W4_MinDvsSValueLabel;
	private: System::Windows::Forms::Label^  W4_PvPMaxDvsSLabel;
	private: System::Windows::Forms::Label^  W4_PvPMaxDvsALabel;
	private: System::Windows::Forms::Label^  W4_PvPMinDvsALabel;
	private: System::Windows::Forms::Label^  W4_PvPMinDvsSLabel;
	private: System::Windows::Forms::Label^  W4_PvPDamageLabel;
	private: System::Windows::Forms::Label^  W4_EPSLabel;
	private: System::Windows::Forms::Label^  W4_MaxDvsALabel;
	private: System::Windows::Forms::Label^  W4_MinDvsALabel;
	private: System::Windows::Forms::Label^  W4_MaxDvsSLabel;
	private: System::Windows::Forms::Label^  W4_MinDvsSLabel;
	private: System::Windows::Forms::Label^  Weapon4OverloadedLabel;

	private: System::Windows::Forms::Label^  TotalEPSValueLabel;
	private: System::Windows::Forms::Label^  TotalPvPMaxDvsAValueLabel;
	private: System::Windows::Forms::Label^  TotalPvPMinDvsAValueLabel;
	private: System::Windows::Forms::Label^  TotalPvPMaxDvsSValueLabel;
	private: System::Windows::Forms::Label^  TotalPvPMinDvsSValueLabel;

	private: System::Windows::Forms::Label^  TotalMaxDvsAValueLabel;
	private: System::Windows::Forms::Label^  TotalMinDvsAValueLabel;
	private: System::Windows::Forms::Label^  TotalMaxDvsSValueLabel;
	private: System::Windows::Forms::Label^  TotalMinDvsSValueLabel;

	private: System::Windows::Forms::Label^  TotalPvPMaxDvsSLabel;
	private: System::Windows::Forms::Label^  TotalPvPMaxDvsALabel;
	private: System::Windows::Forms::Label^  TotalPvPMinDvsALabel;
	private: System::Windows::Forms::Label^  TotalPvPMinDvsSLabel;
	private: System::Windows::Forms::Label^  TotalPvPDamageLabel;

	private: System::Windows::Forms::Label^  TotalEPSLabel;
	private: System::Windows::Forms::Label^  TotalMaxDvsALabel;
	private: System::Windows::Forms::Label^  TotalMinDvsALabel;
	private: System::Windows::Forms::Label^  TotalMaxDvsSLabel;
	private: System::Windows::Forms::Label^  TotalMinDvsSLabel;


	private: System::Windows::Forms::Button^  CloseButton;
private: System::Windows::Forms::Label^  OCapRechargeTimeLabel;


private: System::Windows::Forms::Label^  OCapRechargeTimeValueLabel;

	private: System::Windows::Forms::Label^  OCapEnergyLabel;
	private: System::Windows::Forms::Label^  OCapEnergyValueLabel;
	private: System::Windows::Forms::Label^  OCapFullFireTimeLabel;
	private: System::Windows::Forms::Label^  OCapFullFireTimeValueLabel;
	private: System::Windows::Forms::Label^  AvDmgPerShotValueLabel;
	private: System::Windows::Forms::Label^  AvDmgPerShotLabel;
	private: System::Windows::Forms::Label^  AvDmgPerSecondValueLabel;
	private: System::Windows::Forms::Label^  AvDmgPerSecondLabel;
	private: System::Windows::Forms::GroupBox^  Weapon1GroupBox;
	private: System::Windows::Forms::GroupBox^  Weapon3GroupBox;
	private: System::Windows::Forms::GroupBox^  Weapon2GroupBox;
	private: System::Windows::Forms::GroupBox^  Weapon4GroupBox;
	private: System::Windows::Forms::GroupBox^  TotalsGroupBox;



	protected: 
	protected: 

#pragma endregion
	
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private:
		static double weapon1Refire = 0;
		static double weapon1EPS = 0;
		static double weapon1MinD = 0;
		static double weapon1MaxD = 0;
		static double weapon1vsS = 0;
		static double weapon1vsA = 0;

		static double weapon2Refire = 0;
		static double weapon2EPS = 0;
		static double weapon2MinD = 0;
		static double weapon2MaxD = 0;
		static double weapon2vsS = 0;
		static double weapon2vsA = 0;

		static double weapon3Refire = 0;
		static double weapon3EPS = 0;
		static double weapon3MinD = 0;
		static double weapon3MaxD = 0;
		static double weapon3vsS = 0;
		static double weapon3vsA = 0;

		static double weapon4Refire = 0;
		static double weapon4EPS = 0;
		static double weapon4MinD = 0;
		static double weapon4MaxD = 0;
		static double weapon4vsS = 0;
		static double weapon4vsA = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(WeaponStatsForm::typeid));
			this->WeaponStatsFormLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon1OverloadedLabel = (gcnew System::Windows::Forms::Label());
			this->W1_MinDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W1_MinDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W1_MaxDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W1_PvPMinDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W1_PvPDamageLabel = (gcnew System::Windows::Forms::Label());
			this->W1_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->W1_MaxDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W1_PvPMaxDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W1_PvPMaxDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W1_PvPMinDvsA = (gcnew System::Windows::Forms::Label());
			this->W1_MinDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_MaxDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_MaxDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_MinDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_PvPMaxDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_PvPMinDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_PvPMaxDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_PvPMinDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_EPSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_EPSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_PvPMaxDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_PvPMinDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_PvPMaxDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_PvPMinDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MaxDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MinDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MaxDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MinDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_PvPMaxDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W2_PvPMaxDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W2_PvPMinDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W2_PvPMinDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W2_PvPDamageLabel = (gcnew System::Windows::Forms::Label());
			this->W2_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MaxDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W2_MinDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W2_MaxDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MinDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon2OverloadedLabel = (gcnew System::Windows::Forms::Label());
			this->W3_EPSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_PvPMaxDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_PvPMinDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_PvPMaxDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_PvPMinDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MaxDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MinDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MaxDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MinDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_PvPMaxDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W3_PvPMaxDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W3_PvPMinDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W3_PvPMinDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W3_PvPDamageLabel = (gcnew System::Windows::Forms::Label());
			this->W3_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MaxDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W3_MinDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W3_MaxDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MinDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon3OverloadedLabel = (gcnew System::Windows::Forms::Label());
			this->W4_EPSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_PvPMaxDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_PvPMinDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_PvPMaxDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_PvPMinDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MaxDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MinDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MaxDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MinDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_PvPMaxDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W4_PvPMaxDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W4_PvPMinDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W4_PvPMinDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W4_PvPDamageLabel = (gcnew System::Windows::Forms::Label());
			this->W4_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MaxDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W4_MinDvsALabel = (gcnew System::Windows::Forms::Label());
			this->W4_MaxDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MinDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon4OverloadedLabel = (gcnew System::Windows::Forms::Label());
			this->TotalEPSValueLabel = (gcnew System::Windows::Forms::Label());
			this->TotalPvPMaxDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->TotalPvPMinDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->TotalPvPMaxDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->TotalPvPMinDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->TotalMaxDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->TotalMinDvsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->TotalMaxDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->TotalMinDvsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->TotalPvPMaxDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->TotalPvPMaxDvsALabel = (gcnew System::Windows::Forms::Label());
			this->TotalPvPMinDvsALabel = (gcnew System::Windows::Forms::Label());
			this->TotalPvPMinDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->TotalPvPDamageLabel = (gcnew System::Windows::Forms::Label());
			this->TotalEPSLabel = (gcnew System::Windows::Forms::Label());
			this->TotalMaxDvsALabel = (gcnew System::Windows::Forms::Label());
			this->TotalMinDvsALabel = (gcnew System::Windows::Forms::Label());
			this->TotalMaxDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->TotalMinDvsSLabel = (gcnew System::Windows::Forms::Label());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->OCapRechargeTimeLabel = (gcnew System::Windows::Forms::Label());
			this->OCapRechargeTimeValueLabel = (gcnew System::Windows::Forms::Label());
			this->OCapEnergyLabel = (gcnew System::Windows::Forms::Label());
			this->OCapEnergyValueLabel = (gcnew System::Windows::Forms::Label());
			this->OCapFullFireTimeLabel = (gcnew System::Windows::Forms::Label());
			this->OCapFullFireTimeValueLabel = (gcnew System::Windows::Forms::Label());
			this->AvDmgPerShotValueLabel = (gcnew System::Windows::Forms::Label());
			this->AvDmgPerShotLabel = (gcnew System::Windows::Forms::Label());
			this->AvDmgPerSecondValueLabel = (gcnew System::Windows::Forms::Label());
			this->AvDmgPerSecondLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon1GroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->Weapon3GroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->Weapon2GroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->Weapon4GroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->TotalsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->Weapon1GroupBox->SuspendLayout();
			this->Weapon3GroupBox->SuspendLayout();
			this->Weapon2GroupBox->SuspendLayout();
			this->Weapon4GroupBox->SuspendLayout();
			this->TotalsGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// WeaponStatsFormLabel
			// 
			this->WeaponStatsFormLabel->AutoSize = true;
			this->WeaponStatsFormLabel->BackColor = System::Drawing::Color::Transparent;
			this->WeaponStatsFormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->WeaponStatsFormLabel->Location = System::Drawing::Point(248, 9);
			this->WeaponStatsFormLabel->Name = L"WeaponStatsFormLabel";
			this->WeaponStatsFormLabel->Size = System::Drawing::Size(199, 16);
			this->WeaponStatsFormLabel->TabIndex = 0;
			this->WeaponStatsFormLabel->Text = L"W e a p o n  S t a t i s t i c s";
			// 
			// Weapon1OverloadedLabel
			// 
			this->Weapon1OverloadedLabel->AutoSize = true;
			this->Weapon1OverloadedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon1OverloadedLabel->Location = System::Drawing::Point(62, 16);
			this->Weapon1OverloadedLabel->Name = L"Weapon1OverloadedLabel";
			this->Weapon1OverloadedLabel->Size = System::Drawing::Size(82, 13);
			this->Weapon1OverloadedLabel->TabIndex = 1;
			this->Weapon1OverloadedLabel->Text = L"Overloaded";
			// 
			// W1_MinDvsSLabel
			// 
			this->W1_MinDvsSLabel->AutoSize = true;
			this->W1_MinDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MinDvsSLabel->Location = System::Drawing::Point(3, 29);
			this->W1_MinDvsSLabel->Name = L"W1_MinDvsSLabel";
			this->W1_MinDvsSLabel->Size = System::Drawing::Size(112, 13);
			this->W1_MinDvsSLabel->TabIndex = 2;
			this->W1_MinDvsSLabel->Text = L"Min Damage vs S:";
			// 
			// W1_MinDvsALabel
			// 
			this->W1_MinDvsALabel->AutoSize = true;
			this->W1_MinDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MinDvsALabel->Location = System::Drawing::Point(3, 55);
			this->W1_MinDvsALabel->Name = L"W1_MinDvsALabel";
			this->W1_MinDvsALabel->Size = System::Drawing::Size(112, 13);
			this->W1_MinDvsALabel->TabIndex = 4;
			this->W1_MinDvsALabel->Text = L"Min Damage vs A:";
			// 
			// W1_MaxDvsSLabel
			// 
			this->W1_MaxDvsSLabel->AutoSize = true;
			this->W1_MaxDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MaxDvsSLabel->Location = System::Drawing::Point(3, 42);
			this->W1_MaxDvsSLabel->Name = L"W1_MaxDvsSLabel";
			this->W1_MaxDvsSLabel->Size = System::Drawing::Size(116, 13);
			this->W1_MaxDvsSLabel->TabIndex = 3;
			this->W1_MaxDvsSLabel->Text = L"Max Damage vs S:";
			// 
			// W1_PvPMinDvsSLabel
			// 
			this->W1_PvPMinDvsSLabel->AutoSize = true;
			this->W1_PvPMinDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_PvPMinDvsSLabel->Location = System::Drawing::Point(3, 117);
			this->W1_PvPMinDvsSLabel->Name = L"W1_PvPMinDvsSLabel";
			this->W1_PvPMinDvsSLabel->Size = System::Drawing::Size(112, 13);
			this->W1_PvPMinDvsSLabel->TabIndex = 8;
			this->W1_PvPMinDvsSLabel->Text = L"Min Damage vs S:";
			// 
			// W1_PvPDamageLabel
			// 
			this->W1_PvPDamageLabel->AutoSize = true;
			this->W1_PvPDamageLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_PvPDamageLabel->Location = System::Drawing::Point(61, 104);
			this->W1_PvPDamageLabel->Name = L"W1_PvPDamageLabel";
			this->W1_PvPDamageLabel->Size = System::Drawing::Size(88, 13);
			this->W1_PvPDamageLabel->TabIndex = 7;
			this->W1_PvPDamageLabel->Text = L"PvP Damage";
			// 
			// W1_EPSLabel
			// 
			this->W1_EPSLabel->AutoSize = true;
			this->W1_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_EPSLabel->Location = System::Drawing::Point(3, 81);
			this->W1_EPSLabel->Name = L"W1_EPSLabel";
			this->W1_EPSLabel->Size = System::Drawing::Size(34, 13);
			this->W1_EPSLabel->TabIndex = 6;
			this->W1_EPSLabel->Text = L"EPS:";
			// 
			// W1_MaxDvsALabel
			// 
			this->W1_MaxDvsALabel->AutoSize = true;
			this->W1_MaxDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MaxDvsALabel->Location = System::Drawing::Point(3, 68);
			this->W1_MaxDvsALabel->Name = L"W1_MaxDvsALabel";
			this->W1_MaxDvsALabel->Size = System::Drawing::Size(116, 13);
			this->W1_MaxDvsALabel->TabIndex = 5;
			this->W1_MaxDvsALabel->Text = L"Max Damage vs A:";
			// 
			// W1_PvPMaxDvsSLabel
			// 
			this->W1_PvPMaxDvsSLabel->AutoSize = true;
			this->W1_PvPMaxDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_PvPMaxDvsSLabel->Location = System::Drawing::Point(3, 130);
			this->W1_PvPMaxDvsSLabel->Name = L"W1_PvPMaxDvsSLabel";
			this->W1_PvPMaxDvsSLabel->Size = System::Drawing::Size(116, 13);
			this->W1_PvPMaxDvsSLabel->TabIndex = 11;
			this->W1_PvPMaxDvsSLabel->Text = L"Max Damage vs S:";
			// 
			// W1_PvPMaxDvsALabel
			// 
			this->W1_PvPMaxDvsALabel->AutoSize = true;
			this->W1_PvPMaxDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_PvPMaxDvsALabel->Location = System::Drawing::Point(3, 156);
			this->W1_PvPMaxDvsALabel->Name = L"W1_PvPMaxDvsALabel";
			this->W1_PvPMaxDvsALabel->Size = System::Drawing::Size(116, 13);
			this->W1_PvPMaxDvsALabel->TabIndex = 10;
			this->W1_PvPMaxDvsALabel->Text = L"Max Damage vs A:";
			// 
			// W1_PvPMinDvsA
			// 
			this->W1_PvPMinDvsA->AutoSize = true;
			this->W1_PvPMinDvsA->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_PvPMinDvsA->Location = System::Drawing::Point(3, 143);
			this->W1_PvPMinDvsA->Name = L"W1_PvPMinDvsA";
			this->W1_PvPMinDvsA->Size = System::Drawing::Size(112, 13);
			this->W1_PvPMinDvsA->TabIndex = 9;
			this->W1_PvPMinDvsA->Text = L"Min Damage vs A:";
			// 
			// W1_MinDvsSValueLabel
			// 
			this->W1_MinDvsSValueLabel->AutoSize = true;
			this->W1_MinDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MinDvsSValueLabel->Location = System::Drawing::Point(125, 29);
			this->W1_MinDvsSValueLabel->Name = L"W1_MinDvsSValueLabel";
			this->W1_MinDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W1_MinDvsSValueLabel->TabIndex = 12;
			this->W1_MinDvsSValueLabel->Text = L"None Loaded";
			// 
			// W1_MaxDvsSValueLabel
			// 
			this->W1_MaxDvsSValueLabel->AutoSize = true;
			this->W1_MaxDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MaxDvsSValueLabel->Location = System::Drawing::Point(125, 42);
			this->W1_MaxDvsSValueLabel->Name = L"W1_MaxDvsSValueLabel";
			this->W1_MaxDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W1_MaxDvsSValueLabel->TabIndex = 13;
			this->W1_MaxDvsSValueLabel->Text = L"None Loaded";
			// 
			// W1_MaxDvsAValueLabel
			// 
			this->W1_MaxDvsAValueLabel->AutoSize = true;
			this->W1_MaxDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MaxDvsAValueLabel->Location = System::Drawing::Point(125, 68);
			this->W1_MaxDvsAValueLabel->Name = L"W1_MaxDvsAValueLabel";
			this->W1_MaxDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W1_MaxDvsAValueLabel->TabIndex = 15;
			this->W1_MaxDvsAValueLabel->Text = L"None Loaded";
			// 
			// W1_MinDvsAValueLabel
			// 
			this->W1_MinDvsAValueLabel->AutoSize = true;
			this->W1_MinDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MinDvsAValueLabel->Location = System::Drawing::Point(125, 55);
			this->W1_MinDvsAValueLabel->Name = L"W1_MinDvsAValueLabel";
			this->W1_MinDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W1_MinDvsAValueLabel->TabIndex = 14;
			this->W1_MinDvsAValueLabel->Text = L"None Loaded";
			// 
			// W1_PvPMaxDvsAValueLabel
			// 
			this->W1_PvPMaxDvsAValueLabel->AutoSize = true;
			this->W1_PvPMaxDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_PvPMaxDvsAValueLabel->Location = System::Drawing::Point(125, 156);
			this->W1_PvPMaxDvsAValueLabel->Name = L"W1_PvPMaxDvsAValueLabel";
			this->W1_PvPMaxDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W1_PvPMaxDvsAValueLabel->TabIndex = 19;
			this->W1_PvPMaxDvsAValueLabel->Text = L"None Loaded";
			// 
			// W1_PvPMinDvsAValueLabel
			// 
			this->W1_PvPMinDvsAValueLabel->AutoSize = true;
			this->W1_PvPMinDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_PvPMinDvsAValueLabel->Location = System::Drawing::Point(125, 143);
			this->W1_PvPMinDvsAValueLabel->Name = L"W1_PvPMinDvsAValueLabel";
			this->W1_PvPMinDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W1_PvPMinDvsAValueLabel->TabIndex = 18;
			this->W1_PvPMinDvsAValueLabel->Text = L"None Loaded";
			// 
			// W1_PvPMaxDvsSValueLabel
			// 
			this->W1_PvPMaxDvsSValueLabel->AutoSize = true;
			this->W1_PvPMaxDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_PvPMaxDvsSValueLabel->Location = System::Drawing::Point(125, 130);
			this->W1_PvPMaxDvsSValueLabel->Name = L"W1_PvPMaxDvsSValueLabel";
			this->W1_PvPMaxDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W1_PvPMaxDvsSValueLabel->TabIndex = 17;
			this->W1_PvPMaxDvsSValueLabel->Text = L"None Loaded";
			// 
			// W1_PvPMinDvsSValueLabel
			// 
			this->W1_PvPMinDvsSValueLabel->AutoSize = true;
			this->W1_PvPMinDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_PvPMinDvsSValueLabel->Location = System::Drawing::Point(125, 117);
			this->W1_PvPMinDvsSValueLabel->Name = L"W1_PvPMinDvsSValueLabel";
			this->W1_PvPMinDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W1_PvPMinDvsSValueLabel->TabIndex = 16;
			this->W1_PvPMinDvsSValueLabel->Text = L"None Loaded";
			// 
			// W1_EPSValueLabel
			// 
			this->W1_EPSValueLabel->AutoSize = true;
			this->W1_EPSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_EPSValueLabel->Location = System::Drawing::Point(125, 81);
			this->W1_EPSValueLabel->Name = L"W1_EPSValueLabel";
			this->W1_EPSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W1_EPSValueLabel->TabIndex = 20;
			this->W1_EPSValueLabel->Text = L"None Loaded";
			// 
			// W2_EPSValueLabel
			// 
			this->W2_EPSValueLabel->AutoSize = true;
			this->W2_EPSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_EPSValueLabel->Location = System::Drawing::Point(124, 81);
			this->W2_EPSValueLabel->Name = L"W2_EPSValueLabel";
			this->W2_EPSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W2_EPSValueLabel->TabIndex = 40;
			this->W2_EPSValueLabel->Text = L"None Loaded";
			// 
			// W2_PvPMaxDvsAValueLabel
			// 
			this->W2_PvPMaxDvsAValueLabel->AutoSize = true;
			this->W2_PvPMaxDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_PvPMaxDvsAValueLabel->Location = System::Drawing::Point(124, 159);
			this->W2_PvPMaxDvsAValueLabel->Name = L"W2_PvPMaxDvsAValueLabel";
			this->W2_PvPMaxDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W2_PvPMaxDvsAValueLabel->TabIndex = 39;
			this->W2_PvPMaxDvsAValueLabel->Text = L"None Loaded";
			// 
			// W2_PvPMinDvsAValueLabel
			// 
			this->W2_PvPMinDvsAValueLabel->AutoSize = true;
			this->W2_PvPMinDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_PvPMinDvsAValueLabel->Location = System::Drawing::Point(124, 146);
			this->W2_PvPMinDvsAValueLabel->Name = L"W2_PvPMinDvsAValueLabel";
			this->W2_PvPMinDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W2_PvPMinDvsAValueLabel->TabIndex = 38;
			this->W2_PvPMinDvsAValueLabel->Text = L"None Loaded";
			// 
			// W2_PvPMaxDvsSValueLabel
			// 
			this->W2_PvPMaxDvsSValueLabel->AutoSize = true;
			this->W2_PvPMaxDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_PvPMaxDvsSValueLabel->Location = System::Drawing::Point(124, 133);
			this->W2_PvPMaxDvsSValueLabel->Name = L"W2_PvPMaxDvsSValueLabel";
			this->W2_PvPMaxDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W2_PvPMaxDvsSValueLabel->TabIndex = 37;
			this->W2_PvPMaxDvsSValueLabel->Text = L"None Loaded";
			// 
			// W2_PvPMinDvsSValueLabel
			// 
			this->W2_PvPMinDvsSValueLabel->AutoSize = true;
			this->W2_PvPMinDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_PvPMinDvsSValueLabel->Location = System::Drawing::Point(124, 120);
			this->W2_PvPMinDvsSValueLabel->Name = L"W2_PvPMinDvsSValueLabel";
			this->W2_PvPMinDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W2_PvPMinDvsSValueLabel->TabIndex = 36;
			this->W2_PvPMinDvsSValueLabel->Text = L"None Loaded";
			// 
			// W2_MaxDvsAValueLabel
			// 
			this->W2_MaxDvsAValueLabel->AutoSize = true;
			this->W2_MaxDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MaxDvsAValueLabel->Location = System::Drawing::Point(124, 68);
			this->W2_MaxDvsAValueLabel->Name = L"W2_MaxDvsAValueLabel";
			this->W2_MaxDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W2_MaxDvsAValueLabel->TabIndex = 35;
			this->W2_MaxDvsAValueLabel->Text = L"None Loaded";
			// 
			// W2_MinDvsAValueLabel
			// 
			this->W2_MinDvsAValueLabel->AutoSize = true;
			this->W2_MinDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MinDvsAValueLabel->Location = System::Drawing::Point(124, 55);
			this->W2_MinDvsAValueLabel->Name = L"W2_MinDvsAValueLabel";
			this->W2_MinDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W2_MinDvsAValueLabel->TabIndex = 34;
			this->W2_MinDvsAValueLabel->Text = L"None Loaded";
			// 
			// W2_MaxDvsSValueLabel
			// 
			this->W2_MaxDvsSValueLabel->AutoSize = true;
			this->W2_MaxDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MaxDvsSValueLabel->Location = System::Drawing::Point(124, 42);
			this->W2_MaxDvsSValueLabel->Name = L"W2_MaxDvsSValueLabel";
			this->W2_MaxDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W2_MaxDvsSValueLabel->TabIndex = 33;
			this->W2_MaxDvsSValueLabel->Text = L"None Loaded";
			// 
			// W2_MinDvsSValueLabel
			// 
			this->W2_MinDvsSValueLabel->AutoSize = true;
			this->W2_MinDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MinDvsSValueLabel->Location = System::Drawing::Point(124, 29);
			this->W2_MinDvsSValueLabel->Name = L"W2_MinDvsSValueLabel";
			this->W2_MinDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W2_MinDvsSValueLabel->TabIndex = 32;
			this->W2_MinDvsSValueLabel->Text = L"None Loaded";
			// 
			// W2_PvPMaxDvsSLabel
			// 
			this->W2_PvPMaxDvsSLabel->AutoSize = true;
			this->W2_PvPMaxDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_PvPMaxDvsSLabel->Location = System::Drawing::Point(2, 133);
			this->W2_PvPMaxDvsSLabel->Name = L"W2_PvPMaxDvsSLabel";
			this->W2_PvPMaxDvsSLabel->Size = System::Drawing::Size(116, 13);
			this->W2_PvPMaxDvsSLabel->TabIndex = 31;
			this->W2_PvPMaxDvsSLabel->Text = L"Max Damage vs S:";
			// 
			// W2_PvPMaxDvsALabel
			// 
			this->W2_PvPMaxDvsALabel->AutoSize = true;
			this->W2_PvPMaxDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_PvPMaxDvsALabel->Location = System::Drawing::Point(2, 159);
			this->W2_PvPMaxDvsALabel->Name = L"W2_PvPMaxDvsALabel";
			this->W2_PvPMaxDvsALabel->Size = System::Drawing::Size(116, 13);
			this->W2_PvPMaxDvsALabel->TabIndex = 30;
			this->W2_PvPMaxDvsALabel->Text = L"Max Damage vs A:";
			// 
			// W2_PvPMinDvsALabel
			// 
			this->W2_PvPMinDvsALabel->AutoSize = true;
			this->W2_PvPMinDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_PvPMinDvsALabel->Location = System::Drawing::Point(2, 146);
			this->W2_PvPMinDvsALabel->Name = L"W2_PvPMinDvsALabel";
			this->W2_PvPMinDvsALabel->Size = System::Drawing::Size(112, 13);
			this->W2_PvPMinDvsALabel->TabIndex = 29;
			this->W2_PvPMinDvsALabel->Text = L"Min Damage vs A:";
			// 
			// W2_PvPMinDvsSLabel
			// 
			this->W2_PvPMinDvsSLabel->AutoSize = true;
			this->W2_PvPMinDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_PvPMinDvsSLabel->Location = System::Drawing::Point(2, 120);
			this->W2_PvPMinDvsSLabel->Name = L"W2_PvPMinDvsSLabel";
			this->W2_PvPMinDvsSLabel->Size = System::Drawing::Size(112, 13);
			this->W2_PvPMinDvsSLabel->TabIndex = 28;
			this->W2_PvPMinDvsSLabel->Text = L"Min Damage vs S:";
			// 
			// W2_PvPDamageLabel
			// 
			this->W2_PvPDamageLabel->AutoSize = true;
			this->W2_PvPDamageLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_PvPDamageLabel->Location = System::Drawing::Point(60, 107);
			this->W2_PvPDamageLabel->Name = L"W2_PvPDamageLabel";
			this->W2_PvPDamageLabel->Size = System::Drawing::Size(88, 13);
			this->W2_PvPDamageLabel->TabIndex = 27;
			this->W2_PvPDamageLabel->Text = L"PvP Damage";
			// 
			// W2_EPSLabel
			// 
			this->W2_EPSLabel->AutoSize = true;
			this->W2_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_EPSLabel->Location = System::Drawing::Point(2, 81);
			this->W2_EPSLabel->Name = L"W2_EPSLabel";
			this->W2_EPSLabel->Size = System::Drawing::Size(34, 13);
			this->W2_EPSLabel->TabIndex = 26;
			this->W2_EPSLabel->Text = L"EPS:";
			// 
			// W2_MaxDvsALabel
			// 
			this->W2_MaxDvsALabel->AutoSize = true;
			this->W2_MaxDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MaxDvsALabel->Location = System::Drawing::Point(2, 68);
			this->W2_MaxDvsALabel->Name = L"W2_MaxDvsALabel";
			this->W2_MaxDvsALabel->Size = System::Drawing::Size(116, 13);
			this->W2_MaxDvsALabel->TabIndex = 25;
			this->W2_MaxDvsALabel->Text = L"Max Damage vs A:";
			// 
			// W2_MinDvsALabel
			// 
			this->W2_MinDvsALabel->AutoSize = true;
			this->W2_MinDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MinDvsALabel->Location = System::Drawing::Point(2, 55);
			this->W2_MinDvsALabel->Name = L"W2_MinDvsALabel";
			this->W2_MinDvsALabel->Size = System::Drawing::Size(112, 13);
			this->W2_MinDvsALabel->TabIndex = 24;
			this->W2_MinDvsALabel->Text = L"Min Damage vs A:";
			// 
			// W2_MaxDvsSLabel
			// 
			this->W2_MaxDvsSLabel->AutoSize = true;
			this->W2_MaxDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MaxDvsSLabel->Location = System::Drawing::Point(2, 42);
			this->W2_MaxDvsSLabel->Name = L"W2_MaxDvsSLabel";
			this->W2_MaxDvsSLabel->Size = System::Drawing::Size(116, 13);
			this->W2_MaxDvsSLabel->TabIndex = 23;
			this->W2_MaxDvsSLabel->Text = L"Max Damage vs S:";
			// 
			// W2_MinDvsSLabel
			// 
			this->W2_MinDvsSLabel->AutoSize = true;
			this->W2_MinDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MinDvsSLabel->Location = System::Drawing::Point(2, 29);
			this->W2_MinDvsSLabel->Name = L"W2_MinDvsSLabel";
			this->W2_MinDvsSLabel->Size = System::Drawing::Size(112, 13);
			this->W2_MinDvsSLabel->TabIndex = 22;
			this->W2_MinDvsSLabel->Text = L"Min Damage vs S:";
			// 
			// Weapon2OverloadedLabel
			// 
			this->Weapon2OverloadedLabel->AutoSize = true;
			this->Weapon2OverloadedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon2OverloadedLabel->Location = System::Drawing::Point(62, 16);
			this->Weapon2OverloadedLabel->Name = L"Weapon2OverloadedLabel";
			this->Weapon2OverloadedLabel->Size = System::Drawing::Size(82, 13);
			this->Weapon2OverloadedLabel->TabIndex = 21;
			this->Weapon2OverloadedLabel->Text = L"Overloaded";
			// 
			// W3_EPSValueLabel
			// 
			this->W3_EPSValueLabel->AutoSize = true;
			this->W3_EPSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_EPSValueLabel->Location = System::Drawing::Point(125, 81);
			this->W3_EPSValueLabel->Name = L"W3_EPSValueLabel";
			this->W3_EPSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W3_EPSValueLabel->TabIndex = 60;
			this->W3_EPSValueLabel->Text = L"None Loaded";
			// 
			// W3_PvPMaxDvsAValueLabel
			// 
			this->W3_PvPMaxDvsAValueLabel->AutoSize = true;
			this->W3_PvPMaxDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_PvPMaxDvsAValueLabel->Location = System::Drawing::Point(125, 159);
			this->W3_PvPMaxDvsAValueLabel->Name = L"W3_PvPMaxDvsAValueLabel";
			this->W3_PvPMaxDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W3_PvPMaxDvsAValueLabel->TabIndex = 59;
			this->W3_PvPMaxDvsAValueLabel->Text = L"None Loaded";
			// 
			// W3_PvPMinDvsAValueLabel
			// 
			this->W3_PvPMinDvsAValueLabel->AutoSize = true;
			this->W3_PvPMinDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_PvPMinDvsAValueLabel->Location = System::Drawing::Point(125, 146);
			this->W3_PvPMinDvsAValueLabel->Name = L"W3_PvPMinDvsAValueLabel";
			this->W3_PvPMinDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W3_PvPMinDvsAValueLabel->TabIndex = 58;
			this->W3_PvPMinDvsAValueLabel->Text = L"None Loaded";
			// 
			// W3_PvPMaxDvsSValueLabel
			// 
			this->W3_PvPMaxDvsSValueLabel->AutoSize = true;
			this->W3_PvPMaxDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_PvPMaxDvsSValueLabel->Location = System::Drawing::Point(125, 133);
			this->W3_PvPMaxDvsSValueLabel->Name = L"W3_PvPMaxDvsSValueLabel";
			this->W3_PvPMaxDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W3_PvPMaxDvsSValueLabel->TabIndex = 57;
			this->W3_PvPMaxDvsSValueLabel->Text = L"None Loaded";
			// 
			// W3_PvPMinDvsSValueLabel
			// 
			this->W3_PvPMinDvsSValueLabel->AutoSize = true;
			this->W3_PvPMinDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_PvPMinDvsSValueLabel->Location = System::Drawing::Point(125, 120);
			this->W3_PvPMinDvsSValueLabel->Name = L"W3_PvPMinDvsSValueLabel";
			this->W3_PvPMinDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W3_PvPMinDvsSValueLabel->TabIndex = 56;
			this->W3_PvPMinDvsSValueLabel->Text = L"None Loaded";
			// 
			// W3_MaxDvsAValueLabel
			// 
			this->W3_MaxDvsAValueLabel->AutoSize = true;
			this->W3_MaxDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MaxDvsAValueLabel->Location = System::Drawing::Point(125, 68);
			this->W3_MaxDvsAValueLabel->Name = L"W3_MaxDvsAValueLabel";
			this->W3_MaxDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W3_MaxDvsAValueLabel->TabIndex = 55;
			this->W3_MaxDvsAValueLabel->Text = L"None Loaded";
			// 
			// W3_MinDvsAValueLabel
			// 
			this->W3_MinDvsAValueLabel->AutoSize = true;
			this->W3_MinDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MinDvsAValueLabel->Location = System::Drawing::Point(125, 55);
			this->W3_MinDvsAValueLabel->Name = L"W3_MinDvsAValueLabel";
			this->W3_MinDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W3_MinDvsAValueLabel->TabIndex = 54;
			this->W3_MinDvsAValueLabel->Text = L"None Loaded";
			// 
			// W3_MaxDvsSValueLabel
			// 
			this->W3_MaxDvsSValueLabel->AutoSize = true;
			this->W3_MaxDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MaxDvsSValueLabel->Location = System::Drawing::Point(125, 42);
			this->W3_MaxDvsSValueLabel->Name = L"W3_MaxDvsSValueLabel";
			this->W3_MaxDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W3_MaxDvsSValueLabel->TabIndex = 53;
			this->W3_MaxDvsSValueLabel->Text = L"None Loaded";
			// 
			// W3_MinDvsSValueLabel
			// 
			this->W3_MinDvsSValueLabel->AutoSize = true;
			this->W3_MinDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MinDvsSValueLabel->Location = System::Drawing::Point(125, 29);
			this->W3_MinDvsSValueLabel->Name = L"W3_MinDvsSValueLabel";
			this->W3_MinDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W3_MinDvsSValueLabel->TabIndex = 52;
			this->W3_MinDvsSValueLabel->Text = L"None Loaded";
			// 
			// W3_PvPMaxDvsSLabel
			// 
			this->W3_PvPMaxDvsSLabel->AutoSize = true;
			this->W3_PvPMaxDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_PvPMaxDvsSLabel->Location = System::Drawing::Point(3, 133);
			this->W3_PvPMaxDvsSLabel->Name = L"W3_PvPMaxDvsSLabel";
			this->W3_PvPMaxDvsSLabel->Size = System::Drawing::Size(116, 13);
			this->W3_PvPMaxDvsSLabel->TabIndex = 51;
			this->W3_PvPMaxDvsSLabel->Text = L"Max Damage vs S:";
			// 
			// W3_PvPMaxDvsALabel
			// 
			this->W3_PvPMaxDvsALabel->AutoSize = true;
			this->W3_PvPMaxDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_PvPMaxDvsALabel->Location = System::Drawing::Point(3, 159);
			this->W3_PvPMaxDvsALabel->Name = L"W3_PvPMaxDvsALabel";
			this->W3_PvPMaxDvsALabel->Size = System::Drawing::Size(116, 13);
			this->W3_PvPMaxDvsALabel->TabIndex = 50;
			this->W3_PvPMaxDvsALabel->Text = L"Max Damage vs A:";
			// 
			// W3_PvPMinDvsALabel
			// 
			this->W3_PvPMinDvsALabel->AutoSize = true;
			this->W3_PvPMinDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_PvPMinDvsALabel->Location = System::Drawing::Point(3, 146);
			this->W3_PvPMinDvsALabel->Name = L"W3_PvPMinDvsALabel";
			this->W3_PvPMinDvsALabel->Size = System::Drawing::Size(112, 13);
			this->W3_PvPMinDvsALabel->TabIndex = 49;
			this->W3_PvPMinDvsALabel->Text = L"Min Damage vs A:";
			// 
			// W3_PvPMinDvsSLabel
			// 
			this->W3_PvPMinDvsSLabel->AutoSize = true;
			this->W3_PvPMinDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_PvPMinDvsSLabel->Location = System::Drawing::Point(3, 120);
			this->W3_PvPMinDvsSLabel->Name = L"W3_PvPMinDvsSLabel";
			this->W3_PvPMinDvsSLabel->Size = System::Drawing::Size(112, 13);
			this->W3_PvPMinDvsSLabel->TabIndex = 48;
			this->W3_PvPMinDvsSLabel->Text = L"Min Damage vs S:";
			// 
			// W3_PvPDamageLabel
			// 
			this->W3_PvPDamageLabel->AutoSize = true;
			this->W3_PvPDamageLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_PvPDamageLabel->Location = System::Drawing::Point(61, 107);
			this->W3_PvPDamageLabel->Name = L"W3_PvPDamageLabel";
			this->W3_PvPDamageLabel->Size = System::Drawing::Size(88, 13);
			this->W3_PvPDamageLabel->TabIndex = 47;
			this->W3_PvPDamageLabel->Text = L"PvP Damage";
			// 
			// W3_EPSLabel
			// 
			this->W3_EPSLabel->AutoSize = true;
			this->W3_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_EPSLabel->Location = System::Drawing::Point(3, 81);
			this->W3_EPSLabel->Name = L"W3_EPSLabel";
			this->W3_EPSLabel->Size = System::Drawing::Size(34, 13);
			this->W3_EPSLabel->TabIndex = 46;
			this->W3_EPSLabel->Text = L"EPS:";
			// 
			// W3_MaxDvsALabel
			// 
			this->W3_MaxDvsALabel->AutoSize = true;
			this->W3_MaxDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MaxDvsALabel->Location = System::Drawing::Point(3, 68);
			this->W3_MaxDvsALabel->Name = L"W3_MaxDvsALabel";
			this->W3_MaxDvsALabel->Size = System::Drawing::Size(116, 13);
			this->W3_MaxDvsALabel->TabIndex = 45;
			this->W3_MaxDvsALabel->Text = L"Max Damage vs A:";
			// 
			// W3_MinDvsALabel
			// 
			this->W3_MinDvsALabel->AutoSize = true;
			this->W3_MinDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MinDvsALabel->Location = System::Drawing::Point(3, 55);
			this->W3_MinDvsALabel->Name = L"W3_MinDvsALabel";
			this->W3_MinDvsALabel->Size = System::Drawing::Size(112, 13);
			this->W3_MinDvsALabel->TabIndex = 44;
			this->W3_MinDvsALabel->Text = L"Min Damage vs A:";
			// 
			// W3_MaxDvsSLabel
			// 
			this->W3_MaxDvsSLabel->AutoSize = true;
			this->W3_MaxDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MaxDvsSLabel->Location = System::Drawing::Point(3, 42);
			this->W3_MaxDvsSLabel->Name = L"W3_MaxDvsSLabel";
			this->W3_MaxDvsSLabel->Size = System::Drawing::Size(116, 13);
			this->W3_MaxDvsSLabel->TabIndex = 43;
			this->W3_MaxDvsSLabel->Text = L"Max Damage vs S:";
			// 
			// W3_MinDvsSLabel
			// 
			this->W3_MinDvsSLabel->AutoSize = true;
			this->W3_MinDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MinDvsSLabel->Location = System::Drawing::Point(3, 29);
			this->W3_MinDvsSLabel->Name = L"W3_MinDvsSLabel";
			this->W3_MinDvsSLabel->Size = System::Drawing::Size(112, 13);
			this->W3_MinDvsSLabel->TabIndex = 42;
			this->W3_MinDvsSLabel->Text = L"Min Damage vs S:";
			// 
			// Weapon3OverloadedLabel
			// 
			this->Weapon3OverloadedLabel->AutoSize = true;
			this->Weapon3OverloadedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon3OverloadedLabel->Location = System::Drawing::Point(62, 16);
			this->Weapon3OverloadedLabel->Name = L"Weapon3OverloadedLabel";
			this->Weapon3OverloadedLabel->Size = System::Drawing::Size(82, 13);
			this->Weapon3OverloadedLabel->TabIndex = 41;
			this->Weapon3OverloadedLabel->Text = L"Overloaded";
			// 
			// W4_EPSValueLabel
			// 
			this->W4_EPSValueLabel->AutoSize = true;
			this->W4_EPSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_EPSValueLabel->Location = System::Drawing::Point(124, 81);
			this->W4_EPSValueLabel->Name = L"W4_EPSValueLabel";
			this->W4_EPSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W4_EPSValueLabel->TabIndex = 80;
			this->W4_EPSValueLabel->Text = L"None Loaded";
			// 
			// W4_PvPMaxDvsAValueLabel
			// 
			this->W4_PvPMaxDvsAValueLabel->AutoSize = true;
			this->W4_PvPMaxDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_PvPMaxDvsAValueLabel->Location = System::Drawing::Point(124, 159);
			this->W4_PvPMaxDvsAValueLabel->Name = L"W4_PvPMaxDvsAValueLabel";
			this->W4_PvPMaxDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W4_PvPMaxDvsAValueLabel->TabIndex = 79;
			this->W4_PvPMaxDvsAValueLabel->Text = L"None Loaded";
			// 
			// W4_PvPMinDvsAValueLabel
			// 
			this->W4_PvPMinDvsAValueLabel->AutoSize = true;
			this->W4_PvPMinDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_PvPMinDvsAValueLabel->Location = System::Drawing::Point(124, 146);
			this->W4_PvPMinDvsAValueLabel->Name = L"W4_PvPMinDvsAValueLabel";
			this->W4_PvPMinDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W4_PvPMinDvsAValueLabel->TabIndex = 78;
			this->W4_PvPMinDvsAValueLabel->Text = L"None Loaded";
			// 
			// W4_PvPMaxDvsSValueLabel
			// 
			this->W4_PvPMaxDvsSValueLabel->AutoSize = true;
			this->W4_PvPMaxDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_PvPMaxDvsSValueLabel->Location = System::Drawing::Point(124, 133);
			this->W4_PvPMaxDvsSValueLabel->Name = L"W4_PvPMaxDvsSValueLabel";
			this->W4_PvPMaxDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W4_PvPMaxDvsSValueLabel->TabIndex = 77;
			this->W4_PvPMaxDvsSValueLabel->Text = L"None Loaded";
			// 
			// W4_PvPMinDvsSValueLabel
			// 
			this->W4_PvPMinDvsSValueLabel->AutoSize = true;
			this->W4_PvPMinDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_PvPMinDvsSValueLabel->Location = System::Drawing::Point(124, 120);
			this->W4_PvPMinDvsSValueLabel->Name = L"W4_PvPMinDvsSValueLabel";
			this->W4_PvPMinDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W4_PvPMinDvsSValueLabel->TabIndex = 76;
			this->W4_PvPMinDvsSValueLabel->Text = L"None Loaded";
			// 
			// W4_MaxDvsAValueLabel
			// 
			this->W4_MaxDvsAValueLabel->AutoSize = true;
			this->W4_MaxDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MaxDvsAValueLabel->Location = System::Drawing::Point(124, 68);
			this->W4_MaxDvsAValueLabel->Name = L"W4_MaxDvsAValueLabel";
			this->W4_MaxDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W4_MaxDvsAValueLabel->TabIndex = 75;
			this->W4_MaxDvsAValueLabel->Text = L"None Loaded";
			// 
			// W4_MinDvsAValueLabel
			// 
			this->W4_MinDvsAValueLabel->AutoSize = true;
			this->W4_MinDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MinDvsAValueLabel->Location = System::Drawing::Point(124, 55);
			this->W4_MinDvsAValueLabel->Name = L"W4_MinDvsAValueLabel";
			this->W4_MinDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->W4_MinDvsAValueLabel->TabIndex = 74;
			this->W4_MinDvsAValueLabel->Text = L"None Loaded";
			// 
			// W4_MaxDvsSValueLabel
			// 
			this->W4_MaxDvsSValueLabel->AutoSize = true;
			this->W4_MaxDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MaxDvsSValueLabel->Location = System::Drawing::Point(124, 42);
			this->W4_MaxDvsSValueLabel->Name = L"W4_MaxDvsSValueLabel";
			this->W4_MaxDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W4_MaxDvsSValueLabel->TabIndex = 73;
			this->W4_MaxDvsSValueLabel->Text = L"None Loaded";
			// 
			// W4_MinDvsSValueLabel
			// 
			this->W4_MinDvsSValueLabel->AutoSize = true;
			this->W4_MinDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MinDvsSValueLabel->Location = System::Drawing::Point(124, 29);
			this->W4_MinDvsSValueLabel->Name = L"W4_MinDvsSValueLabel";
			this->W4_MinDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->W4_MinDvsSValueLabel->TabIndex = 72;
			this->W4_MinDvsSValueLabel->Text = L"None Loaded";
			// 
			// W4_PvPMaxDvsSLabel
			// 
			this->W4_PvPMaxDvsSLabel->AutoSize = true;
			this->W4_PvPMaxDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_PvPMaxDvsSLabel->Location = System::Drawing::Point(2, 133);
			this->W4_PvPMaxDvsSLabel->Name = L"W4_PvPMaxDvsSLabel";
			this->W4_PvPMaxDvsSLabel->Size = System::Drawing::Size(116, 13);
			this->W4_PvPMaxDvsSLabel->TabIndex = 71;
			this->W4_PvPMaxDvsSLabel->Text = L"Max Damage vs S:";
			// 
			// W4_PvPMaxDvsALabel
			// 
			this->W4_PvPMaxDvsALabel->AutoSize = true;
			this->W4_PvPMaxDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_PvPMaxDvsALabel->Location = System::Drawing::Point(2, 159);
			this->W4_PvPMaxDvsALabel->Name = L"W4_PvPMaxDvsALabel";
			this->W4_PvPMaxDvsALabel->Size = System::Drawing::Size(116, 13);
			this->W4_PvPMaxDvsALabel->TabIndex = 70;
			this->W4_PvPMaxDvsALabel->Text = L"Max Damage vs A:";
			// 
			// W4_PvPMinDvsALabel
			// 
			this->W4_PvPMinDvsALabel->AutoSize = true;
			this->W4_PvPMinDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_PvPMinDvsALabel->Location = System::Drawing::Point(2, 146);
			this->W4_PvPMinDvsALabel->Name = L"W4_PvPMinDvsALabel";
			this->W4_PvPMinDvsALabel->Size = System::Drawing::Size(112, 13);
			this->W4_PvPMinDvsALabel->TabIndex = 69;
			this->W4_PvPMinDvsALabel->Text = L"Min Damage vs A:";
			// 
			// W4_PvPMinDvsSLabel
			// 
			this->W4_PvPMinDvsSLabel->AutoSize = true;
			this->W4_PvPMinDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_PvPMinDvsSLabel->Location = System::Drawing::Point(2, 120);
			this->W4_PvPMinDvsSLabel->Name = L"W4_PvPMinDvsSLabel";
			this->W4_PvPMinDvsSLabel->Size = System::Drawing::Size(112, 13);
			this->W4_PvPMinDvsSLabel->TabIndex = 68;
			this->W4_PvPMinDvsSLabel->Text = L"Min Damage vs S:";
			// 
			// W4_PvPDamageLabel
			// 
			this->W4_PvPDamageLabel->AutoSize = true;
			this->W4_PvPDamageLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_PvPDamageLabel->Location = System::Drawing::Point(60, 107);
			this->W4_PvPDamageLabel->Name = L"W4_PvPDamageLabel";
			this->W4_PvPDamageLabel->Size = System::Drawing::Size(88, 13);
			this->W4_PvPDamageLabel->TabIndex = 67;
			this->W4_PvPDamageLabel->Text = L"PvP Damage";
			// 
			// W4_EPSLabel
			// 
			this->W4_EPSLabel->AutoSize = true;
			this->W4_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_EPSLabel->Location = System::Drawing::Point(2, 81);
			this->W4_EPSLabel->Name = L"W4_EPSLabel";
			this->W4_EPSLabel->Size = System::Drawing::Size(34, 13);
			this->W4_EPSLabel->TabIndex = 66;
			this->W4_EPSLabel->Text = L"EPS:";
			// 
			// W4_MaxDvsALabel
			// 
			this->W4_MaxDvsALabel->AutoSize = true;
			this->W4_MaxDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MaxDvsALabel->Location = System::Drawing::Point(2, 68);
			this->W4_MaxDvsALabel->Name = L"W4_MaxDvsALabel";
			this->W4_MaxDvsALabel->Size = System::Drawing::Size(116, 13);
			this->W4_MaxDvsALabel->TabIndex = 65;
			this->W4_MaxDvsALabel->Text = L"Max Damage vs A:";
			// 
			// W4_MinDvsALabel
			// 
			this->W4_MinDvsALabel->AutoSize = true;
			this->W4_MinDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MinDvsALabel->Location = System::Drawing::Point(2, 55);
			this->W4_MinDvsALabel->Name = L"W4_MinDvsALabel";
			this->W4_MinDvsALabel->Size = System::Drawing::Size(112, 13);
			this->W4_MinDvsALabel->TabIndex = 64;
			this->W4_MinDvsALabel->Text = L"Min Damage vs A:";
			// 
			// W4_MaxDvsSLabel
			// 
			this->W4_MaxDvsSLabel->AutoSize = true;
			this->W4_MaxDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MaxDvsSLabel->Location = System::Drawing::Point(2, 42);
			this->W4_MaxDvsSLabel->Name = L"W4_MaxDvsSLabel";
			this->W4_MaxDvsSLabel->Size = System::Drawing::Size(116, 13);
			this->W4_MaxDvsSLabel->TabIndex = 63;
			this->W4_MaxDvsSLabel->Text = L"Max Damage vs S:";
			// 
			// W4_MinDvsSLabel
			// 
			this->W4_MinDvsSLabel->AutoSize = true;
			this->W4_MinDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MinDvsSLabel->Location = System::Drawing::Point(2, 29);
			this->W4_MinDvsSLabel->Name = L"W4_MinDvsSLabel";
			this->W4_MinDvsSLabel->Size = System::Drawing::Size(112, 13);
			this->W4_MinDvsSLabel->TabIndex = 62;
			this->W4_MinDvsSLabel->Text = L"Min Damage vs S:";
			// 
			// Weapon4OverloadedLabel
			// 
			this->Weapon4OverloadedLabel->AutoSize = true;
			this->Weapon4OverloadedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon4OverloadedLabel->Location = System::Drawing::Point(62, 16);
			this->Weapon4OverloadedLabel->Name = L"Weapon4OverloadedLabel";
			this->Weapon4OverloadedLabel->Size = System::Drawing::Size(82, 13);
			this->Weapon4OverloadedLabel->TabIndex = 61;
			this->Weapon4OverloadedLabel->Text = L"Overloaded";
			// 
			// TotalEPSValueLabel
			// 
			this->TotalEPSValueLabel->AutoSize = true;
			this->TotalEPSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalEPSValueLabel->Location = System::Drawing::Point(142, 75);
			this->TotalEPSValueLabel->Name = L"TotalEPSValueLabel";
			this->TotalEPSValueLabel->Size = System::Drawing::Size(81, 13);
			this->TotalEPSValueLabel->TabIndex = 100;
			this->TotalEPSValueLabel->Text = L"None Loaded";
			// 
			// TotalPvPMaxDvsAValueLabel
			// 
			this->TotalPvPMaxDvsAValueLabel->AutoSize = true;
			this->TotalPvPMaxDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalPvPMaxDvsAValueLabel->Location = System::Drawing::Point(142, 153);
			this->TotalPvPMaxDvsAValueLabel->Name = L"TotalPvPMaxDvsAValueLabel";
			this->TotalPvPMaxDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->TotalPvPMaxDvsAValueLabel->TabIndex = 99;
			this->TotalPvPMaxDvsAValueLabel->Text = L"None Loaded";
			// 
			// TotalPvPMinDvsAValueLabel
			// 
			this->TotalPvPMinDvsAValueLabel->AutoSize = true;
			this->TotalPvPMinDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalPvPMinDvsAValueLabel->Location = System::Drawing::Point(142, 140);
			this->TotalPvPMinDvsAValueLabel->Name = L"TotalPvPMinDvsAValueLabel";
			this->TotalPvPMinDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->TotalPvPMinDvsAValueLabel->TabIndex = 98;
			this->TotalPvPMinDvsAValueLabel->Text = L"None Loaded";
			// 
			// TotalPvPMaxDvsSValueLabel
			// 
			this->TotalPvPMaxDvsSValueLabel->AutoSize = true;
			this->TotalPvPMaxDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalPvPMaxDvsSValueLabel->Location = System::Drawing::Point(142, 127);
			this->TotalPvPMaxDvsSValueLabel->Name = L"TotalPvPMaxDvsSValueLabel";
			this->TotalPvPMaxDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->TotalPvPMaxDvsSValueLabel->TabIndex = 97;
			this->TotalPvPMaxDvsSValueLabel->Text = L"None Loaded";
			// 
			// TotalPvPMinDvsSValueLabel
			// 
			this->TotalPvPMinDvsSValueLabel->AutoSize = true;
			this->TotalPvPMinDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalPvPMinDvsSValueLabel->Location = System::Drawing::Point(142, 114);
			this->TotalPvPMinDvsSValueLabel->Name = L"TotalPvPMinDvsSValueLabel";
			this->TotalPvPMinDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->TotalPvPMinDvsSValueLabel->TabIndex = 96;
			this->TotalPvPMinDvsSValueLabel->Text = L"None Loaded";
			// 
			// TotalMaxDvsAValueLabel
			// 
			this->TotalMaxDvsAValueLabel->AutoSize = true;
			this->TotalMaxDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalMaxDvsAValueLabel->Location = System::Drawing::Point(142, 62);
			this->TotalMaxDvsAValueLabel->Name = L"TotalMaxDvsAValueLabel";
			this->TotalMaxDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->TotalMaxDvsAValueLabel->TabIndex = 95;
			this->TotalMaxDvsAValueLabel->Text = L"None Loaded";
			// 
			// TotalMinDvsAValueLabel
			// 
			this->TotalMinDvsAValueLabel->AutoSize = true;
			this->TotalMinDvsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalMinDvsAValueLabel->Location = System::Drawing::Point(142, 49);
			this->TotalMinDvsAValueLabel->Name = L"TotalMinDvsAValueLabel";
			this->TotalMinDvsAValueLabel->Size = System::Drawing::Size(81, 13);
			this->TotalMinDvsAValueLabel->TabIndex = 94;
			this->TotalMinDvsAValueLabel->Text = L"None Loaded";
			// 
			// TotalMaxDvsSValueLabel
			// 
			this->TotalMaxDvsSValueLabel->AutoSize = true;
			this->TotalMaxDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalMaxDvsSValueLabel->Location = System::Drawing::Point(142, 36);
			this->TotalMaxDvsSValueLabel->Name = L"TotalMaxDvsSValueLabel";
			this->TotalMaxDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->TotalMaxDvsSValueLabel->TabIndex = 93;
			this->TotalMaxDvsSValueLabel->Text = L"None Loaded";
			// 
			// TotalMinDvsSValueLabel
			// 
			this->TotalMinDvsSValueLabel->AutoSize = true;
			this->TotalMinDvsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalMinDvsSValueLabel->Location = System::Drawing::Point(142, 23);
			this->TotalMinDvsSValueLabel->Name = L"TotalMinDvsSValueLabel";
			this->TotalMinDvsSValueLabel->Size = System::Drawing::Size(81, 13);
			this->TotalMinDvsSValueLabel->TabIndex = 92;
			this->TotalMinDvsSValueLabel->Text = L"None Loaded";
			// 
			// TotalPvPMaxDvsSLabel
			// 
			this->TotalPvPMaxDvsSLabel->AutoSize = true;
			this->TotalPvPMaxDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalPvPMaxDvsSLabel->Location = System::Drawing::Point(20, 127);
			this->TotalPvPMaxDvsSLabel->Name = L"TotalPvPMaxDvsSLabel";
			this->TotalPvPMaxDvsSLabel->Size = System::Drawing::Size(116, 13);
			this->TotalPvPMaxDvsSLabel->TabIndex = 91;
			this->TotalPvPMaxDvsSLabel->Text = L"Max Damage vs S:";
			// 
			// TotalPvPMaxDvsALabel
			// 
			this->TotalPvPMaxDvsALabel->AutoSize = true;
			this->TotalPvPMaxDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalPvPMaxDvsALabel->Location = System::Drawing::Point(20, 153);
			this->TotalPvPMaxDvsALabel->Name = L"TotalPvPMaxDvsALabel";
			this->TotalPvPMaxDvsALabel->Size = System::Drawing::Size(116, 13);
			this->TotalPvPMaxDvsALabel->TabIndex = 90;
			this->TotalPvPMaxDvsALabel->Text = L"Max Damage vs A:";
			// 
			// TotalPvPMinDvsALabel
			// 
			this->TotalPvPMinDvsALabel->AutoSize = true;
			this->TotalPvPMinDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalPvPMinDvsALabel->Location = System::Drawing::Point(20, 140);
			this->TotalPvPMinDvsALabel->Name = L"TotalPvPMinDvsALabel";
			this->TotalPvPMinDvsALabel->Size = System::Drawing::Size(112, 13);
			this->TotalPvPMinDvsALabel->TabIndex = 89;
			this->TotalPvPMinDvsALabel->Text = L"Min Damage vs A:";
			// 
			// TotalPvPMinDvsSLabel
			// 
			this->TotalPvPMinDvsSLabel->AutoSize = true;
			this->TotalPvPMinDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalPvPMinDvsSLabel->Location = System::Drawing::Point(20, 114);
			this->TotalPvPMinDvsSLabel->Name = L"TotalPvPMinDvsSLabel";
			this->TotalPvPMinDvsSLabel->Size = System::Drawing::Size(112, 13);
			this->TotalPvPMinDvsSLabel->TabIndex = 88;
			this->TotalPvPMinDvsSLabel->Text = L"Min Damage vs S:";
			// 
			// TotalPvPDamageLabel
			// 
			this->TotalPvPDamageLabel->AutoSize = true;
			this->TotalPvPDamageLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalPvPDamageLabel->Location = System::Drawing::Point(78, 101);
			this->TotalPvPDamageLabel->Name = L"TotalPvPDamageLabel";
			this->TotalPvPDamageLabel->Size = System::Drawing::Size(88, 13);
			this->TotalPvPDamageLabel->TabIndex = 87;
			this->TotalPvPDamageLabel->Text = L"PvP Damage";
			// 
			// TotalEPSLabel
			// 
			this->TotalEPSLabel->AutoSize = true;
			this->TotalEPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalEPSLabel->Location = System::Drawing::Point(20, 75);
			this->TotalEPSLabel->Name = L"TotalEPSLabel";
			this->TotalEPSLabel->Size = System::Drawing::Size(34, 13);
			this->TotalEPSLabel->TabIndex = 86;
			this->TotalEPSLabel->Text = L"EPS:";
			// 
			// TotalMaxDvsALabel
			// 
			this->TotalMaxDvsALabel->AutoSize = true;
			this->TotalMaxDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalMaxDvsALabel->Location = System::Drawing::Point(20, 62);
			this->TotalMaxDvsALabel->Name = L"TotalMaxDvsALabel";
			this->TotalMaxDvsALabel->Size = System::Drawing::Size(116, 13);
			this->TotalMaxDvsALabel->TabIndex = 85;
			this->TotalMaxDvsALabel->Text = L"Max Damage vs A:";
			// 
			// TotalMinDvsALabel
			// 
			this->TotalMinDvsALabel->AutoSize = true;
			this->TotalMinDvsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalMinDvsALabel->Location = System::Drawing::Point(20, 49);
			this->TotalMinDvsALabel->Name = L"TotalMinDvsALabel";
			this->TotalMinDvsALabel->Size = System::Drawing::Size(112, 13);
			this->TotalMinDvsALabel->TabIndex = 84;
			this->TotalMinDvsALabel->Text = L"Min Damage vs A:";
			// 
			// TotalMaxDvsSLabel
			// 
			this->TotalMaxDvsSLabel->AutoSize = true;
			this->TotalMaxDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalMaxDvsSLabel->Location = System::Drawing::Point(20, 36);
			this->TotalMaxDvsSLabel->Name = L"TotalMaxDvsSLabel";
			this->TotalMaxDvsSLabel->Size = System::Drawing::Size(116, 13);
			this->TotalMaxDvsSLabel->TabIndex = 83;
			this->TotalMaxDvsSLabel->Text = L"Max Damage vs S:";
			// 
			// TotalMinDvsSLabel
			// 
			this->TotalMinDvsSLabel->AutoSize = true;
			this->TotalMinDvsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalMinDvsSLabel->Location = System::Drawing::Point(20, 23);
			this->TotalMinDvsSLabel->Name = L"TotalMinDvsSLabel";
			this->TotalMinDvsSLabel->Size = System::Drawing::Size(112, 13);
			this->TotalMinDvsSLabel->TabIndex = 82;
			this->TotalMinDvsSLabel->Text = L"Min Damage vs S:";
			// 
			// CloseButton
			// 
			this->CloseButton->ForeColor = System::Drawing::Color::Black;
			this->CloseButton->Location = System::Drawing::Point(311, 410);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 101;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &WeaponStatsForm::CloseButton_Click);
			// 
			// OCapRechargeTimeLabel
			// 
			this->OCapRechargeTimeLabel->AutoSize = true;
			this->OCapRechargeTimeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OCapRechargeTimeLabel->Location = System::Drawing::Point(4, 241);
			this->OCapRechargeTimeLabel->Name = L"OCapRechargeTimeLabel";
			this->OCapRechargeTimeLabel->Size = System::Drawing::Size(145, 13);
			this->OCapRechargeTimeLabel->TabIndex = 103;
			this->OCapRechargeTimeLabel->Text = L"Cap Recharge Time (s):";
			// 
			// OCapRechargeTimeValueLabel
			// 
			this->OCapRechargeTimeValueLabel->AutoSize = true;
			this->OCapRechargeTimeValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OCapRechargeTimeValueLabel->Location = System::Drawing::Point(157, 241);
			this->OCapRechargeTimeValueLabel->Name = L"OCapRechargeTimeValueLabel";
			this->OCapRechargeTimeValueLabel->Size = System::Drawing::Size(81, 13);
			this->OCapRechargeTimeValueLabel->TabIndex = 105;
			this->OCapRechargeTimeValueLabel->Text = L"None Loaded";
			// 
			// OCapEnergyLabel
			// 
			this->OCapEnergyLabel->AutoSize = true;
			this->OCapEnergyLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OCapEnergyLabel->Location = System::Drawing::Point(4, 228);
			this->OCapEnergyLabel->Name = L"OCapEnergyLabel";
			this->OCapEnergyLabel->Size = System::Drawing::Size(149, 13);
			this->OCapEnergyLabel->TabIndex = 107;
			this->OCapEnergyLabel->Text = L"Overloaded Cap Energy:";
			// 
			// OCapEnergyValueLabel
			// 
			this->OCapEnergyValueLabel->AutoSize = true;
			this->OCapEnergyValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OCapEnergyValueLabel->Location = System::Drawing::Point(157, 228);
			this->OCapEnergyValueLabel->Name = L"OCapEnergyValueLabel";
			this->OCapEnergyValueLabel->Size = System::Drawing::Size(81, 13);
			this->OCapEnergyValueLabel->TabIndex = 109;
			this->OCapEnergyValueLabel->Text = L"None Loaded";
			// 
			// OCapFullFireTimeLabel
			// 
			this->OCapFullFireTimeLabel->AutoSize = true;
			this->OCapFullFireTimeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OCapFullFireTimeLabel->Location = System::Drawing::Point(4, 254);
			this->OCapFullFireTimeLabel->Name = L"OCapFullFireTimeLabel";
			this->OCapFullFireTimeLabel->Size = System::Drawing::Size(108, 13);
			this->OCapFullFireTimeLabel->TabIndex = 102;
			this->OCapFullFireTimeLabel->Text = L"Full Fire Time (s):";
			// 
			// OCapFullFireTimeValueLabel
			// 
			this->OCapFullFireTimeValueLabel->AutoSize = true;
			this->OCapFullFireTimeValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OCapFullFireTimeValueLabel->Location = System::Drawing::Point(157, 254);
			this->OCapFullFireTimeValueLabel->Name = L"OCapFullFireTimeValueLabel";
			this->OCapFullFireTimeValueLabel->Size = System::Drawing::Size(81, 13);
			this->OCapFullFireTimeValueLabel->TabIndex = 104;
			this->OCapFullFireTimeValueLabel->Text = L"None Loaded";
			// 
			// AvDmgPerShotValueLabel
			// 
			this->AvDmgPerShotValueLabel->AutoSize = true;
			this->AvDmgPerShotValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->AvDmgPerShotValueLabel->Location = System::Drawing::Point(141, 185);
			this->AvDmgPerShotValueLabel->Name = L"AvDmgPerShotValueLabel";
			this->AvDmgPerShotValueLabel->Size = System::Drawing::Size(81, 13);
			this->AvDmgPerShotValueLabel->TabIndex = 111;
			this->AvDmgPerShotValueLabel->Text = L"None Loaded";
			// 
			// AvDmgPerShotLabel
			// 
			this->AvDmgPerShotLabel->AutoSize = true;
			this->AvDmgPerShotLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->AvDmgPerShotLabel->Location = System::Drawing::Point(4, 185);
			this->AvDmgPerShotLabel->Name = L"AvDmgPerShotLabel";
			this->AvDmgPerShotLabel->Size = System::Drawing::Size(115, 13);
			this->AvDmgPerShotLabel->TabIndex = 110;
			this->AvDmgPerShotLabel->Text = L"Av. Dmg per Shot:";
			// 
			// AvDmgPerSecondValueLabel
			// 
			this->AvDmgPerSecondValueLabel->AutoSize = true;
			this->AvDmgPerSecondValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->AvDmgPerSecondValueLabel->Location = System::Drawing::Point(141, 198);
			this->AvDmgPerSecondValueLabel->Name = L"AvDmgPerSecondValueLabel";
			this->AvDmgPerSecondValueLabel->Size = System::Drawing::Size(81, 13);
			this->AvDmgPerSecondValueLabel->TabIndex = 113;
			this->AvDmgPerSecondValueLabel->Text = L"None Loaded";
			// 
			// AvDmgPerSecondLabel
			// 
			this->AvDmgPerSecondLabel->AutoSize = true;
			this->AvDmgPerSecondLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->AvDmgPerSecondLabel->Location = System::Drawing::Point(4, 198);
			this->AvDmgPerSecondLabel->Name = L"AvDmgPerSecondLabel";
			this->AvDmgPerSecondLabel->Size = System::Drawing::Size(131, 13);
			this->AvDmgPerSecondLabel->TabIndex = 112;
			this->AvDmgPerSecondLabel->Text = L"Av. Dmg per Second:";
			// 
			// Weapon1GroupBox
			// 
			this->Weapon1GroupBox->BackColor = System::Drawing::Color::Transparent;
			this->Weapon1GroupBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Weapon1GroupBox.BackgroundImage")));
			this->Weapon1GroupBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Weapon1GroupBox->Controls->Add(this->Weapon1OverloadedLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_MinDvsSLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_MaxDvsSLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_MinDvsALabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_MaxDvsALabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_EPSLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_MinDvsSValueLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_MaxDvsSValueLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_MinDvsAValueLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_MaxDvsAValueLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_EPSValueLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_PvPDamageLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_PvPMinDvsSLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_PvPMinDvsA);
			this->Weapon1GroupBox->Controls->Add(this->W1_PvPMaxDvsALabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_PvPMaxDvsSLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_PvPMinDvsSValueLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_PvPMaxDvsSValueLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_PvPMinDvsAValueLabel);
			this->Weapon1GroupBox->Controls->Add(this->W1_PvPMaxDvsAValueLabel);
			this->Weapon1GroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon1GroupBox->Location = System::Drawing::Point(12, 29);
			this->Weapon1GroupBox->Name = L"Weapon1GroupBox";
			this->Weapon1GroupBox->Size = System::Drawing::Size(207, 182);
			this->Weapon1GroupBox->TabIndex = 114;
			this->Weapon1GroupBox->TabStop = false;
			this->Weapon1GroupBox->Text = L"Weapon 1";
			// 
			// Weapon3GroupBox
			// 
			this->Weapon3GroupBox->BackColor = System::Drawing::Color::Transparent;
			this->Weapon3GroupBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Weapon3GroupBox.BackgroundImage")));
			this->Weapon3GroupBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Weapon3GroupBox->Controls->Add(this->Weapon3OverloadedLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_MinDvsSLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_MaxDvsSLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_MinDvsALabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_MaxDvsALabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_EPSLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_PvPDamageLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_PvPMinDvsSLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_PvPMinDvsALabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_PvPMaxDvsALabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_PvPMaxDvsSLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_MinDvsSValueLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_MaxDvsSValueLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_MinDvsAValueLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_MaxDvsAValueLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_PvPMinDvsSValueLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_PvPMaxDvsSValueLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_PvPMinDvsAValueLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_PvPMaxDvsAValueLabel);
			this->Weapon3GroupBox->Controls->Add(this->W3_EPSValueLabel);
			this->Weapon3GroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon3GroupBox->Location = System::Drawing::Point(12, 217);
			this->Weapon3GroupBox->Name = L"Weapon3GroupBox";
			this->Weapon3GroupBox->Size = System::Drawing::Size(207, 182);
			this->Weapon3GroupBox->TabIndex = 115;
			this->Weapon3GroupBox->TabStop = false;
			this->Weapon3GroupBox->Text = L"Weapon 3";
			// 
			// Weapon2GroupBox
			// 
			this->Weapon2GroupBox->BackColor = System::Drawing::Color::Transparent;
			this->Weapon2GroupBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Weapon2GroupBox.BackgroundImage")));
			this->Weapon2GroupBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Weapon2GroupBox->Controls->Add(this->Weapon2OverloadedLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_MinDvsSLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_MaxDvsSLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_MinDvsALabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_MaxDvsALabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_EPSLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_PvPDamageLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_PvPMinDvsSLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_PvPMinDvsALabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_PvPMaxDvsALabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_PvPMaxDvsSLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_MinDvsSValueLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_MaxDvsSValueLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_MinDvsAValueLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_MaxDvsAValueLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_PvPMinDvsSValueLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_PvPMaxDvsSValueLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_PvPMinDvsAValueLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_PvPMaxDvsAValueLabel);
			this->Weapon2GroupBox->Controls->Add(this->W2_EPSValueLabel);
			this->Weapon2GroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon2GroupBox->Location = System::Drawing::Point(225, 29);
			this->Weapon2GroupBox->Name = L"Weapon2GroupBox";
			this->Weapon2GroupBox->Size = System::Drawing::Size(207, 182);
			this->Weapon2GroupBox->TabIndex = 116;
			this->Weapon2GroupBox->TabStop = false;
			this->Weapon2GroupBox->Text = L"Weapon 2";
			// 
			// Weapon4GroupBox
			// 
			this->Weapon4GroupBox->BackColor = System::Drawing::Color::Transparent;
			this->Weapon4GroupBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Weapon4GroupBox.BackgroundImage")));
			this->Weapon4GroupBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Weapon4GroupBox->Controls->Add(this->Weapon4OverloadedLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_MinDvsSLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_MaxDvsSLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_MinDvsALabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_MaxDvsALabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_EPSLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_PvPDamageLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_PvPMinDvsSLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_PvPMinDvsALabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_PvPMaxDvsALabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_PvPMaxDvsSLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_MinDvsSValueLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_MaxDvsSValueLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_MinDvsAValueLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_MaxDvsAValueLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_PvPMinDvsSValueLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_PvPMaxDvsSValueLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_PvPMinDvsAValueLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_PvPMaxDvsAValueLabel);
			this->Weapon4GroupBox->Controls->Add(this->W4_EPSValueLabel);
			this->Weapon4GroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon4GroupBox->Location = System::Drawing::Point(225, 217);
			this->Weapon4GroupBox->Name = L"Weapon4GroupBox";
			this->Weapon4GroupBox->Size = System::Drawing::Size(207, 182);
			this->Weapon4GroupBox->TabIndex = 117;
			this->Weapon4GroupBox->TabStop = false;
			this->Weapon4GroupBox->Text = L"Weapon 4";
			// 
			// TotalsGroupBox
			// 
			this->TotalsGroupBox->BackColor = System::Drawing::Color::Transparent;
			this->TotalsGroupBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"TotalsGroupBox.BackgroundImage")));
			this->TotalsGroupBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->TotalsGroupBox->Controls->Add(this->TotalMinDvsSLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalMaxDvsSLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalMinDvsALabel);
			this->TotalsGroupBox->Controls->Add(this->TotalMaxDvsALabel);
			this->TotalsGroupBox->Controls->Add(this->OCapEnergyValueLabel);
			this->TotalsGroupBox->Controls->Add(this->AvDmgPerSecondValueLabel);
			this->TotalsGroupBox->Controls->Add(this->OCapEnergyLabel);
			this->TotalsGroupBox->Controls->Add(this->OCapRechargeTimeValueLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalEPSLabel);
			this->TotalsGroupBox->Controls->Add(this->OCapRechargeTimeLabel);
			this->TotalsGroupBox->Controls->Add(this->OCapFullFireTimeValueLabel);
			this->TotalsGroupBox->Controls->Add(this->AvDmgPerSecondLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalPvPDamageLabel);
			this->TotalsGroupBox->Controls->Add(this->OCapFullFireTimeLabel);
			this->TotalsGroupBox->Controls->Add(this->AvDmgPerShotValueLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalPvPMinDvsSLabel);
			this->TotalsGroupBox->Controls->Add(this->AvDmgPerShotLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalPvPMinDvsALabel);
			this->TotalsGroupBox->Controls->Add(this->TotalPvPMaxDvsALabel);
			this->TotalsGroupBox->Controls->Add(this->TotalPvPMaxDvsSLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalMinDvsSValueLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalMaxDvsSValueLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalMinDvsAValueLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalMaxDvsAValueLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalPvPMinDvsSValueLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalEPSValueLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalPvPMaxDvsSValueLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalPvPMaxDvsAValueLabel);
			this->TotalsGroupBox->Controls->Add(this->TotalPvPMinDvsAValueLabel);
			this->TotalsGroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalsGroupBox->Location = System::Drawing::Point(438, 74);
			this->TotalsGroupBox->Name = L"TotalsGroupBox";
			this->TotalsGroupBox->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->TotalsGroupBox->Size = System::Drawing::Size(242, 286);
			this->TotalsGroupBox->TabIndex = 118;
			this->TotalsGroupBox->TabStop = false;
			this->TotalsGroupBox->Text = L"Totals";
			// 
			// WeaponStatsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(696, 445);
			this->Controls->Add(this->TotalsGroupBox);
			this->Controls->Add(this->Weapon4GroupBox);
			this->Controls->Add(this->Weapon2GroupBox);
			this->Controls->Add(this->Weapon3GroupBox);
			this->Controls->Add(this->Weapon1GroupBox);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->WeaponStatsFormLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"WeaponStatsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Weapon Statistics";
			this->Weapon1GroupBox->ResumeLayout(false);
			this->Weapon1GroupBox->PerformLayout();
			this->Weapon3GroupBox->ResumeLayout(false);
			this->Weapon3GroupBox->PerformLayout();
			this->Weapon2GroupBox->ResumeLayout(false);
			this->Weapon2GroupBox->PerformLayout();
			this->Weapon4GroupBox->ResumeLayout(false);
			this->Weapon4GroupBox->PerformLayout();
			this->TotalsGroupBox->ResumeLayout(false);
			this->TotalsGroupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		///
		/// Functions
		///
private: System::Void CalculateWeapon1Damages(Weapon^ loadedWeapon1, int selectedWeaponOverload){
			 String^ weapon1Name;
			 System::Data::DataRow^ rowWeapon;

			 Weapon^ tempWeapon = gcnew Weapon();
			 tempWeapon = loadedWeapon1;

			 rowWeapon = tempWeapon[0];

			 weapon1Name = rowWeapon["Name"]->ToString();
			 weapon1MinD = Convert::ToDouble(rowWeapon["Min Damage"]->ToString());
			 weapon1MaxD = Convert::ToDouble(rowWeapon["Max Damage"]->ToString());
			 weapon1vsS = Convert::ToDouble(rowWeapon["vs Sheilds"]->ToString());
			 weapon1vsA = Convert::ToDouble(rowWeapon["vs Armor"]->ToString());
			 weapon1EPS = Convert::ToDouble(rowWeapon["EPS"]->ToString());
			 weapon1Refire = Convert::ToDouble(rowWeapon["Refire"]->ToString());

			 if (weapon1Name != "None")
			 {
				 switch (selectedWeaponOverload)
				 {
				 case 0: W1_MinDvsSValueLabel->Text = ((weapon1MinD * 1.00) * weapon1vsS).ToString(".##");
						 W1_MaxDvsSValueLabel->Text = ((weapon1MaxD * 1.00) * weapon1vsS).ToString(".##");
						 W1_MinDvsAValueLabel->Text = ((weapon1MinD * 1.00) * weapon1vsA).ToString(".##");
						 W1_MaxDvsAValueLabel->Text = ((weapon1MaxD * 1.00) * weapon1vsA).ToString(".##");
						 W1_EPSValueLabel->Text = (weapon1EPS * 1.00).ToString(".##");

						 W1_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W1_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W1_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W1_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W1_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon1EPS *= 1.00;
					 break;
				 case 1: W1_MinDvsSValueLabel->Text = ((weapon1MinD * 1.25) * weapon1vsS).ToString(".##");
						 W1_MaxDvsSValueLabel->Text = ((weapon1MaxD * 1.25) * weapon1vsS).ToString(".##");
						 W1_MinDvsAValueLabel->Text = ((weapon1MinD * 1.25) * weapon1vsA).ToString(".##");
						 W1_MaxDvsAValueLabel->Text = ((weapon1MaxD * 1.25) * weapon1vsA).ToString(".##");
						 W1_EPSValueLabel->Text = (weapon1EPS * 1.43).ToString(".##");

						 W1_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W1_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W1_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W1_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W1_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon1EPS *= 1.43;
					 break;
				 case 2: W1_MinDvsSValueLabel->Text = ((weapon1MinD * 1.50) * weapon1vsS).ToString(".##");
						 W1_MaxDvsSValueLabel->Text = ((weapon1MaxD * 1.50) * weapon1vsS).ToString(".##");
						 W1_MinDvsAValueLabel->Text = ((weapon1MinD * 1.50) * weapon1vsA).ToString(".##");
						 W1_MaxDvsAValueLabel->Text = ((weapon1MaxD * 1.50) * weapon1vsA).ToString(".##");
						 W1_EPSValueLabel->Text = (weapon1EPS * 2.00).ToString(".##");

						 W1_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W1_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W1_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W1_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W1_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon1EPS *= 2.00;
					 break;
				 case 3: W1_MinDvsSValueLabel->Text = ((weapon1MinD * 2.00) * weapon1vsS).ToString(".##");
						 W1_MaxDvsSValueLabel->Text = ((weapon1MaxD * 2.00) * weapon1vsS).ToString(".##");
						 W1_MinDvsAValueLabel->Text = ((weapon1MinD * 2.00) * weapon1vsA).ToString(".##");
						 W1_MaxDvsAValueLabel->Text = ((weapon1MaxD * 2.00) * weapon1vsA).ToString(".##");
						 W1_EPSValueLabel->Text = (weapon1EPS * 2.86).ToString(".##");

						 W1_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W1_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W1_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W1_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W1_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 
						 weapon1EPS *= 2.86;
					 break;
				 case 4: W1_MinDvsSValueLabel->Text = ((weapon1MinD * 3.00) * weapon1vsS).ToString(".##");
						 W1_MaxDvsSValueLabel->Text = ((weapon1MaxD * 3.00) * weapon1vsS).ToString(".##");
						 W1_MinDvsAValueLabel->Text = ((weapon1MinD * 3.00) * weapon1vsA).ToString(".##");
						 W1_MaxDvsAValueLabel->Text = ((weapon1MaxD * 3.00) * weapon1vsA).ToString(".##");
						 W1_EPSValueLabel->Text = (weapon1EPS * 5.00).ToString(".##");

						 W1_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W1_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W1_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W1_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W1_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W1_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon1EPS *= 5.00;
					 break;
				 }
			 }
		 }
private: System::Void CalculateWeapon2Damages(Weapon^ loadedWeapon2, int selectedWeaponOverload){
			 String^ weapon2Name;
			 System::Data::DataRow^ rowWeapon;

			 Weapon^ tempWeapon = gcnew Weapon();
			 tempWeapon = loadedWeapon2;

			 rowWeapon = tempWeapon[0];

			 weapon2Name = rowWeapon["Name"]->ToString();
			 weapon2MinD = Convert::ToDouble(rowWeapon["Min Damage"]->ToString());
			 weapon2MaxD = Convert::ToDouble(rowWeapon["Max Damage"]->ToString());
			 weapon2vsS = Convert::ToDouble(rowWeapon["vs Sheilds"]->ToString());
			 weapon2vsA = Convert::ToDouble(rowWeapon["vs Armor"]->ToString());
			 weapon2EPS = Convert::ToDouble(rowWeapon["EPS"]->ToString());
			 weapon2Refire = Convert::ToDouble(rowWeapon["Refire"]->ToString());

			 if (weapon2Name != "None")
			 {
				 switch (selectedWeaponOverload)
				 {
				 case 0: W2_MinDvsSValueLabel->Text = ((weapon2MinD * 1.00) * weapon2vsS).ToString(".##");
						 W2_MaxDvsSValueLabel->Text = ((weapon2MaxD * 1.00) * weapon2vsS).ToString(".##");
						 W2_MinDvsAValueLabel->Text = ((weapon2MinD * 1.00) * weapon2vsA).ToString(".##");
						 W2_MaxDvsAValueLabel->Text = ((weapon2MaxD * 1.00) * weapon2vsA).ToString(".##");
						 W2_EPSValueLabel->Text = (weapon2EPS * 1.00).ToString(".##");

						 W2_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W2_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W2_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W2_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W2_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon2EPS *= 1.00;
					 break;
				 case 1: W2_MinDvsSValueLabel->Text = ((weapon2MinD * 1.25) * weapon2vsS).ToString(".##");
						 W2_MaxDvsSValueLabel->Text = ((weapon2MaxD * 1.25) * weapon2vsS).ToString(".##");
						 W2_MinDvsAValueLabel->Text = ((weapon2MinD * 1.25) * weapon2vsA).ToString(".##");
						 W2_MaxDvsAValueLabel->Text = ((weapon2MaxD * 1.25) * weapon2vsA).ToString(".##");
						 W2_EPSValueLabel->Text = (weapon2EPS * 1.43).ToString(".##");

						 W2_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W2_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W2_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W2_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W2_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon2EPS *= 1.43;
					 break;
				 case 2: W2_MinDvsSValueLabel->Text = ((weapon2MinD * 1.50) * weapon2vsS).ToString(".##");
						 W2_MaxDvsSValueLabel->Text = ((weapon2MaxD * 1.50) * weapon2vsS).ToString(".##");
						 W2_MinDvsAValueLabel->Text = ((weapon2MinD * 1.50) * weapon2vsA).ToString(".##");
						 W2_MaxDvsAValueLabel->Text = ((weapon2MaxD * 1.50) * weapon2vsA).ToString(".##");
						 W2_EPSValueLabel->Text = (weapon2EPS * 2.00).ToString(".##");

						 W2_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W2_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W2_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W2_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W2_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon2EPS *= 2.00;
					 break;
				 case 3: W2_MinDvsSValueLabel->Text = ((weapon2MinD * 2.00) * weapon2vsS).ToString(".##");
						 W2_MaxDvsSValueLabel->Text = ((weapon2MaxD * 2.00) * weapon2vsS).ToString(".##");
						 W2_MinDvsAValueLabel->Text = ((weapon2MinD * 2.00) * weapon2vsA).ToString(".##");
						 W2_MaxDvsAValueLabel->Text = ((weapon2MaxD * 2.00) * weapon2vsA).ToString(".##");
						 W2_EPSValueLabel->Text = (weapon2EPS * 2.86).ToString(".##");

						 W2_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W2_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W2_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W2_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W2_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon2EPS *= 2.86;
					 break;
				 case 4: W2_MinDvsSValueLabel->Text = ((weapon2MinD * 3.00) * weapon2vsS).ToString(".##");
						 W2_MaxDvsSValueLabel->Text = ((weapon2MaxD * 3.00) * weapon2vsS).ToString(".##");
						 W2_MinDvsAValueLabel->Text = ((weapon2MinD * 3.00) * weapon2vsA).ToString(".##");
						 W2_MaxDvsAValueLabel->Text = ((weapon2MaxD * 3.00) * weapon2vsA).ToString(".##");
						 W2_EPSValueLabel->Text = (weapon2EPS * 5.00).ToString(".##");

						 W2_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W2_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W2_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W2_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W2_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W2_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon2EPS *= 5.00;
					 break;
				 }
			 }
		 }
private: System::Void CalculateWeapon3Damages(Weapon^ loadedWeapon3, int selectedWeaponOverload){
			 String^ weapon3Name;
			 System::Data::DataRow^ rowWeapon;

			 Weapon^ tempWeapon = gcnew Weapon();
			 tempWeapon = loadedWeapon3;

			 rowWeapon = tempWeapon[0];

			 weapon3Name = rowWeapon["Name"]->ToString();
			 weapon3MinD = Convert::ToDouble(rowWeapon["Min Damage"]->ToString());
			 weapon3MaxD = Convert::ToDouble(rowWeapon["Max Damage"]->ToString());
			 weapon3vsS = Convert::ToDouble(rowWeapon["vs Sheilds"]->ToString());
			 weapon3vsA = Convert::ToDouble(rowWeapon["vs Armor"]->ToString());
			 weapon3EPS = Convert::ToDouble(rowWeapon["EPS"]->ToString());
			 weapon3Refire = Convert::ToDouble(rowWeapon["Refire"]->ToString());

			 if (weapon3Name != "None")
			 {
				 switch (selectedWeaponOverload)
				 {
				 case 0: W3_MinDvsSValueLabel->Text = ((weapon3MinD * 1.00) * weapon3vsS).ToString(".##");
						 W3_MaxDvsSValueLabel->Text = ((weapon3MaxD * 1.00) * weapon3vsS).ToString(".##");
						 W3_MinDvsAValueLabel->Text = ((weapon3MinD * 1.00) * weapon3vsA).ToString(".##");
						 W3_MaxDvsAValueLabel->Text = ((weapon3MaxD * 1.00) * weapon3vsA).ToString(".##");
						 W3_EPSValueLabel->Text = (weapon3EPS * 1.00).ToString(".##");

						 W3_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W3_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W3_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W3_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W3_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon3EPS *= 1.00;
					 break;
				 case 1: W3_MinDvsSValueLabel->Text = ((weapon3MinD * 1.25) * weapon3vsS).ToString(".##");
						 W3_MaxDvsSValueLabel->Text = ((weapon3MaxD * 1.25) * weapon3vsS).ToString(".##");
						 W3_MinDvsAValueLabel->Text = ((weapon3MinD * 1.25) * weapon3vsA).ToString(".##");
						 W3_MaxDvsAValueLabel->Text = ((weapon3MaxD * 1.25) * weapon3vsA).ToString(".##");
						 W3_EPSValueLabel->Text = (weapon3EPS * 1.43).ToString(".##");

						 W3_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W3_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W3_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W3_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W3_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon3EPS *= 1.43;
					 break;
				 case 2: W3_MinDvsSValueLabel->Text = ((weapon3MinD * 1.50) * weapon3vsS).ToString(".##");
						 W3_MaxDvsSValueLabel->Text = ((weapon3MaxD * 1.50) * weapon3vsS).ToString(".##");
						 W3_MinDvsAValueLabel->Text = ((weapon3MinD * 1.50) * weapon3vsA).ToString(".##");
						 W3_MaxDvsAValueLabel->Text = ((weapon3MaxD * 1.50) * weapon3vsA).ToString(".##");
						 W3_EPSValueLabel->Text = (weapon3EPS * 2.00).ToString(".##");

						 W3_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W3_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W3_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W3_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W3_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon3EPS *= 2.00;
					 break;
				 case 3: W3_MinDvsSValueLabel->Text = ((weapon3MinD * 2.00) * weapon3vsS).ToString(".##");
						 W3_MaxDvsSValueLabel->Text = ((weapon3MaxD * 2.00) * weapon3vsS).ToString(".##");
						 W3_MinDvsAValueLabel->Text = ((weapon3MinD * 2.00) * weapon3vsA).ToString(".##");
						 W3_MaxDvsAValueLabel->Text = ((weapon3MaxD * 2.00) * weapon3vsA).ToString(".##");
						 W3_EPSValueLabel->Text = (weapon3EPS * 2.86).ToString(".##");

						 W3_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W3_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W3_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W3_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W3_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon3EPS *= 2.86;
					 break;
				 case 4: W3_MinDvsSValueLabel->Text = ((weapon3MinD * 3.00) * weapon3vsS).ToString(".##");
						 W3_MaxDvsSValueLabel->Text = ((weapon3MaxD * 3.00) * weapon3vsS).ToString(".##");
						 W3_MinDvsAValueLabel->Text = ((weapon3MinD * 3.00) * weapon3vsA).ToString(".##");
						 W3_MaxDvsAValueLabel->Text = ((weapon3MaxD * 3.00) * weapon3vsA).ToString(".##");
						 W3_EPSValueLabel->Text = (weapon3EPS * 5.00).ToString(".##");

						 W3_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W3_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W3_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W3_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W3_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W3_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon3EPS *= 5.00;
					 break;
				 }
			 }
		 }
private: System::Void CalculateWeapon4Damages(Weapon^ loadedWeapon4, int selectedWeaponOverload){
			 String^ weapon4Name;
			 System::Data::DataRow^ rowWeapon;

			 Weapon^ tempWeapon = gcnew Weapon();
			 tempWeapon = loadedWeapon4;

			 rowWeapon = tempWeapon[0];

			 weapon4Name = rowWeapon["Name"]->ToString();
			 weapon4MinD = Convert::ToDouble(rowWeapon["Min Damage"]->ToString());
			 weapon4MaxD = Convert::ToDouble(rowWeapon["Max Damage"]->ToString());
			 weapon4vsS = Convert::ToDouble(rowWeapon["vs Sheilds"]->ToString());
			 weapon4vsA = Convert::ToDouble(rowWeapon["vs Armor"]->ToString());
			 weapon4EPS = Convert::ToDouble(rowWeapon["EPS"]->ToString());
			 weapon4Refire = Convert::ToDouble(rowWeapon["Refire"]->ToString());

			 if (weapon4Name != "None")
			 {
				 switch (selectedWeaponOverload)
				 {
				 case 0: W4_MinDvsSValueLabel->Text = ((weapon4MinD * 1.00) * weapon4vsS).ToString(".##");
						 W4_MaxDvsSValueLabel->Text = ((weapon4MaxD * 1.00) * weapon4vsS).ToString(".##");
						 W4_MinDvsAValueLabel->Text = ((weapon4MinD * 1.00) * weapon4vsA).ToString(".##");
						 W4_MaxDvsAValueLabel->Text = ((weapon4MaxD * 1.00) * weapon4vsA).ToString(".##");
						 W4_EPSValueLabel->Text = (weapon4EPS * 1.00).ToString(".##");

						 W4_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W4_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W4_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W4_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W4_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon4EPS *= 1.00;
					 break;
				 case 1: W4_MinDvsSValueLabel->Text = ((weapon4MinD * 1.25) * weapon4vsS).ToString(".##");
						 W4_MaxDvsSValueLabel->Text = ((weapon4MaxD * 1.25) * weapon4vsS).ToString(".##");
						 W4_MinDvsAValueLabel->Text = ((weapon4MinD * 1.25) * weapon4vsA).ToString(".##");
						 W4_MaxDvsAValueLabel->Text = ((weapon4MaxD * 1.25) * weapon4vsA).ToString(".##");
						 W4_EPSValueLabel->Text = (weapon4EPS * 1.43).ToString(".##");

						 W4_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W4_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W4_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W4_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W4_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon4EPS *= 1.43;
					 break;
				 case 2: W4_MinDvsSValueLabel->Text = ((weapon4MinD * 1.50) * weapon4vsS).ToString(".##");
						 W4_MaxDvsSValueLabel->Text = ((weapon4MaxD * 1.50) * weapon4vsS).ToString(".##");
						 W4_MinDvsAValueLabel->Text = ((weapon4MinD * 1.50) * weapon4vsA).ToString(".##");
						 W4_MaxDvsAValueLabel->Text = ((weapon4MaxD * 1.50) * weapon4vsA).ToString(".##");
						 W4_EPSValueLabel->Text = (weapon4EPS * 2.00).ToString(".##");

						 W4_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W4_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W4_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W4_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W4_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon4EPS *= 2.00;
					 break;
				 case 3: W4_MinDvsSValueLabel->Text = ((weapon4MinD * 2.00) * weapon4vsS).ToString(".##");
						 W4_MaxDvsSValueLabel->Text = ((weapon4MaxD * 2.00) * weapon4vsS).ToString(".##");
						 W4_MinDvsAValueLabel->Text = ((weapon4MinD * 2.00) * weapon4vsA).ToString(".##");
						 W4_MaxDvsAValueLabel->Text = ((weapon4MaxD * 2.00) * weapon4vsA).ToString(".##");
						 W4_EPSValueLabel->Text = (weapon4EPS * 2.86).ToString(".##");

						 W4_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W4_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W4_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W4_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W4_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon4EPS *= 2.86;
					 break;
				 case 4: W4_MinDvsSValueLabel->Text = ((weapon4MinD * 3.00) * weapon4vsS).ToString(".##");
						 W4_MaxDvsSValueLabel->Text = ((weapon4MaxD * 3.00) * weapon4vsS).ToString(".##");
						 W4_MinDvsAValueLabel->Text = ((weapon4MinD * 3.00) * weapon4vsA).ToString(".##");
						 W4_MaxDvsAValueLabel->Text = ((weapon4MaxD * 3.00) * weapon4vsA).ToString(".##");
						 W4_EPSValueLabel->Text = (weapon4EPS * 5.00).ToString(".##");

						 W4_PvPMinDvsSValueLabel->Text = (Convert::ToDouble(W4_MinDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W4_MaxDvsSValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMinDvsAValueLabel->Text = (Convert::ToDouble(W4_MinDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");
						 W4_PvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W4_MaxDvsAValueLabel->Text->ToString()) * 0.5).ToString(".##");

						 weapon4EPS *= 5.00;
					 break;
				 }
			 }
		 }
private: System::Void SetWeapon1Zero(Weapon^ loadedWeapon1){
			 String^ weapon1Name;
			 System::Data::DataRow^ rowWeapon;

			 Weapon^ tempWeapon = gcnew Weapon();
			 tempWeapon = loadedWeapon1;

			 rowWeapon = tempWeapon[0];

			 weapon1Name = rowWeapon["Name"]->ToString();

			 if (weapon1Name == "None")
			 {
				 W1_MinDvsSValueLabel->Text = "0.0";
				 W1_MaxDvsSValueLabel->Text = "0.0";
				 W1_MinDvsAValueLabel->Text = "0.0";
				 W1_MaxDvsAValueLabel->Text = "0.0";
				 W1_EPSValueLabel->Text = "0.0";

				 W1_PvPMinDvsSValueLabel->Text = "0.0";
				 W1_PvPMaxDvsSValueLabel->Text = "0.0";
				 W1_PvPMinDvsAValueLabel->Text = "0.0";
				 W1_PvPMaxDvsAValueLabel->Text = "0.0";
			 }
		 }
private: System::Void SetWeapon2Zero(Weapon^ loadedWeapon2){
			 String^ weapon2Name;
			 System::Data::DataRow^ rowWeapon;

			 Weapon^ tempWeapon = gcnew Weapon();
			 tempWeapon = loadedWeapon2;

			 rowWeapon = tempWeapon[0];

			 weapon2Name = rowWeapon["Name"]->ToString();

			 if (weapon2Name == "None")
			 {
				 W2_MinDvsSValueLabel->Text = "0.0";
				 W2_MaxDvsSValueLabel->Text = "0.0";
				 W2_MinDvsAValueLabel->Text = "0.0";
				 W2_MaxDvsAValueLabel->Text = "0.0";
				 W2_EPSValueLabel->Text = "0.0";

				 W2_PvPMinDvsSValueLabel->Text = "0.0";
				 W2_PvPMaxDvsSValueLabel->Text = "0.0";
				 W2_PvPMinDvsAValueLabel->Text = "0.0";
				 W2_PvPMaxDvsAValueLabel->Text = "0.0";
			 }
		 }
private: System::Void SetWeapon3Zero(Weapon^ loadedWeapon3){
			 String^ weapon3Name;
			 System::Data::DataRow^ rowWeapon;

			 Weapon^ tempWeapon = gcnew Weapon();
			 tempWeapon = loadedWeapon3;

			 rowWeapon = tempWeapon[0];

			 weapon3Name = rowWeapon["Name"]->ToString();

			 if (weapon3Name == "None")
			 {
				 W3_MinDvsSValueLabel->Text = "0.0";
				 W3_MaxDvsSValueLabel->Text = "0.0";
				 W3_MinDvsAValueLabel->Text = "0.0";
				 W3_MaxDvsAValueLabel->Text = "0.0";
				 W3_EPSValueLabel->Text = "0.0";

				 W3_PvPMinDvsSValueLabel->Text = "0.0";
				 W3_PvPMaxDvsSValueLabel->Text = "0.0";
				 W3_PvPMinDvsAValueLabel->Text = "0.0";
				 W3_PvPMaxDvsAValueLabel->Text = "0.0";
			 }
		 }
private: System::Void SetWeapon4Zero(Weapon^ loadedWeapon4){
			 String^ weapon4Name;
			 System::Data::DataRow^ rowWeapon;

			 Weapon^ tempWeapon = gcnew Weapon();
			 tempWeapon = loadedWeapon4;

			 rowWeapon = tempWeapon[0];

			 weapon4Name = rowWeapon["Name"]->ToString();

			 if (weapon4Name == "None")
			 {
				 W4_MinDvsSValueLabel->Text = "0.0";
				 W4_MaxDvsSValueLabel->Text = "0.0";
				 W4_MinDvsAValueLabel->Text = "0.0";
				 W4_MaxDvsAValueLabel->Text = "0.0";
				 W4_EPSValueLabel->Text = "0.0";

				 W4_PvPMinDvsSValueLabel->Text = "0.0";
				 W4_PvPMaxDvsSValueLabel->Text = "0.0";
				 W4_PvPMinDvsAValueLabel->Text = "0.0";
				 W4_PvPMaxDvsAValueLabel->Text = "0.0";
			 }
		 }
private: System::Void CalculateTotals(){
			 // Overloaded Damages
			 TotalMinDvsSValueLabel->Text = (Convert::ToDouble(W1_MinDvsSValueLabel->Text->ToString()) + Convert::ToDouble(W2_MinDvsSValueLabel->Text->ToString())
				 + Convert::ToDouble(W3_MinDvsSValueLabel->Text->ToString()) + Convert::ToDouble(W4_MinDvsSValueLabel->Text->ToString())).ToString(".##");

			 TotalMaxDvsSValueLabel->Text = (Convert::ToDouble(W1_MaxDvsSValueLabel->Text->ToString()) + Convert::ToDouble(W2_MaxDvsSValueLabel->Text->ToString())
				 + Convert::ToDouble(W3_MaxDvsSValueLabel->Text->ToString()) + Convert::ToDouble(W4_MaxDvsSValueLabel->Text->ToString())).ToString(".##");
			 
			 TotalMinDvsAValueLabel->Text = (Convert::ToDouble(W1_MinDvsAValueLabel->Text->ToString()) + Convert::ToDouble(W2_MinDvsAValueLabel->Text->ToString())
				 + Convert::ToDouble(W3_MinDvsAValueLabel->Text->ToString()) + Convert::ToDouble(W4_MinDvsAValueLabel->Text->ToString())).ToString(".##");
			 
			 TotalMaxDvsAValueLabel->Text = (Convert::ToDouble(W1_MaxDvsAValueLabel->Text->ToString()) + Convert::ToDouble(W2_MaxDvsAValueLabel->Text->ToString())
				 + Convert::ToDouble(W3_MaxDvsAValueLabel->Text->ToString()) + Convert::ToDouble(W4_MaxDvsAValueLabel->Text->ToString())).ToString(".##");

			 TotalEPSValueLabel->Text = (Convert::ToDouble(W1_EPSValueLabel->Text->ToString()) + Convert::ToDouble(W2_EPSValueLabel->Text->ToString())
				 + Convert::ToDouble(W3_EPSValueLabel->Text->ToString()) + Convert::ToDouble(W4_EPSValueLabel->Text->ToString())).ToString(".##");

			 // PvP Damages
			 TotalPvPMinDvsSValueLabel->Text = (Convert::ToDouble(W1_PvPMinDvsSValueLabel->Text->ToString()) + Convert::ToDouble(W2_PvPMinDvsSValueLabel->Text->ToString())
				 + Convert::ToDouble(W3_PvPMinDvsSValueLabel->Text->ToString()) + Convert::ToDouble(W4_PvPMinDvsSValueLabel->Text->ToString())).ToString(".##");

			 TotalPvPMaxDvsSValueLabel->Text = (Convert::ToDouble(W1_PvPMaxDvsSValueLabel->Text->ToString()) + Convert::ToDouble(W2_PvPMaxDvsSValueLabel->Text->ToString())
				 + Convert::ToDouble(W3_PvPMaxDvsSValueLabel->Text->ToString()) + Convert::ToDouble(W4_PvPMaxDvsSValueLabel->Text->ToString())).ToString(".##");
			 
			 TotalPvPMinDvsAValueLabel->Text = (Convert::ToDouble(W1_PvPMinDvsAValueLabel->Text->ToString()) + Convert::ToDouble(W2_PvPMinDvsAValueLabel->Text->ToString())
				 + Convert::ToDouble(W3_PvPMinDvsAValueLabel->Text->ToString()) + Convert::ToDouble(W4_PvPMinDvsAValueLabel->Text->ToString())).ToString(".##");
			 
			 TotalPvPMaxDvsAValueLabel->Text = (Convert::ToDouble(W1_PvPMaxDvsAValueLabel->Text->ToString()) + Convert::ToDouble(W2_PvPMaxDvsAValueLabel->Text->ToString())
				 + Convert::ToDouble(W3_PvPMaxDvsAValueLabel->Text->ToString()) + Convert::ToDouble(W4_PvPMaxDvsAValueLabel->Text->ToString())).ToString(".##");
		 }
private: System::Void CalculateAverageDmg(int selectedWeaponOverload){
			 double WODmgMod;

			 switch (selectedWeaponOverload)
			 {
			 case 0: WODmgMod = 1.00;
				 break;
			 case 1: WODmgMod = 1.25;
				 break;
			 case 2: WODmgMod = 1.50;
				 break;
			 case 3: WODmgMod = 2.00;
				 break;
			 case 4: WODmgMod = 3.00;
				 break;
			 }

			 // Weapon 1
 			 double weapon1AverageDmg;
			 double weapon1Averagevs;
			 double weapon1shotsPerSecond;
			 double weapon1avdmgPerShot;
			 double weapon1avdmgPerSec;

			 weapon1AverageDmg = (weapon1MinD + weapon1MaxD) / 2;
			 weapon1Averagevs = (weapon1vsS + weapon1vsA) / 2;

			 if (weapon1Refire > 0)
			 {
				 weapon1shotsPerSecond = (0.76 / weapon1Refire);
			 }
			 else
			 {
				 weapon1shotsPerSecond = 0.0;
			 }

			 weapon1avdmgPerShot = weapon1AverageDmg * weapon1Averagevs * WODmgMod;
			 weapon1avdmgPerSec = weapon1avdmgPerShot * weapon1shotsPerSecond;

			 // Weapon 2
			 double weapon2AverageDmg;
			 double weapon2Averagevs;
			 double weapon2shotsPerSecond;
			 double weapon2avdmgPerShot;
			 double weapon2avdmgPerSec;

			 weapon2AverageDmg = (weapon2MinD + weapon2MaxD) / 2;
			 weapon2Averagevs = (weapon2vsS + weapon2vsA) / 2;

			 if (weapon2Refire > 0)
			 {
				 weapon2shotsPerSecond = (0.76 / weapon2Refire);
			 }
			 else
			 {
				 weapon2shotsPerSecond = 0.0;
			 }

			 weapon2avdmgPerShot = weapon2AverageDmg * weapon2Averagevs * WODmgMod;
			 weapon2avdmgPerSec = weapon2avdmgPerShot * weapon2shotsPerSecond;

			 // Weapon 3
			 double weapon3AverageDmg;
			 double weapon3Averagevs;
			 double weapon3shotsPerSecond;
			 double weapon3avdmgPerShot;
			 double weapon3avdmgPerSec;

			 weapon3AverageDmg = (weapon3MinD + weapon3MaxD) / 2;
			 weapon3Averagevs = (weapon3vsS + weapon3vsA) / 2;

			 if (weapon3Refire > 0)
			 {
				 weapon3shotsPerSecond = (0.76 / weapon3Refire);
			 }
			 else
			 {
				 weapon3shotsPerSecond = 0.0;
			 }

			 weapon3avdmgPerShot = weapon3AverageDmg * weapon3Averagevs * WODmgMod;
			 weapon3avdmgPerSec = weapon3avdmgPerShot * weapon3shotsPerSecond;

			 // Weapon 4
			 double weapon4AverageDmg;
			 double weapon4Averagevs;
			 double weapon4shotsPerSecond;
			 double weapon4avdmgPerShot;
			 double weapon4avdmgPerSec;

			 weapon4AverageDmg = (weapon4MinD + weapon4MaxD) / 2;
			 weapon4Averagevs = (weapon4vsS + weapon4vsA) / 2;

			 if (weapon4Refire > 0)
			 {
				 weapon4shotsPerSecond = (0.76 / weapon4Refire);
			 }
			 else
			 {
				 weapon4shotsPerSecond = 0.0;
			 }

			 weapon4avdmgPerShot = weapon4AverageDmg * weapon4Averagevs * WODmgMod;
			 weapon4avdmgPerSec = weapon4avdmgPerShot * weapon4shotsPerSecond;

			 // Result
			 AvDmgPerShotValueLabel->Text = (weapon1avdmgPerShot + weapon2avdmgPerShot + weapon3avdmgPerShot + weapon4avdmgPerShot).ToString(".##");
			 AvDmgPerSecondValueLabel->Text = (weapon1avdmgPerSec + weapon2avdmgPerSec + weapon3avdmgPerSec + weapon4avdmgPerSec).ToString(".##");
		 }
private: System::Void CalculateCapacitorValues(Capacitor^ loadedCapacitor, int selectedCapacitorOverload){
			 double COMod;

			 switch (selectedCapacitorOverload)
			 {
			 case 0: COMod = 1.00;
				 break;
			 case 1: COMod = 1.25;
				 break;
			 case 2: COMod = 1.50;
				 break;
			 case 3: COMod = 1.75;
				 break;
			 case 4: COMod = 2.00;
				 break;
			 }

			 String^ capacitorName;
			 double capacitorEnergy;
			 double capacitorRecharge;

			 double weapon1EPsec;
			 double weapon2EPsec;
			 double weapon3EPsec;
			 double weapon4EPsec;

			 double weapon1FreeFireTime;
			 double weapon2FreeFireTime;
			 double weapon3FreeFireTime;
			 double weapon4FreeFireTime;

			 double weapon1shotsPerSecond;
			 double weapon2shotsPerSecond;
			 double weapon3shotsPerSecond;
			 double weapon4shotsPerSecond;

			 System::Data::DataRow^ rowCapacitor;

			 Capacitor^ tempCapacitor = gcnew Capacitor();
			 tempCapacitor = loadedCapacitor;

			 rowCapacitor = tempCapacitor[0];

			 capacitorName = rowCapacitor["Name"]->ToString();
			 capacitorEnergy = Convert::ToDouble(rowCapacitor["Energy"]->ToString());
			 capacitorRecharge = Convert::ToDouble(rowCapacitor["Recharge"]->ToString());

			 if (capacitorName != "None")
			 {
				 capacitorEnergy *= COMod;
				 capacitorRecharge *= COMod;

				 OCapEnergyValueLabel->Text = capacitorEnergy.ToString(".##");
				 OCapRechargeTimeValueLabel->Text = (capacitorEnergy / capacitorRecharge).ToString(".##");

				 // Weapon 1
				 if (weapon1Refire > 0)
				 {
					 weapon1shotsPerSecond = (0.76 / weapon1Refire);
					 weapon1EPsec = weapon1EPS * weapon1shotsPerSecond;
				 }
				 else
				 {
					 weapon1FreeFireTime = 0.0;
				 }

				 // Weapon 2
				 if (weapon2Refire > 0)
				 {
					 weapon2shotsPerSecond = (0.76 / weapon2Refire);
					 weapon2EPsec = weapon2EPS * weapon2shotsPerSecond;
				 }
				 else
				 {
					 weapon2FreeFireTime = 0.0;
				 }

				 // Weapon 3
				 if (weapon3Refire > 0)
				 {
					 weapon3shotsPerSecond = (0.76 / weapon3Refire);
					 weapon3EPsec = weapon3EPS * weapon3shotsPerSecond;
				 }
				 else
				 {
					 weapon3FreeFireTime = 0.0;
				 }

				 // Weapon 4
				 if (weapon4Refire > 0)
				 {
					 weapon4shotsPerSecond = (0.76 / weapon4Refire);
					 weapon4EPsec = weapon4EPS * weapon4shotsPerSecond;
				 }
				 else
				 {
					 weapon4FreeFireTime = 0.0;
				 }

				 OCapFullFireTimeValueLabel->Text = (capacitorEnergy / ((weapon1EPsec + weapon2EPsec + weapon3EPsec + weapon4EPsec) - capacitorRecharge)).ToString(".##");
				 
				 if (Convert::ToDouble(OCapFullFireTimeValueLabel->Text->ToString()) < 0)
				 {
					 OCapFullFireTimeValueLabel->Text = "Infinite";
				 }
			 }
		 }
private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
};
}
