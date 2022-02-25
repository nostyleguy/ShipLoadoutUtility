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
	/// Summary for PropulsionStatsForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class PropulsionStatsForm : public System::Windows::Forms::Form
	{
	public:
		PropulsionStatsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		PropulsionStatsForm(Engine^ loadedEngine, int selectedEO, int selectedChassis)
		{
			InitializeComponent();

			CalculateChassisMods(selectedChassis);
			CalculateEngineStats(loadedEngine, selectedEO);
			CalculateOptimalTurnSpeed();
		}

		PropulsionStatsForm(Engine^ loadedEngine, Booster^ loadedBooster, int selectedEO, int selectedChassis)
		{
			InitializeComponent();

			CalculateChassisMods(selectedChassis);
			CalculateEngineStats(loadedEngine, selectedEO);
			CalculateBoosterValues(loadedBooster, selectedEO);
			CalculateOptimalTurnSpeed();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PropulsionStatsForm()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region PropulsionStatsForm Item Declerations
	private: System::Windows::Forms::Label^  PropulsionStatsFormLabel;
	private: System::Windows::Forms::Button^  CloseButton;
	private: System::Windows::Forms::Label^  E_RollLabel;
	private: System::Windows::Forms::Label^  E_YawLabel;
	private: System::Windows::Forms::Label^  E_PitchLabel;
	private: System::Windows::Forms::Label^  EngineCompLabel;
	private: System::Windows::Forms::Label^  ChassisModLabel;
	private: System::Windows::Forms::Label^  TopSpeedLabel;
	private: System::Windows::Forms::Label^  BoostTimeLabel;
	private: System::Windows::Forms::Label^  BoostedTopSpeedLabel;
	private: System::Windows::Forms::Label^  OptimalTurnSpeedLabel;
	private: System::Windows::Forms::Label^  OptimalTurnSpeedValueLabel;
	private: System::Windows::Forms::Label^  BoostedTopSpeedValueLabel;
	private: System::Windows::Forms::Label^  BoostTimeValueLabel;
	private: System::Windows::Forms::Label^  TopSpeedValueLabel;
	private: System::Windows::Forms::Label^  PitchValueLabel;
	private: System::Windows::Forms::Label^  YawValueLabel;
	private: System::Windows::Forms::Label^  RollValueLabel;
	private: System::Windows::Forms::Label^  PitchChassisLabel;
	private: System::Windows::Forms::Label^  YawChassisLabel;
	private: System::Windows::Forms::Label^  RollChassisLabel;
	private: System::Windows::Forms::Label^  BoosterRechargeTimeValueLabel;
	private: System::Windows::Forms::Label^  BoosterRechargeTimeLabel;
	private: System::Windows::Forms::Panel^  YPRPanel;
	private: System::Windows::Forms::Panel^  StatsPanel;
	private: System::Windows::Forms::Panel^  FoilsStatsPanel;
	private: System::Windows::Forms::Label^  FoilsClosedLabel;
	private: System::Windows::Forms::Label^  TopSpeedFoilsClosedLabel;
	private: System::Windows::Forms::Label^  BoostTimeFoilsLabel;
	private: System::Windows::Forms::Label^  BoosterRechargeFoilsValueLabel;
	private: System::Windows::Forms::Label^  BoostedTopSpeedFoilsClosedLabel;
	private: System::Windows::Forms::Label^  BoosterRechargeFoilsLabel;
	private: System::Windows::Forms::Label^  OptimalTurnSpeedFoilsClosedLabel;
	private: System::Windows::Forms::Label^  OptimalTurnSpeedFoilsClosedValueLabel;
	private: System::Windows::Forms::Label^  TopSpeedFoilsClosedValueLabel;
	private: System::Windows::Forms::Label^  BoostedTopSpeedFoilsClosedValueLabel;
	private: System::Windows::Forms::Label^  BoostTimeFoilsValueLabel;
	private: System::Windows::Forms::Label^  FoilsOpenLabel;
	private: System::Windows::Forms::Label^  TopSpeedFoilsOpenLabel;
	private: System::Windows::Forms::Label^  BoostedTopSpeedFoilsOpenLabel;
	private: System::Windows::Forms::Label^  OptimalTurnSpeedFoilsOpenLabel;
	private: System::Windows::Forms::Label^  OptimalTurnSpeedFoilsOpenValueLabel;
	private: System::Windows::Forms::Label^  TopSpeedFoilsOpenValueLabel;
	private: System::Windows::Forms::Label^  BoostedTopSpeedFoilsOpenValueLabel;
	protected: 
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PropulsionStatsForm::typeid));
			this->PropulsionStatsFormLabel = (gcnew System::Windows::Forms::Label());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->E_RollLabel = (gcnew System::Windows::Forms::Label());
			this->E_YawLabel = (gcnew System::Windows::Forms::Label());
			this->E_PitchLabel = (gcnew System::Windows::Forms::Label());
			this->EngineCompLabel = (gcnew System::Windows::Forms::Label());
			this->ChassisModLabel = (gcnew System::Windows::Forms::Label());
			this->TopSpeedLabel = (gcnew System::Windows::Forms::Label());
			this->BoostTimeLabel = (gcnew System::Windows::Forms::Label());
			this->BoostedTopSpeedLabel = (gcnew System::Windows::Forms::Label());
			this->OptimalTurnSpeedLabel = (gcnew System::Windows::Forms::Label());
			this->OptimalTurnSpeedValueLabel = (gcnew System::Windows::Forms::Label());
			this->BoostedTopSpeedValueLabel = (gcnew System::Windows::Forms::Label());
			this->BoostTimeValueLabel = (gcnew System::Windows::Forms::Label());
			this->TopSpeedValueLabel = (gcnew System::Windows::Forms::Label());
			this->PitchValueLabel = (gcnew System::Windows::Forms::Label());
			this->YawValueLabel = (gcnew System::Windows::Forms::Label());
			this->RollValueLabel = (gcnew System::Windows::Forms::Label());
			this->PitchChassisLabel = (gcnew System::Windows::Forms::Label());
			this->YawChassisLabel = (gcnew System::Windows::Forms::Label());
			this->RollChassisLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterRechargeTimeValueLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterRechargeTimeLabel = (gcnew System::Windows::Forms::Label());
			this->YPRPanel = (gcnew System::Windows::Forms::Panel());
			this->StatsPanel = (gcnew System::Windows::Forms::Panel());
			this->FoilsStatsPanel = (gcnew System::Windows::Forms::Panel());
			this->FoilsOpenLabel = (gcnew System::Windows::Forms::Label());
			this->TopSpeedFoilsOpenLabel = (gcnew System::Windows::Forms::Label());
			this->BoostedTopSpeedFoilsOpenLabel = (gcnew System::Windows::Forms::Label());
			this->OptimalTurnSpeedFoilsOpenLabel = (gcnew System::Windows::Forms::Label());
			this->OptimalTurnSpeedFoilsOpenValueLabel = (gcnew System::Windows::Forms::Label());
			this->TopSpeedFoilsOpenValueLabel = (gcnew System::Windows::Forms::Label());
			this->BoostedTopSpeedFoilsOpenValueLabel = (gcnew System::Windows::Forms::Label());
			this->FoilsClosedLabel = (gcnew System::Windows::Forms::Label());
			this->TopSpeedFoilsClosedLabel = (gcnew System::Windows::Forms::Label());
			this->BoostTimeFoilsLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterRechargeFoilsValueLabel = (gcnew System::Windows::Forms::Label());
			this->BoostedTopSpeedFoilsClosedLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterRechargeFoilsLabel = (gcnew System::Windows::Forms::Label());
			this->OptimalTurnSpeedFoilsClosedLabel = (gcnew System::Windows::Forms::Label());
			this->OptimalTurnSpeedFoilsClosedValueLabel = (gcnew System::Windows::Forms::Label());
			this->TopSpeedFoilsClosedValueLabel = (gcnew System::Windows::Forms::Label());
			this->BoostedTopSpeedFoilsClosedValueLabel = (gcnew System::Windows::Forms::Label());
			this->BoostTimeFoilsValueLabel = (gcnew System::Windows::Forms::Label());
			this->YPRPanel->SuspendLayout();
			this->StatsPanel->SuspendLayout();
			this->FoilsStatsPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// PropulsionStatsFormLabel
			// 
			this->PropulsionStatsFormLabel->AutoSize = true;
			this->PropulsionStatsFormLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->PropulsionStatsFormLabel->Location = System::Drawing::Point(40, 9);
			this->PropulsionStatsFormLabel->Name = L"PropulsionStatsFormLabel";
			this->PropulsionStatsFormLabel->Size = System::Drawing::Size(232, 16);
			this->PropulsionStatsFormLabel->TabIndex = 2;
			this->PropulsionStatsFormLabel->Text = L"P r o p u l s i o n  S t a t i s t i c s";
			// 
			// CloseButton
			// 
			this->CloseButton->ForeColor = System::Drawing::Color::Black;
			this->CloseButton->Location = System::Drawing::Point(119, 325);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 46;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &PropulsionStatsForm::CloseButton_Click);
			// 
			// E_RollLabel
			// 
			this->E_RollLabel->AutoSize = true;
			this->E_RollLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_RollLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_RollLabel->Location = System::Drawing::Point(8, 102);
			this->E_RollLabel->Name = L"E_RollLabel";
			this->E_RollLabel->Size = System::Drawing::Size(37, 14);
			this->E_RollLabel->TabIndex = 70;
			this->E_RollLabel->Text = L"Roll:";
			// 
			// E_YawLabel
			// 
			this->E_YawLabel->AutoSize = true;
			this->E_YawLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_YawLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_YawLabel->Location = System::Drawing::Point(8, 70);
			this->E_YawLabel->Name = L"E_YawLabel";
			this->E_YawLabel->Size = System::Drawing::Size(42, 14);
			this->E_YawLabel->TabIndex = 69;
			this->E_YawLabel->Text = L"Yaw:";
			// 
			// E_PitchLabel
			// 
			this->E_PitchLabel->AutoSize = true;
			this->E_PitchLabel->BackColor = System::Drawing::Color::Transparent;
			this->E_PitchLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->E_PitchLabel->Location = System::Drawing::Point(8, 38);
			this->E_PitchLabel->Name = L"E_PitchLabel";
			this->E_PitchLabel->Size = System::Drawing::Size(45, 14);
			this->E_PitchLabel->TabIndex = 68;
			this->E_PitchLabel->Text = L"Pitch:";
			// 
			// EngineCompLabel
			// 
			this->EngineCompLabel->AutoSize = true;
			this->EngineCompLabel->BackColor = System::Drawing::Color::Transparent;
			this->EngineCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineCompLabel->Location = System::Drawing::Point(58, 11);
			this->EngineCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EngineCompLabel->Name = L"EngineCompLabel";
			this->EngineCompLabel->Size = System::Drawing::Size(51, 14);
			this->EngineCompLabel->TabIndex = 278;
			this->EngineCompLabel->Text = L"Engine";
			// 
			// ChassisModLabel
			// 
			this->ChassisModLabel->AutoSize = true;
			this->ChassisModLabel->BackColor = System::Drawing::Color::Transparent;
			this->ChassisModLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ChassisModLabel->Location = System::Drawing::Point(124, 11);
			this->ChassisModLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ChassisModLabel->Name = L"ChassisModLabel";
			this->ChassisModLabel->Size = System::Drawing::Size(95, 14);
			this->ChassisModLabel->TabIndex = 279;
			this->ChassisModLabel->Text = L"Chassis Mods";
			// 
			// TopSpeedLabel
			// 
			this->TopSpeedLabel->AutoSize = true;
			this->TopSpeedLabel->BackColor = System::Drawing::Color::Transparent;
			this->TopSpeedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TopSpeedLabel->Location = System::Drawing::Point(5, 29);
			this->TopSpeedLabel->Name = L"TopSpeedLabel";
			this->TopSpeedLabel->Size = System::Drawing::Size(121, 14);
			this->TopSpeedLabel->TabIndex = 281;
			this->TopSpeedLabel->Text = L"Actual Top Speed:";
			// 
			// BoostTimeLabel
			// 
			this->BoostTimeLabel->AutoSize = true;
			this->BoostTimeLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoostTimeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoostTimeLabel->Location = System::Drawing::Point(5, 82);
			this->BoostTimeLabel->Name = L"BoostTimeLabel";
			this->BoostTimeLabel->Size = System::Drawing::Size(148, 14);
			this->BoostTimeLabel->TabIndex = 282;
			this->BoostTimeLabel->Text = L"Booster Burn Time (s):";
			// 
			// BoostedTopSpeedLabel
			// 
			this->BoostedTopSpeedLabel->AutoSize = true;
			this->BoostedTopSpeedLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoostedTopSpeedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoostedTopSpeedLabel->Location = System::Drawing::Point(5, 43);
			this->BoostedTopSpeedLabel->Name = L"BoostedTopSpeedLabel";
			this->BoostedTopSpeedLabel->Size = System::Drawing::Size(135, 14);
			this->BoostedTopSpeedLabel->TabIndex = 283;
			this->BoostedTopSpeedLabel->Text = L"Boosted Top Speed:";
			// 
			// OptimalTurnSpeedLabel
			// 
			this->OptimalTurnSpeedLabel->AutoSize = true;
			this->OptimalTurnSpeedLabel->BackColor = System::Drawing::Color::Transparent;
			this->OptimalTurnSpeedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OptimalTurnSpeedLabel->Location = System::Drawing::Point(5, 57);
			this->OptimalTurnSpeedLabel->Name = L"OptimalTurnSpeedLabel";
			this->OptimalTurnSpeedLabel->Size = System::Drawing::Size(136, 14);
			this->OptimalTurnSpeedLabel->TabIndex = 284;
			this->OptimalTurnSpeedLabel->Text = L"Optimal Turn Speed:";
			// 
			// OptimalTurnSpeedValueLabel
			// 
			this->OptimalTurnSpeedValueLabel->AutoSize = true;
			this->OptimalTurnSpeedValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->OptimalTurnSpeedValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OptimalTurnSpeedValueLabel->Location = System::Drawing::Point(191, 57);
			this->OptimalTurnSpeedValueLabel->Name = L"OptimalTurnSpeedValueLabel";
			this->OptimalTurnSpeedValueLabel->Size = System::Drawing::Size(71, 14);
			this->OptimalTurnSpeedValueLabel->TabIndex = 288;
			this->OptimalTurnSpeedValueLabel->Text = L"No Engine";
			// 
			// BoostedTopSpeedValueLabel
			// 
			this->BoostedTopSpeedValueLabel->AutoSize = true;
			this->BoostedTopSpeedValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoostedTopSpeedValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoostedTopSpeedValueLabel->Location = System::Drawing::Point(191, 43);
			this->BoostedTopSpeedValueLabel->Name = L"BoostedTopSpeedValueLabel";
			this->BoostedTopSpeedValueLabel->Size = System::Drawing::Size(77, 14);
			this->BoostedTopSpeedValueLabel->TabIndex = 287;
			this->BoostedTopSpeedValueLabel->Text = L"No Booster";
			// 
			// BoostTimeValueLabel
			// 
			this->BoostTimeValueLabel->AutoSize = true;
			this->BoostTimeValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoostTimeValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoostTimeValueLabel->Location = System::Drawing::Point(191, 82);
			this->BoostTimeValueLabel->Name = L"BoostTimeValueLabel";
			this->BoostTimeValueLabel->Size = System::Drawing::Size(77, 14);
			this->BoostTimeValueLabel->TabIndex = 286;
			this->BoostTimeValueLabel->Text = L"No Booster";
			// 
			// TopSpeedValueLabel
			// 
			this->TopSpeedValueLabel->AutoSize = true;
			this->TopSpeedValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->TopSpeedValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TopSpeedValueLabel->Location = System::Drawing::Point(191, 29);
			this->TopSpeedValueLabel->Name = L"TopSpeedValueLabel";
			this->TopSpeedValueLabel->Size = System::Drawing::Size(71, 14);
			this->TopSpeedValueLabel->TabIndex = 285;
			this->TopSpeedValueLabel->Text = L"No Engine";
			// 
			// PitchValueLabel
			// 
			this->PitchValueLabel->AutoSize = true;
			this->PitchValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->PitchValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->PitchValueLabel->Location = System::Drawing::Point(62, 38);
			this->PitchValueLabel->Name = L"PitchValueLabel";
			this->PitchValueLabel->Size = System::Drawing::Size(71, 14);
			this->PitchValueLabel->TabIndex = 289;
			this->PitchValueLabel->Text = L"No Engine";
			// 
			// YawValueLabel
			// 
			this->YawValueLabel->AutoSize = true;
			this->YawValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->YawValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->YawValueLabel->Location = System::Drawing::Point(62, 70);
			this->YawValueLabel->Name = L"YawValueLabel";
			this->YawValueLabel->Size = System::Drawing::Size(71, 14);
			this->YawValueLabel->TabIndex = 290;
			this->YawValueLabel->Text = L"No Engine";
			// 
			// RollValueLabel
			// 
			this->RollValueLabel->AutoSize = true;
			this->RollValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->RollValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RollValueLabel->Location = System::Drawing::Point(62, 102);
			this->RollValueLabel->Name = L"RollValueLabel";
			this->RollValueLabel->Size = System::Drawing::Size(71, 14);
			this->RollValueLabel->TabIndex = 291;
			this->RollValueLabel->Text = L"No Engine";
			// 
			// PitchChassisLabel
			// 
			this->PitchChassisLabel->AutoSize = true;
			this->PitchChassisLabel->BackColor = System::Drawing::Color::Transparent;
			this->PitchChassisLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->PitchChassisLabel->Location = System::Drawing::Point(151, 38);
			this->PitchChassisLabel->Name = L"PitchChassisLabel";
			this->PitchChassisLabel->Size = System::Drawing::Size(71, 14);
			this->PitchChassisLabel->TabIndex = 292;
			this->PitchChassisLabel->Text = L"No Engine";
			// 
			// YawChassisLabel
			// 
			this->YawChassisLabel->AutoSize = true;
			this->YawChassisLabel->BackColor = System::Drawing::Color::Transparent;
			this->YawChassisLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->YawChassisLabel->Location = System::Drawing::Point(151, 70);
			this->YawChassisLabel->Name = L"YawChassisLabel";
			this->YawChassisLabel->Size = System::Drawing::Size(71, 14);
			this->YawChassisLabel->TabIndex = 293;
			this->YawChassisLabel->Text = L"No Engine";
			// 
			// RollChassisLabel
			// 
			this->RollChassisLabel->AutoSize = true;
			this->RollChassisLabel->BackColor = System::Drawing::Color::Transparent;
			this->RollChassisLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->RollChassisLabel->Location = System::Drawing::Point(151, 102);
			this->RollChassisLabel->Name = L"RollChassisLabel";
			this->RollChassisLabel->Size = System::Drawing::Size(71, 14);
			this->RollChassisLabel->TabIndex = 294;
			this->RollChassisLabel->Text = L"No Engine";
			// 
			// BoosterRechargeTimeValueLabel
			// 
			this->BoosterRechargeTimeValueLabel->AutoSize = true;
			this->BoosterRechargeTimeValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterRechargeTimeValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterRechargeTimeValueLabel->Location = System::Drawing::Point(191, 96);
			this->BoosterRechargeTimeValueLabel->Name = L"BoosterRechargeTimeValueLabel";
			this->BoosterRechargeTimeValueLabel->Size = System::Drawing::Size(77, 14);
			this->BoosterRechargeTimeValueLabel->TabIndex = 299;
			this->BoosterRechargeTimeValueLabel->Text = L"No Booster";
			// 
			// BoosterRechargeTimeLabel
			// 
			this->BoosterRechargeTimeLabel->AutoSize = true;
			this->BoosterRechargeTimeLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterRechargeTimeLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterRechargeTimeLabel->Location = System::Drawing::Point(5, 96);
			this->BoosterRechargeTimeLabel->Name = L"BoosterRechargeTimeLabel";
			this->BoosterRechargeTimeLabel->Size = System::Drawing::Size(178, 14);
			this->BoosterRechargeTimeLabel->TabIndex = 298;
			this->BoosterRechargeTimeLabel->Text = L"Booster Recharge Time (s):";
			// 
			// YPRPanel
			// 
			this->YPRPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"YPRPanel.BackgroundImage")));
			this->YPRPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->YPRPanel->Controls->Add(this->EngineCompLabel);
			this->YPRPanel->Controls->Add(this->E_PitchLabel);
			this->YPRPanel->Controls->Add(this->E_YawLabel);
			this->YPRPanel->Controls->Add(this->RollChassisLabel);
			this->YPRPanel->Controls->Add(this->E_RollLabel);
			this->YPRPanel->Controls->Add(this->YawChassisLabel);
			this->YPRPanel->Controls->Add(this->ChassisModLabel);
			this->YPRPanel->Controls->Add(this->PitchChassisLabel);
			this->YPRPanel->Controls->Add(this->PitchValueLabel);
			this->YPRPanel->Controls->Add(this->RollValueLabel);
			this->YPRPanel->Controls->Add(this->YawValueLabel);
			this->YPRPanel->Location = System::Drawing::Point(42, 29);
			this->YPRPanel->Name = L"YPRPanel";
			this->YPRPanel->Size = System::Drawing::Size(229, 128);
			this->YPRPanel->TabIndex = 300;
			// 
			// StatsPanel
			// 
			this->StatsPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"StatsPanel.BackgroundImage")));
			this->StatsPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->StatsPanel->Controls->Add(this->TopSpeedLabel);
			this->StatsPanel->Controls->Add(this->BoostTimeLabel);
			this->StatsPanel->Controls->Add(this->BoosterRechargeTimeValueLabel);
			this->StatsPanel->Controls->Add(this->BoostedTopSpeedLabel);
			this->StatsPanel->Controls->Add(this->BoosterRechargeTimeLabel);
			this->StatsPanel->Controls->Add(this->OptimalTurnSpeedLabel);
			this->StatsPanel->Controls->Add(this->OptimalTurnSpeedValueLabel);
			this->StatsPanel->Controls->Add(this->TopSpeedValueLabel);
			this->StatsPanel->Controls->Add(this->BoostedTopSpeedValueLabel);
			this->StatsPanel->Controls->Add(this->BoostTimeValueLabel);
			this->StatsPanel->Location = System::Drawing::Point(5, 171);
			this->StatsPanel->Name = L"StatsPanel";
			this->StatsPanel->Size = System::Drawing::Size(302, 138);
			this->StatsPanel->TabIndex = 301;
			// 
			// FoilsStatsPanel
			// 
			this->FoilsStatsPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"FoilsStatsPanel.BackgroundImage")));
			this->FoilsStatsPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->FoilsStatsPanel->Controls->Add(this->FoilsOpenLabel);
			this->FoilsStatsPanel->Controls->Add(this->TopSpeedFoilsOpenLabel);
			this->FoilsStatsPanel->Controls->Add(this->BoostedTopSpeedFoilsOpenLabel);
			this->FoilsStatsPanel->Controls->Add(this->OptimalTurnSpeedFoilsOpenLabel);
			this->FoilsStatsPanel->Controls->Add(this->OptimalTurnSpeedFoilsOpenValueLabel);
			this->FoilsStatsPanel->Controls->Add(this->TopSpeedFoilsOpenValueLabel);
			this->FoilsStatsPanel->Controls->Add(this->BoostedTopSpeedFoilsOpenValueLabel);
			this->FoilsStatsPanel->Controls->Add(this->FoilsClosedLabel);
			this->FoilsStatsPanel->Controls->Add(this->TopSpeedFoilsClosedLabel);
			this->FoilsStatsPanel->Controls->Add(this->BoostTimeFoilsLabel);
			this->FoilsStatsPanel->Controls->Add(this->BoosterRechargeFoilsValueLabel);
			this->FoilsStatsPanel->Controls->Add(this->BoostedTopSpeedFoilsClosedLabel);
			this->FoilsStatsPanel->Controls->Add(this->BoosterRechargeFoilsLabel);
			this->FoilsStatsPanel->Controls->Add(this->OptimalTurnSpeedFoilsClosedLabel);
			this->FoilsStatsPanel->Controls->Add(this->OptimalTurnSpeedFoilsClosedValueLabel);
			this->FoilsStatsPanel->Controls->Add(this->TopSpeedFoilsClosedValueLabel);
			this->FoilsStatsPanel->Controls->Add(this->BoostedTopSpeedFoilsClosedValueLabel);
			this->FoilsStatsPanel->Controls->Add(this->BoostTimeFoilsValueLabel);
			this->FoilsStatsPanel->Location = System::Drawing::Point(5, 163);
			this->FoilsStatsPanel->Name = L"FoilsStatsPanel";
			this->FoilsStatsPanel->Size = System::Drawing::Size(302, 156);
			this->FoilsStatsPanel->TabIndex = 300;
			// 
			// FoilsOpenLabel
			// 
			this->FoilsOpenLabel->AutoSize = true;
			this->FoilsOpenLabel->BackColor = System::Drawing::Color::Transparent;
			this->FoilsOpenLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FoilsOpenLabel->Location = System::Drawing::Point(5, 62);
			this->FoilsOpenLabel->Name = L"FoilsOpenLabel";
			this->FoilsOpenLabel->Size = System::Drawing::Size(82, 14);
			this->FoilsOpenLabel->TabIndex = 317;
			this->FoilsOpenLabel->Text = L"Foils Open:";
			// 
			// TopSpeedFoilsOpenLabel
			// 
			this->TopSpeedFoilsOpenLabel->AutoSize = true;
			this->TopSpeedFoilsOpenLabel->BackColor = System::Drawing::Color::Transparent;
			this->TopSpeedFoilsOpenLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TopSpeedFoilsOpenLabel->Location = System::Drawing::Point(5, 76);
			this->TopSpeedFoilsOpenLabel->Name = L"TopSpeedFoilsOpenLabel";
			this->TopSpeedFoilsOpenLabel->Size = System::Drawing::Size(121, 14);
			this->TopSpeedFoilsOpenLabel->TabIndex = 311;
			this->TopSpeedFoilsOpenLabel->Text = L"Actual Top Speed:";
			// 
			// BoostedTopSpeedFoilsOpenLabel
			// 
			this->BoostedTopSpeedFoilsOpenLabel->AutoSize = true;
			this->BoostedTopSpeedFoilsOpenLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoostedTopSpeedFoilsOpenLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoostedTopSpeedFoilsOpenLabel->Location = System::Drawing::Point(5, 90);
			this->BoostedTopSpeedFoilsOpenLabel->Name = L"BoostedTopSpeedFoilsOpenLabel";
			this->BoostedTopSpeedFoilsOpenLabel->Size = System::Drawing::Size(135, 14);
			this->BoostedTopSpeedFoilsOpenLabel->TabIndex = 312;
			this->BoostedTopSpeedFoilsOpenLabel->Text = L"Boosted Top Speed:";
			// 
			// OptimalTurnSpeedFoilsOpenLabel
			// 
			this->OptimalTurnSpeedFoilsOpenLabel->AutoSize = true;
			this->OptimalTurnSpeedFoilsOpenLabel->BackColor = System::Drawing::Color::Transparent;
			this->OptimalTurnSpeedFoilsOpenLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OptimalTurnSpeedFoilsOpenLabel->Location = System::Drawing::Point(5, 105);
			this->OptimalTurnSpeedFoilsOpenLabel->Name = L"OptimalTurnSpeedFoilsOpenLabel";
			this->OptimalTurnSpeedFoilsOpenLabel->Size = System::Drawing::Size(136, 14);
			this->OptimalTurnSpeedFoilsOpenLabel->TabIndex = 313;
			this->OptimalTurnSpeedFoilsOpenLabel->Text = L"Optimal Turn Speed:";
			// 
			// OptimalTurnSpeedFoilsOpenValueLabel
			// 
			this->OptimalTurnSpeedFoilsOpenValueLabel->AutoSize = true;
			this->OptimalTurnSpeedFoilsOpenValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->OptimalTurnSpeedFoilsOpenValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->OptimalTurnSpeedFoilsOpenValueLabel->Location = System::Drawing::Point(191, 105);
			this->OptimalTurnSpeedFoilsOpenValueLabel->Name = L"OptimalTurnSpeedFoilsOpenValueLabel";
			this->OptimalTurnSpeedFoilsOpenValueLabel->Size = System::Drawing::Size(71, 14);
			this->OptimalTurnSpeedFoilsOpenValueLabel->TabIndex = 316;
			this->OptimalTurnSpeedFoilsOpenValueLabel->Text = L"No Engine";
			// 
			// TopSpeedFoilsOpenValueLabel
			// 
			this->TopSpeedFoilsOpenValueLabel->AutoSize = true;
			this->TopSpeedFoilsOpenValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->TopSpeedFoilsOpenValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TopSpeedFoilsOpenValueLabel->Location = System::Drawing::Point(191, 76);
			this->TopSpeedFoilsOpenValueLabel->Name = L"TopSpeedFoilsOpenValueLabel";
			this->TopSpeedFoilsOpenValueLabel->Size = System::Drawing::Size(71, 14);
			this->TopSpeedFoilsOpenValueLabel->TabIndex = 314;
			this->TopSpeedFoilsOpenValueLabel->Text = L"No Engine";
			// 
			// BoostedTopSpeedFoilsOpenValueLabel
			// 
			this->BoostedTopSpeedFoilsOpenValueLabel->AutoSize = true;
			this->BoostedTopSpeedFoilsOpenValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoostedTopSpeedFoilsOpenValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->BoostedTopSpeedFoilsOpenValueLabel->Location = System::Drawing::Point(191, 90);
			this->BoostedTopSpeedFoilsOpenValueLabel->Name = L"BoostedTopSpeedFoilsOpenValueLabel";
			this->BoostedTopSpeedFoilsOpenValueLabel->Size = System::Drawing::Size(77, 14);
			this->BoostedTopSpeedFoilsOpenValueLabel->TabIndex = 315;
			this->BoostedTopSpeedFoilsOpenValueLabel->Text = L"No Booster";
			// 
			// FoilsClosedLabel
			// 
			this->FoilsClosedLabel->AutoSize = true;
			this->FoilsClosedLabel->BackColor = System::Drawing::Color::Transparent;
			this->FoilsClosedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FoilsClosedLabel->Location = System::Drawing::Point(5, 3);
			this->FoilsClosedLabel->Name = L"FoilsClosedLabel";
			this->FoilsClosedLabel->Size = System::Drawing::Size(91, 14);
			this->FoilsClosedLabel->TabIndex = 310;
			this->FoilsClosedLabel->Text = L"Foils Closed:";
			// 
			// TopSpeedFoilsClosedLabel
			// 
			this->TopSpeedFoilsClosedLabel->AutoSize = true;
			this->TopSpeedFoilsClosedLabel->BackColor = System::Drawing::Color::Transparent;
			this->TopSpeedFoilsClosedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TopSpeedFoilsClosedLabel->Location = System::Drawing::Point(5, 17);
			this->TopSpeedFoilsClosedLabel->Name = L"TopSpeedFoilsClosedLabel";
			this->TopSpeedFoilsClosedLabel->Size = System::Drawing::Size(121, 14);
			this->TopSpeedFoilsClosedLabel->TabIndex = 300;
			this->TopSpeedFoilsClosedLabel->Text = L"Actual Top Speed:";
			// 
			// BoostTimeFoilsLabel
			// 
			this->BoostTimeFoilsLabel->AutoSize = true;
			this->BoostTimeFoilsLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoostTimeFoilsLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoostTimeFoilsLabel->Location = System::Drawing::Point(5, 123);
			this->BoostTimeFoilsLabel->Name = L"BoostTimeFoilsLabel";
			this->BoostTimeFoilsLabel->Size = System::Drawing::Size(148, 14);
			this->BoostTimeFoilsLabel->TabIndex = 301;
			this->BoostTimeFoilsLabel->Text = L"Booster Burn Time (s):";
			// 
			// BoosterRechargeFoilsValueLabel
			// 
			this->BoosterRechargeFoilsValueLabel->AutoSize = true;
			this->BoosterRechargeFoilsValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterRechargeFoilsValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterRechargeFoilsValueLabel->Location = System::Drawing::Point(191, 137);
			this->BoosterRechargeFoilsValueLabel->Name = L"BoosterRechargeFoilsValueLabel";
			this->BoosterRechargeFoilsValueLabel->Size = System::Drawing::Size(77, 14);
			this->BoosterRechargeFoilsValueLabel->TabIndex = 309;
			this->BoosterRechargeFoilsValueLabel->Text = L"No Booster";
			// 
			// BoostedTopSpeedFoilsClosedLabel
			// 
			this->BoostedTopSpeedFoilsClosedLabel->AutoSize = true;
			this->BoostedTopSpeedFoilsClosedLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoostedTopSpeedFoilsClosedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoostedTopSpeedFoilsClosedLabel->Location = System::Drawing::Point(5, 31);
			this->BoostedTopSpeedFoilsClosedLabel->Name = L"BoostedTopSpeedFoilsClosedLabel";
			this->BoostedTopSpeedFoilsClosedLabel->Size = System::Drawing::Size(135, 14);
			this->BoostedTopSpeedFoilsClosedLabel->TabIndex = 302;
			this->BoostedTopSpeedFoilsClosedLabel->Text = L"Boosted Top Speed:";
			// 
			// BoosterRechargeFoilsLabel
			// 
			this->BoosterRechargeFoilsLabel->AutoSize = true;
			this->BoosterRechargeFoilsLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterRechargeFoilsLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterRechargeFoilsLabel->Location = System::Drawing::Point(5, 137);
			this->BoosterRechargeFoilsLabel->Name = L"BoosterRechargeFoilsLabel";
			this->BoosterRechargeFoilsLabel->Size = System::Drawing::Size(178, 14);
			this->BoosterRechargeFoilsLabel->TabIndex = 308;
			this->BoosterRechargeFoilsLabel->Text = L"Booster Recharge Time (s):";
			// 
			// OptimalTurnSpeedFoilsClosedLabel
			// 
			this->OptimalTurnSpeedFoilsClosedLabel->AutoSize = true;
			this->OptimalTurnSpeedFoilsClosedLabel->BackColor = System::Drawing::Color::Transparent;
			this->OptimalTurnSpeedFoilsClosedLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OptimalTurnSpeedFoilsClosedLabel->Location = System::Drawing::Point(5, 46);
			this->OptimalTurnSpeedFoilsClosedLabel->Name = L"OptimalTurnSpeedFoilsClosedLabel";
			this->OptimalTurnSpeedFoilsClosedLabel->Size = System::Drawing::Size(136, 14);
			this->OptimalTurnSpeedFoilsClosedLabel->TabIndex = 303;
			this->OptimalTurnSpeedFoilsClosedLabel->Text = L"Optimal Turn Speed:";
			// 
			// OptimalTurnSpeedFoilsClosedValueLabel
			// 
			this->OptimalTurnSpeedFoilsClosedValueLabel->AutoSize = true;
			this->OptimalTurnSpeedFoilsClosedValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->OptimalTurnSpeedFoilsClosedValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->OptimalTurnSpeedFoilsClosedValueLabel->Location = System::Drawing::Point(191, 46);
			this->OptimalTurnSpeedFoilsClosedValueLabel->Name = L"OptimalTurnSpeedFoilsClosedValueLabel";
			this->OptimalTurnSpeedFoilsClosedValueLabel->Size = System::Drawing::Size(71, 14);
			this->OptimalTurnSpeedFoilsClosedValueLabel->TabIndex = 307;
			this->OptimalTurnSpeedFoilsClosedValueLabel->Text = L"No Engine";
			// 
			// TopSpeedFoilsClosedValueLabel
			// 
			this->TopSpeedFoilsClosedValueLabel->AutoSize = true;
			this->TopSpeedFoilsClosedValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->TopSpeedFoilsClosedValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TopSpeedFoilsClosedValueLabel->Location = System::Drawing::Point(191, 17);
			this->TopSpeedFoilsClosedValueLabel->Name = L"TopSpeedFoilsClosedValueLabel";
			this->TopSpeedFoilsClosedValueLabel->Size = System::Drawing::Size(71, 14);
			this->TopSpeedFoilsClosedValueLabel->TabIndex = 304;
			this->TopSpeedFoilsClosedValueLabel->Text = L"No Engine";
			// 
			// BoostedTopSpeedFoilsClosedValueLabel
			// 
			this->BoostedTopSpeedFoilsClosedValueLabel->AutoSize = true;
			this->BoostedTopSpeedFoilsClosedValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoostedTopSpeedFoilsClosedValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->BoostedTopSpeedFoilsClosedValueLabel->Location = System::Drawing::Point(191, 31);
			this->BoostedTopSpeedFoilsClosedValueLabel->Name = L"BoostedTopSpeedFoilsClosedValueLabel";
			this->BoostedTopSpeedFoilsClosedValueLabel->Size = System::Drawing::Size(77, 14);
			this->BoostedTopSpeedFoilsClosedValueLabel->TabIndex = 306;
			this->BoostedTopSpeedFoilsClosedValueLabel->Text = L"No Booster";
			// 
			// BoostTimeFoilsValueLabel
			// 
			this->BoostTimeFoilsValueLabel->AutoSize = true;
			this->BoostTimeFoilsValueLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoostTimeFoilsValueLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoostTimeFoilsValueLabel->Location = System::Drawing::Point(191, 123);
			this->BoostTimeFoilsValueLabel->Name = L"BoostTimeFoilsValueLabel";
			this->BoostTimeFoilsValueLabel->Size = System::Drawing::Size(77, 14);
			this->BoostTimeFoilsValueLabel->TabIndex = 305;
			this->BoostTimeFoilsValueLabel->Text = L"No Booster";
			// 
			// PropulsionStatsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->ClientSize = System::Drawing::Size(313, 360);
			this->Controls->Add(this->YPRPanel);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->PropulsionStatsFormLabel);
			this->Controls->Add(this->FoilsStatsPanel);
			this->Controls->Add(this->StatsPanel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PropulsionStatsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Propulsion Statistics";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PropulsionStatsForm::PropulsionStatsForm_FormClosing);
			this->YPRPanel->ResumeLayout(false);
			this->YPRPanel->PerformLayout();
			this->StatsPanel->ResumeLayout(false);
			this->StatsPanel->PerformLayout();
			this->FoilsStatsPanel->ResumeLayout(false);
			this->FoilsStatsPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		/// 
		/// Globals
		///
		static double optimalTurnSpeedMod = 1.00;
		static double speedMod = 0;
		static double speedModFoilsClosed = 0;
		static double speedModFoilsOpen = 0;

private: System::Void CalculateOptimalTurnSpeed(){
			 if (speedMod != 0)
			 {
				OptimalTurnSpeedValueLabel->Text = String::Concat((Convert::ToDouble(TopSpeedValueLabel->Text->ToString()) * optimalTurnSpeedMod).ToString(".##"), " (", (optimalTurnSpeedMod * 100).ToString("G"), "%)");
			 }
			 else
			 {
				 OptimalTurnSpeedFoilsClosedValueLabel->Text = String::Concat((Convert::ToDouble(TopSpeedFoilsClosedValueLabel->Text->ToString()) * optimalTurnSpeedMod).ToString(".##"), " (", (optimalTurnSpeedMod * 100).ToString("G"), "%)");
				 OptimalTurnSpeedFoilsOpenValueLabel->Text = String::Concat((Convert::ToDouble(TopSpeedFoilsOpenValueLabel->Text->ToString()) * optimalTurnSpeedMod).ToString(".##"), " (", (optimalTurnSpeedMod * 100).ToString("G"), "%)");
			 }
		 }
private: System::Void CalculateEngineStats(Engine^ loadedEngine, int selectedEngineOverload){
			 double loadedEnginePitch;
			 double loadedEngineYaw;
			 double loadedEngineRoll;
			 double loadedEngineSpeed;
			 double actualTopSpeed;

			 System::Data::DataRow^ rowEngine;

			 Engine^ tempEngine = gcnew Engine();
			 tempEngine = loadedEngine;

			 rowEngine = tempEngine[0];

			 loadedEnginePitch = Convert::ToDouble(rowEngine["Pitch"]->ToString());
			 loadedEngineYaw = Convert::ToDouble(rowEngine["Yaw"]->ToString());
			 loadedEngineRoll = Convert::ToDouble(rowEngine["Roll"]->ToString());
			 loadedEngineSpeed = Convert::ToDouble(rowEngine["Top Speed"]->ToString());

			 actualTopSpeed = loadedEngineSpeed * 10;

			switch (selectedEngineOverload)
			{
			case 0: PitchValueLabel->Text = (loadedEnginePitch * 1).ToString(".##");
					YawValueLabel->Text = (loadedEngineYaw * 1).ToString(".##");
					RollValueLabel->Text = (loadedEngineRoll * 1).ToString(".##");
					if (speedMod != 0)
					{
						TopSpeedValueLabel->Text = ((actualTopSpeed * 1) * speedMod).ToString(".##");
					}
					else
					{
						TopSpeedFoilsClosedValueLabel->Text = ((actualTopSpeed * 1) * speedModFoilsClosed).ToString(".##");
						TopSpeedFoilsOpenValueLabel->Text = ((actualTopSpeed * 1) * speedModFoilsOpen).ToString(".##");
					}
				break;
			case 1: PitchValueLabel->Text = (loadedEnginePitch * 1.1).ToString(".##");
					YawValueLabel->Text = (loadedEngineYaw * 1.1).ToString(".##");
					RollValueLabel->Text = (loadedEngineRoll * 1.1).ToString(".##");
					if (speedMod != 0)
					{
						TopSpeedValueLabel->Text = ((actualTopSpeed * 1.1) * speedMod).ToString(".##");
					}
					else
					{
						TopSpeedFoilsClosedValueLabel->Text = ((actualTopSpeed * 1.1) * speedModFoilsClosed).ToString(".##");
						TopSpeedFoilsOpenValueLabel->Text = ((actualTopSpeed * 1.1) * speedModFoilsOpen).ToString(".##");
					}
				break;
			case 2: PitchValueLabel->Text = (loadedEnginePitch * 1.2).ToString(".##");
					YawValueLabel->Text = (loadedEngineYaw * 1.2).ToString(".##");
					RollValueLabel->Text = (loadedEngineRoll * 1.2).ToString(".##");
					if (speedMod != 0)
					{
						TopSpeedValueLabel->Text = ((actualTopSpeed * 1.2) * speedMod).ToString(".##");
					}
					else
					{
						TopSpeedFoilsClosedValueLabel->Text = ((actualTopSpeed * 1.2) * speedModFoilsClosed).ToString(".##");
						TopSpeedFoilsOpenValueLabel->Text = ((actualTopSpeed * 1.2) * speedModFoilsOpen).ToString(".##");
					}
				break;
			case 3: PitchValueLabel->Text = (loadedEnginePitch * 1.3).ToString(".##");
					YawValueLabel->Text = (loadedEngineYaw * 1.3).ToString(".##");
					RollValueLabel->Text = (loadedEngineRoll * 1.3).ToString(".##");
					if (speedMod != 0)
					{
						TopSpeedValueLabel->Text = ((actualTopSpeed * 1.3) * speedMod).ToString(".##");
					}
					else
					{
						TopSpeedFoilsClosedValueLabel->Text = ((actualTopSpeed * 1.3) * speedModFoilsClosed).ToString(".##");
						TopSpeedFoilsOpenValueLabel->Text = ((actualTopSpeed * 1.3) * speedModFoilsOpen).ToString(".##");
					}
				break;
			case 4: PitchValueLabel->Text = (loadedEnginePitch * 1.4).ToString(".##");
					YawValueLabel->Text = (loadedEngineYaw * 1.4).ToString(".##");
					RollValueLabel->Text = (loadedEngineRoll * 1.4).ToString(".##");
					if (speedMod != 0)
					{
						TopSpeedValueLabel->Text = ((actualTopSpeed * 1.4) * speedMod).ToString(".##");
					}
					else
					{
						TopSpeedFoilsClosedValueLabel->Text = ((actualTopSpeed * 1.4) * speedModFoilsClosed).ToString(".##");
						TopSpeedFoilsOpenValueLabel->Text = ((actualTopSpeed * 1.4) * speedModFoilsOpen).ToString(".##");
					}
				break;
			}
		 }
private: System::Void CalculateBoosterValues(Booster^ loadedBooster, int selectedEngineOverload){
			 double loadedBoosterEnergy;
			 double loadedBoosterRecharge;
			 double loadedBoosterConsumption;
			 double loadedBoosterAcceleration;
			 double loadedBoosterSpeed;
			 double actualBoosterSpeed;
			 double boosterBurnTime;
			 double boostedTopSpeed;
			 double boostedTopSpeedFoilsClosed;
			 double boostedTopSpeedFoilsOpen;
			 double boosterReachargeTime;

			 System::Data::DataRow^ rowBooster;

			 Booster^ tempBooster = gcnew Booster();
			 tempBooster = loadedBooster;

			 rowBooster = tempBooster[0];

			 loadedBoosterEnergy = Convert::ToDouble(rowBooster["Energy"]->ToString());
			 loadedBoosterRecharge = Convert::ToDouble(rowBooster["Recharge"]->ToString());
			 loadedBoosterConsumption = Convert::ToDouble(rowBooster["Consumption"]->ToString());
			 loadedBoosterAcceleration = Convert::ToDouble(rowBooster["Acceleration"]->ToString());
			 loadedBoosterSpeed = Convert::ToDouble(rowBooster["Top Speed"]->ToString());

			 actualBoosterSpeed = loadedBoosterSpeed * 10;
			 boosterBurnTime = (loadedBoosterEnergy / loadedBoosterConsumption);
			 boosterReachargeTime = (loadedBoosterEnergy / loadedBoosterRecharge);
			 if (speedMod != 0)
			 {
				 boostedTopSpeed = (Convert::ToDouble(TopSpeedValueLabel->Text->ToString()) + actualBoosterSpeed);
				 BoostedTopSpeedValueLabel->Text = boostedTopSpeed.ToString(".##");

				 BoostTimeValueLabel->Text = boosterBurnTime.ToString(".##");
				 BoosterRechargeTimeValueLabel->Text = boosterReachargeTime.ToString(".##");
			 }
			 else
			 {
				 boostedTopSpeedFoilsClosed = (Convert::ToDouble(TopSpeedFoilsClosedValueLabel->Text->ToString()) + actualBoosterSpeed);
				 boostedTopSpeedFoilsOpen = (Convert::ToDouble(TopSpeedFoilsOpenValueLabel->Text->ToString()) + actualBoosterSpeed);

				 BoostedTopSpeedFoilsClosedValueLabel->Text = boostedTopSpeedFoilsClosed.ToString(".##");
				 BoostedTopSpeedFoilsOpenValueLabel->Text = boostedTopSpeedFoilsOpen.ToString(".##");

				 BoostTimeFoilsValueLabel->Text = boosterBurnTime.ToString(".##");
				 BoosterRechargeFoilsValueLabel->Text = boosterReachargeTime.ToString(".##");
			 }
		 }
private: System::Void CalculateChassisMods(int selectedChassis){
			 switch (selectedChassis) 
			 {
			 /// Z-95
			 case 3:			PitchChassisLabel->Text = "600";
								YawChassisLabel->Text = "600";
								RollChassisLabel->Text = "300";
								speedMod = 0.95;
								optimalTurnSpeedMod = 0.75;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;
							
			 /// Heavy Z-95				 
			 case 4:			PitchChassisLabel->Text = "600";
								YawChassisLabel->Text = "600";
								RollChassisLabel->Text = "300";
								speedMod = 0.95;
								optimalTurnSpeedMod = 0.75;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;
							
			 /// Y-wing
			 case 5:			PitchChassisLabel->Text = "80";
								YawChassisLabel->Text = "80";
								RollChassisLabel->Text = "40";
								speedMod = 0.85;
								optimalTurnSpeedMod = 0.35;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;
						   
			 /// Y-wing LP
			 case 6:			PitchChassisLabel->Text = "70";
								YawChassisLabel->Text = "70";
								RollChassisLabel->Text = "35";
								speedMod = 0.85;
								optimalTurnSpeedMod = 0.35;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;
							  
			 /// X-wing
			 case 7:			PitchChassisLabel->Text = "300";
								YawChassisLabel->Text = "200";
								RollChassisLabel->Text = "150";
								speedMod = 0;
								speedModFoilsClosed = 0.95;
								speedModFoilsOpen = 0.90;
								optimalTurnSpeedMod = 0.45;

								StatsPanel->Hide();
								FoilsStatsPanel->Show();
								break;
						   
			 /// Adv. X-wing
			 case 8:			PitchChassisLabel->Text = "300";
								YawChassisLabel->Text = "200";
								RollChassisLabel->Text = "150";
								speedMod = 0;
								speedModFoilsClosed = 0.95;
								speedModFoilsOpen = 0.90;
								optimalTurnSpeedMod = 0.45;

								StatsPanel->Hide();
								FoilsStatsPanel->Show();
								break;
								
			 /// A-wing
			 case 9:			PitchChassisLabel->Text = "250";
								YawChassisLabel->Text = "250";
								RollChassisLabel->Text = "125";
								speedMod = 1.00;
								optimalTurnSpeedMod = 0.85;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;
						   
			 /// B-wing
			 case 10:			PitchChassisLabel->Text = "35";
								YawChassisLabel->Text = "35";
								RollChassisLabel->Text = "17";
								speedMod = 0;
								speedModFoilsClosed = 0.85;
								speedModFoilsOpen = 0.80;
								optimalTurnSpeedMod = 0.30;

								StatsPanel->Hide();
								FoilsStatsPanel->Show();
								break;
						   
			 /// Nova
			 case 11:			PitchChassisLabel->Text = "50";
								YawChassisLabel->Text = "50";
								RollChassisLabel->Text = "40";
								speedMod = 0.80;
								optimalTurnSpeedMod = 0.35;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Tie LD
			 case 15:			PitchChassisLabel->Text = "600";
								YawChassisLabel->Text = "600";
								RollChassisLabel->Text = "300";
								speedMod = 0.95;
								optimalTurnSpeedMod = 0.75;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Heavy Tie
			 case 16:			PitchChassisLabel->Text = "500";
								YawChassisLabel->Text = "500";
								RollChassisLabel->Text = "250";
								speedMod = 0.98;
								optimalTurnSpeedMod = 0.60;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Tie Fighter
			 case 17:			PitchChassisLabel->Text = "500";
								YawChassisLabel->Text = "500";
								RollChassisLabel->Text = "250";
								speedMod = 0.98;
								optimalTurnSpeedMod = 0.60;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Tie/IN
			 case 18:			PitchChassisLabel->Text = "400";
								YawChassisLabel->Text = "400";
								RollChassisLabel->Text = "200";
								speedMod = 0.97;
								optimalTurnSpeedMod = 0.60;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Tie Bomber
			 case 19:			PitchChassisLabel->Text = "50";
								YawChassisLabel->Text = "50";
								RollChassisLabel->Text = "25";
								speedMod = 0.85;
								optimalTurnSpeedMod = 0.35;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Tie Inter.
			 case 20:			PitchChassisLabel->Text = "300";
								YawChassisLabel->Text = "300";
								RollChassisLabel->Text = "150";
								speedMod = 1.00;
								optimalTurnSpeedMod = 0.85;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Tie Adv.
			 case 21:			PitchChassisLabel->Text = "300";
								YawChassisLabel->Text = "300";
								RollChassisLabel->Text = "150";
								speedMod = 1.00;
								optimalTurnSpeedMod = 0.85;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Tie Aggres.
			 case 22:			PitchChassisLabel->Text = "200";
								YawChassisLabel->Text = "150";
								RollChassisLabel->Text = "100";
								speedMod = 0.95;
								optimalTurnSpeedMod = 0.45;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// RGI
			 case 23:			PitchChassisLabel->Text = "300";
								YawChassisLabel->Text = "300";
								RollChassisLabel->Text = "150";
								speedMod = 1.00;
								optimalTurnSpeedMod = 0.85;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Tie Opp.
			 case 24:			PitchChassisLabel->Text = "100";
								YawChassisLabel->Text = "100";
								RollChassisLabel->Text = "50";
								speedMod = 0.90;
								optimalTurnSpeedMod = 0.40;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Decimator
			 case 25:			PitchChassisLabel->Text = "50";
								YawChassisLabel->Text = "50";
								RollChassisLabel->Text = "40";
								speedMod = 0.80;
								optimalTurnSpeedMod = 0.35;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Syck
			 case 29:			PitchChassisLabel->Text = "600";
								YawChassisLabel->Text = "600";
								RollChassisLabel->Text = "300";
								speedMod = 0.95;
								optimalTurnSpeedMod = 0.75;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Heavy Syck
			 case 30:			PitchChassisLabel->Text = "600";
								YawChassisLabel->Text = "600";
								RollChassisLabel->Text = "300";
								speedMod = 0.95;
								optimalTurnSpeedMod = 0.75;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Dunelizard
			 case 31:			PitchChassisLabel->Text = "300";
								YawChassisLabel->Text = "300";
								RollChassisLabel->Text = "150";
								speedMod = 0.95;
								optimalTurnSpeedMod = 0.45;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Kihraxz
			 case 32:			PitchChassisLabel->Text = "400";
								YawChassisLabel->Text = "400";
								RollChassisLabel->Text = "200";
								speedMod = 1.00;
								optimalTurnSpeedMod = 0.60;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// M12L Kimo
			 case 33:			PitchChassisLabel->Text = "100";
								YawChassisLabel->Text = "100";
								RollChassisLabel->Text = "50";
								speedMod = 0.92;
								optimalTurnSpeedMod = 0.45;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Ixiyen
			 case 34:			PitchChassisLabel->Text = "200";
								YawChassisLabel->Text = "200";
								RollChassisLabel->Text = "100";
								speedMod = 0.95;
								optimalTurnSpeedMod = 0.45;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Rihkxyrk
			 case 35:			PitchChassisLabel->Text = "100";
								YawChassisLabel->Text = "100";
								RollChassisLabel->Text = "50";
								speedMod = 0.89;
								optimalTurnSpeedMod = 0.40;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

		 	 /// Vaksai
			 case 36:			PitchChassisLabel->Text = "400";
								YawChassisLabel->Text = "400";
								RollChassisLabel->Text = "200";
								speedMod = 1.00;
								optimalTurnSpeedMod = 0.60;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// M22-T Kyrat
			 case 37:			PitchChassisLabel->Text = "100";
								YawChassisLabel->Text = "100";
								RollChassisLabel->Text = "50";
								speedMod = 0.92;
								optimalTurnSpeedMod = 0.45;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// YT-1300
			 case 38:			PitchChassisLabel->Text = "50";
								YawChassisLabel->Text = "50";
								RollChassisLabel->Text = "40";
								speedMod = 0.80;
								optimalTurnSpeedMod = 0.35;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// ARC-170
			 case 42:			PitchChassisLabel->Text = "400";
								YawChassisLabel->Text = "400";
								RollChassisLabel->Text = "200";
								speedMod = 0.97;
								optimalTurnSpeedMod = 0.60;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// JSF
			 case 43:			PitchChassisLabel->Text = "400";
								YawChassisLabel->Text = "400";
								RollChassisLabel->Text = "200";
								speedMod = 0.95;
								optimalTurnSpeedMod = 0.60;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// B22
			 case 44:			PitchChassisLabel->Text = "400";
								YawChassisLabel->Text = "400";
								RollChassisLabel->Text = "200";
								speedMod = 0.95;
								optimalTurnSpeedMod = 0.60;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// Firespray
			 case 45:			PitchChassisLabel->Text = "100";
								YawChassisLabel->Text = "100";
								RollChassisLabel->Text = "50";
								speedMod = 0.90;
								optimalTurnSpeedMod = 0.45;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;

			 /// YT-2400
			 case 46:			PitchChassisLabel->Text = "50";
								YawChassisLabel->Text = "50";
								RollChassisLabel->Text = "40";
								speedMod = 0.80;
								optimalTurnSpeedMod = 0.35;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();
								break;
								
			 default:			PitchChassisLabel->Text = "Invalid Chassis Selected";
								YawChassisLabel->Text = "Invalid Chassis Selected";
								RollChassisLabel->Text = "Invalid Chassis Selected";
								speedMod = 0.00;
								optimalTurnSpeedMod = 0.00;

								StatsPanel->Show();
								FoilsStatsPanel->Hide();

								if (MessageBox::Show("Error: That is not a valid Ship Chassis.", "Invalid Chassis Selection", 
								MessageBoxButtons::OK, MessageBoxIcon::Error) == 
								System::Windows::Forms::DialogResult::OK){
									break;
								}
			 }
		 }
private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void PropulsionStatsForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		 }
};
}
