#pragma once
#include "ReactorForm.h"
#include "BoosterForm.h"
#include "CapacitorForm.h"
#include "ChaffForm.h"
#include "DroidForm.h"
#include "EngineForm.h"
#include "ArmorForm.h"
#include "OrdinanceForm.h"
#include "WeaponForm.h"
#include "SheildForm.h"
#include "CompNamePrompt.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace CompLib;


namespace ShipLoadouts {

	/// <summary>
	/// Summary for ComponentManagementForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ComponentManagementForm : public System::Windows::Forms::Form
	{
	private:
		List<Reactor^>^ m_ReactorList;
		List<Engine^>^ m_EngineList;
		List<Booster^>^ m_BoosterList;
		List<Sheild^>^ m_SheildList;
		List<Armor^>^ m_ArmorList;
		List<Droid^>^ m_DroidList;
		List<Capacitor^>^ m_CapacitorList;
		List<Weapon^>^ m_WeaponList;
		List<Ordinance^>^ m_OrdinanceList;
		List<Chaff^>^ m_ChaffList;

		List<String^>^ m_ReactorNameList;
		List<String^>^ m_EngineNameList;
		List<String^>^ m_BoosterNameList;
		List<String^>^ m_SheildNameList;
		List<String^>^ m_ArmorNameList;
		List<String^>^ m_DroidNameList;
		List<String^>^ m_CapacitorNameList;
		List<String^>^ m_WeaponNameList;
		List<String^>^ m_OrdinanceNameList;
		List<String^>^ m_ChaffNameList;
	public:
		ComponentManagementForm(void)
		{
			InitializeComponent();
			UpdateGUI();
			//
			//TODO: Add the constructor code here
			//
		}

		ComponentManagementForm(String^ tempCurrentDir)
		{
			InitializeComponent();
			UpdateGUI();
		}

		ComponentManagementForm(List<Reactor^>^ tempReactorList, List<Engine^>^ tempEngineList, List<Booster^>^ tempBoosterList,
			List<Sheild^>^ tempSheildList, List<Armor^>^ tempArmorList, List<Droid^>^ tempDroidList, List<Capacitor^>^ tempCapacitorList,
			List<Weapon^>^ tempWeaponList, List<Ordinance^>^ tempOrdinanceList, List<Chaff^>^ tempChaffList, List<String^>^ tempReactorNameList,
			List<String^>^ tempEngineNameList, List<String^>^ tempBoosterNameList, List<String^>^ tempSheildNameList, List<String^>^ tempArmorNameList,
			List<String^>^ tempDroidNameList, List<String^>^ tempCapacitorNameList, List<String^>^ tempWeaponNameList, List<String^>^ tempOrdinanceNameList,
			List<String^>^ tempChaffNameList, String^ selectedReactor, String^ selectedEngine, String^ selectedBooster, String^ selectedSheild, 
			 String^ selectedFArmor, String^ selectedRArmor, String^ selectedDroid, String^ selectedCapacitor, String^ selectedOrdinance1, 
			 String^ selectedOrdinance2, String^ selectedOrdinance3, String^ selectedWeapon1, String^ selectedWeapon2, String^ selectedWeapon3, 
			 String^ selectedWeapon4, String^ selectedChaff, String^ tempCurrentDir)
		{
			InitializeComponent();

			CMappdir = tempCurrentDir;

			CMReactorList = tempReactorList;
			CMEngineList = tempEngineList;
			CMBoosterList = tempBoosterList;
			CMSheildList = tempSheildList;
			CMArmorList = tempArmorList;
			CMDroidList = tempDroidList;
			CMCapacitorList = tempCapacitorList;
			CMWeaponList = tempWeaponList;
			CMOrdinanceList = tempOrdinanceList;
			CMChaffList = tempChaffList;

			CMReactorNameList = tempReactorNameList;
			CMEngineNameList = tempEngineNameList;
			CMBoosterNameList = tempBoosterNameList;
			CMSheildNameList = tempSheildNameList;
			CMArmorNameList = tempArmorNameList;
			CMDroidNameList = tempDroidNameList;
			CMCapacitorNameList = tempCapacitorNameList;
			CMWeaponNameList = tempWeaponNameList;
			CMOrdinanceNameList = tempOrdinanceNameList;
			CMChaffNameList = tempChaffNameList;

			loadedReactor = selectedReactor;
			loadedEngine = selectedEngine;
			loadedBooster = selectedBooster;
			loadedSheild = selectedSheild;
			loadedFArmor = selectedFArmor;
			loadedRArmor = selectedRArmor;
			loadedDroid = selectedDroid;
			loadedCapacitor = selectedCapacitor;
			loadedOrdinance1 = selectedOrdinance1;
			loadedOrdinance2 = selectedOrdinance2;
			loadedOrdinance3 = selectedOrdinance3;
			loadedWeapon1 = selectedWeapon1;
			loadedWeapon2 = selectedWeapon2;
			loadedWeapon3 = selectedWeapon3;
			loadedWeapon4 = selectedWeapon4;
			loadedChaff = selectedChaff;

			UpdateGUI();
			UpdateSelection();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ComponentManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Form Item Declerations
	private: System::Windows::Forms::Label^  ComponentsLabel;
	private: System::Windows::Forms::Button^  CloseButton;		 
	private: System::Windows::Forms::Panel^  CompManagementPanel;
	private: System::Windows::Forms::Button^  DeleteChaffButton;
	private: System::Windows::Forms::Button^  DeleteOrdinanceButton;
	private: System::Windows::Forms::Button^  DeleteWeaponButton;
	private: System::Windows::Forms::Button^  DeleteCapacitorButton;
	private: System::Windows::Forms::Button^  DeleteDroidButton;
	private: System::Windows::Forms::Button^  DeleteArmorButton;
	private: System::Windows::Forms::Button^  DeleteSheildButton;
	private: System::Windows::Forms::Button^  DeleteBoosterButton;
	private: System::Windows::Forms::Button^  DeleteEngineButton;
	private: System::Windows::Forms::Button^  DeleteReactorButton;
	private: System::Windows::Forms::Button^  AddCountermeasuresButton;
	private: System::Windows::Forms::Button^  EditCountermeasuresButton;
	private: System::Windows::Forms::Button^  EditReactorButton;
	private: System::Windows::Forms::Button^  AddEngineButton;
	private: System::Windows::Forms::Button^  EditEngineButton;
	private: System::Windows::Forms::Button^  AddBoosterButton;
	private: System::Windows::Forms::Button^  EditBoosterButton;
	private: System::Windows::Forms::Button^  AddSheildButton;
	private: System::Windows::Forms::Button^  EditSheildButton;
	private: System::Windows::Forms::Button^  AddArmorButton;
	private: System::Windows::Forms::Button^  EditArmorButton;
	private: System::Windows::Forms::Button^  AddDroidButton;
	private: System::Windows::Forms::Button^  EditDroidButton;
	private: System::Windows::Forms::Button^  AddCapacitorButton;
	private: System::Windows::Forms::Button^  EditCapacitorButton;
	private: System::Windows::Forms::Button^  AddOrdinanceButton;
	private: System::Windows::Forms::Button^  EditOrdinanceButton;
	private: System::Windows::Forms::Button^  AddWeaponButton;
	private: System::Windows::Forms::Button^  EditWeaponButton;
	private: System::Windows::Forms::Button^  AddReactorButton;
	private: System::Windows::Forms::ComboBox^  CountermeasuresComboBox;
	private: System::Windows::Forms::ComboBox^  WeaponComboBox;
	private: System::Windows::Forms::Label^  CountermeasuresCompLabel;
	private: System::Windows::Forms::Label^  WeaponCompLabel;
	private: System::Windows::Forms::ComboBox^  DroidComboBox;
	private: System::Windows::Forms::ComboBox^  CapacitorComboBox;
	private: System::Windows::Forms::ComboBox^  OrdinanceComboBox;
	private: System::Windows::Forms::Label^  OrdinanaceCompLabel;
	private: System::Windows::Forms::Label^  CapacitorCompLabel;
	private: System::Windows::Forms::Label^  DroidCompLabel;
	private: System::Windows::Forms::ComboBox^  EngineComboBox;
	private: System::Windows::Forms::ComboBox^  BoosterComboBox;
	private: System::Windows::Forms::ComboBox^  SheildComboBox;
	private: System::Windows::Forms::ComboBox^  ArmorComboBox;
	private: System::Windows::Forms::ComboBox^  ReactorComboBox;
	private: System::Windows::Forms::Label^  ArmorCompLabel;
	private: System::Windows::Forms::Label^  SheildCompLabel;
	private: System::Windows::Forms::Label^  BoosterCompLabel;
	private: System::Windows::Forms::Label^  EngineCompLabel;
	private: System::Windows::Forms::Label^  ReactorCompLabel;

#pragma endregion

	public:
		property List<Reactor^>^ ReactorData
		{
			List<Reactor^>^ get() { return m_ReactorList; }
			void set (List<Reactor^>^ value) { m_ReactorList = value; }
		}
		property List<String^>^ ReactorNameData
		{
			List<String^>^ get() { return m_ReactorNameList; }
			void set (List<String^>^ value) { m_ReactorNameList = value; }
		}

		property List<Engine^>^ EngineData
		{
			List<Engine^>^ get() { return m_EngineList; }
			void set (List<Engine^>^ value) { m_EngineList = value; }
		}
		property List<String^>^ EngineNameData
		{
			List<String^>^ get() { return m_EngineNameList; }
			void set (List<String^>^ value) { m_EngineNameList = value; }
		}

		property List<Booster^>^ BoosterData
		{
			List<Booster^>^ get() { return m_BoosterList; }
			void set (List<Booster^>^ value) { m_BoosterList = value; }
		}
		property List<String^>^ BoosterNameData
		{
			List<String^>^ get() { return m_BoosterNameList; }
			void set (List<String^>^ value) { m_BoosterNameList = value; }
		}

		property List<Sheild^>^ SheildData
		{
			List<Sheild^>^ get() { return m_SheildList; }
			void set (List<Sheild^>^ value) { m_SheildList = value; }
		}
		property List<String^>^ SheildNameData
		{
			List<String^>^ get() { return m_SheildNameList; }
			void set (List<String^>^ value) { m_SheildNameList = value; }
		}

		property List<Armor^>^ ArmorData
		{
			List<Armor^>^ get() { return m_ArmorList; }
			void set (List<Armor^>^ value) { m_ArmorList = value; }
		}
		property List<String^>^ ArmorNameData
		{
			List<String^>^ get() { return m_ArmorNameList; }
			void set (List<String^>^ value) { m_ArmorNameList = value; }
		}

		property List<Droid^>^ DroidData
		{
			List<Droid^>^ get() { return m_DroidList; }
			void set (List<Droid^>^ value) { m_DroidList = value; }
		}
		property List<String^>^ DroidNameData
		{
			List<String^>^ get() { return m_DroidNameList; }
			void set (List<String^>^ value) { m_DroidNameList = value; }
		}

		property List<Capacitor^>^ CapacitorData
		{
			List<Capacitor^>^ get() { return m_CapacitorList; }
			void set (List<Capacitor^>^ value) { m_CapacitorList = value; }
		}
		property List<String^>^ CapacitorNameData
		{
			List<String^>^ get() { return m_CapacitorNameList; }
			void set (List<String^>^ value) { m_CapacitorNameList = value; }
		}

		property List<Weapon^>^ WeaponData
		{
			List<Weapon^>^ get() { return m_WeaponList; }
			void set (List<Weapon^>^ value) { m_WeaponList = value; }
		}
		property List<String^>^ WeaponNameData
		{
			List<String^>^ get() { return m_WeaponNameList; }
			void set (List<String^>^ value) { m_WeaponNameList = value; }
		}

		property List<Ordinance^>^ OrdinanceData
		{
			List<Ordinance^>^ get() { return m_OrdinanceList; }
			void set (List<Ordinance^>^ value) { m_OrdinanceList = value; }
		}
		property List<String^>^ OrdinanceNameData
		{
			List<String^>^ get() { return m_OrdinanceNameList; }
			void set (List<String^>^ value) { m_OrdinanceNameList = value; }
		}

		property List<Chaff^>^ ChaffData
		{
			List<Chaff^>^ get() { return m_ChaffList; }
			void set (List<Chaff^>^ value) { m_ChaffList = value; }
		}
		property List<String^>^ ChaffNameData
		{
			List<String^>^ get() { return m_ChaffNameList; }
			void set (List<String^>^ value) { m_ChaffNameList = value; }
		}
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Globals

		/// Create a list of each component type.
		static List<CompLib::Armor^>^ CMArmorList = gcnew List<CompLib::Armor^>();
		static List<CompLib::Booster^>^ CMBoosterList = gcnew List<CompLib::Booster^>();
		static List<CompLib::Chaff^>^ CMChaffList = gcnew List<CompLib::Chaff^>();
		static List<CompLib::Capacitor^>^ CMCapacitorList = gcnew List<CompLib::Capacitor^>();
		static List<CompLib::Droid^>^ CMDroidList = gcnew List<CompLib::Droid^>();
		static List<CompLib::Engine^>^ CMEngineList = gcnew List<CompLib::Engine^>();
		static List<CompLib::Ordinance^>^ CMOrdinanceList = gcnew List<CompLib::Ordinance^>();
		static List<CompLib::Reactor^>^ CMReactorList = gcnew List<CompLib::Reactor^>();
		static List<CompLib::Sheild^>^ CMSheildList = gcnew List<CompLib::Sheild^>();
		static List<CompLib::Weapon^>^ CMWeaponList = gcnew List<CompLib::Weapon^>();

		/// Create a list of each component type name.
		static List<String^>^ CMArmorNameList = gcnew List<String^>();
		static List<String^>^ CMBoosterNameList = gcnew List<String^>();
		static List<String^>^ CMChaffNameList = gcnew List<String^>();
		static List<String^>^ CMCapacitorNameList = gcnew List<String^>();
		static List<String^>^ CMDroidNameList = gcnew List<String^>();
		static List<String^>^ CMEngineNameList = gcnew List<String^>();
		static List<String^>^ CMOrdinanceNameList = gcnew List<String^>();
		static List<String^>^ CMReactorNameList = gcnew List<String^>();
		static List<String^>^ CMSheildNameList = gcnew List<String^>();
		static List<String^>^ CMWeaponNameList = gcnew List<String^>();

		//static bool changesMade = false;

		static String^ loadedReactor = "";
		static String^ loadedEngine = "";
		static String^ loadedBooster = "";
		static String^ loadedSheild = "";
		static String^ loadedFArmor = "";
		static String^ loadedRArmor = "";
		static String^ loadedDroid = "";
		static String^ loadedCapacitor = "";
		static String^ loadedOrdinance1 = "";
		static String^ loadedOrdinance2 = "";
		static String^ loadedOrdinance3 = "";
		static String^ loadedWeapon1 = "";
		static String^ loadedWeapon2 = "";
		static String^ loadedWeapon3 = "";
		static String^ loadedWeapon4 = "";
		static String^ loadedChaff = "";

		static String^ CMappdir = "";

#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ComponentManagementForm::typeid));
			this->ComponentsLabel = (gcnew System::Windows::Forms::Label());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->CompManagementPanel = (gcnew System::Windows::Forms::Panel());
			this->DeleteChaffButton = (gcnew System::Windows::Forms::Button());
			this->DeleteOrdinanceButton = (gcnew System::Windows::Forms::Button());
			this->DeleteWeaponButton = (gcnew System::Windows::Forms::Button());
			this->DeleteCapacitorButton = (gcnew System::Windows::Forms::Button());
			this->DeleteDroidButton = (gcnew System::Windows::Forms::Button());
			this->DeleteArmorButton = (gcnew System::Windows::Forms::Button());
			this->DeleteSheildButton = (gcnew System::Windows::Forms::Button());
			this->DeleteBoosterButton = (gcnew System::Windows::Forms::Button());
			this->DeleteEngineButton = (gcnew System::Windows::Forms::Button());
			this->DeleteReactorButton = (gcnew System::Windows::Forms::Button());
			this->AddCountermeasuresButton = (gcnew System::Windows::Forms::Button());
			this->EditCountermeasuresButton = (gcnew System::Windows::Forms::Button());
			this->EditReactorButton = (gcnew System::Windows::Forms::Button());
			this->AddEngineButton = (gcnew System::Windows::Forms::Button());
			this->EditEngineButton = (gcnew System::Windows::Forms::Button());
			this->AddBoosterButton = (gcnew System::Windows::Forms::Button());
			this->EditBoosterButton = (gcnew System::Windows::Forms::Button());
			this->AddSheildButton = (gcnew System::Windows::Forms::Button());
			this->EditSheildButton = (gcnew System::Windows::Forms::Button());
			this->AddArmorButton = (gcnew System::Windows::Forms::Button());
			this->EditArmorButton = (gcnew System::Windows::Forms::Button());
			this->AddDroidButton = (gcnew System::Windows::Forms::Button());
			this->EditDroidButton = (gcnew System::Windows::Forms::Button());
			this->AddCapacitorButton = (gcnew System::Windows::Forms::Button());
			this->EditCapacitorButton = (gcnew System::Windows::Forms::Button());
			this->AddOrdinanceButton = (gcnew System::Windows::Forms::Button());
			this->EditOrdinanceButton = (gcnew System::Windows::Forms::Button());
			this->AddWeaponButton = (gcnew System::Windows::Forms::Button());
			this->EditWeaponButton = (gcnew System::Windows::Forms::Button());
			this->AddReactorButton = (gcnew System::Windows::Forms::Button());
			this->CountermeasuresComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->WeaponComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CountermeasuresCompLabel = (gcnew System::Windows::Forms::Label());
			this->WeaponCompLabel = (gcnew System::Windows::Forms::Label());
			this->DroidComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CapacitorComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->OrdinanceComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->OrdinanaceCompLabel = (gcnew System::Windows::Forms::Label());
			this->CapacitorCompLabel = (gcnew System::Windows::Forms::Label());
			this->DroidCompLabel = (gcnew System::Windows::Forms::Label());
			this->EngineComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->BoosterComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SheildComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ArmorComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ReactorComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ArmorCompLabel = (gcnew System::Windows::Forms::Label());
			this->SheildCompLabel = (gcnew System::Windows::Forms::Label());
			this->BoosterCompLabel = (gcnew System::Windows::Forms::Label());
			this->EngineCompLabel = (gcnew System::Windows::Forms::Label());
			this->ReactorCompLabel = (gcnew System::Windows::Forms::Label());
			this->CompManagementPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// ComponentsLabel
			// 
			this->ComponentsLabel->AutoSize = true;
			this->ComponentsLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ComponentsLabel->Location = System::Drawing::Point(230, 9);
			this->ComponentsLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ComponentsLabel->Name = L"ComponentsLabel";
			this->ComponentsLabel->Size = System::Drawing::Size(172, 16);
			this->ComponentsLabel->TabIndex = 275;
			this->ComponentsLabel->Text = L"C  o  m  p  o  n  e  n  t  s";
			// 
			// CloseButton
			// 
			this->CloseButton->ForeColor = System::Drawing::Color::Black;
			this->CloseButton->Location = System::Drawing::Point(279, 385);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 41;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::CloseButton_Click);
			// 
			// CompManagementPanel
			// 
			this->CompManagementPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"CompManagementPanel.BackgroundImage")));
			this->CompManagementPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CompManagementPanel->Controls->Add(this->DeleteChaffButton);
			this->CompManagementPanel->Controls->Add(this->DeleteOrdinanceButton);
			this->CompManagementPanel->Controls->Add(this->DeleteWeaponButton);
			this->CompManagementPanel->Controls->Add(this->DeleteCapacitorButton);
			this->CompManagementPanel->Controls->Add(this->DeleteDroidButton);
			this->CompManagementPanel->Controls->Add(this->DeleteArmorButton);
			this->CompManagementPanel->Controls->Add(this->DeleteSheildButton);
			this->CompManagementPanel->Controls->Add(this->DeleteBoosterButton);
			this->CompManagementPanel->Controls->Add(this->DeleteEngineButton);
			this->CompManagementPanel->Controls->Add(this->DeleteReactorButton);
			this->CompManagementPanel->Controls->Add(this->AddCountermeasuresButton);
			this->CompManagementPanel->Controls->Add(this->EditCountermeasuresButton);
			this->CompManagementPanel->Controls->Add(this->EditReactorButton);
			this->CompManagementPanel->Controls->Add(this->AddEngineButton);
			this->CompManagementPanel->Controls->Add(this->EditEngineButton);
			this->CompManagementPanel->Controls->Add(this->AddBoosterButton);
			this->CompManagementPanel->Controls->Add(this->EditBoosterButton);
			this->CompManagementPanel->Controls->Add(this->AddSheildButton);
			this->CompManagementPanel->Controls->Add(this->EditSheildButton);
			this->CompManagementPanel->Controls->Add(this->AddArmorButton);
			this->CompManagementPanel->Controls->Add(this->EditArmorButton);
			this->CompManagementPanel->Controls->Add(this->AddDroidButton);
			this->CompManagementPanel->Controls->Add(this->EditDroidButton);
			this->CompManagementPanel->Controls->Add(this->AddCapacitorButton);
			this->CompManagementPanel->Controls->Add(this->EditCapacitorButton);
			this->CompManagementPanel->Controls->Add(this->AddOrdinanceButton);
			this->CompManagementPanel->Controls->Add(this->EditOrdinanceButton);
			this->CompManagementPanel->Controls->Add(this->AddWeaponButton);
			this->CompManagementPanel->Controls->Add(this->EditWeaponButton);
			this->CompManagementPanel->Controls->Add(this->AddReactorButton);
			this->CompManagementPanel->Controls->Add(this->CountermeasuresComboBox);
			this->CompManagementPanel->Controls->Add(this->WeaponComboBox);
			this->CompManagementPanel->Controls->Add(this->CountermeasuresCompLabel);
			this->CompManagementPanel->Controls->Add(this->WeaponCompLabel);
			this->CompManagementPanel->Controls->Add(this->DroidComboBox);
			this->CompManagementPanel->Controls->Add(this->CapacitorComboBox);
			this->CompManagementPanel->Controls->Add(this->OrdinanceComboBox);
			this->CompManagementPanel->Controls->Add(this->OrdinanaceCompLabel);
			this->CompManagementPanel->Controls->Add(this->CapacitorCompLabel);
			this->CompManagementPanel->Controls->Add(this->DroidCompLabel);
			this->CompManagementPanel->Controls->Add(this->EngineComboBox);
			this->CompManagementPanel->Controls->Add(this->BoosterComboBox);
			this->CompManagementPanel->Controls->Add(this->SheildComboBox);
			this->CompManagementPanel->Controls->Add(this->ArmorComboBox);
			this->CompManagementPanel->Controls->Add(this->ReactorComboBox);
			this->CompManagementPanel->Controls->Add(this->ArmorCompLabel);
			this->CompManagementPanel->Controls->Add(this->SheildCompLabel);
			this->CompManagementPanel->Controls->Add(this->BoosterCompLabel);
			this->CompManagementPanel->Controls->Add(this->EngineCompLabel);
			this->CompManagementPanel->Controls->Add(this->ReactorCompLabel);
			this->CompManagementPanel->Location = System::Drawing::Point(5, 35);
			this->CompManagementPanel->Name = L"CompManagementPanel";
			this->CompManagementPanel->Size = System::Drawing::Size(622, 340);
			this->CompManagementPanel->TabIndex = 325;
			// 
			// DeleteChaffButton
			// 
			this->DeleteChaffButton->ForeColor = System::Drawing::Color::Black;
			this->DeleteChaffButton->Location = System::Drawing::Point(355, 304);
			this->DeleteChaffButton->Name = L"DeleteChaffButton";
			this->DeleteChaffButton->Size = System::Drawing::Size(68, 21);
			this->DeleteChaffButton->TabIndex = 364;
			this->DeleteChaffButton->Text = L"Delete";
			this->DeleteChaffButton->UseVisualStyleBackColor = true;
			this->DeleteChaffButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::DeleteChaffButton_Click);
			// 
			// DeleteOrdinanceButton
			// 
			this->DeleteOrdinanceButton->ForeColor = System::Drawing::Color::Black;
			this->DeleteOrdinanceButton->Location = System::Drawing::Point(200, 304);
			this->DeleteOrdinanceButton->Name = L"DeleteOrdinanceButton";
			this->DeleteOrdinanceButton->Size = System::Drawing::Size(68, 21);
			this->DeleteOrdinanceButton->TabIndex = 360;
			this->DeleteOrdinanceButton->Text = L"Delete";
			this->DeleteOrdinanceButton->UseVisualStyleBackColor = true;
			this->DeleteOrdinanceButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::DeleteOrdinanceButton_Click);
			// 
			// DeleteWeaponButton
			// 
			this->DeleteWeaponButton->ForeColor = System::Drawing::Color::Black;
			this->DeleteWeaponButton->Location = System::Drawing::Point(510, 196);
			this->DeleteWeaponButton->Name = L"DeleteWeaponButton";
			this->DeleteWeaponButton->Size = System::Drawing::Size(68, 21);
			this->DeleteWeaponButton->TabIndex = 356;
			this->DeleteWeaponButton->Text = L"Delete";
			this->DeleteWeaponButton->UseVisualStyleBackColor = true;
			this->DeleteWeaponButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::DeleteWeaponButton_Click);
			// 
			// DeleteCapacitorButton
			// 
			this->DeleteCapacitorButton->ForeColor = System::Drawing::Color::Black;
			this->DeleteCapacitorButton->Location = System::Drawing::Point(355, 196);
			this->DeleteCapacitorButton->Name = L"DeleteCapacitorButton";
			this->DeleteCapacitorButton->Size = System::Drawing::Size(68, 21);
			this->DeleteCapacitorButton->TabIndex = 352;
			this->DeleteCapacitorButton->Text = L"Delete";
			this->DeleteCapacitorButton->UseVisualStyleBackColor = true;
			this->DeleteCapacitorButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::DeleteCapacitorButton_Click);
			// 
			// DeleteDroidButton
			// 
			this->DeleteDroidButton->ForeColor = System::Drawing::Color::Black;
			this->DeleteDroidButton->Location = System::Drawing::Point(201, 196);
			this->DeleteDroidButton->Name = L"DeleteDroidButton";
			this->DeleteDroidButton->Size = System::Drawing::Size(68, 21);
			this->DeleteDroidButton->TabIndex = 348;
			this->DeleteDroidButton->Text = L"Delete";
			this->DeleteDroidButton->UseVisualStyleBackColor = true;
			this->DeleteDroidButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::DeleteDroidButton_Click);
			// 
			// DeleteArmorButton
			// 
			this->DeleteArmorButton->ForeColor = System::Drawing::Color::Black;
			this->DeleteArmorButton->Location = System::Drawing::Point(45, 196);
			this->DeleteArmorButton->Name = L"DeleteArmorButton";
			this->DeleteArmorButton->Size = System::Drawing::Size(68, 21);
			this->DeleteArmorButton->TabIndex = 344;
			this->DeleteArmorButton->Text = L"Delete";
			this->DeleteArmorButton->UseVisualStyleBackColor = true;
			this->DeleteArmorButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::DeleteArmorButton_Click);
			// 
			// DeleteSheildButton
			// 
			this->DeleteSheildButton->ForeColor = System::Drawing::Color::Black;
			this->DeleteSheildButton->Location = System::Drawing::Point(510, 85);
			this->DeleteSheildButton->Name = L"DeleteSheildButton";
			this->DeleteSheildButton->Size = System::Drawing::Size(68, 21);
			this->DeleteSheildButton->TabIndex = 340;
			this->DeleteSheildButton->Text = L"Delete";
			this->DeleteSheildButton->UseVisualStyleBackColor = true;
			this->DeleteSheildButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::DeleteSheildButton_Click);
			// 
			// DeleteBoosterButton
			// 
			this->DeleteBoosterButton->ForeColor = System::Drawing::Color::Black;
			this->DeleteBoosterButton->Location = System::Drawing::Point(355, 85);
			this->DeleteBoosterButton->Name = L"DeleteBoosterButton";
			this->DeleteBoosterButton->Size = System::Drawing::Size(68, 21);
			this->DeleteBoosterButton->TabIndex = 336;
			this->DeleteBoosterButton->Text = L"Delete";
			this->DeleteBoosterButton->UseVisualStyleBackColor = true;
			this->DeleteBoosterButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::DeleteBoosterButton_Click);
			// 
			// DeleteEngineButton
			// 
			this->DeleteEngineButton->ForeColor = System::Drawing::Color::Black;
			this->DeleteEngineButton->Location = System::Drawing::Point(201, 85);
			this->DeleteEngineButton->Name = L"DeleteEngineButton";
			this->DeleteEngineButton->Size = System::Drawing::Size(68, 21);
			this->DeleteEngineButton->TabIndex = 332;
			this->DeleteEngineButton->Text = L"Delete";
			this->DeleteEngineButton->UseVisualStyleBackColor = true;
			this->DeleteEngineButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::DeleteEngineButton_Click);
			// 
			// DeleteReactorButton
			// 
			this->DeleteReactorButton->ForeColor = System::Drawing::Color::Black;
			this->DeleteReactorButton->Location = System::Drawing::Point(45, 85);
			this->DeleteReactorButton->Name = L"DeleteReactorButton";
			this->DeleteReactorButton->Size = System::Drawing::Size(68, 21);
			this->DeleteReactorButton->TabIndex = 328;
			this->DeleteReactorButton->Text = L"Delete";
			this->DeleteReactorButton->UseVisualStyleBackColor = true;
			this->DeleteReactorButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::DeleteReactorButton_Click);
			// 
			// AddCountermeasuresButton
			// 
			this->AddCountermeasuresButton->ForeColor = System::Drawing::Color::Black;
			this->AddCountermeasuresButton->Location = System::Drawing::Point(319, 277);
			this->AddCountermeasuresButton->Name = L"AddCountermeasuresButton";
			this->AddCountermeasuresButton->Size = System::Drawing::Size(68, 21);
			this->AddCountermeasuresButton->TabIndex = 362;
			this->AddCountermeasuresButton->Text = L"Add";
			this->AddCountermeasuresButton->UseVisualStyleBackColor = true;
			this->AddCountermeasuresButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::AddCountermeasuresButton_Click);
			// 
			// EditCountermeasuresButton
			// 
			this->EditCountermeasuresButton->ForeColor = System::Drawing::Color::Black;
			this->EditCountermeasuresButton->Location = System::Drawing::Point(391, 277);
			this->EditCountermeasuresButton->Name = L"EditCountermeasuresButton";
			this->EditCountermeasuresButton->Size = System::Drawing::Size(68, 21);
			this->EditCountermeasuresButton->TabIndex = 363;
			this->EditCountermeasuresButton->Text = L"Edit";
			this->EditCountermeasuresButton->UseVisualStyleBackColor = true;
			this->EditCountermeasuresButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::EditCountermeasuresButton_Click);
			// 
			// EditReactorButton
			// 
			this->EditReactorButton->ForeColor = System::Drawing::Color::Black;
			this->EditReactorButton->Location = System::Drawing::Point(81, 58);
			this->EditReactorButton->Name = L"EditReactorButton";
			this->EditReactorButton->Size = System::Drawing::Size(68, 21);
			this->EditReactorButton->TabIndex = 327;
			this->EditReactorButton->Text = L"Edit";
			this->EditReactorButton->UseVisualStyleBackColor = true;
			this->EditReactorButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::EditReactorButton_Click);
			// 
			// AddEngineButton
			// 
			this->AddEngineButton->ForeColor = System::Drawing::Color::Black;
			this->AddEngineButton->Location = System::Drawing::Point(164, 58);
			this->AddEngineButton->Name = L"AddEngineButton";
			this->AddEngineButton->Size = System::Drawing::Size(68, 21);
			this->AddEngineButton->TabIndex = 330;
			this->AddEngineButton->Text = L"Add";
			this->AddEngineButton->UseVisualStyleBackColor = true;
			this->AddEngineButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::AddEngineButton_Click);
			// 
			// EditEngineButton
			// 
			this->EditEngineButton->ForeColor = System::Drawing::Color::Black;
			this->EditEngineButton->Location = System::Drawing::Point(236, 58);
			this->EditEngineButton->Name = L"EditEngineButton";
			this->EditEngineButton->Size = System::Drawing::Size(68, 21);
			this->EditEngineButton->TabIndex = 331;
			this->EditEngineButton->Text = L"Edit";
			this->EditEngineButton->UseVisualStyleBackColor = true;
			this->EditEngineButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::EditEngineButton_Click);
			// 
			// AddBoosterButton
			// 
			this->AddBoosterButton->ForeColor = System::Drawing::Color::Black;
			this->AddBoosterButton->Location = System::Drawing::Point(319, 58);
			this->AddBoosterButton->Name = L"AddBoosterButton";
			this->AddBoosterButton->Size = System::Drawing::Size(68, 21);
			this->AddBoosterButton->TabIndex = 334;
			this->AddBoosterButton->Text = L"Add";
			this->AddBoosterButton->UseVisualStyleBackColor = true;
			this->AddBoosterButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::AddBoosterButton_Click);
			// 
			// EditBoosterButton
			// 
			this->EditBoosterButton->ForeColor = System::Drawing::Color::Black;
			this->EditBoosterButton->Location = System::Drawing::Point(391, 58);
			this->EditBoosterButton->Name = L"EditBoosterButton";
			this->EditBoosterButton->Size = System::Drawing::Size(68, 21);
			this->EditBoosterButton->TabIndex = 335;
			this->EditBoosterButton->Text = L"Edit";
			this->EditBoosterButton->UseVisualStyleBackColor = true;
			this->EditBoosterButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::EditBoosterButton_Click);
			// 
			// AddSheildButton
			// 
			this->AddSheildButton->ForeColor = System::Drawing::Color::Black;
			this->AddSheildButton->Location = System::Drawing::Point(474, 58);
			this->AddSheildButton->Name = L"AddSheildButton";
			this->AddSheildButton->Size = System::Drawing::Size(68, 21);
			this->AddSheildButton->TabIndex = 338;
			this->AddSheildButton->Text = L"Add";
			this->AddSheildButton->UseVisualStyleBackColor = true;
			this->AddSheildButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::AddSheildButton_Click);
			// 
			// EditSheildButton
			// 
			this->EditSheildButton->ForeColor = System::Drawing::Color::Black;
			this->EditSheildButton->Location = System::Drawing::Point(546, 58);
			this->EditSheildButton->Name = L"EditSheildButton";
			this->EditSheildButton->Size = System::Drawing::Size(68, 21);
			this->EditSheildButton->TabIndex = 339;
			this->EditSheildButton->Text = L"Edit";
			this->EditSheildButton->UseVisualStyleBackColor = true;
			this->EditSheildButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::EditSheildButton_Click);
			// 
			// AddArmorButton
			// 
			this->AddArmorButton->ForeColor = System::Drawing::Color::Black;
			this->AddArmorButton->Location = System::Drawing::Point(9, 169);
			this->AddArmorButton->Name = L"AddArmorButton";
			this->AddArmorButton->Size = System::Drawing::Size(68, 21);
			this->AddArmorButton->TabIndex = 342;
			this->AddArmorButton->Text = L"Add";
			this->AddArmorButton->UseVisualStyleBackColor = true;
			this->AddArmorButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::AddArmorButton_Click);
			// 
			// EditArmorButton
			// 
			this->EditArmorButton->ForeColor = System::Drawing::Color::Black;
			this->EditArmorButton->Location = System::Drawing::Point(81, 169);
			this->EditArmorButton->Name = L"EditArmorButton";
			this->EditArmorButton->Size = System::Drawing::Size(68, 21);
			this->EditArmorButton->TabIndex = 343;
			this->EditArmorButton->Text = L"Edit";
			this->EditArmorButton->UseVisualStyleBackColor = true;
			this->EditArmorButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::EditArmorButton_Click);
			// 
			// AddDroidButton
			// 
			this->AddDroidButton->ForeColor = System::Drawing::Color::Black;
			this->AddDroidButton->Location = System::Drawing::Point(164, 169);
			this->AddDroidButton->Name = L"AddDroidButton";
			this->AddDroidButton->Size = System::Drawing::Size(68, 21);
			this->AddDroidButton->TabIndex = 346;
			this->AddDroidButton->Text = L"Add";
			this->AddDroidButton->UseVisualStyleBackColor = true;
			this->AddDroidButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::AddDroidButton_Click);
			// 
			// EditDroidButton
			// 
			this->EditDroidButton->ForeColor = System::Drawing::Color::Black;
			this->EditDroidButton->Location = System::Drawing::Point(236, 169);
			this->EditDroidButton->Name = L"EditDroidButton";
			this->EditDroidButton->Size = System::Drawing::Size(68, 21);
			this->EditDroidButton->TabIndex = 347;
			this->EditDroidButton->Text = L"Edit";
			this->EditDroidButton->UseVisualStyleBackColor = true;
			this->EditDroidButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::EditDroidButton_Click);
			// 
			// AddCapacitorButton
			// 
			this->AddCapacitorButton->ForeColor = System::Drawing::Color::Black;
			this->AddCapacitorButton->Location = System::Drawing::Point(319, 169);
			this->AddCapacitorButton->Name = L"AddCapacitorButton";
			this->AddCapacitorButton->Size = System::Drawing::Size(68, 21);
			this->AddCapacitorButton->TabIndex = 350;
			this->AddCapacitorButton->Text = L"Add";
			this->AddCapacitorButton->UseVisualStyleBackColor = true;
			this->AddCapacitorButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::AddCapacitorButton_Click);
			// 
			// EditCapacitorButton
			// 
			this->EditCapacitorButton->ForeColor = System::Drawing::Color::Black;
			this->EditCapacitorButton->Location = System::Drawing::Point(391, 169);
			this->EditCapacitorButton->Name = L"EditCapacitorButton";
			this->EditCapacitorButton->Size = System::Drawing::Size(68, 21);
			this->EditCapacitorButton->TabIndex = 351;
			this->EditCapacitorButton->Text = L"Edit";
			this->EditCapacitorButton->UseVisualStyleBackColor = true;
			this->EditCapacitorButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::EditCapacitorButton_Click);
			// 
			// AddOrdinanceButton
			// 
			this->AddOrdinanceButton->ForeColor = System::Drawing::Color::Black;
			this->AddOrdinanceButton->Location = System::Drawing::Point(164, 277);
			this->AddOrdinanceButton->Name = L"AddOrdinanceButton";
			this->AddOrdinanceButton->Size = System::Drawing::Size(68, 21);
			this->AddOrdinanceButton->TabIndex = 358;
			this->AddOrdinanceButton->Text = L"Add";
			this->AddOrdinanceButton->UseVisualStyleBackColor = true;
			this->AddOrdinanceButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::AddOrdinanceButton_Click);
			// 
			// EditOrdinanceButton
			// 
			this->EditOrdinanceButton->ForeColor = System::Drawing::Color::Black;
			this->EditOrdinanceButton->Location = System::Drawing::Point(236, 277);
			this->EditOrdinanceButton->Name = L"EditOrdinanceButton";
			this->EditOrdinanceButton->Size = System::Drawing::Size(68, 21);
			this->EditOrdinanceButton->TabIndex = 359;
			this->EditOrdinanceButton->Text = L"Edit";
			this->EditOrdinanceButton->UseVisualStyleBackColor = true;
			this->EditOrdinanceButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::EditOrdinanceButton_Click);
			// 
			// AddWeaponButton
			// 
			this->AddWeaponButton->ForeColor = System::Drawing::Color::Black;
			this->AddWeaponButton->Location = System::Drawing::Point(474, 169);
			this->AddWeaponButton->Name = L"AddWeaponButton";
			this->AddWeaponButton->Size = System::Drawing::Size(68, 21);
			this->AddWeaponButton->TabIndex = 354;
			this->AddWeaponButton->Text = L"Add";
			this->AddWeaponButton->UseVisualStyleBackColor = true;
			this->AddWeaponButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::AddWeaponButton_Click);
			// 
			// EditWeaponButton
			// 
			this->EditWeaponButton->ForeColor = System::Drawing::Color::Black;
			this->EditWeaponButton->Location = System::Drawing::Point(546, 169);
			this->EditWeaponButton->Name = L"EditWeaponButton";
			this->EditWeaponButton->Size = System::Drawing::Size(68, 21);
			this->EditWeaponButton->TabIndex = 355;
			this->EditWeaponButton->Text = L"Edit";
			this->EditWeaponButton->UseVisualStyleBackColor = true;
			this->EditWeaponButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::EditWeaponButton_Click);
			// 
			// AddReactorButton
			// 
			this->AddReactorButton->ForeColor = System::Drawing::Color::Black;
			this->AddReactorButton->Location = System::Drawing::Point(9, 58);
			this->AddReactorButton->Name = L"AddReactorButton";
			this->AddReactorButton->Size = System::Drawing::Size(68, 21);
			this->AddReactorButton->TabIndex = 326;
			this->AddReactorButton->Text = L"Add";
			this->AddReactorButton->UseVisualStyleBackColor = true;
			this->AddReactorButton->Click += gcnew System::EventHandler(this, &ComponentManagementForm::AddReactorButton_Click);
			// 
			// CountermeasuresComboBox
			// 
			this->CountermeasuresComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CountermeasuresComboBox->DropDownWidth = 200;
			this->CountermeasuresComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CountermeasuresComboBox->FormattingEnabled = true;
			this->CountermeasuresComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L""});
			this->CountermeasuresComboBox->Location = System::Drawing::Point(319, 250);
			this->CountermeasuresComboBox->Name = L"CountermeasuresComboBox";
			this->CountermeasuresComboBox->Size = System::Drawing::Size(140, 21);
			this->CountermeasuresComboBox->TabIndex = 361;
			this->CountermeasuresComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ComponentManagementForm::CountermeasuresComboBox_SelectedIndexChanged);
			// 
			// WeaponComboBox
			// 
			this->WeaponComboBox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->WeaponComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->WeaponComboBox->DropDownWidth = 200;
			this->WeaponComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->WeaponComboBox->FormattingEnabled = true;
			this->WeaponComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L""});
			this->WeaponComboBox->Location = System::Drawing::Point(474, 142);
			this->WeaponComboBox->Name = L"WeaponComboBox";
			this->WeaponComboBox->Size = System::Drawing::Size(140, 21);
			this->WeaponComboBox->TabIndex = 353;
			this->WeaponComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ComponentManagementForm::WeaponComboBox_SelectedIndexChanged);
			// 
			// CountermeasuresCompLabel
			// 
			this->CountermeasuresCompLabel->AutoSize = true;
			this->CountermeasuresCompLabel->BackColor = System::Drawing::Color::Transparent;
			this->CountermeasuresCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CountermeasuresCompLabel->Location = System::Drawing::Point(321, 232);
			this->CountermeasuresCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->CountermeasuresCompLabel->Name = L"CountermeasuresCompLabel";
			this->CountermeasuresCompLabel->Size = System::Drawing::Size(138, 16);
			this->CountermeasuresCompLabel->TabIndex = 374;
			this->CountermeasuresCompLabel->Text = L"Countermeasures";
			// 
			// WeaponCompLabel
			// 
			this->WeaponCompLabel->AutoSize = true;
			this->WeaponCompLabel->BackColor = System::Drawing::Color::Transparent;
			this->WeaponCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->WeaponCompLabel->Location = System::Drawing::Point(509, 124);
			this->WeaponCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->WeaponCompLabel->Name = L"WeaponCompLabel";
			this->WeaponCompLabel->Size = System::Drawing::Size(67, 16);
			this->WeaponCompLabel->TabIndex = 373;
			this->WeaponCompLabel->Text = L"Weapon";
			// 
			// DroidComboBox
			// 
			this->DroidComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->DroidComboBox->DropDownWidth = 200;
			this->DroidComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DroidComboBox->FormattingEnabled = true;
			this->DroidComboBox->Location = System::Drawing::Point(164, 142);
			this->DroidComboBox->Name = L"DroidComboBox";
			this->DroidComboBox->Size = System::Drawing::Size(140, 21);
			this->DroidComboBox->TabIndex = 345;
			this->DroidComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ComponentManagementForm::DroidComboBox_SelectedIndexChanged);
			// 
			// CapacitorComboBox
			// 
			this->CapacitorComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CapacitorComboBox->DropDownWidth = 200;
			this->CapacitorComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorComboBox->FormattingEnabled = true;
			this->CapacitorComboBox->Location = System::Drawing::Point(319, 142);
			this->CapacitorComboBox->Name = L"CapacitorComboBox";
			this->CapacitorComboBox->Size = System::Drawing::Size(140, 21);
			this->CapacitorComboBox->TabIndex = 349;
			this->CapacitorComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ComponentManagementForm::CapacitorComboBox_SelectedIndexChanged);
			// 
			// OrdinanceComboBox
			// 
			this->OrdinanceComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->OrdinanceComboBox->DropDownWidth = 200;
			this->OrdinanceComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OrdinanceComboBox->FormattingEnabled = true;
			this->OrdinanceComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L""});
			this->OrdinanceComboBox->Location = System::Drawing::Point(164, 250);
			this->OrdinanceComboBox->Name = L"OrdinanceComboBox";
			this->OrdinanceComboBox->Size = System::Drawing::Size(140, 21);
			this->OrdinanceComboBox->TabIndex = 357;
			this->OrdinanceComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ComponentManagementForm::OrdinanceComboBox_SelectedIndexChanged);
			// 
			// OrdinanaceCompLabel
			// 
			this->OrdinanaceCompLabel->AutoSize = true;
			this->OrdinanaceCompLabel->BackColor = System::Drawing::Color::Transparent;
			this->OrdinanaceCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OrdinanaceCompLabel->Location = System::Drawing::Point(195, 232);
			this->OrdinanaceCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->OrdinanaceCompLabel->Name = L"OrdinanaceCompLabel";
			this->OrdinanaceCompLabel->Size = System::Drawing::Size(82, 16);
			this->OrdinanaceCompLabel->TabIndex = 372;
			this->OrdinanaceCompLabel->Text = L"Ordinance";
			// 
			// CapacitorCompLabel
			// 
			this->CapacitorCompLabel->AutoSize = true;
			this->CapacitorCompLabel->BackColor = System::Drawing::Color::Transparent;
			this->CapacitorCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CapacitorCompLabel->Location = System::Drawing::Point(349, 123);
			this->CapacitorCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->CapacitorCompLabel->Name = L"CapacitorCompLabel";
			this->CapacitorCompLabel->Size = System::Drawing::Size(78, 16);
			this->CapacitorCompLabel->TabIndex = 371;
			this->CapacitorCompLabel->Text = L"Capacitor";
			// 
			// DroidCompLabel
			// 
			this->DroidCompLabel->AutoSize = true;
			this->DroidCompLabel->BackColor = System::Drawing::Color::Transparent;
			this->DroidCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DroidCompLabel->Location = System::Drawing::Point(178, 124);
			this->DroidCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DroidCompLabel->Name = L"DroidCompLabel";
			this->DroidCompLabel->Size = System::Drawing::Size(117, 16);
			this->DroidCompLabel->TabIndex = 370;
			this->DroidCompLabel->Text = L"Droid Interface";
			// 
			// EngineComboBox
			// 
			this->EngineComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->EngineComboBox->DropDownWidth = 200;
			this->EngineComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineComboBox->FormattingEnabled = true;
			this->EngineComboBox->Location = System::Drawing::Point(164, 31);
			this->EngineComboBox->Name = L"EngineComboBox";
			this->EngineComboBox->Size = System::Drawing::Size(140, 21);
			this->EngineComboBox->TabIndex = 329;
			this->EngineComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ComponentManagementForm::EngineComboBox_SelectedIndexChanged);
			// 
			// BoosterComboBox
			// 
			this->BoosterComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->BoosterComboBox->DropDownWidth = 200;
			this->BoosterComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterComboBox->FormattingEnabled = true;
			this->BoosterComboBox->Location = System::Drawing::Point(319, 31);
			this->BoosterComboBox->Name = L"BoosterComboBox";
			this->BoosterComboBox->Size = System::Drawing::Size(140, 21);
			this->BoosterComboBox->TabIndex = 333;
			this->BoosterComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ComponentManagementForm::BoosterComboBox_SelectedIndexChanged);
			// 
			// SheildComboBox
			// 
			this->SheildComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->SheildComboBox->DropDownWidth = 200;
			this->SheildComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildComboBox->FormattingEnabled = true;
			this->SheildComboBox->Location = System::Drawing::Point(474, 31);
			this->SheildComboBox->Name = L"SheildComboBox";
			this->SheildComboBox->Size = System::Drawing::Size(140, 21);
			this->SheildComboBox->TabIndex = 337;
			this->SheildComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ComponentManagementForm::SheildComboBox_SelectedIndexChanged);
			// 
			// ArmorComboBox
			// 
			this->ArmorComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ArmorComboBox->DropDownWidth = 200;
			this->ArmorComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ArmorComboBox->FormattingEnabled = true;
			this->ArmorComboBox->Location = System::Drawing::Point(9, 142);
			this->ArmorComboBox->Name = L"ArmorComboBox";
			this->ArmorComboBox->Size = System::Drawing::Size(140, 21);
			this->ArmorComboBox->TabIndex = 341;
			this->ArmorComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ComponentManagementForm::ArmorComboBox_SelectedIndexChanged);
			// 
			// ReactorComboBox
			// 
			this->ReactorComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ReactorComboBox->DropDownWidth = 200;
			this->ReactorComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorComboBox->FormattingEnabled = true;
			this->ReactorComboBox->Location = System::Drawing::Point(9, 31);
			this->ReactorComboBox->Name = L"ReactorComboBox";
			this->ReactorComboBox->Size = System::Drawing::Size(140, 21);
			this->ReactorComboBox->TabIndex = 325;
			this->ReactorComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ComponentManagementForm::ReactorComboBox_SelectedIndexChanged);
			// 
			// ArmorCompLabel
			// 
			this->ArmorCompLabel->AutoSize = true;
			this->ArmorCompLabel->BackColor = System::Drawing::Color::Transparent;
			this->ArmorCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ArmorCompLabel->Location = System::Drawing::Point(53, 123);
			this->ArmorCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ArmorCompLabel->Name = L"ArmorCompLabel";
			this->ArmorCompLabel->Size = System::Drawing::Size(53, 16);
			this->ArmorCompLabel->TabIndex = 369;
			this->ArmorCompLabel->Text = L"Armor";
			// 
			// SheildCompLabel
			// 
			this->SheildCompLabel->AutoSize = true;
			this->SheildCompLabel->BackColor = System::Drawing::Color::Transparent;
			this->SheildCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SheildCompLabel->Location = System::Drawing::Point(517, 13);
			this->SheildCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->SheildCompLabel->Name = L"SheildCompLabel";
			this->SheildCompLabel->Size = System::Drawing::Size(52, 16);
			this->SheildCompLabel->TabIndex = 368;
			this->SheildCompLabel->Text = L"Shield";
			// 
			// BoosterCompLabel
			// 
			this->BoosterCompLabel->AutoSize = true;
			this->BoosterCompLabel->BackColor = System::Drawing::Color::Transparent;
			this->BoosterCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoosterCompLabel->Location = System::Drawing::Point(356, 13);
			this->BoosterCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->BoosterCompLabel->Name = L"BoosterCompLabel";
			this->BoosterCompLabel->Size = System::Drawing::Size(65, 16);
			this->BoosterCompLabel->TabIndex = 367;
			this->BoosterCompLabel->Text = L"Booster";
			// 
			// EngineCompLabel
			// 
			this->EngineCompLabel->AutoSize = true;
			this->EngineCompLabel->BackColor = System::Drawing::Color::Transparent;
			this->EngineCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->EngineCompLabel->Location = System::Drawing::Point(206, 13);
			this->EngineCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EngineCompLabel->Name = L"EngineCompLabel";
			this->EngineCompLabel->Size = System::Drawing::Size(57, 16);
			this->EngineCompLabel->TabIndex = 366;
			this->EngineCompLabel->Text = L"Engine";
			// 
			// ReactorCompLabel
			// 
			this->ReactorCompLabel->AutoSize = true;
			this->ReactorCompLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReactorCompLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReactorCompLabel->Location = System::Drawing::Point(48, 13);
			this->ReactorCompLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ReactorCompLabel->Name = L"ReactorCompLabel";
			this->ReactorCompLabel->Size = System::Drawing::Size(64, 16);
			this->ReactorCompLabel->TabIndex = 365;
			this->ReactorCompLabel->Text = L"Reactor";
			// 
			// ComponentManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(45)), 
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->ClientSize = System::Drawing::Size(632, 420);
			this->Controls->Add(this->CompManagementPanel);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->ComponentsLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ComponentManagementForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Component Management";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ComponentManagementForm::ComponentManagementForm_FormClosing);
			this->CompManagementPanel->ResumeLayout(false);
			this->CompManagementPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		 ///
		 /// Functions
		 ///

		 // Clears all componet lists.
