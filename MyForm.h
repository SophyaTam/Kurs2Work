#pragma once
#include "MyForm1.h"

namespace Kurs2Work {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ SerialsOption;
	protected:

	private: System::Windows::Forms::Button^ Child_Option;
	private: System::Windows::Forms::Button^ Detective_Option;
	private: System::Windows::Forms::Button^ Comedy_Option;
	private: System::Windows::Forms::Button^ MelodramOption;


	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SerialsOption = (gcnew System::Windows::Forms::Button());
			this->Child_Option = (gcnew System::Windows::Forms::Button());
			this->Detective_Option = (gcnew System::Windows::Forms::Button());
			this->Comedy_Option = (gcnew System::Windows::Forms::Button());
			this->MelodramOption = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// SerialsOption
			// 
			this->SerialsOption->Location = System::Drawing::Point(320, 363);
			this->SerialsOption->Name = L"SerialsOption";
			this->SerialsOption->Size = System::Drawing::Size(75, 23);
			this->SerialsOption->TabIndex = 0;
			this->SerialsOption->Text = L"Сериалы";
			this->SerialsOption->UseVisualStyleBackColor = true;
			this->SerialsOption->Click += gcnew System::EventHandler(this, &MyForm::Serials_Click);
			// 
			// Child_Option
			// 
			this->Child_Option->Location = System::Drawing::Point(320, 110);
			this->Child_Option->Name = L"Child_Option";
			this->Child_Option->Size = System::Drawing::Size(75, 23);
			this->Child_Option->TabIndex = 1;
			this->Child_Option->Text = L"Детское";
			this->Child_Option->UseVisualStyleBackColor = true;
			this->Child_Option->Click += gcnew System::EventHandler(this, &MyForm::Child_Option_Click);
			// 
			// Detective_Option
			// 
			this->Detective_Option->Location = System::Drawing::Point(320, 168);
			this->Detective_Option->Name = L"Detective_Option";
			this->Detective_Option->Size = System::Drawing::Size(75, 23);
			this->Detective_Option->TabIndex = 2;
			this->Detective_Option->Text = L"Детективы";
			this->Detective_Option->UseVisualStyleBackColor = true;
			this->Detective_Option->Click += gcnew System::EventHandler(this, &MyForm::Detective_Option_Click);
			// 
			// Comedy_Option
			// 
			this->Comedy_Option->Location = System::Drawing::Point(320, 234);
			this->Comedy_Option->Name = L"Comedy_Option";
			this->Comedy_Option->Size = System::Drawing::Size(75, 23);
			this->Comedy_Option->TabIndex = 3;
			this->Comedy_Option->Text = L"Комедии";
			this->Comedy_Option->UseVisualStyleBackColor = true;
			this->Comedy_Option->Click += gcnew System::EventHandler(this, &MyForm::Comedy_Option_Click);
			// 
			// MelodramOption
			// 
			this->MelodramOption->Location = System::Drawing::Point(320, 303);
			this->MelodramOption->Name = L"MelodramOption";
			this->MelodramOption->Size = System::Drawing::Size(75, 23);
			this->MelodramOption->TabIndex = 4;
			this->MelodramOption->Text = L"Мелодрамы";
			this->MelodramOption->UseVisualStyleBackColor = true;
			this->MelodramOption->Click += gcnew System::EventHandler(this, &MyForm::MelodramOption_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(276, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(172, 16);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Доступные направления:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(738, 436);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MelodramOption);
			this->Controls->Add(this->Comedy_Option);
			this->Controls->Add(this->Detective_Option);
			this->Controls->Add(this->Child_Option);
			this->Controls->Add(this->SerialsOption);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Child_Option_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MyForm1^ obj3 = gcnew MyForm1();
		obj3->ShowDialog();
	}
	private: System::Void Detective_Option_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MyForm1^ obj3 = gcnew MyForm1();
		obj3->ShowDialog();
	}
	private: System::Void Comedy_Option_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MyForm1^ obj3 = gcnew MyForm1();
		obj3->ShowDialog();
	}
	private: System::Void MelodramOption_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MyForm1^ obj3 = gcnew MyForm1();
		obj3->ShowDialog();
	}
	private: System::Void Serials_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MyForm1^ obj3 = gcnew MyForm1();
		obj3->ShowDialog();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
