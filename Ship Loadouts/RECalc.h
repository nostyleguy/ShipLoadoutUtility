#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ShipLoadouts {

	/// <summary>
	/// Summary for RECalc
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class RECalc : public System::Windows::Forms::Form
	{
	public:
		RECalc(void)
		{
			InitializeComponent();

			height = this->Height;

			ReactorPanel->Hide();
			CalcReactorButton->Enabled = false;

			EnginePanel->Hide();
			CalcEngineButton->Enabled = false;

			BoosterPanel->Hide();
			CalcBoosterButton->Enabled = false;

			SheildPanel->Hide();
			CalcSheildButton->Enabled = false;

			ArmorPanel->Hide();
			CalcArmorButton->Enabled = false;

			DroidPanel->Hide();
			CalcDroidButton->Enabled = false;

			CapacitorPanel->Hide();
			CalcCapacitorButton->Enabled = false;

			WeaponPanel->Hide();
			CalcWeaponButton->Enabled = false;

			this->Height = height - 320;

			compInfoheight = this->Height;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RECalc()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region RECalcForm Item Decerations

	private: System::Windows::Forms::Panel^  CompInfoPanel;
	private: System::Windows::Forms::Label^  CompLevel;
	private: System::Windows::Forms::ComboBox^  CompTypeComboBox;
	private: System::Windows::Forms::ComboBox^  CompLevelComboBox;
	private: System::Windows::Forms::Label^  CompType;

	private: System::Windows::Forms::Panel^  WeaponPanel;
	private: System::Windows::Forms::Label^  WeaponOutputLabel;
	private: System::Windows::Forms::Label^  WeaponInputLabel;
	private: System::Windows::Forms::Label^  W_RefireLabel;
	private: System::Windows::Forms::TextBox^  WeaponFormRefireTextBox;
	private: System::Windows::Forms::Label^  W_EPSLabel;
	private: System::Windows::Forms::TextBox^  WeaponFormEPSTextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormvsATextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormvsSTextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormMaxDTextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormMinDTextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormMassTextBox;
	private: System::Windows::Forms::TextBox^  WeaponFormArmorTextBox;
	private: System::Windows::Forms::Label^  W_vsALabel;
	private: System::Windows::Forms::Label^  W_vsSLabel;
	private: System::Windows::Forms::Label^  W_MaxDLabel;
	private: System::Windows::Forms::Label^  W_MinDLabel;
	private: System::Windows::Forms::Label^  W_DrainLabel;
	private: System::Windows::Forms::Label^  W_MassLabel;
	private: System::Windows::Forms::Label^  W_ArmorLabel;
	private: System::Windows::Forms::Label^  W_RefireOutputValueLabel;
	private: System::Windows::Forms::Label^  W_EPSOutputValueLabel;
	private: System::Windows::Forms::Label^  W_vsAOutputValueLabel;
	private: System::Windows::Forms::Label^  W_vsSOutputValueLabel;
	private: System::Windows::Forms::Label^  W_MaxDOutputValueLabel;
	private: System::Windows::Forms::Label^  W_MinDOutputValueLabel;
	private: System::Windows::Forms::Label^  W_DrainOutputValueLabel;
	private: System::Windows::Forms::Label^  W_MassOutputValueLabel;
	private: System::Windows::Forms::Label^  W_ArmorOutputValueLabel;
	private: System::Windows::Forms::Label^  W_RefireOutputLabel;
	private: System::Windows::Forms::Label^  W_EPSOutputLabel;
	private: System::Windows::Forms::Label^  W_vsAOutputLabel;
	private: System::Windows::Forms::Label^  W_vsSOutputLabel;
	private: System::Windows::Forms::Label^  W_MaxDOutputLabel;
	private: System::Windows::Forms::Label^  W_MinDOutputLabel;
	private: System::Windows::Forms::Label^  W_DrainOutputLabel;
	private: System::Windows::Forms::Label^  W_MassOutputLabel;
	private: System::Windows::Forms::Label^  W_ArmorOutputLabel;
	private: System::Windows::Forms::Button^  CalcWeaponButton;

	private: System::Windows::Forms::Panel^  ReactorPanel;
	private: System::Windows::Forms::Label^  ReactorOutputLabel;
	private: System::Windows::Forms::Label^  ReactorInputLabel;
	private: System::Windows::Forms::TextBox^  ReactorFormGenerationTextBox;
	private: System::Windows::Forms::TextBox^  ReactorFormMassTextBox;
	private: System::Windows::Forms::TextBox^  ReactorFormArmorTextBox;
	private: System::Windows::Forms::Label^  R_GenerationLabel;
	private: System::Windows::Forms::Label^  R_MassLabel;
	private: System::Windows::Forms::Label^  R_ArmorLabel;
	private: System::Windows::Forms::Label^  R_GenerationOutputValueLabel;
	private: System::Windows::Forms::Label^  R_MassOutputValueLabel;
	private: System::Windows::Forms::Label^  R_ArmorOutputValueLabel;
	private: System::Windows::Forms::Label^  R_GenerationOutputLabel;
	private: System::Windows::Forms::Label^  R_MassOutputLabel;
	private: System::Windows::Forms::Label^  R_ArmorOutputLabel;
	private: System::Windows::Forms::Button^  CalcReactorButton;

	private: System::Windows::Forms::Panel^  ArmorPanel;
	private: System::Windows::Forms::TextBox^  ArmorFormMassTextBox;
	private: System::Windows::Forms::TextBox^  ArmorFormArmorTextBox;
	private: System::Windows::Forms::Label^  A_MassLabel;
	private: System::Windows::Forms::Label^  A_ArmorLabel;
	private: System::Windows::Forms::Label^  ArmorOutputLabel;
	private: System::Windows::Forms::Label^  ArmorInput;
	private: System::Windows::Forms::Button^  CalcArmorButton;
	private: System::Windows::Forms::Label^  A_MassOutputValueLabel;
	private: System::Windows::Forms::Label^  A_ArmorOutputValueLabel;
	private: System::Windows::Forms::Label^  A_MassOutputLabel;
	private: System::Windows::Forms::Label^  A_ArmorOutputLabel;
	private: System::Windows::Forms::Button^  ClearWeaponButton;
	private: System::Windows::Forms::Button^  ClearReactorButton;
	private: System::Windows::Forms::Button^  ClearArmorButton;

	private: System::Windows::Forms::Panel^  EnginePanel;
	private: System::Windows::Forms::Button^  ClearEngineButton;
	private: System::Windows::Forms::Button^  CalcEngineButton;
	private: System::Windows::Forms::Label^  EnigneOutputLabel;
	private: System::Windows::Forms::Label^  EngineOutputLabel;
	private: System::Windows::Forms::Label^  E_SpeedOutputValueLabel;
	private: System::Windows::Forms::Label^  E_RollOutputValueLabel;
	private: System::Windows::Forms::Label^  E_YawOutputValueLabel;
	private: System::Windows::Forms::Label^  E_PitchOutputValueLabel;
	private: System::Windows::Forms::Label^  E_MassOutputValueLabel;
	private: System::Windows::Forms::Label^  E_DrainOutputValueLabel;
	private: System::Windows::Forms::Label^  E_ArmorOutputValueLabel;
	private: System::Windows::Forms::Label^  E_SpeedOutputLabel;
	private: System::Windows::Forms::Label^  E_RollOutputLabel;
	private: System::Windows::Forms::Label^  E_YawOutputLabel;
	private: System::Windows::Forms::Label^  E_PitchOutputLabel;
	private: System::Windows::Forms::Label^  E_DrainOutputLabel;
	private: System::Windows::Forms::Label^  E_MassOutputLabel;
	private: System::Windows::Forms::Label^  E_ArmorOutputLabel;
	private: System::Windows::Forms::TextBox^  EngineFormSpeedTextBox;
	private: System::Windows::Forms::TextBox^  EngineFormRollTextBox;
	private: System::Windows::Forms::TextBox^  EngineFormYawTextBox;
	private: System::Windows::Forms::TextBox^  EngineFormPitchTextBox;
	private: System::Windows::Forms::TextBox^  EngineFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  EngineFormMassTextBox;
	private: System::Windows::Forms::TextBox^  EngineFormArmorTextBox;
	private: System::Windows::Forms::Label^  E_SpeedLabel;
	private: System::Windows::Forms::Label^  E_RollLabel;
	private: System::Windows::Forms::Label^  E_YawLabel;
	private: System::Windows::Forms::Label^  E_PitchLabel;
	private: System::Windows::Forms::Label^  E_DrainLabel;
	private: System::Windows::Forms::Label^  E_MassLabel;
	private: System::Windows::Forms::Label^  E_ArmorLabel;

	private: System::Windows::Forms::Panel^  BoosterPanel;
	private: System::Windows::Forms::Button^  ClearBoosterButton;
	private: System::Windows::Forms::Button^  CalcBoosterButton;
	private: System::Windows::Forms::Label^  BoosterOutputLabel;
	private: System::Windows::Forms::Label^  BoosterInputLabel;
	private: System::Windows::Forms::Label^  B_SpeedLabel;
	private: System::Windows::Forms::TextBox^  BoosterFormSpeedTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormAccelerationTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormConsumptionTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormRechargeTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormEnergyTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormMassTextBox;
	private: System::Windows::Forms::TextBox^  BoosterFormArmorTextBox;
	private: System::Windows::Forms::Label^  B_AccelerationLabel;
	private: System::Windows::Forms::Label^  B_ConsumptionLabel;
	private: System::Windows::Forms::Label^  B_RechargeLabel;
	private: System::Windows::Forms::Label^  B_EnergyLabel;
	private: System::Windows::Forms::Label^  B_DrainLabel;
	private: System::Windows::Forms::Label^  B_MassLabel;
	private: System::Windows::Forms::Label^  B_ArmorLabel;
	private: System::Windows::Forms::Label^  B_SpeedOutputValueLabel;
	private: System::Windows::Forms::Label^  B_AccelerationOutputValueLabel;
	private: System::Windows::Forms::Label^  B_ConsumptionOutputValueLabel;
	private: System::Windows::Forms::Label^  B_RechargeOutputValueLabel;
	private: System::Windows::Forms::Label^  B_EnergyOutputValueLabel;
	private: System::Windows::Forms::Label^  B_DrainOutputValueLabel;
	private: System::Windows::Forms::Label^  B_MassOutputValueLabel;
	private: System::Windows::Forms::Label^  B_ArmorOutputValueLabel;
	private: System::Windows::Forms::Label^  B_SpeedOutputLabel;
	private: System::Windows::Forms::Label^  B_AccelerationOutputLabel;
	private: System::Windows::Forms::Label^  B_ConsumptionOutputLabel;
	private: System::Windows::Forms::Label^  B_RechargeOutputLabel;
	private: System::Windows::Forms::Label^  B_EnergyOutputLabel;
	private: System::Windows::Forms::Label^  B_DrainOutputLabel;
	private: System::Windows::Forms::Label^  B_MassOutputLabel;
	private: System::Windows::Forms::Label^  B_ArmorOutputLabel;

	private: System::Windows::Forms::Panel^  SheildPanel;
	private: System::Windows::Forms::Button^  ClearSheildButton;
	private: System::Windows::Forms::Button^  CalcSheildButton;
	private: System::Windows::Forms::Label^  SheildOutputLabel;
	private: System::Windows::Forms::Label^  SheildInputLabel;
	private: System::Windows::Forms::Label^  S_RechargeOutputLabel;
	private: System::Windows::Forms::Label^  S_RearHPOutputLabel;
	private: System::Windows::Forms::Label^  S_FrontHPOutputLabel;
	private: System::Windows::Forms::Label^  S_DrainOutputLabel;
	private: System::Windows::Forms::Label^  S_MassOutputLabel;
	private: System::Windows::Forms::TextBox^  SheildFormRechargeTextBox;
	private: System::Windows::Forms::TextBox^  SheildFormBackHPTextBox;
	private: System::Windows::Forms::TextBox^  SheildFormFrontHPTextBox;
	private: System::Windows::Forms::TextBox^  SheildFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  SheildFormMassTextBox;
	private: System::Windows::Forms::TextBox^  SheildFormArmorTextBox;
	private: System::Windows::Forms::Label^  S_RechargeLabel;
	private: System::Windows::Forms::Label^  S_RearHPLabel;
	private: System::Windows::Forms::Label^  S_FrontHPLabel;
	private: System::Windows::Forms::Label^  S_DrainLabel;
	private: System::Windows::Forms::Label^  S_MassLabel;
	private: System::Windows::Forms::Label^  S_ArmorLabel;
	private: System::Windows::Forms::Label^  S_RechargeOutputValueLabel;
	private: System::Windows::Forms::Label^  S_RearHPOutputValueLabel;
	private: System::Windows::Forms::Label^  S_FrontHPOutputValueLabel;
	private: System::Windows::Forms::Label^  S_MassOutputValueLabel;
	private: System::Windows::Forms::Label^  S_DrainOutputValueLabel;
	private: System::Windows::Forms::Label^  S_ArmorOutputValueLabel;
	private: System::Windows::Forms::Label^  S_ArmorOutputLabel;

	private: System::Windows::Forms::Panel^  DroidPanel;
	private: System::Windows::Forms::Label^  DroidOutputLabel;
	private: System::Windows::Forms::Label^  DroidInputLabel;
	private: System::Windows::Forms::Button^  ClearDriodButton;
	private: System::Windows::Forms::Button^  CalcDroidButton;
	private: System::Windows::Forms::Label^  D_SpeedOutputValueLabel;
	private: System::Windows::Forms::Label^  D_MassOutputValueLabel;
	private: System::Windows::Forms::Label^  D_DrainOutputValueLabel;
	private: System::Windows::Forms::Label^  D_ArmorOutputValueLabel;
	private: System::Windows::Forms::Label^  D_SpeedOutputLabel;
	private: System::Windows::Forms::Label^  D_DrainOutputLabel;
	private: System::Windows::Forms::Label^  D_MassOutputLabel;
	private: System::Windows::Forms::Label^  D_ArmorOutputLabel;
	private: System::Windows::Forms::TextBox^  DroidFormSpeedTextBox;
	private: System::Windows::Forms::Label^  D_SpeedLabel;
	private: System::Windows::Forms::TextBox^  DroidFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  DroidFormMassTextBox;
	private: System::Windows::Forms::TextBox^  DroidFormArmorTextBox;
	private: System::Windows::Forms::Label^  D_DrainLabel;
	private: System::Windows::Forms::Label^  D_MassLabel;
	private: System::Windows::Forms::Label^  D_ArmorLabel;

	private: System::Windows::Forms::Panel^  CapacitorPanel;
	private: System::Windows::Forms::Label^  CapacitorOutputLabel;
	private: System::Windows::Forms::Label^  CapacitorInputLabel;
	private: System::Windows::Forms::Button^  ClearCapacitorButton;
	private: System::Windows::Forms::Button^  CalcCapacitorButton;
	private: System::Windows::Forms::Label^  C_RechargeOutputValueLabel;
	private: System::Windows::Forms::Label^  C_EnergyOutputValueLabel;
	private: System::Windows::Forms::Label^  C_MassOutputValueLabel;
	private: System::Windows::Forms::Label^  C_DrainOutputValueLabel;
	private: System::Windows::Forms::Label^  C_ArmorOutputValueLabel;
	private: System::Windows::Forms::Label^  C_RechargeOutputLabel;
	private: System::Windows::Forms::Label^  C_EnergyOutputLabel;
	private: System::Windows::Forms::Label^  C_DrainOutputLabel;
	private: System::Windows::Forms::Label^  C_MassOutputLabel;
	private: System::Windows::Forms::Label^  C_ArmorOutputLabel;
	private: System::Windows::Forms::Label^  C_RechargeLabel;
	private: System::Windows::Forms::TextBox^  CapacitorFormRechargeTextBox;
	private: System::Windows::Forms::TextBox^  CapacitorFormEnergyTextBox;
	private: System::Windows::Forms::Label^  C_EnergyLabel;
	private: System::Windows::Forms::TextBox^  CapacitorFormDrainTextBox;
	private: System::Windows::Forms::TextBox^  CapacitorFormMassTextBox;
	private: System::Windows::Forms::TextBox^  CapacitorFormArmorTextBox;
	private: System::Windows::Forms::Label^  C_DrainLabel;
	private: System::Windows::Forms::Label^  C_MassLabel;
	private: System::Windows::Forms::Label^  C_ArmorLabel;

#pragma endregion

	protected: 


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		static int height;
		static int compInfoheight;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RECalc::typeid));
			this->CompInfoPanel = (gcnew System::Windows::Forms::Panel());
			this->CompTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CompLevelComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CompType = (gcnew System::Windows::Forms::Label());
			this->CompLevel = (gcnew System::Windows::Forms::Label());
			this->WeaponPanel = (gcnew System::Windows::Forms::Panel());
			this->ClearWeaponButton = (gcnew System::Windows::Forms::Button());
			this->CalcWeaponButton = (gcnew System::Windows::Forms::Button());
			this->W_RefireOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->W_EPSOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->W_vsAOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->W_vsSOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->W_MaxDOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->W_MinDOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->W_DrainOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->W_MassOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->W_ArmorOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->WeaponOutputLabel = (gcnew System::Windows::Forms::Label());
			this->W_RefireOutputLabel = (gcnew System::Windows::Forms::Label());
			this->W_EPSOutputLabel = (gcnew System::Windows::Forms::Label());
			this->W_vsAOutputLabel = (gcnew System::Windows::Forms::Label());
			this->W_vsSOutputLabel = (gcnew System::Windows::Forms::Label());
			this->W_MaxDOutputLabel = (gcnew System::Windows::Forms::Label());
			this->W_MinDOutputLabel = (gcnew System::Windows::Forms::Label());
			this->W_DrainOutputLabel = (gcnew System::Windows::Forms::Label());
			this->W_MassOutputLabel = (gcnew System::Windows::Forms::Label());
			this->W_ArmorOutputLabel = (gcnew System::Windows::Forms::Label());
			this->WeaponInputLabel = (gcnew System::Windows::Forms::Label());
			this->W_RefireLabel = (gcnew System::Windows::Forms::Label());
			this->WeaponFormRefireTextBox = (gcnew System::Windows::Forms::TextBox());
			this->W_EPSLabel = (gcnew System::Windows::Forms::Label());
			this->WeaponFormEPSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormvsATextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormvsSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormMaxDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormMinDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WeaponFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->W_vsALabel = (gcnew System::Windows::Forms::Label());
			this->W_vsSLabel = (gcnew System::Windows::Forms::Label());
			this->W_MaxDLabel = (gcnew System::Windows::Forms::Label());
			this->W_MinDLabel = (gcnew System::Windows::Forms::Label());
			this->W_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->W_MassLabel = (gcnew System::Windows::Forms::Label());
			this->W_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorPanel = (gcnew System::Windows::Forms::Panel());
			this->ClearReactorButton = (gcnew System::Windows::Forms::Button());
			this->R_GenerationOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->R_MassOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->R_ArmorOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->R_GenerationOutputLabel = (gcnew System::Windows::Forms::Label());
			this->R_MassOutputLabel = (gcnew System::Windows::Forms::Label());
			this->R_ArmorOutputLabel = (gcnew System::Windows::Forms::Label());
			this->CalcReactorButton = (gcnew System::Windows::Forms::Button());
			this->ReactorFormGenerationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ReactorFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ReactorFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->R_GenerationLabel = (gcnew System::Windows::Forms::Label());
			this->R_MassLabel = (gcnew System::Windows::Forms::Label());
			this->R_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorOutputLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorInputLabel = (gcnew System::Windows::Forms::Label());
			this->ArmorPanel = (gcnew System::Windows::Forms::Panel());
			this->ClearArmorButton = (gcnew System::Windows::Forms::Button());
			this->A_MassOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->A_ArmorOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->A_MassOutputLabel = (gcnew System::Windows::Forms::Label());
			this->A_ArmorOutputLabel = (gcnew System::Windows::Forms::Label());
			this->CalcArmorButton = (gcnew System::Windows::Forms::Button());
			this->ArmorOutputLabel = (gcnew System::Windows::Forms::Label());
			this->ArmorInput = (gcnew System::Windows::Forms::Label());
			this->ArmorFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ArmorFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->A_MassLabel = (gcnew System::Windows::Forms::Label());
			this->A_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->EnginePanel = (gcnew System::Windows::Forms::Panel());
			this->E_SpeedOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_RollOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_YawOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_PitchOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_MassOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_DrainOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_ArmorOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->E_SpeedOutputLabel = (gcnew System::Windows::Forms::Label());
			this->E_RollOutputLabel = (gcnew System::Windows::Forms::Label());
			this->E_YawOutputLabel = (gcnew System::Windows::Forms::Label());
			this->E_PitchOutputLabel = (gcnew System::Windows::Forms::Label());
			this->E_DrainOutputLabel = (gcnew System::Windows::Forms::Label());
			this->E_MassOutputLabel = (gcnew System::Windows::Forms::Label());
			this->E_ArmorOutputLabel = (gcnew System::Windows::Forms::Label());
			this->EngineFormSpeedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EngineFormRollTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EngineFormYawTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EngineFormPitchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EngineFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EngineFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EngineFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->E_SpeedLabel = (gcnew System::Windows::Forms::Label());
			this->E_RollLabel = (gcnew System::Windows::Forms::Label());
			this->E_YawLabel = (gcnew System::Windows::Forms::Label());
			this->E_PitchLabel = (gcnew System::Windows::Forms::Label());
			this->E_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->E_MassLabel = (gcnew System::Windows::Forms::Label());
			this->E_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->ClearEngineButton = (gcnew System::Windows::Forms::Button());
			this->CalcEngineButton = (gcnew System::Windows::Forms::Button());
			this->EnigneOutputLabel = (gcnew System::Windows::Forms::Label());
			this->EngineOutputLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterPanel = (gcnew System::Windows::Forms::Panel());
			this->B_SpeedOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_AccelerationOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_ConsumptionOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_RechargeOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_EnergyOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_DrainOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_MassOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_ArmorOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->B_SpeedOutputLabel = (gcnew System::Windows::Forms::Label());
			this->B_AccelerationOutputLabel = (gcnew System::Windows::Forms::Label());
			this->B_ConsumptionOutputLabel = (gcnew System::Windows::Forms::Label());
			this->B_RechargeOutputLabel = (gcnew System::Windows::Forms::Label());
			this->B_EnergyOutputLabel = (gcnew System::Windows::Forms::Label());
			this->B_DrainOutputLabel = (gcnew System::Windows::Forms::Label());
			this->B_MassOutputLabel = (gcnew System::Windows::Forms::Label());
			this->B_ArmorOutputLabel = (gcnew System::Windows::Forms::Label());
			this->B_SpeedLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterFormSpeedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormAccelerationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormConsumptionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormRechargeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormEnergyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BoosterFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->B_AccelerationLabel = (gcnew System::Windows::Forms::Label());
			this->B_ConsumptionLabel = (gcnew System::Windows::Forms::Label());
			this->B_RechargeLabel = (gcnew System::Windows::Forms::Label());
			this->B_EnergyLabel = (gcnew System::Windows::Forms::Label());
			this->B_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->B_MassLabel = (gcnew System::Windows::Forms::Label());
			this->B_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->ClearBoosterButton = (gcnew System::Windows::Forms::Button());
			this->CalcBoosterButton = (gcnew System::Windows::Forms::Button());
			this->BoosterOutputLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterInputLabel = (gcnew System::Windows::Forms::Label());
			this->SheildPanel = (gcnew System::Windows::Forms::Panel());
			this->S_RechargeOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_RearHPOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_FrontHPOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_MassOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_DrainOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_ArmorOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->S_RechargeOutputLabel = (gcnew System::Windows::Forms::Label());
			this->S_RearHPOutputLabel = (gcnew System::Windows::Forms::Label());
			this->S_FrontHPOutputLabel = (gcnew System::Windows::Forms::Label());
			this->S_DrainOutputLabel = (gcnew System::Windows::Forms::Label());
			this->S_MassOutputLabel = (gcnew System::Windows::Forms::Label());
			this->S_ArmorOutputLabel = (gcnew System::Windows::Forms::Label());
			this->SheildFormRechargeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SheildFormBackHPTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SheildFormFrontHPTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SheildFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SheildFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SheildFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->S_RechargeLabel = (gcnew System::Windows::Forms::Label());
			this->S_RearHPLabel = (gcnew System::Windows::Forms::Label());
			this->S_FrontHPLabel = (gcnew System::Windows::Forms::Label());
			this->S_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->S_MassLabel = (gcnew System::Windows::Forms::Label());
			this->S_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->ClearSheildButton = (gcnew System::Windows::Forms::Button());
			this->CalcSheildButton = (gcnew System::Windows::Forms::Button());
			this->SheildOutputLabel = (gcnew System::Windows::Forms::Label());
			this->SheildInputLabel = (gcnew System::Windows::Forms::Label());
			this->DroidPanel = (gcnew System::Windows::Forms::Panel());
			this->D_SpeedOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->D_MassOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->D_DrainOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->D_ArmorOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->D_SpeedOutputLabel = (gcnew System::Windows::Forms::Label());
			this->D_DrainOutputLabel = (gcnew System::Windows::Forms::Label());
			this->D_MassOutputLabel = (gcnew System::Windows::Forms::Label());
			this->D_ArmorOutputLabel = (gcnew System::Windows::Forms::Label());
			this->DroidFormSpeedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->D_SpeedLabel = (gcnew System::Windows::Forms::Label());
			this->DroidFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DroidFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DroidFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->D_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->D_MassLabel = (gcnew System::Windows::Forms::Label());
			this->D_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->DroidOutputLabel = (gcnew System::Windows::Forms::Label());
			this->DroidInputLabel = (gcnew System::Windows::Forms::Label());
			this->ClearDriodButton = (gcnew System::Windows::Forms::Button());
			this->CalcDroidButton = (gcnew System::Windows::Forms::Button());
			this->CapacitorPanel = (gcnew System::Windows::Forms::Panel());
			this->C_RechargeOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->C_EnergyOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->C_MassOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->C_DrainOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->C_ArmorOutputValueLabel = (gcnew System::Windows::Forms::Label());
			this->C_RechargeOutputLabel = (gcnew System::Windows::Forms::Label());
			this->C_EnergyOutputLabel = (gcnew System::Windows::Forms::Label());
			this->C_DrainOutputLabel = (gcnew System::Windows::Forms::Label());
			this->C_MassOutputLabel = (gcnew System::Windows::Forms::Label());
			this->C_ArmorOutputLabel = (gcnew System::Windows::Forms::Label());
			this->C_RechargeLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorFormRechargeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CapacitorFormEnergyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->C_EnergyLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorFormDrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CapacitorFormMassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CapacitorFormArmorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->C_DrainLabel = (gcnew System::Windows::Forms::Label());
			this->C_MassLabel = (gcnew System::Windows::Forms::Label());
			this->C_ArmorLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorOutputLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorInputLabel = (gcnew System::Windows::Forms::Label());
			this->ClearCapacitorButton = (gcnew System::Windows::Forms::Button());
			this->CalcCapacitorButton = (gcnew System::Windows::Forms::Button());
			this->CompInfoPanel->SuspendLayout();
			this->WeaponPanel->SuspendLayout();
			this->ReactorPanel->SuspendLayout();
			this->ArmorPanel->SuspendLayout();
			this->EnginePanel->SuspendLayout();
			this->BoosterPanel->SuspendLayout();
			this->SheildPanel->SuspendLayout();
			this->DroidPanel->SuspendLayout();
			this->CapacitorPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// CompInfoPanel
			// 
			this->CompInfoPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"CompInfoPanel.BackgroundImage")));
			this->CompInfoPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CompInfoPanel->Controls->Add(this->CompTypeComboBox);
			this->CompInfoPanel->Controls->Add(this->CompLevelComboBox);
			this->CompInfoPanel->Controls->Add(this->CompType);
			this->CompInfoPanel->Controls->Add(this->CompLevel);
			this->CompInfoPanel->Location = System::Drawing::Point(100, 12);
			this->CompInfoPanel->Name = L"CompInfoPanel";
			this->CompInfoPanel->Size = System::Drawing::Size(260, 73);
			this->CompInfoPanel->TabIndex = 0;
			// 
			// CompTypeComboBox
			// 
			this->CompTypeComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CompTypeComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CompTypeComboBox->FormattingEnabled = true;
			this->CompTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"Reactor", L"Engine", L"Booster", L"Shield", 
				L"Armor", L"Droid Interface", L"Capacitor", L"Weapon"});
			this->CompTypeComboBox->Location = System::Drawing::Point(123, 38);
			this->CompTypeComboBox->Name = L"CompTypeComboBox";
			this->CompTypeComboBox->Size = System::Drawing::Size(121, 22);
			this->CompTypeComboBox->TabIndex = 3;
			this->CompTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &RECalc::CompTypeComboBox_SelectedIndexChanged);
			// 
			// CompLevelComboBox
			// 
			this->CompLevelComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CompLevelComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CompLevelComboBox->FormattingEnabled = true;
			this->CompLevelComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(10) {L"1", L"2", L"3", L"4", L"5", L"6", L"7", 
				L"8", L"9", L"10"});
			this->CompLevelComboBox->Location = System::Drawing::Point(123, 11);
			this->CompLevelComboBox->Name = L"CompLevelComboBox";
			this->CompLevelComboBox->Size = System::Drawing::Size(47, 22);
			this->CompLevelComboBox->TabIndex = 2;
			// 
			// CompType
			// 
			this->CompType->AutoSize = true;
			this->CompType->BackColor = System::Drawing::Color::Transparent;
			this->CompType->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CompType->Location = System::Drawing::Point(3, 40);
			this->CompType->Name = L"CompType";
			this->CompType->Size = System::Drawing::Size(111, 14);
			this->CompType->TabIndex = 1;
			this->CompType->Text = L"Componet Type:";
			// 
			// CompLevel
			// 
			this->CompLevel->AutoSize = true;
			this->CompLevel->BackColor = System::Drawing::Color::Transparent;
			this->CompLevel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CompLevel->Location = System::Drawing::Point(3, 13);
			this->CompLevel->Name = L"CompLevel";
			this->CompLevel->Size = System::Drawing::Size(114, 14);
			this->CompLevel->TabIndex = 0;
			this->CompLevel->Text = L"Componet Level:";
			// 
			// WeaponPanel
			// 
			this->WeaponPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"WeaponPanel.BackgroundImage")));
			this->WeaponPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->WeaponPanel->Controls->Add(this->ClearWeaponButton);
			this->WeaponPanel->Controls->Add(this->CalcWeaponButton);
			this->WeaponPanel->Controls->Add(this->W_RefireOutputValueLabel);
			this->WeaponPanel->Controls->Add(this->W_EPSOutputValueLabel);
			this->WeaponPanel->Controls->Add(this->W_vsAOutputValueLabel);
			this->WeaponPanel->Controls->Add(this->W_vsSOutputValueLabel);
			this->WeaponPanel->Controls->Add(this->W_MaxDOutputValueLabel);
			this->WeaponPanel->Controls->Add(this->W_MinDOutputValueLabel);
			this->WeaponPanel->Controls->Add(this->W_DrainOutputValueLabel);
			this->WeaponPanel->Controls->Add(this->W_MassOutputValueLabel);
			this->WeaponPanel->Controls->Add(this->W_ArmorOutputValueLabel);
			this->WeaponPanel->Controls->Add(this->WeaponOutputLabel);
			this->WeaponPanel->Controls->Add(this->W_RefireOutputLabel);
			this->WeaponPanel->Controls->Add(this->W_EPSOutputLabel);
			this->WeaponPanel->Controls->Add(this->W_vsAOutputLabel);
			this->WeaponPanel->Controls->Add(this->W_vsSOutputLabel);
			this->WeaponPanel->Controls->Add(this->W_MaxDOutputLabel);
			this->WeaponPanel->Controls->Add(this->W_MinDOutputLabel);
			this->WeaponPanel->Controls->Add(this->W_DrainOutputLabel);
			this->WeaponPanel->Controls->Add(this->W_MassOutputLabel);
			this->WeaponPanel->Controls->Add(this->W_ArmorOutputLabel);
			this->WeaponPanel->Controls->Add(this->WeaponInputLabel);
			this->WeaponPanel->Controls->Add(this->W_RefireLabel);
			this->WeaponPanel->Controls->Add(this->WeaponFormRefireTextBox);
			this->WeaponPanel->Controls->Add(this->W_EPSLabel);
			this->WeaponPanel->Controls->Add(this->WeaponFormEPSTextBox);
			this->WeaponPanel->Controls->Add(this->WeaponFormvsATextBox);
			this->WeaponPanel->Controls->Add(this->WeaponFormvsSTextBox);
			this->WeaponPanel->Controls->Add(this->WeaponFormMaxDTextBox);
			this->WeaponPanel->Controls->Add(this->WeaponFormMinDTextBox);
			this->WeaponPanel->Controls->Add(this->WeaponFormDrainTextBox);
			this->WeaponPanel->Controls->Add(this->WeaponFormMassTextBox);
			this->WeaponPanel->Controls->Add(this->WeaponFormArmorTextBox);
			this->WeaponPanel->Controls->Add(this->W_vsALabel);
			this->WeaponPanel->Controls->Add(this->W_vsSLabel);
			this->WeaponPanel->Controls->Add(this->W_MaxDLabel);
			this->WeaponPanel->Controls->Add(this->W_MinDLabel);
			this->WeaponPanel->Controls->Add(this->W_DrainLabel);
			this->WeaponPanel->Controls->Add(this->W_MassLabel);
			this->WeaponPanel->Controls->Add(this->W_ArmorLabel);
			this->WeaponPanel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->WeaponPanel->Location = System::Drawing::Point(12, 91);
			this->WeaponPanel->Name = L"WeaponPanel";
			this->WeaponPanel->Size = System::Drawing::Size(437, 309);
			this->WeaponPanel->TabIndex = 1;
			// 
			// ClearWeaponButton
			// 
			this->ClearWeaponButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ClearWeaponButton->ForeColor = System::Drawing::Color::Black;
			this->ClearWeaponButton->Location = System::Drawing::Point(221, 272);
			this->ClearWeaponButton->Name = L"ClearWeaponButton";
			this->ClearWeaponButton->Size = System::Drawing::Size(75, 23);
			this->ClearWeaponButton->TabIndex = 171;
			this->ClearWeaponButton->Text = L"Clear";
			this->ClearWeaponButton->UseVisualStyleBackColor = true;
			this->ClearWeaponButton->Click += gcnew System::EventHandler(this, &RECalc::ClearWeaponButton_Click);
			// 
			// CalcWeaponButton
			// 
			this->CalcWeaponButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->CalcWeaponButton->ForeColor = System::Drawing::Color::Black;
			this->CalcWeaponButton->Location = System::Drawing::Point(140, 272);
			this->CalcWeaponButton->Name = L"CalcWeaponButton";
			this->CalcWeaponButton->Size = System::Drawing::Size(75, 23);
			this->CalcWeaponButton->TabIndex = 0;
			this->CalcWeaponButton->Text = L"Calculate!";
			this->CalcWeaponButton->UseVisualStyleBackColor = true;
			this->CalcWeaponButton->Click += gcnew System::EventHandler(this, &RECalc::CalcWeaponButton_Click);
			// 
			// W_RefireOutputValueLabel
			// 
			this->W_RefireOutputValueLabel->AutoSize = true;
			this->W_RefireOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_RefireOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_RefireOutputValueLabel->Location = System::Drawing::Point(328, 246);
			this->W_RefireOutputValueLabel->Name = L"W_RefireOutputValueLabel";
			this->W_RefireOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->W_RefireOutputValueLabel->TabIndex = 162;
			this->W_RefireOutputValueLabel->Text = L"No Input";
			// 
			// W_EPSOutputValueLabel
			// 
			this->W_EPSOutputValueLabel->AutoSize = true;
			this->W_EPSOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_EPSOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_EPSOutputValueLabel->Location = System::Drawing::Point(328, 220);
			this->W_EPSOutputValueLabel->Name = L"W_EPSOutputValueLabel";
			this->W_EPSOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->W_EPSOutputValueLabel->TabIndex = 161;
			this->W_EPSOutputValueLabel->Text = L"No Input";
			// 
			// W_vsAOutputValueLabel
			// 
			this->W_vsAOutputValueLabel->AutoSize = true;
			this->W_vsAOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_vsAOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_vsAOutputValueLabel->Location = System::Drawing::Point(328, 194);
			this->W_vsAOutputValueLabel->Name = L"W_vsAOutputValueLabel";
			this->W_vsAOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->W_vsAOutputValueLabel->TabIndex = 160;
			this->W_vsAOutputValueLabel->Text = L"No Input";
			// 
			// W_vsSOutputValueLabel
			// 
			this->W_vsSOutputValueLabel->AutoSize = true;
			this->W_vsSOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_vsSOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_vsSOutputValueLabel->Location = System::Drawing::Point(328, 168);
			this->W_vsSOutputValueLabel->Name = L"W_vsSOutputValueLabel";
			this->W_vsSOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->W_vsSOutputValueLabel->TabIndex = 159;
			this->W_vsSOutputValueLabel->Text = L"No Input";
			// 
			// W_MaxDOutputValueLabel
			// 
			this->W_MaxDOutputValueLabel->AutoSize = true;
			this->W_MaxDOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_MaxDOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_MaxDOutputValueLabel->Location = System::Drawing::Point(328, 142);
			this->W_MaxDOutputValueLabel->Name = L"W_MaxDOutputValueLabel";
			this->W_MaxDOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->W_MaxDOutputValueLabel->TabIndex = 158;
			this->W_MaxDOutputValueLabel->Text = L"No Input";
			// 
			// W_MinDOutputValueLabel
			// 
			this->W_MinDOutputValueLabel->AutoSize = true;
			this->W_MinDOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_MinDOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_MinDOutputValueLabel->Location = System::Drawing::Point(328, 116);
			this->W_MinDOutputValueLabel->Name = L"W_MinDOutputValueLabel";
			this->W_MinDOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->W_MinDOutputValueLabel->TabIndex = 157;
			this->W_MinDOutputValueLabel->Text = L"No Input";
			// 
			// W_DrainOutputValueLabel
			// 
			this->W_DrainOutputValueLabel->AutoSize = true;
			this->W_DrainOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_DrainOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_DrainOutputValueLabel->Location = System::Drawing::Point(328, 64);
			this->W_DrainOutputValueLabel->Name = L"W_DrainOutputValueLabel";
			this->W_DrainOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->W_DrainOutputValueLabel->TabIndex = 156;
			this->W_DrainOutputValueLabel->Text = L"No Input";
			// 
			// W_MassOutputValueLabel
			// 
			this->W_MassOutputValueLabel->AutoSize = true;
			this->W_MassOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_MassOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_MassOutputValueLabel->Location = System::Drawing::Point(328, 90);
			this->W_MassOutputValueLabel->Name = L"W_MassOutputValueLabel";
			this->W_MassOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->W_MassOutputValueLabel->TabIndex = 155;
			this->W_MassOutputValueLabel->Text = L"No Input";
			// 
			// W_ArmorOutputValueLabel
			// 
			this->W_ArmorOutputValueLabel->AutoSize = true;
			this->W_ArmorOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_ArmorOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_ArmorOutputValueLabel->Location = System::Drawing::Point(328, 38);
			this->W_ArmorOutputValueLabel->Name = L"W_ArmorOutputValueLabel";
			this->W_ArmorOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->W_ArmorOutputValueLabel->TabIndex = 154;
			this->W_ArmorOutputValueLabel->Text = L"No Input";
			// 
			// WeaponOutputLabel
			// 
			this->WeaponOutputLabel->AutoSize = true;
			this->WeaponOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->WeaponOutputLabel->Location = System::Drawing::Point(283, 13);
			this->WeaponOutputLabel->Name = L"WeaponOutputLabel";
			this->WeaponOutputLabel->Size = System::Drawing::Size(51, 14);
			this->WeaponOutputLabel->TabIndex = 153;
			this->WeaponOutputLabel->Text = L"Output";
			// 
			// W_RefireOutputLabel
			// 
			this->W_RefireOutputLabel->AutoSize = true;
			this->W_RefireOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_RefireOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_RefireOutputLabel->Location = System::Drawing::Point(228, 246);
			this->W_RefireOutputLabel->Name = L"W_RefireOutputLabel";
			this->W_RefireOutputLabel->Size = System::Drawing::Size(51, 16);
			this->W_RefireOutputLabel->TabIndex = 152;
			this->W_RefireOutputLabel->Text = L"Refire:";
			// 
			// W_EPSOutputLabel
			// 
			this->W_EPSOutputLabel->AutoSize = true;
			this->W_EPSOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_EPSOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_EPSOutputLabel->Location = System::Drawing::Point(228, 220);
			this->W_EPSOutputLabel->Name = L"W_EPSOutputLabel";
			this->W_EPSOutputLabel->Size = System::Drawing::Size(39, 16);
			this->W_EPSOutputLabel->TabIndex = 151;
			this->W_EPSOutputLabel->Text = L"EPS:";
			// 
			// W_vsAOutputLabel
			// 
			this->W_vsAOutputLabel->AutoSize = true;
			this->W_vsAOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_vsAOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_vsAOutputLabel->Location = System::Drawing::Point(228, 194);
			this->W_vsAOutputLabel->Name = L"W_vsAOutputLabel";
			this->W_vsAOutputLabel->Size = System::Drawing::Size(72, 16);
			this->W_vsAOutputLabel->TabIndex = 150;
			this->W_vsAOutputLabel->Text = L"vs Armor:";
			// 
			// W_vsSOutputLabel
			// 
			this->W_vsSOutputLabel->AutoSize = true;
			this->W_vsSOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_vsSOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_vsSOutputLabel->Location = System::Drawing::Point(228, 168);
			this->W_vsSOutputLabel->Name = L"W_vsSOutputLabel";
			this->W_vsSOutputLabel->Size = System::Drawing::Size(80, 16);
			this->W_vsSOutputLabel->TabIndex = 149;
			this->W_vsSOutputLabel->Text = L"vs Sheilds:";
			// 
			// W_MaxDOutputLabel
			// 
			this->W_MaxDOutputLabel->AutoSize = true;
			this->W_MaxDOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_MaxDOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_MaxDOutputLabel->Location = System::Drawing::Point(228, 142);
			this->W_MaxDOutputLabel->Name = L"W_MaxDOutputLabel";
			this->W_MaxDOutputLabel->Size = System::Drawing::Size(97, 16);
			this->W_MaxDOutputLabel->TabIndex = 148;
			this->W_MaxDOutputLabel->Text = L"Max Damage:";
			// 
			// W_MinDOutputLabel
			// 
			this->W_MinDOutputLabel->AutoSize = true;
			this->W_MinDOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_MinDOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_MinDOutputLabel->Location = System::Drawing::Point(228, 116);
			this->W_MinDOutputLabel->Name = L"W_MinDOutputLabel";
			this->W_MinDOutputLabel->Size = System::Drawing::Size(93, 16);
			this->W_MinDOutputLabel->TabIndex = 147;
			this->W_MinDOutputLabel->Text = L"Min Damage:";
			// 
			// W_DrainOutputLabel
			// 
			this->W_DrainOutputLabel->AutoSize = true;
			this->W_DrainOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_DrainOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_DrainOutputLabel->Location = System::Drawing::Point(228, 64);
			this->W_DrainOutputLabel->Name = L"W_DrainOutputLabel";
			this->W_DrainOutputLabel->Size = System::Drawing::Size(47, 16);
			this->W_DrainOutputLabel->TabIndex = 146;
			this->W_DrainOutputLabel->Text = L"Drain:";
			// 
			// W_MassOutputLabel
			// 
			this->W_MassOutputLabel->AutoSize = true;
			this->W_MassOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_MassOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_MassOutputLabel->Location = System::Drawing::Point(228, 90);
			this->W_MassOutputLabel->Name = L"W_MassOutputLabel";
			this->W_MassOutputLabel->Size = System::Drawing::Size(47, 16);
			this->W_MassOutputLabel->TabIndex = 145;
			this->W_MassOutputLabel->Text = L"Mass:";
			// 
			// W_ArmorOutputLabel
			// 
			this->W_ArmorOutputLabel->AutoSize = true;
			this->W_ArmorOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_ArmorOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_ArmorOutputLabel->Location = System::Drawing::Point(228, 38);
			this->W_ArmorOutputLabel->Name = L"W_ArmorOutputLabel";
			this->W_ArmorOutputLabel->Size = System::Drawing::Size(52, 16);
			this->W_ArmorOutputLabel->TabIndex = 144;
			this->W_ArmorOutputLabel->Text = L"Armor:";
			// 
			// WeaponInputLabel
			// 
			this->WeaponInputLabel->AutoSize = true;
			this->WeaponInputLabel->BackColor = System::Drawing::Color::Transparent;
			this->WeaponInputLabel->Location = System::Drawing::Point(84, 13);
			this->WeaponInputLabel->Name = L"WeaponInputLabel";
			this->WeaponInputLabel->Size = System::Drawing::Size(41, 14);
			this->WeaponInputLabel->TabIndex = 143;
			this->WeaponInputLabel->Text = L"Input";
			// 
			// W_RefireLabel
			// 
			this->W_RefireLabel->AutoSize = true;
			this->W_RefireLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_RefireLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_RefireLabel->Location = System::Drawing::Point(9, 245);
			this->W_RefireLabel->Name = L"W_RefireLabel";
			this->W_RefireLabel->Size = System::Drawing::Size(51, 16);
			this->W_RefireLabel->TabIndex = 142;
			this->W_RefireLabel->Text = L"Refire:";
			// 
			// WeaponFormRefireTextBox
			// 
			this->WeaponFormRefireTextBox->Location = System::Drawing::Point(110, 244);
			this->WeaponFormRefireTextBox->MaxLength = 10;
			this->WeaponFormRefireTextBox->Name = L"WeaponFormRefireTextBox";
			this->WeaponFormRefireTextBox->Size = System::Drawing::Size(100, 22);
			this->WeaponFormRefireTextBox->TabIndex = 133;
			this->WeaponFormRefireTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::WeaponFormRefireTextBox_KeyPress);
			this->WeaponFormRefireTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::WeaponFormRefireTextBox_TextChanged);
			// 
			// W_EPSLabel
			// 
			this->W_EPSLabel->AutoSize = true;
			this->W_EPSLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_EPSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_EPSLabel->Location = System::Drawing::Point(9, 219);
			this->W_EPSLabel->Name = L"W_EPSLabel";
			this->W_EPSLabel->Size = System::Drawing::Size(39, 16);
			this->W_EPSLabel->TabIndex = 141;
			this->W_EPSLabel->Text = L"EPS:";
			// 
			// WeaponFormEPSTextBox
			// 
			this->WeaponFormEPSTextBox->Location = System::Drawing::Point(110, 218);
			this->WeaponFormEPSTextBox->MaxLength = 10;
			this->WeaponFormEPSTextBox->Name = L"WeaponFormEPSTextBox";
			this->WeaponFormEPSTextBox->Size = System::Drawing::Size(100, 22);
			this->WeaponFormEPSTextBox->TabIndex = 132;
			this->WeaponFormEPSTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::WeaponFormEPSTextBox_KeyPress);
			this->WeaponFormEPSTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::WeaponFormEPSTextBox_TextChanged);
			// 
			// WeaponFormvsATextBox
			// 
			this->WeaponFormvsATextBox->Location = System::Drawing::Point(110, 192);
			this->WeaponFormvsATextBox->MaxLength = 10;
			this->WeaponFormvsATextBox->Name = L"WeaponFormvsATextBox";
			this->WeaponFormvsATextBox->Size = System::Drawing::Size(100, 22);
			this->WeaponFormvsATextBox->TabIndex = 131;
			this->WeaponFormvsATextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::WeaponFormvsATextBox_KeyPress);
			this->WeaponFormvsATextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::WeaponFormvsATextBox_TextChanged);
			// 
			// WeaponFormvsSTextBox
			// 
			this->WeaponFormvsSTextBox->Location = System::Drawing::Point(110, 166);
			this->WeaponFormvsSTextBox->MaxLength = 10;
			this->WeaponFormvsSTextBox->Name = L"WeaponFormvsSTextBox";
			this->WeaponFormvsSTextBox->Size = System::Drawing::Size(100, 22);
			this->WeaponFormvsSTextBox->TabIndex = 130;
			this->WeaponFormvsSTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::WeaponFormvsSTextBox_KeyPress);
			this->WeaponFormvsSTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::WeaponFormvsSTextBox_TextChanged);
			// 
			// WeaponFormMaxDTextBox
			// 
			this->WeaponFormMaxDTextBox->Location = System::Drawing::Point(110, 140);
			this->WeaponFormMaxDTextBox->MaxLength = 10;
			this->WeaponFormMaxDTextBox->Name = L"WeaponFormMaxDTextBox";
			this->WeaponFormMaxDTextBox->Size = System::Drawing::Size(100, 22);
			this->WeaponFormMaxDTextBox->TabIndex = 129;
			this->WeaponFormMaxDTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::WeaponFormMaxDTextBox_KeyPress);
			this->WeaponFormMaxDTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::WeaponFormMaxDTextBox_TextChanged);
			// 
			// WeaponFormMinDTextBox
			// 
			this->WeaponFormMinDTextBox->Location = System::Drawing::Point(110, 114);
			this->WeaponFormMinDTextBox->MaxLength = 10;
			this->WeaponFormMinDTextBox->Name = L"WeaponFormMinDTextBox";
			this->WeaponFormMinDTextBox->Size = System::Drawing::Size(100, 22);
			this->WeaponFormMinDTextBox->TabIndex = 128;
			this->WeaponFormMinDTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::WeaponFormMinDTextBox_KeyPress);
			this->WeaponFormMinDTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::WeaponFormMinDTextBox_TextChanged);
			// 
			// WeaponFormDrainTextBox
			// 
			this->WeaponFormDrainTextBox->Location = System::Drawing::Point(110, 62);
			this->WeaponFormDrainTextBox->MaxLength = 10;
			this->WeaponFormDrainTextBox->Name = L"WeaponFormDrainTextBox";
			this->WeaponFormDrainTextBox->Size = System::Drawing::Size(100, 22);
			this->WeaponFormDrainTextBox->TabIndex = 126;
			this->WeaponFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::WeaponFormDrainTextBox_KeyPress);
			this->WeaponFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::WeaponFormDrainTextBox_TextChanged);
			// 
			// WeaponFormMassTextBox
			// 
			this->WeaponFormMassTextBox->Location = System::Drawing::Point(110, 88);
			this->WeaponFormMassTextBox->MaxLength = 10;
			this->WeaponFormMassTextBox->Name = L"WeaponFormMassTextBox";
			this->WeaponFormMassTextBox->Size = System::Drawing::Size(100, 22);
			this->WeaponFormMassTextBox->TabIndex = 127;
			this->WeaponFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::WeaponFormMassTextBox_KeyPress);
			this->WeaponFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::WeaponFormMassTextBox_TextChanged);
			// 
			// WeaponFormArmorTextBox
			// 
			this->WeaponFormArmorTextBox->Location = System::Drawing::Point(110, 36);
			this->WeaponFormArmorTextBox->MaxLength = 10;
			this->WeaponFormArmorTextBox->Name = L"WeaponFormArmorTextBox";
			this->WeaponFormArmorTextBox->Size = System::Drawing::Size(100, 22);
			this->WeaponFormArmorTextBox->TabIndex = 125;
			this->WeaponFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::WeaponFormArmorTextBox_KeyPress);
			this->WeaponFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::WeaponFormArmorTextBox_TextChanged);
			// 
			// W_vsALabel
			// 
			this->W_vsALabel->AutoSize = true;
			this->W_vsALabel->BackColor = System::Drawing::Color::Transparent;
			this->W_vsALabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_vsALabel->Location = System::Drawing::Point(9, 193);
			this->W_vsALabel->Name = L"W_vsALabel";
			this->W_vsALabel->Size = System::Drawing::Size(72, 16);
			this->W_vsALabel->TabIndex = 140;
			this->W_vsALabel->Text = L"vs Armor:";
			// 
			// W_vsSLabel
			// 
			this->W_vsSLabel->AutoSize = true;
			this->W_vsSLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_vsSLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_vsSLabel->Location = System::Drawing::Point(9, 167);
			this->W_vsSLabel->Name = L"W_vsSLabel";
			this->W_vsSLabel->Size = System::Drawing::Size(80, 16);
			this->W_vsSLabel->TabIndex = 139;
			this->W_vsSLabel->Text = L"vs Sheilds:";
			// 
			// W_MaxDLabel
			// 
			this->W_MaxDLabel->AutoSize = true;
			this->W_MaxDLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_MaxDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_MaxDLabel->Location = System::Drawing::Point(9, 141);
			this->W_MaxDLabel->Name = L"W_MaxDLabel";
			this->W_MaxDLabel->Size = System::Drawing::Size(97, 16);
			this->W_MaxDLabel->TabIndex = 138;
			this->W_MaxDLabel->Text = L"Max Damage:";
			// 
			// W_MinDLabel
			// 
			this->W_MinDLabel->AutoSize = true;
			this->W_MinDLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_MinDLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_MinDLabel->Location = System::Drawing::Point(9, 115);
			this->W_MinDLabel->Name = L"W_MinDLabel";
			this->W_MinDLabel->Size = System::Drawing::Size(93, 16);
			this->W_MinDLabel->TabIndex = 137;
			this->W_MinDLabel->Text = L"Min Damage:";
			// 
			// W_DrainLabel
			// 
			this->W_DrainLabel->AutoSize = true;
			this->W_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_DrainLabel->Location = System::Drawing::Point(9, 63);
			this->W_DrainLabel->Name = L"W_DrainLabel";
			this->W_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->W_DrainLabel->TabIndex = 136;
			this->W_DrainLabel->Text = L"Drain:";
			// 
			// W_MassLabel
			// 
			this->W_MassLabel->AutoSize = true;
			this->W_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_MassLabel->Location = System::Drawing::Point(9, 89);
			this->W_MassLabel->Name = L"W_MassLabel";
			this->W_MassLabel->Size = System::Drawing::Size(47, 16);
			this->W_MassLabel->TabIndex = 135;
			this->W_MassLabel->Text = L"Mass:";
			// 
			// W_ArmorLabel
			// 
			this->W_ArmorLabel->AutoSize = true;
			this->W_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->W_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->W_ArmorLabel->Location = System::Drawing::Point(9, 37);
			this->W_ArmorLabel->Name = L"W_ArmorLabel";
			this->W_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->W_ArmorLabel->TabIndex = 134;
			this->W_ArmorLabel->Text = L"Armor:";
			// 
			// ReactorPanel
			// 
			this->ReactorPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ReactorPanel.BackgroundImage")));
			this->ReactorPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ReactorPanel->Controls->Add(this->ClearReactorButton);
			this->ReactorPanel->Controls->Add(this->R_GenerationOutputValueLabel);
			this->ReactorPanel->Controls->Add(this->R_MassOutputValueLabel);
			this->ReactorPanel->Controls->Add(this->R_ArmorOutputValueLabel);
			this->ReactorPanel->Controls->Add(this->R_GenerationOutputLabel);
			this->ReactorPanel->Controls->Add(this->R_MassOutputLabel);
			this->ReactorPanel->Controls->Add(this->R_ArmorOutputLabel);
			this->ReactorPanel->Controls->Add(this->CalcReactorButton);
			this->ReactorPanel->Controls->Add(this->ReactorFormGenerationTextBox);
			this->ReactorPanel->Controls->Add(this->ReactorFormMassTextBox);
			this->ReactorPanel->Controls->Add(this->ReactorFormArmorTextBox);
			this->ReactorPanel->Controls->Add(this->R_GenerationLabel);
			this->ReactorPanel->Controls->Add(this->R_MassLabel);
			this->ReactorPanel->Controls->Add(this->R_ArmorLabel);
			this->ReactorPanel->Controls->Add(this->ReactorOutputLabel);
			this->ReactorPanel->Controls->Add(this->ReactorInputLabel);
			this->ReactorPanel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorPanel->Location = System::Drawing::Point(12, 91);
			this->ReactorPanel->Name = L"ReactorPanel";
			this->ReactorPanel->Size = System::Drawing::Size(437, 174);
			this->ReactorPanel->TabIndex = 163;
			// 
			// ClearReactorButton
			// 
			this->ClearReactorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ClearReactorButton->ForeColor = System::Drawing::Color::Black;
			this->ClearReactorButton->Location = System::Drawing::Point(221, 138);
			this->ClearReactorButton->Name = L"ClearReactorButton";
			this->ClearReactorButton->Size = System::Drawing::Size(75, 23);
			this->ClearReactorButton->TabIndex = 170;
			this->ClearReactorButton->Text = L"Clear";
			this->ClearReactorButton->UseVisualStyleBackColor = true;
			this->ClearReactorButton->Click += gcnew System::EventHandler(this, &RECalc::ClearReactorButton_Click);
			// 
			// R_GenerationOutputValueLabel
			// 
			this->R_GenerationOutputValueLabel->AutoSize = true;
			this->R_GenerationOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_GenerationOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_GenerationOutputValueLabel->Location = System::Drawing::Point(328, 108);
			this->R_GenerationOutputValueLabel->Name = L"R_GenerationOutputValueLabel";
			this->R_GenerationOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->R_GenerationOutputValueLabel->TabIndex = 169;
			this->R_GenerationOutputValueLabel->Text = L"No Input";
			// 
			// R_MassOutputValueLabel
			// 
			this->R_MassOutputValueLabel->AutoSize = true;
			this->R_MassOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_MassOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_MassOutputValueLabel->Location = System::Drawing::Point(328, 73);
			this->R_MassOutputValueLabel->Name = L"R_MassOutputValueLabel";
			this->R_MassOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->R_MassOutputValueLabel->TabIndex = 168;
			this->R_MassOutputValueLabel->Text = L"No Input";
			// 
			// R_ArmorOutputValueLabel
			// 
			this->R_ArmorOutputValueLabel->AutoSize = true;
			this->R_ArmorOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_ArmorOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_ArmorOutputValueLabel->Location = System::Drawing::Point(328, 36);
			this->R_ArmorOutputValueLabel->Name = L"R_ArmorOutputValueLabel";
			this->R_ArmorOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->R_ArmorOutputValueLabel->TabIndex = 167;
			this->R_ArmorOutputValueLabel->Text = L"No Input";
			// 
			// R_GenerationOutputLabel
			// 
			this->R_GenerationOutputLabel->AutoSize = true;
			this->R_GenerationOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_GenerationOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_GenerationOutputLabel->Location = System::Drawing::Point(228, 108);
			this->R_GenerationOutputLabel->Name = L"R_GenerationOutputLabel";
			this->R_GenerationOutputLabel->Size = System::Drawing::Size(85, 16);
			this->R_GenerationOutputLabel->TabIndex = 166;
			this->R_GenerationOutputLabel->Text = L"Generation:";
			// 
			// R_MassOutputLabel
			// 
			this->R_MassOutputLabel->AutoSize = true;
			this->R_MassOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_MassOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_MassOutputLabel->Location = System::Drawing::Point(228, 73);
			this->R_MassOutputLabel->Name = L"R_MassOutputLabel";
			this->R_MassOutputLabel->Size = System::Drawing::Size(47, 16);
			this->R_MassOutputLabel->TabIndex = 165;
			this->R_MassOutputLabel->Text = L"Mass:";
			// 
			// R_ArmorOutputLabel
			// 
			this->R_ArmorOutputLabel->AutoSize = true;
			this->R_ArmorOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_ArmorOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_ArmorOutputLabel->Location = System::Drawing::Point(228, 37);
			this->R_ArmorOutputLabel->Name = L"R_ArmorOutputLabel";
			this->R_ArmorOutputLabel->Size = System::Drawing::Size(52, 16);
			this->R_ArmorOutputLabel->TabIndex = 164;
			this->R_ArmorOutputLabel->Text = L"Armor:";
			// 
			// CalcReactorButton
			// 
			this->CalcReactorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->CalcReactorButton->ForeColor = System::Drawing::Color::Black;
			this->CalcReactorButton->Location = System::Drawing::Point(140, 138);
			this->CalcReactorButton->Name = L"CalcReactorButton";
			this->CalcReactorButton->Size = System::Drawing::Size(75, 23);
			this->CalcReactorButton->TabIndex = 163;
			this->CalcReactorButton->Text = L"Calculate!";
			this->CalcReactorButton->UseVisualStyleBackColor = true;
			this->CalcReactorButton->Click += gcnew System::EventHandler(this, &RECalc::CalcReactorButton_Click);
			// 
			// ReactorFormGenerationTextBox
			// 
			this->ReactorFormGenerationTextBox->Location = System::Drawing::Point(110, 106);
			this->ReactorFormGenerationTextBox->MaxLength = 10;
			this->ReactorFormGenerationTextBox->Name = L"ReactorFormGenerationTextBox";
			this->ReactorFormGenerationTextBox->Size = System::Drawing::Size(100, 22);
			this->ReactorFormGenerationTextBox->TabIndex = 156;
			this->ReactorFormGenerationTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::ReactorFormGenerationTextBox_KeyPress);
			this->ReactorFormGenerationTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::ReactorFormGenerationTextBox_TextChanged);
			// 
			// ReactorFormMassTextBox
			// 
			this->ReactorFormMassTextBox->Location = System::Drawing::Point(110, 71);
			this->ReactorFormMassTextBox->MaxLength = 10;
			this->ReactorFormMassTextBox->Name = L"ReactorFormMassTextBox";
			this->ReactorFormMassTextBox->Size = System::Drawing::Size(100, 22);
			this->ReactorFormMassTextBox->TabIndex = 155;
			this->ReactorFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::ReactorFormMassTextBox_KeyPress);
			this->ReactorFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::ReactorFormMassTextBox_TextChanged);
			// 
			// ReactorFormArmorTextBox
			// 
			this->ReactorFormArmorTextBox->Location = System::Drawing::Point(110, 34);
			this->ReactorFormArmorTextBox->MaxLength = 10;
			this->ReactorFormArmorTextBox->Name = L"ReactorFormArmorTextBox";
			this->ReactorFormArmorTextBox->Size = System::Drawing::Size(100, 22);
			this->ReactorFormArmorTextBox->TabIndex = 154;
			this->ReactorFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::ReactorFormArmorTextBox_KeyPress);
			this->ReactorFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::ReactorFormArmorTextBox_TextChanged);
			// 
			// R_GenerationLabel
			// 
			this->R_GenerationLabel->AutoSize = true;
			this->R_GenerationLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_GenerationLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_GenerationLabel->Location = System::Drawing::Point(9, 108);
			this->R_GenerationLabel->Name = L"R_GenerationLabel";
			this->R_GenerationLabel->Size = System::Drawing::Size(85, 16);
			this->R_GenerationLabel->TabIndex = 159;
			this->R_GenerationLabel->Text = L"Generation:";
			// 
			// R_MassLabel
			// 
			this->R_MassLabel->AutoSize = true;
			this->R_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_MassLabel->Location = System::Drawing::Point(9, 73);
			this->R_MassLabel->Name = L"R_MassLabel";
			this->R_MassLabel->Size = System::Drawing::Size(47, 16);
			this->R_MassLabel->TabIndex = 158;
			this->R_MassLabel->Text = L"Mass:";
			// 
			// R_ArmorLabel
			// 
			this->R_ArmorLabel->AutoSize = true;
			this->R_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->R_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_ArmorLabel->Location = System::Drawing::Point(9, 38);
			this->R_ArmorLabel->Name = L"R_ArmorLabel";
			this->R_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->R_ArmorLabel->TabIndex = 157;
			this->R_ArmorLabel->Text = L"Armor:";
			// 
			// ReactorOutputLabel
			// 
			this->ReactorOutputLabel->AutoSize = true;
			this->ReactorOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReactorOutputLabel->Location = System::Drawing::Point(283, 13);
			this->ReactorOutputLabel->Name = L"ReactorOutputLabel";
			this->ReactorOutputLabel->Size = System::Drawing::Size(51, 14);
			this->ReactorOutputLabel->TabIndex = 153;
			this->ReactorOutputLabel->Text = L"Output";
			// 
			// ReactorInputLabel
			// 
			this->ReactorInputLabel->AutoSize = true;
			this->ReactorInputLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReactorInputLabel->Location = System::Drawing::Point(84, 13);
			this->ReactorInputLabel->Name = L"ReactorInputLabel";
			this->ReactorInputLabel->Size = System::Drawing::Size(41, 14);
			this->ReactorInputLabel->TabIndex = 143;
			this->ReactorInputLabel->Text = L"Input";
			// 
			// ArmorPanel
			// 
			this->ArmorPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ArmorPanel.BackgroundImage")));
			this->ArmorPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ArmorPanel->Controls->Add(this->ClearArmorButton);
			this->ArmorPanel->Controls->Add(this->A_MassOutputValueLabel);
			this->ArmorPanel->Controls->Add(this->A_ArmorOutputValueLabel);
			this->ArmorPanel->Controls->Add(this->A_MassOutputLabel);
			this->ArmorPanel->Controls->Add(this->A_ArmorOutputLabel);
			this->ArmorPanel->Controls->Add(this->CalcArmorButton);
			this->ArmorPanel->Controls->Add(this->ArmorOutputLabel);
			this->ArmorPanel->Controls->Add(this->ArmorInput);
			this->ArmorPanel->Controls->Add(this->ArmorFormMassTextBox);
			this->ArmorPanel->Controls->Add(this->ArmorFormArmorTextBox);
			this->ArmorPanel->Controls->Add(this->A_MassLabel);
			this->ArmorPanel->Controls->Add(this->A_ArmorLabel);
			this->ArmorPanel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ArmorPanel->Location = System::Drawing::Point(12, 91);
			this->ArmorPanel->Name = L"ArmorPanel";
			this->ArmorPanel->Size = System::Drawing::Size(437, 148);
			this->ArmorPanel->TabIndex = 164;
			// 
			// ClearArmorButton
			// 
			this->ClearArmorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ClearArmorButton->ForeColor = System::Drawing::Color::Black;
			this->ClearArmorButton->Location = System::Drawing::Point(221, 109);
			this->ClearArmorButton->Name = L"ClearArmorButton";
			this->ClearArmorButton->Size = System::Drawing::Size(75, 23);
			this->ClearArmorButton->TabIndex = 172;
			this->ClearArmorButton->Text = L"Clear";
			this->ClearArmorButton->UseVisualStyleBackColor = true;
			this->ClearArmorButton->Click += gcnew System::EventHandler(this, &RECalc::ClearArmorButton_Click);
			// 
			// A_MassOutputValueLabel
			// 
			this->A_MassOutputValueLabel->AutoSize = true;
			this->A_MassOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->A_MassOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->A_MassOutputValueLabel->Location = System::Drawing::Point(328, 78);
			this->A_MassOutputValueLabel->Name = L"A_MassOutputValueLabel";
			this->A_MassOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->A_MassOutputValueLabel->TabIndex = 164;
			this->A_MassOutputValueLabel->Text = L"No Input";
			// 
			// A_ArmorOutputValueLabel
			// 
			this->A_ArmorOutputValueLabel->AutoSize = true;
			this->A_ArmorOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->A_ArmorOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->A_ArmorOutputValueLabel->Location = System::Drawing::Point(328, 42);
			this->A_ArmorOutputValueLabel->Name = L"A_ArmorOutputValueLabel";
			this->A_ArmorOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->A_ArmorOutputValueLabel->TabIndex = 163;
			this->A_ArmorOutputValueLabel->Text = L"No Input";
			// 
			// A_MassOutputLabel
			// 
			this->A_MassOutputLabel->AutoSize = true;
			this->A_MassOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->A_MassOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->A_MassOutputLabel->Location = System::Drawing::Point(228, 78);
			this->A_MassOutputLabel->Name = L"A_MassOutputLabel";
			this->A_MassOutputLabel->Size = System::Drawing::Size(47, 16);
			this->A_MassOutputLabel->TabIndex = 158;
			this->A_MassOutputLabel->Text = L"Mass:";
			// 
			// A_ArmorOutputLabel
			// 
			this->A_ArmorOutputLabel->AutoSize = true;
			this->A_ArmorOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->A_ArmorOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->A_ArmorOutputLabel->Location = System::Drawing::Point(228, 42);
			this->A_ArmorOutputLabel->Name = L"A_ArmorOutputLabel";
			this->A_ArmorOutputLabel->Size = System::Drawing::Size(52, 16);
			this->A_ArmorOutputLabel->TabIndex = 157;
			this->A_ArmorOutputLabel->Text = L"Armor:";
			// 
			// CalcArmorButton
			// 
			this->CalcArmorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->CalcArmorButton->ForeColor = System::Drawing::Color::Black;
			this->CalcArmorButton->Location = System::Drawing::Point(140, 109);
			this->CalcArmorButton->Name = L"CalcArmorButton";
			this->CalcArmorButton->Size = System::Drawing::Size(75, 23);
			this->CalcArmorButton->TabIndex = 156;
			this->CalcArmorButton->Text = L"Calculate!";
			this->CalcArmorButton->UseVisualStyleBackColor = true;
			this->CalcArmorButton->Click += gcnew System::EventHandler(this, &RECalc::CalcArmorButton_Click);
			// 
			// ArmorOutputLabel
			// 
			this->ArmorOutputLabel->AutoSize = true;
			this->ArmorOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->ArmorOutputLabel->Location = System::Drawing::Point(283, 13);
			this->ArmorOutputLabel->Name = L"ArmorOutputLabel";
			this->ArmorOutputLabel->Size = System::Drawing::Size(51, 14);
			this->ArmorOutputLabel->TabIndex = 155;
			this->ArmorOutputLabel->Text = L"Output";
			// 
			// ArmorInput
			// 
			this->ArmorInput->AutoSize = true;
			this->ArmorInput->BackColor = System::Drawing::Color::Transparent;
			this->ArmorInput->Location = System::Drawing::Point(84, 13);
			this->ArmorInput->Name = L"ArmorInput";
			this->ArmorInput->Size = System::Drawing::Size(41, 14);
			this->ArmorInput->TabIndex = 154;
			this->ArmorInput->Text = L"Input";
			// 
			// ArmorFormMassTextBox
			// 
			this->ArmorFormMassTextBox->Location = System::Drawing::Point(110, 76);
			this->ArmorFormMassTextBox->MaxLength = 10;
			this->ArmorFormMassTextBox->Name = L"ArmorFormMassTextBox";
			this->ArmorFormMassTextBox->Size = System::Drawing::Size(100, 22);
			this->ArmorFormMassTextBox->TabIndex = 70;
			this->ArmorFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::ArmorFormMassTextBox_KeyPress);
			this->ArmorFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::ArmorFormMassTextBox_TextChanged);
			// 
			// ArmorFormArmorTextBox
			// 
			this->ArmorFormArmorTextBox->Location = System::Drawing::Point(110, 40);
			this->ArmorFormArmorTextBox->MaxLength = 10;
			this->ArmorFormArmorTextBox->Name = L"ArmorFormArmorTextBox";
			this->ArmorFormArmorTextBox->Size = System::Drawing::Size(100, 22);
			this->ArmorFormArmorTextBox->TabIndex = 69;
			this->ArmorFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::ArmorFormArmorTextBox_KeyPress);
			this->ArmorFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::ArmorFormArmorTextBox_TextChanged);
			// 
			// A_MassLabel
			// 
			this->A_MassLabel->AutoSize = true;
			this->A_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->A_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->A_MassLabel->Location = System::Drawing::Point(9, 78);
			this->A_MassLabel->Name = L"A_MassLabel";
			this->A_MassLabel->Size = System::Drawing::Size(47, 16);
			this->A_MassLabel->TabIndex = 72;
			this->A_MassLabel->Text = L"Mass:";
			// 
			// A_ArmorLabel
			// 
			this->A_ArmorLabel->AutoSize = true;
			this->A_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->A_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->A_ArmorLabel->Location = System::Drawing::Point(9, 42);
			this->A_ArmorLabel->Name = L"A_ArmorLabel";
			this->A_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->A_ArmorLabel->TabIndex = 71;
			this->A_ArmorLabel->Text = L"Armor:";
			// 
			// EnginePanel
			// 
			this->EnginePanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"EnginePanel.BackgroundImage")));
			this->EnginePanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->EnginePanel->Controls->Add(this->E_SpeedOutputValueLabel);
			this->EnginePanel->Controls->Add(this->E_RollOutputValueLabel);
			this->EnginePanel->Controls->Add(this->E_YawOutputValueLabel);
			this->EnginePanel->Controls->Add(this->E_PitchOutputValueLabel);
			this->EnginePanel->Controls->Add(this->E_MassOutputValueLabel);
			this->EnginePanel->Controls->Add(this->E_DrainOutputValueLabel);
			this->EnginePanel->Controls->Add(this->E_ArmorOutputValueLabel);
			this->EnginePanel->Controls->Add(this->E_SpeedOutputLabel);
			this->EnginePanel->Controls->Add(this->E_RollOutputLabel);
			this->EnginePanel->Controls->Add(this->E_YawOutputLabel);
			this->EnginePanel->Controls->Add(this->E_PitchOutputLabel);
			this->EnginePanel->Controls->Add(this->E_DrainOutputLabel);
			this->EnginePanel->Controls->Add(this->E_MassOutputLabel);
			this->EnginePanel->Controls->Add(this->E_ArmorOutputLabel);
			this->EnginePanel->Controls->Add(this->EngineFormSpeedTextBox);
			this->EnginePanel->Controls->Add(this->EngineFormRollTextBox);
			this->EnginePanel->Controls->Add(this->EngineFormYawTextBox);
			this->EnginePanel->Controls->Add(this->EngineFormPitchTextBox);
			this->EnginePanel->Controls->Add(this->EngineFormDrainTextBox);
			this->EnginePanel->Controls->Add(this->EngineFormMassTextBox);
			this->EnginePanel->Controls->Add(this->EngineFormArmorTextBox);
			this->EnginePanel->Controls->Add(this->E_SpeedLabel);
			this->EnginePanel->Controls->Add(this->E_RollLabel);
			this->EnginePanel->Controls->Add(this->E_YawLabel);
			this->EnginePanel->Controls->Add(this->E_PitchLabel);
			this->EnginePanel->Controls->Add(this->E_DrainLabel);
			this->EnginePanel->Controls->Add(this->E_MassLabel);
			this->EnginePanel->Controls->Add(this->E_ArmorLabel);
			this->EnginePanel->Controls->Add(this->ClearEngineButton);
			this->EnginePanel->Controls->Add(this->CalcEngineButton);
			this->EnginePanel->Controls->Add(this->EnigneOutputLabel);
			this->EnginePanel->Controls->Add(this->EngineOutputLabel);
			this->EnginePanel->Location = System::Drawing::Point(12, 91);
			this->EnginePanel->Name = L"EnginePanel";
			this->EnginePanel->Size = System::Drawing::Size(437, 261);
			this->EnginePanel->TabIndex = 165;
			// 
			// E_SpeedOutputValueLabel
			// 
			this->E_SpeedOutputValueLabel->AutoSize = true;
			this->E_SpeedOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_SpeedOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_SpeedOutputValueLabel->Location = System::Drawing::Point(328, 192);
			this->E_SpeedOutputValueLabel->Name = L"E_SpeedOutputValueLabel";
			this->E_SpeedOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->E_SpeedOutputValueLabel->TabIndex = 203;
			this->E_SpeedOutputValueLabel->Text = L"No Input";
			// 
			// E_RollOutputValueLabel
			// 
			this->E_RollOutputValueLabel->AutoSize = true;
			this->E_RollOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_RollOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_RollOutputValueLabel->Location = System::Drawing::Point(328, 165);
			this->E_RollOutputValueLabel->Name = L"E_RollOutputValueLabel";
			this->E_RollOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->E_RollOutputValueLabel->TabIndex = 202;
			this->E_RollOutputValueLabel->Text = L"No Input";
			// 
			// E_YawOutputValueLabel
			// 
			this->E_YawOutputValueLabel->AutoSize = true;
			this->E_YawOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_YawOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_YawOutputValueLabel->Location = System::Drawing::Point(328, 140);
			this->E_YawOutputValueLabel->Name = L"E_YawOutputValueLabel";
			this->E_YawOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->E_YawOutputValueLabel->TabIndex = 201;
			this->E_YawOutputValueLabel->Text = L"No Input";
			// 
			// E_PitchOutputValueLabel
			// 
			this->E_PitchOutputValueLabel->AutoSize = true;
			this->E_PitchOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_PitchOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_PitchOutputValueLabel->Location = System::Drawing::Point(328, 114);
			this->E_PitchOutputValueLabel->Name = L"E_PitchOutputValueLabel";
			this->E_PitchOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->E_PitchOutputValueLabel->TabIndex = 200;
			this->E_PitchOutputValueLabel->Text = L"No Input";
			// 
			// E_MassOutputValueLabel
			// 
			this->E_MassOutputValueLabel->AutoSize = true;
			this->E_MassOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_MassOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_MassOutputValueLabel->Location = System::Drawing::Point(328, 88);
			this->E_MassOutputValueLabel->Name = L"E_MassOutputValueLabel";
			this->E_MassOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->E_MassOutputValueLabel->TabIndex = 199;
			this->E_MassOutputValueLabel->Text = L"No Input";
			// 
			// E_DrainOutputValueLabel
			// 
			this->E_DrainOutputValueLabel->AutoSize = true;
			this->E_DrainOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_DrainOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_DrainOutputValueLabel->Location = System::Drawing::Point(328, 62);
			this->E_DrainOutputValueLabel->Name = L"E_DrainOutputValueLabel";
			this->E_DrainOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->E_DrainOutputValueLabel->TabIndex = 198;
			this->E_DrainOutputValueLabel->Text = L"No Input";
			// 
			// E_ArmorOutputValueLabel
			// 
			this->E_ArmorOutputValueLabel->AutoSize = true;
			this->E_ArmorOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_ArmorOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_ArmorOutputValueLabel->Location = System::Drawing::Point(328, 36);
			this->E_ArmorOutputValueLabel->Name = L"E_ArmorOutputValueLabel";
			this->E_ArmorOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->E_ArmorOutputValueLabel->TabIndex = 197;
			this->E_ArmorOutputValueLabel->Text = L"No Input";
			// 
			// E_SpeedOutputLabel
			// 
			this->E_SpeedOutputLabel->AutoSize = true;
			this->E_SpeedOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_SpeedOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_SpeedOutputLabel->Location = System::Drawing::Point(227, 193);
			this->E_SpeedOutputLabel->Name = L"E_SpeedOutputLabel";
			this->E_SpeedOutputLabel->Size = System::Drawing::Size(55, 16);
			this->E_SpeedOutputLabel->TabIndex = 196;
			this->E_SpeedOutputLabel->Text = L"Speed:";
			// 
			// E_RollOutputLabel
			// 
			this->E_RollOutputLabel->AutoSize = true;
			this->E_RollOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_RollOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_RollOutputLabel->Location = System::Drawing::Point(228, 166);
			this->E_RollOutputLabel->Name = L"E_RollOutputLabel";
			this->E_RollOutputLabel->Size = System::Drawing::Size(36, 16);
			this->E_RollOutputLabel->TabIndex = 195;
			this->E_RollOutputLabel->Text = L"Roll:";
			// 
			// E_YawOutputLabel
			// 
			this->E_YawOutputLabel->AutoSize = true;
			this->E_YawOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_YawOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_YawOutputLabel->Location = System::Drawing::Point(228, 140);
			this->E_YawOutputLabel->Name = L"E_YawOutputLabel";
			this->E_YawOutputLabel->Size = System::Drawing::Size(42, 16);
			this->E_YawOutputLabel->TabIndex = 194;
			this->E_YawOutputLabel->Text = L"Yaw:";
			// 
			// E_PitchOutputLabel
			// 
			this->E_PitchOutputLabel->AutoSize = true;
			this->E_PitchOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_PitchOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_PitchOutputLabel->Location = System::Drawing::Point(228, 114);
			this->E_PitchOutputLabel->Name = L"E_PitchOutputLabel";
			this->E_PitchOutputLabel->Size = System::Drawing::Size(47, 16);
			this->E_PitchOutputLabel->TabIndex = 193;
			this->E_PitchOutputLabel->Text = L"Pitch:";
			// 
			// E_DrainOutputLabel
			// 
			this->E_DrainOutputLabel->AutoSize = true;
			this->E_DrainOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_DrainOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_DrainOutputLabel->Location = System::Drawing::Point(228, 62);
			this->E_DrainOutputLabel->Name = L"E_DrainOutputLabel";
			this->E_DrainOutputLabel->Size = System::Drawing::Size(47, 16);
			this->E_DrainOutputLabel->TabIndex = 192;
			this->E_DrainOutputLabel->Text = L"Drain:";
			// 
			// E_MassOutputLabel
			// 
			this->E_MassOutputLabel->AutoSize = true;
			this->E_MassOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_MassOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_MassOutputLabel->Location = System::Drawing::Point(228, 88);
			this->E_MassOutputLabel->Name = L"E_MassOutputLabel";
			this->E_MassOutputLabel->Size = System::Drawing::Size(47, 16);
			this->E_MassOutputLabel->TabIndex = 191;
			this->E_MassOutputLabel->Text = L"Mass:";
			// 
			// E_ArmorOutputLabel
			// 
			this->E_ArmorOutputLabel->AutoSize = true;
			this->E_ArmorOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_ArmorOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_ArmorOutputLabel->Location = System::Drawing::Point(227, 36);
			this->E_ArmorOutputLabel->Name = L"E_ArmorOutputLabel";
			this->E_ArmorOutputLabel->Size = System::Drawing::Size(52, 16);
			this->E_ArmorOutputLabel->TabIndex = 190;
			this->E_ArmorOutputLabel->Text = L"Armor:";
			// 
			// EngineFormSpeedTextBox
			// 
			this->EngineFormSpeedTextBox->Location = System::Drawing::Point(110, 192);
			this->EngineFormSpeedTextBox->MaxLength = 10;
			this->EngineFormSpeedTextBox->Name = L"EngineFormSpeedTextBox";
			this->EngineFormSpeedTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormSpeedTextBox->TabIndex = 182;
			this->EngineFormSpeedTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::EngineFormSpeedTextBox_KeyPress);
			this->EngineFormSpeedTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::EngineFormSpeedTextBox_TextChanged);
			// 
			// EngineFormRollTextBox
			// 
			this->EngineFormRollTextBox->Location = System::Drawing::Point(110, 166);
			this->EngineFormRollTextBox->MaxLength = 10;
			this->EngineFormRollTextBox->Name = L"EngineFormRollTextBox";
			this->EngineFormRollTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormRollTextBox->TabIndex = 181;
			this->EngineFormRollTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::EngineFormRollTextBox_KeyPress);
			this->EngineFormRollTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::EngineFormRollTextBox_TextChanged);
			// 
			// EngineFormYawTextBox
			// 
			this->EngineFormYawTextBox->Location = System::Drawing::Point(110, 140);
			this->EngineFormYawTextBox->MaxLength = 10;
			this->EngineFormYawTextBox->Name = L"EngineFormYawTextBox";
			this->EngineFormYawTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormYawTextBox->TabIndex = 180;
			this->EngineFormYawTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::EngineFormYawTextBox_KeyPress);
			this->EngineFormYawTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::EngineFormYawTextBox_TextChanged);
			// 
			// EngineFormPitchTextBox
			// 
			this->EngineFormPitchTextBox->Location = System::Drawing::Point(110, 114);
			this->EngineFormPitchTextBox->MaxLength = 10;
			this->EngineFormPitchTextBox->Name = L"EngineFormPitchTextBox";
			this->EngineFormPitchTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormPitchTextBox->TabIndex = 179;
			this->EngineFormPitchTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::EngineFormPitchTextBox_KeyPress);
			this->EngineFormPitchTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::EngineFormPitchTextBox_TextChanged);
			// 
			// EngineFormDrainTextBox
			// 
			this->EngineFormDrainTextBox->Location = System::Drawing::Point(110, 62);
			this->EngineFormDrainTextBox->MaxLength = 10;
			this->EngineFormDrainTextBox->Name = L"EngineFormDrainTextBox";
			this->EngineFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormDrainTextBox->TabIndex = 177;
			this->EngineFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::EngineFormDrainTextBox_KeyPress);
			this->EngineFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::EngineFormDrainTextBox_TextChanged);
			// 
			// EngineFormMassTextBox
			// 
			this->EngineFormMassTextBox->Location = System::Drawing::Point(110, 88);
			this->EngineFormMassTextBox->MaxLength = 10;
			this->EngineFormMassTextBox->Name = L"EngineFormMassTextBox";
			this->EngineFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormMassTextBox->TabIndex = 178;
			this->EngineFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::EngineFormMassTextBox_KeyPress);
			this->EngineFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::EngineFormMassTextBox_TextChanged);
			// 
			// EngineFormArmorTextBox
			// 
			this->EngineFormArmorTextBox->Location = System::Drawing::Point(110, 36);
			this->EngineFormArmorTextBox->MaxLength = 10;
			this->EngineFormArmorTextBox->Name = L"EngineFormArmorTextBox";
			this->EngineFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->EngineFormArmorTextBox->TabIndex = 176;
			this->EngineFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::EngineFormArmorTextBox_KeyPress);
			this->EngineFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::EngineFormArmorTextBox_TextChanged);
			// 
			// E_SpeedLabel
			// 
			this->E_SpeedLabel->AutoSize = true;
			this->E_SpeedLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_SpeedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_SpeedLabel->Location = System::Drawing::Point(9, 192);
			this->E_SpeedLabel->Name = L"E_SpeedLabel";
			this->E_SpeedLabel->Size = System::Drawing::Size(55, 16);
			this->E_SpeedLabel->TabIndex = 189;
			this->E_SpeedLabel->Text = L"Speed:";
			// 
			// E_RollLabel
			// 
			this->E_RollLabel->AutoSize = true;
			this->E_RollLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_RollLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_RollLabel->Location = System::Drawing::Point(9, 166);
			this->E_RollLabel->Name = L"E_RollLabel";
			this->E_RollLabel->Size = System::Drawing::Size(36, 16);
			this->E_RollLabel->TabIndex = 188;
			this->E_RollLabel->Text = L"Roll:";
			// 
			// E_YawLabel
			// 
			this->E_YawLabel->AutoSize = true;
			this->E_YawLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_YawLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_YawLabel->Location = System::Drawing::Point(9, 140);
			this->E_YawLabel->Name = L"E_YawLabel";
			this->E_YawLabel->Size = System::Drawing::Size(42, 16);
			this->E_YawLabel->TabIndex = 187;
			this->E_YawLabel->Text = L"Yaw:";
			// 
			// E_PitchLabel
			// 
			this->E_PitchLabel->AutoSize = true;
			this->E_PitchLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_PitchLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_PitchLabel->Location = System::Drawing::Point(9, 114);
			this->E_PitchLabel->Name = L"E_PitchLabel";
			this->E_PitchLabel->Size = System::Drawing::Size(47, 16);
			this->E_PitchLabel->TabIndex = 186;
			this->E_PitchLabel->Text = L"Pitch:";
			// 
			// E_DrainLabel
			// 
			this->E_DrainLabel->AutoSize = true;
			this->E_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_DrainLabel->Location = System::Drawing::Point(9, 62);
			this->E_DrainLabel->Name = L"E_DrainLabel";
			this->E_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->E_DrainLabel->TabIndex = 185;
			this->E_DrainLabel->Text = L"Drain:";
			// 
			// E_MassLabel
			// 
			this->E_MassLabel->AutoSize = true;
			this->E_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_MassLabel->Location = System::Drawing::Point(9, 88);
			this->E_MassLabel->Name = L"E_MassLabel";
			this->E_MassLabel->Size = System::Drawing::Size(47, 16);
			this->E_MassLabel->TabIndex = 184;
			this->E_MassLabel->Text = L"Mass:";
			// 
			// E_ArmorLabel
			// 
			this->E_ArmorLabel->AutoSize = true;
			this->E_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_ArmorLabel->Location = System::Drawing::Point(9, 36);
			this->E_ArmorLabel->Name = L"E_ArmorLabel";
			this->E_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->E_ArmorLabel->TabIndex = 183;
			this->E_ArmorLabel->Text = L"Armor:";
			// 
			// ClearEngineButton
			// 
			this->ClearEngineButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ClearEngineButton->ForeColor = System::Drawing::Color::Black;
			this->ClearEngineButton->Location = System::Drawing::Point(221, 222);
			this->ClearEngineButton->Name = L"ClearEngineButton";
			this->ClearEngineButton->Size = System::Drawing::Size(75, 23);
			this->ClearEngineButton->TabIndex = 175;
			this->ClearEngineButton->Text = L"Clear";
			this->ClearEngineButton->UseVisualStyleBackColor = true;
			this->ClearEngineButton->Click += gcnew System::EventHandler(this, &RECalc::ClearEngineButton_Click);
			// 
			// CalcEngineButton
			// 
			this->CalcEngineButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->CalcEngineButton->ForeColor = System::Drawing::Color::Black;
			this->CalcEngineButton->Location = System::Drawing::Point(140, 222);
			this->CalcEngineButton->Name = L"CalcEngineButton";
			this->CalcEngineButton->Size = System::Drawing::Size(75, 23);
			this->CalcEngineButton->TabIndex = 172;
			this->CalcEngineButton->Text = L"Calculate!";
			this->CalcEngineButton->UseVisualStyleBackColor = true;
			this->CalcEngineButton->Click += gcnew System::EventHandler(this, &RECalc::CalcEngineButton_Click);
			// 
			// EnigneOutputLabel
			// 
			this->EnigneOutputLabel->AutoSize = true;
			this->EnigneOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->EnigneOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EnigneOutputLabel->Location = System::Drawing::Point(283, 13);
			this->EnigneOutputLabel->Name = L"EnigneOutputLabel";
			this->EnigneOutputLabel->Size = System::Drawing::Size(51, 14);
			this->EnigneOutputLabel->TabIndex = 174;
			this->EnigneOutputLabel->Text = L"Output";
			// 
			// EngineOutputLabel
			// 
			this->EngineOutputLabel->AutoSize = true;
			this->EngineOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->EngineOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineOutputLabel->Location = System::Drawing::Point(84, 13);
			this->EngineOutputLabel->Name = L"EngineOutputLabel";
			this->EngineOutputLabel->Size = System::Drawing::Size(41, 14);
			this->EngineOutputLabel->TabIndex = 173;
			this->EngineOutputLabel->Text = L"Input";
			// 
			// BoosterPanel
			// 
			this->BoosterPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"BoosterPanel.BackgroundImage")));
			this->BoosterPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->BoosterPanel->Controls->Add(this->B_SpeedOutputValueLabel);
			this->BoosterPanel->Controls->Add(this->B_AccelerationOutputValueLabel);
			this->BoosterPanel->Controls->Add(this->B_ConsumptionOutputValueLabel);
			this->BoosterPanel->Controls->Add(this->B_RechargeOutputValueLabel);
			this->BoosterPanel->Controls->Add(this->B_EnergyOutputValueLabel);
			this->BoosterPanel->Controls->Add(this->B_DrainOutputValueLabel);
			this->BoosterPanel->Controls->Add(this->B_MassOutputValueLabel);
			this->BoosterPanel->Controls->Add(this->B_ArmorOutputValueLabel);
			this->BoosterPanel->Controls->Add(this->B_SpeedOutputLabel);
			this->BoosterPanel->Controls->Add(this->B_AccelerationOutputLabel);
			this->BoosterPanel->Controls->Add(this->B_ConsumptionOutputLabel);
			this->BoosterPanel->Controls->Add(this->B_RechargeOutputLabel);
			this->BoosterPanel->Controls->Add(this->B_EnergyOutputLabel);
			this->BoosterPanel->Controls->Add(this->B_DrainOutputLabel);
			this->BoosterPanel->Controls->Add(this->B_MassOutputLabel);
			this->BoosterPanel->Controls->Add(this->B_ArmorOutputLabel);
			this->BoosterPanel->Controls->Add(this->B_SpeedLabel);
			this->BoosterPanel->Controls->Add(this->BoosterFormSpeedTextBox);
			this->BoosterPanel->Controls->Add(this->BoosterFormAccelerationTextBox);
			this->BoosterPanel->Controls->Add(this->BoosterFormConsumptionTextBox);
			this->BoosterPanel->Controls->Add(this->BoosterFormRechargeTextBox);
			this->BoosterPanel->Controls->Add(this->BoosterFormEnergyTextBox);
			this->BoosterPanel->Controls->Add(this->BoosterFormDrainTextBox);
			this->BoosterPanel->Controls->Add(this->BoosterFormMassTextBox);
			this->BoosterPanel->Controls->Add(this->BoosterFormArmorTextBox);
			this->BoosterPanel->Controls->Add(this->B_AccelerationLabel);
			this->BoosterPanel->Controls->Add(this->B_ConsumptionLabel);
			this->BoosterPanel->Controls->Add(this->B_RechargeLabel);
			this->BoosterPanel->Controls->Add(this->B_EnergyLabel);
			this->BoosterPanel->Controls->Add(this->B_DrainLabel);
			this->BoosterPanel->Controls->Add(this->B_MassLabel);
			this->BoosterPanel->Controls->Add(this->B_ArmorLabel);
			this->BoosterPanel->Controls->Add(this->ClearBoosterButton);
			this->BoosterPanel->Controls->Add(this->CalcBoosterButton);
			this->BoosterPanel->Controls->Add(this->BoosterOutputLabel);
			this->BoosterPanel->Controls->Add(this->BoosterInputLabel);
			this->BoosterPanel->Location = System::Drawing::Point(12, 91);
			this->BoosterPanel->Name = L"BoosterPanel";
			this->BoosterPanel->Size = System::Drawing::Size(437, 284);
			this->BoosterPanel->TabIndex = 166;
			// 
			// B_SpeedOutputValueLabel
			// 
			this->B_SpeedOutputValueLabel->AutoSize = true;
			this->B_SpeedOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_SpeedOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_SpeedOutputValueLabel->Location = System::Drawing::Point(328, 222);
			this->B_SpeedOutputValueLabel->Name = L"B_SpeedOutputValueLabel";
			this->B_SpeedOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->B_SpeedOutputValueLabel->TabIndex = 205;
			this->B_SpeedOutputValueLabel->Text = L"No Input";
			// 
			// B_AccelerationOutputValueLabel
			// 
			this->B_AccelerationOutputValueLabel->AutoSize = true;
			this->B_AccelerationOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_AccelerationOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->B_AccelerationOutputValueLabel->Location = System::Drawing::Point(328, 196);
			this->B_AccelerationOutputValueLabel->Name = L"B_AccelerationOutputValueLabel";
			this->B_AccelerationOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->B_AccelerationOutputValueLabel->TabIndex = 204;
			this->B_AccelerationOutputValueLabel->Text = L"No Input";
			// 
			// B_ConsumptionOutputValueLabel
			// 
			this->B_ConsumptionOutputValueLabel->AutoSize = true;
			this->B_ConsumptionOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_ConsumptionOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->B_ConsumptionOutputValueLabel->Location = System::Drawing::Point(328, 170);
			this->B_ConsumptionOutputValueLabel->Name = L"B_ConsumptionOutputValueLabel";
			this->B_ConsumptionOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->B_ConsumptionOutputValueLabel->TabIndex = 203;
			this->B_ConsumptionOutputValueLabel->Text = L"No Input";
			// 
			// B_RechargeOutputValueLabel
			// 
			this->B_RechargeOutputValueLabel->AutoSize = true;
			this->B_RechargeOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_RechargeOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_RechargeOutputValueLabel->Location = System::Drawing::Point(328, 144);
			this->B_RechargeOutputValueLabel->Name = L"B_RechargeOutputValueLabel";
			this->B_RechargeOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->B_RechargeOutputValueLabel->TabIndex = 202;
			this->B_RechargeOutputValueLabel->Text = L"No Input";
			// 
			// B_EnergyOutputValueLabel
			// 
			this->B_EnergyOutputValueLabel->AutoSize = true;
			this->B_EnergyOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_EnergyOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_EnergyOutputValueLabel->Location = System::Drawing::Point(328, 118);
			this->B_EnergyOutputValueLabel->Name = L"B_EnergyOutputValueLabel";
			this->B_EnergyOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->B_EnergyOutputValueLabel->TabIndex = 201;
			this->B_EnergyOutputValueLabel->Text = L"No Input";
			// 
			// B_DrainOutputValueLabel
			// 
			this->B_DrainOutputValueLabel->AutoSize = true;
			this->B_DrainOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_DrainOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_DrainOutputValueLabel->Location = System::Drawing::Point(328, 66);
			this->B_DrainOutputValueLabel->Name = L"B_DrainOutputValueLabel";
			this->B_DrainOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->B_DrainOutputValueLabel->TabIndex = 200;
			this->B_DrainOutputValueLabel->Text = L"No Input";
			// 
			// B_MassOutputValueLabel
			// 
			this->B_MassOutputValueLabel->AutoSize = true;
			this->B_MassOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_MassOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_MassOutputValueLabel->Location = System::Drawing::Point(328, 92);
			this->B_MassOutputValueLabel->Name = L"B_MassOutputValueLabel";
			this->B_MassOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->B_MassOutputValueLabel->TabIndex = 199;
			this->B_MassOutputValueLabel->Text = L"No Input";
			// 
			// B_ArmorOutputValueLabel
			// 
			this->B_ArmorOutputValueLabel->AutoSize = true;
			this->B_ArmorOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_ArmorOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_ArmorOutputValueLabel->Location = System::Drawing::Point(328, 40);
			this->B_ArmorOutputValueLabel->Name = L"B_ArmorOutputValueLabel";
			this->B_ArmorOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->B_ArmorOutputValueLabel->TabIndex = 198;
			this->B_ArmorOutputValueLabel->Text = L"No Input";
			// 
			// B_SpeedOutputLabel
			// 
			this->B_SpeedOutputLabel->AutoSize = true;
			this->B_SpeedOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_SpeedOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_SpeedOutputLabel->Location = System::Drawing::Point(227, 222);
			this->B_SpeedOutputLabel->Name = L"B_SpeedOutputLabel";
			this->B_SpeedOutputLabel->Size = System::Drawing::Size(55, 16);
			this->B_SpeedOutputLabel->TabIndex = 197;
			this->B_SpeedOutputLabel->Text = L"Speed:";
			// 
			// B_AccelerationOutputLabel
			// 
			this->B_AccelerationOutputLabel->AutoSize = true;
			this->B_AccelerationOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_AccelerationOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_AccelerationOutputLabel->Location = System::Drawing::Point(227, 196);
			this->B_AccelerationOutputLabel->Name = L"B_AccelerationOutputLabel";
			this->B_AccelerationOutputLabel->Size = System::Drawing::Size(96, 16);
			this->B_AccelerationOutputLabel->TabIndex = 196;
			this->B_AccelerationOutputLabel->Text = L"Acceleration:";
			// 
			// B_ConsumptionOutputLabel
			// 
			this->B_ConsumptionOutputLabel->AutoSize = true;
			this->B_ConsumptionOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_ConsumptionOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_ConsumptionOutputLabel->Location = System::Drawing::Point(227, 170);
			this->B_ConsumptionOutputLabel->Name = L"B_ConsumptionOutputLabel";
			this->B_ConsumptionOutputLabel->Size = System::Drawing::Size(98, 16);
			this->B_ConsumptionOutputLabel->TabIndex = 195;
			this->B_ConsumptionOutputLabel->Text = L"Consumption:";
			// 
			// B_RechargeOutputLabel
			// 
			this->B_RechargeOutputLabel->AutoSize = true;
			this->B_RechargeOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_RechargeOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_RechargeOutputLabel->Location = System::Drawing::Point(227, 144);
			this->B_RechargeOutputLabel->Name = L"B_RechargeOutputLabel";
			this->B_RechargeOutputLabel->Size = System::Drawing::Size(75, 16);
			this->B_RechargeOutputLabel->TabIndex = 194;
			this->B_RechargeOutputLabel->Text = L"Recharge:";
			// 
			// B_EnergyOutputLabel
			// 
			this->B_EnergyOutputLabel->AutoSize = true;
			this->B_EnergyOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_EnergyOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_EnergyOutputLabel->Location = System::Drawing::Point(227, 118);
			this->B_EnergyOutputLabel->Name = L"B_EnergyOutputLabel";
			this->B_EnergyOutputLabel->Size = System::Drawing::Size(59, 16);
			this->B_EnergyOutputLabel->TabIndex = 193;
			this->B_EnergyOutputLabel->Text = L"Energy:";
			// 
			// B_DrainOutputLabel
			// 
			this->B_DrainOutputLabel->AutoSize = true;
			this->B_DrainOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_DrainOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_DrainOutputLabel->Location = System::Drawing::Point(227, 66);
			this->B_DrainOutputLabel->Name = L"B_DrainOutputLabel";
			this->B_DrainOutputLabel->Size = System::Drawing::Size(47, 16);
			this->B_DrainOutputLabel->TabIndex = 192;
			this->B_DrainOutputLabel->Text = L"Drain:";
			// 
			// B_MassOutputLabel
			// 
			this->B_MassOutputLabel->AutoSize = true;
			this->B_MassOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_MassOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_MassOutputLabel->Location = System::Drawing::Point(227, 92);
			this->B_MassOutputLabel->Name = L"B_MassOutputLabel";
			this->B_MassOutputLabel->Size = System::Drawing::Size(47, 16);
			this->B_MassOutputLabel->TabIndex = 191;
			this->B_MassOutputLabel->Text = L"Mass:";
			// 
			// B_ArmorOutputLabel
			// 
			this->B_ArmorOutputLabel->AutoSize = true;
			this->B_ArmorOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_ArmorOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_ArmorOutputLabel->Location = System::Drawing::Point(227, 40);
			this->B_ArmorOutputLabel->Name = L"B_ArmorOutputLabel";
			this->B_ArmorOutputLabel->Size = System::Drawing::Size(52, 16);
			this->B_ArmorOutputLabel->TabIndex = 190;
			this->B_ArmorOutputLabel->Text = L"Armor:";
			// 
			// B_SpeedLabel
			// 
			this->B_SpeedLabel->AutoSize = true;
			this->B_SpeedLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_SpeedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_SpeedLabel->Location = System::Drawing::Point(12, 222);
			this->B_SpeedLabel->Name = L"B_SpeedLabel";
			this->B_SpeedLabel->Size = System::Drawing::Size(55, 16);
			this->B_SpeedLabel->TabIndex = 189;
			this->B_SpeedLabel->Text = L"Speed:";
			// 
			// BoosterFormSpeedTextBox
			// 
			this->BoosterFormSpeedTextBox->Location = System::Drawing::Point(113, 221);
			this->BoosterFormSpeedTextBox->MaxLength = 10;
			this->BoosterFormSpeedTextBox->Name = L"BoosterFormSpeedTextBox";
			this->BoosterFormSpeedTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormSpeedTextBox->TabIndex = 181;
			this->BoosterFormSpeedTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::BoosterFormSpeedTextBox_KeyPress);
			this->BoosterFormSpeedTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::BoosterFormSpeedTextBox_TextChanged);
			// 
			// BoosterFormAccelerationTextBox
			// 
			this->BoosterFormAccelerationTextBox->Location = System::Drawing::Point(113, 195);
			this->BoosterFormAccelerationTextBox->MaxLength = 10;
			this->BoosterFormAccelerationTextBox->Name = L"BoosterFormAccelerationTextBox";
			this->BoosterFormAccelerationTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormAccelerationTextBox->TabIndex = 180;
			this->BoosterFormAccelerationTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::BoosterFormAccelerationTextBox_KeyPress);
			this->BoosterFormAccelerationTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::BoosterFormAccelerationTextBox_TextChanged);
			// 
			// BoosterFormConsumptionTextBox
			// 
			this->BoosterFormConsumptionTextBox->Location = System::Drawing::Point(113, 169);
			this->BoosterFormConsumptionTextBox->MaxLength = 10;
			this->BoosterFormConsumptionTextBox->Name = L"BoosterFormConsumptionTextBox";
			this->BoosterFormConsumptionTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormConsumptionTextBox->TabIndex = 179;
			this->BoosterFormConsumptionTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::BoosterFormConsumptionTextBox_KeyPress);
			this->BoosterFormConsumptionTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::BoosterFormConsumptionTextBox_TextChanged);
			// 
			// BoosterFormRechargeTextBox
			// 
			this->BoosterFormRechargeTextBox->Location = System::Drawing::Point(113, 143);
			this->BoosterFormRechargeTextBox->MaxLength = 10;
			this->BoosterFormRechargeTextBox->Name = L"BoosterFormRechargeTextBox";
			this->BoosterFormRechargeTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormRechargeTextBox->TabIndex = 178;
			this->BoosterFormRechargeTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::BoosterFormRechargeTextBox_KeyPress);
			this->BoosterFormRechargeTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::BoosterFormRechargeTextBox_TextChanged);
			// 
			// BoosterFormEnergyTextBox
			// 
			this->BoosterFormEnergyTextBox->Location = System::Drawing::Point(113, 117);
			this->BoosterFormEnergyTextBox->MaxLength = 10;
			this->BoosterFormEnergyTextBox->Name = L"BoosterFormEnergyTextBox";
			this->BoosterFormEnergyTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormEnergyTextBox->TabIndex = 177;
			this->BoosterFormEnergyTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::BoosterFormEnergyTextBox_KeyPress);
			this->BoosterFormEnergyTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::BoosterFormEnergyTextBox_TextChanged);
			// 
			// BoosterFormDrainTextBox
			// 
			this->BoosterFormDrainTextBox->Location = System::Drawing::Point(113, 65);
			this->BoosterFormDrainTextBox->MaxLength = 10;
			this->BoosterFormDrainTextBox->Name = L"BoosterFormDrainTextBox";
			this->BoosterFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormDrainTextBox->TabIndex = 175;
			this->BoosterFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::EngineFormDrainTextBox_KeyPress);
			this->BoosterFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::BoosterFormDrainTextBox_TextChanged);
			// 
			// BoosterFormMassTextBox
			// 
			this->BoosterFormMassTextBox->Location = System::Drawing::Point(113, 91);
			this->BoosterFormMassTextBox->MaxLength = 10;
			this->BoosterFormMassTextBox->Name = L"BoosterFormMassTextBox";
			this->BoosterFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormMassTextBox->TabIndex = 176;
			this->BoosterFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::EngineFormMassTextBox_KeyPress);
			this->BoosterFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::BoosterFormMassTextBox_TextChanged);
			// 
			// BoosterFormArmorTextBox
			// 
			this->BoosterFormArmorTextBox->Location = System::Drawing::Point(113, 39);
			this->BoosterFormArmorTextBox->MaxLength = 10;
			this->BoosterFormArmorTextBox->Name = L"BoosterFormArmorTextBox";
			this->BoosterFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->BoosterFormArmorTextBox->TabIndex = 174;
			this->BoosterFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::BoosterFormArmorTextBox_KeyPress);
			this->BoosterFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::BoosterFormArmorTextBox_TextChanged);
			// 
			// B_AccelerationLabel
			// 
			this->B_AccelerationLabel->AutoSize = true;
			this->B_AccelerationLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_AccelerationLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_AccelerationLabel->Location = System::Drawing::Point(12, 196);
			this->B_AccelerationLabel->Name = L"B_AccelerationLabel";
			this->B_AccelerationLabel->Size = System::Drawing::Size(96, 16);
			this->B_AccelerationLabel->TabIndex = 188;
			this->B_AccelerationLabel->Text = L"Acceleration:";
			// 
			// B_ConsumptionLabel
			// 
			this->B_ConsumptionLabel->AutoSize = true;
			this->B_ConsumptionLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_ConsumptionLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_ConsumptionLabel->Location = System::Drawing::Point(12, 170);
			this->B_ConsumptionLabel->Name = L"B_ConsumptionLabel";
			this->B_ConsumptionLabel->Size = System::Drawing::Size(98, 16);
			this->B_ConsumptionLabel->TabIndex = 187;
			this->B_ConsumptionLabel->Text = L"Consumption:";
			// 
			// B_RechargeLabel
			// 
			this->B_RechargeLabel->AutoSize = true;
			this->B_RechargeLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_RechargeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_RechargeLabel->Location = System::Drawing::Point(12, 144);
			this->B_RechargeLabel->Name = L"B_RechargeLabel";
			this->B_RechargeLabel->Size = System::Drawing::Size(75, 16);
			this->B_RechargeLabel->TabIndex = 186;
			this->B_RechargeLabel->Text = L"Recharge:";
			// 
			// B_EnergyLabel
			// 
			this->B_EnergyLabel->AutoSize = true;
			this->B_EnergyLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_EnergyLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_EnergyLabel->Location = System::Drawing::Point(12, 118);
			this->B_EnergyLabel->Name = L"B_EnergyLabel";
			this->B_EnergyLabel->Size = System::Drawing::Size(59, 16);
			this->B_EnergyLabel->TabIndex = 185;
			this->B_EnergyLabel->Text = L"Energy:";
			// 
			// B_DrainLabel
			// 
			this->B_DrainLabel->AutoSize = true;
			this->B_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_DrainLabel->Location = System::Drawing::Point(12, 66);
			this->B_DrainLabel->Name = L"B_DrainLabel";
			this->B_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->B_DrainLabel->TabIndex = 184;
			this->B_DrainLabel->Text = L"Drain:";
			// 
			// B_MassLabel
			// 
			this->B_MassLabel->AutoSize = true;
			this->B_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_MassLabel->Location = System::Drawing::Point(12, 92);
			this->B_MassLabel->Name = L"B_MassLabel";
			this->B_MassLabel->Size = System::Drawing::Size(47, 16);
			this->B_MassLabel->TabIndex = 183;
			this->B_MassLabel->Text = L"Mass:";
			// 
			// B_ArmorLabel
			// 
			this->B_ArmorLabel->AutoSize = true;
			this->B_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->B_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->B_ArmorLabel->Location = System::Drawing::Point(12, 40);
			this->B_ArmorLabel->Name = L"B_ArmorLabel";
			this->B_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->B_ArmorLabel->TabIndex = 182;
			this->B_ArmorLabel->Text = L"Armor:";
			// 
			// ClearBoosterButton
			// 
			this->ClearBoosterButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ClearBoosterButton->ForeColor = System::Drawing::Color::Black;
			this->ClearBoosterButton->Location = System::Drawing::Point(221, 249);
			this->ClearBoosterButton->Name = L"ClearBoosterButton";
			this->ClearBoosterButton->Size = System::Drawing::Size(75, 23);
			this->ClearBoosterButton->TabIndex = 173;
			this->ClearBoosterButton->Text = L"Clear";
			this->ClearBoosterButton->UseVisualStyleBackColor = true;
			this->ClearBoosterButton->Click += gcnew System::EventHandler(this, &RECalc::ClearBoosterButton_Click);
			// 
			// CalcBoosterButton
			// 
			this->CalcBoosterButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->CalcBoosterButton->ForeColor = System::Drawing::Color::Black;
			this->CalcBoosterButton->Location = System::Drawing::Point(140, 249);
			this->CalcBoosterButton->Name = L"CalcBoosterButton";
			this->CalcBoosterButton->Size = System::Drawing::Size(75, 23);
			this->CalcBoosterButton->TabIndex = 172;
			this->CalcBoosterButton->Text = L"Calculate!";
			this->CalcBoosterButton->UseVisualStyleBackColor = true;
			this->CalcBoosterButton->Click += gcnew System::EventHandler(this, &RECalc::CalcBoosterButton_Click);
			// 
			// BoosterOutputLabel
			// 
			this->BoosterOutputLabel->AutoSize = true;
			this->BoosterOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterOutputLabel->Location = System::Drawing::Point(283, 15);
			this->BoosterOutputLabel->Name = L"BoosterOutputLabel";
			this->BoosterOutputLabel->Size = System::Drawing::Size(51, 14);
			this->BoosterOutputLabel->TabIndex = 157;
			this->BoosterOutputLabel->Text = L"Output";
			// 
			// BoosterInputLabel
			// 
			this->BoosterInputLabel->AutoSize = true;
			this->BoosterInputLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterInputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterInputLabel->Location = System::Drawing::Point(84, 15);
			this->BoosterInputLabel->Name = L"BoosterInputLabel";
			this->BoosterInputLabel->Size = System::Drawing::Size(41, 14);
			this->BoosterInputLabel->TabIndex = 156;
			this->BoosterInputLabel->Text = L"Input";
			// 
			// SheildPanel
			// 
			this->SheildPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"SheildPanel.BackgroundImage")));
			this->SheildPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->SheildPanel->Controls->Add(this->S_RechargeOutputValueLabel);
			this->SheildPanel->Controls->Add(this->S_RearHPOutputValueLabel);
			this->SheildPanel->Controls->Add(this->S_FrontHPOutputValueLabel);
			this->SheildPanel->Controls->Add(this->S_MassOutputValueLabel);
			this->SheildPanel->Controls->Add(this->S_DrainOutputValueLabel);
			this->SheildPanel->Controls->Add(this->S_ArmorOutputValueLabel);
			this->SheildPanel->Controls->Add(this->S_RechargeOutputLabel);
			this->SheildPanel->Controls->Add(this->S_RearHPOutputLabel);
			this->SheildPanel->Controls->Add(this->S_FrontHPOutputLabel);
			this->SheildPanel->Controls->Add(this->S_DrainOutputLabel);
			this->SheildPanel->Controls->Add(this->S_MassOutputLabel);
			this->SheildPanel->Controls->Add(this->S_ArmorOutputLabel);
			this->SheildPanel->Controls->Add(this->SheildFormRechargeTextBox);
			this->SheildPanel->Controls->Add(this->SheildFormBackHPTextBox);
			this->SheildPanel->Controls->Add(this->SheildFormFrontHPTextBox);
			this->SheildPanel->Controls->Add(this->SheildFormDrainTextBox);
			this->SheildPanel->Controls->Add(this->SheildFormMassTextBox);
			this->SheildPanel->Controls->Add(this->SheildFormArmorTextBox);
			this->SheildPanel->Controls->Add(this->S_RechargeLabel);
			this->SheildPanel->Controls->Add(this->S_RearHPLabel);
			this->SheildPanel->Controls->Add(this->S_FrontHPLabel);
			this->SheildPanel->Controls->Add(this->S_DrainLabel);
			this->SheildPanel->Controls->Add(this->S_MassLabel);
			this->SheildPanel->Controls->Add(this->S_ArmorLabel);
			this->SheildPanel->Controls->Add(this->ClearSheildButton);
			this->SheildPanel->Controls->Add(this->CalcSheildButton);
			this->SheildPanel->Controls->Add(this->SheildOutputLabel);
			this->SheildPanel->Controls->Add(this->SheildInputLabel);
			this->SheildPanel->Location = System::Drawing::Point(12, 91);
			this->SheildPanel->Name = L"SheildPanel";
			this->SheildPanel->Size = System::Drawing::Size(437, 235);
			this->SheildPanel->TabIndex = 167;
			// 
			// S_RechargeOutputValueLabel
			// 
			this->S_RechargeOutputValueLabel->AutoSize = true;
			this->S_RechargeOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_RechargeOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_RechargeOutputValueLabel->Location = System::Drawing::Point(328, 166);
			this->S_RechargeOutputValueLabel->Name = L"S_RechargeOutputValueLabel";
			this->S_RechargeOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->S_RechargeOutputValueLabel->TabIndex = 204;
			this->S_RechargeOutputValueLabel->Text = L"No Input";
			// 
			// S_RearHPOutputValueLabel
			// 
			this->S_RearHPOutputValueLabel->AutoSize = true;
			this->S_RearHPOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_RearHPOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_RearHPOutputValueLabel->Location = System::Drawing::Point(328, 140);
			this->S_RearHPOutputValueLabel->Name = L"S_RearHPOutputValueLabel";
			this->S_RearHPOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->S_RearHPOutputValueLabel->TabIndex = 203;
			this->S_RearHPOutputValueLabel->Text = L"No Input";
			// 
			// S_FrontHPOutputValueLabel
			// 
			this->S_FrontHPOutputValueLabel->AutoSize = true;
			this->S_FrontHPOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_FrontHPOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_FrontHPOutputValueLabel->Location = System::Drawing::Point(328, 114);
			this->S_FrontHPOutputValueLabel->Name = L"S_FrontHPOutputValueLabel";
			this->S_FrontHPOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->S_FrontHPOutputValueLabel->TabIndex = 202;
			this->S_FrontHPOutputValueLabel->Text = L"No Input";
			// 
			// S_MassOutputValueLabel
			// 
			this->S_MassOutputValueLabel->AutoSize = true;
			this->S_MassOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_MassOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_MassOutputValueLabel->Location = System::Drawing::Point(328, 88);
			this->S_MassOutputValueLabel->Name = L"S_MassOutputValueLabel";
			this->S_MassOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->S_MassOutputValueLabel->TabIndex = 201;
			this->S_MassOutputValueLabel->Text = L"No Input";
			// 
			// S_DrainOutputValueLabel
			// 
			this->S_DrainOutputValueLabel->AutoSize = true;
			this->S_DrainOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_DrainOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_DrainOutputValueLabel->Location = System::Drawing::Point(328, 62);
			this->S_DrainOutputValueLabel->Name = L"S_DrainOutputValueLabel";
			this->S_DrainOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->S_DrainOutputValueLabel->TabIndex = 200;
			this->S_DrainOutputValueLabel->Text = L"No Input";
			// 
			// S_ArmorOutputValueLabel
			// 
			this->S_ArmorOutputValueLabel->AutoSize = true;
			this->S_ArmorOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_ArmorOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_ArmorOutputValueLabel->Location = System::Drawing::Point(328, 36);
			this->S_ArmorOutputValueLabel->Name = L"S_ArmorOutputValueLabel";
			this->S_ArmorOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->S_ArmorOutputValueLabel->TabIndex = 199;
			this->S_ArmorOutputValueLabel->Text = L"No Input";
			// 
			// S_RechargeOutputLabel
			// 
			this->S_RechargeOutputLabel->AutoSize = true;
			this->S_RechargeOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_RechargeOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_RechargeOutputLabel->Location = System::Drawing::Point(227, 166);
			this->S_RechargeOutputLabel->Name = L"S_RechargeOutputLabel";
			this->S_RechargeOutputLabel->Size = System::Drawing::Size(75, 16);
			this->S_RechargeOutputLabel->TabIndex = 193;
			this->S_RechargeOutputLabel->Text = L"Recharge:";
			// 
			// S_RearHPOutputLabel
			// 
			this->S_RearHPOutputLabel->AutoSize = true;
			this->S_RearHPOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_RearHPOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_RearHPOutputLabel->Location = System::Drawing::Point(227, 140);
			this->S_RearHPOutputLabel->Name = L"S_RearHPOutputLabel";
			this->S_RearHPOutputLabel->Size = System::Drawing::Size(65, 16);
			this->S_RearHPOutputLabel->TabIndex = 192;
			this->S_RearHPOutputLabel->Text = L"Rear HP:";
			// 
			// S_FrontHPOutputLabel
			// 
			this->S_FrontHPOutputLabel->AutoSize = true;
			this->S_FrontHPOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_FrontHPOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_FrontHPOutputLabel->Location = System::Drawing::Point(227, 114);
			this->S_FrontHPOutputLabel->Name = L"S_FrontHPOutputLabel";
			this->S_FrontHPOutputLabel->Size = System::Drawing::Size(71, 16);
			this->S_FrontHPOutputLabel->TabIndex = 191;
			this->S_FrontHPOutputLabel->Text = L"Front HP:";
			// 
			// S_DrainOutputLabel
			// 
			this->S_DrainOutputLabel->AutoSize = true;
			this->S_DrainOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_DrainOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_DrainOutputLabel->Location = System::Drawing::Point(227, 62);
			this->S_DrainOutputLabel->Name = L"S_DrainOutputLabel";
			this->S_DrainOutputLabel->Size = System::Drawing::Size(47, 16);
			this->S_DrainOutputLabel->TabIndex = 190;
			this->S_DrainOutputLabel->Text = L"Drain:";
			// 
			// S_MassOutputLabel
			// 
			this->S_MassOutputLabel->AutoSize = true;
			this->S_MassOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_MassOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_MassOutputLabel->Location = System::Drawing::Point(227, 88);
			this->S_MassOutputLabel->Name = L"S_MassOutputLabel";
			this->S_MassOutputLabel->Size = System::Drawing::Size(47, 16);
			this->S_MassOutputLabel->TabIndex = 189;
			this->S_MassOutputLabel->Text = L"Mass:";
			// 
			// S_ArmorOutputLabel
			// 
			this->S_ArmorOutputLabel->AutoSize = true;
			this->S_ArmorOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_ArmorOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_ArmorOutputLabel->Location = System::Drawing::Point(227, 36);
			this->S_ArmorOutputLabel->Name = L"S_ArmorOutputLabel";
			this->S_ArmorOutputLabel->Size = System::Drawing::Size(52, 16);
			this->S_ArmorOutputLabel->TabIndex = 188;
			this->S_ArmorOutputLabel->Text = L"Armor:";
			// 
			// SheildFormRechargeTextBox
			// 
			this->SheildFormRechargeTextBox->Location = System::Drawing::Point(110, 165);
			this->SheildFormRechargeTextBox->MaxLength = 10;
			this->SheildFormRechargeTextBox->Name = L"SheildFormRechargeTextBox";
			this->SheildFormRechargeTextBox->Size = System::Drawing::Size(100, 20);
			this->SheildFormRechargeTextBox->TabIndex = 181;
			this->SheildFormRechargeTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::SheildFormRechargeTextBox_KeyPress);
			this->SheildFormRechargeTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::SheildFormRechargeTextBox_TextChanged);
			// 
			// SheildFormBackHPTextBox
			// 
			this->SheildFormBackHPTextBox->Location = System::Drawing::Point(110, 139);
			this->SheildFormBackHPTextBox->MaxLength = 10;
			this->SheildFormBackHPTextBox->Name = L"SheildFormBackHPTextBox";
			this->SheildFormBackHPTextBox->Size = System::Drawing::Size(100, 20);
			this->SheildFormBackHPTextBox->TabIndex = 180;
			this->SheildFormBackHPTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::SheildFormBackHPTextBox_KeyPress);
			this->SheildFormBackHPTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::SheildFormBackHPTextBox_TextChanged);
			// 
			// SheildFormFrontHPTextBox
			// 
			this->SheildFormFrontHPTextBox->Location = System::Drawing::Point(110, 113);
			this->SheildFormFrontHPTextBox->MaxLength = 10;
			this->SheildFormFrontHPTextBox->Name = L"SheildFormFrontHPTextBox";
			this->SheildFormFrontHPTextBox->Size = System::Drawing::Size(100, 20);
			this->SheildFormFrontHPTextBox->TabIndex = 179;
			this->SheildFormFrontHPTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::SheildFormFrontHPTextBox_KeyPress);
			this->SheildFormFrontHPTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::SheildFormFrontHPTextBox_TextChanged);
			// 
			// SheildFormDrainTextBox
			// 
			this->SheildFormDrainTextBox->Location = System::Drawing::Point(110, 61);
			this->SheildFormDrainTextBox->MaxLength = 10;
			this->SheildFormDrainTextBox->Name = L"SheildFormDrainTextBox";
			this->SheildFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->SheildFormDrainTextBox->TabIndex = 177;
			this->SheildFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::SheildFormDrainTextBox_KeyPress);
			this->SheildFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::SheildFormDrainTextBox_TextChanged);
			// 
			// SheildFormMassTextBox
			// 
			this->SheildFormMassTextBox->Location = System::Drawing::Point(110, 87);
			this->SheildFormMassTextBox->MaxLength = 10;
			this->SheildFormMassTextBox->Name = L"SheildFormMassTextBox";
			this->SheildFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->SheildFormMassTextBox->TabIndex = 178;
			this->SheildFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::SheildFormMassTextBox_KeyPress);
			this->SheildFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::SheildFormMassTextBox_TextChanged);
			// 
			// SheildFormArmorTextBox
			// 
			this->SheildFormArmorTextBox->Location = System::Drawing::Point(110, 35);
			this->SheildFormArmorTextBox->MaxLength = 10;
			this->SheildFormArmorTextBox->Name = L"SheildFormArmorTextBox";
			this->SheildFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->SheildFormArmorTextBox->TabIndex = 176;
			this->SheildFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::SheildFormArmorTextBox_KeyPress);
			this->SheildFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::SheildFormArmorTextBox_TextChanged);
			// 
			// S_RechargeLabel
			// 
			this->S_RechargeLabel->AutoSize = true;
			this->S_RechargeLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_RechargeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_RechargeLabel->Location = System::Drawing::Point(9, 166);
			this->S_RechargeLabel->Name = L"S_RechargeLabel";
			this->S_RechargeLabel->Size = System::Drawing::Size(75, 16);
			this->S_RechargeLabel->TabIndex = 187;
			this->S_RechargeLabel->Text = L"Recharge:";
			// 
			// S_RearHPLabel
			// 
			this->S_RearHPLabel->AutoSize = true;
			this->S_RearHPLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_RearHPLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_RearHPLabel->Location = System::Drawing::Point(9, 140);
			this->S_RearHPLabel->Name = L"S_RearHPLabel";
			this->S_RearHPLabel->Size = System::Drawing::Size(65, 16);
			this->S_RearHPLabel->TabIndex = 186;
			this->S_RearHPLabel->Text = L"Rear HP:";
			// 
			// S_FrontHPLabel
			// 
			this->S_FrontHPLabel->AutoSize = true;
			this->S_FrontHPLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_FrontHPLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_FrontHPLabel->Location = System::Drawing::Point(9, 114);
			this->S_FrontHPLabel->Name = L"S_FrontHPLabel";
			this->S_FrontHPLabel->Size = System::Drawing::Size(71, 16);
			this->S_FrontHPLabel->TabIndex = 185;
			this->S_FrontHPLabel->Text = L"Front HP:";
			// 
			// S_DrainLabel
			// 
			this->S_DrainLabel->AutoSize = true;
			this->S_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_DrainLabel->Location = System::Drawing::Point(9, 62);
			this->S_DrainLabel->Name = L"S_DrainLabel";
			this->S_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->S_DrainLabel->TabIndex = 184;
			this->S_DrainLabel->Text = L"Drain:";
			// 
			// S_MassLabel
			// 
			this->S_MassLabel->AutoSize = true;
			this->S_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_MassLabel->Location = System::Drawing::Point(9, 88);
			this->S_MassLabel->Name = L"S_MassLabel";
			this->S_MassLabel->Size = System::Drawing::Size(47, 16);
			this->S_MassLabel->TabIndex = 183;
			this->S_MassLabel->Text = L"Mass:";
			// 
			// S_ArmorLabel
			// 
			this->S_ArmorLabel->AutoSize = true;
			this->S_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->S_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->S_ArmorLabel->Location = System::Drawing::Point(9, 36);
			this->S_ArmorLabel->Name = L"S_ArmorLabel";
			this->S_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->S_ArmorLabel->TabIndex = 182;
			this->S_ArmorLabel->Text = L"Armor:";
			// 
			// ClearSheildButton
			// 
			this->ClearSheildButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ClearSheildButton->ForeColor = System::Drawing::Color::Black;
			this->ClearSheildButton->Location = System::Drawing::Point(221, 196);
			this->ClearSheildButton->Name = L"ClearSheildButton";
			this->ClearSheildButton->Size = System::Drawing::Size(75, 23);
			this->ClearSheildButton->TabIndex = 175;
			this->ClearSheildButton->Text = L"Clear";
			this->ClearSheildButton->UseVisualStyleBackColor = true;
			this->ClearSheildButton->Click += gcnew System::EventHandler(this, &RECalc::ClearSheildButton_Click);
			// 
			// CalcSheildButton
			// 
			this->CalcSheildButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->CalcSheildButton->ForeColor = System::Drawing::Color::Black;
			this->CalcSheildButton->Location = System::Drawing::Point(140, 196);
			this->CalcSheildButton->Name = L"CalcSheildButton";
			this->CalcSheildButton->Size = System::Drawing::Size(75, 23);
			this->CalcSheildButton->TabIndex = 174;
			this->CalcSheildButton->Text = L"Calculate!";
			this->CalcSheildButton->UseVisualStyleBackColor = true;
			this->CalcSheildButton->Click += gcnew System::EventHandler(this, &RECalc::CalcSheildButton_Click);
			// 
			// SheildOutputLabel
			// 
			this->SheildOutputLabel->AutoSize = true;
			this->SheildOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->SheildOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildOutputLabel->Location = System::Drawing::Point(283, 13);
			this->SheildOutputLabel->Name = L"SheildOutputLabel";
			this->SheildOutputLabel->Size = System::Drawing::Size(51, 14);
			this->SheildOutputLabel->TabIndex = 159;
			this->SheildOutputLabel->Text = L"Output";
			// 
			// SheildInputLabel
			// 
			this->SheildInputLabel->AutoSize = true;
			this->SheildInputLabel->BackColor = System::Drawing::Color::Transparent;
			this->SheildInputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildInputLabel->Location = System::Drawing::Point(84, 13);
			this->SheildInputLabel->Name = L"SheildInputLabel";
			this->SheildInputLabel->Size = System::Drawing::Size(41, 14);
			this->SheildInputLabel->TabIndex = 158;
			this->SheildInputLabel->Text = L"Input";
			// 
			// DroidPanel
			// 
			this->DroidPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"DroidPanel.BackgroundImage")));
			this->DroidPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DroidPanel->Controls->Add(this->D_SpeedOutputValueLabel);
			this->DroidPanel->Controls->Add(this->D_MassOutputValueLabel);
			this->DroidPanel->Controls->Add(this->D_DrainOutputValueLabel);
			this->DroidPanel->Controls->Add(this->D_ArmorOutputValueLabel);
			this->DroidPanel->Controls->Add(this->D_SpeedOutputLabel);
			this->DroidPanel->Controls->Add(this->D_DrainOutputLabel);
			this->DroidPanel->Controls->Add(this->D_MassOutputLabel);
			this->DroidPanel->Controls->Add(this->D_ArmorOutputLabel);
			this->DroidPanel->Controls->Add(this->DroidFormSpeedTextBox);
			this->DroidPanel->Controls->Add(this->D_SpeedLabel);
			this->DroidPanel->Controls->Add(this->DroidFormDrainTextBox);
			this->DroidPanel->Controls->Add(this->DroidFormMassTextBox);
			this->DroidPanel->Controls->Add(this->DroidFormArmorTextBox);
			this->DroidPanel->Controls->Add(this->D_DrainLabel);
			this->DroidPanel->Controls->Add(this->D_MassLabel);
			this->DroidPanel->Controls->Add(this->D_ArmorLabel);
			this->DroidPanel->Controls->Add(this->DroidOutputLabel);
			this->DroidPanel->Controls->Add(this->DroidInputLabel);
			this->DroidPanel->Controls->Add(this->ClearDriodButton);
			this->DroidPanel->Controls->Add(this->CalcDroidButton);
			this->DroidPanel->Location = System::Drawing::Point(12, 91);
			this->DroidPanel->Name = L"DroidPanel";
			this->DroidPanel->Size = System::Drawing::Size(437, 208);
			this->DroidPanel->TabIndex = 168;
			// 
			// D_SpeedOutputValueLabel
			// 
			this->D_SpeedOutputValueLabel->AutoSize = true;
			this->D_SpeedOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_SpeedOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_SpeedOutputValueLabel->Location = System::Drawing::Point(328, 140);
			this->D_SpeedOutputValueLabel->Name = L"D_SpeedOutputValueLabel";
			this->D_SpeedOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->D_SpeedOutputValueLabel->TabIndex = 195;
			this->D_SpeedOutputValueLabel->Text = L"No Input";
			// 
			// D_MassOutputValueLabel
			// 
			this->D_MassOutputValueLabel->AutoSize = true;
			this->D_MassOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_MassOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_MassOutputValueLabel->Location = System::Drawing::Point(328, 106);
			this->D_MassOutputValueLabel->Name = L"D_MassOutputValueLabel";
			this->D_MassOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->D_MassOutputValueLabel->TabIndex = 194;
			this->D_MassOutputValueLabel->Text = L"No Input";
			// 
			// D_DrainOutputValueLabel
			// 
			this->D_DrainOutputValueLabel->AutoSize = true;
			this->D_DrainOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_DrainOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_DrainOutputValueLabel->Location = System::Drawing::Point(328, 71);
			this->D_DrainOutputValueLabel->Name = L"D_DrainOutputValueLabel";
			this->D_DrainOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->D_DrainOutputValueLabel->TabIndex = 193;
			this->D_DrainOutputValueLabel->Text = L"No Input";
			// 
			// D_ArmorOutputValueLabel
			// 
			this->D_ArmorOutputValueLabel->AutoSize = true;
			this->D_ArmorOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_ArmorOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_ArmorOutputValueLabel->Location = System::Drawing::Point(328, 36);
			this->D_ArmorOutputValueLabel->Name = L"D_ArmorOutputValueLabel";
			this->D_ArmorOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->D_ArmorOutputValueLabel->TabIndex = 192;
			this->D_ArmorOutputValueLabel->Text = L"No Input";
			// 
			// D_SpeedOutputLabel
			// 
			this->D_SpeedOutputLabel->AutoSize = true;
			this->D_SpeedOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_SpeedOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_SpeedOutputLabel->Location = System::Drawing::Point(227, 141);
			this->D_SpeedOutputLabel->Name = L"D_SpeedOutputLabel";
			this->D_SpeedOutputLabel->Size = System::Drawing::Size(55, 16);
			this->D_SpeedOutputLabel->TabIndex = 191;
			this->D_SpeedOutputLabel->Text = L"Speed:";
			// 
			// D_DrainOutputLabel
			// 
			this->D_DrainOutputLabel->AutoSize = true;
			this->D_DrainOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_DrainOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_DrainOutputLabel->Location = System::Drawing::Point(227, 71);
			this->D_DrainOutputLabel->Name = L"D_DrainOutputLabel";
			this->D_DrainOutputLabel->Size = System::Drawing::Size(47, 16);
			this->D_DrainOutputLabel->TabIndex = 190;
			this->D_DrainOutputLabel->Text = L"Drain:";
			// 
			// D_MassOutputLabel
			// 
			this->D_MassOutputLabel->AutoSize = true;
			this->D_MassOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_MassOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_MassOutputLabel->Location = System::Drawing::Point(227, 106);
			this->D_MassOutputLabel->Name = L"D_MassOutputLabel";
			this->D_MassOutputLabel->Size = System::Drawing::Size(47, 16);
			this->D_MassOutputLabel->TabIndex = 189;
			this->D_MassOutputLabel->Text = L"Mass:";
			// 
			// D_ArmorOutputLabel
			// 
			this->D_ArmorOutputLabel->AutoSize = true;
			this->D_ArmorOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_ArmorOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_ArmorOutputLabel->Location = System::Drawing::Point(227, 36);
			this->D_ArmorOutputLabel->Name = L"D_ArmorOutputLabel";
			this->D_ArmorOutputLabel->Size = System::Drawing::Size(52, 16);
			this->D_ArmorOutputLabel->TabIndex = 188;
			this->D_ArmorOutputLabel->Text = L"Armor:";
			// 
			// DroidFormSpeedTextBox
			// 
			this->DroidFormSpeedTextBox->Location = System::Drawing::Point(110, 140);
			this->DroidFormSpeedTextBox->MaxLength = 10;
			this->DroidFormSpeedTextBox->Name = L"DroidFormSpeedTextBox";
			this->DroidFormSpeedTextBox->Size = System::Drawing::Size(100, 20);
			this->DroidFormSpeedTextBox->TabIndex = 183;
			this->DroidFormSpeedTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::DroidFormSpeedTextBox_KeyPress);
			this->DroidFormSpeedTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::DroidFormSpeedTextBox_TextChanged);
			// 
			// D_SpeedLabel
			// 
			this->D_SpeedLabel->AutoSize = true;
			this->D_SpeedLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_SpeedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_SpeedLabel->Location = System::Drawing::Point(12, 141);
			this->D_SpeedLabel->Name = L"D_SpeedLabel";
			this->D_SpeedLabel->Size = System::Drawing::Size(55, 16);
			this->D_SpeedLabel->TabIndex = 187;
			this->D_SpeedLabel->Text = L"Speed:";
			// 
			// DroidFormDrainTextBox
			// 
			this->DroidFormDrainTextBox->Location = System::Drawing::Point(110, 70);
			this->DroidFormDrainTextBox->MaxLength = 10;
			this->DroidFormDrainTextBox->Name = L"DroidFormDrainTextBox";
			this->DroidFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->DroidFormDrainTextBox->TabIndex = 181;
			this->DroidFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::BoosterFormDrainTextBox_KeyPress);
			this->DroidFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::DroidFormDrainTextBox_TextChanged);
			// 
			// DroidFormMassTextBox
			// 
			this->DroidFormMassTextBox->Location = System::Drawing::Point(110, 105);
			this->DroidFormMassTextBox->MaxLength = 10;
			this->DroidFormMassTextBox->Name = L"DroidFormMassTextBox";
			this->DroidFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->DroidFormMassTextBox->TabIndex = 182;
			this->DroidFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::DroidFormMassTextBox_KeyPress);
			this->DroidFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::DroidFormMassTextBox_TextChanged);
			// 
			// DroidFormArmorTextBox
			// 
			this->DroidFormArmorTextBox->Location = System::Drawing::Point(110, 35);
			this->DroidFormArmorTextBox->MaxLength = 10;
			this->DroidFormArmorTextBox->Name = L"DroidFormArmorTextBox";
			this->DroidFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->DroidFormArmorTextBox->TabIndex = 180;
			this->DroidFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::DroidFormArmorTextBox_KeyPress);
			this->DroidFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::DroidFormArmorTextBox_TextChanged);
			// 
			// D_DrainLabel
			// 
			this->D_DrainLabel->AutoSize = true;
			this->D_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_DrainLabel->Location = System::Drawing::Point(12, 71);
			this->D_DrainLabel->Name = L"D_DrainLabel";
			this->D_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->D_DrainLabel->TabIndex = 186;
			this->D_DrainLabel->Text = L"Drain:";
			// 
			// D_MassLabel
			// 
			this->D_MassLabel->AutoSize = true;
			this->D_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_MassLabel->Location = System::Drawing::Point(12, 106);
			this->D_MassLabel->Name = L"D_MassLabel";
			this->D_MassLabel->Size = System::Drawing::Size(47, 16);
			this->D_MassLabel->TabIndex = 185;
			this->D_MassLabel->Text = L"Mass:";
			// 
			// D_ArmorLabel
			// 
			this->D_ArmorLabel->AutoSize = true;
			this->D_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->D_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D_ArmorLabel->Location = System::Drawing::Point(12, 36);
			this->D_ArmorLabel->Name = L"D_ArmorLabel";
			this->D_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->D_ArmorLabel->TabIndex = 184;
			this->D_ArmorLabel->Text = L"Armor:";
			// 
			// DroidOutputLabel
			// 
			this->DroidOutputLabel->AutoSize = true;
			this->DroidOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->DroidOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DroidOutputLabel->Location = System::Drawing::Point(283, 13);
			this->DroidOutputLabel->Name = L"DroidOutputLabel";
			this->DroidOutputLabel->Size = System::Drawing::Size(51, 14);
			this->DroidOutputLabel->TabIndex = 179;
			this->DroidOutputLabel->Text = L"Output";
			// 
			// DroidInputLabel
			// 
			this->DroidInputLabel->AutoSize = true;
			this->DroidInputLabel->BackColor = System::Drawing::Color::Transparent;
			this->DroidInputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DroidInputLabel->Location = System::Drawing::Point(84, 13);
			this->DroidInputLabel->Name = L"DroidInputLabel";
			this->DroidInputLabel->Size = System::Drawing::Size(41, 14);
			this->DroidInputLabel->TabIndex = 178;
			this->DroidInputLabel->Text = L"Input";
			// 
			// ClearDriodButton
			// 
			this->ClearDriodButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ClearDriodButton->ForeColor = System::Drawing::Color::Black;
			this->ClearDriodButton->Location = System::Drawing::Point(221, 169);
			this->ClearDriodButton->Name = L"ClearDriodButton";
			this->ClearDriodButton->Size = System::Drawing::Size(75, 23);
			this->ClearDriodButton->TabIndex = 177;
			this->ClearDriodButton->Text = L"Clear";
			this->ClearDriodButton->UseVisualStyleBackColor = true;
			this->ClearDriodButton->Click += gcnew System::EventHandler(this, &RECalc::ClearDroidButton_Click);
			// 
			// CalcDroidButton
			// 
			this->CalcDroidButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->CalcDroidButton->ForeColor = System::Drawing::Color::Black;
			this->CalcDroidButton->Location = System::Drawing::Point(140, 169);
			this->CalcDroidButton->Name = L"CalcDroidButton";
			this->CalcDroidButton->Size = System::Drawing::Size(75, 23);
			this->CalcDroidButton->TabIndex = 176;
			this->CalcDroidButton->Text = L"Calculate!";
			this->CalcDroidButton->UseVisualStyleBackColor = true;
			this->CalcDroidButton->Click += gcnew System::EventHandler(this, &RECalc::CalcDroidButton_Click);
			// 
			// CapacitorPanel
			// 
			this->CapacitorPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"CapacitorPanel.BackgroundImage")));
			this->CapacitorPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CapacitorPanel->Controls->Add(this->C_RechargeOutputValueLabel);
			this->CapacitorPanel->Controls->Add(this->C_EnergyOutputValueLabel);
			this->CapacitorPanel->Controls->Add(this->C_MassOutputValueLabel);
			this->CapacitorPanel->Controls->Add(this->C_DrainOutputValueLabel);
			this->CapacitorPanel->Controls->Add(this->C_ArmorOutputValueLabel);
			this->CapacitorPanel->Controls->Add(this->C_RechargeOutputLabel);
			this->CapacitorPanel->Controls->Add(this->C_EnergyOutputLabel);
			this->CapacitorPanel->Controls->Add(this->C_DrainOutputLabel);
			this->CapacitorPanel->Controls->Add(this->C_MassOutputLabel);
			this->CapacitorPanel->Controls->Add(this->C_ArmorOutputLabel);
			this->CapacitorPanel->Controls->Add(this->C_RechargeLabel);
			this->CapacitorPanel->Controls->Add(this->CapacitorFormRechargeTextBox);
			this->CapacitorPanel->Controls->Add(this->CapacitorFormEnergyTextBox);
			this->CapacitorPanel->Controls->Add(this->C_EnergyLabel);
			this->CapacitorPanel->Controls->Add(this->CapacitorFormDrainTextBox);
			this->CapacitorPanel->Controls->Add(this->CapacitorFormMassTextBox);
			this->CapacitorPanel->Controls->Add(this->CapacitorFormArmorTextBox);
			this->CapacitorPanel->Controls->Add(this->C_DrainLabel);
			this->CapacitorPanel->Controls->Add(this->C_MassLabel);
			this->CapacitorPanel->Controls->Add(this->C_ArmorLabel);
			this->CapacitorPanel->Controls->Add(this->CapacitorOutputLabel);
			this->CapacitorPanel->Controls->Add(this->CapacitorInputLabel);
			this->CapacitorPanel->Controls->Add(this->ClearCapacitorButton);
			this->CapacitorPanel->Controls->Add(this->CalcCapacitorButton);
			this->CapacitorPanel->Location = System::Drawing::Point(12, 91);
			this->CapacitorPanel->Name = L"CapacitorPanel";
			this->CapacitorPanel->Size = System::Drawing::Size(437, 235);
			this->CapacitorPanel->TabIndex = 169;
			// 
			// C_RechargeOutputValueLabel
			// 
			this->C_RechargeOutputValueLabel->AutoSize = true;
			this->C_RechargeOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_RechargeOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_RechargeOutputValueLabel->Location = System::Drawing::Point(328, 173);
			this->C_RechargeOutputValueLabel->Name = L"C_RechargeOutputValueLabel";
			this->C_RechargeOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->C_RechargeOutputValueLabel->TabIndex = 201;
			this->C_RechargeOutputValueLabel->Text = L"No Input";
			// 
			// C_EnergyOutputValueLabel
			// 
			this->C_EnergyOutputValueLabel->AutoSize = true;
			this->C_EnergyOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_EnergyOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_EnergyOutputValueLabel->Location = System::Drawing::Point(328, 139);
			this->C_EnergyOutputValueLabel->Name = L"C_EnergyOutputValueLabel";
			this->C_EnergyOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->C_EnergyOutputValueLabel->TabIndex = 200;
			this->C_EnergyOutputValueLabel->Text = L"No Input";
			// 
			// C_MassOutputValueLabel
			// 
			this->C_MassOutputValueLabel->AutoSize = true;
			this->C_MassOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_MassOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_MassOutputValueLabel->Location = System::Drawing::Point(328, 105);
			this->C_MassOutputValueLabel->Name = L"C_MassOutputValueLabel";
			this->C_MassOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->C_MassOutputValueLabel->TabIndex = 199;
			this->C_MassOutputValueLabel->Text = L"No Input";
			// 
			// C_DrainOutputValueLabel
			// 
			this->C_DrainOutputValueLabel->AutoSize = true;
			this->C_DrainOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_DrainOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_DrainOutputValueLabel->Location = System::Drawing::Point(328, 71);
			this->C_DrainOutputValueLabel->Name = L"C_DrainOutputValueLabel";
			this->C_DrainOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->C_DrainOutputValueLabel->TabIndex = 198;
			this->C_DrainOutputValueLabel->Text = L"No Input";
			// 
			// C_ArmorOutputValueLabel
			// 
			this->C_ArmorOutputValueLabel->AutoSize = true;
			this->C_ArmorOutputValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_ArmorOutputValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_ArmorOutputValueLabel->Location = System::Drawing::Point(328, 36);
			this->C_ArmorOutputValueLabel->Name = L"C_ArmorOutputValueLabel";
			this->C_ArmorOutputValueLabel->Size = System::Drawing::Size(65, 16);
			this->C_ArmorOutputValueLabel->TabIndex = 197;
			this->C_ArmorOutputValueLabel->Text = L"No Input";
			// 
			// C_RechargeOutputLabel
			// 
			this->C_RechargeOutputLabel->AutoSize = true;
			this->C_RechargeOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_RechargeOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_RechargeOutputLabel->Location = System::Drawing::Point(228, 173);
			this->C_RechargeOutputLabel->Name = L"C_RechargeOutputLabel";
			this->C_RechargeOutputLabel->Size = System::Drawing::Size(75, 16);
			this->C_RechargeOutputLabel->TabIndex = 196;
			this->C_RechargeOutputLabel->Text = L"Recharge:";
			// 
			// C_EnergyOutputLabel
			// 
			this->C_EnergyOutputLabel->AutoSize = true;
			this->C_EnergyOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_EnergyOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_EnergyOutputLabel->Location = System::Drawing::Point(228, 139);
			this->C_EnergyOutputLabel->Name = L"C_EnergyOutputLabel";
			this->C_EnergyOutputLabel->Size = System::Drawing::Size(59, 16);
			this->C_EnergyOutputLabel->TabIndex = 195;
			this->C_EnergyOutputLabel->Text = L"Energy:";
			// 
			// C_DrainOutputLabel
			// 
			this->C_DrainOutputLabel->AutoSize = true;
			this->C_DrainOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_DrainOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_DrainOutputLabel->Location = System::Drawing::Point(227, 71);
			this->C_DrainOutputLabel->Name = L"C_DrainOutputLabel";
			this->C_DrainOutputLabel->Size = System::Drawing::Size(47, 16);
			this->C_DrainOutputLabel->TabIndex = 194;
			this->C_DrainOutputLabel->Text = L"Drain:";
			// 
			// C_MassOutputLabel
			// 
			this->C_MassOutputLabel->AutoSize = true;
			this->C_MassOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_MassOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_MassOutputLabel->Location = System::Drawing::Point(228, 105);
			this->C_MassOutputLabel->Name = L"C_MassOutputLabel";
			this->C_MassOutputLabel->Size = System::Drawing::Size(47, 16);
			this->C_MassOutputLabel->TabIndex = 193;
			this->C_MassOutputLabel->Text = L"Mass:";
			// 
			// C_ArmorOutputLabel
			// 
			this->C_ArmorOutputLabel->AutoSize = true;
			this->C_ArmorOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_ArmorOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_ArmorOutputLabel->Location = System::Drawing::Point(228, 36);
			this->C_ArmorOutputLabel->Name = L"C_ArmorOutputLabel";
			this->C_ArmorOutputLabel->Size = System::Drawing::Size(52, 16);
			this->C_ArmorOutputLabel->TabIndex = 192;
			this->C_ArmorOutputLabel->Text = L"Armor:";
			// 
			// C_RechargeLabel
			// 
			this->C_RechargeLabel->AutoSize = true;
			this->C_RechargeLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_RechargeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_RechargeLabel->Location = System::Drawing::Point(12, 173);
			this->C_RechargeLabel->Name = L"C_RechargeLabel";
			this->C_RechargeLabel->Size = System::Drawing::Size(75, 16);
			this->C_RechargeLabel->TabIndex = 191;
			this->C_RechargeLabel->Text = L"Recharge:";
			// 
			// CapacitorFormRechargeTextBox
			// 
			this->CapacitorFormRechargeTextBox->Location = System::Drawing::Point(110, 172);
			this->CapacitorFormRechargeTextBox->MaxLength = 10;
			this->CapacitorFormRechargeTextBox->Name = L"CapacitorFormRechargeTextBox";
			this->CapacitorFormRechargeTextBox->Size = System::Drawing::Size(100, 20);
			this->CapacitorFormRechargeTextBox->TabIndex = 186;
			this->CapacitorFormRechargeTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::CapacitorFormRechargeTextBox_KeyPress);
			this->CapacitorFormRechargeTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::CapacitorFormRechargeTextBox_TextChanged);
			// 
			// CapacitorFormEnergyTextBox
			// 
			this->CapacitorFormEnergyTextBox->Location = System::Drawing::Point(110, 138);
			this->CapacitorFormEnergyTextBox->MaxLength = 10;
			this->CapacitorFormEnergyTextBox->Name = L"CapacitorFormEnergyTextBox";
			this->CapacitorFormEnergyTextBox->Size = System::Drawing::Size(100, 20);
			this->CapacitorFormEnergyTextBox->TabIndex = 185;
			this->CapacitorFormEnergyTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::CapacitorFormEnergyTextBox_KeyPress);
			this->CapacitorFormEnergyTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::CapacitorFormEnergyTextBox_TextChanged);
			// 
			// C_EnergyLabel
			// 
			this->C_EnergyLabel->AutoSize = true;
			this->C_EnergyLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_EnergyLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_EnergyLabel->Location = System::Drawing::Point(12, 139);
			this->C_EnergyLabel->Name = L"C_EnergyLabel";
			this->C_EnergyLabel->Size = System::Drawing::Size(59, 16);
			this->C_EnergyLabel->TabIndex = 190;
			this->C_EnergyLabel->Text = L"Energy:";
			// 
			// CapacitorFormDrainTextBox
			// 
			this->CapacitorFormDrainTextBox->Location = System::Drawing::Point(110, 70);
			this->CapacitorFormDrainTextBox->MaxLength = 10;
			this->CapacitorFormDrainTextBox->Name = L"CapacitorFormDrainTextBox";
			this->CapacitorFormDrainTextBox->Size = System::Drawing::Size(100, 20);
			this->CapacitorFormDrainTextBox->TabIndex = 183;
			this->CapacitorFormDrainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::CapacitorFormDrainTextBox_KeyPress);
			this->CapacitorFormDrainTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::CapacitorFormDrainTextBox_TextChanged);
			// 
			// CapacitorFormMassTextBox
			// 
			this->CapacitorFormMassTextBox->Location = System::Drawing::Point(110, 104);
			this->CapacitorFormMassTextBox->MaxLength = 10;
			this->CapacitorFormMassTextBox->Name = L"CapacitorFormMassTextBox";
			this->CapacitorFormMassTextBox->Size = System::Drawing::Size(100, 20);
			this->CapacitorFormMassTextBox->TabIndex = 184;
			this->CapacitorFormMassTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::CapacitorFormMassTextBox_KeyPress);
			this->CapacitorFormMassTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::CapacitorFormMassTextBox_TextChanged);
			// 
			// CapacitorFormArmorTextBox
			// 
			this->CapacitorFormArmorTextBox->Location = System::Drawing::Point(110, 36);
			this->CapacitorFormArmorTextBox->MaxLength = 10;
			this->CapacitorFormArmorTextBox->Name = L"CapacitorFormArmorTextBox";
			this->CapacitorFormArmorTextBox->Size = System::Drawing::Size(100, 20);
			this->CapacitorFormArmorTextBox->TabIndex = 182;
			this->CapacitorFormArmorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RECalc::CapacitorFormArmorTextBox_KeyPress);
			this->CapacitorFormArmorTextBox->TextChanged += gcnew System::EventHandler(this, &RECalc::CapacitorFormArmorTextBox_TextChanged);
			// 
			// C_DrainLabel
			// 
			this->C_DrainLabel->AutoSize = true;
			this->C_DrainLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_DrainLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_DrainLabel->Location = System::Drawing::Point(12, 71);
			this->C_DrainLabel->Name = L"C_DrainLabel";
			this->C_DrainLabel->Size = System::Drawing::Size(47, 16);
			this->C_DrainLabel->TabIndex = 189;
			this->C_DrainLabel->Text = L"Drain:";
			// 
			// C_MassLabel
			// 
			this->C_MassLabel->AutoSize = true;
			this->C_MassLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_MassLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_MassLabel->Location = System::Drawing::Point(12, 105);
			this->C_MassLabel->Name = L"C_MassLabel";
			this->C_MassLabel->Size = System::Drawing::Size(47, 16);
			this->C_MassLabel->TabIndex = 188;
			this->C_MassLabel->Text = L"Mass:";
			// 
			// C_ArmorLabel
			// 
			this->C_ArmorLabel->AutoSize = true;
			this->C_ArmorLabel->BackColor = System::Drawing::Color::Transparent;
			this->C_ArmorLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->C_ArmorLabel->Location = System::Drawing::Point(12, 37);
			this->C_ArmorLabel->Name = L"C_ArmorLabel";
			this->C_ArmorLabel->Size = System::Drawing::Size(52, 16);
			this->C_ArmorLabel->TabIndex = 187;
			this->C_ArmorLabel->Text = L"Armor:";
			// 
			// CapacitorOutputLabel
			// 
			this->CapacitorOutputLabel->AutoSize = true;
			this->CapacitorOutputLabel->BackColor = System::Drawing::Color::Transparent;
			this->CapacitorOutputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorOutputLabel->Location = System::Drawing::Point(283, 13);
			this->CapacitorOutputLabel->Name = L"CapacitorOutputLabel";
			this->CapacitorOutputLabel->Size = System::Drawing::Size(51, 14);
			this->CapacitorOutputLabel->TabIndex = 181;
			this->CapacitorOutputLabel->Text = L"Output";
			// 
			// CapacitorInputLabel
			// 
			this->CapacitorInputLabel->AutoSize = true;
			this->CapacitorInputLabel->BackColor = System::Drawing::Color::Transparent;
			this->CapacitorInputLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorInputLabel->Location = System::Drawing::Point(84, 13);
			this->CapacitorInputLabel->Name = L"CapacitorInputLabel";
			this->CapacitorInputLabel->Size = System::Drawing::Size(41, 14);
			this->CapacitorInputLabel->TabIndex = 180;
			this->CapacitorInputLabel->Text = L"Input";
			// 
			// ClearCapacitorButton
			// 
			this->ClearCapacitorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ClearCapacitorButton->ForeColor = System::Drawing::Color::Black;
			this->ClearCapacitorButton->Location = System::Drawing::Point(221, 201);
			this->ClearCapacitorButton->Name = L"ClearCapacitorButton";
			this->ClearCapacitorButton->Size = System::Drawing::Size(75, 23);
			this->ClearCapacitorButton->TabIndex = 179;
			this->ClearCapacitorButton->Text = L"Clear";
			this->ClearCapacitorButton->UseVisualStyleBackColor = true;
			this->ClearCapacitorButton->Click += gcnew System::EventHandler(this, &RECalc::ClearCapacitorButton_Click);
			// 
			// CalcCapacitorButton
			// 
			this->CalcCapacitorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->CalcCapacitorButton->ForeColor = System::Drawing::Color::Black;
			this->CalcCapacitorButton->Location = System::Drawing::Point(140, 201);
			this->CalcCapacitorButton->Name = L"CalcCapacitorButton";
			this->CalcCapacitorButton->Size = System::Drawing::Size(75, 23);
			this->CalcCapacitorButton->TabIndex = 178;
			this->CalcCapacitorButton->Text = L"Calculate!";
			this->CalcCapacitorButton->UseVisualStyleBackColor = true;
			this->CalcCapacitorButton->Click += gcnew System::EventHandler(this, &RECalc::CalcCapacitorButton_Click);
			// 
			// RECalc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->ClientSize = System::Drawing::Size(461, 415);
			this->Controls->Add(this->CompInfoPanel);
			this->Controls->Add(this->DroidPanel);
			this->Controls->Add(this->ArmorPanel);
			this->Controls->Add(this->SheildPanel);
			this->Controls->Add(this->EnginePanel);
			this->Controls->Add(this->ReactorPanel);
			this->Controls->Add(this->BoosterPanel);
			this->Controls->Add(this->WeaponPanel);
			this->Controls->Add(this->CapacitorPanel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"RECalc";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Reverse Engineer Calculator";
			this->CompInfoPanel->ResumeLayout(false);
			this->CompInfoPanel->PerformLayout();
			this->WeaponPanel->ResumeLayout(false);
			this->WeaponPanel->PerformLayout();
			this->ReactorPanel->ResumeLayout(false);
			this->ReactorPanel->PerformLayout();
			this->ArmorPanel->ResumeLayout(false);
			this->ArmorPanel->PerformLayout();
			this->EnginePanel->ResumeLayout(false);
			this->EnginePanel->PerformLayout();
			this->BoosterPanel->ResumeLayout(false);
			this->BoosterPanel->PerformLayout();
			this->SheildPanel->ResumeLayout(false);
			this->SheildPanel->PerformLayout();
			this->DroidPanel->ResumeLayout(false);
			this->DroidPanel->PerformLayout();
			this->CapacitorPanel->ResumeLayout(false);
			this->CapacitorPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		///
		/// Functions
		///

		/// Reactor Functions
private: System::Void UpdateReactorGUI(){
			 if (ReactorFormArmorTextBox->Text != "" && ReactorFormMassTextBox->Text != "" && 
				 ReactorFormGenerationTextBox->Text != "")
			 {
				 CalcReactorButton->Enabled = true;
			 }
			 else
			 {
				 CalcReactorButton->Enabled = false;
			 }
		 }
private: System::Void ResetReactorRE(){
			 ReactorFormArmorTextBox->Clear();
			 ReactorFormMassTextBox->Clear();
			 ReactorFormGenerationTextBox->Clear();

			 R_ArmorOutputValueLabel->Text = "No Input";
			 R_MassOutputValueLabel->Text = "No Input";
			 R_GenerationOutputValueLabel->Text = "No Input";
		 }
private: System::Void CalculateReactorRE(){
			 switch (CompLevelComboBox->SelectedIndex)
			 {
			 case 0: R_ArmorOutputValueLabel->Text = (Convert::ToDouble(ReactorFormArmorTextBox->Text->ToString()) * 1.02).ToString(".##");
					 R_MassOutputValueLabel->Text = (Convert::ToDouble(ReactorFormMassTextBox->Text->ToString()) * 0.98).ToString(".##");
					 R_GenerationOutputValueLabel->Text = (Convert::ToDouble(ReactorFormGenerationTextBox->Text->ToString()) * 1.02).ToString(".##");
				 break;
			 case 1: R_ArmorOutputValueLabel->Text = (Convert::ToDouble(ReactorFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 R_MassOutputValueLabel->Text = (Convert::ToDouble(ReactorFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 R_GenerationOutputValueLabel->Text = (Convert::ToDouble(ReactorFormGenerationTextBox->Text->ToString()) * 1.03).ToString(".##");
				 break;
			 case 2: R_ArmorOutputValueLabel->Text = (Convert::ToDouble(ReactorFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 R_MassOutputValueLabel->Text = (Convert::ToDouble(ReactorFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 R_GenerationOutputValueLabel->Text = (Convert::ToDouble(ReactorFormGenerationTextBox->Text->ToString()) * 1.03).ToString(".##");
				 break;
			 case 3: R_ArmorOutputValueLabel->Text = (Convert::ToDouble(ReactorFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 R_MassOutputValueLabel->Text = (Convert::ToDouble(ReactorFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 R_GenerationOutputValueLabel->Text = (Convert::ToDouble(ReactorFormGenerationTextBox->Text->ToString()) * 1.04).ToString(".##");
				 break;
			 case 4: R_ArmorOutputValueLabel->Text = (Convert::ToDouble(ReactorFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 R_MassOutputValueLabel->Text = (Convert::ToDouble(ReactorFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 R_GenerationOutputValueLabel->Text = (Convert::ToDouble(ReactorFormGenerationTextBox->Text->ToString()) * 1.04).ToString(".##");
				 break;
			 case 5: R_ArmorOutputValueLabel->Text = (Convert::ToDouble(ReactorFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 R_MassOutputValueLabel->Text = (Convert::ToDouble(ReactorFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 R_GenerationOutputValueLabel->Text = (Convert::ToDouble(ReactorFormGenerationTextBox->Text->ToString()) * 1.05).ToString(".##");
				 break;
			 case 6: R_ArmorOutputValueLabel->Text = (Convert::ToDouble(ReactorFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 R_MassOutputValueLabel->Text = (Convert::ToDouble(ReactorFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 R_GenerationOutputValueLabel->Text = (Convert::ToDouble(ReactorFormGenerationTextBox->Text->ToString()) * 1.05).ToString(".##");
				 break;
			 case 7: R_ArmorOutputValueLabel->Text = (Convert::ToDouble(ReactorFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 R_MassOutputValueLabel->Text = (Convert::ToDouble(ReactorFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 R_GenerationOutputValueLabel->Text = (Convert::ToDouble(ReactorFormGenerationTextBox->Text->ToString()) * 1.06).ToString(".##");
				 break;
			 case 8: R_ArmorOutputValueLabel->Text = (Convert::ToDouble(ReactorFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 R_MassOutputValueLabel->Text = (Convert::ToDouble(ReactorFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 R_GenerationOutputValueLabel->Text = (Convert::ToDouble(ReactorFormGenerationTextBox->Text->ToString()) * 1.06).ToString(".##");
				 break;
			 case 9: R_ArmorOutputValueLabel->Text = (Convert::ToDouble(ReactorFormArmorTextBox->Text->ToString()) * 1.07).ToString(".##");
					 R_MassOutputValueLabel->Text = (Convert::ToDouble(ReactorFormMassTextBox->Text->ToString()) * 0.93).ToString(".##");
					 R_GenerationOutputValueLabel->Text = (Convert::ToDouble(ReactorFormGenerationTextBox->Text->ToString()) * 1.07).ToString(".##");
				 break;
			 }
		 }
		/// Reactor Event Handlers
private: System::Void CalcReactorButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 CalculateReactorRE();
		 }
private: System::Void ClearReactorButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ResetReactorRE();
		 }
private: System::Void ReactorFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateReactorGUI();
		 }
private: System::Void ReactorFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateReactorGUI();
		 }
private: System::Void ReactorFormGenerationTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateReactorGUI();
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
		
		 
		/// Engine Functions
private: System::Void UpdateEngineGUI(){
			 if (EngineFormArmorTextBox->Text != "" && EngineFormMassTextBox->Text != "" && 
				 EngineFormDrainTextBox->Text != "" && EngineFormPitchTextBox->Text != "" &&
				 EngineFormYawTextBox->Text != "" && EngineFormRollTextBox->Text != "" &&
				 EngineFormSpeedTextBox->Text != "")
			 {
				 CalcEngineButton->Enabled = true;
			 }
			 else
			 {
				 CalcEngineButton->Enabled = false;
			 }
		 }
private: System::Void ResetEngineRE(){
			 EngineFormArmorTextBox->Clear();
			 EngineFormDrainTextBox->Clear();
			 EngineFormMassTextBox->Clear();
			 EngineFormPitchTextBox->Clear();
			 EngineFormYawTextBox->Clear();
			 EngineFormRollTextBox->Clear();
			 EngineFormSpeedTextBox->Clear();

			 E_ArmorOutputValueLabel->Text = "No Input";
			 E_DrainOutputValueLabel->Text = "No Input";
			 E_MassOutputValueLabel->Text = "No Input";
			 E_PitchOutputValueLabel->Text = "No Input";
			 E_YawOutputValueLabel->Text = "No Input";
			 E_RollOutputValueLabel->Text = "No Input";
			 E_SpeedOutputValueLabel->Text = "No Input";
		 }
private: System::Void CalculateEngineRE(){
			 switch (CompLevelComboBox->SelectedIndex)
			 {
			 case 0: E_ArmorOutputValueLabel->Text = (Convert::ToDouble(EngineFormArmorTextBox->Text->ToString()) * 1.02).ToString(".##");
					 E_DrainOutputValueLabel->Text = (Convert::ToDouble(EngineFormDrainTextBox->Text->ToString()) * 0.98).ToString(".##");
					 E_MassOutputValueLabel->Text = (Convert::ToDouble(EngineFormMassTextBox->Text->ToString()) * 0.98).ToString(".##");
					 E_PitchOutputValueLabel->Text = (Convert::ToDouble(EngineFormPitchTextBox->Text->ToString()) * 1.02).ToString(".##");
					 E_YawOutputValueLabel->Text = (Convert::ToDouble(EngineFormYawTextBox->Text->ToString()) * 1.02).ToString(".##");
					 E_RollOutputValueLabel->Text = (Convert::ToDouble(EngineFormRollTextBox->Text->ToString()) * 1.02).ToString(".##");
					 E_SpeedOutputValueLabel->Text = (Convert::ToDouble(EngineFormSpeedTextBox->Text->ToString()) * 1.02).ToString(".##");
				 break;
			 case 1: E_ArmorOutputValueLabel->Text = (Convert::ToDouble(EngineFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 E_DrainOutputValueLabel->Text = (Convert::ToDouble(EngineFormDrainTextBox->Text->ToString()) * 0.97).ToString(".##");
					 E_MassOutputValueLabel->Text = (Convert::ToDouble(EngineFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 E_PitchOutputValueLabel->Text = (Convert::ToDouble(EngineFormPitchTextBox->Text->ToString()) * 1.03).ToString(".##");
					 E_YawOutputValueLabel->Text = (Convert::ToDouble(EngineFormYawTextBox->Text->ToString()) * 1.03).ToString(".##");
					 E_RollOutputValueLabel->Text = (Convert::ToDouble(EngineFormRollTextBox->Text->ToString()) * 1.03).ToString(".##");
					 E_SpeedOutputValueLabel->Text = (Convert::ToDouble(EngineFormSpeedTextBox->Text->ToString()) * 1.02).ToString(".##");
				 break;
			 case 2: E_ArmorOutputValueLabel->Text = (Convert::ToDouble(EngineFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 E_DrainOutputValueLabel->Text = (Convert::ToDouble(EngineFormDrainTextBox->Text->ToString()) * 0.97).ToString(".##");
					 E_MassOutputValueLabel->Text = (Convert::ToDouble(EngineFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 E_PitchOutputValueLabel->Text = (Convert::ToDouble(EngineFormPitchTextBox->Text->ToString()) * 1.03).ToString(".##");
					 E_YawOutputValueLabel->Text = (Convert::ToDouble(EngineFormYawTextBox->Text->ToString()) * 1.03).ToString(".##");
					 E_RollOutputValueLabel->Text = (Convert::ToDouble(EngineFormRollTextBox->Text->ToString()) * 1.03).ToString(".##");
					 E_SpeedOutputValueLabel->Text = (Convert::ToDouble(EngineFormSpeedTextBox->Text->ToString()) * 1.03).ToString(".##");
				 break;
			 case 3: E_ArmorOutputValueLabel->Text = (Convert::ToDouble(EngineFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 E_DrainOutputValueLabel->Text = (Convert::ToDouble(EngineFormDrainTextBox->Text->ToString()) * 0.96).ToString(".##");
					 E_MassOutputValueLabel->Text = (Convert::ToDouble(EngineFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 E_PitchOutputValueLabel->Text = (Convert::ToDouble(EngineFormPitchTextBox->Text->ToString()) * 1.04).ToString(".##");
					 E_YawOutputValueLabel->Text = (Convert::ToDouble(EngineFormYawTextBox->Text->ToString()) * 1.04).ToString(".##");
					 E_RollOutputValueLabel->Text = (Convert::ToDouble(EngineFormRollTextBox->Text->ToString()) * 1.04).ToString(".##");
					 E_SpeedOutputValueLabel->Text = (Convert::ToDouble(EngineFormSpeedTextBox->Text->ToString()) * 1.04).ToString(".##");
				 break;
			 case 4: E_ArmorOutputValueLabel->Text = (Convert::ToDouble(EngineFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 E_DrainOutputValueLabel->Text = (Convert::ToDouble(EngineFormDrainTextBox->Text->ToString()) * 0.96).ToString(".##");
					 E_MassOutputValueLabel->Text = (Convert::ToDouble(EngineFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 E_PitchOutputValueLabel->Text = (Convert::ToDouble(EngineFormPitchTextBox->Text->ToString()) * 1.04).ToString(".##");
					 E_YawOutputValueLabel->Text = (Convert::ToDouble(EngineFormYawTextBox->Text->ToString()) * 1.04).ToString(".##");
					 E_RollOutputValueLabel->Text = (Convert::ToDouble(EngineFormRollTextBox->Text->ToString()) * 1.04).ToString(".##");
					 E_SpeedOutputValueLabel->Text = (Convert::ToDouble(EngineFormSpeedTextBox->Text->ToString()) * 1.04).ToString(".##");
				 break;
			 case 5: E_ArmorOutputValueLabel->Text = (Convert::ToDouble(EngineFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 E_DrainOutputValueLabel->Text = (Convert::ToDouble(EngineFormDrainTextBox->Text->ToString()) * 0.95).ToString(".##");
					 E_MassOutputValueLabel->Text = (Convert::ToDouble(EngineFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 E_PitchOutputValueLabel->Text = (Convert::ToDouble(EngineFormPitchTextBox->Text->ToString()) * 1.05).ToString(".##");
					 E_YawOutputValueLabel->Text = (Convert::ToDouble(EngineFormYawTextBox->Text->ToString()) * 1.05).ToString(".##");
					 E_RollOutputValueLabel->Text = (Convert::ToDouble(EngineFormRollTextBox->Text->ToString()) * 1.05).ToString(".##");
					 E_SpeedOutputValueLabel->Text = (Convert::ToDouble(EngineFormSpeedTextBox->Text->ToString()) * 1.05).ToString(".##");
				 break;
			 case 6: E_ArmorOutputValueLabel->Text = (Convert::ToDouble(EngineFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 E_DrainOutputValueLabel->Text = (Convert::ToDouble(EngineFormDrainTextBox->Text->ToString()) * 0.95).ToString(".##");
					 E_MassOutputValueLabel->Text = (Convert::ToDouble(EngineFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 E_PitchOutputValueLabel->Text = (Convert::ToDouble(EngineFormPitchTextBox->Text->ToString()) * 1.05).ToString(".##");
					 E_YawOutputValueLabel->Text = (Convert::ToDouble(EngineFormYawTextBox->Text->ToString()) * 1.05).ToString(".##");
					 E_RollOutputValueLabel->Text = (Convert::ToDouble(EngineFormRollTextBox->Text->ToString()) * 1.05).ToString(".##");
					 E_SpeedOutputValueLabel->Text = (Convert::ToDouble(EngineFormSpeedTextBox->Text->ToString()) * 1.05).ToString(".##");
				 break;
			 case 7: E_ArmorOutputValueLabel->Text = (Convert::ToDouble(EngineFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 E_DrainOutputValueLabel->Text = (Convert::ToDouble(EngineFormDrainTextBox->Text->ToString()) * 0.94).ToString(".##");
					 E_MassOutputValueLabel->Text = (Convert::ToDouble(EngineFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 E_PitchOutputValueLabel->Text = (Convert::ToDouble(EngineFormPitchTextBox->Text->ToString()) * 1.06).ToString(".##");
					 E_YawOutputValueLabel->Text = (Convert::ToDouble(EngineFormYawTextBox->Text->ToString()) * 1.06).ToString(".##");
					 E_RollOutputValueLabel->Text = (Convert::ToDouble(EngineFormRollTextBox->Text->ToString()) * 1.06).ToString(".##");
					 E_SpeedOutputValueLabel->Text = (Convert::ToDouble(EngineFormSpeedTextBox->Text->ToString()) * 1.06).ToString(".##");
				 break;
			 case 8: E_ArmorOutputValueLabel->Text = (Convert::ToDouble(EngineFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 E_DrainOutputValueLabel->Text = (Convert::ToDouble(EngineFormDrainTextBox->Text->ToString()) * 0.94).ToString(".##");
					 E_MassOutputValueLabel->Text = (Convert::ToDouble(EngineFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 E_PitchOutputValueLabel->Text = (Convert::ToDouble(EngineFormPitchTextBox->Text->ToString()) * 1.06).ToString(".##");
					 E_YawOutputValueLabel->Text = (Convert::ToDouble(EngineFormYawTextBox->Text->ToString()) * 1.06).ToString(".##");
					 E_RollOutputValueLabel->Text = (Convert::ToDouble(EngineFormRollTextBox->Text->ToString()) * 1.06).ToString(".##");
					 E_SpeedOutputValueLabel->Text = (Convert::ToDouble(EngineFormSpeedTextBox->Text->ToString()) * 1.06).ToString(".##");
				 break;
			 case 9: E_ArmorOutputValueLabel->Text = (Convert::ToDouble(EngineFormArmorTextBox->Text->ToString()) * 1.07).ToString(".##");
					 E_DrainOutputValueLabel->Text = (Convert::ToDouble(EngineFormDrainTextBox->Text->ToString()) * 0.93).ToString(".##");
					 E_MassOutputValueLabel->Text = (Convert::ToDouble(EngineFormMassTextBox->Text->ToString()) * 0.93).ToString(".##");
					 E_PitchOutputValueLabel->Text = (Convert::ToDouble(EngineFormPitchTextBox->Text->ToString()) * 1.07).ToString(".##");
					 E_YawOutputValueLabel->Text = (Convert::ToDouble(EngineFormYawTextBox->Text->ToString()) * 1.07).ToString(".##");
					 E_RollOutputValueLabel->Text = (Convert::ToDouble(EngineFormRollTextBox->Text->ToString()) * 1.07).ToString(".##");
					 E_SpeedOutputValueLabel->Text = (Convert::ToDouble(EngineFormSpeedTextBox->Text->ToString()) * 1.07).ToString(".##");
				 break;
			 }
		 }

		/// Engine Event Handlers
private: System::Void CalcEngineButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 CalculateEngineRE();
		 }
private: System::Void ClearEngineButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ResetEngineRE();
		 }
private: System::Void EngineFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateEngineGUI();
		 }
private: System::Void EngineFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateEngineGUI();
		 }
private: System::Void EngineFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateEngineGUI();
		 }
private: System::Void EngineFormPitchTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateEngineGUI();
		 }
private: System::Void EngineFormYawTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateEngineGUI();
		 }
private: System::Void EngineFormRollTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateEngineGUI();
		 }
private: System::Void EngineFormSpeedTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateEngineGUI();
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
		
		 
		/// Booster Functions
private: System::Void UpdateBoosterGUI(){
			 if (BoosterFormArmorTextBox->Text != "" && BoosterFormMassTextBox->Text != "" && 
				 BoosterFormDrainTextBox->Text != "" && BoosterFormEnergyTextBox->Text != "" &&
				 BoosterFormRechargeTextBox->Text != "" && BoosterFormConsumptionTextBox->Text != "" &&
				 BoosterFormAccelerationTextBox->Text != "" && BoosterFormSpeedTextBox->Text != "")
			 {
				 CalcBoosterButton->Enabled = true;
			 }
			 else
			 {
				 CalcBoosterButton->Enabled = false;
			 }
		 }
private: System::Void ResetBoosterRE(){
			 BoosterFormArmorTextBox->Clear();
			 BoosterFormDrainTextBox->Clear();
			 BoosterFormMassTextBox->Clear();
			 BoosterFormEnergyTextBox->Clear();
			 BoosterFormRechargeTextBox->Clear();
			 BoosterFormConsumptionTextBox->Clear();
			 BoosterFormAccelerationTextBox->Clear();
			 BoosterFormSpeedTextBox->Clear();

			 B_ArmorOutputValueLabel->Text = "No Input";
			 B_DrainOutputValueLabel->Text = "No Input";
			 B_MassOutputValueLabel->Text = "No Input";
			 B_EnergyOutputValueLabel->Text = "No Input";
			 B_RechargeOutputValueLabel->Text = "No Input";
			 B_ConsumptionOutputValueLabel->Text = "No Input";
			 B_AccelerationOutputValueLabel->Text = "No Input";
			 B_SpeedOutputValueLabel->Text = "No Input";
		 }
private: System::Void CalculateBoosterRE(){
			 switch (CompLevelComboBox->SelectedIndex)
			 {
			 case 0: B_ArmorOutputValueLabel->Text = (Convert::ToDouble(BoosterFormArmorTextBox->Text->ToString()) * 1.02).ToString(".##");
					 B_DrainOutputValueLabel->Text = (Convert::ToDouble(BoosterFormDrainTextBox->Text->ToString()) * 0.98).ToString(".##");
					 B_MassOutputValueLabel->Text = (Convert::ToDouble(BoosterFormMassTextBox->Text->ToString()) * 0.98).ToString(".##");
					 B_EnergyOutputValueLabel->Text = (Convert::ToDouble(BoosterFormEnergyTextBox->Text->ToString()) * 1.02).ToString(".##");
					 B_RechargeOutputValueLabel->Text = (Convert::ToDouble(BoosterFormRechargeTextBox->Text->ToString()) * 1.02).ToString(".##");
					 B_ConsumptionOutputValueLabel->Text = (Convert::ToDouble(BoosterFormConsumptionTextBox->Text->ToString()) * 0.98).ToString(".##");
					 B_AccelerationOutputValueLabel->Text = (Convert::ToDouble(BoosterFormAccelerationTextBox->Text->ToString()) * 1.02).ToString(".##");
					 B_SpeedOutputValueLabel->Text = (Convert::ToDouble(BoosterFormSpeedTextBox->Text->ToString()) * 1.02).ToString(".##");
				 break;
			 case 1: B_ArmorOutputValueLabel->Text = (Convert::ToDouble(BoosterFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 B_DrainOutputValueLabel->Text = (Convert::ToDouble(BoosterFormDrainTextBox->Text->ToString()) * 0.97).ToString(".##");
					 B_MassOutputValueLabel->Text = (Convert::ToDouble(BoosterFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 B_EnergyOutputValueLabel->Text = (Convert::ToDouble(BoosterFormEnergyTextBox->Text->ToString()) * 1.03).ToString(".##");
					 B_RechargeOutputValueLabel->Text = (Convert::ToDouble(BoosterFormRechargeTextBox->Text->ToString()) * 1.03).ToString(".##");
					 B_ConsumptionOutputValueLabel->Text = (Convert::ToDouble(BoosterFormConsumptionTextBox->Text->ToString()) * 0.97).ToString(".##");
					 B_AccelerationOutputValueLabel->Text = (Convert::ToDouble(BoosterFormAccelerationTextBox->Text->ToString()) * 1.03).ToString(".##");
					 B_SpeedOutputValueLabel->Text = (Convert::ToDouble(BoosterFormSpeedTextBox->Text->ToString()) * 1.03).ToString(".##");
				 break;
			 case 2: B_ArmorOutputValueLabel->Text = (Convert::ToDouble(BoosterFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 B_DrainOutputValueLabel->Text = (Convert::ToDouble(BoosterFormDrainTextBox->Text->ToString()) * 0.97).ToString(".##");
					 B_MassOutputValueLabel->Text = (Convert::ToDouble(BoosterFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 B_EnergyOutputValueLabel->Text = (Convert::ToDouble(BoosterFormEnergyTextBox->Text->ToString()) * 1.03).ToString(".##");
					 B_RechargeOutputValueLabel->Text = (Convert::ToDouble(BoosterFormRechargeTextBox->Text->ToString()) * 1.03).ToString(".##");
					 B_ConsumptionOutputValueLabel->Text = (Convert::ToDouble(BoosterFormConsumptionTextBox->Text->ToString()) * 0.97).ToString(".##");
					 B_AccelerationOutputValueLabel->Text = (Convert::ToDouble(BoosterFormAccelerationTextBox->Text->ToString()) * 1.03).ToString(".##");
					 B_SpeedOutputValueLabel->Text = (Convert::ToDouble(BoosterFormSpeedTextBox->Text->ToString()) * 1.03).ToString(".##");
				 break;
			 case 3: B_ArmorOutputValueLabel->Text = (Convert::ToDouble(BoosterFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 B_DrainOutputValueLabel->Text = (Convert::ToDouble(BoosterFormDrainTextBox->Text->ToString()) * 0.96).ToString(".##");
					 B_MassOutputValueLabel->Text = (Convert::ToDouble(BoosterFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 B_EnergyOutputValueLabel->Text = (Convert::ToDouble(BoosterFormEnergyTextBox->Text->ToString()) * 1.04).ToString(".##");
					 B_RechargeOutputValueLabel->Text = (Convert::ToDouble(BoosterFormRechargeTextBox->Text->ToString()) * 1.04).ToString(".##");
					 B_ConsumptionOutputValueLabel->Text = (Convert::ToDouble(BoosterFormConsumptionTextBox->Text->ToString()) * 0.96).ToString(".##");
					 B_AccelerationOutputValueLabel->Text = (Convert::ToDouble(BoosterFormAccelerationTextBox->Text->ToString()) * 1.04).ToString(".##");
					 B_SpeedOutputValueLabel->Text = (Convert::ToDouble(BoosterFormSpeedTextBox->Text->ToString()) * 1.04).ToString(".##");
				 break;
			 case 4: B_ArmorOutputValueLabel->Text = (Convert::ToDouble(BoosterFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 B_DrainOutputValueLabel->Text = (Convert::ToDouble(BoosterFormDrainTextBox->Text->ToString()) * 0.96).ToString(".##");
					 B_MassOutputValueLabel->Text = (Convert::ToDouble(BoosterFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 B_EnergyOutputValueLabel->Text = (Convert::ToDouble(BoosterFormEnergyTextBox->Text->ToString()) * 1.04).ToString(".##");
					 B_RechargeOutputValueLabel->Text = (Convert::ToDouble(BoosterFormRechargeTextBox->Text->ToString()) * 1.04).ToString(".##");
					 B_ConsumptionOutputValueLabel->Text = (Convert::ToDouble(BoosterFormConsumptionTextBox->Text->ToString()) * 0.96).ToString(".##");
					 B_AccelerationOutputValueLabel->Text = (Convert::ToDouble(BoosterFormAccelerationTextBox->Text->ToString()) * 1.04).ToString(".##");
					 B_SpeedOutputValueLabel->Text = (Convert::ToDouble(BoosterFormSpeedTextBox->Text->ToString()) * 1.04).ToString(".##");
				 break;
			 case 5: B_ArmorOutputValueLabel->Text = (Convert::ToDouble(BoosterFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 B_DrainOutputValueLabel->Text = (Convert::ToDouble(BoosterFormDrainTextBox->Text->ToString()) * 0.95).ToString(".##");
					 B_MassOutputValueLabel->Text = (Convert::ToDouble(BoosterFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 B_EnergyOutputValueLabel->Text = (Convert::ToDouble(BoosterFormEnergyTextBox->Text->ToString()) * 1.05).ToString(".##");
					 B_RechargeOutputValueLabel->Text = (Convert::ToDouble(BoosterFormRechargeTextBox->Text->ToString()) * 1.05).ToString(".##");
					 B_ConsumptionOutputValueLabel->Text = (Convert::ToDouble(BoosterFormConsumptionTextBox->Text->ToString()) * 0.95).ToString(".##");
					 B_AccelerationOutputValueLabel->Text = (Convert::ToDouble(BoosterFormAccelerationTextBox->Text->ToString()) * 1.05).ToString(".##");
					 B_SpeedOutputValueLabel->Text = (Convert::ToDouble(BoosterFormSpeedTextBox->Text->ToString()) * 1.05).ToString(".##");
				 break;
			 case 6: B_ArmorOutputValueLabel->Text = (Convert::ToDouble(BoosterFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 B_DrainOutputValueLabel->Text = (Convert::ToDouble(BoosterFormDrainTextBox->Text->ToString()) * 0.95).ToString(".##");
					 B_MassOutputValueLabel->Text = (Convert::ToDouble(BoosterFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 B_EnergyOutputValueLabel->Text = (Convert::ToDouble(BoosterFormEnergyTextBox->Text->ToString()) * 1.05).ToString(".##");
					 B_RechargeOutputValueLabel->Text = (Convert::ToDouble(BoosterFormRechargeTextBox->Text->ToString()) * 1.05).ToString(".##");
					 B_ConsumptionOutputValueLabel->Text = (Convert::ToDouble(BoosterFormConsumptionTextBox->Text->ToString()) * 0.95).ToString(".##");
					 B_AccelerationOutputValueLabel->Text = (Convert::ToDouble(BoosterFormAccelerationTextBox->Text->ToString()) * 1.05).ToString(".##");
					 B_SpeedOutputValueLabel->Text = (Convert::ToDouble(BoosterFormSpeedTextBox->Text->ToString()) * 1.05).ToString(".##");
				 break;
			 case 7: B_ArmorOutputValueLabel->Text = (Convert::ToDouble(BoosterFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 B_DrainOutputValueLabel->Text = (Convert::ToDouble(BoosterFormDrainTextBox->Text->ToString()) * 0.94).ToString(".##");
					 B_MassOutputValueLabel->Text = (Convert::ToDouble(BoosterFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 B_EnergyOutputValueLabel->Text = (Convert::ToDouble(BoosterFormEnergyTextBox->Text->ToString()) * 1.06).ToString(".##");
					 B_RechargeOutputValueLabel->Text = (Convert::ToDouble(BoosterFormRechargeTextBox->Text->ToString()) * 1.06).ToString(".##");
					 B_ConsumptionOutputValueLabel->Text = (Convert::ToDouble(BoosterFormConsumptionTextBox->Text->ToString()) * 0.94).ToString(".##");
					 B_AccelerationOutputValueLabel->Text = (Convert::ToDouble(BoosterFormAccelerationTextBox->Text->ToString()) * 1.06).ToString(".##");
					 B_SpeedOutputValueLabel->Text = (Convert::ToDouble(BoosterFormSpeedTextBox->Text->ToString()) * 1.06).ToString(".##");
				 break;
			 case 8: B_ArmorOutputValueLabel->Text = (Convert::ToDouble(BoosterFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 B_DrainOutputValueLabel->Text = (Convert::ToDouble(BoosterFormDrainTextBox->Text->ToString()) * 0.94).ToString(".##");
					 B_MassOutputValueLabel->Text = (Convert::ToDouble(BoosterFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 B_EnergyOutputValueLabel->Text = (Convert::ToDouble(BoosterFormEnergyTextBox->Text->ToString()) * 1.06).ToString(".##");
					 B_RechargeOutputValueLabel->Text = (Convert::ToDouble(BoosterFormRechargeTextBox->Text->ToString()) * 1.06).ToString(".##");
					 B_ConsumptionOutputValueLabel->Text = (Convert::ToDouble(BoosterFormConsumptionTextBox->Text->ToString()) * 0.94).ToString(".##");
					 B_AccelerationOutputValueLabel->Text = (Convert::ToDouble(BoosterFormAccelerationTextBox->Text->ToString()) * 1.06).ToString(".##");
					 B_SpeedOutputValueLabel->Text = (Convert::ToDouble(BoosterFormSpeedTextBox->Text->ToString()) * 1.06).ToString(".##");
				 break;
			 case 9: B_ArmorOutputValueLabel->Text = (Convert::ToDouble(BoosterFormArmorTextBox->Text->ToString()) * 1.07).ToString(".##");
					 B_DrainOutputValueLabel->Text = (Convert::ToDouble(BoosterFormDrainTextBox->Text->ToString()) * 0.93).ToString(".##");
					 B_MassOutputValueLabel->Text = (Convert::ToDouble(BoosterFormMassTextBox->Text->ToString()) * 0.93).ToString(".##");
					 B_EnergyOutputValueLabel->Text = (Convert::ToDouble(BoosterFormEnergyTextBox->Text->ToString()) * 1.07).ToString(".##");
					 B_RechargeOutputValueLabel->Text = (Convert::ToDouble(BoosterFormRechargeTextBox->Text->ToString()) * 1.07).ToString(".##");
					 B_ConsumptionOutputValueLabel->Text = (Convert::ToDouble(BoosterFormConsumptionTextBox->Text->ToString()) * 0.93).ToString(".##");
					 B_AccelerationOutputValueLabel->Text = (Convert::ToDouble(BoosterFormAccelerationTextBox->Text->ToString()) * 1.07).ToString(".##");
					 B_SpeedOutputValueLabel->Text = (Convert::ToDouble(BoosterFormSpeedTextBox->Text->ToString()) * 1.07).ToString(".##");
				 break;
			 }
		 }
		/// Booster Event Handlers
private: System::Void CalcBoosterButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 CalculateBoosterRE();
		 }
private: System::Void ClearBoosterButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ResetBoosterRE();
		 }		

private: System::Void BoosterFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateBoosterGUI();
		 }
private: System::Void BoosterFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateBoosterGUI();
		 }
private: System::Void BoosterFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateBoosterGUI();
		 }
private: System::Void BoosterFormEnergyTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateBoosterGUI();
		 }
private: System::Void BoosterFormRechargeTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateBoosterGUI();
		 }
private: System::Void BoosterFormConsumptionTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateBoosterGUI();
		 }
private: System::Void BoosterFormAccelerationTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateBoosterGUI();
		 }
private: System::Void BoosterFormSpeedTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateBoosterGUI();
		 }
private: System::Void BoosterFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormEnergyTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormRechargeTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormConsumptionTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormAccelerationTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void BoosterFormSpeedTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
		
		 
		 /// Sheild Functions
private: System::Void UpdateSheildGUI(){
			 if (SheildFormArmorTextBox->Text != "" && SheildFormMassTextBox->Text != "" && 
				 SheildFormDrainTextBox->Text != "" && SheildFormFrontHPTextBox->Text != "" &&
				 SheildFormBackHPTextBox->Text != "" && SheildFormRechargeTextBox->Text != "")
			 {
				 CalcSheildButton->Enabled = true;
			 }
			 else
			 {
				 CalcSheildButton->Enabled = false;
			 }
		 }
private: System::Void ResetSheildRE(){
			 SheildFormArmorTextBox->Clear();
			 SheildFormDrainTextBox->Clear();
			 SheildFormMassTextBox->Clear();
			 SheildFormFrontHPTextBox->Clear();
			 SheildFormBackHPTextBox->Clear();
			 SheildFormRechargeTextBox->Clear();

			 S_ArmorOutputValueLabel->Text = "No Input";
			 S_DrainOutputValueLabel->Text = "No Input";
			 S_MassOutputValueLabel->Text = "No Input";
			 S_FrontHPOutputValueLabel->Text = "No Input";
			 S_RearHPOutputValueLabel->Text = "No Input";
			 S_RechargeOutputValueLabel->Text = "No Input";
		 }
private: System::Void CalculateSheildRE(){
			 switch (CompLevelComboBox->SelectedIndex)
			 {
			 case 0: S_ArmorOutputValueLabel->Text = (Convert::ToDouble(SheildFormArmorTextBox->Text->ToString()) * 1.02).ToString(".##");
					 S_DrainOutputValueLabel->Text = (Convert::ToDouble(SheildFormDrainTextBox->Text->ToString()) * 0.98).ToString(".##");
					 S_MassOutputValueLabel->Text = (Convert::ToDouble(SheildFormMassTextBox->Text->ToString()) * 0.98).ToString(".##");
					 S_FrontHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormFrontHPTextBox->Text->ToString()) * 1.02).ToString(".##");
					 S_RearHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormBackHPTextBox->Text->ToString()) * 1.02).ToString(".##");
					 S_RechargeOutputValueLabel->Text = (Convert::ToDouble(SheildFormRechargeTextBox->Text->ToString()) * 1.02).ToString(".##");
				 break;
			 case 1: S_ArmorOutputValueLabel->Text = (Convert::ToDouble(SheildFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 S_DrainOutputValueLabel->Text = (Convert::ToDouble(SheildFormDrainTextBox->Text->ToString()) * 0.97).ToString(".##");
					 S_MassOutputValueLabel->Text = (Convert::ToDouble(SheildFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 S_FrontHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormFrontHPTextBox->Text->ToString()) * 1.03).ToString(".##");
					 S_RearHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormBackHPTextBox->Text->ToString()) * 1.03).ToString(".##");
					 S_RechargeOutputValueLabel->Text = (Convert::ToDouble(SheildFormRechargeTextBox->Text->ToString()) * 1.03).ToString(".##");
				 break;
			 case 2: S_ArmorOutputValueLabel->Text = (Convert::ToDouble(SheildFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 S_DrainOutputValueLabel->Text = (Convert::ToDouble(SheildFormDrainTextBox->Text->ToString()) * 0.97).ToString(".##");
					 S_MassOutputValueLabel->Text = (Convert::ToDouble(SheildFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 S_FrontHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormFrontHPTextBox->Text->ToString()) * 1.03).ToString(".##");
					 S_RearHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormBackHPTextBox->Text->ToString()) * 1.03).ToString(".##");
					 S_RechargeOutputValueLabel->Text = (Convert::ToDouble(SheildFormRechargeTextBox->Text->ToString()) * 1.03).ToString(".##");
				 break;
			 case 3: S_ArmorOutputValueLabel->Text = (Convert::ToDouble(SheildFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 S_DrainOutputValueLabel->Text = (Convert::ToDouble(SheildFormDrainTextBox->Text->ToString()) * 0.96).ToString(".##");
					 S_MassOutputValueLabel->Text = (Convert::ToDouble(SheildFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 S_FrontHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormFrontHPTextBox->Text->ToString()) * 1.04).ToString(".##");
					 S_RearHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormBackHPTextBox->Text->ToString()) * 1.04).ToString(".##");
					 S_RechargeOutputValueLabel->Text = (Convert::ToDouble(SheildFormRechargeTextBox->Text->ToString()) * 1.04).ToString(".##");
				 break;
			 case 4: S_ArmorOutputValueLabel->Text = (Convert::ToDouble(SheildFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 S_DrainOutputValueLabel->Text = (Convert::ToDouble(SheildFormDrainTextBox->Text->ToString()) * 0.96).ToString(".##");
					 S_MassOutputValueLabel->Text = (Convert::ToDouble(SheildFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 S_FrontHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormFrontHPTextBox->Text->ToString()) * 1.04).ToString(".##");
					 S_RearHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormBackHPTextBox->Text->ToString()) * 1.04).ToString(".##");
					 S_RechargeOutputValueLabel->Text = (Convert::ToDouble(SheildFormRechargeTextBox->Text->ToString()) * 1.04).ToString(".##");
				 break;
			 case 5: S_ArmorOutputValueLabel->Text = (Convert::ToDouble(SheildFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 S_DrainOutputValueLabel->Text = (Convert::ToDouble(SheildFormDrainTextBox->Text->ToString()) * 0.95).ToString(".##");
					 S_MassOutputValueLabel->Text = (Convert::ToDouble(SheildFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 S_FrontHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormFrontHPTextBox->Text->ToString()) * 1.05).ToString(".##");
					 S_RearHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormBackHPTextBox->Text->ToString()) * 1.05).ToString(".##");
					 S_RechargeOutputValueLabel->Text = (Convert::ToDouble(SheildFormRechargeTextBox->Text->ToString()) * 1.05).ToString(".##");
				 break;
			 case 6: S_ArmorOutputValueLabel->Text = (Convert::ToDouble(SheildFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 S_DrainOutputValueLabel->Text = (Convert::ToDouble(SheildFormDrainTextBox->Text->ToString()) * 0.95).ToString(".##");
					 S_MassOutputValueLabel->Text = (Convert::ToDouble(SheildFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 S_FrontHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormFrontHPTextBox->Text->ToString()) * 1.05).ToString(".##");
					 S_RearHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormBackHPTextBox->Text->ToString()) * 1.05).ToString(".##");
					 S_RechargeOutputValueLabel->Text = (Convert::ToDouble(SheildFormRechargeTextBox->Text->ToString()) * 1.05).ToString(".##");
				 break;
			 case 7: S_ArmorOutputValueLabel->Text = (Convert::ToDouble(SheildFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 S_DrainOutputValueLabel->Text = (Convert::ToDouble(SheildFormDrainTextBox->Text->ToString()) * 0.94).ToString(".##");
					 S_MassOutputValueLabel->Text = (Convert::ToDouble(SheildFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 S_FrontHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormFrontHPTextBox->Text->ToString()) * 1.06).ToString(".##");
					 S_RearHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormBackHPTextBox->Text->ToString()) * 1.06).ToString(".##");
					 S_RechargeOutputValueLabel->Text = (Convert::ToDouble(SheildFormRechargeTextBox->Text->ToString()) * 1.06).ToString(".##");
				 break;
			 case 8: S_ArmorOutputValueLabel->Text = (Convert::ToDouble(SheildFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 S_DrainOutputValueLabel->Text = (Convert::ToDouble(SheildFormDrainTextBox->Text->ToString()) * 0.94).ToString(".##");
					 S_MassOutputValueLabel->Text = (Convert::ToDouble(SheildFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 S_FrontHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormFrontHPTextBox->Text->ToString()) * 1.06).ToString(".##");
					 S_RearHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormBackHPTextBox->Text->ToString()) * 1.06).ToString(".##");
					 S_RechargeOutputValueLabel->Text = (Convert::ToDouble(SheildFormRechargeTextBox->Text->ToString()) * 1.06).ToString(".##");
				 break;
			 case 9: S_ArmorOutputValueLabel->Text = (Convert::ToDouble(SheildFormArmorTextBox->Text->ToString()) * 1.07).ToString(".##");
					 S_DrainOutputValueLabel->Text = (Convert::ToDouble(SheildFormDrainTextBox->Text->ToString()) * 0.93).ToString(".##");
					 S_MassOutputValueLabel->Text = (Convert::ToDouble(SheildFormMassTextBox->Text->ToString()) * 0.93).ToString(".##");
					 S_FrontHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormFrontHPTextBox->Text->ToString()) * 1.07).ToString(".##");
					 S_RearHPOutputValueLabel->Text = (Convert::ToDouble(SheildFormBackHPTextBox->Text->ToString()) * 1.07).ToString(".##");
					 S_RechargeOutputValueLabel->Text = (Convert::ToDouble(SheildFormRechargeTextBox->Text->ToString()) * 1.07).ToString(".##");
				 break;
			 }
		 }
		/// Sheild Event Handlers
private: System::Void CalcSheildButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 CalculateSheildRE();
		 }
private: System::Void ClearSheildButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ResetSheildRE();
		 }

private: System::Void SheildFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSheildGUI();
		 }
private: System::Void SheildFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSheildGUI();
		 }
private: System::Void SheildFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSheildGUI();
		 }
private: System::Void SheildFormFrontHPTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSheildGUI();
		 }
private: System::Void SheildFormBackHPTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSheildGUI();
		 }
private: System::Void SheildFormRechargeTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSheildGUI();
		 }
private: System::Void SheildFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void SheildFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void SheildFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void SheildFormFrontHPTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void SheildFormBackHPTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void SheildFormRechargeTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
		 

		/// Armor Functions
private: System::Void UpdateArmorGUI(){
			 if (ArmorFormArmorTextBox->Text != "" && ArmorFormMassTextBox->Text != "")
			 {
				 CalcArmorButton->Enabled = true;
			 }
			 else
			 {
				 CalcArmorButton->Enabled = false;
			 }
		 }
private: System::Void ResetArmorRE(){
			 ArmorFormArmorTextBox->Clear();
			 ArmorFormMassTextBox->Clear();

			 A_ArmorOutputValueLabel->Text = "No Input";
			 A_MassOutputValueLabel->Text = "No Input";
		 }
private: System::Void CalculateArmorRE(){
			 switch (CompLevelComboBox->SelectedIndex)
			 {
			 case 0: A_ArmorOutputValueLabel->Text = (Convert::ToDouble(ArmorFormArmorTextBox->Text->ToString()) * 1.02).ToString(".##");
					 A_MassOutputValueLabel->Text = (Convert::ToDouble(ArmorFormMassTextBox->Text->ToString()) * 0.98).ToString(".##");
				 break;
			 case 1: A_ArmorOutputValueLabel->Text = (Convert::ToDouble(ArmorFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 A_MassOutputValueLabel->Text = (Convert::ToDouble(ArmorFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
				 break;
			 case 2: A_ArmorOutputValueLabel->Text = (Convert::ToDouble(ArmorFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 A_MassOutputValueLabel->Text = (Convert::ToDouble(ArmorFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
				 break;
			 case 3: A_ArmorOutputValueLabel->Text = (Convert::ToDouble(ArmorFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 A_MassOutputValueLabel->Text = (Convert::ToDouble(ArmorFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
				 break;
			 case 4: A_ArmorOutputValueLabel->Text = (Convert::ToDouble(ArmorFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 A_MassOutputValueLabel->Text = (Convert::ToDouble(ArmorFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
				 break;
			 case 5: A_ArmorOutputValueLabel->Text = (Convert::ToDouble(ArmorFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 A_MassOutputValueLabel->Text = (Convert::ToDouble(ArmorFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
				 break;
			 case 6: A_ArmorOutputValueLabel->Text = (Convert::ToDouble(ArmorFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 A_MassOutputValueLabel->Text = (Convert::ToDouble(ArmorFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
				 break;
			 case 7: A_ArmorOutputValueLabel->Text = (Convert::ToDouble(ArmorFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 A_MassOutputValueLabel->Text = (Convert::ToDouble(ArmorFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
				 break;
			 case 8: A_ArmorOutputValueLabel->Text = (Convert::ToDouble(ArmorFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 A_MassOutputValueLabel->Text = (Convert::ToDouble(ArmorFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
				 break;
			 case 9: A_ArmorOutputValueLabel->Text = (Convert::ToDouble(ArmorFormArmorTextBox->Text->ToString()) * 1.07).ToString(".##");
					 A_MassOutputValueLabel->Text = (Convert::ToDouble(ArmorFormMassTextBox->Text->ToString()) * 0.93).ToString(".##");
				 break;
			 }
		 }
		/// Armor Event Handlers
private: System::Void CalcArmorButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 CalculateArmorRE();
		 }
private: System::Void ClearArmorButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ResetArmorRE();
		 }		
private: System::Void ArmorFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateArmorGUI();
		 }
private: System::Void ArmorFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateArmorGUI();
		 }
private: System::Void ArmorFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }	
		 }
private: System::Void ArmorFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }	
		 }
		
		 
		/// Droid Functions
private: System::Void UpdateDroidGUI(){
			 if (DroidFormArmorTextBox->Text != "" && DroidFormMassTextBox->Text != "" && 
				 DroidFormDrainTextBox->Text != "" && DroidFormSpeedTextBox->Text != "")
			 {
				 CalcDroidButton->Enabled = true;
			 }
			 else
			 {
				 CalcDroidButton->Enabled = false;
			 }
		 }
private: System::Void ResetDroidRE(){
			 DroidFormArmorTextBox->Clear();
			 DroidFormDrainTextBox->Clear();
			 DroidFormMassTextBox->Clear();
			 DroidFormSpeedTextBox->Clear();

			 D_ArmorOutputValueLabel->Text = "No Input";
			 D_DrainOutputValueLabel->Text = "No Input";
			 D_MassOutputValueLabel->Text = "No Input";
			 D_SpeedOutputValueLabel->Text = "No Input";
		 }
private: System::Void CalculateDroidRE(){
			 switch (CompLevelComboBox->SelectedIndex)
			 {
			 case 0: D_ArmorOutputValueLabel->Text = (Convert::ToDouble(DroidFormArmorTextBox->Text->ToString()) * 1.02).ToString(".##");
					 D_DrainOutputValueLabel->Text = (Convert::ToDouble(DroidFormDrainTextBox->Text->ToString()) * 0.98).ToString(".##");
					 D_MassOutputValueLabel->Text = (Convert::ToDouble(DroidFormMassTextBox->Text->ToString()) * 0.98).ToString(".##");
					 D_SpeedOutputValueLabel->Text = (Convert::ToDouble(DroidFormSpeedTextBox->Text->ToString()) * 0.98).ToString(".##");
				 break;
			 case 1: D_ArmorOutputValueLabel->Text = (Convert::ToDouble(DroidFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 D_DrainOutputValueLabel->Text = (Convert::ToDouble(DroidFormDrainTextBox->Text->ToString()) * 0.97).ToString(".##");
					 D_MassOutputValueLabel->Text = (Convert::ToDouble(DroidFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 D_SpeedOutputValueLabel->Text = (Convert::ToDouble(DroidFormSpeedTextBox->Text->ToString()) * 0.97).ToString(".##");
				 break;
			 case 2: D_ArmorOutputValueLabel->Text = (Convert::ToDouble(DroidFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 D_DrainOutputValueLabel->Text = (Convert::ToDouble(DroidFormDrainTextBox->Text->ToString()) * 0.97).ToString(".##");
					 D_MassOutputValueLabel->Text = (Convert::ToDouble(DroidFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 D_SpeedOutputValueLabel->Text = (Convert::ToDouble(DroidFormSpeedTextBox->Text->ToString()) * 0.97).ToString(".##");
				 break;
			 case 3: D_ArmorOutputValueLabel->Text = (Convert::ToDouble(DroidFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 D_DrainOutputValueLabel->Text = (Convert::ToDouble(DroidFormDrainTextBox->Text->ToString()) * 0.96).ToString(".##");
					 D_MassOutputValueLabel->Text = (Convert::ToDouble(DroidFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 D_SpeedOutputValueLabel->Text = (Convert::ToDouble(DroidFormSpeedTextBox->Text->ToString()) * 0.96).ToString(".##");
				 break;
			 case 4: D_ArmorOutputValueLabel->Text = (Convert::ToDouble(DroidFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 D_DrainOutputValueLabel->Text = (Convert::ToDouble(DroidFormDrainTextBox->Text->ToString()) * 0.96).ToString(".##");
					 D_MassOutputValueLabel->Text = (Convert::ToDouble(DroidFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 D_SpeedOutputValueLabel->Text = (Convert::ToDouble(DroidFormSpeedTextBox->Text->ToString()) * 0.96).ToString(".##");
				 break;
			 case 5: D_ArmorOutputValueLabel->Text = (Convert::ToDouble(DroidFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 D_DrainOutputValueLabel->Text = (Convert::ToDouble(DroidFormDrainTextBox->Text->ToString()) * 0.95).ToString(".##");
					 D_MassOutputValueLabel->Text = (Convert::ToDouble(DroidFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 D_SpeedOutputValueLabel->Text = (Convert::ToDouble(DroidFormSpeedTextBox->Text->ToString()) * 0.95).ToString(".##");
				 break;
			 case 6: D_ArmorOutputValueLabel->Text = (Convert::ToDouble(DroidFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 D_DrainOutputValueLabel->Text = (Convert::ToDouble(DroidFormDrainTextBox->Text->ToString()) * 0.95).ToString(".##");
					 D_MassOutputValueLabel->Text = (Convert::ToDouble(DroidFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 D_SpeedOutputValueLabel->Text = (Convert::ToDouble(DroidFormSpeedTextBox->Text->ToString()) * 0.95).ToString(".##");
				 break;
			 case 7: D_ArmorOutputValueLabel->Text = (Convert::ToDouble(DroidFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 D_DrainOutputValueLabel->Text = (Convert::ToDouble(DroidFormDrainTextBox->Text->ToString()) * 0.94).ToString(".##");
					 D_MassOutputValueLabel->Text = (Convert::ToDouble(DroidFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 D_SpeedOutputValueLabel->Text = (Convert::ToDouble(DroidFormSpeedTextBox->Text->ToString()) * 0.94).ToString(".##");
				 break;
			 case 8: D_ArmorOutputValueLabel->Text = (Convert::ToDouble(DroidFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 D_DrainOutputValueLabel->Text = (Convert::ToDouble(DroidFormDrainTextBox->Text->ToString()) * 0.94).ToString(".##");
					 D_MassOutputValueLabel->Text = (Convert::ToDouble(DroidFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 D_SpeedOutputValueLabel->Text = (Convert::ToDouble(DroidFormSpeedTextBox->Text->ToString()) * 0.94).ToString(".##");
				 break;
			 case 9: D_ArmorOutputValueLabel->Text = (Convert::ToDouble(DroidFormArmorTextBox->Text->ToString()) * 1.07).ToString(".##");
					 D_DrainOutputValueLabel->Text = (Convert::ToDouble(DroidFormDrainTextBox->Text->ToString()) * 0.93).ToString(".##");
					 D_MassOutputValueLabel->Text = (Convert::ToDouble(DroidFormMassTextBox->Text->ToString()) * 0.93).ToString(".##");
					 D_SpeedOutputValueLabel->Text = (Convert::ToDouble(DroidFormSpeedTextBox->Text->ToString()) * 0.93).ToString(".##");
				 break;
			 }
		 }
		/// Droid Event Handlers
private: System::Void CalcDroidButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 CalculateDroidRE();
		 }
private: System::Void ClearDroidButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ResetDroidRE();
		 }	
private: System::Void DroidFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateDroidGUI();
		 }
private: System::Void DroidFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateDroidGUI();
		 }
private: System::Void DroidFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateDroidGUI();
		 }
private: System::Void DroidFormSpeedTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateDroidGUI();
		 }
private: System::Void DroidFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void DroidFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void DroidFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void DroidFormSpeedTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }

		 
		/// Capacitor Functions
private: System::Void UpdateCapacitorGUI(){
			 if (CapacitorFormArmorTextBox->Text != "" && CapacitorFormMassTextBox->Text != "" && 
				 CapacitorFormDrainTextBox->Text != "" && CapacitorFormEnergyTextBox->Text != "" &&
				 CapacitorFormRechargeTextBox->Text != "")
			 {
				 CalcCapacitorButton->Enabled = true;
			 }
			 else
			 {
				 CalcCapacitorButton->Enabled = false;
			 }
		 }
private: System::Void ResetCapacitorRE(){
			 CapacitorFormArmorTextBox->Clear();
			 CapacitorFormDrainTextBox->Clear();
			 CapacitorFormMassTextBox->Clear();
			 CapacitorFormEnergyTextBox->Clear();
			 CapacitorFormRechargeTextBox->Clear();

			 C_ArmorOutputValueLabel->Text = "No Input";
			 C_DrainOutputValueLabel->Text = "No Input";
			 C_MassOutputValueLabel->Text = "No Input";
			 C_EnergyOutputValueLabel->Text = "No Input";
			 C_RechargeOutputValueLabel->Text = "No Input";
		 }
private: System::Void CalculateCapacitorRE(){
			 switch (CompLevelComboBox->SelectedIndex)
			 {
			 case 0: C_ArmorOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormArmorTextBox->Text->ToString()) * 1.02).ToString(".##");
					 C_DrainOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormDrainTextBox->Text->ToString()) * 0.98).ToString(".##");
					 C_MassOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormMassTextBox->Text->ToString()) * 0.98).ToString(".##");
					 C_EnergyOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormEnergyTextBox->Text->ToString()) * 1.02).ToString(".##");
					 C_RechargeOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormRechargeTextBox->Text->ToString()) * 1.02).ToString(".##");
				 break;
			 case 1: C_ArmorOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 C_DrainOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormDrainTextBox->Text->ToString()) * 0.97).ToString(".##");
					 C_MassOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 C_EnergyOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormEnergyTextBox->Text->ToString()) * 1.03).ToString(".##");
					 C_RechargeOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormRechargeTextBox->Text->ToString()) * 1.03).ToString(".##");
				 break;
			 case 2: C_ArmorOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 C_DrainOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormDrainTextBox->Text->ToString()) * 0.97).ToString(".##");
					 C_MassOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 C_EnergyOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormEnergyTextBox->Text->ToString()) * 1.03).ToString(".##");
					 C_RechargeOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormRechargeTextBox->Text->ToString()) * 1.03).ToString(".##");
				 break;
			 case 3: C_ArmorOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 C_DrainOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormDrainTextBox->Text->ToString()) * 0.96).ToString(".##");
					 C_MassOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 C_EnergyOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormEnergyTextBox->Text->ToString()) * 1.04).ToString(".##");
					 C_RechargeOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormRechargeTextBox->Text->ToString()) * 1.04).ToString(".##");
				 break;
			 case 4: C_ArmorOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 C_DrainOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormDrainTextBox->Text->ToString()) * 0.96).ToString(".##");
					 C_MassOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 C_EnergyOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormEnergyTextBox->Text->ToString()) * 1.04).ToString(".##");
					 C_RechargeOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormRechargeTextBox->Text->ToString()) * 1.04).ToString(".##");
				 break;
			 case 5: C_ArmorOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 C_DrainOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormDrainTextBox->Text->ToString()) * 0.95).ToString(".##");
					 C_MassOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 C_EnergyOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormEnergyTextBox->Text->ToString()) * 1.05).ToString(".##");
					 C_RechargeOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormRechargeTextBox->Text->ToString()) * 1.05).ToString(".##");
				 break;
			 case 6: C_ArmorOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 C_DrainOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormDrainTextBox->Text->ToString()) * 0.95).ToString(".##");
					 C_MassOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 C_EnergyOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormEnergyTextBox->Text->ToString()) * 1.05).ToString(".##");
					 C_RechargeOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormRechargeTextBox->Text->ToString()) * 1.05).ToString(".##");
				 break;
			 case 7: C_ArmorOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 C_DrainOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormDrainTextBox->Text->ToString()) * 0.94).ToString(".##");
					 C_MassOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 C_EnergyOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormEnergyTextBox->Text->ToString()) * 1.06).ToString(".##");
					 C_RechargeOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormRechargeTextBox->Text->ToString()) * 1.06).ToString(".##");
				 break;
			 case 8: C_ArmorOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 C_DrainOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormDrainTextBox->Text->ToString()) * 0.94).ToString(".##");
					 C_MassOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 C_EnergyOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormEnergyTextBox->Text->ToString()) * 1.06).ToString(".##");
					 C_RechargeOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormRechargeTextBox->Text->ToString()) * 1.06).ToString(".##");
				 break;
			 case 9: C_ArmorOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormArmorTextBox->Text->ToString()) * 1.07).ToString(".##");
					 C_DrainOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormDrainTextBox->Text->ToString()) * 0.93).ToString(".##");
					 C_MassOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormMassTextBox->Text->ToString()) * 0.93).ToString(".##");
					 C_EnergyOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormEnergyTextBox->Text->ToString()) * 1.07).ToString(".##");
					 C_RechargeOutputValueLabel->Text = (Convert::ToDouble(CapacitorFormRechargeTextBox->Text->ToString()) * 1.07).ToString(".##");
				 break;
			 }
		 }
		/// Capacitor Event Handlers
private: System::Void CalcCapacitorButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 CalculateCapacitorRE();
		 }
private: System::Void ClearCapacitorButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ResetCapacitorRE();
		 }

private: System::Void CapacitorFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateCapacitorGUI();
		 }
private: System::Void CapacitorFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateCapacitorGUI();
		 }
private: System::Void CapacitorFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateCapacitorGUI();
		 }
private: System::Void CapacitorFormEnergyTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateCapacitorGUI();
		 }
private: System::Void CapacitorFormRechargeTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateCapacitorGUI();
		 }
private: System::Void CapacitorFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void CapacitorFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void CapacitorFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void CapacitorFormEnergyTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void CapacitorFormRechargeTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
		 

		/// Weapon Functions
private: System::Void UpdateWeaponGUI(){
			 if (WeaponFormArmorTextBox->Text != "" && WeaponFormMassTextBox->Text != "" && 
				 WeaponFormDrainTextBox->Text != "" && WeaponFormMinDTextBox->Text != "" &&
				 WeaponFormMaxDTextBox->Text != "" && WeaponFormvsSTextBox->Text != "" &&
				 WeaponFormvsATextBox->Text != "" && WeaponFormEPSTextBox->Text != "" &&
				 WeaponFormRefireTextBox->Text != "")
			 {
				 CalcWeaponButton->Enabled = true;
			 }
			 else
			 {
				 CalcWeaponButton->Enabled = false;
			 }
		 }
private: System::Void ResetWeaponRE(){
			 WeaponFormArmorTextBox->Clear();
			 WeaponFormDrainTextBox->Clear();
			 WeaponFormMassTextBox->Clear();
			 WeaponFormMinDTextBox->Clear();
			 WeaponFormMaxDTextBox->Clear();
			 WeaponFormvsSTextBox->Clear();
			 WeaponFormvsATextBox->Clear();
			 WeaponFormEPSTextBox->Clear();
			 WeaponFormRefireTextBox->Clear();

			 W_ArmorOutputValueLabel->Text = "No Input";
			 W_DrainOutputValueLabel->Text = "No Input";
			 W_MassOutputValueLabel->Text = "No Input";
			 W_MinDOutputValueLabel->Text = "No Input";
			 W_MaxDOutputValueLabel->Text = "No Input";
			 W_vsSOutputValueLabel->Text = "No Input";
			 W_vsAOutputValueLabel->Text = "No Input";
			 W_EPSOutputValueLabel->Text = "No Input";
			 W_RefireOutputValueLabel->Text = "No Input";
		 }
private: System::Void CalculateWeaponRE(){
			 switch (CompLevelComboBox->SelectedIndex)
			 {
			 case 0: W_ArmorOutputValueLabel->Text = (Convert::ToDouble(WeaponFormArmorTextBox->Text->ToString()) * 1.02).ToString(".##");
					 W_DrainOutputValueLabel->Text = (Convert::ToDouble(WeaponFormDrainTextBox->Text->ToString()) * 0.98).ToString(".##");
					 W_MassOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMassTextBox->Text->ToString()) * 0.98).ToString(".##");
					 W_MinDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMinDTextBox->Text->ToString()) * 1.02).ToString(".##");
					 W_MaxDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMaxDTextBox->Text->ToString()) * 1.02).ToString(".##");
					 W_vsSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsSTextBox->Text->ToString()) * 1.02).ToString(".##");
					 W_vsAOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsATextBox->Text->ToString()) * 1.02).ToString(".##");
					 W_EPSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormEPSTextBox->Text->ToString()) * 0.98).ToString(".##");
					 W_RefireOutputValueLabel->Text = (Convert::ToDouble(WeaponFormRefireTextBox->Text->ToString()) * 0.98).ToString(".##");
				 break;
			 case 1: W_ArmorOutputValueLabel->Text = (Convert::ToDouble(WeaponFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 W_DrainOutputValueLabel->Text = (Convert::ToDouble(WeaponFormDrainTextBox->Text->ToString()) * 0.97).ToString(".##");
					 W_MassOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 W_MinDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMinDTextBox->Text->ToString()) * 1.03).ToString(".##");
					 W_MaxDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMaxDTextBox->Text->ToString()) * 1.03).ToString(".##");
					 W_vsSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsSTextBox->Text->ToString()) * 1.03).ToString(".##");
					 W_vsAOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsATextBox->Text->ToString()) * 1.03).ToString(".##");
					 W_EPSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormEPSTextBox->Text->ToString()) * 0.97).ToString(".##");
					 W_RefireOutputValueLabel->Text = (Convert::ToDouble(WeaponFormRefireTextBox->Text->ToString()) * 0.97).ToString(".##");
				 break;
			 case 2: W_ArmorOutputValueLabel->Text = (Convert::ToDouble(WeaponFormArmorTextBox->Text->ToString()) * 1.03).ToString(".##");
					 W_DrainOutputValueLabel->Text = (Convert::ToDouble(WeaponFormDrainTextBox->Text->ToString()) * 0.97).ToString(".##");
					 W_MassOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMassTextBox->Text->ToString()) * 0.97).ToString(".##");
					 W_MinDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMinDTextBox->Text->ToString()) * 1.03).ToString(".##");
					 W_MaxDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMaxDTextBox->Text->ToString()) * 1.03).ToString(".##");
					 W_vsSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsSTextBox->Text->ToString()) * 1.03).ToString(".##");
					 W_vsAOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsATextBox->Text->ToString()) * 1.03).ToString(".##");
					 W_EPSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormEPSTextBox->Text->ToString()) * 0.97).ToString(".##");
					 W_RefireOutputValueLabel->Text = (Convert::ToDouble(WeaponFormRefireTextBox->Text->ToString()) * 0.97).ToString(".##");
				 break;
			 case 3: W_ArmorOutputValueLabel->Text = (Convert::ToDouble(WeaponFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 W_DrainOutputValueLabel->Text = (Convert::ToDouble(WeaponFormDrainTextBox->Text->ToString()) * 0.96).ToString(".##");
					 W_MassOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 W_MinDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMinDTextBox->Text->ToString()) * 1.04).ToString(".##");
					 W_MaxDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMaxDTextBox->Text->ToString()) * 1.04).ToString(".##");
					 W_vsSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsSTextBox->Text->ToString()) * 1.04).ToString(".##");
					 W_vsAOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsATextBox->Text->ToString()) * 1.04).ToString(".##");
					 W_EPSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormEPSTextBox->Text->ToString()) * 0.96).ToString(".##");
					 W_RefireOutputValueLabel->Text = (Convert::ToDouble(WeaponFormRefireTextBox->Text->ToString()) * 0.96).ToString(".##");
				 break;
			 case 4: W_ArmorOutputValueLabel->Text = (Convert::ToDouble(WeaponFormArmorTextBox->Text->ToString()) * 1.04).ToString(".##");
					 W_DrainOutputValueLabel->Text = (Convert::ToDouble(WeaponFormDrainTextBox->Text->ToString()) * 0.96).ToString(".##");
					 W_MassOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMassTextBox->Text->ToString()) * 0.96).ToString(".##");
					 W_MinDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMinDTextBox->Text->ToString()) * 1.04).ToString(".##");
					 W_MaxDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMaxDTextBox->Text->ToString()) * 1.04).ToString(".##");
					 W_vsSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsSTextBox->Text->ToString()) * 1.04).ToString(".##");
					 W_vsAOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsATextBox->Text->ToString()) * 1.04).ToString(".##");
					 W_EPSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormEPSTextBox->Text->ToString()) * 0.96).ToString(".##");
					 W_RefireOutputValueLabel->Text = (Convert::ToDouble(WeaponFormRefireTextBox->Text->ToString()) * 0.96).ToString(".##");
				 break;
			 case 5: W_ArmorOutputValueLabel->Text = (Convert::ToDouble(WeaponFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 W_DrainOutputValueLabel->Text = (Convert::ToDouble(WeaponFormDrainTextBox->Text->ToString()) * 0.95).ToString(".##");
					 W_MassOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 W_MinDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMinDTextBox->Text->ToString()) * 1.05).ToString(".##");
					 W_MaxDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMaxDTextBox->Text->ToString()) * 1.05).ToString(".##");
					 W_vsSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsSTextBox->Text->ToString()) * 1.05).ToString(".##");
					 W_vsAOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsATextBox->Text->ToString()) * 1.05).ToString(".##");
					 W_EPSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormEPSTextBox->Text->ToString()) * 0.95).ToString(".##");
					 W_RefireOutputValueLabel->Text = (Convert::ToDouble(WeaponFormRefireTextBox->Text->ToString()) * 0.95).ToString(".##");
				 break;
			 case 6: W_ArmorOutputValueLabel->Text = (Convert::ToDouble(WeaponFormArmorTextBox->Text->ToString()) * 1.05).ToString(".##");
					 W_DrainOutputValueLabel->Text = (Convert::ToDouble(WeaponFormDrainTextBox->Text->ToString()) * 0.95).ToString(".##");
					 W_MassOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMassTextBox->Text->ToString()) * 0.95).ToString(".##");
					 W_MinDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMinDTextBox->Text->ToString()) * 1.05).ToString(".##");
					 W_MaxDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMaxDTextBox->Text->ToString()) * 1.05).ToString(".##");
					 W_vsSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsSTextBox->Text->ToString()) * 1.05).ToString(".##");
					 W_vsAOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsATextBox->Text->ToString()) * 1.05).ToString(".##");
					 W_EPSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormEPSTextBox->Text->ToString()) * 0.95).ToString(".##");
					 W_RefireOutputValueLabel->Text = (Convert::ToDouble(WeaponFormRefireTextBox->Text->ToString()) * 0.95).ToString(".##");
				 break;
			 case 7: W_ArmorOutputValueLabel->Text = (Convert::ToDouble(WeaponFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 W_DrainOutputValueLabel->Text = (Convert::ToDouble(WeaponFormDrainTextBox->Text->ToString()) * 0.94).ToString(".##");
					 W_MassOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 W_MinDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMinDTextBox->Text->ToString()) * 1.06).ToString(".##");
					 W_MaxDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMaxDTextBox->Text->ToString()) * 1.06).ToString(".##");
					 W_vsSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsSTextBox->Text->ToString()) * 1.06).ToString(".##");
					 W_vsAOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsATextBox->Text->ToString()) * 1.06).ToString(".##");
					 W_EPSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormEPSTextBox->Text->ToString()) * 0.94).ToString(".##");
					 W_RefireOutputValueLabel->Text = (Convert::ToDouble(WeaponFormRefireTextBox->Text->ToString()) * 0.94).ToString(".##");
				 break;
			 case 8: W_ArmorOutputValueLabel->Text = (Convert::ToDouble(WeaponFormArmorTextBox->Text->ToString()) * 1.06).ToString(".##");
					 W_DrainOutputValueLabel->Text = (Convert::ToDouble(WeaponFormDrainTextBox->Text->ToString()) * 0.94).ToString(".##");
					 W_MassOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMassTextBox->Text->ToString()) * 0.94).ToString(".##");
					 W_MinDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMinDTextBox->Text->ToString()) * 1.06).ToString(".##");
					 W_MaxDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMaxDTextBox->Text->ToString()) * 1.06).ToString(".##");
					 W_vsSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsSTextBox->Text->ToString()) * 1.06).ToString(".##");
					 W_vsAOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsATextBox->Text->ToString()) * 1.06).ToString(".##");
					 W_EPSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormEPSTextBox->Text->ToString()) * 0.94).ToString(".##");
					 W_RefireOutputValueLabel->Text = (Convert::ToDouble(WeaponFormRefireTextBox->Text->ToString()) * 0.94).ToString(".##");
				 break;
			 case 9: W_ArmorOutputValueLabel->Text = (Convert::ToDouble(WeaponFormArmorTextBox->Text->ToString()) * 1.07).ToString(".##");
					 W_DrainOutputValueLabel->Text = (Convert::ToDouble(WeaponFormDrainTextBox->Text->ToString()) * 0.93).ToString(".##");
					 W_MassOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMassTextBox->Text->ToString()) * 0.93).ToString(".##");
					 W_MinDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMinDTextBox->Text->ToString()) * 1.07).ToString(".##");
					 W_MaxDOutputValueLabel->Text = (Convert::ToDouble(WeaponFormMaxDTextBox->Text->ToString()) * 1.07).ToString(".##");
					 W_vsSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsSTextBox->Text->ToString()) * 1.07).ToString(".##");
					 W_vsAOutputValueLabel->Text = (Convert::ToDouble(WeaponFormvsATextBox->Text->ToString()) * 1.07).ToString(".##");
					 W_EPSOutputValueLabel->Text = (Convert::ToDouble(WeaponFormEPSTextBox->Text->ToString()) * 0.93).ToString(".##");
					 W_RefireOutputValueLabel->Text = (Convert::ToDouble(WeaponFormRefireTextBox->Text->ToString()) * 0.93).ToString(".##");
				 break;
			 }
		 }
		/// Weapon Event Handlers