private: System::Void ClearLists(){
			 CMReactorList->Clear();
			 CMEngineList->Clear();
			 CMBoosterList->Clear();
			 CMSheildList->Clear();
			 CMArmorList->Clear();
			 CMDroidList->Clear();
			 CMCapacitorList->Clear();
			 CMWeaponList->Clear();
			 CMOrdinanceList->Clear();
			 CMChaffList->Clear();

			 CMReactorNameList->Clear();
			 CMEngineNameList->Clear();
			 CMBoosterNameList->Clear();
			 CMSheildNameList->Clear();
			 CMArmorNameList->Clear();
			 CMDroidNameList->Clear();
			 CMCapacitorNameList->Clear();
			 CMWeaponNameList->Clear();
			 CMOrdinanceNameList->Clear();
			 CMChaffNameList->Clear();
		 }
		 // Updates the interface.
private: System::Void UpdateGUI() {
			 // Reactors
			 ReactorComboBox->Items->Clear();

			 for (int i=0; i<CMReactorNameList->Count; i++)
			 {
				 ReactorComboBox->Items->Add(CMReactorNameList[i]);
			 }

			 if (ReactorComboBox->Items->Count == 0)
			 {
				 DeleteReactorButton->Enabled = false;
				 EditReactorButton->Enabled = false;
			 }
			 else
			 {
				 DeleteReactorButton->Enabled = true;
				 EditReactorButton->Enabled = true;
			 }

			 // Engines
			 EngineComboBox->Items->Clear();

			 for (int i=0; i<CMEngineNameList->Count; i++)
			 {
				 EngineComboBox->Items->Add(CMEngineNameList[i]);
			 }

			 if (EngineComboBox->Items->Count == 0)
			 {
				 DeleteEngineButton->Enabled = false;
				 EditEngineButton->Enabled = false;
			 }
			 else
			 {
				 DeleteEngineButton->Enabled = true;
				 EditEngineButton->Enabled = true;
			 }

			 // Boosters
			 BoosterComboBox->Items->Clear();

			 for (int i=0; i<CMBoosterNameList->Count; i++)
			 {
				 BoosterComboBox->Items->Add(CMBoosterNameList[i]);
			 }

			 if (BoosterComboBox->Items->Count == 0)
			 {
				 DeleteBoosterButton->Enabled = false;
				 EditBoosterButton->Enabled = false;
			 }
			 else
			 {
				 DeleteBoosterButton->Enabled = true;
				 EditBoosterButton->Enabled = true;
			 }

			 // Sheilds
			 SheildComboBox->Items->Clear();

			 for (int i=0; i<CMSheildNameList->Count; i++)
			 {
				 SheildComboBox->Items->Add(CMSheildNameList[i]);
			 }

			 if (SheildComboBox->Items->Count == 0)
			 {
				 DeleteSheildButton->Enabled = false;
				 EditSheildButton->Enabled = false;
			 }
			 else
			 {
				 DeleteSheildButton->Enabled = true;
				 EditSheildButton->Enabled = true;
			 }

			 // Armor
			 ArmorComboBox->Items->Clear();

			 for (int i=0; i<CMArmorNameList->Count; i++)
			 {
				 ArmorComboBox->Items->Add(CMArmorNameList[i]);
			 }

			 if (ArmorComboBox->Items->Count == 0)
			 {
				 DeleteArmorButton->Enabled = false;
				 EditArmorButton->Enabled = false;
			 }
			 else
			 {
				 DeleteArmorButton->Enabled = true;
				 EditArmorButton->Enabled = true;
			 }

			 // Droid
			 DroidComboBox->Items->Clear();

			 for (int i=0; i<CMDroidNameList->Count; i++)
			 {
				 DroidComboBox->Items->Add(CMDroidNameList[i]);
			 }

			 if (DroidComboBox->Items->Count == 0)
			 {
				 DeleteDroidButton->Enabled = false;
				 EditDroidButton->Enabled = false;
			 }
			 else
			 {
				 DeleteDroidButton->Enabled = true;
				 EditDroidButton->Enabled = true;
			 }

			 // Capacitor
			 CapacitorComboBox->Items->Clear();

			 for (int i=0; i<CMCapacitorNameList->Count; i++)
			 {
				 CapacitorComboBox->Items->Add(CMCapacitorNameList[i]);
			 }

			 if (CapacitorComboBox->Items->Count == 0)
			 {
				 DeleteCapacitorButton->Enabled = false;
				 EditCapacitorButton->Enabled = false;
			 }
			 else
			 {
				 DeleteCapacitorButton->Enabled = true;
				 EditCapacitorButton->Enabled = true;
			 }

			 // Weapons
			 WeaponComboBox->Items->Clear();

			 for (int i=0; i<CMWeaponNameList->Count; i++)
			 {
				 WeaponComboBox->Items->Add(CMWeaponNameList[i]);
			 }

			 if (WeaponComboBox->Items->Count == 0)
			 {
				 DeleteWeaponButton->Enabled = false;
				 EditWeaponButton->Enabled = false;
			 }
			 else
			 {
				 DeleteWeaponButton->Enabled = true;
				 EditWeaponButton->Enabled = true;
			 }

			 // Ordinance
			 OrdinanceComboBox->Items->Clear();

			 for (int i=0; i<CMOrdinanceNameList->Count; i++)
			 {
				 OrdinanceComboBox->Items->Add(CMOrdinanceNameList[i]);
			 }

			 if (OrdinanceComboBox->Items->Count == 0)
			 {
				 DeleteOrdinanceButton->Enabled = false;
				 EditOrdinanceButton->Enabled = false;
			 }
			 else
			 {
				 DeleteOrdinanceButton->Enabled = true;
				 EditOrdinanceButton->Enabled = true;
			 }

			 // Chaff
			 CountermeasuresComboBox->Items->Clear();

			 for (int i=0; i<CMChaffNameList->Count; i++)
			 {
				 CountermeasuresComboBox->Items->Add(CMChaffNameList[i]);
			 }

			 if (CountermeasuresComboBox->Items->Count == 0)
			 {
				 DeleteChaffButton->Enabled = false;
				 EditCountermeasuresButton->Enabled = false;
			 }
			 else
			 {
				 DeleteChaffButton->Enabled = true;
				 EditCountermeasuresButton->Enabled = true;
			 }

			 this->Invalidate();
		 }

		 // Disables/Enables the Delete and Edit buttons depending on what the user selects in the combo box.
