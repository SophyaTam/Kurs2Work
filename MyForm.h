#pragma once
#include "MyForm1.h"
#include "MainMenu1.h" // Âêëþ÷àåì òîëüêî çàãîëîâî÷íûé ôàéë
#include "Video.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include "Global.h"

namespace Kurs2Work {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		MainMenu1* mainMenu; // Èñïîëüçóåì îáû÷íûé óêàçàòåëü

	public:
		MyForm() {
			InitializeComponent();
			mainMenu = new MainMenu1; // Ñîçäàåì ýêçåìïëÿð MainMenu1
			mainMenu->AddOptions(); // Äîáàâëÿåì îïöèè
		}

		~MyForm() {
			delete mainMenu; // Îñâîáîæäàåì ïàìÿòü
		}

	private: System::Windows::Forms::Button^ SerialsOption;
	private: System::Windows::Forms::Button^ Child_Option;
	private: System::Windows::Forms::Button^ Detective_Option;
	private: System::Windows::Forms::Button^ Comedy_Option;
	private: System::Windows::Forms::Button^ MelodramOption;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label2;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Mistral", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(314, 60);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(127, 51);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Child_Option_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::MediumPurple;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(314, 128);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 51);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Detective_Option_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Thistle;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(313, 265);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(126, 48);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::Comedy_Option_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Plum;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Palace Script MT", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(315, 198);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(126, 48);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::Melodram_Option_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::LavenderBlush;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(314, 332);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(125, 48);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::Serials_Option_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"MingLiU_HKSCS-ExtB", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(221, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 23);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// MyForm
			// 
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(745, 416);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Child_Option_Click(System::Object^ sender, System::EventArgs^ e) {
		globalOption = 1;
		this->Hide();
		MyForm1^ obj1 = gcnew MyForm1(this);
		obj1->ShowDialog();
	}
	private: System::Void Detective_Option_Click(System::Object^ sender, System::EventArgs^ e) {
		globalOption = 2;
		this->Hide();
		MyForm1^ obj1 = gcnew MyForm1(this);
		obj1->ShowDialog();
	}
	private: System::Void Comedy_Option_Click(System::Object^ sender, System::EventArgs^ e) {
		globalOption = 3;
		this->Hide();
		MyForm1^ obj1 = gcnew MyForm1(this);
		obj1->ShowDialog();
	}
	private: System::Void Melodram_Option_Click(System::Object^ sender, System::EventArgs^ e) {
		globalOption = 4;
		this->Hide();
		MyForm1^ obj1 = gcnew MyForm1(this);
		obj1->ShowDialog();
	}
	private: System::Void Serials_Option_Click(System::Object^ sender, System::EventArgs^ e) {
		globalOption = 5;
		this->Hide();
		MyForm1^ obj1 = gcnew MyForm1(this);
		obj1->ShowDialog();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		int n = this->button1->TabIndex + 1; // Óáåäèòåñü, ÷òî âû èñïîëüçóåòå ïðàâèëüíûé èíäåêñ
		std::string optionText = mainMenu->AddOptionsInput(n); // Ïîëó÷àåì òåêñò îïöèè
		this->button1->Text = msclr::interop::marshal_as<System::String^>(optionText); // Ïðåîáðàçóåì std::string â System::String^

		int n1 = this->button2->TabIndex + 1; // Èñïîëüçóåì ïðàâèëüíûé èíäåêñ äëÿ button2
		std::string optionText1 = mainMenu->AddOptionsInput(n1); // Ïîëó÷àåì òåêñò îïöèè äëÿ button2
		this->button2->Text = msclr::interop::marshal_as<System::String^>(optionText1); // Ïðåîáðàçóåì std::string â System::String^

		int n2 = this->button3->TabIndex + 1; // Èñïîëüçóåì ïðàâèëüíûé èíäåêñ äëÿ button3
		std::string optionText2 = mainMenu->AddOptionsInput(n2); // Ïîëó÷àåì òåêñò îïöèè äëÿ button3
		this->button3->Text = msclr::interop::marshal_as<System::String^>(optionText2); // Ïðåîáðàçóåì std::string â System::String^

		int n3 = this->button4->TabIndex + 1; // Èñïîëüçóåì ïðàâèëüíûé èíäåêñ äëÿ button4
		std::string optionText3 = mainMenu->AddOptionsInput(n3); // Ïîëó÷àåì òåêñò îïöèè äëÿ button4
		this->button4->Text = msclr::interop::marshal_as<System::String^>(optionText3); // Ïðåîáðàçóåì std::string â System::String^

		int n4 = this->button5->TabIndex + 1; // Èñïîëüçóåì ïðàâèëüíûé èíäåêñ äëÿ button5
		std::string optionText4 = mainMenu->AddOptionsInput(n4); // Ïîëó÷àåì òåêñò îïöèè äëÿ button5
		this->button5->Text = msclr::interop::marshal_as<System::String^>(optionText4); // Ïðåîáðàçóåì std::string â System::String^

		std::string optionText5 = mainMenu->WelcomeText();
		this->label2->Text = msclr::interop::marshal_as<System::String^>(optionText5);
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}