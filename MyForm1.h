﻿#pragma once
#include "Video.h"
#include <comdef.h>
#include "Voice.h"
#include <string>
#include <msclr/marshal_cppstd.h>

namespace Kurs2Work {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	private:
		Video* video; // Указатель на класс Video
		Voice* voice; // Указатель на класс Voice

	public:
		Form^ obj;

		MyForm1(void)
		{
			InitializeComponent();
			
			video = new Video(); // Передаем AxWindowsMediaPlayer в Video
			voice = new Voice(); // Передаем AxWindowsMediaPlayer в Voice
		}

		MyForm1(Form^ obj1)
		{
			obj = obj1;
			InitializeComponent();

			// Инициализация объектов Video и Voice
			video = new Video(); // Передаем AxWindowsMediaPlayer в Video
			voice = new Voice(); // Передаем AxWindowsMediaPlayer в Voice
		}

	protected:
		~MyForm1()
		{
			if (components)
			{
				delete video;
				delete voice;
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
		/// Îáÿçàòåëüíàÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òðåáóåìûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà — íå èçìåíÿéòå 
		/// ñîäåðæèìîå ýòîãî ìåòîäà ñ ïîìîùüþ ðåäàêòîðà êîäà.
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
			this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm1::buttonExit_Click_1);
			// 
			// buttonNext
			// 
			this->buttonNext->Location = System::Drawing::Point(1080, 137);
			this->buttonNext->Name = L"buttonNext";
			this->buttonNext->Size = System::Drawing::Size(98, 23);
			this->buttonNext->TabIndex = 4;
			this->buttonNext->Text = L"Следующий";
			this->buttonNext->UseVisualStyleBackColor = true;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(1064, 215);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(104, 56);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm1::trackBar1_Scroll);
			// 
			// Volume
			// 
			this->Volume->AutoSize = true;
			this->Volume->Location = System::Drawing::Point(1077, 185);
			this->Volume->Name = L"Volume";
			this->Volume->Size = System::Drawing::Size(39, 16);
			this->Volume->TabIndex = 6;
			this->Volume->Text = L"Звук";
			// 
			// percent
			// 
			this->percent->AutoSize = true;
			this->percent->Location = System::Drawing::Point(1089, 254);
			this->percent->Name = L"percent";
			this->percent->Size = System::Drawing::Size(26, 16);
			this->percent->TabIndex = 7;
			this->percent->Text = L"0%";
			this->percent->Click += gcnew System::EventHandler(this, &MyForm1::percent_Click);
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
	std::string videoFile = video->ChooseOption(1); // Выбор файла для воспроизведения

	// Проверяем, что videoFile не пустой
	if (videoFile.empty()) {
		MessageBoxA(NULL, "Не удалось выбрать видеофайл.", "Ошибка", MB_OK);
		return; // Выходим из функции, если видеофайл не найден
	}

	System::String^ managedVideoFile = gcnew System::String(videoFile.c_str());
	try {
		axWindowsMediaPlayer2->URL = managedVideoFile; // Устанавливаем URL
		axWindowsMediaPlayer2->Ctlcontrols->play(); // Запускаем воспроизведение
	}
	catch (System::Exception^ e) {
		// Обработка исключения
		MessageBox::Show("Ошибка при установке URL: " + e->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		axWindowsMediaPlayer2->settings->volume = voice->ChangeVoice(54);
	}

	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		// Получаем текущее значение TrackBar
		int value = trackBar1->Value;
		// Обновляем текст Label
		percent->Text = value.ToString() + "%";
		axWindowsMediaPlayer2->settings->volume = voice->ChangeVoice(trackBar1->Value);
	}
private: System::Void percent_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonExit_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	obj->Show();
}
};
}