private: System::Void UpdateSelection(){
			 // Reactor
			 if (ReactorComboBox->SelectedIndex == -1 || ReactorComboBox->SelectedIndex == 0)
			 {
				 DeleteReactorButton->Enabled = false;
				 EditReactorButton->Enabled = false;
			 }
			 else
			 {
				 DeleteReactorButton->Enabled = true;
				 EditReactorButton->Enabled = true;
			 }

			 // Engine
			 if (EngineComboBox->SelectedIndex == -1 || EngineComboBox->SelectedIndex == 0)
			 {
				 DeleteEngineButton->Enabled = false;
				 EditEngineButton->Enabled = false;
			 }
			 else
			 {
				 DeleteEngineButton->Enabled = true;
				 EditEngineButton->Enabled = true;
			 }

			 // Booster
			 if (BoosterComboBox->SelectedIndex == -1 || BoosterComboBox->SelectedIndex == 0)
			 {
				 DeleteBoosterButton->Enabled = false;
				 EditBoosterButton->Enabled = false;
			 }
			 else
			 {
				 DeleteBoosterButton->Enabled = true;
				 EditBoosterButton->Enabled = true;
			 }

			 // Sheild
			 if (SheildComboBox->SelectedIndex == -1 || SheildComboBox->SelectedIndex == 0)
			 {
				 DeleteSheildButton->Enabled = false;
				 EditSheildButton->Enabled = false;
			 }
			 else
			 {
				 DeleteSheildButton->Enabled = true;
				 EditSheildButton->Enabled = true;
			 }

 			 // Armor
			 if (ArmorComboBox->SelectedIndex == -1 || ArmorComboBox->SelectedIndex == 0)
			 {
				 DeleteArmorButton->Enabled = false;
				 EditArmorButton->Enabled = false;
			 }
			 else
			 {
				 DeleteArmorButton->Enabled = true;
				 EditArmorButton->Enabled = true;
			 }

 			 // Droid
			 if (DroidComboBox->SelectedIndex == -1 || DroidComboBox->SelectedIndex == 0)
			 {
				 DeleteDroidButton->Enabled = false;
				 EditDroidButton->Enabled = false;
			 }
			 else
			 {
				 DeleteDroidButton->Enabled = true;
				 EditDroidButton->Enabled = true;
			 }

 			 // Capacitor
			 if (CapacitorComboBox->SelectedIndex == -1 || CapacitorComboBox->SelectedIndex == 0)
			 {
				 DeleteCapacitorButton->Enabled = false;
				 EditCapacitorButton->Enabled = false;
			 }
			 else
			 {
				 DeleteCapacitorButton->Enabled = true;
				 EditCapacitorButton->Enabled = true;
			 }

 			 // Weapon
			 if (WeaponComboBox->SelectedIndex == -1 || WeaponComboBox->SelectedIndex == 0)
			 {
				 DeleteWeaponButton->Enabled = false;
				 EditWeaponButton->Enabled = false;
			 }
			 else
			 {
				 DeleteWeaponButton->Enabled = true;
				 EditWeaponButton->Enabled = true;
			 }

 			 // Ordinance
			 if (OrdinanceComboBox->SelectedIndex == -1 || OrdinanceComboBox->SelectedIndex == 0)
			 {
				 DeleteOrdinanceButton->Enabled = false;
				 EditOrdinanceButton->Enabled = false;
			 }
			 else
			 {
				 DeleteOrdinanceButton->Enabled = true;
				 EditOrdinanceButton->Enabled = true;
			 }

 			 // Chaff
			 if (CountermeasuresComboBox->SelectedIndex == -1 || CountermeasuresComboBox->SelectedIndex == 0)
			 {
				 DeleteChaffButton->Enabled = false;
				 EditCountermeasuresButton->Enabled = false;
			 }
			 else
			 {
				 DeleteChaffButton->Enabled = true;
				 EditCountermeasuresButton->Enabled = true;
			 }

		 }
		 // Closes the form.  Includes the CreateCompLib function.