private: System::Void CalcWeaponButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 CalculateWeaponRE();
		 }
private: System::Void ClearWeaponButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ResetWeaponRE();
		 }
private: System::Void WeaponFormArmorTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateWeaponGUI();
		 }
private: System::Void WeaponFormMassTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateWeaponGUI();
		 }
private: System::Void WeaponFormDrainTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateWeaponGUI();
		 }
private: System::Void WeaponFormMinDTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateWeaponGUI();
		 }
private: System::Void WeaponFormMaxDTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateWeaponGUI();
		 }
private: System::Void WeaponFormvsSTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateWeaponGUI();
		 }
private: System::Void WeaponFormvsATextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateWeaponGUI();
		 }
private: System::Void WeaponFormEPSTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateWeaponGUI();
		 }
private: System::Void WeaponFormRefireTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateWeaponGUI();
		 }
private: System::Void WeaponFormArmorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormMassTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormDrainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormMinDTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormMaxDTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormvsSTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormvsATextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormEPSTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
private: System::Void WeaponFormRefireTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!(e->KeyChar == Convert::ToChar(Keys::Back)))
			 {
				 if (!((e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '.')))
				 {
					 e->Handled = true;
				 }
			 }
		 }
		
		 
		/// Other Event Handlers
