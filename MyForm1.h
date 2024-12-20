#pragma once

namespace Kurs2Work {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		Form ^obj;
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		MyForm1(Form ^obj1)
		{
			obj = obj1;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer1;
	private: AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer2;
	private: System::Windows::Forms::Button^ buttonStop;
	private: System::Windows::Forms::Button^ buttonAdvert;


	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::Button^ buttonNext;


	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ Volume;
	private: System::Windows::Forms::Label^ percent;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->axWindowsMediaPlayer2 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->buttonStop = (gcnew System::Windows::Forms::Button());
			this->buttonAdvert = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->buttonNext = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->Volume = (gcnew System::Windows::Forms::Label());
			this->percent = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// axWindowsMediaPlayer2
			// 
			this->axWindowsMediaPlayer2->Enabled = true;
			this->axWindowsMediaPlayer2->Location = System::Drawing::Point(2, 0);
			this->axWindowsMediaPlayer2->Name = L"axWindowsMediaPlayer2";
			this->axWindowsMediaPlayer2->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer2.OcxState")));
			this->axWindowsMediaPlayer2->Size = System::Drawing::Size(1043, 635);
			this->axWindowsMediaPlayer2->TabIndex = 0;
			this->axWindowsMediaPlayer2->Enter += gcnew System::EventHandler(this, &MyForm1::axWindowsMediaPlayer2_Enter_1);
			// 
			// buttonStop
			// 
			this->buttonStop->Location = System::Drawing::Point(1080, 41);
			this->buttonStop->Name = L"buttonStop";
			this->buttonStop->Size = System::Drawing::Size(75, 23);
			this->buttonStop->TabIndex = 1;
			this->buttonStop->Text = L"Стоп";
			this->buttonStop->UseVisualStyleBackColor = true;
			// 
			// buttonAdvert
			// 
			this->buttonAdvert->Location = System::Drawing::Point(1080, 87);
			this->buttonAdvert->Name = L"buttonAdvert";
			this->buttonAdvert->Size = System::Drawing::Size(75, 23);
			this->buttonAdvert->TabIndex = 2;
			this->buttonAdvert->Text = L"Реклама";
			this->buttonAdvert->UseVisualStyleBackColor = true;
			// 
			// buttonExit
			// 
			this->buttonExit->Location = System::Drawing::Point(1080, 595);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(75, 23);
			this->buttonExit->TabIndex = 3;
			this->buttonExit->Text = L"Назад";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm1::buttonExit_Click);
			// 
			// buttonNext
			// 
			this->buttonNext->Location = System::Drawing::Point(1080, 137);
			this->buttonNext->Name = L"buttonNext";
			this->buttonNext->Size = System::Drawing::Size(98, 23);
			this->buttonNext->TabIndex = 4;
			this->buttonNext->Text = L"Следующее";
			this->buttonNext->UseVisualStyleBackColor = true;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(1064, 215);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(104, 56);
			this->trackBar1->TabIndex = 5;
			// 
			// Volume
			// 
			this->Volume->AutoSize = true;
			this->Volume->Location = System::Drawing::Point(1077, 185);
			this->Volume->Name = L"Volume";
			this->Volume->Size = System::Drawing::Size(75, 16);
			this->Volume->TabIndex = 6;
			this->Volume->Text = L"Громкость";
			this->Volume->Click += gcnew System::EventHandler(this, &MyForm1::label1_Click);
			// 
			// percent
			// 
			this->percent->AutoSize = true;
			this->percent->Location = System::Drawing::Point(1089, 254);
			this->percent->Name = L"percent";
			this->percent->Size = System::Drawing::Size(26, 16);
			this->percent->TabIndex = 7;
			this->percent->Text = L"0%";
			// 
			// MyForm1
			// 
			this->ClientSize = System::Drawing::Size(1190, 639);
			this->Controls->Add(this->percent);
			this->Controls->Add(this->Volume);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->buttonNext);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonAdvert);
			this->Controls->Add(this->buttonStop);
			this->Controls->Add(this->axWindowsMediaPlayer2);
			this->Name = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void axWindowsMediaPlayer2_Enter_1(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Убедитесь, что файл существует по указанному пути
			axWindowsMediaPlayer2->URL = "C:\\Users\\User\\source\\repos\\Фиксики.mp4"; // Замените на ваш файл
			axWindowsMediaPlayer2->Ctlcontrols->play();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка: " + ex->Message);
		}
	}
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	obj->Show();
}
};
}