private: System::Void CloseForm(){
			 m_ReactorList = CMReactorList;
			 m_EngineList = CMEngineList;
			 m_BoosterList = CMBoosterList;
			 m_SheildList = CMSheildList;
			 m_ArmorList = CMArmorList;
			 m_DroidList = CMDroidList;
			 m_CapacitorList = CMCapacitorList;
			 m_WeaponList = CMWeaponList;
			 m_OrdinanceList = CMOrdinanceList;
			 m_ChaffList = CMChaffList;

			 m_ReactorNameList = CMReactorNameList;
			 m_EngineNameList = CMEngineNameList;
			 m_BoosterNameList = CMBoosterNameList;
			 m_SheildNameList = CMSheildNameList;
			 m_ArmorNameList = CMArmorNameList;
			 m_DroidNameList = CMDroidNameList;
			 m_CapacitorNameList = CMCapacitorNameList;
			 m_WeaponNameList = CMWeaponNameList;
			 m_OrdinanceNameList = CMOrdinanceNameList;
			 m_ChaffNameList = CMChaffNameList;

			 String^ complibdirectory = "CompLib\\complib.xml";

			 System::IO::File::Delete(String::Concat(CMappdir, "\\", complibdirectory));

			 CompLib::XMLUtilities::CreateCompFile(String::Concat(CMappdir, "\\", complibdirectory), "pilotname", CMReactorList->ToArray(), CMEngineList->ToArray(), 
				 CMBoosterList->ToArray(), CMSheildList->ToArray(), CMArmorList->ToArray(), CMDroidList->ToArray(), CMCapacitorList->ToArray(),
				 CMOrdinanceList->ToArray(), CMWeaponList->ToArray(), CMChaffList->ToArray());
		 }
		 /// Edit functions for the case of an existing component (Dosn't delete component on "Cancel")