private: System::Void CompTypeComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 switch (CompTypeComboBox->SelectedIndex)
			 {
			 case 0: ReactorPanel->BringToFront();
					 ReactorPanel->Show();

					 EnginePanel->Hide();
					 BoosterPanel->Hide();
					 SheildPanel->Hide();
					 ArmorPanel->Hide();
					 DroidPanel->Hide();
					 CapacitorPanel->Hide();
					 WeaponPanel->Hide();

					 this->Height = compInfoheight + (ReactorPanel->Height + 5);
				 break;
			 case 1: EnginePanel->BringToFront();
					 EnginePanel->Show();

					 ReactorPanel->Hide();
					 BoosterPanel->Hide();
					 SheildPanel->Hide();
					 ArmorPanel->Hide();
					 DroidPanel->Hide();
					 CapacitorPanel->Hide();
					 WeaponPanel->Hide();

					 this->Height = compInfoheight + (EnginePanel->Height + 5);
				 break;
			 case 2: BoosterPanel->BringToFront();
					 BoosterPanel->Show();

					 ReactorPanel->Hide();
					 EnginePanel->Hide();
					 SheildPanel->Hide();
					 ArmorPanel->Hide();
					 DroidPanel->Hide();
					 CapacitorPanel->Hide();
					 WeaponPanel->Hide();

					 this->Height = compInfoheight + (BoosterPanel->Height + 5);
				 break;
			 case 3: SheildPanel->BringToFront();
					 SheildPanel->Show();

					 ReactorPanel->Hide();
					 EnginePanel->Hide();
					 BoosterPanel->Hide();
					 ArmorPanel->Hide();
					 DroidPanel->Hide();
					 CapacitorPanel->Hide();
					 WeaponPanel->Hide();

					 this->Height = compInfoheight + (SheildPanel->Height + 5);
				 break;
			 case 4: ArmorPanel->BringToFront();
					 ArmorPanel->Show();

					 ReactorPanel->Hide();
					 EnginePanel->Hide();
					 BoosterPanel->Hide();
					 SheildPanel->Hide();
					 DroidPanel->Hide();
					 CapacitorPanel->Hide();
					 WeaponPanel->Hide();

					 this->Height = compInfoheight + (ArmorPanel->Height + 5);
				 break;
			 case 5: DroidPanel->BringToFront();
					 DroidPanel->Show();

					 ReactorPanel->Hide();
					 EnginePanel->Hide();
					 BoosterPanel->Hide();
					 SheildPanel->Hide();
					 ArmorPanel->Hide();
					 CapacitorPanel->Hide();
					 WeaponPanel->Hide();

					 this->Height = compInfoheight + (DroidPanel->Height + 5);
				 break;
			 case 6: CapacitorPanel->BringToFront();
					 CapacitorPanel->Show();

					 ReactorPanel->Hide();
					 EnginePanel->Hide();
					 BoosterPanel->Hide();
					 SheildPanel->Hide();
					 ArmorPanel->Hide();
					 DroidPanel->Hide();
					 WeaponPanel->Hide();

					 this->Height = compInfoheight + (CapacitorPanel->Height + 5);
				 break;
			 case 7: WeaponPanel->BringToFront();
					 WeaponPanel->Show();

					 ReactorPanel->Hide();
					 EnginePanel->Hide();
					 BoosterPanel->Hide();
					 SheildPanel->Hide();
					 ArmorPanel->Hide();
					 DroidPanel->Hide();
					 CapacitorPanel->Hide();

					 this->Height = compInfoheight + (WeaponPanel->Height + 5);
				 break;
			 }
		 }
};
}
