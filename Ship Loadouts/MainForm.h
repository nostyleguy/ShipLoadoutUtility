#pragma once
#include "MassDrainSummaryForm.h"
#include "WeaponStatsForm.h"
#include "PropulsionStatsForm.h"
#include "ProtectionStatsForm.h"
#include "ReactorCalcForm.h"
#include "ComponentManagementForm.h"
#include "ShipNamePrompt.h"
#include "AboutForm.h"
#include "RECalc.h"

namespace ShipLoadouts {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MainForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();

			appdir = IO::Directory::GetCurrentDirectory();

			bool error = false;

			if (System::IO::File::Exists(String::Concat(appdir, "\\", complibdirectory)) == true)
			{
				LoadExistingCompLibFile();
			}
			else
			{
				if (MessageBox::Show("Existing Componet Library file not found, please place the backup provided in the program's directory in the CompLib folder and reaname to 'complib.xml'.", 
					"No CompLib File", MessageBoxButtons::OK, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::OK)
				{
					error = true;
				}
			}

			if (error != true)
			{
				ShipChassisComboBox->Enabled = false;
				ReactorPanel->Enabled = false;
				EnginePanel->Enabled = false;
				ArmorPanel->Enabled = false;
				BoosterPanel->Enabled = false;
				CapacitorPanel->Enabled = false;
				DroidPanel->Enabled = false;
				CountermeasuresPanel->Enabled = false;
				Ordinance1Panel->Enabled = false;
				Ordinance2Panel->Enabled = false;
				Ordinance3Panel->Enabled = false;
				Weapon1Panel->Enabled = false;
				Weapon2Panel->Enabled = false;
				Weapon3Panel->Enabled = false;
				Weapon4Panel->Enabled = false;
				SheildPanel->Enabled = false;
				ReactorOverloadComboBox->Enabled = false;
				EngineOverloadComboBox->Enabled = false;
				WeaponOverloadComboBox->Enabled = false;
				CapacitorOverloadComboBox->Enabled = false;

				Reset();

				changesMade = false;
			}
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	#pragma region MainForm item declarations

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newShipToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openShipToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveShiploadoutToolStripMenuItem;

	private: System::Windows::Forms::Label^  ShipNameLabel;
	private: System::Windows::Forms::Label^  TotalMassLabel;
	private: System::Windows::Forms::Label^  ShipMassUsedLabel;
	private: System::Windows::Forms::Label^  LeftoverMassLabel;

	private: System::Windows::Forms::Label^  OverloadsLabel;
	private: System::Windows::Forms::Label^  ReactorOverloadLabel;
	private: System::Windows::Forms::Label^  EngineOverloadLabel;
	private: System::Windows::Forms::Label^  WeaponOverloadLabel;
	private: System::Windows::Forms::Label^  CapacitorOverloadLabel;

	private: System::Windows::Forms::Label^  ShipChassisLabel;
	private: System::Windows::Forms::ComboBox^  ShipChassisComboBox;

	private: System::Windows::Forms::ComboBox^  ReactorOverloadComboBox;
	private: System::Windows::Forms::ComboBox^  WeaponOverloadComboBox;
	private: System::Windows::Forms::ComboBox^  EngineOverloadComboBox;
	private: System::Windows::Forms::ComboBox^  CapacitorOverloadComboBox;

	private: System::Windows::Forms::Label^  ReactorStatusLabel;
	private: System::Windows::Forms::Label^  EngineStatusLabel;
	private: System::Windows::Forms::Label^  SheildStatusLabel;
	private: System::Windows::Forms::Label^  FArmorStatusLabel;
	private: System::Windows::Forms::Label^  RArmorLabel;
	private: System::Windows::Forms::Label^  CapacitorStatusLabel;
	private: System::Windows::Forms::Label^  BoosterStatusLabel;
	private: System::Windows::Forms::Label^  DriodStatusLabel;
	private: System::Windows::Forms::Label^  Weapon1StatusLabel;
	private: System::Windows::Forms::Label^  Weapon2StatusLabel;
	private: System::Windows::Forms::Label^  Weapon3StatusLabel;
	private: System::Windows::Forms::Label^  Weapon4StatusLabel;
	private: System::Windows::Forms::Label^  Ordinance1StatusLabel;
	private: System::Windows::Forms::Label^  Ordinance2StatusLabel;
	private: System::Windows::Forms::Label^  Ordinance3StatusLabel;
	private: System::Windows::Forms::Label^  CountermeasuresStatusLabel;
	private: System::Windows::Forms::Label^  ShipStatusLabel;

	private: System::Windows::Forms::Label^  ReactorGBLabel;
	private: System::Windows::Forms::Label^  EngineGBLabel;
	private: System::Windows::Forms::Label^  SheildGBLabel;
	private: System::Windows::Forms::Label^  FArmorGBLabel;
	private: System::Windows::Forms::Label^  RArmorGBLabel;
	private: System::Windows::Forms::Label^  CapacitorGBLabel;
	private: System::Windows::Forms::Label^  BoosterGBLabel;
	private: System::Windows::Forms::Label^  DroidGBLabel;
	private: System::Windows::Forms::Label^  Weapon1GBLabel;
	private: System::Windows::Forms::Label^  Weapon2GBLabel;
	private: System::Windows::Forms::Label^  Weapon3GBLabel;
	private: System::Windows::Forms::Label^  Weapon4GBLabel;
	private: System::Windows::Forms::Label^  OrdinanceGBLabel;
	private: System::Windows::Forms::Label^  Ordinance2GBLabel;
	private: System::Windows::Forms::Label^  Ordinance3GBLabel;
	private: System::Windows::Forms::Label^  CountermeasuresGBLabel;

	private: System::Windows::Forms::Label^  R_ArmorLabel;
	private: System::Windows::Forms::Label^  R_MassLabel;
	private: System::Windows::Forms::Label^  R_GenerationLabel;
	private: System::Windows::Forms::Label^  R_ArmorValueLabel;
	private: System::Windows::Forms::Label^  R_MassValueLabel;
	private: System::Windows::Forms::Label^  R_GenerationValueLabel;

	private: System::Windows::Forms::Label^  E_ArmorLabel;
	private: System::Windows::Forms::Label^  E_MassLabel;
	private: System::Windows::Forms::Label^  E_DrainLabel;
	private: System::Windows::Forms::Label^  E_PitchLabel;
	private: System::Windows::Forms::Label^  E_YawLabel;
	private: System::Windows::Forms::Label^  E_RollLabel;
	private: System::Windows::Forms::Label^  E_SpeedLabel;
	private: System::Windows::Forms::Label^  E_ArmorValueLabel;
	private: System::Windows::Forms::Label^  E_MassValueLabel;
	private: System::Windows::Forms::Label^  E_DrainValueLabel;
	private: System::Windows::Forms::Label^  E_PitchValueLabel;
	private: System::Windows::Forms::Label^  E_YawValueLabel;
	private: System::Windows::Forms::Label^  E_RollValueLabel;
	private: System::Windows::Forms::Label^  E_SpeedValueLabel;

	private: System::Windows::Forms::Label^  B_ArmorLabel;
	private: System::Windows::Forms::Label^  B_MassLabel;
	private: System::Windows::Forms::Label^  B_DrainLabel;
	private: System::Windows::Forms::Label^  B_EnergyLabel;
	private: System::Windows::Forms::Label^  B_RechargeLabel;
	private: System::Windows::Forms::Label^  B_ConsumptionLabel;
	private: System::Windows::Forms::Label^  B_AccelerationLabel;
	private: System::Windows::Forms::Label^  B_SpeedLabel;
	private: System::Windows::Forms::Label^  B_ArmorValueLabel;
	private: System::Windows::Forms::Label^  B_MassValueLabel;
	private: System::Windows::Forms::Label^  B_DrainValueLabel;
	private: System::Windows::Forms::Label^  B_EnergyValueLabel;
	private: System::Windows::Forms::Label^  B_RechargeValueLabel;
	private: System::Windows::Forms::Label^  B_ConsumptionValueLabel;
	private: System::Windows::Forms::Label^  B_AccelerationValueLabel;
	private: System::Windows::Forms::Label^  B_SpeedValueLabel;

	private: System::Windows::Forms::Label^  S_ArmorLabel;
	private: System::Windows::Forms::Label^  S_MassLabel;
	private: System::Windows::Forms::Label^  S_DrainLabel;
	private: System::Windows::Forms::Label^  S_FrontHPLabel;
	private: System::Windows::Forms::Label^  S_BackHPLabel;
	private: System::Windows::Forms::Label^  S_RechargeLabel;
	private: System::Windows::Forms::Label^  S_AdjustmentLabel;
	private: System::Windows::Forms::Label^  S_ArmorValueLabel;
	private: System::Windows::Forms::Label^  S_MassValueLabel;
	private: System::Windows::Forms::Label^  S_DrainValueLabel;
	private: System::Windows::Forms::Label^  S_FrontHPValueLabel;
	private: System::Windows::Forms::Label^  S_BackHPValueLabel;
	private: System::Windows::Forms::Label^  S_RechargeValueLabel;
	private: System::Windows::Forms::Label^  S_AdjustmentValueLabel;
	
	private: System::Windows::Forms::Label^  FA_MassLabel;
	private: System::Windows::Forms::Label^  FA_ArmorLabel;
	private: System::Windows::Forms::Label^  FA_MassValueLabel;
	private: System::Windows::Forms::Label^  FA_ArmorValueLabel;
	private: System::Windows::Forms::Label^  RA_MassLabel;
	private: System::Windows::Forms::Label^  RA_ArmorLabel;
	private: System::Windows::Forms::Label^  RA_MassValueLabel;
	private: System::Windows::Forms::Label^  RA_ArmorValueLabel;

	private: System::Windows::Forms::Label^  D_ArmorLabel;
	private: System::Windows::Forms::Label^  D_MassLabel;
	private: System::Windows::Forms::Label^  D_DrainLabel;
	private: System::Windows::Forms::Label^  D_SpeedLabel;
	private: System::Windows::Forms::Label^  D_ArmorValueLabel;
	private: System::Windows::Forms::Label^  D_MassValueLabel;
	private: System::Windows::Forms::Label^  D_DrainValueLabel;
	private: System::Windows::Forms::Label^  D_SpeedValueLabel;

	private: System::Windows::Forms::Label^  C_ArmorLabel;
	private: System::Windows::Forms::Label^  C_MassLabel;
	private: System::Windows::Forms::Label^  C_DrainLabel;
	private: System::Windows::Forms::Label^  C_EnergyLabel;
	private: System::Windows::Forms::Label^  C_RechargeLabel;
	private: System::Windows::Forms::Label^  C_ArmorValueLabel;
	private: System::Windows::Forms::Label^  C_MassValueLabel;
	private: System::Windows::Forms::Label^  C_DrainValueLabel;
	private: System::Windows::Forms::Label^  C_EnergyValueLabel;
	private: System::Windows::Forms::Label^  C_RechargeValueLabel;

	private: System::Windows::Forms::Label^  W1_ArmorLabel;
	private: System::Windows::Forms::Label^  W1_MassLabel;
	private: System::Windows::Forms::Label^  W1_DrainLabel;
	private: System::Windows::Forms::Label^  W1_MinDLabel;
	private: System::Windows::Forms::Label^  W1_MaxDLabel;
	private: System::Windows::Forms::Label^  W1_vsSLabel;
	private: System::Windows::Forms::Label^  W1_vsALabel;
	private: System::Windows::Forms::Label^  W1_EPSLabel;
	private: System::Windows::Forms::Label^  W1_RefireLabel;
	private: System::Windows::Forms::Label^  W1_RefireValueLabel;
	private: System::Windows::Forms::Label^  W1_EPSValueLabel;
	private: System::Windows::Forms::Label^  W1_vsAValueLabel;
	private: System::Windows::Forms::Label^  W1_vsSValueLabel;
	private: System::Windows::Forms::Label^  W1_MaxDValueLabel;
	private: System::Windows::Forms::Label^  W1_MinDValueLabel;
	private: System::Windows::Forms::Label^  W1_DrainValueLabel;
	private: System::Windows::Forms::Label^  W1_MassValueLabel;
	private: System::Windows::Forms::Label^  W1_ArmorValueLabel;

	private: System::Windows::Forms::Label^  W2_RefireValueLabel;
	private: System::Windows::Forms::Label^  W2_EPSValueLabel;
	private: System::Windows::Forms::Label^  W2_vsAValueLabel;
	private: System::Windows::Forms::Label^  W2_vsSValueLabel;
	private: System::Windows::Forms::Label^  W2_MaxDValueLabel;
	private: System::Windows::Forms::Label^  W2_MinDValueLabel;
	private: System::Windows::Forms::Label^  W2_DrainValueLabel;
	private: System::Windows::Forms::Label^  W2_MassValueLabel;
	private: System::Windows::Forms::Label^  W2_ArmorValueLabel;
	private: System::Windows::Forms::Label^  W2_RefireLabel;
	private: System::Windows::Forms::Label^  W2_EPSLabel;
	private: System::Windows::Forms::Label^  W2_vsALabel;
	private: System::Windows::Forms::Label^  W2_vsSLabel;
	private: System::Windows::Forms::Label^  W2_MaxDLabel;
	private: System::Windows::Forms::Label^  W2_MinDLabel;
	private: System::Windows::Forms::Label^  W2_DrainLabel;
	private: System::Windows::Forms::Label^  W2_MassLabel;
	private: System::Windows::Forms::Label^  W2_ArmorLabel;

	private: System::Windows::Forms::Label^  W3_RefireValueLabel;
	private: System::Windows::Forms::Label^  W3_EPSValueLabel;
	private: System::Windows::Forms::Label^  W3_vsAValueLabel;
	private: System::Windows::Forms::Label^  W3_vsSValueLabel;
	private: System::Windows::Forms::Label^  W3_MaxDValueLabel;
	private: System::Windows::Forms::Label^  W3_MinDValueLabel;
	private: System::Windows::Forms::Label^  W3_DrainValueLabel;
	private: System::Windows::Forms::Label^  W3_MassValueLabel;
	private: System::Windows::Forms::Label^  W3_ArmorValueLabel;
	private: System::Windows::Forms::Label^  W3_RefireLabel;
	private: System::Windows::Forms::Label^  W3_EPSLabel;
	private: System::Windows::Forms::Label^  W3_vsALabel;
	private: System::Windows::Forms::Label^  W3_vsSLabel;
	private: System::Windows::Forms::Label^  W3_MaxDLabel;
	private: System::Windows::Forms::Label^  W3_MinDLabel;
	private: System::Windows::Forms::Label^  W3_DrainLabel;
	private: System::Windows::Forms::Label^  W3_MassLabel;
	private: System::Windows::Forms::Label^  W3_ArmorLabel;

	private: System::Windows::Forms::Label^  W4_RefireValueLabel;
	private: System::Windows::Forms::Label^  W4_EPSValueLabel;
	private: System::Windows::Forms::Label^  W4_vsAValueLabel;
	private: System::Windows::Forms::Label^  W4_vsSValueLabel;
	private: System::Windows::Forms::Label^  W4_MaxDValueLabel;
	private: System::Windows::Forms::Label^  W4_MinDValueLabel;
	private: System::Windows::Forms::Label^  W4_DrainValueLabel;
	private: System::Windows::Forms::Label^  W4_MassValueLabel;
	private: System::Windows::Forms::Label^  W4_ArmorValueLabel;
	private: System::Windows::Forms::Label^  W4_RefireLabel;
	private: System::Windows::Forms::Label^  W4_EPSLabel;
	private: System::Windows::Forms::Label^  W4_vsALabel;
	private: System::Windows::Forms::Label^  W4_vsSLabel;
	private: System::Windows::Forms::Label^  W4_MaxDLabel;
	private: System::Windows::Forms::Label^  W4_MinDLabel;
	private: System::Windows::Forms::Label^  W4_DrainLabel;
	private: System::Windows::Forms::Label^  W4_MassLabel;
	private: System::Windows::Forms::Label^  W4_ArmorLabel;

	private: System::Windows::Forms::Label^  O1_AmmoValueLabel;
	private: System::Windows::Forms::Label^  O1_vsAValueLabel;
	private: System::Windows::Forms::Label^  O1_vsSValueLabel;
	private: System::Windows::Forms::Label^  O1_MaxDValueLabel;
	private: System::Windows::Forms::Label^  O1_MinDValueLabel;
	private: System::Windows::Forms::Label^  O1_DrainValueLabel;
	private: System::Windows::Forms::Label^  O1_MassValueLabel;
	private: System::Windows::Forms::Label^  O1_ArmorValueLabel;
	private: System::Windows::Forms::Label^  O1_AmmoLabel;
	private: System::Windows::Forms::Label^  O1_vsALabel;
	private: System::Windows::Forms::Label^  O1_vsSLabel;
	private: System::Windows::Forms::Label^  O1_MaxDLabel;
	private: System::Windows::Forms::Label^  O1_MinDLabel;
	private: System::Windows::Forms::Label^  O1_DrainLabel;
	private: System::Windows::Forms::Label^  O1_MassLabel;
	private: System::Windows::Forms::Label^  O1_ArmorLabel;

	private: System::Windows::Forms::Label^  O2_AmmoValueLabel;
	private: System::Windows::Forms::Label^  O2_vsAValueLabel;
	private: System::Windows::Forms::Label^  O2_vsSValueLabel;
	private: System::Windows::Forms::Label^  O2_MaxDValueLabel;
	private: System::Windows::Forms::Label^  O2_MinDValueLabel;
	private: System::Windows::Forms::Label^  O2_DrainValueLabel;
	private: System::Windows::Forms::Label^  O2_MassValueLabel;
	private: System::Windows::Forms::Label^  O2_ArmorValueLabel;
	private: System::Windows::Forms::Label^  O2_AmmoLabel;
	private: System::Windows::Forms::Label^  O2_vsALabel;
	private: System::Windows::Forms::Label^  O2_vsSLabel;
	private: System::Windows::Forms::Label^  O2_MaxDLabel;
	private: System::Windows::Forms::Label^  O2_MinDLabel;
	private: System::Windows::Forms::Label^  O2_DrainLabel;
	private: System::Windows::Forms::Label^  O2_MassLabel;
	private: System::Windows::Forms::Label^  O2_ArmorLabel;
	private: System::Windows::Forms::Label^  O3_MinDValueLabel;
	private: System::Windows::Forms::Label^  CM_DrainValueLabel;
	private: System::Windows::Forms::Label^  CM_MassValueLabel;
	private: System::Windows::Forms::Label^  CM_ArmorValueLabel;
	private: System::Windows::Forms::Label^  CM_DrainLabel;
	private: System::Windows::Forms::Label^  CM_MassLabel;
	private: System::Windows::Forms::Label^  CM_ArmorLabel;

	private: System::Windows::Forms::Label^  ComponentsLabel;

	private: System::Windows::Forms::Label^  ReactorCompLabel;
	private: System::Windows::Forms::Label^  EngineCompLabel;
	private: System::Windows::Forms::Label^  BoosterCompLabel;
	private: System::Windows::Forms::Label^  SheildCompLabel;
	private: System::Windows::Forms::Label^  FArmorCompLabel;

	private: System::Windows::Forms::Label^  DroidCompLabel;

	private: System::Windows::Forms::Label^  CapacitorCompLabel;
	private: System::Windows::Forms::Label^  Ordinanace1CompLabel;
	private: System::Windows::Forms::Label^  Ordinance2CompLabel;
	private: System::Windows::Forms::Label^  Ordinance3CompLabel;
	private: System::Windows::Forms::Label^  Weapon1CompLabel;
	private: System::Windows::Forms::Label^  Weapon2CompLabel;
	private: System::Windows::Forms::Label^  Weapon3CompLabel;
	private: System::Windows::Forms::Label^  Weapon4CompLabel;
	private: System::Windows::Forms::Label^  CountermeasuresCompLabel;

	private: System::Windows::Forms::Label^  TotalDrainValueLabel;
	private: System::Windows::Forms::Label^  TotalDrainLabel;

	private: System::Windows::Forms::ToolStripMenuItem^  shipStatisticsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  massDrainSummaryToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  propulsionStatsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  protectionStatsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  weaponStatsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeShipLoadoutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;

	private: System::Windows::Forms::ComboBox^  ReactorComboBox;
	private: System::Windows::Forms::ComboBox^  Weapon2ComboBox;
	private: System::Windows::Forms::ComboBox^  Weapon1ComboBox;
	private: System::Windows::Forms::ComboBox^  Ordinance3ComboBox;
	private: System::Windows::Forms::ComboBox^  Ordinance2ComboBox;
	private: System::Windows::Forms::ComboBox^  Ordinance1ComboBox;
	private: System::Windows::Forms::ComboBox^  CapacitorComboBox;
	private: System::Windows::Forms::ComboBox^  DroidComboBox;
	private: System::Windows::Forms::ComboBox^  RArmorComboBox;
	private: System::Windows::Forms::ComboBox^  FArmorComboBox;
	private: System::Windows::Forms::ComboBox^  SheildComboBox;
	private: System::Windows::Forms::ComboBox^  BoosterComboBox;
	private: System::Windows::Forms::ComboBox^  EngineComboBox;
	private: System::Windows::Forms::ComboBox^  Weapon4ComboBox;
	private: System::Windows::Forms::ComboBox^  Weapon3ComboBox;
	private: System::Windows::Forms::ComboBox^  CountermeasuresComboBox;

	private: System::Windows::Forms::ToolStripMenuItem^  componentsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addComponentToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  ShipNameValueLabel;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

	private: System::Windows::Forms::Label^  TotalShipMassValueLabel;
	private: System::Windows::Forms::Label^  ShipMassUsedValueLabel;
	private: System::Windows::Forms::Label^  LeftoverMassUsedValueLabel;

	private: System::Windows::Forms::Panel^  EnginePanel;
	private: System::Windows::Forms::Panel^  BoosterPanel;
	private: System::Windows::Forms::Panel^  Weapon1Panel;
	private: System::Windows::Forms::Panel^  Weapon2Panel;
	private: System::Windows::Forms::Panel^  Weapon3Panel;
	private: System::Windows::Forms::Panel^  Weapon4Panel;
	private: System::Windows::Forms::Panel^  CapacitorPanel;
	private: System::Windows::Forms::Panel^  Ordinance1Panel;
	private: System::Windows::Forms::Panel^  Ordinance2Panel;
	private: System::Windows::Forms::Label^  O3_AmmoValueLabel;
	private: System::Windows::Forms::Label^  O3_vsAValueLabel;
	private: System::Windows::Forms::Label^  O3_vsSValueLabel;
	private: System::Windows::Forms::Label^  O3_MaxDValueLabel;
	private: System::Windows::Forms::Label^  O3_DrainValueLabel;
	private: System::Windows::Forms::Label^  O3_MassValueLabel;
	private: System::Windows::Forms::Label^  O3_ArmorValueLabel;
	private: System::Windows::Forms::Label^  O3_AmmoLabel;
	private: System::Windows::Forms::Label^  O3_vsALabel;
	private: System::Windows::Forms::Label^  O3_vsSLabel;
	private: System::Windows::Forms::Label^  O3_MaxDLabel;
	private: System::Windows::Forms::Label^  O3_MinDLabel;
	private: System::Windows::Forms::Label^  O3_DrianLabel;
	private: System::Windows::Forms::Label^  O3_MassLabel;
	private: System::Windows::Forms::Label^  O3_ArmorLabel;
	private: System::Windows::Forms::Panel^  Ordinance3Panel;
	private: System::Windows::Forms::Panel^  ArmorPanel;
	private: System::Windows::Forms::Panel^  SheildPanel;
	private: System::Windows::Forms::Panel^  CountermeasuresPanel;
	private: System::Windows::Forms::Panel^  ReactorPanel;
	private: System::Windows::Forms::Panel^  DroidPanel;
	private: System::Windows::Forms::Panel^  ShipInfoPanel;
	private: System::Windows::Forms::Panel^  OverloadPanel;
	private: System::Windows::Forms::Panel^  ShipStatusPanel;

	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rECalculatorToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  reactorCalculatorToolStripMenuItem1;

	#pragma endregion

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Globals

		///
		/// Create a list of the saved ships
		///
		static List<CompLib::ShipInfo^>^ ShipInfoList = gcnew List<CompLib::ShipInfo^>();
		///
		/// Create a list of each component type.
		///
		static List<CompLib::Armor^>^ ArmorList = gcnew List<CompLib::Armor^>();
		static List<CompLib::Booster^>^ BoosterList = gcnew List<CompLib::Booster^>();
		static List<CompLib::Chaff^>^ ChaffList = gcnew List<CompLib::Chaff^>();
		static List<CompLib::Capacitor^>^ CapacitorList = gcnew List<CompLib::Capacitor^>();
		static List<CompLib::Droid^>^ DroidList = gcnew List<CompLib::Droid^>();
		static List<CompLib::Engine^>^ EngineList = gcnew List<CompLib::Engine^>();
		static List<CompLib::Ordinance^>^ OrdinanceList = gcnew List<CompLib::Ordinance^>();
		static List<CompLib::Reactor^>^ ReactorList = gcnew List<CompLib::Reactor^>();
		static List<CompLib::Sheild^>^ SheildList = gcnew List<CompLib::Sheild^>();
		static List<CompLib::Weapon^>^ WeaponList = gcnew List<CompLib::Weapon^>();
		///
		/// Create a list of each component type name.
		///
		static List<String^>^ ArmorNameList = gcnew List<String^>();
		static List<String^>^ BoosterNameList = gcnew List<String^>();
		static List<String^>^ ChaffNameList = gcnew List<String^>();
		static List<String^>^ CapacitorNameList = gcnew List<String^>();
		static List<String^>^ DroidNameList = gcnew List<String^>();
		static List<String^>^ EngineNameList = gcnew List<String^>();
		static List<String^>^ OrdinanceNameList = gcnew List<String^>();
		static List<String^>^ ReactorNameList = gcnew List<String^>();
		static List<String^>^ SheildNameList = gcnew List<String^>();
		static List<String^>^ WeaponNameList = gcnew List<String^>();
		///
		/// State Tracking Variables
		///
		static bool changesMade = false;

		static String^ currentReactorSelectedIndex = "";
		static String^ currentEngineSelectedIndex = "";
		static String^ currentBoosterSelectedIndex = "";
		static String^ currentSheildSelectedIndex = "";
		static String^ currentFArmorSelectedIndex = "";
		static String^ currentRArmorSelectedIndex = "";
		static String^ currentDroidSelectedIndex = "";
		static String^ currentCapacitorSelectedIndex = "";
		static String^ currentOrdinance1SelectedIndex = "";
		static String^ currentOrdinance2SelectedIndex = "";
		static String^ currentOrdinance3SelectedIndex = "";
		static String^ currentWeapon1SelectedIndex = "";
		static String^ currentWeapon2SelectedIndex = "";
		static String^ currentWeapon3SelectedIndex = "";
		static String^ currentWeapon4SelectedIndex = "";
		static String^ currentChaffSelectedIndex = "";

		static double currentMassUsed = 0;
		static double currentLeftoverMass = 0;
		static double currentDrainTotal = 0;

		static char compChanged;
		
		static double currentCompMass;

		static double currentReactorMass = 0;
		static double currentEngineMass = 0;
		static double currentBoosterMass = 0;
		static double currentSheildMass = 0;
		static double currentFArmorMass = 0;
		static double currentRArmorMass = 0;
		static double currentDroidMass = 0;
		static double currentCapacitorMass = 0;
		static double currentOrdinance1Mass = 0;
		static double currentOrdinance2Mass = 0;
		static double currentOrdinance3Mass = 0;
		static double currentWeapon1Mass = 0;
		static double currentWeapon2Mass = 0;
		static double currentWeapon3Mass = 0;
		static double currentWeapon4Mass = 0;
		static double currentChaffMass = 0;

		static double currentCompDrain = 0;

		static double currentReactorGeneration = 0;
		static double currentReactorOverloadedGeneration = 0;
		static double currentEngineDrain = 0;
		static double currentEngineOverloadedDrain = 0;
		static double currentBoosterDrain = 0;
		static double currentSheildDrain = 0;
		static double currentFArmorDrain = 0;
		static double currentRArmorDrain = 0;
		static double currentDroidDrain = 0;
		static double currentCapacitorDrain = 0;
		static double currentOrdinance1Drain = 0;
		static double currentOrdinance1OverloadedDrain = 0;
		static double currentOrdinance2Drain = 0;
		static double currentOrdinance2OverloadedDrain = 0;
		static double currentOrdinance3Drain = 0;
		static double currentOrdinance3OverloadedDrain = 0;
		static double currentWeapon1Drain = 0;
		static double currentWeapon1OverloadedDrain = 0;
		static double currentWeapon2Drain = 0;
		static double currentWeapon2OverloadedDrain = 0;
		static double currentWeapon3Drain = 0;
		static double currentWeapon3OverloadedDrain = 0;
		static double currentWeapon4Drain = 0;
		static double currentWeapon4OverloadedDrain = 0;
		static double currentChaffDrain = 0;
		static double currentChaffOverloadedDrain = 0;

		static String^ appdir = "";
		static String^ complibdirectory = "CompLib\\complib.xml";
		static String^ backupdirectory = "CompLib\\Backup\\backupcomplib.xml";

#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newShipToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openShipToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->saveShiploadoutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeShipLoadoutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->componentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addComponentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->shipStatisticsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->massDrainSummaryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->propulsionStatsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->protectionStatsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->weaponStatsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rECalculatorToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reactorCalculatorToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ShipNameLabel = (gcnew System::Windows::Forms::Label());
			this->TotalMassLabel = (gcnew System::Windows::Forms::Label());
			this->ShipMassUsedLabel = (gcnew System::Windows::Forms::Label());
			this->LeftoverMassLabel = (gcnew System::Windows::Forms::Label());
			this->OverloadsLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorOverloadLabel = (gcnew System::Windows::Forms::Label());
			this->EngineOverloadLabel = (gcnew System::Windows::Forms::Label());
			this->WeaponOverloadLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorOverloadLabel = (gcnew System::Windows::Forms::Label());
			this->ShipChassisLabel = (gcnew System::Windows::Forms::Label());
			this->ShipChassisComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ReactorOverloadComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->WeaponOverloadComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->EngineOverloadComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CapacitorOverloadComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ReactorStatusLabel = (gcnew System::Windows::Forms::Label());
			this->EngineStatusLabel = (gcnew System::Windows::Forms::Label());
			this->SheildStatusLabel = (gcnew System::Windows::Forms::Label());
			this->FArmorStatusLabel = (gcnew System::Windows::Forms::Label());
			this->RArmorLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorStatusLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterStatusLabel = (gcnew System::Windows::Forms::Label());
			this->DriodStatusLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon1StatusLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon2StatusLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon3StatusLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon4StatusLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance1StatusLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance2StatusLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance3StatusLabel = (gcnew System::Windows::Forms::Label());
			this->CountermeasuresStatusLabel = (gcnew System::Windows::Forms::Label());
			this->ShipStatusLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorGBLabel = (gcnew System::Windows::Forms::Label());
			this->EngineGBLabel = (gcnew System::Windows::Forms::Label());
			this->SheildGBLabel = (gcnew System::Windows::Forms::Label());
			this->FArmorGBLabel = (gcnew System::Windows::Forms::Label());
			this->RArmorGBLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorGBLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterGBLabel = (gcnew System::Windows::Forms::Label());
			this->DroidGBLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon1GBLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon2GBLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon3GBLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon4GBLabel = (gcnew System::Windows::Forms::Label());
			this->OrdinanceGBLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance2GBLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance3GBLabel = (gcnew System::Windows::Forms::Label());
			this->CountermeasuresGBLabel = (gcnew System::Windows::Forms::Label());
			this->R_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->R_MassLabel = (gcnew System::Windows::Forms::Label());
			this->R_GenerationLabel = (gcnew System::Windows::Forms::Label());
			this->R_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->R_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->R_GenerationValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->E_MassLabel = (gcnew System::Windows::Forms::Label());
			this->E_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->E_PitchLabel = (gcnew System::Windows::Forms::Label());
			this->E_YawLabel = (gcnew System::Windows::Forms::Label());
			this->E_RollLabel = (gcnew System::Windows::Forms::Label());
			this->E_SpeedLabel = (gcnew System::Windows::Forms::Label());
			this->E_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_PitchValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_YawValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_RollValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_SpeedValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->B_MassLabel = (gcnew System::Windows::Forms::Label());
			this->B_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->B_EnergyLabel = (gcnew System::Windows::Forms::Label());
			this->B_RechargeLabel = (gcnew System::Windows::Forms::Label());
			this->B_ConsumptionLabel = (gcnew System::Windows::Forms::Label());
			this->B_AccelerationLabel = (gcnew System::Windows::Forms::Label());
			this->B_SpeedLabel = (gcnew System::Windows::Forms::Label());
			this->B_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_EnergyValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_RechargeValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_ConsumptionValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_AccelerationValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_SpeedValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->S_MassLabel = (gcnew System::Windows::Forms::Label());
			this->S_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->S_FrontHPLabel = (gcnew System::Windows::Forms::Label());
			this->S_BackHPLabel = (gcnew System::Windows::Forms::Label());
			this->S_RechargeLabel = (gcnew System::Windows::Forms::Label());
			this->S_AdjustmentLabel = (gcnew System::Windows::Forms::Label());
			this->S_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_FrontHPValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_BackHPValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_RechargeValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_AdjustmentValueLabel = (gcnew System::Windows::Forms::Label());
			this->FA_MassLabel = (gcnew System::Windows::Forms::Label());
			this->FA_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->FA_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->FA_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->RA_MassLabel = (gcnew System::Windows::Forms::Label());
			this->RA_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->RA_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->RA_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->D_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->D_MassLabel = (gcnew System::Windows::Forms::Label());
			this->D_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->D_SpeedLabel = (gcnew System::Windows::Forms::Label());
			this->D_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->D_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->D_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->D_SpeedValueLabel = (gcnew System::Windows::Forms::Label());
			this->C_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->C_MassLabel = (gcnew System::Windows::Forms::Label());
			this->C_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->C_EnergyLabel = (gcnew System::Windows::Forms::Label());
			this->C_RechargeLabel = (gcnew System::Windows::Forms::Label());
			this->C_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->C_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->C_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->C_EnergyValueLabel = (gcnew System::Windows::Forms::Label());
			this->C_RechargeValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->W1_MassLabel = (gcnew System::Windows::Forms::Label());
			this->W1_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->W1_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->W1_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->W1_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->W1_vsALabel = (gcnew System::Windows::Forms::Label());
			this->W1_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->W1_RefireLabel = (gcnew System::Windows::Forms::Label());
			this->W1_RefireValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_EPSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_vsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_vsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_MaxDValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_MinDValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->W1_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_RefireValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_EPSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_vsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_vsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MaxDValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MinDValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->W2_RefireLabel = (gcnew System::Windows::Forms::Label());
			this->W2_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->W2_vsALabel = (gcnew System::Windows::Forms::Label());
			this->W2_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->W2_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->W2_MassLabel = (gcnew System::Windows::Forms::Label());
			this->W2_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->W3_RefireValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_EPSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_vsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_vsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MaxDValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MinDValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->W3_RefireLabel = (gcnew System::Windows::Forms::Label());
			this->W3_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->W3_vsALabel = (gcnew System::Windows::Forms::Label());
			this->W3_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->W3_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->W3_MassLabel = (gcnew System::Windows::Forms::Label());
			this->W3_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->W4_RefireValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_EPSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_vsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_vsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MaxDValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MinDValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->W4_RefireLabel = (gcnew System::Windows::Forms::Label());
			this->W4_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->W4_vsALabel = (gcnew System::Windows::Forms::Label());
			this->W4_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->W4_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->W4_MassLabel = (gcnew System::Windows::Forms::Label());
			this->W4_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->O1_AmmoValueLabel = (gcnew System::Windows::Forms::Label());
			this->O1_vsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->O1_vsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->O1_MaxDValueLabel = (gcnew System::Windows::Forms::Label());
			this->O1_MinDValueLabel = (gcnew System::Windows::Forms::Label());
			this->O1_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->O1_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->O1_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->O1_AmmoLabel = (gcnew System::Windows::Forms::Label());
			this->O1_vsALabel = (gcnew System::Windows::Forms::Label());
			this->O1_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->O1_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->O1_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->O1_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->O1_MassLabel = (gcnew System::Windows::Forms::Label());
			this->O1_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->O2_AmmoValueLabel = (gcnew System::Windows::Forms::Label());
			this->O2_vsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->O2_vsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->O2_MaxDValueLabel = (gcnew System::Windows::Forms::Label());
			this->O2_MinDValueLabel = (gcnew System::Windows::Forms::Label());
			this->O2_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->O2_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->O2_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->O2_AmmoLabel = (gcnew System::Windows::Forms::Label());
			this->O2_vsALabel = (gcnew System::Windows::Forms::Label());
			this->O2_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->O2_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->O2_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->O2_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->O2_MassLabel = (gcnew System::Windows::Forms::Label());
			this->O2_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->CM_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->CM_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->CM_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->CM_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->CM_MassLabel = (gcnew System::Windows::Forms::Label());
			this->CM_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->ComponentsLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorCompLabel = (gcnew System::Windows::Forms::Label());
			this->EngineCompLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterCompLabel = (gcnew System::Windows::Forms::Label());
			this->SheildCompLabel = (gcnew System::Windows::Forms::Label());
			this->FArmorCompLabel = (gcnew System::Windows::Forms::Label());
			this->DroidCompLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorCompLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinanace1CompLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance2CompLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance3CompLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon1CompLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon2CompLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon3CompLabel = (gcnew System::Windows::Forms::Label());
			this->Weapon4CompLabel = (gcnew System::Windows::Forms::Label());
			this->CountermeasuresCompLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Weapon2ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Weapon1ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Ordinance3ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Ordinance2ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Ordinance1ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CapacitorComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DroidComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->RArmorComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->FArmorComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SheildComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->BoosterComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->EngineComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Weapon4ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Weapon3ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CountermeasuresComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ShipMassUsedValueLabel = (gcnew System::Windows::Forms::Label());
			this->LeftoverMassUsedValueLabel = (gcnew System::Windows::Forms::Label());
			this->ShipNameValueLabel = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->TotalDrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->TotalDrainLabel = (gcnew System::Windows::Forms::Label());
			this->TotalShipMassValueLabel = (gcnew System::Windows::Forms::Label());
			this->EnginePanel = (gcnew System::Windows::Forms::Panel());
			this->BoosterPanel = (gcnew System::Windows::Forms::Panel());
			this->Weapon1Panel = (gcnew System::Windows::Forms::Panel());
			this->Weapon2Panel = (gcnew System::Windows::Forms::Panel());
			this->Weapon3Panel = (gcnew System::Windows::Forms::Panel());
			this->Weapon4Panel = (gcnew System::Windows::Forms::Panel());
			this->CapacitorPanel = (gcnew System::Windows::Forms::Panel());
			this->Ordinance1Panel = (gcnew System::Windows::Forms::Panel());
			this->Ordinance2Panel = (gcnew System::Windows::Forms::Panel());
			this->O3_MinDValueLabel = (gcnew System::Windows::Forms::Label());
			this->O3_AmmoValueLabel = (gcnew System::Windows::Forms::Label());
			this->O3_vsAValueLabel = (gcnew System::Windows::Forms::Label());
			this->O3_vsSValueLabel = (gcnew System::Windows::Forms::Label());
			this->O3_MaxDValueLabel = (gcnew System::Windows::Forms::Label());
			this->O3_DrainValueLabel = (gcnew System::Windows::Forms::Label());
			this->O3_MassValueLabel = (gcnew System::Windows::Forms::Label());
			this->O3_ArmorValueLabel = (gcnew System::Windows::Forms::Label());
			this->O3_AmmoLabel = (gcnew System::Windows::Forms::Label());
			this->O3_vsALabel = (gcnew System::Windows::Forms::Label());
			this->O3_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->O3_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->O3_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->O3_DrianLabel = (gcnew System::Windows::Forms::Label());
			this->O3_MassLabel = (gcnew System::Windows::Forms::Label());
			this->O3_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->Ordinance3Panel = (gcnew System::Windows::Forms::Panel());
			this->ArmorPanel = (gcnew System::Windows::Forms::Panel());
			this->SheildPanel = (gcnew System::Windows::Forms::Panel());
			this->CountermeasuresPanel = (gcnew System::Windows::Forms::Panel());
			this->ReactorPanel = (gcnew System::Windows::Forms::Panel());
			this->DroidPanel = (gcnew System::Windows::Forms::Panel());
			this->ShipInfoPanel = (gcnew System::Windows::Forms::Panel());
			this->OverloadPanel = (gcnew System::Windows::Forms::Panel());
			this->ShipStatusPanel = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			this->EnginePanel->SuspendLayout();
			this->BoosterPanel->SuspendLayout();
			this->Weapon1Panel->SuspendLayout();
			this->Weapon2Panel->SuspendLayout();
			this->Weapon3Panel->SuspendLayout();
			this->Weapon4Panel->SuspendLayout();
			this->CapacitorPanel->SuspendLayout();
			this->Ordinance1Panel->SuspendLayout();
			this->Ordinance2Panel->SuspendLayout();
			this->Ordinance3Panel->SuspendLayout();
			this->ArmorPanel->SuspendLayout();
			this->SheildPanel->SuspendLayout();
			this->CountermeasuresPanel->SuspendLayout();
			this->ReactorPanel->SuspendLayout();
			this->DroidPanel->SuspendLayout();
			this->ShipInfoPanel->SuspendLayout();
			this->OverloadPanel->SuspendLayout();
			this->ShipStatusPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->fileToolStripMenuItem, 
				this->componentsToolStripMenuItem, this->shipStatisticsToolStripMenuItem, this->toolsToolStripMenuItem, this->aboutToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(869, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->newShipToolStripMenuItem, 
				this->openShipToolStripMenuItem, this->toolStripMenuItem1, this->saveShiploadoutToolStripMenuItem, this->closeShipLoadoutToolStripMenuItem, 
				this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newShipToolStripMenuItem
			// 
			this->newShipToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"newShipToolStripMenuItem.Image")));
			this->newShipToolStripMenuItem->Name = L"newShipToolStripMenuItem";
			this->newShipToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->newShipToolStripMenuItem->Text = L"New Ship Loadout...";
			this->newShipToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::newShipToolStripMenuItem_Click);
			// 
			// openShipToolStripMenuItem
			// 
			this->openShipToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openShipToolStripMenuItem.Image")));
			this->openShipToolStripMenuItem->Name = L"openShipToolStripMenuItem";
			this->openShipToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->openShipToolStripMenuItem->Text = L"Open Ship Loadout...";
			this->openShipToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openShipToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(198, 6);
			// 
			// saveShiploadoutToolStripMenuItem
			// 
			this->saveShiploadoutToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveShiploadoutToolStripMenuItem.Image")));
			this->saveShiploadoutToolStripMenuItem->Name = L"saveShiploadoutToolStripMenuItem";
			this->saveShiploadoutToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->saveShiploadoutToolStripMenuItem->Text = L"Save Ship Loadout As...";
			this->saveShiploadoutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveShiploadoutToolStripMenuItem_Click);
			// 
			// closeShipLoadoutToolStripMenuItem
			// 
			this->closeShipLoadoutToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"closeShipLoadoutToolStripMenuItem.Image")));
			this->closeShipLoadoutToolStripMenuItem->Name = L"closeShipLoadoutToolStripMenuItem";
			this->closeShipLoadoutToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->closeShipLoadoutToolStripMenuItem->Text = L"Close Ship Loadout";
			this->closeShipLoadoutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::closeShipLoadoutToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"exitToolStripMenuItem.Image")));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// componentsToolStripMenuItem
			// 
			this->componentsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->addComponentToolStripMenuItem});
			this->componentsToolStripMenuItem->Name = L"componentsToolStripMenuItem";
			this->componentsToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->componentsToolStripMenuItem->Text = L"Components";
			// 
			// addComponentToolStripMenuItem
			// 
			this->addComponentToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"addComponentToolStripMenuItem.Image")));
			this->addComponentToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::White;
			this->addComponentToolStripMenuItem->Name = L"addComponentToolStripMenuItem";
			this->addComponentToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->addComponentToolStripMenuItem->Text = L"Manage Components...";
			this->addComponentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::manageComponentToolStripMenuItem_Click);
			// 
			// shipStatisticsToolStripMenuItem
			// 
			this->shipStatisticsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->massDrainSummaryToolStripMenuItem, 
				this->propulsionStatsToolStripMenuItem, this->protectionStatsToolStripMenuItem, this->weaponStatsToolStripMenuItem});
			this->shipStatisticsToolStripMenuItem->Name = L"shipStatisticsToolStripMenuItem";
			this->shipStatisticsToolStripMenuItem->Size = System::Drawing::Size(85, 20);
			this->shipStatisticsToolStripMenuItem->Text = L"Ship Statistics";
			// 
			// massDrainSummaryToolStripMenuItem
			// 
			this->massDrainSummaryToolStripMenuItem->Name = L"massDrainSummaryToolStripMenuItem";
			this->massDrainSummaryToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->massDrainSummaryToolStripMenuItem->Text = L"Mass/Drain Summary...";
			this->massDrainSummaryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::massDrainSummaryToolStripMenuItem_Click);
			// 
			// propulsionStatsToolStripMenuItem
			// 
			this->propulsionStatsToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"propulsionStatsToolStripMenuItem.Image")));
			this->propulsionStatsToolStripMenuItem->Name = L"propulsionStatsToolStripMenuItem";
			this->propulsionStatsToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->propulsionStatsToolStripMenuItem->Text = L"Propulsion Statistics...";
			this->propulsionStatsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::propulsionStatsToolStripMenuItem_Click);
			// 
			// protectionStatsToolStripMenuItem
			// 
			this->protectionStatsToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"protectionStatsToolStripMenuItem.Image")));
			this->protectionStatsToolStripMenuItem->Name = L"protectionStatsToolStripMenuItem";
			this->protectionStatsToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->protectionStatsToolStripMenuItem->Text = L"Protection Statistics...";
			this->protectionStatsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::protectionStatsToolStripMenuItem_Click);
			// 
			// weaponStatsToolStripMenuItem
			// 
			this->weaponStatsToolStripMenuItem->BackColor = System::Drawing::Color::Transparent;
			this->weaponStatsToolStripMenuItem->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->weaponStatsToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"weaponStatsToolStripMenuItem.Image")));
			this->weaponStatsToolStripMenuItem->Name = L"weaponStatsToolStripMenuItem";
			this->weaponStatsToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->weaponStatsToolStripMenuItem->Text = L"Weapon Statistics...";
			this->weaponStatsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::weaponStatsToolStripMenuItem_Click);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->rECalculatorToolStripMenuItem1, 
				this->reactorCalculatorToolStripMenuItem1});
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// rECalculatorToolStripMenuItem1
			// 
			this->rECalculatorToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"rECalculatorToolStripMenuItem1.Image")));
			this->rECalculatorToolStripMenuItem1->Name = L"rECalculatorToolStripMenuItem1";
			this->rECalculatorToolStripMenuItem1->Size = System::Drawing::Size(186, 22);
			this->rECalculatorToolStripMenuItem1->Text = L"RE Calculator...";
			this->rECalculatorToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::RECalculatorToolStripMenuItem_Click);
			// 
			// reactorCalculatorToolStripMenuItem1
			// 
			this->reactorCalculatorToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"reactorCalculatorToolStripMenuItem1.Image")));
			this->reactorCalculatorToolStripMenuItem1->Name = L"reactorCalculatorToolStripMenuItem1";
			this->reactorCalculatorToolStripMenuItem1->Size = System::Drawing::Size(186, 22);
			this->reactorCalculatorToolStripMenuItem1->Text = L"Reactor Calculator...";
			this->reactorCalculatorToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::reactorCalculatorToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->aboutToolStripMenuItem->Text = L"About...";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutToolStripMenuItem_Click);
			// 
			// ShipNameLabel
			// 
			this->ShipNameLabel->AutoSize = true;
			this->ShipNameLabel->BackColor = System::Drawing::Color::Transparent;
			this->ShipNameLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ShipNameLabel->Location = System::Drawing::Point(4, 7);
			this->ShipNameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ShipNameLabel->Name = L"ShipNameLabel";
			this->ShipNameLabel->Size = System::Drawing::Size(88, 16);
			this->ShipNameLabel->TabIndex = 1;
			this->ShipNameLabel->Text = L"Ship Name: ";
			// 
			// TotalMassLabel
			// 
			this->TotalMassLabel->AutoSize = true;
			this->TotalMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->TotalMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalMassLabel->Location = System::Drawing::Point(4, 65);
			this->TotalMassLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->TotalMassLabel->Name = L"TotalMassLabel";
			this->TotalMassLabel->Size = System::Drawing::Size(124, 16);
			this->TotalMassLabel->TabIndex = 2;
			this->TotalMassLabel->Text = L"Total Ship Mass: ";
			// 
			// ShipMassUsedLabel
			// 
			this->ShipMassUsedLabel->AutoSize = true;
			this->ShipMassUsedLabel->BackColor = System::Drawing::Color::Transparent;
			this->ShipMassUsedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ShipMassUsedLabel->Location = System::Drawing::Point(4, 81);
			this->ShipMassUsedLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ShipMassUsedLabel->Name = L"ShipMassUsedLabel";
			this->ShipMassUsedLabel->Size = System::Drawing::Size(117, 16);
			this->ShipMassUsedLabel->TabIndex = 3;
			this->ShipMassUsedLabel->Text = L"Ship Mass Used:";
			// 
			// LeftoverMassLabel
			// 
			this->LeftoverMassLabel->AutoSize = true;
			this->LeftoverMassLabel->BackColor = System::Drawing::Color::Transparent;
			this->LeftoverMassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->LeftoverMassLabel->Location = System::Drawing::Point(4, 97);
			this->LeftoverMassLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LeftoverMassLabel->Name = L"LeftoverMassLabel";
			this->LeftoverMassLabel->Size = System::Drawing::Size(107, 16);
			this->LeftoverMassLabel->TabIndex = 4;
			this->LeftoverMassLabel->Text = L"Leftover Mass:";
			// 
			// OverloadsLabel
			// 
			this->OverloadsLabel->AutoSize = true;
			this->OverloadsLabel->BackColor = System::Drawing::Color::Transparent;
			this->OverloadsLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OverloadsLabel->Location = System::Drawing::Point(19, 2);
			this->OverloadsLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->OverloadsLabel->Name = L"OverloadsLabel";
			this->OverloadsLabel->Size = System::Drawing::Size(114, 16);
			this->OverloadsLabel->TabIndex = 5;
			this->OverloadsLabel->Text = L"O v e r l o a d s";
			// 
			// ReactorOverloadLabel
			// 
			this->ReactorOverloadLabel->AutoSize = true;
			this->ReactorOverloadLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReactorOverloadLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorOverloadLabel->Location = System::Drawing::Point(5, 22);
			this->ReactorOverloadLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ReactorOverloadLabel->Name = L"ReactorOverloadLabel";
			this->ReactorOverloadLabel->Size = System::Drawing::Size(65, 16);
			this->ReactorOverloadLabel->TabIndex = 6;
			this->ReactorOverloadLabel->Text = L"Reactor:";
			// 
			// EngineOverloadLabel
			// 
			this->EngineOverloadLabel->AutoSize = true;
			this->EngineOverloadLabel->BackColor = System::Drawing::Color::Transparent;
			this->EngineOverloadLabel->Location = System::Drawing::Point(5, 52);
			this->EngineOverloadLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EngineOverloadLabel->Name = L"EngineOverloadLabel";
			this->EngineOverloadLabel->Size = System::Drawing::Size(57, 16);
			this->EngineOverloadLabel->TabIndex = 7;
			this->EngineOverloadLabel->Text = L"Engine:";
			// 
			// WeaponOverloadLabel
			// 
			this->WeaponOverloadLabel->AutoSize = true;
			this->WeaponOverloadLabel->BackColor = System::Drawing::Color::Transparent;
			this->WeaponOverloadLabel->Location = System::Drawing::Point(5, 82);
			this->WeaponOverloadLabel->Name = L"WeaponOverloadLabel";
			this->WeaponOverloadLabel->Size = System::Drawing::Size(67, 16);
			this->WeaponOverloadLabel->TabIndex = 8;
			this->WeaponOverloadLabel->Text = L"Weapon:";
			// 
			// CapacitorOverloadLabel
			// 
			this->CapacitorOverloadLabel->AutoSize = true;
			this->CapacitorOverloadLabel->BackColor = System::Drawing::Color::Transparent;
			this->CapacitorOverloadLabel->Location = System::Drawing::Point(5, 112);
			this->CapacitorOverloadLabel->Name = L"CapacitorOverloadLabel";
			this->CapacitorOverloadLabel->Size = System::Drawing::Size(77, 16);
			this->CapacitorOverloadLabel->TabIndex = 9;
			this->CapacitorOverloadLabel->Text = L"Capacitor:";
			// 
			// ShipChassisLabel
			// 
			this->ShipChassisLabel->AutoSize = true;
			this->ShipChassisLabel->BackColor = System::Drawing::Color::Transparent;
			this->ShipChassisLabel->Location = System::Drawing::Point(4, 36);
			this->ShipChassisLabel->Name = L"ShipChassisLabel";
			this->ShipChassisLabel->Size = System::Drawing::Size(96, 16);
			this->ShipChassisLabel->TabIndex = 10;
			this->ShipChassisLabel->Text = L"Ship Chassis:";
			// 
			// ShipChassisComboBox
			// 
			this->ShipChassisComboBox->DropDownHeight = 300;
			this->ShipChassisComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ShipChassisComboBox->FormattingEnabled = true;
			this->ShipChassisComboBox->IntegralHeight = false;
			this->ShipChassisComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(47) {L"----------------", L"Rebel Ships", 
				L"----------------", L"Z-95", L"Heavy Z-95", L"Y-wing", L"Y-wing LP", L"X-wing ", L"Adv. X-wing", L"A-wing", L"B-wing", L"Nova", 
				L"----------------", L"Imperial Ships", L"----------------", L"Tie LD", L"Heavy Tie", L"Tie Fighter", L"Tie/IN", L"Tie Bomber", 
				L"Tie Inter.", L"Tie Adv.", L"Tie Aggres.", L"RGI", L"Tie Opp.", L"Decimator", L"----------------", L"Nuetral Ships", L"----------------", 
				L"Syck", L"Heavy Scyk", L"Dunelizard", L"Kihraxz", L"M12L Kimo", L"Ixiyen", L"Rihkxyrk", L"Vaksai", L"M22-T Krayt", L"YT-1300", 
				L"----------------", L"Special Ships", L"----------------", L"ARC-170", L"JSF", L"B22", L"Firespray", L"YT-2400"});
			this->ShipChassisComboBox->Location = System::Drawing::Point(103, 34);
			this->ShipChassisComboBox->Name = L"ShipChassisComboBox";
			this->ShipChassisComboBox->Size = System::Drawing::Size(119, 24);
			this->ShipChassisComboBox->TabIndex = 1;
			this->ShipChassisComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ShipChassisComboBox_SelectedIndexChanged);
			// 
			// ReactorOverloadComboBox
			// 
			this->ReactorOverloadComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ReactorOverloadComboBox->FormattingEnabled = true;
			this->ReactorOverloadComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"None", L"1", L"2", L"3", L"4"});
			this->ReactorOverloadComboBox->Location = System::Drawing::Point(87, 19);
			this->ReactorOverloadComboBox->Name = L"ReactorOverloadComboBox";
			this->ReactorOverloadComboBox->Size = System::Drawing::Size(65, 24);
			this->ReactorOverloadComboBox->TabIndex = 2;
			this->ReactorOverloadComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ReactorOverloadComboBox_SelectedIndexChanged);
			// 
			// WeaponOverloadComboBox
			// 
			this->WeaponOverloadComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->WeaponOverloadComboBox->FormattingEnabled = true;
			this->WeaponOverloadComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"None", L"1", L"2", L"3", L"4"});
			this->WeaponOverloadComboBox->Location = System::Drawing::Point(87, 79);
			this->WeaponOverloadComboBox->Name = L"WeaponOverloadComboBox";
			this->WeaponOverloadComboBox->Size = System::Drawing::Size(65, 24);
			this->WeaponOverloadComboBox->TabIndex = 4;
			this->WeaponOverloadComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::WeaponOverloadComboBox_SelectedIndexChanged);
			// 
			// EngineOverloadComboBox
			// 
			this->EngineOverloadComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->EngineOverloadComboBox->FormattingEnabled = true;
			this->EngineOverloadComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"None", L"1", L"2", L"3", L"4"});
			this->EngineOverloadComboBox->Location = System::Drawing::Point(87, 49);
			this->EngineOverloadComboBox->Name = L"EngineOverloadComboBox";
			this->EngineOverloadComboBox->Size = System::Drawing::Size(65, 24);
			this->EngineOverloadComboBox->TabIndex = 3;
			this->EngineOverloadComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::EngineOverloadComboBox_SelectedIndexChanged);
			// 
			// CapacitorOverloadComboBox
			// 
			this->CapacitorOverloadComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CapacitorOverloadComboBox->FormattingEnabled = true;
			this->CapacitorOverloadComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"None", L"1", L"2", L"3", L"4"});
			this->CapacitorOverloadComboBox->Location = System::Drawing::Point(87, 109);
			this->CapacitorOverloadComboBox->Name = L"CapacitorOverloadComboBox";
			this->CapacitorOverloadComboBox->Size = System::Drawing::Size(65, 24);
			this->CapacitorOverloadComboBox->TabIndex = 5;
			this->CapacitorOverloadComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::CapacitorOverloadComboBox_SelectedIndexChanged);
			// 
			// ReactorStatusLabel
			// 
			this->ReactorStatusLabel->AutoSize = true;
			this->ReactorStatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReactorStatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorStatusLabel->Location = System::Drawing::Point(3, 26);
			this->ReactorStatusLabel->Name = L"ReactorStatusLabel";
			this->ReactorStatusLabel->Size = System::Drawing::Size(56, 13);
			this->ReactorStatusLabel->TabIndex = 21;
			this->ReactorStatusLabel->Text = L"Reactor:";
			// 
			// EngineStatusLabel
			// 
			this->EngineStatusLabel->AutoSize = true;
			this->EngineStatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->EngineStatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineStatusLabel->Location = System::Drawing::Point(3, 39);
			this->EngineStatusLabel->Name = L"EngineStatusLabel";
			this->EngineStatusLabel->Size = System::Drawing::Size(50, 13);
			this->EngineStatusLabel->TabIndex = 22;
			this->EngineStatusLabel->Text = L"Engine:";
			// 
			// SheildStatusLabel
			// 
			this->SheildStatusLabel->AutoSize = true;
			this->SheildStatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->SheildStatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildStatusLabel->Location = System::Drawing::Point(3, 52);
			this->SheildStatusLabel->Name = L"SheildStatusLabel";
			this->SheildStatusLabel->Size = System::Drawing::Size(47, 13);
			this->SheildStatusLabel->TabIndex = 23;
			this->SheildStatusLabel->Text = L"Shield:";
			// 
			// FArmorStatusLabel
			// 
			this->FArmorStatusLabel->AutoSize = true;
			this->FArmorStatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->FArmorStatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FArmorStatusLabel->Location = System::Drawing::Point(3, 65);
			this->FArmorStatusLabel->Name = L"FArmorStatusLabel";
			this->FArmorStatusLabel->Size = System::Drawing::Size(68, 13);
			this->FArmorStatusLabel->TabIndex = 24;
			this->FArmorStatusLabel->Text = L"Armor (F):";
			// 
			// RArmorLabel
			// 
			this->RArmorLabel->AutoSize = true;
			this->RArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->RArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RArmorLabel->Location = System::Drawing::Point(3, 78);
			this->RArmorLabel->Name = L"RArmorLabel";
			this->RArmorLabel->Size = System::Drawing::Size(70, 13);
			this->RArmorLabel->TabIndex = 25;
			this->RArmorLabel->Text = L"Armor (R):";
			// 
			// CapacitorStatusLabel
			// 
			this->CapacitorStatusLabel->AutoSize = true;
			this->CapacitorStatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->CapacitorStatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorStatusLabel->Location = System::Drawing::Point(3, 91);
			this->CapacitorStatusLabel->Name = L"CapacitorStatusLabel";
			this->CapacitorStatusLabel->Size = System::Drawing::Size(67, 13);
			this->CapacitorStatusLabel->TabIndex = 26;
			this->CapacitorStatusLabel->Text = L"Capacitor:";
			// 
			// BoosterStatusLabel
			// 
			this->BoosterStatusLabel->AutoSize = true;
			this->BoosterStatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterStatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterStatusLabel->Location = System::Drawing::Point(3, 104);
			this->BoosterStatusLabel->Name = L"BoosterStatusLabel";
			this->BoosterStatusLabel->Size = System::Drawing::Size(56, 13);
			this->BoosterStatusLabel->TabIndex = 27;
			this->BoosterStatusLabel->Text = L"Booster:";
			// 
			// DriodStatusLabel
			// 
			this->DriodStatusLabel->AutoSize = true;
			this->DriodStatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->DriodStatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DriodStatusLabel->Location = System::Drawing::Point(3, 117);
			this->DriodStatusLabel->Name = L"DriodStatusLabel";
			this->DriodStatusLabel->Size = System::Drawing::Size(99, 13);
			this->DriodStatusLabel->TabIndex = 28;
			this->DriodStatusLabel->Text = L"Droid Interface:";
			// 
			// Weapon1StatusLabel
			// 
			this->Weapon1StatusLabel->AutoSize = true;
			this->Weapon1StatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon1StatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon1StatusLabel->Location = System::Drawing::Point(195, 26);
			this->Weapon1StatusLabel->Name = L"Weapon1StatusLabel";
			this->Weapon1StatusLabel->Size = System::Drawing::Size(69, 13);
			this->Weapon1StatusLabel->TabIndex = 29;
			this->Weapon1StatusLabel->Text = L"Weapon 1:";
			// 
			// Weapon2StatusLabel
			// 
			this->Weapon2StatusLabel->AutoSize = true;
			this->Weapon2StatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon2StatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon2StatusLabel->Location = System::Drawing::Point(195, 39);
			this->Weapon2StatusLabel->Name = L"Weapon2StatusLabel";
			this->Weapon2StatusLabel->Size = System::Drawing::Size(69, 13);
			this->Weapon2StatusLabel->TabIndex = 30;
			this->Weapon2StatusLabel->Text = L"Weapon 2:";
			// 
			// Weapon3StatusLabel
			// 
			this->Weapon3StatusLabel->AutoSize = true;
			this->Weapon3StatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon3StatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon3StatusLabel->Location = System::Drawing::Point(195, 52);
			this->Weapon3StatusLabel->Name = L"Weapon3StatusLabel";
			this->Weapon3StatusLabel->Size = System::Drawing::Size(69, 13);
			this->Weapon3StatusLabel->TabIndex = 31;
			this->Weapon3StatusLabel->Text = L"Weapon 3:";
			// 
			// Weapon4StatusLabel
			// 
			this->Weapon4StatusLabel->AutoSize = true;
			this->Weapon4StatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon4StatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon4StatusLabel->Location = System::Drawing::Point(195, 65);
			this->Weapon4StatusLabel->Name = L"Weapon4StatusLabel";
			this->Weapon4StatusLabel->Size = System::Drawing::Size(69, 13);
			this->Weapon4StatusLabel->TabIndex = 32;
			this->Weapon4StatusLabel->Text = L"Weapon 4:";
			// 
			// Ordinance1StatusLabel
			// 
			this->Ordinance1StatusLabel->AutoSize = true;
			this->Ordinance1StatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance1StatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance1StatusLabel->Location = System::Drawing::Point(195, 78);
			this->Ordinance1StatusLabel->Name = L"Ordinance1StatusLabel";
			this->Ordinance1StatusLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance1StatusLabel->TabIndex = 33;
			this->Ordinance1StatusLabel->Text = L"Ordinance 1:";
			// 
			// Ordinance2StatusLabel
			// 
			this->Ordinance2StatusLabel->AutoSize = true;
			this->Ordinance2StatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance2StatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance2StatusLabel->Location = System::Drawing::Point(195, 91);
			this->Ordinance2StatusLabel->Name = L"Ordinance2StatusLabel";
			this->Ordinance2StatusLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance2StatusLabel->TabIndex = 34;
			this->Ordinance2StatusLabel->Text = L"Ordinance 2:";
			// 
			// Ordinance3StatusLabel
			// 
			this->Ordinance3StatusLabel->AutoSize = true;
			this->Ordinance3StatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance3StatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance3StatusLabel->Location = System::Drawing::Point(195, 104);
			this->Ordinance3StatusLabel->Name = L"Ordinance3StatusLabel";
			this->Ordinance3StatusLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance3StatusLabel->TabIndex = 35;
			this->Ordinance3StatusLabel->Text = L"Ordinance 3:";
			// 
			// CountermeasuresStatusLabel
			// 
			this->CountermeasuresStatusLabel->AutoSize = true;
			this->CountermeasuresStatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->CountermeasuresStatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CountermeasuresStatusLabel->Location = System::Drawing::Point(195, 117);
			this->CountermeasuresStatusLabel->Name = L"CountermeasuresStatusLabel";
			this->CountermeasuresStatusLabel->Size = System::Drawing::Size(114, 13);
			this->CountermeasuresStatusLabel->TabIndex = 36;
			this->CountermeasuresStatusLabel->Text = L"Countermeasures:";
			// 
			// ShipStatusLabel
			// 
			this->ShipStatusLabel->AutoSize = true;
			this->ShipStatusLabel->BackColor = System::Drawing::Color::Transparent;
			this->ShipStatusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ShipStatusLabel->ForeColor = System::Drawing::Color::White;
			this->ShipStatusLabel->Location = System::Drawing::Point(130, 4);
			this->ShipStatusLabel->Name = L"ShipStatusLabel";
			this->ShipStatusLabel->Size = System::Drawing::Size(126, 16);
			this->ShipStatusLabel->TabIndex = 37;
			this->ShipStatusLabel->Text = L"S h i p  S t a t u s";
			// 
			// ReactorGBLabel
			// 
			this->ReactorGBLabel->AutoSize = true;
			this->ReactorGBLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReactorGBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorGBLabel->Location = System::Drawing::Point(108, 26);
			this->ReactorGBLabel->Name = L"ReactorGBLabel";
			this->ReactorGBLabel->Size = System::Drawing::Size(81, 13);
			this->ReactorGBLabel->TabIndex = 38;
			this->ReactorGBLabel->Text = L"None Loaded";
			// 
			// EngineGBLabel
			// 
			this->EngineGBLabel->AutoSize = true;
			this->EngineGBLabel->BackColor = System::Drawing::Color::Transparent;
			this->EngineGBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineGBLabel->Location = System::Drawing::Point(108, 39);
			this->EngineGBLabel->Name = L"EngineGBLabel";
			this->EngineGBLabel->Size = System::Drawing::Size(81, 13);
			this->EngineGBLabel->TabIndex = 39;
			this->EngineGBLabel->Text = L"None Loaded";
			// 
			// SheildGBLabel
			// 
			this->SheildGBLabel->AutoSize = true;
			this->SheildGBLabel->BackColor = System::Drawing::Color::Transparent;
			this->SheildGBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildGBLabel->Location = System::Drawing::Point(108, 52);
			this->SheildGBLabel->Name = L"SheildGBLabel";
			this->SheildGBLabel->Size = System::Drawing::Size(81, 13);
			this->SheildGBLabel->TabIndex = 40;
			this->SheildGBLabel->Text = L"None Loaded";
			// 
			// FArmorGBLabel
			// 
			this->FArmorGBLabel->AutoSize = true;
			this->FArmorGBLabel->BackColor = System::Drawing::Color::Transparent;
			this->FArmorGBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FArmorGBLabel->Location = System::Drawing::Point(108, 65);
			this->FArmorGBLabel->Name = L"FArmorGBLabel";
			this->FArmorGBLabel->Size = System::Drawing::Size(81, 13);
			this->FArmorGBLabel->TabIndex = 41;
			this->FArmorGBLabel->Text = L"None Loaded";
			// 
			// RArmorGBLabel
			// 
			this->RArmorGBLabel->AutoSize = true;
			this->RArmorGBLabel->BackColor = System::Drawing::Color::Transparent;
			this->RArmorGBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RArmorGBLabel->Location = System::Drawing::Point(108, 78);
			this->RArmorGBLabel->Name = L"RArmorGBLabel";
			this->RArmorGBLabel->Size = System::Drawing::Size(81, 13);
			this->RArmorGBLabel->TabIndex = 42;
			this->RArmorGBLabel->Text = L"None Loaded";
			// 
			// CapacitorGBLabel
			// 
			this->CapacitorGBLabel->AutoSize = true;
			this->CapacitorGBLabel->BackColor = System::Drawing::Color::Transparent;
			this->CapacitorGBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorGBLabel->Location = System::Drawing::Point(108, 91);
			this->CapacitorGBLabel->Name = L"CapacitorGBLabel";
			this->CapacitorGBLabel->Size = System::Drawing::Size(81, 13);
			this->CapacitorGBLabel->TabIndex = 43;
			this->CapacitorGBLabel->Text = L"None Loaded";
			// 
			// BoosterGBLabel
			// 
			this->BoosterGBLabel->AutoSize = true;
			this->BoosterGBLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterGBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterGBLabel->Location = System::Drawing::Point(108, 104);
			this->BoosterGBLabel->Name = L"BoosterGBLabel";
			this->BoosterGBLabel->Size = System::Drawing::Size(81, 13);
			this->BoosterGBLabel->TabIndex = 44;
			this->BoosterGBLabel->Text = L"None Loaded";
			// 
			// DroidGBLabel
			// 
			this->DroidGBLabel->AutoSize = true;
			this->DroidGBLabel->BackColor = System::Drawing::Color::Transparent;
			this->DroidGBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DroidGBLabel->Location = System::Drawing::Point(108, 117);
			this->DroidGBLabel->Name = L"DroidGBLabel";
			this->DroidGBLabel->Size = System::Drawing::Size(81, 13);
			this->DroidGBLabel->TabIndex = 45;
			this->DroidGBLabel->Text = L"None Loaded";
			// 
			// Weapon1GBLabel
			// 
			this->Weapon1GBLabel->AutoSize = true;
			this->Weapon1GBLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon1GBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon1GBLabel->Location = System::Drawing::Point(315, 26);
			this->Weapon1GBLabel->Name = L"Weapon1GBLabel";
			this->Weapon1GBLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon1GBLabel->TabIndex = 46;
			this->Weapon1GBLabel->Text = L"None Loaded";
			// 
			// Weapon2GBLabel
			// 
			this->Weapon2GBLabel->AutoSize = true;
			this->Weapon2GBLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon2GBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon2GBLabel->Location = System::Drawing::Point(315, 39);
			this->Weapon2GBLabel->Name = L"Weapon2GBLabel";
			this->Weapon2GBLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon2GBLabel->TabIndex = 47;
			this->Weapon2GBLabel->Text = L"None Loaded";
			// 
			// Weapon3GBLabel
			// 
			this->Weapon3GBLabel->AutoSize = true;
			this->Weapon3GBLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon3GBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon3GBLabel->Location = System::Drawing::Point(315, 52);
			this->Weapon3GBLabel->Name = L"Weapon3GBLabel";
			this->Weapon3GBLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon3GBLabel->TabIndex = 48;
			this->Weapon3GBLabel->Text = L"None Loaded";
			// 
			// Weapon4GBLabel
			// 
			this->Weapon4GBLabel->AutoSize = true;
			this->Weapon4GBLabel->BackColor = System::Drawing::Color::Transparent;
			this->Weapon4GBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon4GBLabel->Location = System::Drawing::Point(315, 65);
			this->Weapon4GBLabel->Name = L"Weapon4GBLabel";
			this->Weapon4GBLabel->Size = System::Drawing::Size(81, 13);
			this->Weapon4GBLabel->TabIndex = 49;
			this->Weapon4GBLabel->Text = L"None Loaded";
			// 
			// OrdinanceGBLabel
			// 
			this->OrdinanceGBLabel->AutoSize = true;
			this->OrdinanceGBLabel->BackColor = System::Drawing::Color::Transparent;
			this->OrdinanceGBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OrdinanceGBLabel->Location = System::Drawing::Point(315, 78);
			this->OrdinanceGBLabel->Name = L"OrdinanceGBLabel";
			this->OrdinanceGBLabel->Size = System::Drawing::Size(81, 13);
			this->OrdinanceGBLabel->TabIndex = 50;
			this->OrdinanceGBLabel->Text = L"None Loaded";
			// 
			// Ordinance2GBLabel
			// 
			this->Ordinance2GBLabel->AutoSize = true;
			this->Ordinance2GBLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance2GBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance2GBLabel->Location = System::Drawing::Point(315, 91);
			this->Ordinance2GBLabel->Name = L"Ordinance2GBLabel";
			this->Ordinance2GBLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance2GBLabel->TabIndex = 51;
			this->Ordinance2GBLabel->Text = L"None Loaded";
			// 
			// Ordinance3GBLabel
			// 
			this->Ordinance3GBLabel->AutoSize = true;
			this->Ordinance3GBLabel->BackColor = System::Drawing::Color::Transparent;
			this->Ordinance3GBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance3GBLabel->Location = System::Drawing::Point(315, 104);
			this->Ordinance3GBLabel->Name = L"Ordinance3GBLabel";
			this->Ordinance3GBLabel->Size = System::Drawing::Size(81, 13);
			this->Ordinance3GBLabel->TabIndex = 52;
			this->Ordinance3GBLabel->Text = L"None Loaded";
			// 
			// CountermeasuresGBLabel
			// 
			this->CountermeasuresGBLabel->AutoSize = true;
			this->CountermeasuresGBLabel->BackColor = System::Drawing::Color::Transparent;
			this->CountermeasuresGBLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CountermeasuresGBLabel->Location = System::Drawing::Point(315, 117);
			this->CountermeasuresGBLabel->Name = L"CountermeasuresGBLabel";
			this->CountermeasuresGBLabel->Size = System::Drawing::Size(81, 13);
			this->CountermeasuresGBLabel->TabIndex = 53;
			this->CountermeasuresGBLabel->Text = L"None Loaded";
			// 
			// R_ArmorLabel
			// 
			this->R_ArmorLabel->AutoSize = true;
			this->R_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_ArmorLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->R_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_ArmorLabel->Location = System::Drawing::Point(16, 2);
			this->R_ArmorLabel->Name = L"R_ArmorLabel";
			this->R_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->R_ArmorLabel->TabIndex = 55;
			this->R_ArmorLabel->Text = L"Armor:";
			// 
			// R_MassLabel
			// 
			this->R_MassLabel->AutoSize = true;
			this->R_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_MassLabel->Location = System::Drawing::Point(16, 15);
			this->R_MassLabel->Name = L"R_MassLabel";
			this->R_MassLabel->Size = System::Drawing::Size(43, 13);
			this->R_MassLabel->TabIndex = 56;
			this->R_MassLabel->Text = L"Mass:";
			// 
			// R_GenerationLabel
			// 
			this->R_GenerationLabel->AutoSize = true;
			this->R_GenerationLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_GenerationLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_GenerationLabel->Location = System::Drawing::Point(16, 28);
			this->R_GenerationLabel->Name = L"R_GenerationLabel";
			this->R_GenerationLabel->Size = System::Drawing::Size(83, 13);
			this->R_GenerationLabel->TabIndex = 57;
			this->R_GenerationLabel->Text = L"Generation:";
			// 
			// R_ArmorValueLabel
			// 
			this->R_ArmorValueLabel->AutoSize = true;
			this->R_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_ArmorValueLabel->Location = System::Drawing::Point(96, 2);
			this->R_ArmorValueLabel->Name = L"R_ArmorValueLabel";
			this->R_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->R_ArmorValueLabel->TabIndex = 58;
			this->R_ArmorValueLabel->Text = L"0";
			// 
			// R_MassValueLabel
			// 
			this->R_MassValueLabel->AutoSize = true;
			this->R_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_MassValueLabel->Location = System::Drawing::Point(96, 15);
			this->R_MassValueLabel->Name = L"R_MassValueLabel";
			this->R_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->R_MassValueLabel->TabIndex = 59;
			this->R_MassValueLabel->Text = L"0";
			// 
			// R_GenerationValueLabel
			// 
			this->R_GenerationValueLabel->AutoSize = true;
			this->R_GenerationValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_GenerationValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_GenerationValueLabel->Location = System::Drawing::Point(96, 28);
			this->R_GenerationValueLabel->Name = L"R_GenerationValueLabel";
			this->R_GenerationValueLabel->Size = System::Drawing::Size(15, 13);
			this->R_GenerationValueLabel->TabIndex = 60;
			this->R_GenerationValueLabel->Text = L"0";
			// 
			// E_ArmorLabel
			// 
			this->E_ArmorLabel->AutoSize = true;
			this->E_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_ArmorLabel->ForeColor = System::Drawing::Color::White;
			this->E_ArmorLabel->Location = System::Drawing::Point(16, 2);
			this->E_ArmorLabel->Name = L"E_ArmorLabel";
			this->E_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->E_ArmorLabel->TabIndex = 62;
			this->E_ArmorLabel->Text = L"Armor:";
			// 
			// E_MassLabel
			// 
			this->E_MassLabel->AutoSize = true;
			this->E_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_MassLabel->ForeColor = System::Drawing::Color::White;
			this->E_MassLabel->Location = System::Drawing::Point(16, 28);
			this->E_MassLabel->Name = L"E_MassLabel";
			this->E_MassLabel->Size = System::Drawing::Size(43, 13);
			this->E_MassLabel->TabIndex = 63;
			this->E_MassLabel->Text = L"Mass:";
			// 
			// E_DrainLabel
			// 
			this->E_DrainLabel->AutoSize = true;
			this->E_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_DrainLabel->ForeColor = System::Drawing::Color::White;
			this->E_DrainLabel->Location = System::Drawing::Point(16, 15);
			this->E_DrainLabel->Name = L"E_DrainLabel";
			this->E_DrainLabel->Size = System::Drawing::Size(46, 13);
			this->E_DrainLabel->TabIndex = 64;
			this->E_DrainLabel->Text = L"Drain:";
			// 
			// E_PitchLabel
			// 
			this->E_PitchLabel->AutoSize = true;
			this->E_PitchLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_PitchLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_PitchLabel->ForeColor = System::Drawing::Color::White;
			this->E_PitchLabel->Location = System::Drawing::Point(16, 41);
			this->E_PitchLabel->Name = L"E_PitchLabel";
			this->E_PitchLabel->Size = System::Drawing::Size(43, 13);
			this->E_PitchLabel->TabIndex = 65;
			this->E_PitchLabel->Text = L"Pitch:";
			// 
			// E_YawLabel
			// 
			this->E_YawLabel->AutoSize = true;
			this->E_YawLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_YawLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_YawLabel->ForeColor = System::Drawing::Color::White;
			this->E_YawLabel->Location = System::Drawing::Point(16, 54);
			this->E_YawLabel->Name = L"E_YawLabel";
			this->E_YawLabel->Size = System::Drawing::Size(37, 13);
			this->E_YawLabel->TabIndex = 66;
			this->E_YawLabel->Text = L"Yaw:";
			// 
			// E_RollLabel
			// 
			this->E_RollLabel->AutoSize = true;
			this->E_RollLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_RollLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_RollLabel->ForeColor = System::Drawing::Color::White;
			this->E_RollLabel->Location = System::Drawing::Point(16, 67);
			this->E_RollLabel->Name = L"E_RollLabel";
			this->E_RollLabel->Size = System::Drawing::Size(35, 13);
			this->E_RollLabel->TabIndex = 67;
			this->E_RollLabel->Text = L"Roll:";
			// 
			// E_SpeedLabel
			// 
			this->E_SpeedLabel->AutoSize = true;
			this->E_SpeedLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_SpeedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_SpeedLabel->ForeColor = System::Drawing::Color::White;
			this->E_SpeedLabel->Location = System::Drawing::Point(16, 80);
			this->E_SpeedLabel->Name = L"E_SpeedLabel";
			this->E_SpeedLabel->Size = System::Drawing::Size(51, 13);
			this->E_SpeedLabel->TabIndex = 68;
			this->E_SpeedLabel->Text = L"Speed:";
			// 
			// E_ArmorValueLabel
			// 
			this->E_ArmorValueLabel->AutoSize = true;
			this->E_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_ArmorValueLabel->ForeColor = System::Drawing::Color::White;
			this->E_ArmorValueLabel->Location = System::Drawing::Point(65, 2);
			this->E_ArmorValueLabel->Name = L"E_ArmorValueLabel";
			this->E_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->E_ArmorValueLabel->TabIndex = 69;
			this->E_ArmorValueLabel->Text = L"0";
			// 
			// E_MassValueLabel
			// 
			this->E_MassValueLabel->AutoSize = true;
			this->E_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_MassValueLabel->ForeColor = System::Drawing::Color::White;
			this->E_MassValueLabel->Location = System::Drawing::Point(65, 28);
			this->E_MassValueLabel->Name = L"E_MassValueLabel";
			this->E_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->E_MassValueLabel->TabIndex = 70;
			this->E_MassValueLabel->Text = L"0";
			// 
			// E_DrainValueLabel
			// 
			this->E_DrainValueLabel->AutoSize = true;
			this->E_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_DrainValueLabel->ForeColor = System::Drawing::Color::White;
			this->E_DrainValueLabel->Location = System::Drawing::Point(65, 15);
			this->E_DrainValueLabel->Name = L"E_DrainValueLabel";
			this->E_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->E_DrainValueLabel->TabIndex = 71;
			this->E_DrainValueLabel->Text = L"0";
			// 
			// E_PitchValueLabel
			// 
			this->E_PitchValueLabel->AutoSize = true;
			this->E_PitchValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_PitchValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_PitchValueLabel->ForeColor = System::Drawing::Color::White;
			this->E_PitchValueLabel->Location = System::Drawing::Point(65, 41);
			this->E_PitchValueLabel->Name = L"E_PitchValueLabel";
			this->E_PitchValueLabel->Size = System::Drawing::Size(15, 13);
			this->E_PitchValueLabel->TabIndex = 72;
			this->E_PitchValueLabel->Text = L"0";
			// 
			// E_YawValueLabel
			// 
			this->E_YawValueLabel->AutoSize = true;
			this->E_YawValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_YawValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_YawValueLabel->ForeColor = System::Drawing::Color::White;
			this->E_YawValueLabel->Location = System::Drawing::Point(65, 54);
			this->E_YawValueLabel->Name = L"E_YawValueLabel";
			this->E_YawValueLabel->Size = System::Drawing::Size(15, 13);
			this->E_YawValueLabel->TabIndex = 73;
			this->E_YawValueLabel->Text = L"0";
			// 
			// E_RollValueLabel
			// 
			this->E_RollValueLabel->AutoSize = true;
			this->E_RollValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_RollValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_RollValueLabel->ForeColor = System::Drawing::Color::White;
			this->E_RollValueLabel->Location = System::Drawing::Point(65, 67);
			this->E_RollValueLabel->Name = L"E_RollValueLabel";
			this->E_RollValueLabel->Size = System::Drawing::Size(15, 13);
			this->E_RollValueLabel->TabIndex = 74;
			this->E_RollValueLabel->Text = L"0";
			// 
			// E_SpeedValueLabel
			// 
			this->E_SpeedValueLabel->AutoSize = true;
			this->E_SpeedValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_SpeedValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_SpeedValueLabel->ForeColor = System::Drawing::Color::White;
			this->E_SpeedValueLabel->Location = System::Drawing::Point(65, 80);
			this->E_SpeedValueLabel->Name = L"E_SpeedValueLabel";
			this->E_SpeedValueLabel->Size = System::Drawing::Size(15, 13);
			this->E_SpeedValueLabel->TabIndex = 75;
			this->E_SpeedValueLabel->Text = L"0";
			// 
			// B_ArmorLabel
			// 
			this->B_ArmorLabel->AutoSize = true;
			this->B_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_ArmorLabel->ForeColor = System::Drawing::Color::White;
			this->B_ArmorLabel->Location = System::Drawing::Point(16, 2);
			this->B_ArmorLabel->Name = L"B_ArmorLabel";
			this->B_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->B_ArmorLabel->TabIndex = 77;
			this->B_ArmorLabel->Text = L"Armor:";
			// 
			// B_MassLabel
			// 
			this->B_MassLabel->AutoSize = true;
			this->B_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_MassLabel->ForeColor = System::Drawing::Color::White;
			this->B_MassLabel->Location = System::Drawing::Point(16, 28);
			this->B_MassLabel->Name = L"B_MassLabel";
			this->B_MassLabel->Size = System::Drawing::Size(43, 13);
			this->B_MassLabel->TabIndex = 78;
			this->B_MassLabel->Text = L"Mass:";
			// 
			// B_DrainLabel
			// 
			this->B_DrainLabel->AutoSize = true;
			this->B_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_DrainLabel->ForeColor = System::Drawing::Color::White;
			this->B_DrainLabel->Location = System::Drawing::Point(16, 15);
			this->B_DrainLabel->Name = L"B_DrainLabel";
			this->B_DrainLabel->Size = System::Drawing::Size(46, 13);
			this->B_DrainLabel->TabIndex = 79;
			this->B_DrainLabel->Text = L"Drain:";
			// 
			// B_EnergyLabel
			// 
			this->B_EnergyLabel->AutoSize = true;
			this->B_EnergyLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_EnergyLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_EnergyLabel->ForeColor = System::Drawing::Color::White;
			this->B_EnergyLabel->Location = System::Drawing::Point(16, 41);
			this->B_EnergyLabel->Name = L"B_EnergyLabel";
			this->B_EnergyLabel->Size = System::Drawing::Size(57, 13);
			this->B_EnergyLabel->TabIndex = 80;
			this->B_EnergyLabel->Text = L"Energy:";
			// 
			// B_RechargeLabel
			// 
			this->B_RechargeLabel->AutoSize = true;
			this->B_RechargeLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_RechargeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_RechargeLabel->ForeColor = System::Drawing::Color::White;
			this->B_RechargeLabel->Location = System::Drawing::Point(16, 54);
			this->B_RechargeLabel->Name = L"B_RechargeLabel";
			this->B_RechargeLabel->Size = System::Drawing::Size(72, 13);
			this->B_RechargeLabel->TabIndex = 81;
			this->B_RechargeLabel->Text = L"Recharge:";
			// 
			// B_ConsumptionLabel
			// 
			this->B_ConsumptionLabel->AutoSize = true;
			this->B_ConsumptionLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_ConsumptionLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_ConsumptionLabel->ForeColor = System::Drawing::Color::White;
			this->B_ConsumptionLabel->Location = System::Drawing::Point(16, 67);
			this->B_ConsumptionLabel->Name = L"B_ConsumptionLabel";
			this->B_ConsumptionLabel->Size = System::Drawing::Size(70, 13);
			this->B_ConsumptionLabel->TabIndex = 82;
			this->B_ConsumptionLabel->Text = L"Consump:";
			// 
			// B_AccelerationLabel
			// 
			this->B_AccelerationLabel->AutoSize = true;
			this->B_AccelerationLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_AccelerationLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_AccelerationLabel->ForeColor = System::Drawing::Color::White;
			this->B_AccelerationLabel->Location = System::Drawing::Point(16, 80);
			this->B_AccelerationLabel->Name = L"B_AccelerationLabel";
			this->B_AccelerationLabel->Size = System::Drawing::Size(46, 13);
			this->B_AccelerationLabel->TabIndex = 83;
			this->B_AccelerationLabel->Text = L"Accel:";
			// 
			// B_SpeedLabel
			// 
			this->B_SpeedLabel->AutoSize = true;
			this->B_SpeedLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_SpeedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_SpeedLabel->ForeColor = System::Drawing::Color::White;
			this->B_SpeedLabel->Location = System::Drawing::Point(16, 93);
			this->B_SpeedLabel->Name = L"B_SpeedLabel";
			this->B_SpeedLabel->Size = System::Drawing::Size(51, 13);
			this->B_SpeedLabel->TabIndex = 84;
			this->B_SpeedLabel->Text = L"Speed:";
			// 
			// B_ArmorValueLabel
			// 
			this->B_ArmorValueLabel->AutoSize = true;
			this->B_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_ArmorValueLabel->ForeColor = System::Drawing::Color::White;
			this->B_ArmorValueLabel->Location = System::Drawing::Point(89, 2);
			this->B_ArmorValueLabel->Name = L"B_ArmorValueLabel";
			this->B_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->B_ArmorValueLabel->TabIndex = 85;
			this->B_ArmorValueLabel->Text = L"0";
			// 
			// B_MassValueLabel
			// 
			this->B_MassValueLabel->AutoSize = true;
			this->B_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_MassValueLabel->ForeColor = System::Drawing::Color::White;
			this->B_MassValueLabel->Location = System::Drawing::Point(89, 28);
			this->B_MassValueLabel->Name = L"B_MassValueLabel";
			this->B_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->B_MassValueLabel->TabIndex = 86;
			this->B_MassValueLabel->Text = L"0";
			// 
			// B_DrainValueLabel
			// 
			this->B_DrainValueLabel->AutoSize = true;
			this->B_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_DrainValueLabel->ForeColor = System::Drawing::Color::White;
			this->B_DrainValueLabel->Location = System::Drawing::Point(89, 15);
			this->B_DrainValueLabel->Name = L"B_DrainValueLabel";
			this->B_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->B_DrainValueLabel->TabIndex = 87;
			this->B_DrainValueLabel->Text = L"0";
			// 
			// B_EnergyValueLabel
			// 
			this->B_EnergyValueLabel->AutoSize = true;
			this->B_EnergyValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_EnergyValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_EnergyValueLabel->ForeColor = System::Drawing::Color::White;
			this->B_EnergyValueLabel->Location = System::Drawing::Point(89, 41);
			this->B_EnergyValueLabel->Name = L"B_EnergyValueLabel";
			this->B_EnergyValueLabel->Size = System::Drawing::Size(15, 13);
			this->B_EnergyValueLabel->TabIndex = 88;
			this->B_EnergyValueLabel->Text = L"0";
			// 
			// B_RechargeValueLabel
			// 
			this->B_RechargeValueLabel->AutoSize = true;
			this->B_RechargeValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_RechargeValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_RechargeValueLabel->ForeColor = System::Drawing::Color::White;
			this->B_RechargeValueLabel->Location = System::Drawing::Point(89, 54);
			this->B_RechargeValueLabel->Name = L"B_RechargeValueLabel";
			this->B_RechargeValueLabel->Size = System::Drawing::Size(15, 13);
			this->B_RechargeValueLabel->TabIndex = 89;
			this->B_RechargeValueLabel->Text = L"0";
			// 
			// B_ConsumptionValueLabel
			// 
			this->B_ConsumptionValueLabel->AutoSize = true;
			this->B_ConsumptionValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_ConsumptionValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_ConsumptionValueLabel->ForeColor = System::Drawing::Color::White;
			this->B_ConsumptionValueLabel->Location = System::Drawing::Point(89, 67);
			this->B_ConsumptionValueLabel->Name = L"B_ConsumptionValueLabel";
			this->B_ConsumptionValueLabel->Size = System::Drawing::Size(15, 13);
			this->B_ConsumptionValueLabel->TabIndex = 90;
			this->B_ConsumptionValueLabel->Text = L"0";
			// 
			// B_AccelerationValueLabel
			// 
			this->B_AccelerationValueLabel->AutoSize = true;
			this->B_AccelerationValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_AccelerationValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_AccelerationValueLabel->ForeColor = System::Drawing::Color::White;
			this->B_AccelerationValueLabel->Location = System::Drawing::Point(89, 80);
			this->B_AccelerationValueLabel->Name = L"B_AccelerationValueLabel";
			this->B_AccelerationValueLabel->Size = System::Drawing::Size(15, 13);
			this->B_AccelerationValueLabel->TabIndex = 91;
			this->B_AccelerationValueLabel->Text = L"0";
			// 
			// B_SpeedValueLabel
			// 
			this->B_SpeedValueLabel->AutoSize = true;
			this->B_SpeedValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_SpeedValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_SpeedValueLabel->ForeColor = System::Drawing::Color::White;
			this->B_SpeedValueLabel->Location = System::Drawing::Point(89, 93);
			this->B_SpeedValueLabel->Name = L"B_SpeedValueLabel";
			this->B_SpeedValueLabel->Size = System::Drawing::Size(15, 13);
			this->B_SpeedValueLabel->TabIndex = 92;
			this->B_SpeedValueLabel->Text = L"0";
			// 
			// S_ArmorLabel
			// 
			this->S_ArmorLabel->AutoSize = true;
			this->S_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_ArmorLabel->Location = System::Drawing::Point(16, 2);
			this->S_ArmorLabel->Name = L"S_ArmorLabel";
			this->S_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->S_ArmorLabel->TabIndex = 94;
			this->S_ArmorLabel->Text = L"Armor:";
			// 
			// S_MassLabel
			// 
			this->S_MassLabel->AutoSize = true;
			this->S_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_MassLabel->Location = System::Drawing::Point(16, 28);
			this->S_MassLabel->Name = L"S_MassLabel";
			this->S_MassLabel->Size = System::Drawing::Size(43, 13);
			this->S_MassLabel->TabIndex = 95;
			this->S_MassLabel->Text = L"Mass:";
			// 
			// S_DrainLabel
			// 
			this->S_DrainLabel->AutoSize = true;
			this->S_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_DrainLabel->Location = System::Drawing::Point(16, 15);
			this->S_DrainLabel->Name = L"S_DrainLabel";
			this->S_DrainLabel->Size = System::Drawing::Size(46, 13);
			this->S_DrainLabel->TabIndex = 96;
			this->S_DrainLabel->Text = L"Drain:";
			// 
			// S_FrontHPLabel
			// 
			this->S_FrontHPLabel->AutoSize = true;
			this->S_FrontHPLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_FrontHPLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_FrontHPLabel->Location = System::Drawing::Point(16, 41);
			this->S_FrontHPLabel->Name = L"S_FrontHPLabel";
			this->S_FrontHPLabel->Size = System::Drawing::Size(67, 13);
			this->S_FrontHPLabel->TabIndex = 97;
			this->S_FrontHPLabel->Text = L"Front HP:";
			// 
			// S_BackHPLabel
			// 
			this->S_BackHPLabel->AutoSize = true;
			this->S_BackHPLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_BackHPLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_BackHPLabel->Location = System::Drawing::Point(16, 54);
			this->S_BackHPLabel->Name = L"S_BackHPLabel";
			this->S_BackHPLabel->Size = System::Drawing::Size(63, 13);
			this->S_BackHPLabel->TabIndex = 98;
			this->S_BackHPLabel->Text = L"Back HP:";
			// 
			// S_RechargeLabel
			// 
			this->S_RechargeLabel->AutoSize = true;
			this->S_RechargeLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_RechargeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_RechargeLabel->Location = System::Drawing::Point(16, 67);
			this->S_RechargeLabel->Name = L"S_RechargeLabel";
			this->S_RechargeLabel->Size = System::Drawing::Size(72, 13);
			this->S_RechargeLabel->TabIndex = 99;
			this->S_RechargeLabel->Text = L"Recharge:";
			// 
			// S_AdjustmentLabel
			// 
			this->S_AdjustmentLabel->AutoSize = true;
			this->S_AdjustmentLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_AdjustmentLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_AdjustmentLabel->Location = System::Drawing::Point(16, 80);
			this->S_AdjustmentLabel->Name = L"S_AdjustmentLabel";
			this->S_AdjustmentLabel->Size = System::Drawing::Size(53, 13);
			this->S_AdjustmentLabel->TabIndex = 100;
			this->S_AdjustmentLabel->Text = L"Adjust:";
			// 
			// S_ArmorValueLabel
			// 
			this->S_ArmorValueLabel->AutoSize = true;
			this->S_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_ArmorValueLabel->Location = System::Drawing::Point(88, 2);
			this->S_ArmorValueLabel->Name = L"S_ArmorValueLabel";
			this->S_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->S_ArmorValueLabel->TabIndex = 101;
			this->S_ArmorValueLabel->Text = L"0";
			// 
			// S_MassValueLabel
			// 
			this->S_MassValueLabel->AutoSize = true;
			this->S_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_MassValueLabel->Location = System::Drawing::Point(88, 28);
			this->S_MassValueLabel->Name = L"S_MassValueLabel";
			this->S_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->S_MassValueLabel->TabIndex = 102;
			this->S_MassValueLabel->Text = L"0";
			// 
			// S_DrainValueLabel
			// 
			this->S_DrainValueLabel->AutoSize = true;
			this->S_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_DrainValueLabel->Location = System::Drawing::Point(88, 15);
			this->S_DrainValueLabel->Name = L"S_DrainValueLabel";
			this->S_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->S_DrainValueLabel->TabIndex = 103;
			this->S_DrainValueLabel->Text = L"0";
			// 
			// S_FrontHPValueLabel
			// 
			this->S_FrontHPValueLabel->AutoSize = true;
			this->S_FrontHPValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_FrontHPValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_FrontHPValueLabel->Location = System::Drawing::Point(88, 41);
			this->S_FrontHPValueLabel->Name = L"S_FrontHPValueLabel";
			this->S_FrontHPValueLabel->Size = System::Drawing::Size(15, 13);
			this->S_FrontHPValueLabel->TabIndex = 104;
			this->S_FrontHPValueLabel->Text = L"0";
			// 
			// S_BackHPValueLabel
			// 
			this->S_BackHPValueLabel->AutoSize = true;
			this->S_BackHPValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_BackHPValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_BackHPValueLabel->Location = System::Drawing::Point(88, 54);
			this->S_BackHPValueLabel->Name = L"S_BackHPValueLabel";
			this->S_BackHPValueLabel->Size = System::Drawing::Size(15, 13);
			this->S_BackHPValueLabel->TabIndex = 105;
			this->S_BackHPValueLabel->Text = L"0";
			// 
			// S_RechargeValueLabel
			// 
			this->S_RechargeValueLabel->AutoSize = true;
			this->S_RechargeValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_RechargeValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_RechargeValueLabel->Location = System::Drawing::Point(88, 67);
			this->S_RechargeValueLabel->Name = L"S_RechargeValueLabel";
			this->S_RechargeValueLabel->Size = System::Drawing::Size(15, 13);
			this->S_RechargeValueLabel->TabIndex = 106;
			this->S_RechargeValueLabel->Text = L"0";
			// 
			// S_AdjustmentValueLabel
			// 
			this->S_AdjustmentValueLabel->AutoSize = true;
			this->S_AdjustmentValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_AdjustmentValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_AdjustmentValueLabel->Location = System::Drawing::Point(70, 80);
			this->S_AdjustmentValueLabel->Name = L"S_AdjustmentValueLabel";
			this->S_AdjustmentValueLabel->Size = System::Drawing::Size(40, 13);
			this->S_AdjustmentValueLabel->TabIndex = 107;
			this->S_AdjustmentValueLabel->Text = L"None";
			// 
			// FA_MassLabel
			// 
			this->FA_MassLabel->AutoSize = true;
			this->FA_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->FA_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FA_MassLabel->Location = System::Drawing::Point(16, 21);
			this->FA_MassLabel->Name = L"FA_MassLabel";
			this->FA_MassLabel->Size = System::Drawing::Size(43, 13);
			this->FA_MassLabel->TabIndex = 110;
			this->FA_MassLabel->Text = L"Mass:";
			// 
			// FA_ArmorLabel
			// 
			this->FA_ArmorLabel->AutoSize = true;
			this->FA_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->FA_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FA_ArmorLabel->Location = System::Drawing::Point(16, 8);
			this->FA_ArmorLabel->Name = L"FA_ArmorLabel";
			this->FA_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->FA_ArmorLabel->TabIndex = 111;
			this->FA_ArmorLabel->Text = L"Armor:";
			// 
			// FA_MassValueLabel
			// 
			this->FA_MassValueLabel->AutoSize = true;
			this->FA_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FA_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FA_MassValueLabel->Location = System::Drawing::Point(90, 21);
			this->FA_MassValueLabel->Name = L"FA_MassValueLabel";
			this->FA_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->FA_MassValueLabel->TabIndex = 112;
			this->FA_MassValueLabel->Text = L"0";
			// 
			// FA_ArmorValueLabel
			// 
			this->FA_ArmorValueLabel->AutoSize = true;
			this->FA_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->FA_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FA_ArmorValueLabel->Location = System::Drawing::Point(90, 8);
			this->FA_ArmorValueLabel->Name = L"FA_ArmorValueLabel";
			this->FA_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->FA_ArmorValueLabel->TabIndex = 113;
			this->FA_ArmorValueLabel->Text = L"0";
			// 
			// RA_MassLabel
			// 
			this->RA_MassLabel->AutoSize = true;
			this->RA_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->RA_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RA_MassLabel->Location = System::Drawing::Point(16, 106);
			this->RA_MassLabel->Name = L"RA_MassLabel";
			this->RA_MassLabel->Size = System::Drawing::Size(43, 13);
			this->RA_MassLabel->TabIndex = 114;
			this->RA_MassLabel->Text = L"Mass:";
			// 
			// RA_ArmorLabel
			// 
			this->RA_ArmorLabel->AutoSize = true;
			this->RA_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->RA_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RA_ArmorLabel->Location = System::Drawing::Point(16, 93);
			this->RA_ArmorLabel->Name = L"RA_ArmorLabel";
			this->RA_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->RA_ArmorLabel->TabIndex = 115;
			this->RA_ArmorLabel->Text = L"Armor:";
			// 
			// RA_MassValueLabel
			// 
			this->RA_MassValueLabel->AutoSize = true;
			this->RA_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RA_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RA_MassValueLabel->Location = System::Drawing::Point(88, 106);
			this->RA_MassValueLabel->Name = L"RA_MassValueLabel";
			this->RA_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->RA_MassValueLabel->TabIndex = 116;
			this->RA_MassValueLabel->Text = L"0";
			// 
			// RA_ArmorValueLabel
			// 
			this->RA_ArmorValueLabel->AutoSize = true;
			this->RA_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RA_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RA_ArmorValueLabel->Location = System::Drawing::Point(88, 93);
			this->RA_ArmorValueLabel->Name = L"RA_ArmorValueLabel";
			this->RA_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->RA_ArmorValueLabel->TabIndex = 117;
			this->RA_ArmorValueLabel->Text = L"0";
			// 
			// D_ArmorLabel
			// 
			this->D_ArmorLabel->AutoSize = true;
			this->D_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_ArmorLabel->Location = System::Drawing::Point(17, 0);
			this->D_ArmorLabel->Name = L"D_ArmorLabel";
			this->D_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->D_ArmorLabel->TabIndex = 119;
			this->D_ArmorLabel->Text = L"Armor:";
			// 
			// D_MassLabel
			// 
			this->D_MassLabel->AutoSize = true;
			this->D_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_MassLabel->Location = System::Drawing::Point(17, 26);
			this->D_MassLabel->Name = L"D_MassLabel";
			this->D_MassLabel->Size = System::Drawing::Size(43, 13);
			this->D_MassLabel->TabIndex = 120;
			this->D_MassLabel->Text = L"Mass:";
			// 
			// D_DrainLabel
			// 
			this->D_DrainLabel->AutoSize = true;
			this->D_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_DrainLabel->Location = System::Drawing::Point(17, 13);
			this->D_DrainLabel->Name = L"D_DrainLabel";
			this->D_DrainLabel->Size = System::Drawing::Size(46, 13);
			this->D_DrainLabel->TabIndex = 121;
			this->D_DrainLabel->Text = L"Drain:";
			// 
			// D_SpeedLabel
			// 
			this->D_SpeedLabel->AutoSize = true;
			this->D_SpeedLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_SpeedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_SpeedLabel->Location = System::Drawing::Point(17, 39);
			this->D_SpeedLabel->Name = L"D_SpeedLabel";
			this->D_SpeedLabel->Size = System::Drawing::Size(51, 13);
			this->D_SpeedLabel->TabIndex = 122;
			this->D_SpeedLabel->Text = L"Speed:";
			// 
			// D_ArmorValueLabel
			// 
			this->D_ArmorValueLabel->AutoSize = true;
			this->D_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_ArmorValueLabel->Location = System::Drawing::Point(93, 0);
			this->D_ArmorValueLabel->Name = L"D_ArmorValueLabel";
			this->D_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->D_ArmorValueLabel->TabIndex = 123;
			this->D_ArmorValueLabel->Text = L"0";
			// 
			// D_MassValueLabel
			// 
			this->D_MassValueLabel->AutoSize = true;
			this->D_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_MassValueLabel->Location = System::Drawing::Point(93, 26);
			this->D_MassValueLabel->Name = L"D_MassValueLabel";
			this->D_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->D_MassValueLabel->TabIndex = 124;
			this->D_MassValueLabel->Text = L"0";
			// 
			// D_DrainValueLabel
			// 
			this->D_DrainValueLabel->AutoSize = true;
			this->D_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_DrainValueLabel->Location = System::Drawing::Point(93, 13);
			this->D_DrainValueLabel->Name = L"D_DrainValueLabel";
			this->D_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->D_DrainValueLabel->TabIndex = 125;
			this->D_DrainValueLabel->Text = L"0";
			// 
			// D_SpeedValueLabel
			// 
			this->D_SpeedValueLabel->AutoSize = true;
			this->D_SpeedValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_SpeedValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_SpeedValueLabel->Location = System::Drawing::Point(93, 39);
			this->D_SpeedValueLabel->Name = L"D_SpeedValueLabel";
			this->D_SpeedValueLabel->Size = System::Drawing::Size(15, 13);
			this->D_SpeedValueLabel->TabIndex = 126;
			this->D_SpeedValueLabel->Text = L"0";
			// 
			// C_ArmorLabel
			// 
			this->C_ArmorLabel->AutoSize = true;
			this->C_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_ArmorLabel->Location = System::Drawing::Point(16, 0);
			this->C_ArmorLabel->Name = L"C_ArmorLabel";
			this->C_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->C_ArmorLabel->TabIndex = 128;
			this->C_ArmorLabel->Text = L"Armor:";
			// 
			// C_MassLabel
			// 
			this->C_MassLabel->AutoSize = true;
			this->C_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_MassLabel->Location = System::Drawing::Point(16, 26);
			this->C_MassLabel->Name = L"C_MassLabel";
			this->C_MassLabel->Size = System::Drawing::Size(43, 13);
			this->C_MassLabel->TabIndex = 129;
			this->C_MassLabel->Text = L"Mass:";
			// 
			// C_DrainLabel
			// 
			this->C_DrainLabel->AutoSize = true;
			this->C_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_DrainLabel->Location = System::Drawing::Point(16, 13);
			this->C_DrainLabel->Name = L"C_DrainLabel";
			this->C_DrainLabel->Size = System::Drawing::Size(46, 13);
			this->C_DrainLabel->TabIndex = 130;
			this->C_DrainLabel->Text = L"Drain:";
			// 
			// C_EnergyLabel
			// 
			this->C_EnergyLabel->AutoSize = true;
			this->C_EnergyLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_EnergyLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_EnergyLabel->Location = System::Drawing::Point(16, 39);
			this->C_EnergyLabel->Name = L"C_EnergyLabel";
			this->C_EnergyLabel->Size = System::Drawing::Size(57, 13);
			this->C_EnergyLabel->TabIndex = 131;
			this->C_EnergyLabel->Text = L"Energy:";
			// 
			// C_RechargeLabel
			// 
			this->C_RechargeLabel->AutoSize = true;
			this->C_RechargeLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_RechargeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_RechargeLabel->Location = System::Drawing::Point(16, 52);
			this->C_RechargeLabel->Name = L"C_RechargeLabel";
			this->C_RechargeLabel->Size = System::Drawing::Size(72, 13);
			this->C_RechargeLabel->TabIndex = 132;
			this->C_RechargeLabel->Text = L"Recharge:";
			// 
			// C_ArmorValueLabel
			// 
			this->C_ArmorValueLabel->AutoSize = true;
			this->C_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_ArmorValueLabel->Location = System::Drawing::Point(86, 0);
			this->C_ArmorValueLabel->Name = L"C_ArmorValueLabel";
			this->C_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->C_ArmorValueLabel->TabIndex = 133;
			this->C_ArmorValueLabel->Text = L"0";
			// 
			// C_MassValueLabel
			// 
			this->C_MassValueLabel->AutoSize = true;
			this->C_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_MassValueLabel->Location = System::Drawing::Point(86, 26);
			this->C_MassValueLabel->Name = L"C_MassValueLabel";
			this->C_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->C_MassValueLabel->TabIndex = 134;
			this->C_MassValueLabel->Text = L"0";
			// 
			// C_DrainValueLabel
			// 
			this->C_DrainValueLabel->AutoSize = true;
			this->C_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_DrainValueLabel->Location = System::Drawing::Point(86, 13);
			this->C_DrainValueLabel->Name = L"C_DrainValueLabel";
			this->C_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->C_DrainValueLabel->TabIndex = 135;
			this->C_DrainValueLabel->Text = L"0";
			// 
			// C_EnergyValueLabel
			// 
			this->C_EnergyValueLabel->AutoSize = true;
			this->C_EnergyValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_EnergyValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_EnergyValueLabel->Location = System::Drawing::Point(86, 39);
			this->C_EnergyValueLabel->Name = L"C_EnergyValueLabel";
			this->C_EnergyValueLabel->Size = System::Drawing::Size(15, 13);
			this->C_EnergyValueLabel->TabIndex = 136;
			this->C_EnergyValueLabel->Text = L"0";
			// 
			// C_RechargeValueLabel
			// 
			this->C_RechargeValueLabel->AutoSize = true;
			this->C_RechargeValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_RechargeValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_RechargeValueLabel->Location = System::Drawing::Point(86, 52);
			this->C_RechargeValueLabel->Name = L"C_RechargeValueLabel";
			this->C_RechargeValueLabel->Size = System::Drawing::Size(15, 13);
			this->C_RechargeValueLabel->TabIndex = 137;
			this->C_RechargeValueLabel->Text = L"0";
			// 
			// W1_ArmorLabel
			// 
			this->W1_ArmorLabel->AutoSize = true;
			this->W1_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_ArmorLabel->Location = System::Drawing::Point(16, 2);
			this->W1_ArmorLabel->Name = L"W1_ArmorLabel";
			this->W1_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->W1_ArmorLabel->TabIndex = 139;
			this->W1_ArmorLabel->Text = L"Armor:";
			// 
			// W1_MassLabel
			// 
			this->W1_MassLabel->AutoSize = true;
			this->W1_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MassLabel->Location = System::Drawing::Point(16, 28);
			this->W1_MassLabel->Name = L"W1_MassLabel";
			this->W1_MassLabel->Size = System::Drawing::Size(43, 13);
			this->W1_MassLabel->TabIndex = 140;
			this->W1_MassLabel->Text = L"Mass:";
			// 
			// W1_DrainLabel
			// 
			this->W1_DrainLabel->AutoSize = true;
			this->W1_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_DrainLabel->Location = System::Drawing::Point(16, 15);
			this->W1_DrainLabel->Name = L"W1_DrainLabel";
			this->W1_DrainLabel->Size = System::Drawing::Size(46, 13);
			this->W1_DrainLabel->TabIndex = 141;
			this->W1_DrainLabel->Text = L"Drain:";
			// 
			// W1_MinDLabel
			// 
			this->W1_MinDLabel->AutoSize = true;
			this->W1_MinDLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MinDLabel->Location = System::Drawing::Point(16, 41);
			this->W1_MinDLabel->Name = L"W1_MinDLabel";
			this->W1_MinDLabel->Size = System::Drawing::Size(66, 13);
			this->W1_MinDLabel->TabIndex = 142;
			this->W1_MinDLabel->Text = L"Min Dmg:";
			// 
			// W1_MaxDLabel
			// 
			this->W1_MaxDLabel->AutoSize = true;
			this->W1_MaxDLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MaxDLabel->Location = System::Drawing::Point(16, 54);
			this->W1_MaxDLabel->Name = L"W1_MaxDLabel";
			this->W1_MaxDLabel->Size = System::Drawing::Size(70, 13);
			this->W1_MaxDLabel->TabIndex = 143;
			this->W1_MaxDLabel->Text = L"Max Dmg:";
			// 
			// W1_vsSLabel
			// 
			this->W1_vsSLabel->AutoSize = true;
			this->W1_vsSLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_vsSLabel->Location = System::Drawing::Point(16, 67);
			this->W1_vsSLabel->Name = L"W1_vsSLabel";
			this->W1_vsSLabel->Size = System::Drawing::Size(77, 13);
			this->W1_vsSLabel->TabIndex = 144;
			this->W1_vsSLabel->Text = L"vs Shields:";
			// 
			// W1_vsALabel
			// 
			this->W1_vsALabel->AutoSize = true;
			this->W1_vsALabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_vsALabel->Location = System::Drawing::Point(16, 80);
			this->W1_vsALabel->Name = L"W1_vsALabel";
			this->W1_vsALabel->Size = System::Drawing::Size(71, 13);
			this->W1_vsALabel->TabIndex = 145;
			this->W1_vsALabel->Text = L"vs Armor:";
			// 
			// W1_EPSLabel
			// 
			this->W1_EPSLabel->AutoSize = true;
			this->W1_EPSLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_EPSLabel->Location = System::Drawing::Point(16, 93);
			this->W1_EPSLabel->Name = L"W1_EPSLabel";
			this->W1_EPSLabel->Size = System::Drawing::Size(35, 13);
			this->W1_EPSLabel->TabIndex = 146;
			this->W1_EPSLabel->Text = L"EPS:";
			// 
			// W1_RefireLabel
			// 
			this->W1_RefireLabel->AutoSize = true;
			this->W1_RefireLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_RefireLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_RefireLabel->Location = System::Drawing::Point(16, 106);
			this->W1_RefireLabel->Name = L"W1_RefireLabel";
			this->W1_RefireLabel->Size = System::Drawing::Size(50, 13);
			this->W1_RefireLabel->TabIndex = 147;
			this->W1_RefireLabel->Text = L"Refire:";
			// 
			// W1_RefireValueLabel
			// 
			this->W1_RefireValueLabel->AutoSize = true;
			this->W1_RefireValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_RefireValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_RefireValueLabel->Location = System::Drawing::Point(90, 106);
			this->W1_RefireValueLabel->Name = L"W1_RefireValueLabel";
			this->W1_RefireValueLabel->Size = System::Drawing::Size(15, 13);
			this->W1_RefireValueLabel->TabIndex = 156;
			this->W1_RefireValueLabel->Text = L"0";
			// 
			// W1_EPSValueLabel
			// 
			this->W1_EPSValueLabel->AutoSize = true;
			this->W1_EPSValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_EPSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_EPSValueLabel->Location = System::Drawing::Point(90, 93);
			this->W1_EPSValueLabel->Name = L"W1_EPSValueLabel";
			this->W1_EPSValueLabel->Size = System::Drawing::Size(15, 13);
			this->W1_EPSValueLabel->TabIndex = 155;
			this->W1_EPSValueLabel->Text = L"0";
			// 
			// W1_vsAValueLabel
			// 
			this->W1_vsAValueLabel->AutoSize = true;
			this->W1_vsAValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_vsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_vsAValueLabel->Location = System::Drawing::Point(90, 80);
			this->W1_vsAValueLabel->Name = L"W1_vsAValueLabel";
			this->W1_vsAValueLabel->Size = System::Drawing::Size(15, 13);
			this->W1_vsAValueLabel->TabIndex = 154;
			this->W1_vsAValueLabel->Text = L"0";
			// 
			// W1_vsSValueLabel
			// 
			this->W1_vsSValueLabel->AutoSize = true;
			this->W1_vsSValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_vsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_vsSValueLabel->Location = System::Drawing::Point(90, 67);
			this->W1_vsSValueLabel->Name = L"W1_vsSValueLabel";
			this->W1_vsSValueLabel->Size = System::Drawing::Size(15, 13);
			this->W1_vsSValueLabel->TabIndex = 153;
			this->W1_vsSValueLabel->Text = L"0";
			// 
			// W1_MaxDValueLabel
			// 
			this->W1_MaxDValueLabel->AutoSize = true;
			this->W1_MaxDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_MaxDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MaxDValueLabel->Location = System::Drawing::Point(90, 54);
			this->W1_MaxDValueLabel->Name = L"W1_MaxDValueLabel";
			this->W1_MaxDValueLabel->Size = System::Drawing::Size(15, 13);
			this->W1_MaxDValueLabel->TabIndex = 152;
			this->W1_MaxDValueLabel->Text = L"0";
			// 
			// W1_MinDValueLabel
			// 
			this->W1_MinDValueLabel->AutoSize = true;
			this->W1_MinDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_MinDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MinDValueLabel->Location = System::Drawing::Point(90, 41);
			this->W1_MinDValueLabel->Name = L"W1_MinDValueLabel";
			this->W1_MinDValueLabel->Size = System::Drawing::Size(15, 13);
			this->W1_MinDValueLabel->TabIndex = 151;
			this->W1_MinDValueLabel->Text = L"0";
			// 
			// W1_DrainValueLabel
			// 
			this->W1_DrainValueLabel->AutoSize = true;
			this->W1_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_DrainValueLabel->Location = System::Drawing::Point(90, 15);
			this->W1_DrainValueLabel->Name = L"W1_DrainValueLabel";
			this->W1_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->W1_DrainValueLabel->TabIndex = 150;
			this->W1_DrainValueLabel->Text = L"0";
			// 
			// W1_MassValueLabel
			// 
			this->W1_MassValueLabel->AutoSize = true;
			this->W1_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_MassValueLabel->Location = System::Drawing::Point(90, 28);
			this->W1_MassValueLabel->Name = L"W1_MassValueLabel";
			this->W1_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->W1_MassValueLabel->TabIndex = 149;
			this->W1_MassValueLabel->Text = L"0";
			// 
			// W1_ArmorValueLabel
			// 
			this->W1_ArmorValueLabel->AutoSize = true;
			this->W1_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W1_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W1_ArmorValueLabel->Location = System::Drawing::Point(90, 2);
			this->W1_ArmorValueLabel->Name = L"W1_ArmorValueLabel";
			this->W1_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->W1_ArmorValueLabel->TabIndex = 148;
			this->W1_ArmorValueLabel->Text = L"0";
			// 
			// W2_RefireValueLabel
			// 
			this->W2_RefireValueLabel->AutoSize = true;
			this->W2_RefireValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_RefireValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_RefireValueLabel->Location = System::Drawing::Point(90, 106);
			this->W2_RefireValueLabel->Name = L"W2_RefireValueLabel";
			this->W2_RefireValueLabel->Size = System::Drawing::Size(15, 13);
			this->W2_RefireValueLabel->TabIndex = 175;
			this->W2_RefireValueLabel->Text = L"0";
			// 
			// W2_EPSValueLabel
			// 
			this->W2_EPSValueLabel->AutoSize = true;
			this->W2_EPSValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_EPSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_EPSValueLabel->Location = System::Drawing::Point(90, 93);
			this->W2_EPSValueLabel->Name = L"W2_EPSValueLabel";
			this->W2_EPSValueLabel->Size = System::Drawing::Size(15, 13);
			this->W2_EPSValueLabel->TabIndex = 174;
			this->W2_EPSValueLabel->Text = L"0";
			// 
			// W2_vsAValueLabel
			// 
			this->W2_vsAValueLabel->AutoSize = true;
			this->W2_vsAValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_vsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_vsAValueLabel->Location = System::Drawing::Point(90, 80);
			this->W2_vsAValueLabel->Name = L"W2_vsAValueLabel";
			this->W2_vsAValueLabel->Size = System::Drawing::Size(15, 13);
			this->W2_vsAValueLabel->TabIndex = 173;
			this->W2_vsAValueLabel->Text = L"0";
			// 
			// W2_vsSValueLabel
			// 
			this->W2_vsSValueLabel->AutoSize = true;
			this->W2_vsSValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_vsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_vsSValueLabel->Location = System::Drawing::Point(90, 67);
			this->W2_vsSValueLabel->Name = L"W2_vsSValueLabel";
			this->W2_vsSValueLabel->Size = System::Drawing::Size(15, 13);
			this->W2_vsSValueLabel->TabIndex = 172;
			this->W2_vsSValueLabel->Text = L"0";
			// 
			// W2_MaxDValueLabel
			// 
			this->W2_MaxDValueLabel->AutoSize = true;
			this->W2_MaxDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_MaxDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MaxDValueLabel->Location = System::Drawing::Point(90, 54);
			this->W2_MaxDValueLabel->Name = L"W2_MaxDValueLabel";
			this->W2_MaxDValueLabel->Size = System::Drawing::Size(15, 13);
			this->W2_MaxDValueLabel->TabIndex = 171;
			this->W2_MaxDValueLabel->Text = L"0";
			// 
			// W2_MinDValueLabel
			// 
			this->W2_MinDValueLabel->AutoSize = true;
			this->W2_MinDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_MinDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MinDValueLabel->Location = System::Drawing::Point(90, 41);
			this->W2_MinDValueLabel->Name = L"W2_MinDValueLabel";
			this->W2_MinDValueLabel->Size = System::Drawing::Size(15, 13);
			this->W2_MinDValueLabel->TabIndex = 170;
			this->W2_MinDValueLabel->Text = L"0";
			// 
			// W2_DrainValueLabel
			// 
			this->W2_DrainValueLabel->AutoSize = true;
			this->W2_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_DrainValueLabel->Location = System::Drawing::Point(90, 15);
			this->W2_DrainValueLabel->Name = L"W2_DrainValueLabel";
			this->W2_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->W2_DrainValueLabel->TabIndex = 169;
			this->W2_DrainValueLabel->Text = L"0";
			// 
			// W2_MassValueLabel
			// 
			this->W2_MassValueLabel->AutoSize = true;
			this->W2_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MassValueLabel->Location = System::Drawing::Point(90, 28);
			this->W2_MassValueLabel->Name = L"W2_MassValueLabel";
			this->W2_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->W2_MassValueLabel->TabIndex = 168;
			this->W2_MassValueLabel->Text = L"0";
			// 
			// W2_ArmorValueLabel
			// 
			this->W2_ArmorValueLabel->AutoSize = true;
			this->W2_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_ArmorValueLabel->Location = System::Drawing::Point(90, 2);
			this->W2_ArmorValueLabel->Name = L"W2_ArmorValueLabel";
			this->W2_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->W2_ArmorValueLabel->TabIndex = 167;
			this->W2_ArmorValueLabel->Text = L"0";
			// 
			// W2_RefireLabel
			// 
			this->W2_RefireLabel->AutoSize = true;
			this->W2_RefireLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_RefireLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_RefireLabel->Location = System::Drawing::Point(16, 106);
			this->W2_RefireLabel->Name = L"W2_RefireLabel";
			this->W2_RefireLabel->Size = System::Drawing::Size(50, 13);
			this->W2_RefireLabel->TabIndex = 166;
			this->W2_RefireLabel->Text = L"Refire:";
			// 
			// W2_EPSLabel
			// 
			this->W2_EPSLabel->AutoSize = true;
			this->W2_EPSLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_EPSLabel->Location = System::Drawing::Point(16, 93);
			this->W2_EPSLabel->Name = L"W2_EPSLabel";
			this->W2_EPSLabel->Size = System::Drawing::Size(35, 13);
			this->W2_EPSLabel->TabIndex = 165;
			this->W2_EPSLabel->Text = L"EPS:";
			// 
			// W2_vsALabel
			// 
			this->W2_vsALabel->AutoSize = true;
			this->W2_vsALabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_vsALabel->Location = System::Drawing::Point(16, 80);
			this->W2_vsALabel->Name = L"W2_vsALabel";
			this->W2_vsALabel->Size = System::Drawing::Size(71, 13);
			this->W2_vsALabel->TabIndex = 164;
			this->W2_vsALabel->Text = L"vs Armor:";
			// 
			// W2_vsSLabel
			// 
			this->W2_vsSLabel->AutoSize = true;
			this->W2_vsSLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_vsSLabel->Location = System::Drawing::Point(16, 67);
			this->W2_vsSLabel->Name = L"W2_vsSLabel";
			this->W2_vsSLabel->Size = System::Drawing::Size(77, 13);
			this->W2_vsSLabel->TabIndex = 163;
			this->W2_vsSLabel->Text = L"vs Shields:";
			// 
			// W2_MaxDLabel
			// 
			this->W2_MaxDLabel->AutoSize = true;
			this->W2_MaxDLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MaxDLabel->Location = System::Drawing::Point(16, 54);
			this->W2_MaxDLabel->Name = L"W2_MaxDLabel";
			this->W2_MaxDLabel->Size = System::Drawing::Size(70, 13);
			this->W2_MaxDLabel->TabIndex = 162;
			this->W2_MaxDLabel->Text = L"Max Dmg:";
			// 
			// W2_MinDLabel
			// 
			this->W2_MinDLabel->AutoSize = true;
			this->W2_MinDLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MinDLabel->Location = System::Drawing::Point(16, 41);
			this->W2_MinDLabel->Name = L"W2_MinDLabel";
			this->W2_MinDLabel->Size = System::Drawing::Size(66, 13);
			this->W2_MinDLabel->TabIndex = 161;
			this->W2_MinDLabel->Text = L"Min Dmg:";
			// 
			// W2_DrainLabel
			// 
			this->W2_DrainLabel->AutoSize = true;
			this->W2_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_DrainLabel->Location = System::Drawing::Point(16, 15);
			this->W2_DrainLabel->Name = L"W2_DrainLabel";
			this->W2_DrainLabel->Size = System::Drawing::Size(46, 13);
			this->W2_DrainLabel->TabIndex = 160;
			this->W2_DrainLabel->Text = L"Drain:";
			// 
			// W2_MassLabel
			// 
			this->W2_MassLabel->AutoSize = true;
			this->W2_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_MassLabel->Location = System::Drawing::Point(16, 28);
			this->W2_MassLabel->Name = L"W2_MassLabel";
			this->W2_MassLabel->Size = System::Drawing::Size(43, 13);
			this->W2_MassLabel->TabIndex = 159;
			this->W2_MassLabel->Text = L"Mass:";
			// 
			// W2_ArmorLabel
			// 
			this->W2_ArmorLabel->AutoSize = true;
			this->W2_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->W2_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W2_ArmorLabel->Location = System::Drawing::Point(16, 2);
			this->W2_ArmorLabel->Name = L"W2_ArmorLabel";
			this->W2_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->W2_ArmorLabel->TabIndex = 158;
			this->W2_ArmorLabel->Text = L"Armor:";
			// 
			// W3_RefireValueLabel
			// 
			this->W3_RefireValueLabel->AutoSize = true;
			this->W3_RefireValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_RefireValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_RefireValueLabel->Location = System::Drawing::Point(90, 106);
			this->W3_RefireValueLabel->Name = L"W3_RefireValueLabel";
			this->W3_RefireValueLabel->Size = System::Drawing::Size(15, 13);
			this->W3_RefireValueLabel->TabIndex = 194;
			this->W3_RefireValueLabel->Text = L"0";
			// 
			// W3_EPSValueLabel
			// 
			this->W3_EPSValueLabel->AutoSize = true;
			this->W3_EPSValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_EPSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_EPSValueLabel->Location = System::Drawing::Point(90, 93);
			this->W3_EPSValueLabel->Name = L"W3_EPSValueLabel";
			this->W3_EPSValueLabel->Size = System::Drawing::Size(15, 13);
			this->W3_EPSValueLabel->TabIndex = 193;
			this->W3_EPSValueLabel->Text = L"0";
			// 
			// W3_vsAValueLabel
			// 
			this->W3_vsAValueLabel->AutoSize = true;
			this->W3_vsAValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_vsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_vsAValueLabel->Location = System::Drawing::Point(90, 80);
			this->W3_vsAValueLabel->Name = L"W3_vsAValueLabel";
			this->W3_vsAValueLabel->Size = System::Drawing::Size(15, 13);
			this->W3_vsAValueLabel->TabIndex = 192;
			this->W3_vsAValueLabel->Text = L"0";
			// 
			// W3_vsSValueLabel
			// 
			this->W3_vsSValueLabel->AutoSize = true;
			this->W3_vsSValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_vsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_vsSValueLabel->Location = System::Drawing::Point(90, 67);
			this->W3_vsSValueLabel->Name = L"W3_vsSValueLabel";
			this->W3_vsSValueLabel->Size = System::Drawing::Size(15, 13);
			this->W3_vsSValueLabel->TabIndex = 191;
			this->W3_vsSValueLabel->Text = L"0";
			// 
			// W3_MaxDValueLabel
			// 
			this->W3_MaxDValueLabel->AutoSize = true;
			this->W3_MaxDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_MaxDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MaxDValueLabel->Location = System::Drawing::Point(90, 54);
			this->W3_MaxDValueLabel->Name = L"W3_MaxDValueLabel";
			this->W3_MaxDValueLabel->Size = System::Drawing::Size(15, 13);
			this->W3_MaxDValueLabel->TabIndex = 190;
			this->W3_MaxDValueLabel->Text = L"0";
			// 
			// W3_MinDValueLabel
			// 
			this->W3_MinDValueLabel->AutoSize = true;
			this->W3_MinDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_MinDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MinDValueLabel->Location = System::Drawing::Point(90, 41);
			this->W3_MinDValueLabel->Name = L"W3_MinDValueLabel";
			this->W3_MinDValueLabel->Size = System::Drawing::Size(15, 13);
			this->W3_MinDValueLabel->TabIndex = 189;
			this->W3_MinDValueLabel->Text = L"0";
			// 
			// W3_DrainValueLabel
			// 
			this->W3_DrainValueLabel->AutoSize = true;
			this->W3_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_DrainValueLabel->Location = System::Drawing::Point(90, 15);
			this->W3_DrainValueLabel->Name = L"W3_DrainValueLabel";
			this->W3_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->W3_DrainValueLabel->TabIndex = 188;
			this->W3_DrainValueLabel->Text = L"0";
			// 
			// W3_MassValueLabel
			// 
			this->W3_MassValueLabel->AutoSize = true;
			this->W3_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MassValueLabel->Location = System::Drawing::Point(90, 28);
			this->W3_MassValueLabel->Name = L"W3_MassValueLabel";
			this->W3_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->W3_MassValueLabel->TabIndex = 187;
			this->W3_MassValueLabel->Text = L"0";
			// 
			// W3_ArmorValueLabel
			// 
			this->W3_ArmorValueLabel->AutoSize = true;
			this->W3_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_ArmorValueLabel->Location = System::Drawing::Point(90, 2);
			this->W3_ArmorValueLabel->Name = L"W3_ArmorValueLabel";
			this->W3_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->W3_ArmorValueLabel->TabIndex = 186;
			this->W3_ArmorValueLabel->Text = L"0";
			// 
			// W3_RefireLabel
			// 
			this->W3_RefireLabel->AutoSize = true;
			this->W3_RefireLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_RefireLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_RefireLabel->Location = System::Drawing::Point(16, 106);
			this->W3_RefireLabel->Name = L"W3_RefireLabel";
			this->W3_RefireLabel->Size = System::Drawing::Size(50, 13);
			this->W3_RefireLabel->TabIndex = 185;
			this->W3_RefireLabel->Text = L"Refire:";
			// 
			// W3_EPSLabel
			// 
			this->W3_EPSLabel->AutoSize = true;
			this->W3_EPSLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_EPSLabel->Location = System::Drawing::Point(16, 93);
			this->W3_EPSLabel->Name = L"W3_EPSLabel";
			this->W3_EPSLabel->Size = System::Drawing::Size(35, 13);
			this->W3_EPSLabel->TabIndex = 184;
			this->W3_EPSLabel->Text = L"EPS:";
			// 
			// W3_vsALabel
			// 
			this->W3_vsALabel->AutoSize = true;
			this->W3_vsALabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_vsALabel->Location = System::Drawing::Point(16, 80);
			this->W3_vsALabel->Name = L"W3_vsALabel";
			this->W3_vsALabel->Size = System::Drawing::Size(71, 13);
			this->W3_vsALabel->TabIndex = 183;
			this->W3_vsALabel->Text = L"vs Armor:";
			// 
			// W3_vsSLabel
			// 
			this->W3_vsSLabel->AutoSize = true;
			this->W3_vsSLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_vsSLabel->Location = System::Drawing::Point(16, 67);
			this->W3_vsSLabel->Name = L"W3_vsSLabel";
			this->W3_vsSLabel->Size = System::Drawing::Size(77, 13);
			this->W3_vsSLabel->TabIndex = 182;
			this->W3_vsSLabel->Text = L"vs Shields:";
			// 
			// W3_MaxDLabel
			// 
			this->W3_MaxDLabel->AutoSize = true;
			this->W3_MaxDLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MaxDLabel->Location = System::Drawing::Point(16, 54);
			this->W3_MaxDLabel->Name = L"W3_MaxDLabel";
			this->W3_MaxDLabel->Size = System::Drawing::Size(70, 13);
			this->W3_MaxDLabel->TabIndex = 181;
			this->W3_MaxDLabel->Text = L"Max Dmg:";
			// 
			// W3_MinDLabel
			// 
			this->W3_MinDLabel->AutoSize = true;
			this->W3_MinDLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MinDLabel->Location = System::Drawing::Point(16, 41);
			this->W3_MinDLabel->Name = L"W3_MinDLabel";
			this->W3_MinDLabel->Size = System::Drawing::Size(66, 13);
			this->W3_MinDLabel->TabIndex = 180;
			this->W3_MinDLabel->Text = L"Min Dmg:";
			// 
			// W3_DrainLabel
			// 
			this->W3_DrainLabel->AutoSize = true;
			this->W3_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_DrainLabel->Location = System::Drawing::Point(16, 15);
			this->W3_DrainLabel->Name = L"W3_DrainLabel";
			this->W3_DrainLabel->Size = System::Drawing::Size(46, 13);
			this->W3_DrainLabel->TabIndex = 179;
			this->W3_DrainLabel->Text = L"Drain:";
			// 
			// W3_MassLabel
			// 
			this->W3_MassLabel->AutoSize = true;
			this->W3_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_MassLabel->Location = System::Drawing::Point(16, 28);
			this->W3_MassLabel->Name = L"W3_MassLabel";
			this->W3_MassLabel->Size = System::Drawing::Size(43, 13);
			this->W3_MassLabel->TabIndex = 178;
			this->W3_MassLabel->Text = L"Mass:";
			// 
			// W3_ArmorLabel
			// 
			this->W3_ArmorLabel->AutoSize = true;
			this->W3_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->W3_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W3_ArmorLabel->Location = System::Drawing::Point(16, 2);
			this->W3_ArmorLabel->Name = L"W3_ArmorLabel";
			this->W3_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->W3_ArmorLabel->TabIndex = 177;
			this->W3_ArmorLabel->Text = L"Armor:";
			// 
			// W4_RefireValueLabel
			// 
			this->W4_RefireValueLabel->AutoSize = true;
			this->W4_RefireValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_RefireValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_RefireValueLabel->ForeColor = System::Drawing::Color::White;
			this->W4_RefireValueLabel->Location = System::Drawing::Point(92, 106);
			this->W4_RefireValueLabel->Name = L"W4_RefireValueLabel";
			this->W4_RefireValueLabel->Size = System::Drawing::Size(15, 13);
			this->W4_RefireValueLabel->TabIndex = 213;
			this->W4_RefireValueLabel->Text = L"0";
			// 
			// W4_EPSValueLabel
			// 
			this->W4_EPSValueLabel->AutoSize = true;
			this->W4_EPSValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_EPSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_EPSValueLabel->ForeColor = System::Drawing::Color::White;
			this->W4_EPSValueLabel->Location = System::Drawing::Point(92, 93);
			this->W4_EPSValueLabel->Name = L"W4_EPSValueLabel";
			this->W4_EPSValueLabel->Size = System::Drawing::Size(15, 13);
			this->W4_EPSValueLabel->TabIndex = 212;
			this->W4_EPSValueLabel->Text = L"0";
			// 
			// W4_vsAValueLabel
			// 
			this->W4_vsAValueLabel->AutoSize = true;
			this->W4_vsAValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_vsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_vsAValueLabel->ForeColor = System::Drawing::Color::White;
			this->W4_vsAValueLabel->Location = System::Drawing::Point(92, 80);
			this->W4_vsAValueLabel->Name = L"W4_vsAValueLabel";
			this->W4_vsAValueLabel->Size = System::Drawing::Size(15, 13);
			this->W4_vsAValueLabel->TabIndex = 211;
			this->W4_vsAValueLabel->Text = L"0";
			// 
			// W4_vsSValueLabel
			// 
			this->W4_vsSValueLabel->AutoSize = true;
			this->W4_vsSValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_vsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_vsSValueLabel->ForeColor = System::Drawing::Color::White;
			this->W4_vsSValueLabel->Location = System::Drawing::Point(92, 67);
			this->W4_vsSValueLabel->Name = L"W4_vsSValueLabel";
			this->W4_vsSValueLabel->Size = System::Drawing::Size(15, 13);
			this->W4_vsSValueLabel->TabIndex = 210;
			this->W4_vsSValueLabel->Text = L"0";
			// 
			// W4_MaxDValueLabel
			// 
			this->W4_MaxDValueLabel->AutoSize = true;
			this->W4_MaxDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_MaxDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MaxDValueLabel->ForeColor = System::Drawing::Color::White;
			this->W4_MaxDValueLabel->Location = System::Drawing::Point(92, 54);
			this->W4_MaxDValueLabel->Name = L"W4_MaxDValueLabel";
			this->W4_MaxDValueLabel->Size = System::Drawing::Size(15, 13);
			this->W4_MaxDValueLabel->TabIndex = 209;
			this->W4_MaxDValueLabel->Text = L"0";
			// 
			// W4_MinDValueLabel
			// 
			this->W4_MinDValueLabel->AutoSize = true;
			this->W4_MinDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_MinDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MinDValueLabel->ForeColor = System::Drawing::Color::White;
			this->W4_MinDValueLabel->Location = System::Drawing::Point(92, 41);
			this->W4_MinDValueLabel->Name = L"W4_MinDValueLabel";
			this->W4_MinDValueLabel->Size = System::Drawing::Size(15, 13);
			this->W4_MinDValueLabel->TabIndex = 208;
			this->W4_MinDValueLabel->Text = L"0";
			// 
			// W4_DrainValueLabel
			// 
			this->W4_DrainValueLabel->AutoSize = true;
			this->W4_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_DrainValueLabel->ForeColor = System::Drawing::Color::White;
			this->W4_DrainValueLabel->Location = System::Drawing::Point(92, 15);
			this->W4_DrainValueLabel->Name = L"W4_DrainValueLabel";
			this->W4_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->W4_DrainValueLabel->TabIndex = 207;
			this->W4_DrainValueLabel->Text = L"0";
			// 
			// W4_MassValueLabel
			// 
			this->W4_MassValueLabel->AutoSize = true;
			this->W4_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MassValueLabel->ForeColor = System::Drawing::Color::White;
			this->W4_MassValueLabel->Location = System::Drawing::Point(92, 28);
			this->W4_MassValueLabel->Name = L"W4_MassValueLabel";
			this->W4_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->W4_MassValueLabel->TabIndex = 206;
			this->W4_MassValueLabel->Text = L"0";
			// 
			// W4_ArmorValueLabel
			// 
			this->W4_ArmorValueLabel->AutoSize = true;
			this->W4_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_ArmorValueLabel->ForeColor = System::Drawing::Color::White;
			this->W4_ArmorValueLabel->Location = System::Drawing::Point(92, 2);
			this->W4_ArmorValueLabel->Name = L"W4_ArmorValueLabel";
			this->W4_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->W4_ArmorValueLabel->TabIndex = 205;
			this->W4_ArmorValueLabel->Text = L"0";
			// 
			// W4_RefireLabel
			// 
			this->W4_RefireLabel->AutoSize = true;
			this->W4_RefireLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_RefireLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_RefireLabel->ForeColor = System::Drawing::Color::White;
			this->W4_RefireLabel->Location = System::Drawing::Point(16, 106);
			this->W4_RefireLabel->Name = L"W4_RefireLabel";
			this->W4_RefireLabel->Size = System::Drawing::Size(50, 13);
			this->W4_RefireLabel->TabIndex = 204;
			this->W4_RefireLabel->Text = L"Refire:";
			// 
			// W4_EPSLabel
			// 
			this->W4_EPSLabel->AutoSize = true;
			this->W4_EPSLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_EPSLabel->ForeColor = System::Drawing::Color::White;
			this->W4_EPSLabel->Location = System::Drawing::Point(16, 93);
			this->W4_EPSLabel->Name = L"W4_EPSLabel";
			this->W4_EPSLabel->Size = System::Drawing::Size(35, 13);
			this->W4_EPSLabel->TabIndex = 203;
			this->W4_EPSLabel->Text = L"EPS:";
			// 
			// W4_vsALabel
			// 
			this->W4_vsALabel->AutoSize = true;
			this->W4_vsALabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_vsALabel->ForeColor = System::Drawing::Color::White;
			this->W4_vsALabel->Location = System::Drawing::Point(16, 80);
			this->W4_vsALabel->Name = L"W4_vsALabel";
			this->W4_vsALabel->Size = System::Drawing::Size(71, 13);
			this->W4_vsALabel->TabIndex = 202;
			this->W4_vsALabel->Text = L"vs Armor:";
			// 
			// W4_vsSLabel
			// 
			this->W4_vsSLabel->AutoSize = true;
			this->W4_vsSLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_vsSLabel->ForeColor = System::Drawing::Color::White;
			this->W4_vsSLabel->Location = System::Drawing::Point(16, 67);
			this->W4_vsSLabel->Name = L"W4_vsSLabel";
			this->W4_vsSLabel->Size = System::Drawing::Size(77, 13);
			this->W4_vsSLabel->TabIndex = 201;
			this->W4_vsSLabel->Text = L"vs Shields:";
			// 
			// W4_MaxDLabel
			// 
			this->W4_MaxDLabel->AutoSize = true;
			this->W4_MaxDLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MaxDLabel->ForeColor = System::Drawing::Color::White;
			this->W4_MaxDLabel->Location = System::Drawing::Point(16, 54);
			this->W4_MaxDLabel->Name = L"W4_MaxDLabel";
			this->W4_MaxDLabel->Size = System::Drawing::Size(70, 13);
			this->W4_MaxDLabel->TabIndex = 200;
			this->W4_MaxDLabel->Text = L"Max Dmg:";
			// 
			// W4_MinDLabel
			// 
			this->W4_MinDLabel->AutoSize = true;
			this->W4_MinDLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MinDLabel->ForeColor = System::Drawing::Color::White;
			this->W4_MinDLabel->Location = System::Drawing::Point(16, 41);
			this->W4_MinDLabel->Name = L"W4_MinDLabel";
			this->W4_MinDLabel->Size = System::Drawing::Size(66, 13);
			this->W4_MinDLabel->TabIndex = 199;
			this->W4_MinDLabel->Text = L"Min Dmg:";
			// 
			// W4_DrainLabel
			// 
			this->W4_DrainLabel->AutoSize = true;
			this->W4_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_DrainLabel->ForeColor = System::Drawing::Color::White;
			this->W4_DrainLabel->Location = System::Drawing::Point(16, 15);
			this->W4_DrainLabel->Name = L"W4_DrainLabel";
			this->W4_DrainLabel->Size = System::Drawing::Size(46, 13);
			this->W4_DrainLabel->TabIndex = 198;
			this->W4_DrainLabel->Text = L"Drain:";
			// 
			// W4_MassLabel
			// 
			this->W4_MassLabel->AutoSize = true;
			this->W4_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_MassLabel->ForeColor = System::Drawing::Color::White;
			this->W4_MassLabel->Location = System::Drawing::Point(16, 28);
			this->W4_MassLabel->Name = L"W4_MassLabel";
			this->W4_MassLabel->Size = System::Drawing::Size(43, 13);
			this->W4_MassLabel->TabIndex = 197;
			this->W4_MassLabel->Text = L"Mass:";
			// 
			// W4_ArmorLabel
			// 
			this->W4_ArmorLabel->AutoSize = true;
			this->W4_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->W4_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W4_ArmorLabel->ForeColor = System::Drawing::Color::White;
			this->W4_ArmorLabel->Location = System::Drawing::Point(16, 2);
			this->W4_ArmorLabel->Name = L"W4_ArmorLabel";
			this->W4_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->W4_ArmorLabel->TabIndex = 196;
			this->W4_ArmorLabel->Text = L"Armor:";
			// 
			// O1_AmmoValueLabel
			// 
			this->O1_AmmoValueLabel->AutoSize = true;
			this->O1_AmmoValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_AmmoValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_AmmoValueLabel->Location = System::Drawing::Point(91, 91);
			this->O1_AmmoValueLabel->Name = L"O1_AmmoValueLabel";
			this->O1_AmmoValueLabel->Size = System::Drawing::Size(15, 13);
			this->O1_AmmoValueLabel->TabIndex = 231;
			this->O1_AmmoValueLabel->Text = L"0";
			// 
			// O1_vsAValueLabel
			// 
			this->O1_vsAValueLabel->AutoSize = true;
			this->O1_vsAValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_vsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_vsAValueLabel->Location = System::Drawing::Point(91, 78);
			this->O1_vsAValueLabel->Name = L"O1_vsAValueLabel";
			this->O1_vsAValueLabel->Size = System::Drawing::Size(15, 13);
			this->O1_vsAValueLabel->TabIndex = 230;
			this->O1_vsAValueLabel->Text = L"0";
			// 
			// O1_vsSValueLabel
			// 
			this->O1_vsSValueLabel->AutoSize = true;
			this->O1_vsSValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_vsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_vsSValueLabel->Location = System::Drawing::Point(91, 65);
			this->O1_vsSValueLabel->Name = L"O1_vsSValueLabel";
			this->O1_vsSValueLabel->Size = System::Drawing::Size(15, 13);
			this->O1_vsSValueLabel->TabIndex = 229;
			this->O1_vsSValueLabel->Text = L"0";
			// 
			// O1_MaxDValueLabel
			// 
			this->O1_MaxDValueLabel->AutoSize = true;
			this->O1_MaxDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_MaxDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_MaxDValueLabel->Location = System::Drawing::Point(91, 52);
			this->O1_MaxDValueLabel->Name = L"O1_MaxDValueLabel";
			this->O1_MaxDValueLabel->Size = System::Drawing::Size(15, 13);
			this->O1_MaxDValueLabel->TabIndex = 228;
			this->O1_MaxDValueLabel->Text = L"0";
			// 
			// O1_MinDValueLabel
			// 
			this->O1_MinDValueLabel->AutoSize = true;
			this->O1_MinDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_MinDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_MinDValueLabel->Location = System::Drawing::Point(91, 39);
			this->O1_MinDValueLabel->Name = L"O1_MinDValueLabel";
			this->O1_MinDValueLabel->Size = System::Drawing::Size(15, 13);
			this->O1_MinDValueLabel->TabIndex = 227;
			this->O1_MinDValueLabel->Text = L"0";
			// 
			// O1_DrainValueLabel
			// 
			this->O1_DrainValueLabel->AutoSize = true;
			this->O1_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_DrainValueLabel->Location = System::Drawing::Point(91, 13);
			this->O1_DrainValueLabel->Name = L"O1_DrainValueLabel";
			this->O1_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->O1_DrainValueLabel->TabIndex = 226;
			this->O1_DrainValueLabel->Text = L"0";
			// 
			// O1_MassValueLabel
			// 
			this->O1_MassValueLabel->AutoSize = true;
			this->O1_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_MassValueLabel->Location = System::Drawing::Point(91, 26);
			this->O1_MassValueLabel->Name = L"O1_MassValueLabel";
			this->O1_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->O1_MassValueLabel->TabIndex = 225;
			this->O1_MassValueLabel->Text = L"0";
			// 
			// O1_ArmorValueLabel
			// 
			this->O1_ArmorValueLabel->AutoSize = true;
			this->O1_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_ArmorValueLabel->Location = System::Drawing::Point(91, 0);
			this->O1_ArmorValueLabel->Name = L"O1_ArmorValueLabel";
			this->O1_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->O1_ArmorValueLabel->TabIndex = 224;
			this->O1_ArmorValueLabel->Text = L"0";
			// 
			// O1_AmmoLabel
			// 
			this->O1_AmmoLabel->AutoSize = true;
			this->O1_AmmoLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_AmmoLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_AmmoLabel->Location = System::Drawing::Point(16, 91);
			this->O1_AmmoLabel->Name = L"O1_AmmoLabel";
			this->O1_AmmoLabel->Size = System::Drawing::Size(52, 13);
			this->O1_AmmoLabel->TabIndex = 222;
			this->O1_AmmoLabel->Text = L"Ammo:";
			// 
			// O1_vsALabel
			// 
			this->O1_vsALabel->AutoSize = true;
			this->O1_vsALabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_vsALabel->Location = System::Drawing::Point(16, 78);
			this->O1_vsALabel->Name = L"O1_vsALabel";
			this->O1_vsALabel->Size = System::Drawing::Size(71, 13);
			this->O1_vsALabel->TabIndex = 221;
			this->O1_vsALabel->Text = L"vs Armor:";
			// 
			// O1_vsSLabel
			// 
			this->O1_vsSLabel->AutoSize = true;
			this->O1_vsSLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_vsSLabel->Location = System::Drawing::Point(16, 65);
			this->O1_vsSLabel->Name = L"O1_vsSLabel";
			this->O1_vsSLabel->Size = System::Drawing::Size(77, 13);
			this->O1_vsSLabel->TabIndex = 220;
			this->O1_vsSLabel->Text = L"vs Shields:";
			// 
			// O1_MaxDLabel
			// 
			this->O1_MaxDLabel->AutoSize = true;
			this->O1_MaxDLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_MaxDLabel->Location = System::Drawing::Point(16, 52);
			this->O1_MaxDLabel->Name = L"O1_MaxDLabel";
			this->O1_MaxDLabel->Size = System::Drawing::Size(70, 13);
			this->O1_MaxDLabel->TabIndex = 219;
			this->O1_MaxDLabel->Text = L"Max Dmg:";
			// 
			// O1_MinDLabel
			// 
			this->O1_MinDLabel->AutoSize = true;
			this->O1_MinDLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_MinDLabel->Location = System::Drawing::Point(16, 39);
			this->O1_MinDLabel->Name = L"O1_MinDLabel";
			this->O1_MinDLabel->Size = System::Drawing::Size(66, 13);
			this->O1_MinDLabel->TabIndex = 218;
			this->O1_MinDLabel->Text = L"Min Dmg:";
			// 
			// O1_DrainLabel
			// 
			this->O1_DrainLabel->AutoSize = true;
			this->O1_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_DrainLabel->Location = System::Drawing::Point(16, 13);
			this->O1_DrainLabel->Name = L"O1_DrainLabel";
			this->O1_DrainLabel->Size = System::Drawing::Size(46, 13);
			this->O1_DrainLabel->TabIndex = 217;
			this->O1_DrainLabel->Text = L"Drain:";
			// 
			// O1_MassLabel
			// 
			this->O1_MassLabel->AutoSize = true;
			this->O1_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_MassLabel->Location = System::Drawing::Point(16, 26);
			this->O1_MassLabel->Name = L"O1_MassLabel";
			this->O1_MassLabel->Size = System::Drawing::Size(43, 13);
			this->O1_MassLabel->TabIndex = 216;
			this->O1_MassLabel->Text = L"Mass:";
			// 
			// O1_ArmorLabel
			// 
			this->O1_ArmorLabel->AutoSize = true;
			this->O1_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->O1_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O1_ArmorLabel->Location = System::Drawing::Point(16, 0);
			this->O1_ArmorLabel->Name = L"O1_ArmorLabel";
			this->O1_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->O1_ArmorLabel->TabIndex = 215;
			this->O1_ArmorLabel->Text = L"Armor:";
			// 
			// O2_AmmoValueLabel
			// 
			this->O2_AmmoValueLabel->AutoSize = true;
			this->O2_AmmoValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_AmmoValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_AmmoValueLabel->Location = System::Drawing::Point(91, 91);
			this->O2_AmmoValueLabel->Name = L"O2_AmmoValueLabel";
			this->O2_AmmoValueLabel->Size = System::Drawing::Size(15, 13);
			this->O2_AmmoValueLabel->TabIndex = 248;
			this->O2_AmmoValueLabel->Text = L"0";
			// 
			// O2_vsAValueLabel
			// 
			this->O2_vsAValueLabel->AutoSize = true;
			this->O2_vsAValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_vsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_vsAValueLabel->Location = System::Drawing::Point(91, 78);
			this->O2_vsAValueLabel->Name = L"O2_vsAValueLabel";
			this->O2_vsAValueLabel->Size = System::Drawing::Size(15, 13);
			this->O2_vsAValueLabel->TabIndex = 247;
			this->O2_vsAValueLabel->Text = L"0";
			// 
			// O2_vsSValueLabel
			// 
			this->O2_vsSValueLabel->AutoSize = true;
			this->O2_vsSValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_vsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_vsSValueLabel->Location = System::Drawing::Point(91, 65);
			this->O2_vsSValueLabel->Name = L"O2_vsSValueLabel";
			this->O2_vsSValueLabel->Size = System::Drawing::Size(15, 13);
			this->O2_vsSValueLabel->TabIndex = 246;
			this->O2_vsSValueLabel->Text = L"0";
			// 
			// O2_MaxDValueLabel
			// 
			this->O2_MaxDValueLabel->AutoSize = true;
			this->O2_MaxDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_MaxDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_MaxDValueLabel->Location = System::Drawing::Point(91, 52);
			this->O2_MaxDValueLabel->Name = L"O2_MaxDValueLabel";
			this->O2_MaxDValueLabel->Size = System::Drawing::Size(15, 13);
			this->O2_MaxDValueLabel->TabIndex = 245;
			this->O2_MaxDValueLabel->Text = L"0";
			// 
			// O2_MinDValueLabel
			// 
			this->O2_MinDValueLabel->AutoSize = true;
			this->O2_MinDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_MinDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_MinDValueLabel->Location = System::Drawing::Point(91, 39);
			this->O2_MinDValueLabel->Name = L"O2_MinDValueLabel";
			this->O2_MinDValueLabel->Size = System::Drawing::Size(15, 13);
			this->O2_MinDValueLabel->TabIndex = 244;
			this->O2_MinDValueLabel->Text = L"0";
			// 
			// O2_DrainValueLabel
			// 
			this->O2_DrainValueLabel->AutoSize = true;
			this->O2_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_DrainValueLabel->Location = System::Drawing::Point(91, 13);
			this->O2_DrainValueLabel->Name = L"O2_DrainValueLabel";
			this->O2_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->O2_DrainValueLabel->TabIndex = 243;
			this->O2_DrainValueLabel->Text = L"0";
			// 
			// O2_MassValueLabel
			// 
			this->O2_MassValueLabel->AutoSize = true;
			this->O2_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_MassValueLabel->Location = System::Drawing::Point(91, 26);
			this->O2_MassValueLabel->Name = L"O2_MassValueLabel";
			this->O2_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->O2_MassValueLabel->TabIndex = 242;
			this->O2_MassValueLabel->Text = L"0";
			// 
			// O2_ArmorValueLabel
			// 
			this->O2_ArmorValueLabel->AutoSize = true;
			this->O2_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_ArmorValueLabel->Location = System::Drawing::Point(91, 0);
			this->O2_ArmorValueLabel->Name = L"O2_ArmorValueLabel";
			this->O2_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->O2_ArmorValueLabel->TabIndex = 241;
			this->O2_ArmorValueLabel->Text = L"0";
			// 
			// O2_AmmoLabel
			// 
			this->O2_AmmoLabel->AutoSize = true;
			this->O2_AmmoLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_AmmoLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_AmmoLabel->Location = System::Drawing::Point(16, 91);
			this->O2_AmmoLabel->Name = L"O2_AmmoLabel";
			this->O2_AmmoLabel->Size = System::Drawing::Size(52, 13);
			this->O2_AmmoLabel->TabIndex = 240;
			this->O2_AmmoLabel->Text = L"Ammo:";
			// 
			// O2_vsALabel
			// 
			this->O2_vsALabel->AutoSize = true;
			this->O2_vsALabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_vsALabel->Location = System::Drawing::Point(16, 78);
			this->O2_vsALabel->Name = L"O2_vsALabel";
			this->O2_vsALabel->Size = System::Drawing::Size(71, 13);
			this->O2_vsALabel->TabIndex = 239;
			this->O2_vsALabel->Text = L"vs Armor:";
			// 
			// O2_vsSLabel
			// 
			this->O2_vsSLabel->AutoSize = true;
			this->O2_vsSLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_vsSLabel->Location = System::Drawing::Point(16, 65);
			this->O2_vsSLabel->Name = L"O2_vsSLabel";
			this->O2_vsSLabel->Size = System::Drawing::Size(77, 13);
			this->O2_vsSLabel->TabIndex = 238;
			this->O2_vsSLabel->Text = L"vs Shields:";
			// 
			// O2_MaxDLabel
			// 
			this->O2_MaxDLabel->AutoSize = true;
			this->O2_MaxDLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_MaxDLabel->Location = System::Drawing::Point(16, 52);
			this->O2_MaxDLabel->Name = L"O2_MaxDLabel";
			this->O2_MaxDLabel->Size = System::Drawing::Size(70, 13);
			this->O2_MaxDLabel->TabIndex = 237;
			this->O2_MaxDLabel->Text = L"Max Dmg:";
			// 
			// O2_MinDLabel
			// 
			this->O2_MinDLabel->AutoSize = true;
			this->O2_MinDLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_MinDLabel->Location = System::Drawing::Point(16, 39);
			this->O2_MinDLabel->Name = L"O2_MinDLabel";
			this->O2_MinDLabel->Size = System::Drawing::Size(66, 13);
			this->O2_MinDLabel->TabIndex = 236;
			this->O2_MinDLabel->Text = L"Min Dmg:";
			// 
			// O2_DrainLabel
			// 
			this->O2_DrainLabel->AutoSize = true;
			this->O2_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_DrainLabel->Location = System::Drawing::Point(16, 13);
			this->O2_DrainLabel->Name = L"O2_DrainLabel";
			this->O2_DrainLabel->Size = System::Drawing::Size(46, 13);
			this->O2_DrainLabel->TabIndex = 235;
			this->O2_DrainLabel->Text = L"Drain:";
			// 
			// O2_MassLabel
			// 
			this->O2_MassLabel->AutoSize = true;
			this->O2_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_MassLabel->Location = System::Drawing::Point(16, 26);
			this->O2_MassLabel->Name = L"O2_MassLabel";
			this->O2_MassLabel->Size = System::Drawing::Size(43, 13);
			this->O2_MassLabel->TabIndex = 234;
			this->O2_MassLabel->Text = L"Mass:";
			// 
			// O2_ArmorLabel
			// 
			this->O2_ArmorLabel->AutoSize = true;
			this->O2_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->O2_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O2_ArmorLabel->Location = System::Drawing::Point(16, 0);
			this->O2_ArmorLabel->Name = L"O2_ArmorLabel";
			this->O2_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->O2_ArmorLabel->TabIndex = 233;
			this->O2_ArmorLabel->Text = L"Armor:";
			// 
			// CM_DrainValueLabel
			// 
			this->CM_DrainValueLabel->AutoSize = true;
			this->CM_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->CM_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CM_DrainValueLabel->Location = System::Drawing::Point(79, 15);
			this->CM_DrainValueLabel->Name = L"CM_DrainValueLabel";
			this->CM_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->CM_DrainValueLabel->TabIndex = 273;
			this->CM_DrainValueLabel->Text = L"0";
			// 
			// CM_MassValueLabel
			// 
			this->CM_MassValueLabel->AutoSize = true;
			this->CM_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->CM_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CM_MassValueLabel->Location = System::Drawing::Point(79, 28);
			this->CM_MassValueLabel->Name = L"CM_MassValueLabel";
			this->CM_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->CM_MassValueLabel->TabIndex = 272;
			this->CM_MassValueLabel->Text = L"0";
			// 
			// CM_ArmorValueLabel
			// 
			this->CM_ArmorValueLabel->AutoSize = true;
			this->CM_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->CM_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CM_ArmorValueLabel->Location = System::Drawing::Point(78, 2);
			this->CM_ArmorValueLabel->Name = L"CM_ArmorValueLabel";
			this->CM_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->CM_ArmorValueLabel->TabIndex = 271;
			this->CM_ArmorValueLabel->Text = L"0";
			// 
			// CM_DrainLabel
			// 
			this->CM_DrainLabel->AutoSize = true;
			this->CM_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->CM_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CM_DrainLabel->Location = System::Drawing::Point(17, 15);
			this->CM_DrainLabel->Name = L"CM_DrainLabel";
			this->CM_DrainLabel->Size = System::Drawing::Size(46, 13);
			this->CM_DrainLabel->TabIndex = 269;
			this->CM_DrainLabel->Text = L"Drain:";
			// 
			// CM_MassLabel
			// 
			this->CM_MassLabel->AutoSize = true;
			this->CM_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->CM_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CM_MassLabel->Location = System::Drawing::Point(17, 28);
			this->CM_MassLabel->Name = L"CM_MassLabel";
			this->CM_MassLabel->Size = System::Drawing::Size(43, 13);
			this->CM_MassLabel->TabIndex = 268;
			this->CM_MassLabel->Text = L"Mass:";
			// 
			// CM_ArmorLabel
			// 
			this->CM_ArmorLabel->AutoSize = true;
			this->CM_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->CM_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CM_ArmorLabel->Location = System::Drawing::Point(16, 2);
			this->CM_ArmorLabel->Name = L"CM_ArmorLabel";
			this->CM_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->CM_ArmorLabel->TabIndex = 267;
			this->CM_ArmorLabel->Text = L"Armor:";
			// 
			// ComponentsLabel
			// 
			this->ComponentsLabel->AutoSize = true;
			this->ComponentsLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ComponentsLabel->Location = System::Drawing::Point(348, 190);
			this->ComponentsLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ComponentsLabel->Name = L"ComponentsLabel";
			this->ComponentsLabel->Size = System::Drawing::Size(172, 16);
			this->ComponentsLabel->TabIndex = 274;
			this->ComponentsLabel->Text = L"C  o  m  p  o  n  e  n  t  s";
			// 
			// ReactorCompLabel
			// 
			this->ReactorCompLabel->AutoSize = true;
			this->ReactorCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorCompLabel->Location = System::Drawing::Point(56, 208);
			this->ReactorCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ReactorCompLabel->Name = L"ReactorCompLabel";
			this->ReactorCompLabel->Size = System::Drawing::Size(64, 16);
			this->ReactorCompLabel->TabIndex = 276;
			this->ReactorCompLabel->Text = L"Reactor";
			// 
			// EngineCompLabel
			// 
			this->EngineCompLabel->AutoSize = true;
			this->EngineCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineCompLabel->Location = System::Drawing::Point(234, 208);
			this->EngineCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EngineCompLabel->Name = L"EngineCompLabel";
			this->EngineCompLabel->Size = System::Drawing::Size(57, 16);
			this->EngineCompLabel->TabIndex = 277;
			this->EngineCompLabel->Text = L"Engine";
			// 
			// BoosterCompLabel
			// 
			this->BoosterCompLabel->AutoSize = true;
			this->BoosterCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterCompLabel->Location = System::Drawing::Point(402, 208);
			this->BoosterCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->BoosterCompLabel->Name = L"BoosterCompLabel";
			this->BoosterCompLabel->Size = System::Drawing::Size(65, 16);
			this->BoosterCompLabel->TabIndex = 278;
			this->BoosterCompLabel->Text = L"Booster";
			// 
			// SheildCompLabel
			// 
			this->SheildCompLabel->AutoSize = true;
			this->SheildCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildCompLabel->Location = System::Drawing::Point(579, 208);
			this->SheildCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->SheildCompLabel->Name = L"SheildCompLabel";
			this->SheildCompLabel->Size = System::Drawing::Size(52, 16);
			this->SheildCompLabel->TabIndex = 279;
			this->SheildCompLabel->Text = L"Shield";
			// 
			// FArmorCompLabel
			// 
			this->FArmorCompLabel->AutoSize = true;
			this->FArmorCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FArmorCompLabel->Location = System::Drawing::Point(727, 208);
			this->FArmorCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->FArmorCompLabel->Name = L"FArmorCompLabel";
			this->FArmorCompLabel->Size = System::Drawing::Size(110, 16);
			this->FArmorCompLabel->TabIndex = 280;
			this->FArmorCompLabel->Text = L"Armor (Front)";
			// 
			// DroidCompLabel
			// 
			this->DroidCompLabel->AutoSize = true;
			this->DroidCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DroidCompLabel->Location = System::Drawing::Point(29, 371);
			this->DroidCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DroidCompLabel->Name = L"DroidCompLabel";
			this->DroidCompLabel->Size = System::Drawing::Size(117, 16);
			this->DroidCompLabel->TabIndex = 282;
			this->DroidCompLabel->Text = L"Droid Interface";
			// 
			// CapacitorCompLabel
			// 
			this->CapacitorCompLabel->AutoSize = true;
			this->CapacitorCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorCompLabel->Location = System::Drawing::Point(220, 370);
			this->CapacitorCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->CapacitorCompLabel->Name = L"CapacitorCompLabel";
			this->CapacitorCompLabel->Size = System::Drawing::Size(78, 16);
			this->CapacitorCompLabel->TabIndex = 283;
			this->CapacitorCompLabel->Text = L"Capacitor";
			// 
			// Ordinanace1CompLabel
			// 
			this->Ordinanace1CompLabel->AutoSize = true;
			this->Ordinanace1CompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinanace1CompLabel->Location = System::Drawing::Point(386, 370);
			this->Ordinanace1CompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Ordinanace1CompLabel->Name = L"Ordinanace1CompLabel";
			this->Ordinanace1CompLabel->Size = System::Drawing::Size(95, 16);
			this->Ordinanace1CompLabel->TabIndex = 284;
			this->Ordinanace1CompLabel->Text = L"Ordinance 1";
			// 
			// Ordinance2CompLabel
			// 
			this->Ordinance2CompLabel->AutoSize = true;
			this->Ordinance2CompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance2CompLabel->Location = System::Drawing::Point(559, 371);
			this->Ordinance2CompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Ordinance2CompLabel->Name = L"Ordinance2CompLabel";
			this->Ordinance2CompLabel->Size = System::Drawing::Size(95, 16);
			this->Ordinance2CompLabel->TabIndex = 285;
			this->Ordinance2CompLabel->Text = L"Ordinance 2";
			// 
			// Ordinance3CompLabel
			// 
			this->Ordinance3CompLabel->AutoSize = true;
			this->Ordinance3CompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance3CompLabel->Location = System::Drawing::Point(732, 370);
			this->Ordinance3CompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Ordinance3CompLabel->Name = L"Ordinance3CompLabel";
			this->Ordinance3CompLabel->Size = System::Drawing::Size(95, 16);
			this->Ordinance3CompLabel->TabIndex = 286;
			this->Ordinance3CompLabel->Text = L"Ordinance 3";
			// 
			// Weapon1CompLabel
			// 
			this->Weapon1CompLabel->AutoSize = true;
			this->Weapon1CompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon1CompLabel->Location = System::Drawing::Point(48, 537);
			this->Weapon1CompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Weapon1CompLabel->Name = L"Weapon1CompLabel";
			this->Weapon1CompLabel->Size = System::Drawing::Size(80, 16);
			this->Weapon1CompLabel->TabIndex = 287;
			this->Weapon1CompLabel->Text = L"Weapon 1";
			// 
			// Weapon2CompLabel
			// 
			this->Weapon2CompLabel->AutoSize = true;
			this->Weapon2CompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon2CompLabel->Location = System::Drawing::Point(220, 538);
			this->Weapon2CompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Weapon2CompLabel->Name = L"Weapon2CompLabel";
			this->Weapon2CompLabel->Size = System::Drawing::Size(80, 16);
			this->Weapon2CompLabel->TabIndex = 288;
			this->Weapon2CompLabel->Text = L"Weapon 2";
			// 
			// Weapon3CompLabel
			// 
			this->Weapon3CompLabel->AutoSize = true;
			this->Weapon3CompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon3CompLabel->Location = System::Drawing::Point(393, 538);
			this->Weapon3CompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Weapon3CompLabel->Name = L"Weapon3CompLabel";
			this->Weapon3CompLabel->Size = System::Drawing::Size(80, 16);
			this->Weapon3CompLabel->TabIndex = 289;
			this->Weapon3CompLabel->Text = L"Weapon 3";
			// 
			// Weapon4CompLabel
			// 
			this->Weapon4CompLabel->AutoSize = true;
			this->Weapon4CompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon4CompLabel->Location = System::Drawing::Point(568, 538);
			this->Weapon4CompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Weapon4CompLabel->Name = L"Weapon4CompLabel";
			this->Weapon4CompLabel->Size = System::Drawing::Size(80, 16);
			this->Weapon4CompLabel->TabIndex = 290;
			this->Weapon4CompLabel->Text = L"Weapon 4";
			// 
			// CountermeasuresCompLabel
			// 
			this->CountermeasuresCompLabel->AutoSize = true;
			this->CountermeasuresCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CountermeasuresCompLabel->Location = System::Drawing::Point(711, 537);
			this->CountermeasuresCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->CountermeasuresCompLabel->Name = L"CountermeasuresCompLabel";
			this->CountermeasuresCompLabel->Size = System::Drawing::Size(138, 16);
			this->CountermeasuresCompLabel->TabIndex = 291;
			this->CountermeasuresCompLabel->Text = L"Countermeasures";
			// 
			// ReactorComboBox
			// 
			this->ReactorComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ReactorComboBox->DropDownWidth = 200;
			this->ReactorComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorComboBox->FormattingEnabled = true;
			this->ReactorComboBox->Location = System::Drawing::Point(17, 123);
			this->ReactorComboBox->Name = L"ReactorComboBox";
			this->ReactorComboBox->Size = System::Drawing::Size(138, 21);
			this->ReactorComboBox->TabIndex = 6;
			this->ReactorComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ReactorComboBox_SelectedIndexChanged);
			// 
			// Weapon2ComboBox
			// 
			this->Weapon2ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Weapon2ComboBox->DropDownWidth = 200;
			this->Weapon2ComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon2ComboBox->FormattingEnabled = true;
			this->Weapon2ComboBox->Location = System::Drawing::Point(17, 124);
			this->Weapon2ComboBox->Name = L"Weapon2ComboBox";
			this->Weapon2ComboBox->Size = System::Drawing::Size(138, 21);
			this->Weapon2ComboBox->TabIndex = 18;
			this->Weapon2ComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::Weapon2ComboBox_SelectedIndexChanged);
			// 
			// Weapon1ComboBox
			// 
			this->Weapon1ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Weapon1ComboBox->DropDownWidth = 200;
			this->Weapon1ComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon1ComboBox->FormattingEnabled = true;
			this->Weapon1ComboBox->Location = System::Drawing::Point(17, 123);
			this->Weapon1ComboBox->Name = L"Weapon1ComboBox";
			this->Weapon1ComboBox->Size = System::Drawing::Size(138, 21);
			this->Weapon1ComboBox->TabIndex = 17;
			this->Weapon1ComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::Weapon1ComboBox_SelectedIndexChanged);
			// 
			// Ordinance3ComboBox
			// 
			this->Ordinance3ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Ordinance3ComboBox->DropDownWidth = 200;
			this->Ordinance3ComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance3ComboBox->FormattingEnabled = true;
			this->Ordinance3ComboBox->Location = System::Drawing::Point(17, 124);
			this->Ordinance3ComboBox->Name = L"Ordinance3ComboBox";
			this->Ordinance3ComboBox->Size = System::Drawing::Size(138, 21);
			this->Ordinance3ComboBox->TabIndex = 16;
			this->Ordinance3ComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::Ordinance3ComboBox_SelectedIndexChanged);
			// 
			// Ordinance2ComboBox
			// 
			this->Ordinance2ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Ordinance2ComboBox->DropDownWidth = 200;
			this->Ordinance2ComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance2ComboBox->FormattingEnabled = true;
			this->Ordinance2ComboBox->Location = System::Drawing::Point(17, 123);
			this->Ordinance2ComboBox->Name = L"Ordinance2ComboBox";
			this->Ordinance2ComboBox->Size = System::Drawing::Size(138, 21);
			this->Ordinance2ComboBox->TabIndex = 15;
			this->Ordinance2ComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::Ordinance2ComboBox_SelectedIndexChanged);
			// 
			// Ordinance1ComboBox
			// 
			this->Ordinance1ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Ordinance1ComboBox->DropDownWidth = 200;
			this->Ordinance1ComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ordinance1ComboBox->FormattingEnabled = true;
			this->Ordinance1ComboBox->Location = System::Drawing::Point(17, 123);
			this->Ordinance1ComboBox->Name = L"Ordinance1ComboBox";
			this->Ordinance1ComboBox->Size = System::Drawing::Size(138, 21);
			this->Ordinance1ComboBox->TabIndex = 14;
			this->Ordinance1ComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::Ordinance1ComboBox_SelectedIndexChanged);
			// 
			// CapacitorComboBox
			// 
			this->CapacitorComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CapacitorComboBox->DropDownWidth = 200;
			this->CapacitorComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorComboBox->FormattingEnabled = true;
			this->CapacitorComboBox->Location = System::Drawing::Point(17, 123);
			this->CapacitorComboBox->Name = L"CapacitorComboBox";
			this->CapacitorComboBox->Size = System::Drawing::Size(138, 21);
			this->CapacitorComboBox->TabIndex = 13;
			this->CapacitorComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::CapacitorComboBox_SelectedIndexChanged);
			// 
			// DroidComboBox
			// 
			this->DroidComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->DroidComboBox->DropDownWidth = 200;
			this->DroidComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DroidComboBox->FormattingEnabled = true;
			this->DroidComboBox->Location = System::Drawing::Point(17, 123);
			this->DroidComboBox->Name = L"DroidComboBox";
			this->DroidComboBox->Size = System::Drawing::Size(138, 21);
			this->DroidComboBox->TabIndex = 12;
			this->DroidComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::DroidComboBox_SelectedIndexChanged);
			// 
			// RArmorComboBox
			// 
			this->RArmorComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->RArmorComboBox->DropDownWidth = 200;
			this->RArmorComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RArmorComboBox->FormattingEnabled = true;
			this->RArmorComboBox->Location = System::Drawing::Point(17, 123);
			this->RArmorComboBox->Name = L"RArmorComboBox";
			this->RArmorComboBox->Size = System::Drawing::Size(138, 21);
			this->RArmorComboBox->TabIndex = 11;
			this->RArmorComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::RArmorComboBox_SelectedIndexChanged);
			// 
			// FArmorComboBox
			// 
			this->FArmorComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->FArmorComboBox->DropDownWidth = 200;
			this->FArmorComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FArmorComboBox->FormattingEnabled = true;
			this->FArmorComboBox->Location = System::Drawing::Point(17, 40);
			this->FArmorComboBox->Name = L"FArmorComboBox";
			this->FArmorComboBox->Size = System::Drawing::Size(138, 21);
			this->FArmorComboBox->TabIndex = 10;
			this->FArmorComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::FArmorComboBox_SelectedIndexChanged);
			// 
			// SheildComboBox
			// 
			this->SheildComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->SheildComboBox->DropDownWidth = 200;
			this->SheildComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildComboBox->FormattingEnabled = true;
			this->SheildComboBox->Location = System::Drawing::Point(17, 123);
			this->SheildComboBox->Name = L"SheildComboBox";
			this->SheildComboBox->Size = System::Drawing::Size(138, 21);
			this->SheildComboBox->TabIndex = 9;
			this->SheildComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::SheildComboBox_SelectedIndexChanged);
			// 
			// BoosterComboBox
			// 
			this->BoosterComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->BoosterComboBox->DropDownWidth = 200;
			this->BoosterComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterComboBox->FormattingEnabled = true;
			this->BoosterComboBox->Location = System::Drawing::Point(17, 123);
			this->BoosterComboBox->Name = L"BoosterComboBox";
			this->BoosterComboBox->Size = System::Drawing::Size(138, 21);
			this->BoosterComboBox->TabIndex = 8;
			this->BoosterComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::BoosterComboBox_SelectedIndexChanged);
			// 
			// EngineComboBox
			// 
			this->EngineComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->EngineComboBox->DropDownWidth = 200;
			this->EngineComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineComboBox->FormattingEnabled = true;
			this->EngineComboBox->Location = System::Drawing::Point(17, 123);
			this->EngineComboBox->Name = L"EngineComboBox";
			this->EngineComboBox->Size = System::Drawing::Size(138, 21);
			this->EngineComboBox->TabIndex = 7;
			this->EngineComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::EngineComboBox_SelectedIndexChanged);
			// 
			// Weapon4ComboBox
			// 
			this->Weapon4ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Weapon4ComboBox->DropDownWidth = 200;
			this->Weapon4ComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon4ComboBox->FormattingEnabled = true;
			this->Weapon4ComboBox->Location = System::Drawing::Point(17, 123);
			this->Weapon4ComboBox->Name = L"Weapon4ComboBox";
			this->Weapon4ComboBox->Size = System::Drawing::Size(138, 21);
			this->Weapon4ComboBox->TabIndex = 20;
			this->Weapon4ComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::Weapon4ComboBox_SelectedIndexChanged);
			// 
			// Weapon3ComboBox
			// 
			this->Weapon3ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Weapon3ComboBox->DropDownWidth = 200;
			this->Weapon3ComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Weapon3ComboBox->FormattingEnabled = true;
			this->Weapon3ComboBox->Location = System::Drawing::Point(17, 123);
			this->Weapon3ComboBox->Name = L"Weapon3ComboBox";
			this->Weapon3ComboBox->Size = System::Drawing::Size(138, 21);
			this->Weapon3ComboBox->TabIndex = 19;
			this->Weapon3ComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::Weapon3ComboBox_SelectedIndexChanged);
			// 
			// CountermeasuresComboBox
			// 
			this->CountermeasuresComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CountermeasuresComboBox->DropDownWidth = 200;
			this->CountermeasuresComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CountermeasuresComboBox->FormattingEnabled = true;
			this->CountermeasuresComboBox->Location = System::Drawing::Point(17, 123);
			this->CountermeasuresComboBox->Name = L"CountermeasuresComboBox";
			this->CountermeasuresComboBox->Size = System::Drawing::Size(138, 21);
			this->CountermeasuresComboBox->TabIndex = 21;
			this->CountermeasuresComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::CountermeasuresComboBox_SelectedIndexChanged);
			// 
			// ShipMassUsedValueLabel
			// 
			this->ShipMassUsedValueLabel->AutoSize = true;
			this->ShipMassUsedValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->ShipMassUsedValueLabel->Location = System::Drawing::Point(131, 81);
			this->ShipMassUsedValueLabel->Name = L"ShipMassUsedValueLabel";
			this->ShipMassUsedValueLabel->Size = System::Drawing::Size(29, 16);
			this->ShipMassUsedValueLabel->TabIndex = 308;
			this->ShipMassUsedValueLabel->Text = L"0.0";
			// 
			// LeftoverMassUsedValueLabel
			// 
			this->LeftoverMassUsedValueLabel->AutoSize = true;
			this->LeftoverMassUsedValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->LeftoverMassUsedValueLabel->Location = System::Drawing::Point(131, 97);
			this->LeftoverMassUsedValueLabel->Name = L"LeftoverMassUsedValueLabel";
			this->LeftoverMassUsedValueLabel->Size = System::Drawing::Size(29, 16);
			this->LeftoverMassUsedValueLabel->TabIndex = 309;
			this->LeftoverMassUsedValueLabel->Text = L"0.0";
			// 
			// ShipNameValueLabel
			// 
			this->ShipNameValueLabel->AutoSize = true;
			this->ShipNameValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->ShipNameValueLabel->Location = System::Drawing::Point(100, 7);
			this->ShipNameValueLabel->Name = L"ShipNameValueLabel";
			this->ShipNameValueLabel->Size = System::Drawing::Size(117, 16);
			this->ShipNameValueLabel->TabIndex = 310;
			this->ShipNameValueLabel->Text = L"No ship created.";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"xml files|*.xml";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"xml files|*.xml";
			// 
			// TotalDrainValueLabel
			// 
			this->TotalDrainValueLabel->AutoSize = true;
			this->TotalDrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->TotalDrainValueLabel->Location = System::Drawing::Point(131, 113);
			this->TotalDrainValueLabel->Name = L"TotalDrainValueLabel";
			this->TotalDrainValueLabel->Size = System::Drawing::Size(29, 16);
			this->TotalDrainValueLabel->TabIndex = 312;
			this->TotalDrainValueLabel->Text = L"0.0";
			// 
			// TotalDrainLabel
			// 
			this->TotalDrainLabel->AutoSize = true;
			this->TotalDrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->TotalDrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TotalDrainLabel->Location = System::Drawing::Point(4, 113);
			this->TotalDrainLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->TotalDrainLabel->Name = L"TotalDrainLabel";
			this->TotalDrainLabel->Size = System::Drawing::Size(86, 16);
			this->TotalDrainLabel->TabIndex = 311;
			this->TotalDrainLabel->Text = L"Total Drain:";
			// 
			// TotalShipMassValueLabel
			// 
			this->TotalShipMassValueLabel->AutoSize = true;
			this->TotalShipMassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->TotalShipMassValueLabel->Location = System::Drawing::Point(131, 66);
			this->TotalShipMassValueLabel->Name = L"TotalShipMassValueLabel";
			this->TotalShipMassValueLabel->Size = System::Drawing::Size(29, 16);
			this->TotalShipMassValueLabel->TabIndex = 315;
			this->TotalShipMassValueLabel->Text = L"0.0";
			// 
			// EnginePanel
			// 
			this->EnginePanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"EnginePanel.BackgroundImage")));
			this->EnginePanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->EnginePanel->Controls->Add(this->E_ArmorLabel);
			this->EnginePanel->Controls->Add(this->E_MassLabel);
			this->EnginePanel->Controls->Add(this->E_DrainLabel);
			this->EnginePanel->Controls->Add(this->E_PitchLabel);
			this->EnginePanel->Controls->Add(this->E_YawLabel);
			this->EnginePanel->Controls->Add(this->E_RollLabel);
			this->EnginePanel->Controls->Add(this->E_SpeedLabel);
			this->EnginePanel->Controls->Add(this->E_ArmorValueLabel);
			this->EnginePanel->Controls->Add(this->E_MassValueLabel);
			this->EnginePanel->Controls->Add(this->EngineComboBox);
			this->EnginePanel->Controls->Add(this->E_DrainValueLabel);
			this->EnginePanel->Controls->Add(this->E_PitchValueLabel);
			this->EnginePanel->Controls->Add(this->E_YawValueLabel);
			this->EnginePanel->Controls->Add(this->E_RollValueLabel);
			this->EnginePanel->Controls->Add(this->E_SpeedValueLabel);
			this->EnginePanel->Location = System::Drawing::Point(175, 226);
			this->EnginePanel->Name = L"EnginePanel";
			this->EnginePanel->Size = System::Drawing::Size(173, 144);
			this->EnginePanel->TabIndex = 4;
			// 
			// BoosterPanel
			// 
			this->BoosterPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"BoosterPanel.BackgroundImage")));
			this->BoosterPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->BoosterPanel->Controls->Add(this->B_ArmorLabel);
			this->BoosterPanel->Controls->Add(this->B_MassLabel);
			this->BoosterPanel->Controls->Add(this->B_DrainLabel);
			this->BoosterPanel->Controls->Add(this->B_EnergyLabel);
			this->BoosterPanel->Controls->Add(this->B_RechargeLabel);
			this->BoosterPanel->Controls->Add(this->B_ConsumptionLabel);
			this->BoosterPanel->Controls->Add(this->B_AccelerationLabel);
			this->BoosterPanel->Controls->Add(this->B_SpeedLabel);
			this->BoosterPanel->Controls->Add(this->B_ArmorValueLabel);
			this->BoosterPanel->Controls->Add(this->B_MassValueLabel);
			this->BoosterPanel->Controls->Add(this->BoosterComboBox);
			this->BoosterPanel->Controls->Add(this->B_DrainValueLabel);
			this->BoosterPanel->Controls->Add(this->B_EnergyValueLabel);
			this->BoosterPanel->Controls->Add(this->B_RechargeValueLabel);
			this->BoosterPanel->Controls->Add(this->B_ConsumptionValueLabel);
			this->BoosterPanel->Controls->Add(this->B_AccelerationValueLabel);
			this->BoosterPanel->Controls->Add(this->B_SpeedValueLabel);
			this->BoosterPanel->Location = System::Drawing::Point(348, 226);
			this->BoosterPanel->Name = L"BoosterPanel";
			this->BoosterPanel->Size = System::Drawing::Size(173, 144);
			this->BoosterPanel->TabIndex = 5;
			// 
			// Weapon1Panel
			// 
			this->Weapon1Panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Weapon1Panel.BackgroundImage")));
			this->Weapon1Panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Weapon1Panel->Controls->Add(this->W1_ArmorLabel);
			this->Weapon1Panel->Controls->Add(this->W1_MassLabel);
			this->Weapon1Panel->Controls->Add(this->W1_DrainLabel);
			this->Weapon1Panel->Controls->Add(this->W1_MinDLabel);
			this->Weapon1Panel->Controls->Add(this->W1_MaxDLabel);
			this->Weapon1Panel->Controls->Add(this->W1_vsSLabel);
			this->Weapon1Panel->Controls->Add(this->W1_vsALabel);
			this->Weapon1Panel->Controls->Add(this->W1_EPSLabel);
			this->Weapon1Panel->Controls->Add(this->W1_RefireLabel);
			this->Weapon1Panel->Controls->Add(this->W1_ArmorValueLabel);
			this->Weapon1Panel->Controls->Add(this->W1_MassValueLabel);
			this->Weapon1Panel->Controls->Add(this->W1_DrainValueLabel);
			this->Weapon1Panel->Controls->Add(this->W1_MinDValueLabel);
			this->Weapon1Panel->Controls->Add(this->W1_MaxDValueLabel);
			this->Weapon1Panel->Controls->Add(this->W1_vsSValueLabel);
			this->Weapon1Panel->Controls->Add(this->W1_vsAValueLabel);
			this->Weapon1Panel->Controls->Add(this->W1_EPSValueLabel);
			this->Weapon1Panel->Controls->Add(this->W1_RefireValueLabel);
			this->Weapon1Panel->Controls->Add(this->Weapon1ComboBox);
			this->Weapon1Panel->Location = System::Drawing::Point(2, 557);
			this->Weapon1Panel->Name = L"Weapon1Panel";
			this->Weapon1Panel->Size = System::Drawing::Size(173, 144);
			this->Weapon1Panel->TabIndex = 13;
			// 
			// Weapon2Panel
			// 
			this->Weapon2Panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Weapon2Panel.BackgroundImage")));
			this->Weapon2Panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Weapon2Panel->Controls->Add(this->W2_ArmorLabel);
			this->Weapon2Panel->Controls->Add(this->W2_MassLabel);
			this->Weapon2Panel->Controls->Add(this->W2_DrainLabel);
			this->Weapon2Panel->Controls->Add(this->W2_MinDLabel);
			this->Weapon2Panel->Controls->Add(this->W2_MaxDLabel);
			this->Weapon2Panel->Controls->Add(this->W2_vsSLabel);
			this->Weapon2Panel->Controls->Add(this->W2_vsALabel);
			this->Weapon2Panel->Controls->Add(this->W2_EPSLabel);
			this->Weapon2Panel->Controls->Add(this->W2_RefireLabel);
			this->Weapon2Panel->Controls->Add(this->W2_ArmorValueLabel);
			this->Weapon2Panel->Controls->Add(this->W2_MassValueLabel);
			this->Weapon2Panel->Controls->Add(this->W2_DrainValueLabel);
			this->Weapon2Panel->Controls->Add(this->W2_MinDValueLabel);
			this->Weapon2Panel->Controls->Add(this->W2_MaxDValueLabel);
			this->Weapon2Panel->Controls->Add(this->W2_vsSValueLabel);
			this->Weapon2Panel->Controls->Add(this->W2_vsAValueLabel);
			this->Weapon2Panel->Controls->Add(this->W2_EPSValueLabel);
			this->Weapon2Panel->Controls->Add(this->W2_RefireValueLabel);
			this->Weapon2Panel->Controls->Add(this->Weapon2ComboBox);
			this->Weapon2Panel->Location = System::Drawing::Point(175, 557);
			this->Weapon2Panel->Name = L"Weapon2Panel";
			this->Weapon2Panel->Size = System::Drawing::Size(173, 144);
			this->Weapon2Panel->TabIndex = 14;
			// 
			// Weapon3Panel
			// 
			this->Weapon3Panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Weapon3Panel.BackgroundImage")));
			this->Weapon3Panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Weapon3Panel->Controls->Add(this->W3_ArmorLabel);
			this->Weapon3Panel->Controls->Add(this->W3_MassLabel);
			this->Weapon3Panel->Controls->Add(this->W3_DrainLabel);
			this->Weapon3Panel->Controls->Add(this->W3_MinDLabel);
			this->Weapon3Panel->Controls->Add(this->W3_MaxDLabel);
			this->Weapon3Panel->Controls->Add(this->W3_vsSLabel);
			this->Weapon3Panel->Controls->Add(this->W3_vsALabel);
			this->Weapon3Panel->Controls->Add(this->W3_EPSLabel);
			this->Weapon3Panel->Controls->Add(this->W3_RefireLabel);
			this->Weapon3Panel->Controls->Add(this->W3_ArmorValueLabel);
			this->Weapon3Panel->Controls->Add(this->W3_MassValueLabel);
			this->Weapon3Panel->Controls->Add(this->W3_DrainValueLabel);
			this->Weapon3Panel->Controls->Add(this->Weapon3ComboBox);
			this->Weapon3Panel->Controls->Add(this->W3_MinDValueLabel);
			this->Weapon3Panel->Controls->Add(this->W3_MaxDValueLabel);
			this->Weapon3Panel->Controls->Add(this->W3_vsSValueLabel);
			this->Weapon3Panel->Controls->Add(this->W3_vsAValueLabel);
			this->Weapon3Panel->Controls->Add(this->W3_EPSValueLabel);
			this->Weapon3Panel->Controls->Add(this->W3_RefireValueLabel);
			this->Weapon3Panel->Location = System::Drawing::Point(348, 557);
			this->Weapon3Panel->Name = L"Weapon3Panel";
			this->Weapon3Panel->Size = System::Drawing::Size(173, 144);
			this->Weapon3Panel->TabIndex = 15;
			// 
			// Weapon4Panel
			// 
			this->Weapon4Panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Weapon4Panel.BackgroundImage")));
			this->Weapon4Panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Weapon4Panel->Controls->Add(this->W4_ArmorLabel);
			this->Weapon4Panel->Controls->Add(this->W4_MassLabel);
			this->Weapon4Panel->Controls->Add(this->W4_DrainLabel);
			this->Weapon4Panel->Controls->Add(this->W4_MinDLabel);
			this->Weapon4Panel->Controls->Add(this->W4_MaxDLabel);
			this->Weapon4Panel->Controls->Add(this->W4_vsSLabel);
			this->Weapon4Panel->Controls->Add(this->W4_vsALabel);
			this->Weapon4Panel->Controls->Add(this->W4_EPSLabel);
			this->Weapon4Panel->Controls->Add(this->W4_RefireLabel);
			this->Weapon4Panel->Controls->Add(this->W4_ArmorValueLabel);
			this->Weapon4Panel->Controls->Add(this->W4_MassValueLabel);
			this->Weapon4Panel->Controls->Add(this->W4_DrainValueLabel);
			this->Weapon4Panel->Controls->Add(this->Weapon4ComboBox);
			this->Weapon4Panel->Controls->Add(this->W4_MinDValueLabel);
			this->Weapon4Panel->Controls->Add(this->W4_MaxDValueLabel);
			this->Weapon4Panel->Controls->Add(this->W4_vsSValueLabel);
			this->Weapon4Panel->Controls->Add(this->W4_vsAValueLabel);
			this->Weapon4Panel->Controls->Add(this->W4_EPSValueLabel);
			this->Weapon4Panel->Controls->Add(this->W4_RefireValueLabel);
			this->Weapon4Panel->Location = System::Drawing::Point(521, 557);
			this->Weapon4Panel->Name = L"Weapon4Panel";
			this->Weapon4Panel->Size = System::Drawing::Size(173, 144);
			this->Weapon4Panel->TabIndex = 16;
			// 
			// CapacitorPanel
			// 
			this->CapacitorPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"CapacitorPanel.BackgroundImage")));
			this->CapacitorPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->CapacitorPanel->Controls->Add(this->C_ArmorLabel);
			this->CapacitorPanel->Controls->Add(this->C_MassLabel);
			this->CapacitorPanel->Controls->Add(this->C_DrainLabel);
			this->CapacitorPanel->Controls->Add(this->C_EnergyLabel);
			this->CapacitorPanel->Controls->Add(this->C_RechargeLabel);
			this->CapacitorPanel->Controls->Add(this->C_ArmorValueLabel);
			this->CapacitorPanel->Controls->Add(this->C_MassValueLabel);
			this->CapacitorPanel->Controls->Add(this->C_DrainValueLabel);
			this->CapacitorPanel->Controls->Add(this->C_EnergyValueLabel);
			this->CapacitorPanel->Controls->Add(this->C_RechargeValueLabel);
			this->CapacitorPanel->Controls->Add(this->CapacitorComboBox);
			this->CapacitorPanel->Location = System::Drawing::Point(175, 389);
			this->CapacitorPanel->Name = L"CapacitorPanel";
			this->CapacitorPanel->Size = System::Drawing::Size(173, 144);
			this->CapacitorPanel->TabIndex = 9;
			// 
			// Ordinance1Panel
			// 
			this->Ordinance1Panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Ordinance1Panel.BackgroundImage")));
			this->Ordinance1Panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Ordinance1Panel->Controls->Add(this->O1_ArmorLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_MassLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_DrainLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_MinDLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_MaxDLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_vsSLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_vsALabel);
			this->Ordinance1Panel->Controls->Add(this->O1_AmmoLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_ArmorValueLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_MassValueLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_DrainValueLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_MinDValueLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_MaxDValueLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_vsSValueLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_vsAValueLabel);
			this->Ordinance1Panel->Controls->Add(this->O1_AmmoValueLabel);
			this->Ordinance1Panel->Controls->Add(this->Ordinance1ComboBox);
			this->Ordinance1Panel->Location = System::Drawing::Point(348, 389);
			this->Ordinance1Panel->Name = L"Ordinance1Panel";
			this->Ordinance1Panel->Size = System::Drawing::Size(173, 144);
			this->Ordinance1Panel->TabIndex = 10;
			// 
			// Ordinance2Panel
			// 
			this->Ordinance2Panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Ordinance2Panel.BackgroundImage")));
			this->Ordinance2Panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Ordinance2Panel->Controls->Add(this->O2_ArmorLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_MassLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_DrainLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_MinDLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_MaxDLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_vsSLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_vsALabel);
			this->Ordinance2Panel->Controls->Add(this->O2_AmmoLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_ArmorValueLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_MassValueLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_DrainValueLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_MinDValueLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_MaxDValueLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_vsSValueLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_vsAValueLabel);
			this->Ordinance2Panel->Controls->Add(this->O2_AmmoValueLabel);
			this->Ordinance2Panel->Controls->Add(this->Ordinance2ComboBox);
			this->Ordinance2Panel->Location = System::Drawing::Point(521, 389);
			this->Ordinance2Panel->Name = L"Ordinance2Panel";
			this->Ordinance2Panel->Size = System::Drawing::Size(173, 144);
			this->Ordinance2Panel->TabIndex = 11;
			// 
			// O3_MinDValueLabel
			// 
			this->O3_MinDValueLabel->AutoSize = true;
			this->O3_MinDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_MinDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_MinDValueLabel->Location = System::Drawing::Point(91, 39);
			this->O3_MinDValueLabel->Name = L"O3_MinDValueLabel";
			this->O3_MinDValueLabel->Size = System::Drawing::Size(15, 13);
			this->O3_MinDValueLabel->TabIndex = 275;
			this->O3_MinDValueLabel->Text = L"0";
			// 
			// O3_AmmoValueLabel
			// 
			this->O3_AmmoValueLabel->AutoSize = true;
			this->O3_AmmoValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_AmmoValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_AmmoValueLabel->Location = System::Drawing::Point(91, 91);
			this->O3_AmmoValueLabel->Name = L"O3_AmmoValueLabel";
			this->O3_AmmoValueLabel->Size = System::Drawing::Size(15, 13);
			this->O3_AmmoValueLabel->TabIndex = 265;
			this->O3_AmmoValueLabel->Text = L"0";
			// 
			// O3_vsAValueLabel
			// 
			this->O3_vsAValueLabel->AutoSize = true;
			this->O3_vsAValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_vsAValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_vsAValueLabel->Location = System::Drawing::Point(91, 78);
			this->O3_vsAValueLabel->Name = L"O3_vsAValueLabel";
			this->O3_vsAValueLabel->Size = System::Drawing::Size(15, 13);
			this->O3_vsAValueLabel->TabIndex = 264;
			this->O3_vsAValueLabel->Text = L"0";
			// 
			// O3_vsSValueLabel
			// 
			this->O3_vsSValueLabel->AutoSize = true;
			this->O3_vsSValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_vsSValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_vsSValueLabel->Location = System::Drawing::Point(91, 65);
			this->O3_vsSValueLabel->Name = L"O3_vsSValueLabel";
			this->O3_vsSValueLabel->Size = System::Drawing::Size(15, 13);
			this->O3_vsSValueLabel->TabIndex = 263;
			this->O3_vsSValueLabel->Text = L"0";
			// 
			// O3_MaxDValueLabel
			// 
			this->O3_MaxDValueLabel->AutoSize = true;
			this->O3_MaxDValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_MaxDValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_MaxDValueLabel->Location = System::Drawing::Point(91, 52);
			this->O3_MaxDValueLabel->Name = L"O3_MaxDValueLabel";
			this->O3_MaxDValueLabel->Size = System::Drawing::Size(15, 13);
			this->O3_MaxDValueLabel->TabIndex = 262;
			this->O3_MaxDValueLabel->Text = L"0";
			// 
			// O3_DrainValueLabel
			// 
			this->O3_DrainValueLabel->AutoSize = true;
			this->O3_DrainValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_DrainValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_DrainValueLabel->Location = System::Drawing::Point(91, 13);
			this->O3_DrainValueLabel->Name = L"O3_DrainValueLabel";
			this->O3_DrainValueLabel->Size = System::Drawing::Size(15, 13);
			this->O3_DrainValueLabel->TabIndex = 260;
			this->O3_DrainValueLabel->Text = L"0";
			// 
			// O3_MassValueLabel
			// 
			this->O3_MassValueLabel->AutoSize = true;
			this->O3_MassValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_MassValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_MassValueLabel->Location = System::Drawing::Point(91, 26);
			this->O3_MassValueLabel->Name = L"O3_MassValueLabel";
			this->O3_MassValueLabel->Size = System::Drawing::Size(15, 13);
			this->O3_MassValueLabel->TabIndex = 259;
			this->O3_MassValueLabel->Text = L"0";
			// 
			// O3_ArmorValueLabel
			// 
			this->O3_ArmorValueLabel->AutoSize = true;
			this->O3_ArmorValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_ArmorValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_ArmorValueLabel->Location = System::Drawing::Point(91, 0);
			this->O3_ArmorValueLabel->Name = L"O3_ArmorValueLabel";
			this->O3_ArmorValueLabel->Size = System::Drawing::Size(15, 13);
			this->O3_ArmorValueLabel->TabIndex = 258;
			this->O3_ArmorValueLabel->Text = L"0";
			// 
			// O3_AmmoLabel
			// 
			this->O3_AmmoLabel->AutoSize = true;
			this->O3_AmmoLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_AmmoLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_AmmoLabel->Location = System::Drawing::Point(16, 91);
			this->O3_AmmoLabel->Name = L"O3_AmmoLabel";
			this->O3_AmmoLabel->Size = System::Drawing::Size(52, 13);
			this->O3_AmmoLabel->TabIndex = 257;
			this->O3_AmmoLabel->Text = L"Ammo:";
			// 
			// O3_vsALabel
			// 
			this->O3_vsALabel->AutoSize = true;
			this->O3_vsALabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_vsALabel->Location = System::Drawing::Point(16, 78);
			this->O3_vsALabel->Name = L"O3_vsALabel";
			this->O3_vsALabel->Size = System::Drawing::Size(71, 13);
			this->O3_vsALabel->TabIndex = 256;
			this->O3_vsALabel->Text = L"vs Armor:";
			// 
			// O3_vsSLabel
			// 
			this->O3_vsSLabel->AutoSize = true;
			this->O3_vsSLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_vsSLabel->Location = System::Drawing::Point(16, 65);
			this->O3_vsSLabel->Name = L"O3_vsSLabel";
			this->O3_vsSLabel->Size = System::Drawing::Size(77, 13);
			this->O3_vsSLabel->TabIndex = 255;
			this->O3_vsSLabel->Text = L"vs Shields:";
			// 
			// O3_MaxDLabel
			// 
			this->O3_MaxDLabel->AutoSize = true;
			this->O3_MaxDLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_MaxDLabel->Location = System::Drawing::Point(16, 52);
			this->O3_MaxDLabel->Name = L"O3_MaxDLabel";
			this->O3_MaxDLabel->Size = System::Drawing::Size(70, 13);
			this->O3_MaxDLabel->TabIndex = 254;
			this->O3_MaxDLabel->Text = L"Max Dmg:";
			// 
			// O3_MinDLabel
			// 
			this->O3_MinDLabel->AutoSize = true;
			this->O3_MinDLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_MinDLabel->Location = System::Drawing::Point(16, 39);
			this->O3_MinDLabel->Name = L"O3_MinDLabel";
			this->O3_MinDLabel->Size = System::Drawing::Size(66, 13);
			this->O3_MinDLabel->TabIndex = 253;
			this->O3_MinDLabel->Text = L"Min Dmg:";
			// 
			// O3_DrianLabel
			// 
			this->O3_DrianLabel->AutoSize = true;
			this->O3_DrianLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_DrianLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_DrianLabel->Location = System::Drawing::Point(16, 13);
			this->O3_DrianLabel->Name = L"O3_DrianLabel";
			this->O3_DrianLabel->Size = System::Drawing::Size(46, 13);
			this->O3_DrianLabel->TabIndex = 252;
			this->O3_DrianLabel->Text = L"Drain:";
			// 
			// O3_MassLabel
			// 
			this->O3_MassLabel->AutoSize = true;
			this->O3_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_MassLabel->Location = System::Drawing::Point(16, 26);
			this->O3_MassLabel->Name = L"O3_MassLabel";
			this->O3_MassLabel->Size = System::Drawing::Size(43, 13);
			this->O3_MassLabel->TabIndex = 251;
			this->O3_MassLabel->Text = L"Mass:";
			// 
			// O3_ArmorLabel
			// 
			this->O3_ArmorLabel->AutoSize = true;
			this->O3_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->O3_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->O3_ArmorLabel->Location = System::Drawing::Point(16, 0);
			this->O3_ArmorLabel->Name = L"O3_ArmorLabel";
			this->O3_ArmorLabel->Size = System::Drawing::Size(52, 13);
			this->O3_ArmorLabel->TabIndex = 250;
			this->O3_ArmorLabel->Text = L"Armor:";
			// 
			// Ordinance3Panel
			// 
			this->Ordinance3Panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Ordinance3Panel.BackgroundImage")));
			this->Ordinance3Panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Ordinance3Panel->Controls->Add(this->O3_ArmorLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_MassLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_DrianLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_MinDLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_MaxDLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_vsSLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_vsALabel);
			this->Ordinance3Panel->Controls->Add(this->O3_AmmoLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_ArmorValueLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_MassValueLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_DrainValueLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_MaxDValueLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_vsSValueLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_vsAValueLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_AmmoValueLabel);
			this->Ordinance3Panel->Controls->Add(this->O3_MinDValueLabel);
			this->Ordinance3Panel->Controls->Add(this->Ordinance3ComboBox);
			this->Ordinance3Panel->Location = System::Drawing::Point(694, 389);
			this->Ordinance3Panel->Name = L"Ordinance3Panel";
			this->Ordinance3Panel->Size = System::Drawing::Size(173, 144);
			this->Ordinance3Panel->TabIndex = 12;
			// 
			// ArmorPanel
			// 
			this->ArmorPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ArmorPanel.BackgroundImage")));
			this->ArmorPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ArmorPanel->Controls->Add(this->FA_ArmorLabel);
			this->ArmorPanel->Controls->Add(this->FA_MassLabel);
			this->ArmorPanel->Controls->Add(this->FA_MassValueLabel);
			this->ArmorPanel->Controls->Add(this->FA_ArmorValueLabel);
			this->ArmorPanel->Controls->Add(this->FArmorComboBox);
			this->ArmorPanel->Controls->Add(this->RA_ArmorLabel);
			this->ArmorPanel->Controls->Add(this->RA_MassLabel);
			this->ArmorPanel->Controls->Add(this->RA_MassValueLabel);
			this->ArmorPanel->Controls->Add(this->RA_ArmorValueLabel);
			this->ArmorPanel->Controls->Add(this->RArmorComboBox);
			this->ArmorPanel->Location = System::Drawing::Point(694, 226);
			this->ArmorPanel->Name = L"ArmorPanel";
			this->ArmorPanel->Size = System::Drawing::Size(173, 144);
			this->ArmorPanel->TabIndex = 7;
			// 
			// SheildPanel
			// 
			this->SheildPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"SheildPanel.BackgroundImage")));
			this->SheildPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->SheildPanel->Controls->Add(this->S_ArmorLabel);
			this->SheildPanel->Controls->Add(this->S_MassLabel);
			this->SheildPanel->Controls->Add(this->S_DrainLabel);
			this->SheildPanel->Controls->Add(this->S_FrontHPLabel);
			this->SheildPanel->Controls->Add(this->S_BackHPLabel);
			this->SheildPanel->Controls->Add(this->S_RechargeLabel);
			this->SheildPanel->Controls->Add(this->S_AdjustmentLabel);
			this->SheildPanel->Controls->Add(this->S_ArmorValueLabel);
			this->SheildPanel->Controls->Add(this->S_MassValueLabel);
			this->SheildPanel->Controls->Add(this->S_DrainValueLabel);
			this->SheildPanel->Controls->Add(this->S_FrontHPValueLabel);
			this->SheildPanel->Controls->Add(this->S_BackHPValueLabel);
			this->SheildPanel->Controls->Add(this->S_RechargeValueLabel);
			this->SheildPanel->Controls->Add(this->S_AdjustmentValueLabel);
			this->SheildPanel->Controls->Add(this->SheildComboBox);
			this->SheildPanel->Location = System::Drawing::Point(521, 226);
			this->SheildPanel->Name = L"SheildPanel";
			this->SheildPanel->Size = System::Drawing::Size(173, 144);
			this->SheildPanel->TabIndex = 6;
			// 
			// CountermeasuresPanel
			// 
			this->CountermeasuresPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"CountermeasuresPanel.BackgroundImage")));
			this->CountermeasuresPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->CountermeasuresPanel->Controls->Add(this->CM_ArmorLabel);
			this->CountermeasuresPanel->Controls->Add(this->CM_MassLabel);
			this->CountermeasuresPanel->Controls->Add(this->CM_DrainLabel);
			this->CountermeasuresPanel->Controls->Add(this->CM_ArmorValueLabel);
			this->CountermeasuresPanel->Controls->Add(this->CM_MassValueLabel);
			this->CountermeasuresPanel->Controls->Add(this->CM_DrainValueLabel);
			this->CountermeasuresPanel->Controls->Add(this->CountermeasuresComboBox);
			this->CountermeasuresPanel->Location = System::Drawing::Point(694, 557);
			this->CountermeasuresPanel->Name = L"CountermeasuresPanel";
			this->CountermeasuresPanel->Size = System::Drawing::Size(173, 144);
			this->CountermeasuresPanel->TabIndex = 17;
			// 
			// ReactorPanel
			// 
			this->ReactorPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ReactorPanel.BackgroundImage")));
			this->ReactorPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ReactorPanel->Controls->Add(this->R_ArmorLabel);
			this->ReactorPanel->Controls->Add(this->R_MassLabel);
			this->ReactorPanel->Controls->Add(this->R_GenerationLabel);
			this->ReactorPanel->Controls->Add(this->R_ArmorValueLabel);
			this->ReactorPanel->Controls->Add(this->R_MassValueLabel);
			this->ReactorPanel->Controls->Add(this->R_GenerationValueLabel);
			this->ReactorPanel->Controls->Add(this->ReactorComboBox);
			this->ReactorPanel->Location = System::Drawing::Point(2, 226);
			this->ReactorPanel->Name = L"ReactorPanel";
			this->ReactorPanel->Size = System::Drawing::Size(173, 144);
			this->ReactorPanel->TabIndex = 3;
			// 
			// DroidPanel
			// 
			this->DroidPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"DroidPanel.BackgroundImage")));
			this->DroidPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->DroidPanel->Controls->Add(this->D_ArmorLabel);
			this->DroidPanel->Controls->Add(this->D_MassLabel);
			this->DroidPanel->Controls->Add(this->D_DrainLabel);
			this->DroidPanel->Controls->Add(this->D_SpeedLabel);
			this->DroidPanel->Controls->Add(this->D_ArmorValueLabel);
			this->DroidPanel->Controls->Add(this->D_MassValueLabel);
			this->DroidPanel->Controls->Add(this->D_DrainValueLabel);
			this->DroidPanel->Controls->Add(this->D_SpeedValueLabel);
			this->DroidPanel->Controls->Add(this->DroidComboBox);
			this->DroidPanel->Location = System::Drawing::Point(1, 389);
			this->DroidPanel->Name = L"DroidPanel";
			this->DroidPanel->Size = System::Drawing::Size(173, 144);
			this->DroidPanel->TabIndex = 8;
			// 
			// ShipInfoPanel
			// 
			this->ShipInfoPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ShipInfoPanel.BackgroundImage")));
			this->ShipInfoPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ShipInfoPanel->Controls->Add(this->ShipNameLabel);
			this->ShipInfoPanel->Controls->Add(this->TotalMassLabel);
			this->ShipInfoPanel->Controls->Add(this->ShipMassUsedLabel);
			this->ShipInfoPanel->Controls->Add(this->LeftoverMassLabel);
			this->ShipInfoPanel->Controls->Add(this->ShipChassisLabel);
			this->ShipInfoPanel->Controls->Add(this->ShipChassisComboBox);
			this->ShipInfoPanel->Controls->Add(this->ShipMassUsedValueLabel);
			this->ShipInfoPanel->Controls->Add(this->LeftoverMassUsedValueLabel);
			this->ShipInfoPanel->Controls->Add(this->ShipNameValueLabel);
			this->ShipInfoPanel->Controls->Add(this->TotalDrainLabel);
			this->ShipInfoPanel->Controls->Add(this->TotalDrainValueLabel);
			this->ShipInfoPanel->Controls->Add(this->TotalShipMassValueLabel);
			this->ShipInfoPanel->Location = System::Drawing::Point(19, 45);
			this->ShipInfoPanel->Name = L"ShipInfoPanel";
			this->ShipInfoPanel->Size = System::Drawing::Size(228, 137);
			this->ShipInfoPanel->TabIndex = 1;
			// 
			// OverloadPanel
			// 
			this->OverloadPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"OverloadPanel.BackgroundImage")));
			this->OverloadPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->OverloadPanel->Controls->Add(this->OverloadsLabel);
			this->OverloadPanel->Controls->Add(this->ReactorOverloadLabel);
			this->OverloadPanel->Controls->Add(this->EngineOverloadLabel);
			this->OverloadPanel->Controls->Add(this->WeaponOverloadLabel);
			this->OverloadPanel->Controls->Add(this->CapacitorOverloadLabel);
			this->OverloadPanel->Controls->Add(this->ReactorOverloadComboBox);
			this->OverloadPanel->Controls->Add(this->WeaponOverloadComboBox);
			this->OverloadPanel->Controls->Add(this->EngineOverloadComboBox);
			this->OverloadPanel->Controls->Add(this->CapacitorOverloadComboBox);
			this->OverloadPanel->Location = System::Drawing::Point(277, 45);
			this->OverloadPanel->Name = L"OverloadPanel";
			this->OverloadPanel->Size = System::Drawing::Size(157, 137);
			this->OverloadPanel->TabIndex = 2;
			// 
			// ShipStatusPanel
			// 
			this->ShipStatusPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ShipStatusPanel.BackgroundImage")));
			this->ShipStatusPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ShipStatusPanel->Controls->Add(this->ShipStatusLabel);
			this->ShipStatusPanel->Controls->Add(this->ReactorStatusLabel);
			this->ShipStatusPanel->Controls->Add(this->EngineStatusLabel);
			this->ShipStatusPanel->Controls->Add(this->SheildStatusLabel);
			this->ShipStatusPanel->Controls->Add(this->FArmorStatusLabel);
			this->ShipStatusPanel->Controls->Add(this->RArmorLabel);
			this->ShipStatusPanel->Controls->Add(this->CapacitorStatusLabel);
			this->ShipStatusPanel->Controls->Add(this->BoosterStatusLabel);
			this->ShipStatusPanel->Controls->Add(this->DriodStatusLabel);
			this->ShipStatusPanel->Controls->Add(this->Weapon1StatusLabel);
			this->ShipStatusPanel->Controls->Add(this->Weapon2StatusLabel);
			this->ShipStatusPanel->Controls->Add(this->Weapon3StatusLabel);
			this->ShipStatusPanel->Controls->Add(this->Weapon4StatusLabel);
			this->ShipStatusPanel->Controls->Add(this->Ordinance1StatusLabel);
			this->ShipStatusPanel->Controls->Add(this->Ordinance2StatusLabel);
			this->ShipStatusPanel->Controls->Add(this->Ordinance3StatusLabel);
			this->ShipStatusPanel->Controls->Add(this->CountermeasuresStatusLabel);
			this->ShipStatusPanel->Controls->Add(this->ReactorGBLabel);
			this->ShipStatusPanel->Controls->Add(this->EngineGBLabel);
			this->ShipStatusPanel->Controls->Add(this->SheildGBLabel);
			this->ShipStatusPanel->Controls->Add(this->FArmorGBLabel);
			this->ShipStatusPanel->Controls->Add(this->RArmorGBLabel);
			this->ShipStatusPanel->Controls->Add(this->CapacitorGBLabel);
			this->ShipStatusPanel->Controls->Add(this->BoosterGBLabel);
			this->ShipStatusPanel->Controls->Add(this->DroidGBLabel);
			this->ShipStatusPanel->Controls->Add(this->Weapon1GBLabel);
			this->ShipStatusPanel->Controls->Add(this->Weapon2GBLabel);
			this->ShipStatusPanel->Controls->Add(this->Weapon3GBLabel);
			this->ShipStatusPanel->Controls->Add(this->Weapon4GBLabel);
			this->ShipStatusPanel->Controls->Add(this->OrdinanceGBLabel);
			this->ShipStatusPanel->Controls->Add(this->Ordinance2GBLabel);
			this->ShipStatusPanel->Controls->Add(this->Ordinance3GBLabel);
			this->ShipStatusPanel->Controls->Add(this->CountermeasuresGBLabel);
			this->ShipStatusPanel->Location = System::Drawing::Point(455, 45);
			this->ShipStatusPanel->Name = L"ShipStatusPanel";
			this->ShipStatusPanel->Size = System::Drawing::Size(400, 137);
			this->ShipStatusPanel->TabIndex = 330;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(869, 714);
			this->Controls->Add(this->SheildPanel);
			this->Controls->Add(this->ShipStatusPanel);
			this->Controls->Add(this->OverloadPanel);
			this->Controls->Add(this->ShipInfoPanel);
			this->Controls->Add(this->DroidPanel);
			this->Controls->Add(this->ReactorPanel);
			this->Controls->Add(this->CountermeasuresPanel);
			this->Controls->Add(this->Ordinance3Panel);
			this->Controls->Add(this->Ordinance2Panel);
			this->Controls->Add(this->Ordinance1Panel);
			this->Controls->Add(this->CapacitorPanel);
			this->Controls->Add(this->Weapon2Panel);
			this->Controls->Add(this->Weapon3Panel);
			this->Controls->Add(this->Weapon4Panel);
			this->Controls->Add(this->Weapon1Panel);
			this->Controls->Add(this->BoosterPanel);
			this->Controls->Add(this->CountermeasuresCompLabel);
			this->Controls->Add(this->Weapon4CompLabel);
			this->Controls->Add(this->Weapon3CompLabel);
			this->Controls->Add(this->Weapon2CompLabel);
			this->Controls->Add(this->Weapon1CompLabel);
			this->Controls->Add(this->Ordinance3CompLabel);
			this->Controls->Add(this->Ordinance2CompLabel);
			this->Controls->Add(this->Ordinanace1CompLabel);
			this->Controls->Add(this->CapacitorCompLabel);
			this->Controls->Add(this->DroidCompLabel);
			this->Controls->Add(this->FArmorCompLabel);
			this->Controls->Add(this->SheildCompLabel);
			this->Controls->Add(this->BoosterCompLabel);
			this->Controls->Add(this->EngineCompLabel);
			this->Controls->Add(this->ReactorCompLabel);
			this->Controls->Add(this->ComponentsLabel);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->EnginePanel);
			this->Controls->Add(this->ArmorPanel);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ship Loadout Utility v 0.1 Beta";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->EnginePanel->ResumeLayout(false);
			this->EnginePanel->PerformLayout();
			this->BoosterPanel->ResumeLayout(false);
			this->BoosterPanel->PerformLayout();
			this->Weapon1Panel->ResumeLayout(false);
			this->Weapon1Panel->PerformLayout();
			this->Weapon2Panel->ResumeLayout(false);
			this->Weapon2Panel->PerformLayout();
			this->Weapon3Panel->ResumeLayout(false);
			this->Weapon3Panel->PerformLayout();
			this->Weapon4Panel->ResumeLayout(false);
			this->Weapon4Panel->PerformLayout();
			this->CapacitorPanel->ResumeLayout(false);
			this->CapacitorPanel->PerformLayout();
			this->Ordinance1Panel->ResumeLayout(false);
			this->Ordinance1Panel->PerformLayout();
			this->Ordinance2Panel->ResumeLayout(false);
			this->Ordinance2Panel->PerformLayout();
			this->Ordinance3Panel->ResumeLayout(false);
			this->Ordinance3Panel->PerformLayout();
			this->ArmorPanel->ResumeLayout(false);
			this->ArmorPanel->PerformLayout();
			this->SheildPanel->ResumeLayout(false);
			this->SheildPanel->PerformLayout();
			this->CountermeasuresPanel->ResumeLayout(false);
			this->CountermeasuresPanel->PerformLayout();
			this->ReactorPanel->ResumeLayout(false);
			this->ReactorPanel->PerformLayout();
			this->DroidPanel->ResumeLayout(false);
			this->DroidPanel->PerformLayout();
			this->ShipInfoPanel->ResumeLayout(false);
			this->ShipInfoPanel->PerformLayout();
			this->OverloadPanel->ResumeLayout(false);
			this->OverloadPanel->PerformLayout();
			this->ShipStatusPanel->ResumeLayout(false);
			this->ShipStatusPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		 ///
		 /// Functions
		 ///

		 /// Status functions update the componets "status" (Good or Disabled)
private: System::Void ReactorStatus(){
			 if (currentReactorMass != 0)
			 {
				 ReactorGBLabel->Text = "Good";
				 ReactorGBLabel->ForeColor = Color::Blue;
			 }
			 else
			 {
				 ReactorGBLabel->Text = "None Loaded";
				 ReactorGBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void EngineStatus(){
			 if (currentEngineOverloadedDrain != 0)
			 {
				 if (currentEngineOverloadedDrain > currentReactorOverloadedGeneration)
				 {
					 EngineGBLabel->Text = "Disabled";
					 EngineGBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 EngineGBLabel->Text = "Good";
					 EngineGBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 EngineGBLabel->Text = "None Loaded";
				 EngineGBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void SheildStatus(){
			 double additiveDrain = currentSheildDrain + currentEngineOverloadedDrain;

			 if (currentSheildDrain != 0)
			 {
				 if (additiveDrain > currentReactorOverloadedGeneration)
				 {
					 SheildGBLabel->Text = "Disabled";
					 SheildGBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 SheildGBLabel->Text = "Good";
					 SheildGBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 SheildGBLabel->Text = "None Loaded";
				 SheildGBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void FArmorStatus(){
			 if (currentFArmorMass != 0)
			 {
				 FArmorGBLabel->Text = "Good";
				 FArmorGBLabel->ForeColor = Color::Blue;
			 }
			 else
			 {
				 FArmorGBLabel->Text = "None Loaded";
				 FArmorGBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void RArmorStatus(){
			 if (currentRArmorMass != 0)
			 {
				 RArmorGBLabel->Text = "Good";
				 RArmorGBLabel->ForeColor = Color::Blue;
			 }
			 else
			 {
				 RArmorGBLabel->Text = "None Loaded";
				 RArmorGBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void CapacitorStatus(){
			 double additiveDrain = currentSheildDrain + currentEngineOverloadedDrain + currentCapacitorDrain;

			 if (currentCapacitorDrain != 0)
			 {
				 if (additiveDrain > currentReactorOverloadedGeneration)
				 {
					 CapacitorGBLabel->Text = "Disabled";
					 CapacitorGBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 CapacitorGBLabel->Text = "Good";
					 CapacitorGBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 CapacitorGBLabel->Text = "None Loaded";
				 CapacitorGBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void BoosterStatus(){
			 double additiveDrain = currentSheildDrain + currentEngineOverloadedDrain + currentCapacitorDrain
				 + currentBoosterDrain;

			 if (currentBoosterDrain != 0)
			 {
				 if (additiveDrain > currentReactorOverloadedGeneration)
				 {
					 BoosterGBLabel->Text = "Disabled";
					 BoosterGBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 BoosterGBLabel->Text = "Good";
					 BoosterGBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 BoosterGBLabel->Text = "None Loaded";
				 BoosterGBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void DroidStatus(){
			 double additiveDrain = currentSheildDrain + currentEngineOverloadedDrain + currentCapacitorDrain
				 + currentBoosterDrain + currentDroidDrain;

			 if (currentDroidDrain != 0)
			 {
				 if (additiveDrain > currentReactorOverloadedGeneration)
				 {
					 DroidGBLabel->Text = "Disabled";
					 DroidGBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 DroidGBLabel->Text = "Good";
					 DroidGBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 DroidGBLabel->Text = "None Loaded";
				 DroidGBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void Weapon1Status(){
			 double additiveDrain = currentSheildDrain + currentEngineOverloadedDrain + currentCapacitorDrain
				 + currentBoosterDrain + currentDroidDrain + currentWeapon1OverloadedDrain;

			 if (currentWeapon1OverloadedDrain != 0)
			 {
				 if (additiveDrain > currentReactorOverloadedGeneration)
				 {
					 Weapon1GBLabel->Text = "Disabled";
					 Weapon1GBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 Weapon1GBLabel->Text = "Good";
					 Weapon1GBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 Weapon1GBLabel->Text = "None Loaded";
				 Weapon1GBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void Weapon2Status(){
			 double additiveDrain = currentSheildDrain + currentEngineOverloadedDrain + currentCapacitorDrain
				 + currentBoosterDrain + currentDroidDrain + currentWeapon1OverloadedDrain
				 + currentWeapon2OverloadedDrain;

			 if (currentWeapon2OverloadedDrain != 0)
			 {
				 if (additiveDrain > currentReactorOverloadedGeneration)
				 {
					 Weapon2GBLabel->Text = "Disabled";
					 Weapon2GBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 Weapon2GBLabel->Text = "Good";
					 Weapon2GBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 Weapon2GBLabel->Text = "None Loaded";
				 Weapon2GBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void Weapon3Status(){
			 double additiveDrain = currentSheildDrain + currentEngineOverloadedDrain + currentCapacitorDrain
				 + currentBoosterDrain + currentDroidDrain + currentWeapon1OverloadedDrain
				 + currentWeapon2OverloadedDrain + currentWeapon3OverloadedDrain;

			 if (currentWeapon3OverloadedDrain != 0)
			 {
				 if (additiveDrain > currentReactorOverloadedGeneration)
				 {
					 Weapon3GBLabel->Text = "Disabled";
					 Weapon3GBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 Weapon3GBLabel->Text = "Good";
					 Weapon3GBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 Weapon3GBLabel->Text = "None Loaded";
				 Weapon3GBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void Weapon4Status(){
			 double additiveDrain = currentSheildDrain + currentEngineOverloadedDrain + currentCapacitorDrain
				 + currentBoosterDrain + currentDroidDrain + currentWeapon1OverloadedDrain
				 + currentWeapon2OverloadedDrain + currentWeapon3OverloadedDrain + currentWeapon4OverloadedDrain;

			 if (currentWeapon4OverloadedDrain != 0)
			 {
				 if (additiveDrain > currentReactorOverloadedGeneration)
				 {
					 Weapon4GBLabel->Text = "Disabled";
					 Weapon4GBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 Weapon4GBLabel->Text = "Good";
					 Weapon4GBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 Weapon4GBLabel->Text = "None Loaded";
				 Weapon4GBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void Ordinance1Status(){
			 double additiveDrain = currentSheildDrain + currentEngineOverloadedDrain + currentCapacitorDrain
				 + currentBoosterDrain + currentDroidDrain + currentWeapon1OverloadedDrain
				 + currentWeapon2OverloadedDrain + currentWeapon3OverloadedDrain + currentWeapon4OverloadedDrain
				 + currentOrdinance1OverloadedDrain;

			 if (currentOrdinance1OverloadedDrain != 0)
			 {
				 if (additiveDrain > currentReactorOverloadedGeneration)
				 {
					 OrdinanceGBLabel->Text = "Disabled";
					 OrdinanceGBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 OrdinanceGBLabel->Text = "Good";
					 OrdinanceGBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 OrdinanceGBLabel->Text = "None Loaded";
				 OrdinanceGBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void Ordinance2Status(){
			 double additiveDrain = currentSheildDrain + currentEngineOverloadedDrain + currentCapacitorDrain
				 + currentBoosterDrain + currentDroidDrain + currentWeapon1OverloadedDrain
				 + currentWeapon2OverloadedDrain + currentWeapon3OverloadedDrain + currentWeapon4OverloadedDrain
				 + currentOrdinance1OverloadedDrain + currentOrdinance2OverloadedDrain;

			 if (currentOrdinance2OverloadedDrain != 0)
			 {
				 if (additiveDrain > currentReactorOverloadedGeneration)
				 {
					 Ordinance2GBLabel->Text = "Disabled";
					 Ordinance2GBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 Ordinance2GBLabel->Text = "Good";
					 Ordinance2GBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 Ordinance2GBLabel->Text = "None Loaded";
				 Ordinance2GBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void Ordinance3Status(){
			 double additiveDrain = currentSheildDrain + currentEngineOverloadedDrain + currentCapacitorDrain
				 + currentBoosterDrain + currentDroidDrain + currentWeapon1OverloadedDrain
				 + currentWeapon2OverloadedDrain + currentWeapon3OverloadedDrain + currentWeapon4OverloadedDrain
				 + currentOrdinance1OverloadedDrain + currentOrdinance2OverloadedDrain + currentOrdinance3OverloadedDrain;

			 if (currentOrdinance3OverloadedDrain != 0)
			 {
				 if (additiveDrain > currentReactorOverloadedGeneration)
				 {
					 Ordinance3GBLabel->Text = "Disabled";
					 Ordinance3GBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 Ordinance3GBLabel->Text = "Good";
					 Ordinance3GBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 Ordinance3GBLabel->Text = "None Loaded";
				 Ordinance3GBLabel->ForeColor = Color::White;
			 }
		 }
private: System::Void ChaffStatus(){
			 double additiveDrain = currentSheildDrain + currentEngineOverloadedDrain + currentCapacitorDrain
				 + currentBoosterDrain + currentDroidDrain + currentWeapon1OverloadedDrain
				 + currentWeapon2OverloadedDrain + currentWeapon3OverloadedDrain + currentWeapon4OverloadedDrain
				 + currentOrdinance1OverloadedDrain + currentOrdinance2OverloadedDrain + currentOrdinance3OverloadedDrain
				 + currentChaffDrain;

			 if (currentChaffDrain != 0)
			 {
				 if (additiveDrain > currentReactorOverloadedGeneration)
				 {
					 CountermeasuresGBLabel->Text = "Disabled";
					 CountermeasuresGBLabel->ForeColor = Color::Red;
				 }
				 else
				 {
					 CountermeasuresGBLabel->Text = "Good";
					 CountermeasuresGBLabel->ForeColor = Color::Blue;
				 }
			 }
			 else
			 {
				 CountermeasuresGBLabel->Text = "None Loaded";
				 CountermeasuresGBLabel->ForeColor = Color::White;
			 }
		 }
		 /// Resets the form
private: System::Void Reset(){
			changesMade = true;

			currentReactorSelectedIndex = "";
			currentEngineSelectedIndex = "";
			currentBoosterSelectedIndex = "";
			currentSheildSelectedIndex = "";
			currentFArmorSelectedIndex = "";
			currentRArmorSelectedIndex = "";
			currentDroidSelectedIndex = "";
			currentCapacitorSelectedIndex = "";
			currentOrdinance1SelectedIndex = "";
			currentOrdinance2SelectedIndex = "";
			currentOrdinance3SelectedIndex = "";
			currentWeapon1SelectedIndex = "";
			currentWeapon2SelectedIndex = "";
			currentWeapon3SelectedIndex = "";
			currentWeapon4SelectedIndex = "";
			currentChaffSelectedIndex = "";

			currentMassUsed = 0;
			currentLeftoverMass = 0;
			currentDrainTotal = 0;
			
			currentCompMass = 0;

			currentReactorMass = 0;
			currentEngineMass = 0;
			currentBoosterMass = 0;
			currentSheildMass = 0;
			currentFArmorMass = 0;
			currentRArmorMass = 0;
			currentDroidMass = 0;
			currentCapacitorMass = 0;
			currentOrdinance1Mass = 0;
			currentOrdinance2Mass = 0;
			currentOrdinance3Mass = 0;
			currentWeapon1Mass = 0;
			currentWeapon2Mass = 0;
			currentWeapon3Mass = 0;
			currentWeapon4Mass = 0;
			currentChaffMass = 0;

			currentCompDrain = 0;

			currentReactorGeneration = 0;
			currentReactorOverloadedGeneration = 0;
			currentEngineDrain = 0;
			currentEngineOverloadedDrain = 0;
			currentBoosterDrain = 0;
			currentSheildDrain = 0;
			currentFArmorDrain = 0;
			currentRArmorDrain = 0;
			currentDroidDrain = 0;
			currentCapacitorDrain = 0;
			currentOrdinance1Drain = 0;
			currentOrdinance1OverloadedDrain = 0;
			currentOrdinance2Drain = 0;
			currentOrdinance2OverloadedDrain = 0;
			currentOrdinance3Drain = 0;
			currentOrdinance3OverloadedDrain = 0;
			currentWeapon1Drain = 0;
			currentWeapon1OverloadedDrain = 0;
			currentWeapon2Drain = 0;
			currentWeapon2OverloadedDrain = 0;
			currentWeapon3Drain = 0;
			currentWeapon3OverloadedDrain = 0;
			currentWeapon4Drain = 0;
			currentWeapon4OverloadedDrain = 0;
			currentChaffDrain = 0;
			currentChaffOverloadedDrain = 0;

			ReactorOverloadComboBox->SelectedIndex = 0;
			EngineOverloadComboBox->SelectedIndex = 0;
			WeaponOverloadComboBox->SelectedIndex = 0;
			CapacitorOverloadComboBox->SelectedIndex = 0;

			ReactorComboBox->SelectedIndex = 0;
 			EngineComboBox->SelectedIndex = 0;
			FArmorComboBox->SelectedIndex = 0;
			RArmorComboBox->SelectedIndex = 0;
			BoosterComboBox->SelectedIndex = 0;
			CapacitorComboBox->SelectedIndex = 0;
			DroidComboBox->SelectedIndex = 0;
			CountermeasuresComboBox->SelectedIndex = 0;
			Ordinance1ComboBox->SelectedIndex = 0;
			Ordinance2ComboBox->SelectedIndex = 0;
			Ordinance3ComboBox->SelectedIndex = 0;
			Weapon1ComboBox->SelectedIndex = 0;
			Weapon2ComboBox->SelectedIndex = 0;
			Weapon3ComboBox->SelectedIndex = 0;
			Weapon4ComboBox->SelectedIndex = 0;
			SheildComboBox->SelectedIndex = 0;

			ShipMassUsedValueLabel->Text = "0.0";
			LeftoverMassUsedValueLabel->Text = "0.0";
			TotalDrainValueLabel->Text = "0.0";

			shipStatisticsToolStripMenuItem->Enabled = false;
			saveShiploadoutToolStripMenuItem->Enabled = false;
			closeShipLoadoutToolStripMenuItem->Enabled = false;
		 }
		 /// Clears and empties all the componet lists.
private: System::Void ClearLists(){
				 ReactorList->Clear();
				 ReactorNameList->Clear();

				 EngineList->Clear();
				 EngineNameList->Clear();

				 BoosterList->Clear();
				 BoosterNameList->Clear();

				 SheildList->Clear();
				 SheildNameList->Clear();

				 ArmorList->Clear();
				 ArmorNameList->Clear();

				 DroidList->Clear();
				 DroidNameList->Clear();

				 CapacitorList->Clear();
				 CapacitorNameList->Clear();

				 WeaponList->Clear();
				 WeaponNameList->Clear();

				 OrdinanceList->Clear();
				 OrdinanceNameList->Clear();

				 ChaffList->Clear();
				 ChaffNameList->Clear();
		 }
		 /// Loads an existing CompLib files.
private: System::Void LoadExistingCompLibFile(){
			array<CompLib::Reactor^>^ tempReactorList;
			array<CompLib::Engine^>^ tempEngineList;
			array<CompLib::Booster^>^ tempBoosterList;
			array<CompLib::Sheild^>^ tempSheildList;
			array<CompLib::Armor^>^ tempArmorList;
			array<CompLib::Droid^>^ tempDroidList;
			array<CompLib::Capacitor^>^ tempCapacitorList;
			array<CompLib::Ordinance^>^ tempOrdinanceList;
			array<CompLib::Weapon^>^ tempWeaponList;
			array<CompLib::Chaff^>^ tempChaffList;
			
			String^ pilotName;

			pilotName = CompLib::XMLUtilities::OpenCompFile(String::Concat(appdir, "\\", complibdirectory), tempReactorList, tempEngineList, 
				 tempBoosterList, tempSheildList, tempArmorList, tempDroidList, tempCapacitorList,
				 tempOrdinanceList, tempWeaponList, tempChaffList);

			// Reactor
			if (tempReactorList->Length != 0)
			{
				for (int i=0; i<tempReactorList->Length; i++)
				{
					System::Data::DataRow^ rowReactor;
					Reactor^ tempReactor;

					ReactorList->Add(tempReactorList[i]);
					
					tempReactor = ReactorList[i];
					rowReactor = tempReactor[0];

					ReactorNameList->Add(rowReactor["Name"]->ToString());
				}
			}

			// Engine
			if (tempEngineList->Length != 0)
			{
				for (int i=0; i<tempEngineList->Length; i++)
				{
					System::Data::DataRow^ rowEngine;
					Engine^ tempEngine;

					EngineList->Add(tempEngineList[i]);
					
					tempEngine = EngineList[i];
					rowEngine = tempEngine[0];

					EngineNameList->Add(rowEngine["Name"]->ToString());
				}
			}

			// Booster
			if (tempBoosterList->Length != 0)
			{
				for (int i=0; i<tempBoosterList->Length; i++)
				{
					System::Data::DataRow^ rowBooster;
					Booster^ tempBooster;

					BoosterList->Add(tempBoosterList[i]);
					
					tempBooster = BoosterList[i];
					rowBooster = tempBooster[0];

					BoosterNameList->Add(rowBooster["Name"]->ToString());
				}
			}

			// Sheild
			if (tempSheildList->Length != 0)
			{
				for (int i=0; i<tempSheildList->Length; i++)
				{
					System::Data::DataRow^ rowSheild;
					Sheild^ tempSheild;

					SheildList->Add(tempSheildList[i]);
					
					tempSheild = SheildList[i];
					rowSheild = tempSheild[0];

					SheildNameList->Add(rowSheild["Name"]->ToString());
				}
			}

			// Armor
			if (tempArmorList->Length != 0)
			{
				for (int i=0; i<tempArmorList->Length; i++)
				{
					System::Data::DataRow^ rowArmor;
					Armor^ tempArmor;

					ArmorList->Add(tempArmorList[i]);
					
					tempArmor = ArmorList[i];
					rowArmor = tempArmor[0];

					ArmorNameList->Add(rowArmor["Name"]->ToString());
				}
			}

			// Droid
			if (tempDroidList->Length != 0)
			{
				for (int i=0; i<tempDroidList->Length; i++)
				{
					System::Data::DataRow^ rowDroid;
					Droid^ tempDroid;

					DroidList->Add(tempDroidList[i]);
					
					tempDroid = DroidList[i];
					rowDroid = tempDroid[0];

					DroidNameList->Add(rowDroid["Name"]->ToString());
				}
			}

			// Capacitor
			if (tempCapacitorList->Length != 0)
			{
				for (int i=0; i<tempCapacitorList->Length; i++)
				{
					System::Data::DataRow^ rowCapacitor;
					Capacitor^ tempCapacitor;

					CapacitorList->Add(tempCapacitorList[i]);
					
					tempCapacitor = CapacitorList[i];
					rowCapacitor = tempCapacitor[0];

					CapacitorNameList->Add(rowCapacitor["Name"]->ToString());
				}
			}

			// Ordinance
			if (tempOrdinanceList->Length != 0)
			{
				for (int i=0; i<tempOrdinanceList->Length; i++)
				{
					System::Data::DataRow^ rowOrdinance;
					Ordinance^ tempOrdinance;

					OrdinanceList->Add(tempOrdinanceList[i]);
					
					tempOrdinance = OrdinanceList[i];
					rowOrdinance = tempOrdinance[0];

					OrdinanceNameList->Add(rowOrdinance["Name"]->ToString());
				}
			}

			// Weapon
			if (tempWeaponList->Length != 0)
			{
				for (int i=0; i<tempWeaponList->Length; i++)
				{
					System::Data::DataRow^ rowWeapon;
					Weapon^ tempWeapon;

					WeaponList->Add(tempWeaponList[i]);
					
					tempWeapon = WeaponList[i];
					rowWeapon = tempWeapon[0];

					WeaponNameList->Add(rowWeapon["Name"]->ToString());
				}
			}

			// Chaff
			if (tempChaffList->Length != 0)
			{
				for (int i=0; i<tempChaffList->Length; i++)
				{
					System::Data::DataRow^ rowChaff;
					Chaff^ tempChaff;

					ChaffList->Add(tempChaffList[i]);
					
					tempChaff = ChaffList[i];
					rowChaff = tempChaff[0];

					ChaffNameList->Add(rowChaff["Name"]->ToString());
				}
			}

			if (ReactorList->Count != 0 || EngineList->Count != 0 || BoosterList->Count != 0 || 
				 SheildList->Count != 0 || ArmorList->Count != 0 || DroidList->Count != 0 || 
				 CapacitorList->Count != 0 || WeaponList->Count != 0 || OrdinanceList->Count != 0 ||
				 ChaffList->Count != 0)
			{
				UpdateLists();
			}
			}
		 /// Updates what hardpoints that are editable depending on the ship chassis selected.
private: System::Void UpdateHardpoints() {
			 switch (ShipChassisComboBox->SelectedIndex) {
				 /// Z-95
				 case 3:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;
								
				 /// Heavy Z-95				 
				 case 4:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;
								
				 /// Y-wing
				 case 5:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;
							   
				 /// Y-wing LP
				 case 6:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;
									Ordinance2Panel->Enabled = true;

									Ordinance3Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;
								  
				 /// X-wing
				 case 7:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Weapon3Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;
							   
				 /// Adv. X-wing
				 case 8:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Weapon3Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									TotalShipMassValueLabel->Text = "180000";
									break;
									
				 /// A-wing
				 case 9:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;
							   
				 /// B-wing
				 case 10:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Weapon3Panel->Enabled = true;
									Weapon4Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;
									Ordinance2Panel->Enabled = true;
									Ordinance3Panel->Enabled = false;

									Ordinance3ComboBox->SelectedIndex = 0;
									break;
							   
				 /// Nova
				 case 11:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;
									Ordinance2Panel->Enabled = true;
									Ordinance3Panel->Enabled = true;

									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;

				 /// Tie LD
				 case 15:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;

									Ordinance1Panel->Enabled = false;
									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance1ComboBox->SelectedIndex = 0;
									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;

				 /// Heavy Tie
				 case 16:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;

				 /// Tie Fighter
				 case 17:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;

				 /// Tie/IN
				 case 18:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;

				 /// Tie Bomber
				 case 19:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;
									Ordinance2Panel->Enabled = true;

									Ordinance3Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;

				 /// Tie Inter.
				 case 20:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;

				 /// Tie Adv.
				 case 21:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;

				 /// Tie Aggres.
				 case 22:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;

				 /// RGI
				 case 23:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									break;

				 /// Tie Opp.
				 case 24:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;
									Ordinance2Panel->Enabled = true;
									Ordinance3Panel->Enabled = true;

									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;
									break;

				 /// Decimator
				 case 25:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;
									Ordinance2Panel->Enabled = true;
									Ordinance3Panel->Enabled = true;

									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;
									break;

				 /// Syck
				 case 29:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;
									break;

				 /// Heavy Syck
				 case 30:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;
									break;

				 /// Dunelizard
				 case 31:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;
									break;

				 /// Kihraxz
				 case 32:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;
									break;

				 /// M12L Kimo
				 case 33:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Weapon3Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;
									break;

				 /// Ixiyen
				 case 34:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;
									break;

				 /// Rihkxyrk
				 case 35:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Weapon3Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;
									break;

			 	 /// Vaksai
				 case 36:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									TotalShipMassValueLabel->Text = "150000";
									break;

				 /// M22-T Kyrat
				 case 37:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Weapon3Panel->Enabled = true;
									Weapon4Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									break;

				 /// YT-1300
				 case 38:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;
									Ordinance2Panel->Enabled = true;

									Ordinance3Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;
									break;

				 /// ARC-170
				 case 42:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Weapon3Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									TotalShipMassValueLabel->Text = "125000";
									break;

				 /// JSF
				 case 43:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									TotalShipMassValueLabel->Text = "90000";
									break;

				 /// B22
				 case 44:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;

									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									TotalShipMassValueLabel->Text = "90000";
									break;

				 /// Firespray
				 case 45:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;
									Ordinance2Panel->Enabled = true;

									Ordinance3Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;
									break;

				 /// YT-2400
				 case 46:			ReactorPanel->Enabled = true;
									EnginePanel->Enabled = true;
									BoosterPanel->Enabled = true;
									ArmorPanel->Enabled = true;
									
									SheildPanel->Enabled = true;
									CountermeasuresPanel->Enabled = true;
									DroidPanel->Enabled = true;
									CapacitorPanel->Enabled = true;
									Weapon1Panel->Enabled = true;
									Weapon2Panel->Enabled = true;
									Ordinance1Panel->Enabled = true;
									Ordinance2Panel->Enabled = true;

									Ordinance3Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;

									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;

									TotalShipMassValueLabel->Text = "5000000";
									break;
									
				 default:			ReactorPanel->Enabled = false;
									EnginePanel->Enabled = false;
									ArmorPanel->Enabled = false;
									BoosterPanel->Enabled = false;
									CapacitorPanel->Enabled = false;
									DroidPanel->Enabled = false;
									CountermeasuresPanel->Enabled = false;
									Ordinance1Panel->Enabled = false;
									Ordinance2Panel->Enabled = false;
									Ordinance3Panel->Enabled = false;
									Weapon1Panel->Enabled = false;
									Weapon2Panel->Enabled = false;
									Weapon3Panel->Enabled = false;
									Weapon4Panel->Enabled = false;
									SheildPanel->Enabled = false;

									ReactorComboBox->SelectedIndex = 0;
									EngineComboBox->SelectedIndex = 0;
									FArmorComboBox->SelectedIndex = 0;
									RArmorComboBox->SelectedIndex = 0;
									BoosterComboBox->SelectedIndex = 0;
									CapacitorComboBox->SelectedIndex = 0;
									DroidComboBox->SelectedIndex = 0;
									CountermeasuresComboBox->SelectedIndex = 0;
									Ordinance1ComboBox->SelectedIndex = 0;
									Ordinance2ComboBox->SelectedIndex = 0;
									Ordinance3ComboBox->SelectedIndex = 0;
									Weapon1ComboBox->SelectedIndex = 0;
									Weapon2ComboBox->SelectedIndex = 0;
									Weapon3ComboBox->SelectedIndex = 0;
									Weapon4ComboBox->SelectedIndex = 0;
									SheildComboBox->SelectedIndex = 0;

							if (MessageBox::Show("Error: That is not a valid Ship Chassis.", "Invalid Chassis Selection", 
							MessageBoxButtons::OK, MessageBoxIcon::Error) == 
							System::Windows::Forms::DialogResult::OK){
								break;
							}
			 }
		 }


		 /// Loads componets into the combo boxes for each component.
private: System::Void UpdateLists(){
			 // Reactors
			 ReactorComboBox->Items->Clear();

			 for (int i=0; i<ReactorNameList->Count; i++)
			 {
				 ReactorComboBox->Items->Add(ReactorNameList[i]);
			 }

			 // Engines
			 EngineComboBox->Items->Clear();

			 for (int i=0; i<EngineNameList->Count; i++)
			 {
				 EngineComboBox->Items->Add(EngineNameList[i]);
			 }

			 // Boosters
			 BoosterComboBox->Items->Clear();

			 for (int i=0; i<BoosterNameList->Count; i++)
			 {
				 BoosterComboBox->Items->Add(BoosterNameList[i]);
			 }

			 // Sheilds
			 SheildComboBox->Items->Clear();

			 for (int i=0; i<SheildNameList->Count; i++)
			 {
				 SheildComboBox->Items->Add(SheildNameList[i]);
			 }

			 // Armor
			 FArmorComboBox->Items->Clear();
			 RArmorComboBox->Items->Clear();

			 for (int i=0; i<ArmorNameList->Count; i++)
			 {
				 FArmorComboBox->Items->Add(ArmorNameList[i]);
				 RArmorComboBox->Items->Add(ArmorNameList[i]);
			 }

			 // Droid
			 DroidComboBox->Items->Clear();

			 for (int i=0; i<DroidNameList->Count; i++)
			 {
				 DroidComboBox->Items->Add(DroidNameList[i]);
			 }

			 // Capacitor
			 CapacitorComboBox->Items->Clear();

			 for (int i=0; i<CapacitorNameList->Count; i++)
			 {
				 CapacitorComboBox->Items->Add(CapacitorNameList[i]);
			 }

			 // Weapons
			 Weapon1ComboBox->Items->Clear();
			 Weapon2ComboBox->Items->Clear();
			 Weapon3ComboBox->Items->Clear();
			 Weapon4ComboBox->Items->Clear();

			 for (int i=0; i<WeaponNameList->Count; i++)
			 {
				 Weapon1ComboBox->Items->Add(WeaponNameList[i]);
				 Weapon2ComboBox->Items->Add(WeaponNameList[i]);
				 Weapon3ComboBox->Items->Add(WeaponNameList[i]);
				 Weapon4ComboBox->Items->Add(WeaponNameList[i]);
			 }

			 // Ordinance
			 Ordinance1ComboBox->Items->Clear();
			 Ordinance2ComboBox->Items->Clear();
			 Ordinance3ComboBox->Items->Clear();

			 for (int i=0; i<OrdinanceNameList->Count; i++)
			 {
				 Ordinance1ComboBox->Items->Add(OrdinanceNameList[i]);
				 Ordinance2ComboBox->Items->Add(OrdinanceNameList[i]);
				 Ordinance3ComboBox->Items->Add(OrdinanceNameList[i]);
			 }

			 // Chaff
			 CountermeasuresComboBox->Items->Clear();

			 for (int i=0; i<ChaffNameList->Count; i++)
			 {
				 CountermeasuresComboBox->Items->Add(ChaffNameList[i]);
			 }
		 }
		 /// Reloads componets to refelect any changes that my have occured to them (ie: being 
		 /// edited in the Comp. Management screen.
private: System::Void ReloadComboBoxes(String^ selectedReactor, String^ selectedEngine, String^ selectedBooster, String^ selectedSheild, 
			 String^ selectedFArmor, String^ selectedRArmor, String^ selectedDroid, String^ selectedCapacitor, String^ selectedOrdinance1, 
			 String^ selectedOrdinance2, String^ selectedOrdinance3, String^ selectedWeapon1, String^ selectedWeapon2, String^ selectedWeapon3, 
			 String^ selectedWeapon4, String^ selectedChaff){
			 ReactorComboBox->SelectedIndex = 0;
			 EngineComboBox->SelectedIndex = 0;
			 BoosterComboBox->SelectedIndex = 0;
			 SheildComboBox->SelectedIndex = 0;
			 FArmorComboBox->SelectedIndex = 0;
			 RArmorComboBox->SelectedIndex = 0;
			 DroidComboBox->SelectedIndex = 0;
			 CapacitorComboBox->SelectedIndex = 0;
			 Ordinance1ComboBox->SelectedIndex = 0;
			 Ordinance2ComboBox->SelectedIndex = 0;
			 Ordinance3ComboBox->SelectedIndex = 0;
			 Weapon1ComboBox->SelectedIndex = 0;
			 Weapon2ComboBox->SelectedIndex = 0;
			 Weapon3ComboBox->SelectedIndex = 0;
			 Weapon4ComboBox->SelectedIndex = 0;
			 CountermeasuresComboBox->SelectedIndex = 0;

			 ReactorComboBox->SelectedItem = selectedReactor;
			 EngineComboBox->SelectedItem = selectedEngine;
			 BoosterComboBox->SelectedItem = selectedBooster;
			 SheildComboBox->SelectedItem = selectedSheild;
			 FArmorComboBox->SelectedItem = selectedFArmor;
			 RArmorComboBox->SelectedItem = selectedRArmor;
			 DroidComboBox->SelectedItem = selectedDroid;
			 CapacitorComboBox->SelectedItem = selectedCapacitor;
			 Ordinance1ComboBox->SelectedItem = selectedOrdinance1;
			 Ordinance2ComboBox->SelectedItem = selectedOrdinance2;
			 Ordinance3ComboBox->SelectedItem = selectedOrdinance3;
			 Weapon1ComboBox->SelectedItem = selectedWeapon1;
			 Weapon2ComboBox->SelectedItem = selectedWeapon2;
			 Weapon3ComboBox->SelectedItem = selectedWeapon3;
			 Weapon4ComboBox->SelectedItem = selectedWeapon4;
			 CountermeasuresComboBox->SelectedItem = selectedChaff;
		 }
		 /// Updates the mass calculations every time a new componet is slected in the combo boxes.
private: System::Void UpdateMass(double tempMass, char compChanged){
			 switch (compChanged)
			 {
			 case 'r': currentCompMass = currentReactorMass;
				 break;
			 case 'e': currentCompMass = currentEngineMass;
				 break;
			 case 'b': currentCompMass = currentBoosterMass;
				 break;
			 case 's': currentCompMass = currentSheildMass;
				 break;
			 case 'A': currentCompMass = currentFArmorMass;
				 break;
			 case 'a': currentCompMass = currentRArmorMass;
				 break;
			 case 'd': currentCompMass = currentDroidMass;
				 break;
			 case 'C': currentCompMass = currentCapacitorMass;
				 break;
			 case 'O': currentCompMass = currentOrdinance1Mass;
				 break;
			 case 'o': currentCompMass = currentOrdinance2Mass;
				 break;
			 case '0': currentCompMass = currentOrdinance3Mass;
				 break;
			 case '1': currentCompMass = currentWeapon1Mass;
				 break;
			 case '2': currentCompMass = currentWeapon2Mass;
				 break;
			 case '3': currentCompMass = currentWeapon3Mass;
				 break;
			 case '4': currentCompMass = currentWeapon4Mass;
				 break;
			 case 'c': currentCompMass = currentChaffMass;
				 break;
			 }
			 currentMassUsed += (tempMass - currentCompMass);
			 currentLeftoverMass = Convert::ToDouble(TotalShipMassValueLabel->Text->ToString()) - currentMassUsed;

			 if (currentLeftoverMass < 0)
			 {
				 LeftoverMassUsedValueLabel->ForeColor = Color::Red;
			 }
			 else
			 {
				 LeftoverMassUsedValueLabel->ForeColor = Color::White;
			 }

			 ShipMassUsedValueLabel->Text = currentMassUsed.ToString(".##");
			 LeftoverMassUsedValueLabel->Text = currentLeftoverMass.ToString(".##");
		 }
		 /// Current Drain calculations determine the drain of the loaded componet depending on the overload
		 /// that was selected.
private: System::Void CurrentROGen(){
			 switch (ReactorOverloadComboBox->SelectedIndex)
			 {
			 case 0: currentReactorOverloadedGeneration = currentReactorGeneration * 1;
				 break;
			 case 1: currentReactorOverloadedGeneration = currentReactorGeneration * 1.1;
				 break;
			 case 2: currentReactorOverloadedGeneration = currentReactorGeneration * 1.3;
				 break;
			 case 3: currentReactorOverloadedGeneration = currentReactorGeneration * 1.6;
				 break;
			 case 4: currentReactorOverloadedGeneration = currentReactorGeneration * 1.9;
				 break;
			 }
		 }
private: System::Void CurrentEODrain(){
			 switch (EngineOverloadComboBox->SelectedIndex)
			 {
			 case 0: currentEngineOverloadedDrain = currentEngineDrain * 1;
				 break;
			 case 1: currentEngineOverloadedDrain = currentEngineDrain * 1.25;
				 break;
			 case 2: currentEngineOverloadedDrain = currentEngineDrain * 1.67;
				 break;
			 case 3: currentEngineOverloadedDrain = currentEngineDrain * 3.33;
				 break;
			 case 4: currentEngineOverloadedDrain = currentEngineDrain * 10.0;
				 break;
			 }
		 }
private: System::Void CurrentO1ODrain(){
			 switch (WeaponOverloadComboBox->SelectedIndex)
			 {
			 case 0: currentOrdinance1OverloadedDrain = currentOrdinance1Drain * 1;
				 break;
			 case 1: currentOrdinance1OverloadedDrain = currentOrdinance1Drain * 1.43;
				 break;
			 case 2: currentOrdinance1OverloadedDrain = currentOrdinance1Drain * 2.00;
				 break;
			 case 3: currentOrdinance1OverloadedDrain = currentOrdinance1Drain * 2.86;
				 break;
			 case 4: currentOrdinance1OverloadedDrain = currentOrdinance1Drain * 5.00;
				 break;
			 }
		 }
private: System::Void CurrentO2ODrain(){
			 switch (WeaponOverloadComboBox->SelectedIndex)
			 {
			 case 0: currentOrdinance2OverloadedDrain = currentOrdinance2Drain * 1;
				 break;
			 case 1: currentOrdinance2OverloadedDrain = currentOrdinance2Drain * 1.43;
				 break;
			 case 2: currentOrdinance2OverloadedDrain = currentOrdinance2Drain * 2.00;
				 break;
			 case 3: currentOrdinance2OverloadedDrain = currentOrdinance2Drain * 2.86;
				 break;
			 case 4: currentOrdinance2OverloadedDrain = currentOrdinance2Drain * 5.00;
				 break;
			 }
		 }
private: System::Void CurrentO3ODrain(){
			 switch (WeaponOverloadComboBox->SelectedIndex)
			 {
			 case 0: currentOrdinance3OverloadedDrain = currentOrdinance3Drain * 1;
				 break;
			 case 1: currentOrdinance3OverloadedDrain = currentOrdinance3Drain * 1.43;
				 break;
			 case 2: currentOrdinance3OverloadedDrain = currentOrdinance3Drain * 2.00;
				 break;
			 case 3: currentOrdinance3OverloadedDrain = currentOrdinance3Drain * 2.86;
				 break;
			 case 4: currentOrdinance3OverloadedDrain = currentOrdinance3Drain * 5.00;
				 break;
			 }
		 }
private: System::Void CurrentW1ODrain(){
			 switch (WeaponOverloadComboBox->SelectedIndex)
			 {
			 case 0: currentWeapon1OverloadedDrain = currentWeapon1Drain * 1;
				 break;
			 case 1: currentWeapon1OverloadedDrain = currentWeapon1Drain * 1.43;
				 break;
			 case 2: currentWeapon1OverloadedDrain = currentWeapon1Drain * 2.00;
				 break;
			 case 3: currentWeapon1OverloadedDrain = currentWeapon1Drain * 2.86;
				 break;
			 case 4: currentWeapon1OverloadedDrain = currentWeapon1Drain * 5.00;
				 break;
			 }
		 }
private: System::Void CurrentW2ODrain(){
			 switch (WeaponOverloadComboBox->SelectedIndex)
			 {
			 case 0: currentWeapon2OverloadedDrain = currentWeapon2Drain * 1;
				 break;
			 case 1: currentWeapon2OverloadedDrain = currentWeapon2Drain * 1.43;
				 break;
			 case 2: currentWeapon2OverloadedDrain = currentWeapon2Drain * 2.00;
				 break;
			 case 3: currentWeapon2OverloadedDrain = currentWeapon2Drain * 2.86;
				 break;
			 case 4: currentWeapon2OverloadedDrain = currentWeapon2Drain * 5.00;
				 break;
			 }
		 }
private: System::Void CurrentW3ODrain(){
			 switch (WeaponOverloadComboBox->SelectedIndex)
			 {
			 case 0: currentWeapon3OverloadedDrain = currentWeapon3Drain * 1;
				 break;
			 case 1: currentWeapon3OverloadedDrain = currentWeapon3Drain * 1.43;
				 break;
			 case 2: currentWeapon3OverloadedDrain = currentWeapon3Drain * 2.00;
				 break;
			 case 3: currentWeapon3OverloadedDrain = currentWeapon3Drain * 2.86;
				 break;
			 case 4: currentWeapon3OverloadedDrain = currentWeapon3Drain * 5.00;
				 break;
			 }
		 }
private: System::Void CurrentW4ODrain(){
			 switch (WeaponOverloadComboBox->SelectedIndex)
			 {
			 case 0: currentWeapon4OverloadedDrain = currentWeapon4Drain * 1;
				 break;
			 case 1: currentWeapon4OverloadedDrain = currentWeapon4Drain * 1.43;
				 break;
			 case 2: currentWeapon4OverloadedDrain = currentWeapon4Drain * 2.00;
				 break;
			 case 3: currentWeapon4OverloadedDrain = currentWeapon4Drain * 2.86;
				 break;
			 case 4: currentWeapon4OverloadedDrain = currentWeapon4Drain * 5.00;
				 break;
			 }
		 }
		 /// Updates the drain calculations every time a new componet is selected as well as every time a different
		 /// overload is selected.
private: System::Void UpdateDrain(double tempDrain, char compChanged){
			 switch (compChanged)
			 {
			 case 'e':
				 switch (EngineOverloadComboBox->SelectedIndex)
				 {
				 case 0: tempDrain *= 1;
					 currentDrainTotal -= currentEngineOverloadedDrain;
					 break;
				 case 1: tempDrain *= 1.25;
					 currentDrainTotal -= currentEngineOverloadedDrain;
					 break;
				 case 2: tempDrain *= 1.67;
					 currentDrainTotal -= currentEngineOverloadedDrain;
					 break;
				 case 3: tempDrain *= 3.33;
					 currentDrainTotal -= currentEngineOverloadedDrain;
					 break;
				 case 4: tempDrain *= 10.0;
					 currentDrainTotal -= currentEngineOverloadedDrain;
					 break;
				 }
				 currentCompDrain = 0;
				 break;
			 case 'b': currentCompDrain = currentBoosterDrain;
				 break;
			 case 's': currentCompDrain = currentSheildDrain;
				 break;
			 case 'A': currentCompDrain = currentFArmorDrain;
				 break;
			 case 'a': currentCompDrain = currentRArmorDrain;
				 break;
			 case 'd': currentCompDrain = currentDroidDrain;
				 break;
			 case 'C': currentCompDrain = currentCapacitorDrain;
				 break;
			 case 'O': 
				 switch (WeaponOverloadComboBox->SelectedIndex)
				 {
				 case 0: tempDrain *= 1;
					 currentDrainTotal -= currentOrdinance1OverloadedDrain;
					 break;
				 case 1: tempDrain *= 1.43;
					 currentDrainTotal -= currentOrdinance1OverloadedDrain;
					 break;
				 case 2: tempDrain *= 2.00;
					 currentDrainTotal -= currentOrdinance1OverloadedDrain;
					 break;
				 case 3: tempDrain *= 2.86;
					 currentDrainTotal -= currentOrdinance1OverloadedDrain;
					 break;
				 case 4: tempDrain *= 5.00;
					 currentDrainTotal -= currentOrdinance1OverloadedDrain;
					 break;
				 }
				 currentCompDrain = 0;
				 break;
			 case 'o': 
				 switch (WeaponOverloadComboBox->SelectedIndex)
				 {
				 case 0: tempDrain *= 1;
					 currentDrainTotal -= currentOrdinance2OverloadedDrain;
					 break;
				 case 1: tempDrain *= 1.43;
					 currentDrainTotal -= currentOrdinance2OverloadedDrain;
					 break;
				 case 2: tempDrain *= 2.00;
					 currentDrainTotal -= currentOrdinance2OverloadedDrain;
					 break;
				 case 3: tempDrain *= 2.86;
					 currentDrainTotal -= currentOrdinance2OverloadedDrain;
					 break;
				 case 4: tempDrain *= 5.00;
					 currentDrainTotal -= currentOrdinance2OverloadedDrain;
					 break;
				 }
				 currentCompDrain = 0;
				 break;
			 case '0': 
				 switch (WeaponOverloadComboBox->SelectedIndex)
				 {
				 case 0: tempDrain *= 1;
					 currentDrainTotal -= currentOrdinance3OverloadedDrain;
					 break;
				 case 1: tempDrain *= 1.43;
					 currentDrainTotal -= currentOrdinance3OverloadedDrain;
					 break;
				 case 2: tempDrain *= 2.00;
					 currentDrainTotal -= currentOrdinance3OverloadedDrain;
					 break;
				 case 3: tempDrain *= 2.86;
					 currentDrainTotal -= currentOrdinance3OverloadedDrain;
					 break;
				 case 4: tempDrain *= 5.00;
					 currentDrainTotal -= currentOrdinance3OverloadedDrain;
					 break;
				 }
				 currentCompDrain = 0;
				 break;
			 case '1': 
				 switch (WeaponOverloadComboBox->SelectedIndex)
				 {
				 case 0: tempDrain *= 1;
					 currentDrainTotal -= currentWeapon1OverloadedDrain;
					 break;
				 case 1: tempDrain *= 1.43;
					 currentDrainTotal -= currentWeapon1OverloadedDrain;
					 break;
				 case 2: tempDrain *= 2.00;
					 currentDrainTotal -= currentWeapon1OverloadedDrain;
					 break;
				 case 3: tempDrain *= 2.86;
					 currentDrainTotal -= currentWeapon1OverloadedDrain;
					 break;
				 case 4: tempDrain *= 5.00;
					 currentDrainTotal -= currentWeapon1OverloadedDrain;
					 break;
				 }
				 currentCompDrain = 0;
				 break;
			 case '2': 
				 switch (WeaponOverloadComboBox->SelectedIndex)
				 {
				 case 0: tempDrain *= 1;
					 currentDrainTotal -= currentWeapon2OverloadedDrain;
					 break;
				 case 1: tempDrain *= 1.43;
					 currentDrainTotal -= currentWeapon2OverloadedDrain;
					 break;
				 case 2: tempDrain *= 2.00;
					 currentDrainTotal -= currentWeapon2OverloadedDrain;
					 break;
				 case 3: tempDrain *= 2.86;
					 currentDrainTotal -= currentWeapon2OverloadedDrain;
					 break;
				 case 4: tempDrain *= 5.00;
					 currentDrainTotal -= currentWeapon2OverloadedDrain;
					 break;
				 }
				 currentCompDrain = 0;
				 break;
			 case '3': 
				 switch (WeaponOverloadComboBox->SelectedIndex)
				 {
				 case 0: tempDrain *= 1;
					 currentDrainTotal -= currentWeapon3OverloadedDrain;
					 break;
				 case 1: tempDrain *= 1.43;
					 currentDrainTotal -= currentWeapon3OverloadedDrain;
					 break;
				 case 2: tempDrain *= 2.00;
					 currentDrainTotal -= currentWeapon3OverloadedDrain;
					 break;
				 case 3: tempDrain *= 2.86;
					 currentDrainTotal -= currentWeapon3OverloadedDrain;
					 break;
				 case 4: tempDrain *= 5.00;
					 currentDrainTotal -= currentWeapon3OverloadedDrain;
					 break;
				 }
				 currentCompDrain = 0;
				 break;
			 case '4': 
				 switch (WeaponOverloadComboBox->SelectedIndex)
				 {
				 case 0: tempDrain *= 1;
					 currentDrainTotal -= currentWeapon4OverloadedDrain;
					 break;
				 case 1: tempDrain *= 1.43;
					 currentDrainTotal -= currentWeapon4OverloadedDrain;
					 break;
				 case 2: tempDrain *= 2.00;
					 currentDrainTotal -= currentWeapon4OverloadedDrain;
					 break;
				 case 3: tempDrain *= 2.86;
					 currentDrainTotal -= currentWeapon4OverloadedDrain;
					 break;
				 case 4: tempDrain *= 5.00;
					 currentDrainTotal -= currentWeapon4OverloadedDrain;
					 break;
				 }
				 currentCompDrain = 0;
				 break;
			 case 'c': currentCompDrain = currentChaffDrain;
				 break;
			 }

			 currentDrainTotal += (tempDrain - currentCompDrain);

			 TotalDrainValueLabel->Text = currentDrainTotal.ToString(".##");
		 }
		 /// Closes the form and creates a backup CompLib file in the Backup folder.
private: System::Void CloseForm(){
			 System::IO::File::Delete(String::Concat(appdir, "\\", backupdirectory));

			 CompLib::XMLUtilities::CreateCompFile(String::Concat(appdir, "\\", backupdirectory), "pilotname", ReactorList->ToArray(), EngineList->ToArray(), 
				 BoosterList->ToArray(), SheildList->ToArray(), ArmorList->ToArray(), DroidList->ToArray(), CapacitorList->ToArray(),
				 OrdinanceList->ToArray(), WeaponList->ToArray(), ChaffList->ToArray());
		 }
		 ///
		 /// Form Calls
		 ///
private: System::Void massDrainSummaryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (ReactorComboBox->SelectedIndex != 0 && EngineComboBox->SelectedIndex != 0)
			 {
				 MassDrainSummaryForm ^massDrainSummaryForm = gcnew MassDrainSummaryForm(currentReactorMass, currentEngineMass, 
					 currentBoosterMass, currentSheildMass, currentFArmorMass, currentRArmorMass, currentDroidMass, 
					 currentCapacitorMass, currentOrdinance1Mass, currentOrdinance2Mass, currentOrdinance3Mass, 
					 currentWeapon1Mass, currentWeapon2Mass, currentWeapon3Mass, currentWeapon4Mass, currentChaffMass, 
					 currentReactorGeneration, currentReactorOverloadedGeneration, currentEngineDrain, currentEngineOverloadedDrain, 
					 currentBoosterDrain, currentSheildDrain, currentDroidDrain, currentCapacitorDrain, 
					 currentOrdinance1Drain, currentOrdinance1OverloadedDrain, currentOrdinance2Drain, currentOrdinance2OverloadedDrain, 
					 currentOrdinance3Drain, currentOrdinance3OverloadedDrain, currentWeapon1Drain, currentWeapon1OverloadedDrain, 
					 currentWeapon2Drain, currentWeapon2OverloadedDrain, currentWeapon3Drain, currentWeapon3OverloadedDrain, 
					 currentWeapon4Drain, currentWeapon4OverloadedDrain, currentChaffDrain);

					 massDrainSummaryForm->ShowDialog();

					 massDrainSummaryForm->Close();
			 }
			 else
			 {
				 if (MessageBox::Show("Error: You must have at least a Reactor and Engine for your ship to function.", "No Reactor or Engine", 
					 MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK){
				 }
			 }
		 }

private: System::Void reactorCalculatorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 int selectedReactorOverload = ReactorOverloadComboBox->SelectedIndex;
			 if (currentDrainTotal != 0){
				 if (ReactorComboBox->SelectedIndex != 0)
				 {
					 ReactorCalcForm ^reactorCalcForm = gcnew ReactorCalcForm(ReactorList[ReactorComboBox->SelectedIndex], 
						 selectedReactorOverload, currentDrainTotal);
					 
					 reactorCalcForm->ShowDialog();

					 reactorCalcForm->Close();
				 }
				 else
				 {
					 if (MessageBox::Show("Error: You must have a Reactor loaded.", "No Reactor", 
						 MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK){
					 }
				 }
			 }
			 else
			 {
				 if (MessageBox::Show("Error: You must have at least one componet loaded with a drain value to use the Reactor Calculator.", "No Drain", 
						 MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK){
					 }
			 }
		 }

private: System::Void propulsionStatsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 int selectedEngineOverload = EngineOverloadComboBox->SelectedIndex;
			 int selectedChassis = ShipChassisComboBox->SelectedIndex;

			 if (ReactorComboBox->SelectedIndex != 0 && EngineComboBox->SelectedIndex != 0)
			 {
				 if (BoosterComboBox->SelectedIndex != 0)
				 {
					 PropulsionStatsForm ^propulsionStatsForm = gcnew PropulsionStatsForm(EngineList[EngineComboBox->SelectedIndex],
						 BoosterList[BoosterComboBox->SelectedIndex], selectedEngineOverload, selectedChassis);
					 
					 propulsionStatsForm->ShowDialog();

					 propulsionStatsForm->Close();
				 }
				 else
				 {
					 PropulsionStatsForm ^propulsionStatsForm = gcnew PropulsionStatsForm(EngineList[EngineComboBox->SelectedIndex],
						 selectedEngineOverload, selectedChassis);
					 
					 propulsionStatsForm->ShowDialog();

					 propulsionStatsForm->Close();
				 }
			 }
			 else
			 {
				 if (MessageBox::Show("Error: You must have at least a Reactor and Engine for your ship to function.", "No Reactor or Engine", 
					 MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK){
				 }
			 }
		 }

private: System::Void protectionStatsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (ReactorComboBox->SelectedIndex != 0 && EngineComboBox->SelectedIndex != 0)
			 {
				 ProtectionStatsForm ^protectionStatsForm = gcnew ProtectionStatsForm(ReactorList[ReactorComboBox->SelectedIndex], 
					 EngineList[EngineComboBox->SelectedIndex], BoosterList[BoosterComboBox->SelectedIndex], SheildList[SheildComboBox->SelectedIndex], 
					 DroidList[DroidComboBox->SelectedIndex], CapacitorList[CapacitorComboBox->SelectedIndex], ArmorList[FArmorComboBox->SelectedIndex], 
					 ArmorList[RArmorComboBox->SelectedIndex], OrdinanceList[Ordinance1ComboBox->SelectedIndex], OrdinanceList[Ordinance2ComboBox->SelectedIndex], 
					 OrdinanceList[Ordinance3ComboBox->SelectedIndex], WeaponList[Weapon1ComboBox->SelectedIndex], WeaponList[Weapon2ComboBox->SelectedIndex], 
					 WeaponList[Weapon3ComboBox->SelectedIndex], WeaponList[Weapon4ComboBox->SelectedIndex], ChaffList[CountermeasuresComboBox->SelectedIndex]);
				 
				 protectionStatsForm->ShowDialog();

				 protectionStatsForm->Close();
			 }
			 else
			 {
				 if (MessageBox::Show("Error: You must have at least a Reactor and Engine for your ship to function.", "No Reactor or Engine", 
					 MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK){
				 }
			 }
		 }

private: System::Void weaponStatsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (Weapon1ComboBox->SelectedIndex != 0 || Weapon2ComboBox->SelectedIndex != 0 || 
				 Weapon3ComboBox->SelectedIndex != 0 || Weapon4ComboBox->SelectedIndex != 0)
			 {
				 int selectedWeaponOverload = WeaponOverloadComboBox->SelectedIndex;
				 int selectedCapacitorOverload = CapacitorOverloadComboBox->SelectedIndex;

				 WeaponStatsForm ^weaponStatsForm = gcnew WeaponStatsForm(WeaponList[Weapon1ComboBox->SelectedIndex],
					 WeaponList[Weapon2ComboBox->SelectedIndex], WeaponList[Weapon3ComboBox->SelectedIndex],
					 WeaponList[Weapon4ComboBox->SelectedIndex], CapacitorList[CapacitorComboBox->SelectedIndex], 
					 selectedWeaponOverload, selectedCapacitorOverload);

				 weaponStatsForm->ShowDialog();

				 weaponStatsForm->Close();
			 }
			 else
			 {
				 if (MessageBox::Show("Error: You must have at least one Weapon loaded.", "No Weapon", 
				 MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK){
				 }
			 }
		 }

private: System::Void manageComponentToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ selectedReactor = ReactorComboBox->SelectedItem->ToString();
			String^ selectedEngine = EngineComboBox->SelectedItem->ToString();
			String^ selectedBooster = BoosterComboBox->SelectedItem->ToString();
			String^ selectedSheild = SheildComboBox->SelectedItem->ToString();
			String^ selectedFArmor = FArmorComboBox->SelectedItem->ToString();
			String^ selectedRArmor = RArmorComboBox->SelectedItem->ToString();
			String^ selectedDroid = DroidComboBox->SelectedItem->ToString();
			String^ selectedCapacitor = CapacitorComboBox->SelectedItem->ToString();
			String^ selectedOrdinance1 = Ordinance1ComboBox->SelectedItem->ToString();
			String^ selectedOrdinance2 = Ordinance2ComboBox->SelectedItem->ToString();
			String^ selectedOrdinance3 = Ordinance3ComboBox->SelectedItem->ToString();
			String^ selectedWeapon1 = Weapon1ComboBox->SelectedItem->ToString();
			String^ selectedWeapon2 = Weapon2ComboBox->SelectedItem->ToString();
			String^ selectedWeapon3 = Weapon3ComboBox->SelectedItem->ToString();
			String^ selectedWeapon4 = Weapon4ComboBox->SelectedItem->ToString();
			String^ selectedChaff = CountermeasuresComboBox->SelectedItem->ToString();

			String^ currentdir = "";

			currentdir = appdir;

			if (System::IO::File::Exists(String::Concat(appdir, "\\", complibdirectory)) == false)
			{
				 ComponentManagementForm ^componentManagementForm = gcnew ComponentManagementForm(currentdir);
				 componentManagementForm->ShowDialog();
				 
				 ClearLists();

				 ReactorList = componentManagementForm->ReactorData;
				 ReactorNameList = componentManagementForm->ReactorNameData;

				 EngineList = componentManagementForm->EngineData;
				 EngineNameList = componentManagementForm->EngineNameData;

				 BoosterList = componentManagementForm->BoosterData;
				 BoosterNameList = componentManagementForm->BoosterNameData;

				 SheildList = componentManagementForm->SheildData;
				 SheildNameList = componentManagementForm->SheildNameData;

				 ArmorList = componentManagementForm->ArmorData;
				 ArmorNameList = componentManagementForm->ArmorNameData;

				 DroidList = componentManagementForm->DroidData;
				 DroidNameList = componentManagementForm->DroidNameData;

				 CapacitorList = componentManagementForm->CapacitorData;
				 CapacitorNameList = componentManagementForm->CapacitorNameData;

				 WeaponList = componentManagementForm->WeaponData;
				 WeaponNameList = componentManagementForm->WeaponNameData;

				 OrdinanceList = componentManagementForm->OrdinanceData;
				 OrdinanceNameList = componentManagementForm->OrdinanceNameData;

				 ChaffList = componentManagementForm->ChaffData;
				 ChaffNameList = componentManagementForm->ChaffNameData;

				 componentManagementForm->Close();
				 UpdateLists();

				 ReloadComboBoxes(selectedReactor, selectedEngine, selectedBooster, selectedSheild, selectedFArmor, 
					 selectedRArmor, selectedDroid, selectedCapacitor, selectedOrdinance1, selectedOrdinance2, 
					 selectedOrdinance3, selectedWeapon1, selectedWeapon2, selectedWeapon3, selectedWeapon4, 
					 selectedChaff);
			 }
			 else
			 {
				 ComponentManagementForm ^componentManagementFormEdit = gcnew ComponentManagementForm(ReactorList, EngineList, BoosterList,
					 SheildList, ArmorList, DroidList, CapacitorList, WeaponList, OrdinanceList, ChaffList, ReactorNameList, EngineNameList,
					 BoosterNameList, SheildNameList, ArmorNameList, DroidNameList, CapacitorNameList, WeaponNameList, OrdinanceNameList,
					 ChaffNameList, currentReactorSelectedIndex, currentEngineSelectedIndex, currentBoosterSelectedIndex, currentSheildSelectedIndex, 
					 currentFArmorSelectedIndex, currentRArmorSelectedIndex, currentDroidSelectedIndex, currentCapacitorSelectedIndex, 
					 currentOrdinance1SelectedIndex, currentOrdinance2SelectedIndex, currentOrdinance3SelectedIndex, currentWeapon1SelectedIndex, 
					 currentWeapon2SelectedIndex, currentWeapon3SelectedIndex, currentWeapon4SelectedIndex, currentChaffSelectedIndex, currentdir);

				 componentManagementFormEdit->ShowDialog();

				 ClearLists();

				 componentManagementFormEdit->Close();

				 LoadExistingCompLibFile();

				 UpdateLists();

				 ReloadComboBoxes(selectedReactor, selectedEngine, selectedBooster, selectedSheild, selectedFArmor, 
					 selectedRArmor, selectedDroid, selectedCapacitor, selectedOrdinance1, selectedOrdinance2, 
					 selectedOrdinance3, selectedWeapon1, selectedWeapon2, selectedWeapon3, selectedWeapon4, 
					 selectedChaff);
			 }
		 }

private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 AboutForm ^aboutForm = gcnew AboutForm;
			 aboutForm->ShowDialog();

			 aboutForm->Close();
		 }
private: System::Void RECalculatorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 RECalc ^reCalc = gcnew RECalc;
			 reCalc->ShowDialog();

			 reCalc->Close();
		 }
		 ///
		 /// Chassis Selection
		 ///
private: System::Void ShipChassisComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 switch (ShipChassisComboBox->SelectedIndex){
				 case 0:	ReactorOverloadComboBox->Enabled = false;
							EngineOverloadComboBox->Enabled = false;
							WeaponOverloadComboBox->Enabled = false;
							CapacitorOverloadComboBox->Enabled = false;
							break;

				 case 1:	ReactorOverloadComboBox->Enabled = false;
							EngineOverloadComboBox->Enabled = false;
							WeaponOverloadComboBox->Enabled = false;
							CapacitorOverloadComboBox->Enabled = false;
							break;

				 case 2:	ReactorOverloadComboBox->Enabled = false;
							EngineOverloadComboBox->Enabled = false;
							WeaponOverloadComboBox->Enabled = false;
							CapacitorOverloadComboBox->Enabled = false;
							break;

				 case 12:	ReactorOverloadComboBox->Enabled = false;
							EngineOverloadComboBox->Enabled = false;
							WeaponOverloadComboBox->Enabled = false;
							CapacitorOverloadComboBox->Enabled = false;
							break;

				 case 13:	ReactorOverloadComboBox->Enabled = false;
							EngineOverloadComboBox->Enabled = false;
							WeaponOverloadComboBox->Enabled = false;
							CapacitorOverloadComboBox->Enabled = false;
							break;
							
				 case 14:	ReactorOverloadComboBox->Enabled = false;
							EngineOverloadComboBox->Enabled = false;
							WeaponOverloadComboBox->Enabled = false;
							CapacitorOverloadComboBox->Enabled = false;
							break;

				 case 26:	ReactorOverloadComboBox->Enabled = false;
							EngineOverloadComboBox->Enabled = false;
							WeaponOverloadComboBox->Enabled = false;
							CapacitorOverloadComboBox->Enabled = false;
							break;

				 case 27:	ReactorOverloadComboBox->Enabled = false;
							EngineOverloadComboBox->Enabled = false;
							WeaponOverloadComboBox->Enabled = false;
							CapacitorOverloadComboBox->Enabled = false;
							break;

				 case 28:	ReactorOverloadComboBox->Enabled = false;
							EngineOverloadComboBox->Enabled = false;
							WeaponOverloadComboBox->Enabled = false;
							CapacitorOverloadComboBox->Enabled = false;
							break;

				 case 39:	ReactorOverloadComboBox->Enabled = false;
							EngineOverloadComboBox->Enabled = false;
							WeaponOverloadComboBox->Enabled = false;
							CapacitorOverloadComboBox->Enabled = false;
							break;

				 case 40:	ReactorOverloadComboBox->Enabled = false;
							EngineOverloadComboBox->Enabled = false;
							WeaponOverloadComboBox->Enabled = false;
							CapacitorOverloadComboBox->Enabled = false;
							break;

				 case 41:	ReactorOverloadComboBox->Enabled = false;
							EngineOverloadComboBox->Enabled = false;
							WeaponOverloadComboBox->Enabled = false;
							CapacitorOverloadComboBox->Enabled = false;
							break;

				 default:	ReactorOverloadComboBox->Enabled = true;
							EngineOverloadComboBox->Enabled = true;
							WeaponOverloadComboBox->Enabled = true;
							CapacitorOverloadComboBox->Enabled = true;
							break;
			 }

			 UpdateHardpoints();
		 }




		 ///
		 /// Reactor Selection
		 ///
private: System::Void ReactorComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentReactorSelectedIndex != ReactorComboBox->SelectedItem->ToString())
			 {
				 if (ReactorComboBox->Items->Count != 0)
				 {
					 System::Data::DataRow^ rowReactor;

					 if (ReactorComboBox->SelectedIndex != -1)
					 {
							 Reactor^ tempReactor = gcnew Reactor();
							 tempReactor = ReactorList[ReactorComboBox->SelectedIndex];

							 rowReactor = tempReactor[0];

							 R_ArmorValueLabel->Text = rowReactor["Armor"]->ToString();
							 R_MassValueLabel->Text = rowReactor["Mass"]->ToString();
							 R_GenerationValueLabel->Text = rowReactor["Generation"]->ToString();

							 currentReactorSelectedIndex = ReactorComboBox->SelectedItem->ToString();

							 compChanged = 'r';

							 double tempMass;
							 tempMass = Convert::ToDouble(rowReactor["Mass"]->ToString());
							 UpdateMass(tempMass, compChanged);
							 currentReactorMass = Convert::ToDouble(rowReactor["Mass"]->ToString());

							 currentReactorGeneration = Convert::ToDouble(rowReactor["Generation"]->ToString());
							 
							 CurrentROGen();

							 ReactorStatus();
							 EngineStatus();
							 SheildStatus();
							 FArmorStatus();
							 RArmorStatus();
						 	 CapacitorStatus();
							 BoosterStatus();
							 DroidStatus();
							 Weapon1Status();
							 Weapon2Status();
							 Weapon3Status();
							 Weapon4Status();
							 Ordinance1Status();
							 Ordinance2Status();
							 Ordinance3Status();
							 ChaffStatus();


							 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Engine Selection
		 ///
private: System::Void EngineComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentEngineSelectedIndex != EngineComboBox->SelectedItem->ToString())
			 {
				 if (EngineComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowEngine;

					 if (EngineComboBox->SelectedIndex != -1)
					 {
						 Engine^ tempEngine = gcnew Engine();
						 tempEngine = EngineList[EngineComboBox->SelectedIndex];

						 rowEngine = tempEngine[0];

						 E_ArmorValueLabel->Text = rowEngine["Armor"]->ToString();
						 E_MassValueLabel->Text = rowEngine["Mass"]->ToString();
						 E_DrainValueLabel->Text = rowEngine["Drain"]->ToString();
						 E_PitchValueLabel->Text = rowEngine["Pitch"]->ToString();
						 E_YawValueLabel->Text = rowEngine["Yaw"]->ToString();
						 E_RollValueLabel->Text = rowEngine["Roll"]->ToString();
						 E_SpeedValueLabel->Text = rowEngine["Top Speed"]->ToString();

						 currentEngineSelectedIndex = EngineComboBox->SelectedItem->ToString();

						 compChanged = 'e';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowEngine["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentEngineMass = Convert::ToDouble(rowEngine["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowEngine["Drain"]->ToString());

						 UpdateDrain(tempDrain, compChanged);
						 currentEngineDrain = Convert::ToDouble(rowEngine["Drain"]->ToString());
						 CurrentEODrain();

						 EngineStatus();
						 SheildStatus();
						 FArmorStatus();
						 RArmorStatus();
					 	 CapacitorStatus();
						 BoosterStatus();
						 DroidStatus();
						 Weapon1Status();
						 Weapon2Status();
						 Weapon3Status();
						 Weapon4Status();
						 Ordinance1Status();
						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Booster Selection
		 ///
private: System::Void BoosterComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentBoosterSelectedIndex != BoosterComboBox->SelectedItem->ToString())
			 {
				 if (BoosterComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowBooster;

					 if (BoosterComboBox->SelectedIndex != -1)
					 {
						 Booster^ tempBooster = gcnew Booster();
						 tempBooster = BoosterList[BoosterComboBox->SelectedIndex];

						 rowBooster = tempBooster[0];

						 B_ArmorValueLabel->Text = rowBooster["Armor"]->ToString();
						 B_MassValueLabel->Text = rowBooster["Mass"]->ToString();
						 B_DrainValueLabel->Text = rowBooster["Drain"]->ToString();
						 B_EnergyValueLabel->Text = rowBooster["Energy"]->ToString();
						 B_RechargeValueLabel->Text = rowBooster["Recharge"]->ToString();
						 B_ConsumptionValueLabel->Text = rowBooster["Consumption"]->ToString();
						 B_AccelerationValueLabel->Text = rowBooster["Acceleration"]->ToString();
						 B_SpeedValueLabel->Text = rowBooster["Top Speed"]->ToString();
						 
						 currentBoosterSelectedIndex = BoosterComboBox->SelectedItem->ToString();

						 compChanged = 'b';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowBooster["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentBoosterMass = Convert::ToDouble(rowBooster["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowBooster["Drain"]->ToString());

						 UpdateDrain(tempDrain, compChanged);
						 currentBoosterDrain = Convert::ToDouble(rowBooster["Drain"]->ToString());

						 BoosterStatus();
						 DroidStatus();
						 Weapon1Status();
						 Weapon2Status();
						 Weapon3Status();
						 Weapon4Status();
						 Ordinance1Status();
						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Sheild Selection
		 ///
private: System::Void SheildComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentSheildSelectedIndex != SheildComboBox->SelectedItem->ToString())
			 {
				 if (SheildComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowSheild;

					 if (SheildComboBox->SelectedIndex != -1)
					 {
						 Sheild^ tempSheild = gcnew Sheild();
						 tempSheild = SheildList[SheildComboBox->SelectedIndex];

						 rowSheild = tempSheild[0];

						 S_ArmorValueLabel->Text = rowSheild["Armor"]->ToString();
						 S_MassValueLabel->Text = rowSheild["Mass"]->ToString();
						 S_DrainValueLabel->Text = rowSheild["Drain"]->ToString();
						 S_FrontHPValueLabel->Text = rowSheild["Front HP"]->ToString();
						 S_BackHPValueLabel->Text = rowSheild["Back HP"]->ToString();
						 S_RechargeValueLabel->Text = rowSheild["Recharge"]->ToString();
						 switch (System::Convert::ToInt64(rowSheild["Adjustment"]->ToString()))
						 {
							 case 0: S_AdjustmentValueLabel->Text = "F/Extreme";
								 break;
							 case 1: S_AdjustmentValueLabel->Text = "F/Heavy";
								 break;
							 case 2: S_AdjustmentValueLabel->Text = "F/Moderate";
								 break;
							 case 3: S_AdjustmentValueLabel->Text = "F/Light";
								 break;
							 case 4: S_AdjustmentValueLabel->Text = "None";
								 break;
							 case 5: S_AdjustmentValueLabel->Text = "R/Light";
								 break;
							 case 6: S_AdjustmentValueLabel->Text = "R/Moderate";
								 break;
							 case 7: S_AdjustmentValueLabel->Text = "R/Heavy";
								 break;
							 case 8: S_AdjustmentValueLabel->Text = "R/Extreme";
								 break;
							 default: S_AdjustmentValueLabel->Text = "None";
								 break;
						 }
						 						 
						 currentSheildSelectedIndex = SheildComboBox->SelectedItem->ToString();

						 compChanged = 's';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowSheild["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentSheildMass = Convert::ToDouble(rowSheild["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowSheild["Drain"]->ToString());

						 UpdateDrain(tempDrain, compChanged);
						 currentSheildDrain = Convert::ToDouble(rowSheild["Drain"]->ToString());

						 SheildStatus();
						 FArmorStatus();
						 RArmorStatus();
					 	 CapacitorStatus();
						 BoosterStatus();
						 DroidStatus();
						 Weapon1Status();
						 Weapon2Status();
						 Weapon3Status();
						 Weapon4Status();
						 Ordinance1Status();
						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Front Armor Selection
		 ///
private: System::Void FArmorComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentFArmorSelectedIndex != FArmorComboBox->SelectedItem->ToString())
			 {
				 if (FArmorComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowArmor;

					 if (FArmorComboBox->SelectedIndex != -1)
					 {
						 Armor^ tempArmor = gcnew Armor();
						 tempArmor = ArmorList[FArmorComboBox->SelectedIndex];

						 rowArmor = tempArmor[0];

						 FA_ArmorValueLabel->Text = rowArmor["Armor"]->ToString();
						 FA_MassValueLabel->Text = rowArmor["Mass"]->ToString();

						 currentFArmorSelectedIndex = FArmorComboBox->SelectedItem->ToString();

						 compChanged = 'A';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowArmor["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentFArmorMass = Convert::ToDouble(rowArmor["Mass"]->ToString());

						 FArmorStatus();
						 RArmorStatus();
					 	 CapacitorStatus();
						 BoosterStatus();
						 DroidStatus();
						 Weapon1Status();
						 Weapon2Status();
						 Weapon3Status();
						 Weapon4Status();
						 Ordinance1Status();
						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Rear Armor Selection
		 ///
private: System::Void RArmorComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentRArmorSelectedIndex != RArmorComboBox->SelectedItem->ToString())
			 {
				 if (RArmorComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowArmor;

					 if (RArmorComboBox->SelectedIndex != -1)
					 {
						 Armor^ tempArmor = gcnew Armor();
						 tempArmor = ArmorList[RArmorComboBox->SelectedIndex];

						 rowArmor = tempArmor[0];

						 RA_ArmorValueLabel->Text = rowArmor["Armor"]->ToString();
						 RA_MassValueLabel->Text = rowArmor["Mass"]->ToString();

						 currentRArmorSelectedIndex = RArmorComboBox->SelectedItem->ToString();

						 compChanged = 'a';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowArmor["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentRArmorMass = Convert::ToDouble(rowArmor["Mass"]->ToString());

						 RArmorStatus();
					 	 CapacitorStatus();
						 BoosterStatus();
						 DroidStatus();
						 Weapon1Status();
						 Weapon2Status();
						 Weapon3Status();
						 Weapon4Status();
						 Ordinance1Status();
						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Droid Selection
		 ///
private: System::Void DroidComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentDroidSelectedIndex != DroidComboBox->SelectedItem->ToString())
			 {
				 if (DroidComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowDroid;

					 if (DroidComboBox->SelectedIndex != -1)
					 {
						 Droid^ tempDroid = gcnew Droid();
						 tempDroid = DroidList[DroidComboBox->SelectedIndex];

						 rowDroid = tempDroid[0];

						 D_ArmorValueLabel->Text = rowDroid["Armor"]->ToString();
						 D_MassValueLabel->Text = rowDroid["Mass"]->ToString();
						 D_DrainValueLabel->Text = rowDroid["Drain"]->ToString();
						 D_SpeedValueLabel->Text = rowDroid["Command Speed"]->ToString();

						 currentDroidSelectedIndex = DroidComboBox->SelectedItem->ToString();

						 compChanged = 'd';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowDroid["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentDroidMass = Convert::ToDouble(rowDroid["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowDroid["Drain"]->ToString());

						 UpdateDrain(tempDrain, compChanged);
						 currentDroidDrain = Convert::ToDouble(rowDroid["Drain"]->ToString());

						 DroidStatus();
						 Weapon1Status();
						 Weapon2Status();
						 Weapon3Status();
						 Weapon4Status();
						 Ordinance1Status();
						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Capacitor Selection
		 ///
private: System::Void CapacitorComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentCapacitorSelectedIndex != CapacitorComboBox->SelectedItem->ToString())
			 {
				 if (CapacitorComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowCapacitor;

					 if (CapacitorComboBox->SelectedIndex != -1)
					 {
						 Capacitor^ tempCapacitor = gcnew Capacitor();
						 tempCapacitor = CapacitorList[CapacitorComboBox->SelectedIndex];

						 rowCapacitor = tempCapacitor[0];

						 C_ArmorValueLabel->Text = rowCapacitor["Armor"]->ToString();
						 C_MassValueLabel->Text = rowCapacitor["Mass"]->ToString();
						 C_DrainValueLabel->Text = rowCapacitor["Drain"]->ToString();
						 C_EnergyValueLabel->Text = rowCapacitor["Energy"]->ToString();
						 C_RechargeValueLabel->Text = rowCapacitor["Recharge"]->ToString();

						 currentCapacitorSelectedIndex = CapacitorComboBox->SelectedItem->ToString();

						 compChanged = 'C';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowCapacitor["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentCapacitorMass = Convert::ToDouble(rowCapacitor["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowCapacitor["Drain"]->ToString());

						 UpdateDrain(tempDrain, compChanged);
						 currentCapacitorDrain = Convert::ToDouble(rowCapacitor["Drain"]->ToString());

						 CapacitorStatus();
						 BoosterStatus();
						 DroidStatus();
						 Weapon1Status();
						 Weapon2Status();
						 Weapon3Status();
						 Weapon4Status();
						 Ordinance1Status();
						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Ordinance 1 Selection
		 ///
private: System::Void Ordinance1ComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentOrdinance1SelectedIndex != Ordinance1ComboBox->SelectedItem->ToString())
			 {
				 if (Ordinance1ComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowOrdinance;

					 if (Ordinance1ComboBox->SelectedIndex != -1)
					 {
						 Ordinance^ tempOrdinance = gcnew Ordinance();
						 tempOrdinance = OrdinanceList[Ordinance1ComboBox->SelectedIndex];

						 rowOrdinance = tempOrdinance[0];

						 O1_ArmorValueLabel->Text = rowOrdinance["Armor"]->ToString();
						 O1_MassValueLabel->Text = rowOrdinance["Mass"]->ToString();
						 O1_DrainValueLabel->Text = rowOrdinance["Drain"]->ToString();
						 O1_MinDValueLabel->Text = rowOrdinance["Min Damage"]->ToString();
						 O1_MaxDValueLabel->Text = rowOrdinance["Max Damage"]->ToString();
						 O1_vsSValueLabel->Text = rowOrdinance["vs Sheilds"]->ToString();
						 O1_vsAValueLabel->Text = rowOrdinance["vs Armor"]->ToString();
						 O1_AmmoValueLabel->Text = rowOrdinance["Ammo"]->ToString();

						 currentOrdinance1SelectedIndex = Ordinance1ComboBox->SelectedItem->ToString();

						 compChanged = 'O';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowOrdinance["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentOrdinance1Mass = Convert::ToDouble(rowOrdinance["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowOrdinance["Drain"]->ToString());

						 UpdateDrain(tempDrain, compChanged);
						 currentOrdinance1Drain = Convert::ToDouble(rowOrdinance["Drain"]->ToString());
						 CurrentO1ODrain();

						 Ordinance1Status();
						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Ordinance 2 Selection
		 ///
private: System::Void Ordinance2ComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentOrdinance2SelectedIndex != Ordinance2ComboBox->SelectedItem->ToString())
			 {
				 if (Ordinance2ComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowOrdinance;

					 if (Ordinance2ComboBox->SelectedIndex != -1)
					 {
						 Ordinance^ tempOrdinance = gcnew Ordinance();
						 tempOrdinance = OrdinanceList[Ordinance2ComboBox->SelectedIndex];

						 rowOrdinance = tempOrdinance[0];

						 O2_ArmorValueLabel->Text = rowOrdinance["Armor"]->ToString();
						 O2_MassValueLabel->Text = rowOrdinance["Mass"]->ToString();
						 O2_DrainValueLabel->Text = rowOrdinance["Drain"]->ToString();
						 O2_MinDValueLabel->Text = rowOrdinance["Min Damage"]->ToString();
						 O2_MaxDValueLabel->Text = rowOrdinance["Max Damage"]->ToString();
						 O2_vsSValueLabel->Text = rowOrdinance["vs Sheilds"]->ToString();
						 O2_vsAValueLabel->Text = rowOrdinance["vs Armor"]->ToString();
						 O2_AmmoValueLabel->Text = rowOrdinance["Ammo"]->ToString();

						 currentOrdinance2SelectedIndex = Ordinance2ComboBox->SelectedItem->ToString();

						 compChanged = 'o';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowOrdinance["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentOrdinance2Mass = Convert::ToDouble(rowOrdinance["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowOrdinance["Drain"]->ToString());

						 UpdateDrain(tempDrain, compChanged);
						 currentOrdinance2Drain = Convert::ToDouble(rowOrdinance["Drain"]->ToString());
						 CurrentO2ODrain();

						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Ordinance 3 Selection
		 ///
private: System::Void Ordinance3ComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentOrdinance3SelectedIndex != Ordinance3ComboBox->SelectedItem->ToString())
			 {
				 if (Ordinance3ComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowOrdinance;

					 if (Ordinance3ComboBox->SelectedIndex != -1)
					 {
						 Ordinance^ tempOrdinance = gcnew Ordinance();
						 tempOrdinance = OrdinanceList[Ordinance3ComboBox->SelectedIndex];

						 rowOrdinance = tempOrdinance[0];

						 O3_ArmorValueLabel->Text = rowOrdinance["Armor"]->ToString();
						 O3_MassValueLabel->Text = rowOrdinance["Mass"]->ToString();
						 O3_DrainValueLabel->Text = rowOrdinance["Drain"]->ToString();
						 O3_MinDValueLabel->Text = rowOrdinance["Min Damage"]->ToString();
						 O3_MaxDValueLabel->Text = rowOrdinance["Max Damage"]->ToString();
						 O3_vsSValueLabel->Text = rowOrdinance["vs Sheilds"]->ToString();
						 O3_vsAValueLabel->Text = rowOrdinance["vs Armor"]->ToString();
						 O3_AmmoValueLabel->Text = rowOrdinance["Ammo"]->ToString();

						 currentOrdinance3SelectedIndex = Ordinance3ComboBox->SelectedItem->ToString();

						 compChanged = '0';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowOrdinance["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentOrdinance3Mass = Convert::ToDouble(rowOrdinance["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowOrdinance["Drain"]->ToString());

						 UpdateDrain(tempDrain, compChanged);
						 currentOrdinance3Drain = Convert::ToDouble(rowOrdinance["Drain"]->ToString());
						 CurrentO3ODrain();

						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Weapon 1 Selection
		 ///
private: System::Void Weapon1ComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentWeapon1SelectedIndex != Weapon1ComboBox->SelectedItem->ToString())
			 {
				 if (Weapon1ComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowWeapon;

					 if (Weapon1ComboBox->SelectedIndex != -1)
					 {
						 Weapon^ tempWeapon = gcnew Weapon();
						 tempWeapon = WeaponList[Weapon1ComboBox->SelectedIndex];

						 rowWeapon = tempWeapon[0];

						 W1_ArmorValueLabel->Text = rowWeapon["Armor"]->ToString();
						 W1_MassValueLabel->Text = rowWeapon["Mass"]->ToString();
						 W1_DrainValueLabel->Text = rowWeapon["Drain"]->ToString();
						 W1_MinDValueLabel->Text = rowWeapon["Min Damage"]->ToString();
						 W1_MaxDValueLabel->Text = rowWeapon["Max Damage"]->ToString();
						 W1_vsSValueLabel->Text = rowWeapon["vs Sheilds"]->ToString();
						 W1_vsAValueLabel->Text = rowWeapon["vs Armor"]->ToString();
						 W1_EPSValueLabel->Text = rowWeapon["EPS"]->ToString();
						 W1_RefireValueLabel->Text = rowWeapon["Refire"]->ToString();

						 currentWeapon1SelectedIndex = Weapon1ComboBox->SelectedItem->ToString();

						 compChanged = '1';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowWeapon["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentWeapon1Mass = Convert::ToDouble(rowWeapon["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowWeapon["Drain"]->ToString());

						 UpdateDrain(tempDrain, compChanged);
						 currentWeapon1Drain = Convert::ToDouble(rowWeapon["Drain"]->ToString());
						 CurrentW1ODrain();

						 Weapon1Status();
						 Weapon2Status();
						 Weapon3Status();
						 Weapon4Status();
						 Ordinance1Status();
						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Weapon 2 Selection
		 ///
private: System::Void Weapon2ComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentWeapon2SelectedIndex != Weapon2ComboBox->SelectedItem->ToString())
			 {
				 if (Weapon2ComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowWeapon;

					 if (Weapon2ComboBox->SelectedIndex != -1)
					 {
						 Weapon^ tempWeapon = gcnew Weapon();
						 tempWeapon = WeaponList[Weapon2ComboBox->SelectedIndex];

						 rowWeapon = tempWeapon[0];

						 W2_ArmorValueLabel->Text = rowWeapon["Armor"]->ToString();
						 W2_MassValueLabel->Text = rowWeapon["Mass"]->ToString();
						 W2_DrainValueLabel->Text = rowWeapon["Drain"]->ToString();
						 W2_MinDValueLabel->Text = rowWeapon["Min Damage"]->ToString();
						 W2_MaxDValueLabel->Text = rowWeapon["Max Damage"]->ToString();
						 W2_vsSValueLabel->Text = rowWeapon["vs Sheilds"]->ToString();
						 W2_vsAValueLabel->Text = rowWeapon["vs Armor"]->ToString();
						 W2_EPSValueLabel->Text = rowWeapon["EPS"]->ToString();
						 W2_RefireValueLabel->Text = rowWeapon["Refire"]->ToString();

						 currentWeapon2SelectedIndex = Weapon2ComboBox->SelectedItem->ToString();

						 compChanged = '2';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowWeapon["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentWeapon2Mass = Convert::ToDouble(rowWeapon["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowWeapon["Drain"]->ToString());

						 UpdateDrain(tempDrain, compChanged);
						 currentWeapon2Drain = Convert::ToDouble(rowWeapon["Drain"]->ToString());
						 CurrentW2ODrain();

						 Weapon2Status();
						 Weapon3Status();
						 Weapon4Status();
						 Ordinance1Status();
						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Weapon 3 Selection
		 ///
private: System::Void Weapon3ComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentWeapon3SelectedIndex != Weapon3ComboBox->SelectedItem->ToString())
			 {
				 if (Weapon3ComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowWeapon;

					 if (Weapon3ComboBox->SelectedIndex != -1)
					 {
						 Weapon^ tempWeapon = gcnew Weapon();
						 tempWeapon = WeaponList[Weapon3ComboBox->SelectedIndex];

						 rowWeapon = tempWeapon[0];

						 W3_ArmorValueLabel->Text = rowWeapon["Armor"]->ToString();
						 W3_MassValueLabel->Text = rowWeapon["Mass"]->ToString();
						 W3_DrainValueLabel->Text = rowWeapon["Drain"]->ToString();
						 W3_MinDValueLabel->Text = rowWeapon["Min Damage"]->ToString();
						 W3_MaxDValueLabel->Text = rowWeapon["Max Damage"]->ToString();
						 W3_vsSValueLabel->Text = rowWeapon["vs Sheilds"]->ToString();
						 W3_vsAValueLabel->Text = rowWeapon["vs Armor"]->ToString();
						 W3_EPSValueLabel->Text = rowWeapon["EPS"]->ToString();
						 W3_RefireValueLabel->Text = rowWeapon["Refire"]->ToString();

						 currentWeapon3SelectedIndex = Weapon3ComboBox->SelectedItem->ToString();

						 compChanged = '3';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowWeapon["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentWeapon3Mass = Convert::ToDouble(rowWeapon["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowWeapon["Drain"]->ToString());

						 UpdateDrain(tempDrain, compChanged);
						 currentWeapon3Drain = Convert::ToDouble(rowWeapon["Drain"]->ToString());
						 CurrentW3ODrain();

						 Weapon3Status();
						 Weapon4Status();
						 Ordinance1Status();
						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Weapon 4 Selection
		 ///
private: System::Void Weapon4ComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentWeapon4SelectedIndex != Weapon4ComboBox->SelectedItem->ToString())
			 {
				 if (Weapon4ComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowWeapon;

					 if (Weapon4ComboBox->SelectedIndex != -1)
					 {
						 Weapon^ tempWeapon = gcnew Weapon();
						 tempWeapon = WeaponList[Weapon4ComboBox->SelectedIndex];

						 rowWeapon = tempWeapon[0];

						 W4_ArmorValueLabel->Text = rowWeapon["Armor"]->ToString();
						 W4_MassValueLabel->Text = rowWeapon["Mass"]->ToString();
						 W4_DrainValueLabel->Text = rowWeapon["Drain"]->ToString();
						 W4_MinDValueLabel->Text = rowWeapon["Min Damage"]->ToString();
						 W4_MaxDValueLabel->Text = rowWeapon["Max Damage"]->ToString();
						 W4_vsSValueLabel->Text = rowWeapon["vs Sheilds"]->ToString();
						 W4_vsAValueLabel->Text = rowWeapon["vs Armor"]->ToString();
						 W4_EPSValueLabel->Text = rowWeapon["EPS"]->ToString();
						 W4_RefireValueLabel->Text = rowWeapon["Refire"]->ToString();

						 currentWeapon4SelectedIndex = Weapon4ComboBox->SelectedItem->ToString();

						 compChanged = '4';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowWeapon["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentWeapon4Mass = Convert::ToDouble(rowWeapon["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowWeapon["Drain"]->ToString());

						 UpdateDrain(tempDrain, compChanged);
						 currentWeapon4Drain = Convert::ToDouble(rowWeapon["Drain"]->ToString());
						 CurrentW4ODrain();

						 Weapon4Status();
						 Ordinance1Status();
						 Ordinance2Status();
						 Ordinance3Status();
						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }

		 ///
		 /// Chaff Selection
		 ///
private: System::Void CountermeasuresComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (currentChaffSelectedIndex != CountermeasuresComboBox->SelectedItem->ToString())
			 {
				 if (CountermeasuresComboBox->Items->Count != 0){
					 System::Data::DataRow^ rowChaff;

					 if (CountermeasuresComboBox->SelectedIndex != -1)
					 {
						 Chaff^ tempChaff = gcnew Chaff();
						 tempChaff = ChaffList[CountermeasuresComboBox->SelectedIndex];

						 rowChaff = tempChaff[0];

						 CM_ArmorValueLabel->Text = rowChaff["Armor"]->ToString();
						 CM_MassValueLabel->Text = rowChaff["Mass"]->ToString();
						 CM_DrainValueLabel->Text = rowChaff["Drain"]->ToString();

						 currentChaffSelectedIndex = CountermeasuresComboBox->SelectedItem->ToString();

						 compChanged = 'c';

						 double tempMass;
						 tempMass = Convert::ToDouble(rowChaff["Mass"]->ToString());
						 UpdateMass(tempMass, compChanged);
						 currentChaffMass = Convert::ToDouble(rowChaff["Mass"]->ToString());

						 double tempDrain;

						 tempDrain = Convert::ToDouble(rowChaff["Drain"]->ToString());
						 tempDrain = (tempDrain / 2);

						 UpdateDrain(tempDrain, compChanged);
						 currentChaffDrain = Convert::ToDouble(rowChaff["Drain"]->ToString());
						 currentChaffDrain = (currentChaffDrain / 2);
						 //CurrentChaffODrain();

						 ChaffStatus();

						 changesMade = true;
					 }
				 }
			 }
		 }
		 ///
		 /// Other Event Handlers
		 ///
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void saveShiploadoutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ShipInfo^ shipInfo = gcnew ShipInfo();

			 shipInfo->AddShip(ShipNameValueLabel->Text->ToString(), Convert::ToInt32(ShipChassisComboBox->SelectedIndex), Convert::ToDouble(TotalShipMassValueLabel->Text->ToString()),
				 Convert::ToInt32(ReactorOverloadComboBox->SelectedIndex), Convert::ToInt32(EngineOverloadComboBox->SelectedIndex), Convert::ToInt32(WeaponOverloadComboBox->SelectedIndex),
				 Convert::ToInt32(CapacitorOverloadComboBox->SelectedIndex), ReactorComboBox->SelectedItem->ToString(), EngineComboBox->SelectedItem->ToString(), 
				 BoosterComboBox->SelectedItem->ToString(), SheildComboBox->SelectedItem->ToString(), FArmorComboBox->SelectedItem->ToString(), 
				 RArmorComboBox->SelectedItem->ToString(), DroidComboBox->SelectedItem->ToString(), CapacitorComboBox->SelectedItem->ToString(), 
				 Weapon1ComboBox->SelectedItem->ToString(), Weapon2ComboBox->SelectedItem->ToString(), Weapon3ComboBox->SelectedItem->ToString(), 
				 Weapon4ComboBox->SelectedItem->ToString(), Ordinance1ComboBox->SelectedItem->ToString(), Ordinance2ComboBox->SelectedItem->ToString(), 
				 Ordinance3ComboBox->SelectedItem->ToString(), CountermeasuresComboBox->SelectedItem->ToString());

			 shipInfo->TableName = String::Concat("Ship_", ShipChassisComboBox->SelectedItem->ToString(), "_", ShipNameValueLabel->Text->ToString());

			 List<ShipInfo^>^ shipInfoList = gcnew List<ShipInfo^>();

			 shipInfoList->Add(shipInfo);

			 if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 CompLib::XMLUtilities::CreateShipInfoFile(saveFileDialog1->FileName, "pilotname", shipInfoList->ToArray());
				 changesMade = false;
			 }
		 }
private: System::Void newShipToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (changesMade == true)
			 {
				 if (MessageBox::Show("You have made unsaved changes, this action will cause you to lose your changes. Do you wish to continue?", 
					 "Unsaved Changes Made", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::Yes)
				 {
					 ShipNamePrompt ^nameForm = gcnew ShipNamePrompt;

					 if (nameForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					 {
						 ShipChassisComboBox->Enabled = true;
						 TotalShipMassValueLabel->Text = "";
						 
						 ShipNameValueLabel->Text = nameForm->ShipName;
						 TotalShipMassValueLabel->Text = nameForm->ShipMass;

						 ShipChassisComboBox->SelectedIndex = 3;
						 
						 Reset();

						 this->Text = String::Concat(nameForm->ShipName, " || ", "Ship Loadout Utility v 0.1");

						 shipStatisticsToolStripMenuItem->Enabled = true;
						 saveShiploadoutToolStripMenuItem->Enabled = true;
						 closeShipLoadoutToolStripMenuItem->Enabled = true;
					 }
				 }
				 else
				 {
					 this->Invalidate();
				 }
			 }
			 else
			 {
				 ShipNamePrompt ^nameForm = gcnew ShipNamePrompt;

				 if (nameForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 ShipChassisComboBox->Enabled = true;
					 TotalShipMassValueLabel->Text = "";
					 
					 ShipNameValueLabel->Text = nameForm->ShipName;
					 TotalShipMassValueLabel->Text = nameForm->ShipMass;

					 ShipChassisComboBox->SelectedIndex = 3;

					 Reset();

					 this->Text = String::Concat(nameForm->ShipName, " || ", "Ship Loadout Utility v 0.1");

					 shipStatisticsToolStripMenuItem->Enabled = true;
					 saveShiploadoutToolStripMenuItem->Enabled = true;
					 closeShipLoadoutToolStripMenuItem->Enabled = true;
				 }
			 }
		 }
private: System::Void openShipToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		    if (changesMade == true)
			{
				 if (MessageBox::Show("You have made unsaved changes, this action will cause you to lose your changes. Do you wish to continue?", 
					 "Unsaved Changes Made", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::Yes)
				 {
					ShipInfoList->Clear();

					array<CompLib::ShipInfo^>^ tempShipInfo;

					openFileDialog1->FileName = "";

					if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					{
						String^ pilotName;

						pilotName = CompLib::XMLUtilities::OpenShipInfoFile(openFileDialog1->FileName, tempShipInfo);

						Reset();

						ShipChassisComboBox->Enabled = true;
						ReactorPanel->Enabled = true;
						EnginePanel->Enabled = true;
						ArmorPanel->Enabled = true;
						BoosterPanel->Enabled = true;
						CapacitorPanel->Enabled = true;
						DroidPanel->Enabled = true;
						CountermeasuresPanel->Enabled = true;
						Ordinance1Panel->Enabled = true;
						Ordinance2Panel->Enabled = true;
  						Ordinance3Panel->Enabled = true;
						Weapon1Panel->Enabled = true;
						Weapon2Panel->Enabled = true;
						Weapon3Panel->Enabled = true;
						Weapon4Panel->Enabled = true;
						SheildPanel->Enabled = true;
						ReactorOverloadComboBox->Enabled = true;
						EngineOverloadComboBox->Enabled = true;
						WeaponOverloadComboBox->Enabled = true;
						CapacitorOverloadComboBox->Enabled = true;

						for (int i=0; i<tempShipInfo->Length; i++)
						{
							ShipInfoList->Add(tempShipInfo[i]);
						}

						System::Data::DataRow^ rowShip;

						ShipInfo^ tempShip = gcnew ShipInfo();
						tempShip = ShipInfoList[0];

						rowShip = tempShip[0];

						ShipNameValueLabel->Text = rowShip["Name"]->ToString();
						TotalShipMassValueLabel->Text = rowShip["Mass"]->ToString();
						ShipChassisComboBox->SelectedIndex = Convert::ToInt32(rowShip["Chassis"]->ToString());

						ReactorOverloadComboBox->SelectedIndex = Convert::ToInt32(rowShip["Reactor Overload"]->ToString());
						EngineOverloadComboBox->SelectedIndex = Convert::ToInt32(rowShip["Engine Overload"]->ToString());
						WeaponOverloadComboBox->SelectedIndex = Convert::ToInt32(rowShip["Weapon Overload"]->ToString());
						CapacitorOverloadComboBox->SelectedIndex = Convert::ToInt32(rowShip["Capacitor Overload"]->ToString());

						ReactorComboBox->SelectedItem = rowShip["Loaded Reactor"]->ToString();
						EngineComboBox->SelectedItem = rowShip["Loaded Engine"]->ToString();
						FArmorComboBox->SelectedItem = rowShip["Loaded Front Armor"]->ToString();
						RArmorComboBox->SelectedItem = rowShip["Loaded Rear Armor"]->ToString();
						BoosterComboBox->SelectedItem = rowShip["Loaded Booster"]->ToString();
						CapacitorComboBox->SelectedItem = rowShip["Loaded Capacitor"]->ToString();
						DroidComboBox->SelectedItem = rowShip["Loaded Droid"]->ToString();
						CountermeasuresComboBox->SelectedItem = rowShip["Loaded Chaff"]->ToString();
						Ordinance1ComboBox->SelectedItem = rowShip["Loaded Ordinance 1"]->ToString();
						Ordinance2ComboBox->SelectedItem = rowShip["Loaded Ordinance 2"]->ToString();
						Ordinance3ComboBox->SelectedItem = rowShip["Loaded Ordinance 3"]->ToString();
						Weapon1ComboBox->SelectedItem = rowShip["Loaded Weapon 1"]->ToString();
						Weapon2ComboBox->SelectedItem = rowShip["Loaded Weapon 2"]->ToString();
						Weapon3ComboBox->SelectedItem = rowShip["Loaded Weapon 3"]->ToString();
						Weapon4ComboBox->SelectedItem = rowShip["Loaded Weapon 4"]->ToString();
						SheildComboBox->SelectedItem = rowShip["Loaded Sheild"]->ToString();

						ShipChassisComboBox->Enabled = false;

						this->Text = String::Concat(rowShip["Name"]->ToString(), " || ", "Ship Loadout Utility v 0.1");

						shipStatisticsToolStripMenuItem->Enabled = true;
						saveShiploadoutToolStripMenuItem->Enabled = true;
						closeShipLoadoutToolStripMenuItem->Enabled = true;

						changesMade = false;
					}
				 }
				 else
				 {
					 this->Invalidate();
				 }
			}
			else
			{
				ShipInfoList->Clear();

				array<CompLib::ShipInfo^>^ tempShipInfo;

				openFileDialog1->FileName = "";

				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					String^ pilotName;

					pilotName = CompLib::XMLUtilities::OpenShipInfoFile(openFileDialog1->FileName, tempShipInfo);

					Reset();

					ShipChassisComboBox->Enabled = true;
					ReactorPanel->Enabled = true;
					EnginePanel->Enabled = true;
					ArmorPanel->Enabled = true;
					BoosterPanel->Enabled = true;
					CapacitorPanel->Enabled = true;
					DroidPanel->Enabled = true;
					CountermeasuresPanel->Enabled = true;
					Ordinance1Panel->Enabled = true;
					Ordinance2Panel->Enabled = true;
					Ordinance3Panel->Enabled = true;
					Weapon1Panel->Enabled = true;
					Weapon2Panel->Enabled = true;
					Weapon3Panel->Enabled = true;
					Weapon4Panel->Enabled = true;
					SheildPanel->Enabled = true;
					ReactorOverloadComboBox->Enabled = true;
					EngineOverloadComboBox->Enabled = true;
					WeaponOverloadComboBox->Enabled = true;
					CapacitorOverloadComboBox->Enabled = true;

					for (int i=0; i<tempShipInfo->Length; i++)
					{
						ShipInfoList->Add(tempShipInfo[i]);
					}

					System::Data::DataRow^ rowShip;

					ShipInfo^ tempShip = gcnew ShipInfo();
					tempShip = ShipInfoList[0];

					rowShip = tempShip[0];

					ShipNameValueLabel->Text = rowShip["Name"]->ToString();
					TotalShipMassValueLabel->Text = rowShip["Mass"]->ToString();
					ShipChassisComboBox->SelectedIndex = Convert::ToInt32(rowShip["Chassis"]->ToString());

					ReactorOverloadComboBox->SelectedIndex = Convert::ToInt32(rowShip["Reactor Overload"]->ToString());
					EngineOverloadComboBox->SelectedIndex = Convert::ToInt32(rowShip["Engine Overload"]->ToString());
					WeaponOverloadComboBox->SelectedIndex = Convert::ToInt32(rowShip["Weapon Overload"]->ToString());
					CapacitorOverloadComboBox->SelectedIndex = Convert::ToInt32(rowShip["Capacitor Overload"]->ToString());

					ReactorComboBox->SelectedItem = rowShip["Loaded Reactor"]->ToString();
					EngineComboBox->SelectedItem = rowShip["Loaded Engine"]->ToString();
					FArmorComboBox->SelectedItem = rowShip["Loaded Front Armor"]->ToString();
					RArmorComboBox->SelectedItem = rowShip["Loaded Rear Armor"]->ToString();
					BoosterComboBox->SelectedItem = rowShip["Loaded Booster"]->ToString();
					CapacitorComboBox->SelectedItem = rowShip["Loaded Capacitor"]->ToString();
					DroidComboBox->SelectedItem = rowShip["Loaded Droid"]->ToString();
					CountermeasuresComboBox->SelectedItem = rowShip["Loaded Chaff"]->ToString();
					Ordinance1ComboBox->SelectedItem = rowShip["Loaded Ordinance 1"]->ToString();
					Ordinance2ComboBox->SelectedItem = rowShip["Loaded Ordinance 2"]->ToString();
					Ordinance3ComboBox->SelectedItem = rowShip["Loaded Ordinance 3"]->ToString();
					Weapon1ComboBox->SelectedItem = rowShip["Loaded Weapon 1"]->ToString();
					Weapon2ComboBox->SelectedItem = rowShip["Loaded Weapon 2"]->ToString();
					Weapon3ComboBox->SelectedItem = rowShip["Loaded Weapon 3"]->ToString();
					Weapon4ComboBox->SelectedItem = rowShip["Loaded Weapon 4"]->ToString();
					SheildComboBox->SelectedItem = rowShip["Loaded Sheild"]->ToString();

					ShipChassisComboBox->Enabled = false;

					this->Text = String::Concat(rowShip["Name"]->ToString(), " || ", "Ship Loadout Utility v 0.1");

					shipStatisticsToolStripMenuItem->Enabled = true;
					saveShiploadoutToolStripMenuItem->Enabled = true;
					closeShipLoadoutToolStripMenuItem->Enabled = true;

					changesMade = false;
				}
			}
		}
private: System::Void closeShipLoadoutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (changesMade == true)
			 {
				 if (MessageBox::Show("You have made unsaved changes, this action will cause you to lose your changes. Do you wish to continue?", 
					 "Unsaved Changes Made", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::Yes)
				 {
					 ShipChassisComboBox->Enabled = false;
					 ReactorPanel->Enabled = false;
					 EnginePanel->Enabled = false;
					 ArmorPanel->Enabled = false;
					 BoosterPanel->Enabled = false;
					 CapacitorPanel->Enabled = false;
					 DroidPanel->Enabled = false;
					 CountermeasuresPanel->Enabled = false;
					 Ordinance1Panel->Enabled = false;
					 Ordinance2Panel->Enabled = false;
		  			 Ordinance3Panel->Enabled = false;
					 Weapon1Panel->Enabled = false;
					 Weapon2Panel->Enabled = false;
					 Weapon3Panel->Enabled = false;
					 Weapon4Panel->Enabled = false;
					 SheildPanel->Enabled = false;
					 ReactorOverloadComboBox->Enabled = false;
					 EngineOverloadComboBox->Enabled = false;
					 WeaponOverloadComboBox->Enabled = false;
					 CapacitorOverloadComboBox->Enabled = false;

					 ShipNameValueLabel->Text = "No ship created.";
					 TotalShipMassValueLabel->Text = "0.0";
					
					 Reset();

					 this->Text = "Ship Loadout Utility v 0.1";

					 changesMade = false;
				 }
				 else
				 {
					 this->Invalidate();
				 }
			 }
			 else
			 {
				 ShipChassisComboBox->Enabled = false;
				 ReactorPanel->Enabled = false;
				 EnginePanel->Enabled = false;
				 ArmorPanel->Enabled = false;
				 BoosterPanel->Enabled = false;
				 CapacitorPanel->Enabled = false;
				 DroidPanel->Enabled = false;
				 CountermeasuresPanel->Enabled = false;
				 Ordinance1Panel->Enabled = false;
				 Ordinance2Panel->Enabled = false;
	  			 Ordinance3Panel->Enabled = false;
				 Weapon1Panel->Enabled = false;
				 Weapon2Panel->Enabled = false;
				 Weapon3Panel->Enabled = false;
				 Weapon4Panel->Enabled = false;
				 SheildPanel->Enabled = false;
				 ReactorOverloadComboBox->Enabled = false;
				 EngineOverloadComboBox->Enabled = false;
				 WeaponOverloadComboBox->Enabled = false;
				 CapacitorOverloadComboBox->Enabled = false;

				 ShipNameValueLabel->Text = "No ship created.";
				 TotalShipMassValueLabel->Text = "0.0";
				
				 Reset();

				 this->Text = "Ship Loadout Utility v 0.1";

				 changesMade = false;
			 }
		 }
private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 if (changesMade == true)
			 {
				 if (MessageBox::Show("You have made unsaved changes. This action will cause you to lose those changes. Do you wish to continue?", 
						 "Unsaved Changes Made", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::Yes)
				 {
					 CloseForm();
				 }
				 else
				 {
					 e->Cancel = true;
				 }
			 }
			 else
			 {
				 CloseForm();
			 }
		 }
		 ///
		 /// Overload Event Handlers
		 ///
private: System::Void ReactorOverloadComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 CurrentROGen();

			 ReactorStatus();
			 EngineStatus();
			 SheildStatus();
			 FArmorStatus();
			 RArmorStatus();
		 	 CapacitorStatus();
			 BoosterStatus();
			 DroidStatus();
			 Weapon1Status();
			 Weapon2Status();
			 Weapon3Status();
			 Weapon4Status();
			 Ordinance1Status();
			 Ordinance2Status();
			 Ordinance3Status();
			 ChaffStatus();

			 changesMade = true;
		 }
private: System::Void EngineOverloadComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 compChanged = 'e';
			 UpdateDrain(currentEngineDrain, compChanged);
			 CurrentEODrain();

			 EngineStatus();
			 SheildStatus();
			 FArmorStatus();
			 RArmorStatus();
		 	 CapacitorStatus();
			 BoosterStatus();
			 DroidStatus();
			 Weapon1Status();
			 Weapon2Status();
			 Weapon3Status();
			 Weapon4Status();
			 Ordinance1Status();
			 Ordinance2Status();
			 Ordinance3Status();
			 ChaffStatus();

			 changesMade = true;
		 }
private: System::Void WeaponOverloadComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 compChanged = 'O';
			 UpdateDrain(currentOrdinance1Drain, compChanged);
			 CurrentO1ODrain();

			 compChanged = 'o';
			 UpdateDrain(currentOrdinance2Drain, compChanged);
			 CurrentO2ODrain();

			 compChanged = '0';
			 UpdateDrain(currentOrdinance3Drain, compChanged);
			 CurrentO3ODrain();

			 compChanged = '1';
			 UpdateDrain(currentWeapon1Drain, compChanged);
			 CurrentW1ODrain();

			 compChanged = '2';
			 UpdateDrain(currentWeapon2Drain, compChanged);
			 CurrentW2ODrain();

			 compChanged = '3';
			 UpdateDrain(currentWeapon3Drain, compChanged);
			 CurrentW3ODrain();

			 compChanged = '4';
			 UpdateDrain(currentWeapon4Drain, compChanged);
			 CurrentW4ODrain();

			 Weapon1Status();
			 Weapon2Status();
			 Weapon3Status();
			 Weapon4Status();
			 Ordinance1Status();
			 Ordinance2Status();
			 Ordinance3Status();
			 ChaffStatus();

			 changesMade = true;
		 }
private: System::Void CapacitorOverloadComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 changesMade = true;
		 }
};
}