private: System::Void EditExistingReactor(){
		 	 if (ReactorComboBox->SelectedIndex != -1)
			 {
				 ReactorForm ^reactorForm = gcnew ReactorForm(CMReactorList[ReactorComboBox->SelectedIndex], 
					 ReactorComboBox->SelectedItem->ToString());

				 if(reactorForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = ReactorComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMReactorList->RemoveAt(tempIndex);
						 CMReactorList->Insert(tempIndex, reactorForm->ReactorList);
					 }
					 //changesMade = true;
				 }
				 else
				 {
					 //changesMade = false;
					 this->Invalidate();
				 }
			 }
			 UpdateGUI();
			 ReactorComboBox->SelectedIndex = (CMReactorNameList->Count - 1);
		 }
private: System::Void EditExistingEngine(){
			 if (EngineComboBox->SelectedIndex != -1)
			 {
				 EngineForm ^engineForm = gcnew EngineForm(CMEngineList[EngineComboBox->SelectedIndex],
					 EngineComboBox->SelectedItem->ToString());

				 if(engineForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = EngineComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMEngineList->RemoveAt(tempIndex);
						 CMEngineList->Insert(tempIndex, engineForm->EngineList);
					 }
				 }
				 else
				 {
					 this->Invalidate();
				 }
			 }
			 UpdateGUI();
			 EngineComboBox->SelectedIndex = (CMEngineNameList->Count - 1);
		 }
private: System::Void EditExistingBooster(){
			 if (BoosterComboBox->SelectedIndex != -1) 
			 {
				 BoosterForm ^boosterForm = gcnew BoosterForm(CMBoosterList[BoosterComboBox->SelectedIndex], 
					 BoosterComboBox->SelectedItem->ToString());
				 
				 if(boosterForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = BoosterComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMBoosterList->RemoveAt(tempIndex);
						 CMBoosterList->Insert(tempIndex, boosterForm->BoosterList);
					 }
				 }
				 else
				 {
					 this->Invalidate();
				 }
			 }
			 UpdateGUI();
			 BoosterComboBox->SelectedIndex = (CMBoosterNameList->Count - 1);
		 }
private: System::Void EditExistingSheild(){
			 if (SheildComboBox->SelectedIndex != -1)
			 {
				 SheildForm ^sheildForm = gcnew SheildForm(CMSheildList[SheildComboBox->SelectedIndex],
					 SheildComboBox->SelectedItem->ToString());

				 if(sheildForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = SheildComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMSheildList->RemoveAt(tempIndex);
						 CMSheildList->Insert(tempIndex, sheildForm->SheildList);
					 }
				 }
				 else
				 {
					 this->Invalidate();
				 }
			 }
			 UpdateGUI();
			 SheildComboBox->SelectedIndex = (CMSheildNameList->Count - 1);
		 }
private: System::Void EditExistingArmor(){
			 if (ArmorComboBox->SelectedIndex != -1)
			 {
				 ArmorForm ^armorForm = gcnew ArmorForm(CMArmorList[ArmorComboBox->SelectedIndex], 
					 ArmorComboBox->SelectedItem->ToString());
				 
				 if(armorForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = ArmorComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMArmorList->RemoveAt(tempIndex);
						 CMArmorList->Insert(tempIndex, armorForm->ArmorData);
					
					 }
				 }
				 else
				 {
					 this->Invalidate();
				 }
			 }
			 UpdateGUI();
			 ArmorComboBox->SelectedIndex = (CMArmorNameList->Count - 1);
		 }
private: System::Void EditExistingCapacitor(){
			 if (CapacitorComboBox->SelectedIndex != -1)
			 {
				 CapacitorForm ^capacitorForm = gcnew CapacitorForm(CMCapacitorList[CapacitorComboBox->SelectedIndex], 
					 CapacitorComboBox->SelectedItem->ToString());
				 
				 if(capacitorForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = CapacitorComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMCapacitorList->RemoveAt(tempIndex);
						 CMCapacitorList->Insert(tempIndex, capacitorForm->CapacitorList);
					
					 }
				 }
				 else
				 {
					 this->Invalidate();
				 }
			 }
			 UpdateGUI();
			 CapacitorComboBox->SelectedIndex = (CMCapacitorNameList->Count - 1);
		 }
private: System::Void EditExistingDroid(){
			 if (DroidComboBox->SelectedIndex != -1)
			 {
				 DroidForm ^droidForm = gcnew DroidForm(CMDroidList[DroidComboBox->SelectedIndex], 
					 DroidComboBox->SelectedItem->ToString());
				 
				 if(droidForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = DroidComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMDroidList->RemoveAt(tempIndex);
						 CMDroidList->Insert(tempIndex, droidForm->DroidList);
					
					 }
				 }
				 else
				 {
					 this->Invalidate();
				 }
			 }
			 UpdateGUI();
			 DroidComboBox->SelectedIndex = (CMDroidNameList->Count - 1);
		 }
private: System::Void EditExistingOrdinance(){
			 if (OrdinanceComboBox->SelectedIndex != -1)
			 {
				 OrdinanceForm ^ordinanceForm = gcnew OrdinanceForm(CMOrdinanceList[OrdinanceComboBox->SelectedIndex], 
					 OrdinanceComboBox->SelectedItem->ToString());
				 
				 if(ordinanceForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = OrdinanceComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMOrdinanceList->RemoveAt(tempIndex);
						 CMOrdinanceList->Insert(tempIndex, ordinanceForm->OrdinanceList);
					
					 }
				 }
				 else
				 {
					 this->Invalidate();
				 }
			 }
			 UpdateGUI();
			 OrdinanceComboBox->SelectedIndex = (CMOrdinanceNameList->Count - 1);
		 }
private: System::Void EditExistingWeapon(){
			 if (WeaponComboBox->SelectedIndex != -1)
			 {
				 WeaponForm ^weaponForm = gcnew WeaponForm(CMWeaponList[WeaponComboBox->SelectedIndex], 
					 WeaponComboBox->SelectedItem->ToString());
				 
				 if(weaponForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = WeaponComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMWeaponList->RemoveAt(tempIndex);
						 CMWeaponList->Insert(tempIndex, weaponForm->WeaponList);
					
					 }
				 }
				 else
				 {
					 this->Invalidate();
				 }
			 }
			 UpdateGUI();
			 WeaponComboBox->SelectedIndex = (CMWeaponNameList->Count - 1);
		 }
private: System::Void EditExistingChaff(){
			 if (CountermeasuresComboBox->SelectedIndex != -1)
			 {
				 ChaffForm ^chaffForm = gcnew ChaffForm(CMChaffList[CountermeasuresComboBox->SelectedIndex], 
					 CountermeasuresComboBox->SelectedItem->ToString());
				 
				 if(chaffForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = CountermeasuresComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMChaffList->RemoveAt(tempIndex);
						 CMChaffList->Insert(tempIndex, chaffForm->ChaffList);
					
					 }
				 }
				 else
				 {
					 this->Invalidate();
				 }
			 }
			 UpdateGUI();
			 CountermeasuresComboBox->SelectedIndex = (CMChaffNameList->Count - 1);
		 }
		 // Edit functions for the case of a new componet (Does delete component on "Cancel")
private: System::Void EditOnAddReactor(){
		 	 if (ReactorComboBox->SelectedIndex != -1)
			 {
				 ReactorForm ^reactorForm = gcnew ReactorForm(CMReactorList[ReactorComboBox->SelectedIndex], 
					 ReactorComboBox->SelectedItem->ToString());

				 if(reactorForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = ReactorComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMReactorList->RemoveAt(tempIndex);
						 CMReactorList->Insert(tempIndex, reactorForm->ReactorList);
					 }
					 //changesMade = true;
				 }
				 else
				 {
					 int tempIndex = ReactorComboBox->SelectedIndex;

					 CMReactorNameList->RemoveAt(tempIndex);
					 CMReactorList->RemoveAt(tempIndex);

					 //changesMade = false;
				 }
			 }
			 UpdateGUI();
			 ReactorComboBox->SelectedIndex = (CMReactorNameList->Count - 1);
		 }

private: System::Void EditOnAddEngine(){
			 if (EngineComboBox->SelectedIndex != -1)
			 {
				 EngineForm ^engineForm = gcnew EngineForm(CMEngineList[EngineComboBox->SelectedIndex],
					 EngineComboBox->SelectedItem->ToString());

				 if(engineForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = EngineComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMEngineList->RemoveAt(tempIndex);
						 CMEngineList->Insert(tempIndex, engineForm->EngineList);
					 }
				 }
				 else
				 {
					 int tempIndex = EngineComboBox->SelectedIndex;

					 CMEngineNameList->RemoveAt(tempIndex);
					 CMEngineList->RemoveAt(tempIndex);
				 }
			 }
			 UpdateGUI();
			 EngineComboBox->SelectedIndex = (CMEngineNameList->Count - 1);
		 }
private: System::Void EditOnAddBooster(){
			 if (BoosterComboBox->SelectedIndex != -1) 
			 {
				 BoosterForm ^boosterForm = gcnew BoosterForm(CMBoosterList[BoosterComboBox->SelectedIndex], 
					 BoosterComboBox->SelectedItem->ToString());
				 
				 if(boosterForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = BoosterComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMBoosterList->RemoveAt(tempIndex);
						 CMBoosterList->Insert(tempIndex, boosterForm->BoosterList);
					 }
				 }
				 else
				 {
					 int tempIndex = BoosterComboBox->SelectedIndex;

					 CMBoosterNameList->RemoveAt(tempIndex);
					 CMBoosterList->RemoveAt(tempIndex);
				 }
			 }
			 UpdateGUI();
			 BoosterComboBox->SelectedIndex = (CMBoosterNameList->Count - 1);
		 }
private: System::Void EditOnAddSheild(){
			 if (SheildComboBox->SelectedIndex != -1)
			 {
				 SheildForm ^sheildForm = gcnew SheildForm(CMSheildList[SheildComboBox->SelectedIndex],
					 SheildComboBox->SelectedItem->ToString());

				 if(sheildForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = SheildComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMSheildList->RemoveAt(tempIndex);
						 CMSheildList->Insert(tempIndex, sheildForm->SheildList);
					 }
				 }
				 else
				 {
					 int tempIndex = SheildComboBox->SelectedIndex;

					 CMSheildNameList->RemoveAt(tempIndex);
					 CMSheildList->RemoveAt(tempIndex);
				 }
			 }
			 UpdateGUI();
			 SheildComboBox->SelectedIndex = (CMSheildNameList->Count - 1);
		 }
private: System::Void EditOnAddArmor(){
		 	 if (ArmorComboBox->SelectedIndex != -1)
			 {
				 ArmorForm ^armorForm = gcnew ArmorForm(CMArmorList[ArmorComboBox->SelectedIndex], 
					 ArmorComboBox->SelectedItem->ToString());
				 
				 if(armorForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = ArmorComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMArmorList->RemoveAt(tempIndex);
						 CMArmorList->Insert(tempIndex, armorForm->ArmorData);
					
					 }
				 }
				 else
				 {
					 int tempIndex = ArmorComboBox->SelectedIndex;

					 CMArmorNameList->RemoveAt(tempIndex);
					 CMArmorList->RemoveAt(tempIndex);
				 }
			 }
			 UpdateGUI();
			 ArmorComboBox->SelectedIndex = (CMArmorNameList->Count - 1);
		 }
private: System::Void EditOnAddCapacitor(){
		 	 if (CapacitorComboBox->SelectedIndex != -1)
			 {
				 CapacitorForm ^capacitorForm = gcnew CapacitorForm(CMCapacitorList[CapacitorComboBox->SelectedIndex], 
					 CapacitorComboBox->SelectedItem->ToString());
				 
				 if(capacitorForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = CapacitorComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMCapacitorList->RemoveAt(tempIndex);
						 CMCapacitorList->Insert(tempIndex, capacitorForm->CapacitorList);
					
					 }
				 }
				 else
				 {
					 int tempIndex = CapacitorComboBox->SelectedIndex;

					 CMCapacitorNameList->RemoveAt(tempIndex);
					 CMCapacitorList->RemoveAt(tempIndex);
				 }
			 }
			 UpdateGUI();
			 CapacitorComboBox->SelectedIndex = (CMCapacitorNameList->Count - 1);
		 }
private: System::Void EditOnAddDroid(){
		 	 if (DroidComboBox->SelectedIndex != -1)
			 {
				 DroidForm ^droidForm = gcnew DroidForm(CMDroidList[DroidComboBox->SelectedIndex], 
					 DroidComboBox->SelectedItem->ToString());
				 
				 if(droidForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = DroidComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMDroidList->RemoveAt(tempIndex);
						 CMDroidList->Insert(tempIndex, droidForm->DroidList);
					
					 }
				 }
				 else
				 {
					 int tempIndex = DroidComboBox->SelectedIndex;

					 CMDroidNameList->RemoveAt(tempIndex);
					 CMDroidList->RemoveAt(tempIndex);
				 }
			 }
			 UpdateGUI();
			 DroidComboBox->SelectedIndex = (CMDroidNameList->Count - 1);
		 }
private: System::Void EditOnAddOrdinance(){
		 	 if (OrdinanceComboBox->SelectedIndex != -1)
			 {
				 OrdinanceForm ^ordinanceForm = gcnew OrdinanceForm(CMOrdinanceList[OrdinanceComboBox->SelectedIndex], 
					 OrdinanceComboBox->SelectedItem->ToString());
				 
				 if(ordinanceForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = OrdinanceComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMOrdinanceList->RemoveAt(tempIndex);
						 CMOrdinanceList->Insert(tempIndex, ordinanceForm->OrdinanceList);
					
					 }
				 }
				 else
				 {
					 int tempIndex = OrdinanceComboBox->SelectedIndex;

					 CMOrdinanceNameList->RemoveAt(tempIndex);
					 CMOrdinanceList->RemoveAt(tempIndex);
				 }
			 }
			 UpdateGUI();
			 OrdinanceComboBox->SelectedIndex = (CMOrdinanceNameList->Count - 1);
		 }
private: System::Void EditOnAddWeapon(){
		 	 if (WeaponComboBox->SelectedIndex != -1)
			 {
				 WeaponForm ^weaponForm = gcnew WeaponForm(CMWeaponList[WeaponComboBox->SelectedIndex], 
					 WeaponComboBox->SelectedItem->ToString());
				 
				 if(weaponForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = WeaponComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMWeaponList->RemoveAt(tempIndex);
						 CMWeaponList->Insert(tempIndex, weaponForm->WeaponList);
					
					 }
				 }
				 else
				 {
					 int tempIndex = WeaponComboBox->SelectedIndex;

					 CMWeaponNameList->RemoveAt(tempIndex);
					 CMWeaponList->RemoveAt(tempIndex);
				 }
			 }
			 UpdateGUI();
			 WeaponComboBox->SelectedIndex = (CMWeaponNameList->Count - 1);
		 }
private: System::Void EditOnAddChaff(){
		 	 if (CountermeasuresComboBox->SelectedIndex != -1)
			 {
				 ChaffForm ^chaffForm = gcnew ChaffForm(CMChaffList[CountermeasuresComboBox->SelectedIndex], 
					 CountermeasuresComboBox->SelectedItem->ToString());
				 
				 if(chaffForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {

					 int tempIndex = CountermeasuresComboBox->SelectedIndex;

					 if (tempIndex != -1)
					 {
						 CMChaffList->RemoveAt(tempIndex);
						 CMChaffList->Insert(tempIndex, chaffForm->ChaffList);
					
					 }
				 }
				 else
				 {
					 int tempIndex = CountermeasuresComboBox->SelectedIndex;

					 CMChaffNameList->RemoveAt(tempIndex);
					 CMChaffList->RemoveAt(tempIndex);
				 }
			 }
			 UpdateGUI();
			 CountermeasuresComboBox->SelectedIndex = (CMChaffNameList->Count - 1);
		 }
		 ///
		 /// Reactor Event Handlers
		 ///
private: System::Void AddReactorButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CompNamePrompt ^nameForm = gcnew CompNamePrompt;

				 if (nameForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					for (int i=0; i<CMReactorNameList->Count; i++)
					{
						if (nameForm->CompName->ToString() == CMReactorNameList[i]->ToString())
						{
							if (MessageBox::Show("Error: That Component Name already exists.", "Bad Component Name", 
								MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK)
							{
								goto error;
							}
						}
					}

					CMReactorNameList->Add(nameForm->CompName);
					 
					CompLib::Reactor^ tempReactor = gcnew CompLib::Reactor();
					tempReactor->TableName = String::Concat("Reactor_", nameForm->CompName);
					CMReactorList->Add(tempReactor);

					error:
					nameForm->Close();
					UpdateGUI();
					ReactorComboBox->SelectedIndex = (CMReactorNameList->Count - 1);

					EditOnAddReactor();
				 }
		 }
private: System::Void EditReactorButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 EditExistingReactor();
		 }
private: System::Void DeleteReactorButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (loadedReactor != ReactorComboBox->SelectedItem)
			 {
				 CMReactorNameList->RemoveAt(ReactorComboBox->SelectedIndex);
				 CMReactorList->RemoveAt(ReactorComboBox->SelectedIndex);

				 UpdateGUI();
				 ReactorComboBox->SelectedIndex = (CMReactorNameList->Count - 1);
			 }
			 else
			 {
				 MessageBox::Show("Error: You cannot delete a component that is currently loaded into the open ship. If you wish to delete this componet you must unload it first.", 
					 "Componet in Use", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
		 }

private: System::Void ReactorComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSelection();
		 }

		 ///		 
		 /// Engine Event Handlers
		 ///
private: System::Void AddEngineButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CompNamePrompt ^nameForm = gcnew CompNamePrompt;

				 if (nameForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 for (int i=0; i<CMEngineNameList->Count; i++)
					 {
						 if (nameForm->CompName->ToString() == CMEngineNameList[i]->ToString())
						 {
							 if (MessageBox::Show("Error: That Component Name already exists.", "Bad Component Name", 
								MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK)
							 {
								 goto error;
							 }
						 }
					 }

					 CMEngineNameList->Add(nameForm->CompName);
					 
					 CompLib::Engine^ tempEngine = gcnew CompLib::Engine();
					 tempEngine->TableName = String::Concat("Engine_", nameForm->CompName);
					 CMEngineList->Add(tempEngine);

					 error:
					 nameForm->Close();
					 UpdateGUI();
					 EngineComboBox->SelectedIndex = (CMEngineNameList->Count - 1);

					 EditOnAddEngine();
				 }
		 }
private: System::Void EditEngineButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 EditExistingEngine();
		 }

private: System::Void DeleteEngineButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (loadedEngine != EngineComboBox->SelectedItem)
			 {
				 CMEngineNameList->RemoveAt(EngineComboBox->SelectedIndex);
				 CMEngineList->RemoveAt(EngineComboBox->SelectedIndex);

				 UpdateGUI();
				 EngineComboBox->SelectedIndex = (CMEngineNameList->Count - 1);
			 }
			 else
			 {
				 MessageBox::Show("Error: You cannot delete a component that is currently loaded into the open ship. If you wish to delete this componet you must unload it first.", 
					 "Componet in Use", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
		 }
private: System::Void EngineComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSelection();
		 }

		 ///		 
		 /// Booster Event Handlers
		 ///
private: System::Void AddBoosterButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CompNamePrompt ^nameForm = gcnew CompNamePrompt;

				 if (nameForm->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					 for (int i=0; i<CMBoosterNameList->Count; i++)
					 {
						 if (nameForm->CompName->ToString() == CMBoosterNameList[i]->ToString())
						 {
							 if (MessageBox::Show("Error: That Component Name already exists.", "Bad Component Name", 
								MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK)
							 {
								 goto error;
							 }
						 }
					 }
					 
					 CMBoosterNameList->Add(nameForm->CompName);

					 CompLib::Booster^ tempBooster = gcnew CompLib::Booster();
					 tempBooster->TableName = String::Concat("Booster_", nameForm->CompName);
					 CMBoosterList->Add(tempBooster);

					 error:
					 nameForm->Close();
					 UpdateGUI();
					 BoosterComboBox->SelectedIndex = (CMBoosterNameList->Count - 1);

					 EditOnAddBooster();
				 }
		 }
private: System::Void EditBoosterButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 EditExistingBooster();
		 }

private: System::Void DeleteBoosterButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (loadedBooster != BoosterComboBox->SelectedItem)
			 {
				 CMBoosterNameList->RemoveAt(BoosterComboBox->SelectedIndex);
				 CMBoosterList->RemoveAt(BoosterComboBox->SelectedIndex);

				 UpdateGUI();
				 BoosterComboBox->SelectedIndex = (CMBoosterNameList->Count - 1);
			 }
			 else
			 {
				 MessageBox::Show("Error: You cannot delete a component that is currently loaded into the open ship. If you wish to delete this componet you must unload it first.", 
					 "Componet in Use", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
		 }
private: System::Void BoosterComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSelection();
		 }

		 ///		 
		 /// Sheild Event Handlers
		 ///
private: System::Void AddSheildButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CompNamePrompt ^nameForm = gcnew CompNamePrompt;
				 if (nameForm->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					 for (int i=0; i<CMSheildNameList->Count; i++)
					 {
						 if (nameForm->CompName->ToString() == CMSheildNameList[i]->ToString())
						 {
							 if (MessageBox::Show("Error: That Component Name already exists.", "Bad Component Name", 
								MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK)
							 {
								 goto error;
							 }
						 }
					 }

					 CMSheildNameList->Add(nameForm->CompName);

					 CompLib::Sheild^ tempSheild = gcnew CompLib::Sheild();
					 tempSheild->TableName = String::Concat("Sheild_", nameForm->CompName);
					 CMSheildList->Add(tempSheild);

					 error:
					 nameForm->Close();
					 UpdateGUI();
					 SheildComboBox->SelectedIndex = (CMSheildNameList->Count - 1);

					 EditOnAddSheild();
				 }
		 }
private: System::Void EditSheildButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 EditExistingSheild();
		 }



private: System::Void DeleteSheildButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (loadedSheild != SheildComboBox->SelectedItem)
			 {
				 CMSheildNameList->RemoveAt(SheildComboBox->SelectedIndex);
				 CMSheildList->RemoveAt(SheildComboBox->SelectedIndex);

				 UpdateGUI();
				 SheildComboBox->SelectedIndex = (CMSheildNameList->Count - 1);
			 }
			 else
			 {
				 MessageBox::Show("Error: You cannot delete a component that is currently loaded into the open ship. If you wish to delete this componet you must unload it first.", 
					 "Componet in Use", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
		 }
private: System::Void SheildComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSelection();
		 }
		 ///		 
		 /// Armor Event Handlers
		 ///
private: System::Void AddArmorButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CompNamePrompt ^nameForm = gcnew CompNamePrompt;

				 if (nameForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					for (int i=0; i<CMArmorNameList->Count; i++)
					{
						if (nameForm->CompName->ToString() == CMArmorNameList[i]->ToString())
						{
							if (MessageBox::Show("Error: That Component Name already exists.", "Bad Component Name", 
								MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK)
							{
								goto error;
							}
						}
					}

					CMArmorNameList->Add(nameForm->CompName);
					 
					CompLib::Armor^ tempArmor = gcnew CompLib::Armor();
					tempArmor->TableName = String::Concat("Armor_", nameForm->CompName);
					CMArmorList->Add(tempArmor);

					error:
					nameForm->Close();
					UpdateGUI();
					ArmorComboBox->SelectedIndex = (CMArmorNameList->Count - 1);

					EditOnAddArmor();
				}
		 }
private: System::Void EditArmorButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditExistingArmor();
		 }


private: System::Void DeleteArmorButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (loadedFArmor != ArmorComboBox->SelectedItem || loadedRArmor != ArmorComboBox->SelectedItem)
			 {
				 CMArmorNameList->RemoveAt(ArmorComboBox->SelectedIndex);
				 CMArmorList->RemoveAt(ArmorComboBox->SelectedIndex);

				 UpdateGUI();
				 ArmorComboBox->SelectedIndex = (CMArmorNameList->Count - 1);
			 }
			 else
			 {
				 MessageBox::Show("Error: You cannot delete a component that is currently loaded into the open ship. If you wish to delete this componet you must unload it first.", 
					 "Componet in Use", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
		 }
private: System::Void ArmorComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSelection();
		 }
		 ///		 
		 /// Droid  Event Handlers
		 ///
private: System::Void AddDroidButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CompNamePrompt ^nameForm = gcnew CompNamePrompt;
				 if (nameForm->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					for (int i=0; i<CMDroidNameList->Count; i++)
					{
						if (nameForm->CompName->ToString() == CMDroidNameList[i]->ToString())
						{
							if (MessageBox::Show("Error: That Component Name already exists.", "Bad Component Name", 
								MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK)
							{
								goto error;
							}
						}
					}
					CMDroidNameList->Add(nameForm->CompName);
					 
					CompLib::Droid^ tempDroid = gcnew CompLib::Droid();
					tempDroid->TableName = String::Concat("Droid_", nameForm->CompName);
					CMDroidList->Add(tempDroid);

					error:
					nameForm->Close();
					UpdateGUI();
					DroidComboBox->SelectedIndex = (CMDroidNameList->Count - 1);

					EditOnAddDroid();
				 }
		 }
private: System::Void EditDroidButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditExistingDroid();
		 }


private: System::Void DeleteDroidButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (loadedDroid != DroidComboBox->SelectedItem)
			 {
				 CMDroidNameList->RemoveAt(DroidComboBox->SelectedIndex);
				 CMDroidList->RemoveAt(DroidComboBox->SelectedIndex);

				 UpdateGUI();
				 DroidComboBox->SelectedIndex = (CMDroidNameList->Count - 1);
			 }
			 else
			 {
				 MessageBox::Show("Error: You cannot delete a component that is currently loaded into the open ship. If you wish to delete this componet you must unload it first.", 
					 "Componet in Use", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
		 }
private: System::Void DroidComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSelection();
		 }
		 ///		 
		 /// Capacitor  Event Handlers
		 ///
private: System::Void AddCapacitorButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CompNamePrompt ^nameForm = gcnew CompNamePrompt;
				 if (nameForm->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					for (int i=0; i<CMCapacitorNameList->Count; i++)
					{
						if (nameForm->CompName->ToString() == CMCapacitorNameList[i]->ToString())
						{
							if (MessageBox::Show("Error: That Component Name already exists.", "Bad Component Name", 
								MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK)
							{
								goto error;
							}
						}
					}
					CMCapacitorNameList->Add(nameForm->CompName);
					 
					CompLib::Capacitor^ tempCapacitor = gcnew CompLib::Capacitor();
					tempCapacitor->TableName = String::Concat("Capacitor_", nameForm->CompName);
					CMCapacitorList->Add(tempCapacitor);

					error:
					nameForm->Close();
					UpdateGUI();
					CapacitorComboBox->SelectedIndex = (CMCapacitorNameList->Count - 1);

					EditOnAddCapacitor();
				 }
		 }
private: System::Void EditCapacitorButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditExistingCapacitor();
		 }


private: System::Void DeleteCapacitorButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (loadedCapacitor != CapacitorComboBox->SelectedItem)
			 {
				 CMCapacitorNameList->RemoveAt(CapacitorComboBox->SelectedIndex);
				 CMCapacitorList->RemoveAt(CapacitorComboBox->SelectedIndex);

				 UpdateGUI();
				 CapacitorComboBox->SelectedIndex = (CMCapacitorNameList->Count - 1);
			 }
			 else
			 {
				 MessageBox::Show("Error: You cannot delete a component that is currently loaded into the open ship. If you wish to delete this componet you must unload it first.", 
					 "Componet in Use", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
		 }
private: System::Void CapacitorComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSelection();
		 }
		 ///		 
		 /// Weapon  Event Handlers
		 ///
private: System::Void AddWeaponButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CompNamePrompt ^nameForm = gcnew CompNamePrompt;
				 if (nameForm->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					for (int i=0; i<CMWeaponNameList->Count; i++)
					{
						if (nameForm->CompName->ToString() == CMWeaponNameList[i]->ToString())
						{
							if (MessageBox::Show("Error: That Component Name already exists.", "Bad Component Name", 
								MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK)
							{
								goto error;
							}
						}
					}
					CMWeaponNameList->Add(nameForm->CompName);
					 
					CompLib::Weapon^ tempWeapon = gcnew CompLib::Weapon();
					tempWeapon->TableName = String::Concat("Weapon_", nameForm->CompName);
					CMWeaponList->Add(tempWeapon);

					error:
					nameForm->Close();
					UpdateGUI();
					WeaponComboBox->SelectedIndex = (CMWeaponNameList->Count - 1);

					EditOnAddWeapon();
				 }
		 }
private: System::Void EditWeaponButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditExistingWeapon();
		 }


private: System::Void DeleteWeaponButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (loadedWeapon1 != WeaponComboBox->SelectedItem || loadedWeapon2 != WeaponComboBox->SelectedItem ||
				 loadedWeapon3 != WeaponComboBox->SelectedItem || loadedWeapon4 != WeaponComboBox->SelectedItem)
			 {
				 CMWeaponNameList->RemoveAt(WeaponComboBox->SelectedIndex);
				 CMWeaponList->RemoveAt(WeaponComboBox->SelectedIndex);

				 UpdateGUI();
				 WeaponComboBox->SelectedIndex = (CMWeaponNameList->Count - 1);
			 }
			 else
			 {
				 MessageBox::Show("Error: You cannot delete a component that is currently loaded into the open ship. If you wish to delete this componet you must unload it first.", 
					 "Componet in Use", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
		 }
private: System::Void WeaponComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSelection();
		 }
		 ///		 
		 /// Ordinance  Event Handlers
		 ///
private: System::Void AddOrdinanceButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CompNamePrompt ^nameForm = gcnew CompNamePrompt;
				 if (nameForm->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					for (int i=0; i<CMOrdinanceNameList->Count; i++)
					{
						if (nameForm->CompName->ToString() == CMOrdinanceNameList[i]->ToString())
						{
							if (MessageBox::Show("Error: That Component Name already exists.", "Bad Component Name", 
								MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK)
							{
								goto error;
							}
						}
					}
					CMOrdinanceNameList->Add(nameForm->CompName);
					 
					CompLib::Ordinance^ tempOrdinance = gcnew CompLib::Ordinance();
					tempOrdinance->TableName = String::Concat("Ordinance_", nameForm->CompName);
					CMOrdinanceList->Add(tempOrdinance);

					error:
					nameForm->Close();
					UpdateGUI();
					OrdinanceComboBox->SelectedIndex = (CMOrdinanceNameList->Count - 1);

					EditOnAddOrdinance();
				 }
		 }
private: System::Void EditOrdinanceButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditExistingOrdinance();
		 }


private: System::Void DeleteOrdinanceButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (loadedOrdinance1 != OrdinanceComboBox->SelectedItem || loadedOrdinance2 != OrdinanceComboBox->SelectedItem ||
				 loadedOrdinance3 != OrdinanceComboBox->SelectedItem)
			 {
				 CMOrdinanceNameList->RemoveAt(OrdinanceComboBox->SelectedIndex);
				 CMOrdinanceList->RemoveAt(OrdinanceComboBox->SelectedIndex);

				 UpdateGUI();
				 OrdinanceComboBox->SelectedIndex = (CMOrdinanceNameList->Count - 1);
			 }
			 else
			 {
				 MessageBox::Show("Error: You cannot delete a component that is currently loaded into the open ship. If you wish to delete this componet you must unload it first.", 
					 "Componet in Use", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
		 }
private: System::Void OrdinanceComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSelection();
		 }
		 ///		 
		 /// Chaff  Event Handlers
		 ///
private: System::Void AddCountermeasuresButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 CompNamePrompt ^nameForm = gcnew CompNamePrompt;
				 if (nameForm->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					for (int i=0; i<CMChaffNameList->Count; i++)
					{
						if (nameForm->CompName->ToString() == CMChaffNameList[i]->ToString())
						{
							if (MessageBox::Show("Error: That Component Name already exists.", "Bad Component Name", 
								MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK)
							{
								goto error;
							}
						}
					}
					CMChaffNameList->Add(nameForm->CompName);
					 
					CompLib::Chaff^ tempChaff = gcnew CompLib::Chaff();
					tempChaff->TableName = String::Concat("Chaff_", nameForm->CompName);
					CMChaffList->Add(tempChaff);

					error:
					nameForm->Close();
					UpdateGUI();
					CountermeasuresComboBox->SelectedIndex = (CMChaffNameList->Count - 1);

					EditOnAddChaff();
				 }
		 }
private: System::Void EditCountermeasuresButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditExistingChaff();
		 }


private: System::Void DeleteChaffButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (loadedChaff != CountermeasuresComboBox->SelectedItem)
			 {
				 CMChaffNameList->RemoveAt(CountermeasuresComboBox->SelectedIndex);
				 CMChaffList->RemoveAt(CountermeasuresComboBox->SelectedIndex);

				 UpdateGUI();
				 CountermeasuresComboBox->SelectedIndex = (CMChaffNameList->Count - 1);
			 }
			 else
			 {
				 MessageBox::Show("Error: You cannot delete a component that is currently loaded into the open ship. If you wish to delete this componet you must unload it first.", 
					 "Componet in Use", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
		 }
private: System::Void CountermeasuresComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 UpdateSelection();
		 }


		 ///		 
		 /// Other
		 ///
private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void ComponentManagementForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			bool error = false;
			
			if (CMReactorNameList->Count == 0 || CMEngineNameList->Count == 0 || CMBoosterNameList->Count == 0 || 
			CMSheildNameList->Count == 0 || CMArmorNameList->Count == 0 || CMDroidNameList->Count == 0 || 
			CMCapacitorNameList->Count == 0 || CMWeaponNameList->Count == 0 || CMOrdinanceNameList->Count == 0 ||
			CMChaffNameList->Count == 0)
			{
				if (MessageBox::Show("Error: You must add at least one component to each component type.", "Bad Component", 
					MessageBoxButtons::OK, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::OK)
				{
					error = true;
				}
			}

			if (error == false)
			{
				CloseForm();
			}
			else
			{
				e->Cancel;
			}
		 }
};
}
