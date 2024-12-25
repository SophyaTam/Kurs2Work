#pragma once
#include "Video.h"
#include <comdef.h>
#include "Voice.h"
#include "Advert.h"
#include <string>
#include "Stop.h"
#include <msclr/marshal_cppstd.h>
#include "Global.h"
#include <Windows.h>
#include <msclr/marshal.h> // Для использования Marshal

using namespace WMPLib;

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
		Stop* stop;   // Указатель на класс Stop
		Advert* advert; // Указатель на класс Advert
		int flag; // Флаг для управления рекламой
		int timerflag;
		int progressClick = 0;
		int stopBut = 0;
		bool isAdPlaying; // Флаг для отслеживания воспроизведения рекламы
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ labelStart;
	private: System::Windows::Forms::Label^ labelStop;
	private: System::Windows::Forms::Button^ button_Progress;


	public:
		Form^ obj; // Ссылка на родительскую форму

		MyForm1(void)
		{
			InitializeComponent();
			video = new Video(); // Инициализация объекта Video
			voice = new Voice(); // Инициализация объекта Voice
			stop = new Stop();   // Инициализация объекта Stop
			advert = new Advert(); // Инициализация объекта Advert
			flag = 0; // Изначально флаг рекламы выключен
			isAdPlaying = false; // Изначально реклама не воспроизводится
			this->buttonAdvert->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
		}

		MyForm1(Form^ obj1)
		{
			obj = obj1;
			InitializeComponent();
			video = new Video(); // Инициализация объекта Video
			voice = new Voice(); // Инициализация объекта Voice
			stop = new Stop();   // Инициализация объекта Stop
			advert = new Advert(); // Инициализация объекта Advert
			flag = 0; // Изначально флаг рекламы выключен
			isAdPlaying = false; // Изначально реклама не воспроизводится
			this->buttonAdvert->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
		}

		~MyForm1()
		{
			if (components)
			{
				delete components; // Освобождаем компоненты
			}
			delete video; // Освобождаем память
			delete voice; // Освобождаем память
			delete stop;  // Освобождаем память
			delete advert; // Освобождаем память
		}

	private: AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer2;
	private: System::Windows::Forms::Button^ buttonStop;
	private: System::Windows::Forms::Button^ buttonAdvert;
	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::Button^ buttonNext;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ Volume;
	private: System::Windows::Forms::Label^ percent;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ timer1;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			   this->axWindowsMediaPlayer2 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			   this->buttonStop = (gcnew System::Windows::Forms::Button());
			   this->buttonAdvert = (gcnew System::Windows::Forms::Button());
			   this->buttonExit = (gcnew System::Windows::Forms::Button());
			   this->buttonNext = (gcnew System::Windows::Forms::Button());
			   this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			   this->Volume = (gcnew System::Windows::Forms::Label());
			   this->percent = (gcnew System::Windows::Forms::Label());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			   this->labelStart = (gcnew System::Windows::Forms::Label());
			   this->labelStop = (gcnew System::Windows::Forms::Label());
			   this->button_Progress = (gcnew System::Windows::Forms::Button());
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
			   this->axWindowsMediaPlayer2->Enter += gcnew System::EventHandler(this, &MyForm1::axWindowsMediaPlayer2_Click_1);
			   // 
			   // buttonStop
			   // 
			   this->buttonStop->Location = System::Drawing::Point(1080, 41);
			   this->buttonStop->Name = L"buttonStop";
			   this->buttonStop->Size = System::Drawing::Size(75, 23);
			   this->buttonStop->TabIndex = 1;
			   this->buttonStop->Text = L"Стоп";
			   this->buttonStop->UseVisualStyleBackColor = true;
			   this->buttonStop->Click += gcnew System::EventHandler(this, &MyForm1::buttonStop_Click);
			   // 
			   // buttonAdvert
			   // 
			   this->buttonAdvert->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				   static_cast<System::Int32>(static_cast<System::Byte>(192)));
			   this->buttonAdvert->Location = System::Drawing::Point(1080, 87);
			   this->buttonAdvert->Name = L"buttonAdvert";
			   this->buttonAdvert->Size = System::Drawing::Size(75, 23);
			   this->buttonAdvert->TabIndex = 2;
			   this->buttonAdvert->Text = L"Реклама";
			   this->buttonAdvert->UseVisualStyleBackColor = false;
			   this->buttonAdvert->Click += gcnew System::EventHandler(this, &MyForm1::buttonAdvert_Click);
			   // 
			   // buttonExit
			   // 
			   this->buttonExit->Location = System::Drawing::Point(1103, 604);
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
			   this->buttonNext->Click += gcnew System::EventHandler(this, &MyForm1::buttonNext_Click);
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
			   // timer1
			   // 
			   this->timer1->Interval = 500;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm1::timer1_Tick);
			   // 
			   // progressBar1
			   // 
			   this->progressBar1->Cursor = System::Windows::Forms::Cursors::Default;
			   this->progressBar1->Location = System::Drawing::Point(34, 625);
			   this->progressBar1->Name = L"progressBar1";
			   this->progressBar1->Size = System::Drawing::Size(982, 10);
			   this->progressBar1->TabIndex = 8;
			   this->progressBar1->Visible = false;
			   this->progressBar1->Click += gcnew System::EventHandler(this, &MyForm1::progressBar1_Click);
			   // 
			   // labelStart
			   // 
			   this->labelStart->AutoSize = true;
			   this->labelStart->Location = System::Drawing::Point(-1, 619);
			   this->labelStart->Name = L"labelStart";
			   this->labelStart->Size = System::Drawing::Size(44, 16);
			   this->labelStart->TabIndex = 9;
			   this->labelStart->Text = L"label1";
			   this->labelStart->Visible = false;
			   // 
			   // labelStop
			   // 
			   this->labelStop->AutoSize = true;
			   this->labelStop->Location = System::Drawing::Point(1012, 619);
			   this->labelStop->Name = L"labelStop";
			   this->labelStop->Size = System::Drawing::Size(44, 16);
			   this->labelStop->TabIndex = 10;
			   this->labelStop->Text = L"label1";
			   this->labelStop->Visible = false;
			   this->labelStop->Click += gcnew System::EventHandler(this, &MyForm1::labelStop_Click);
			   // 
			   // button_Progress
			   // 
			   this->button_Progress->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->button_Progress->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			   this->button_Progress->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->button_Progress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button_Progress->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				   static_cast<System::Int32>(static_cast<System::Byte>(192)));
			   this->button_Progress->Location = System::Drawing::Point(996, 579);
			   this->button_Progress->Name = L"button_Progress";
			   this->button_Progress->Size = System::Drawing::Size(49, 37);
			   this->button_Progress->TabIndex = 11;
			   this->button_Progress->Text = L">";
			   this->button_Progress->UseVisualStyleBackColor = false;
			   this->button_Progress->Click += gcnew System::EventHandler(this, &MyForm1::button_Progress_Click);
			   // 
			   // MyForm1
			   // 
			   this->ClientSize = System::Drawing::Size(1190, 639);
			   this->Controls->Add(this->button_Progress);
			   this->Controls->Add(this->labelStop);
			   this->Controls->Add(this->labelStart);
			   this->Controls->Add(this->progressBar1);
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
	private: System::Void axWindowsMediaPlayer2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {

		if (video == nullptr) {
			MessageBoxA(NULL, "video не инициализирован.", "Ошибка", MB_OK);
			return;
		}

		video->ChooseOption(globalOption);
		std::string videoFile = video->chooseRandomVideo();

		if (videoFile.empty()) {
			MessageBoxA(NULL, "Не удалось выбрать видеофайл.", "Ошибка", MB_OK);
			return;
		}

		System::String^ managedVideoFile = gcnew System::String(videoFile.c_str());

		if (axWindowsMediaPlayer2 == nullptr) {
			MessageBoxA(NULL, "axWindowsMediaPlayer2 не инициализирован.", "Ошибка", MB_OK);
			return;
		}

		try {
			axWindowsMediaPlayer2->URL = managedVideoFile;
			if (axWindowsMediaPlayer2->Ctlcontrols != nullptr) {
				axWindowsMediaPlayer2->Ctlcontrols->play();
			}
			else {
				MessageBoxA(NULL, "Ctlcontrols не инициализирован.", "Ошибка", MB_OK);
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Произошла ошибка: " << e.what() << std::endl;
			MessageBoxA(NULL, "Произошла ошибка при установке URL.", "Ошибка", MB_OK);
		}
		axWindowsMediaPlayer2->settings->volume = voice->ChangeVoice(54);
		trackBar1->Value = 54;
		percent->Text = "54%";
		isAdPlaying = true;
		timer1->Start();
	}

		   void ProgressBarLoad() {
			   // Устанавливаем начальное время в LabelStart
			   labelStart->Text = "00:00";

			   // Проверяем, что текущая медиа существует
			   if (axWindowsMediaPlayer2->currentMedia != nullptr) {
				   // Получаем длительность видео
				   double duration = axWindowsMediaPlayer2->currentMedia->duration;

				   // Проверяем, что длительность больше нуля
				   if (duration > 0) {
					   int minutes = static_cast<int>(duration) / 60; // Получаем минуты
					   int seconds = static_cast<int>(duration) % 60; // Получаем секунды

					   // Форматируем строку для LabelStop
					   System::String^ durationString = System::String::Format("{0:D2}:{1:D2}", minutes, seconds);
					   labelStop->Text = durationString;

					   // Устанавливаем максимальное значение прогресс-бара
					   progressBar1->Maximum = static_cast<int>(duration);
					   progressBar1->Value = 0; // Начальное значение прогресс-бара

					   // Запускаем таймер для обновления прогресс-бара
					   timer1->Start(); // Предполагается, что у вас есть таймер, который будет обновлять прогресс
				   }
				   else {
					   labelStop->Text = "00:00"; // Если длительность не определена, устанавливаем текст по умолчанию
					   progressBar1->Value = 0; // Устанавливаем значение прогресс-бара в 0
				   }
			   }
			   else {
				   labelStop->Text = "00:00"; // Если текущая медиа не установлена, устанавливаем текст по умолчанию
				   progressBar1->Value = 0; // Устанавливаем значение прогресс-бара в 0
			   }
		   }

		   // Обработчик таймера для обновления прогресс-бара

	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		// Получаем текущее значение TrackBar
		int value = trackBar1->Value;
		// Обновляем текст Label
		percent->Text = value.ToString() + "%";
		axWindowsMediaPlayer2->settings->volume = voice->ChangeVoice(trackBar1->Value);
	}
	private: System::Void percent_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonNext_Click(System::Object^ sender, System::EventArgs^ e) {
		this->progressBar1->Visible = false;
		this->labelStart->Visible = false;
		this->labelStop->Visible = false;
		ProgressBarLoad();
		button_Progress->Text = ">";
		progressClick = 0;

		timerflag = 1;
		if (flag == 1 ) {
			StartVideoWithTimer();
		}
		else {
			PlaySecondVideo();
		}
	}
		   void StartVideoWithTimer() {
			   advert->ChooseOption();
			   std::string videoFile = advert->chooseRandomVideo();

			   if (videoFile.empty()) {
				   MessageBoxA(NULL, "Не удалось выбрать рекламу.", "Ошибка", MB_OK);
				   return;
			   }

			   System::String^ managedVideoFile = gcnew System::String(videoFile.c_str());

			   if (axWindowsMediaPlayer2 == nullptr) {
				   MessageBoxA(NULL, "axWindowsMediaPlayer2 не инициализирован.", "Ошибка", MB_OK);
				   return;
			   }

			   try {
				   axWindowsMediaPlayer2->URL = managedVideoFile;
				   if (axWindowsMediaPlayer2->Ctlcontrols != nullptr) {
					   axWindowsMediaPlayer2->Ctlcontrols->play();
					   isAdPlaying = true;

					   // Запускаем таймер
					   timer1->Start();
					   MessageBoxA(NULL, "Таймер запустился.", "Информация", MB_OK);
				   }
				   else {
					   MessageBoxA(NULL, "Ctlcontrols не инициализирован.", "Ошибка", MB_OK);
				   }
			   }
			   catch (const std::exception& e) {
				   MessageBoxA(NULL, "Произошла ошибка при установке URL.", "Ошибка", MB_OK);
			   }
		   }

private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	// Проверяем, что текущая медиа существует и воспроизводится
	if (axWindowsMediaPlayer2->currentMedia != nullptr) {
		double currentPosition = axWindowsMediaPlayer2->Ctlcontrols->currentPosition;
		progressBar1->Value = static_cast<int>(currentPosition);

		int minutes = static_cast<int>(currentPosition) / 60;
		int seconds = static_cast<int>(currentPosition) % 60;
		labelStart->Text = System::String::Format("{0:D2}:{1:D2}", minutes, seconds);

		if (isAdPlaying) {

			// Получаем длительность видео
			double duration = axWindowsMediaPlayer2->currentMedia->duration;

			// Проверяем, что длительность больше нуля
			if (duration > 0) {
				// Проверяем, достигло ли текущее время длительности видео
				if (currentPosition >= duration) {
					axWindowsMediaPlayer2->Ctlcontrols->stop();
					timer1->Stop();
					isAdPlaying = false;

					// Запускаем следующее видео
					PlaySecondVideo();
				}
			}
		}
	}
}
private: void PlaySecondVideo() {
	this->progressBar1->Visible = false;
	this->labelStart->Visible = false;
	this->labelStop->Visible = false;
	ProgressBarLoad();
	// Здесь вы можете указать путь к вашему второму видео
	std::string videoFile = video->chooseRandomVideo(); // Предполагается, что video - это объект, который выбирает второе видео

	if (videoFile.empty()) {
		MessageBoxA(NULL, "Не удалось выбрать второе видео.", "Ошибка", MB_OK);
		return;
	}

	System::String^ secondVideoFile = gcnew System::String(videoFile.c_str());

	if (axWindowsMediaPlayer2 != nullptr) {
		try {
			axWindowsMediaPlayer2->URL = secondVideoFile; // Устанавливаем URL второго видео
			if (axWindowsMediaPlayer2->Ctlcontrols != nullptr) {
				axWindowsMediaPlayer2->Ctlcontrols->play(); // Запускаем воспроизведение второго видео
			}
			else {
				MessageBoxA(NULL, "Ctlcontrols не инициализирован.", "Ошибка", MB_OK);
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Произошла ошибка: " << e.what() << std::endl;
			MessageBoxA(NULL, "Произошла ошибка при установке URL второго видео.", "Ошибка", MB_OK);
		}
	}
	else {
		MessageBoxA(NULL, "axWindowsMediaPlayer2 не инициализирован.", "Ошибка", MB_OK);
	}
	isAdPlaying = true;
	timer1->Start();
}
	private: System::Void buttonAdvert_Click(System::Object^ sender, System::EventArgs^ e) {
		if (flag == 0) { // Используем оператор сравнения
			flag = 1;
			this->buttonAdvert->BackColor = System::Drawing::Color::FromArgb(192, 255, 192); // Светло-зеленый
		}
		else {
			flag = 0; // Изменяем на 0, чтобы переключать обратно
			this->buttonAdvert->BackColor = System::Drawing::Color::FromArgb(255, 192, 192); // Светло-красный
		}
		// Обновление интерфейса (если необходимо)
		this->Invalidate(); // Или this->Refresh();
	}
	private: System::Void buttonStop_Click(System::Object^ sender, System::EventArgs^ e) {
		if (stopBut == 0)
		{
			stop->ButtonStop(axWindowsMediaPlayer2);
			buttonStop->Text = "Старт";
			stopBut = 1;
		}
		else {
			stop->ButtonStop(axWindowsMediaPlayer2);
			buttonStop->Text = "Стоп";
			stopBut = 0;
		}
	}
		   private: System::Void buttonExit_Click_1(System::Object^ sender, System::EventArgs^ e) {
			   this->Hide();
			   obj->Show();
		   }
private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Получаем текущее положение курсора на ProgressBar
	int mouseX = System::Windows::Forms::Cursor::Position.X - progressBar1->Location.X - this->Location.X;
	int progressBarWidth = progressBar1->Width;

	// Вычисляем новое значение для прогресс-бара
	if (mouseX >= 0 && mouseX <= progressBarWidth) {
		int newValue = static_cast<int>((static_cast<double>(mouseX) / progressBarWidth) * progressBar1->Maximum);
		progressBar1->Value = newValue;

		// Устанавливаем новую позицию воспроизведения в axWindowsMediaPlayer2
		if (axWindowsMediaPlayer2->currentMedia != nullptr) {
			double duration = axWindowsMediaPlayer2->currentMedia->duration;
			double newPosition = (newValue / static_cast<double>(progressBar1->Maximum)) * duration;
			axWindowsMediaPlayer2->Ctlcontrols->currentPosition = newPosition;
		}
	}
}
private: System::Void labelStop_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_Progress_Click(System::Object^ sender, System::EventArgs^ e) {
	if (progressClick == 0)
	{
		this->progressBar1->Visible = true;
		this->labelStart->Visible = true;
		this->labelStop->Visible = true;
		ProgressBarLoad();
		button_Progress->Text = "<";
		progressClick = 1;
	}
	else {
		this->progressBar1->Visible = false;
		this->labelStart->Visible = false;
		this->labelStop->Visible = false;
		ProgressBarLoad();
		button_Progress->Text = ">";
		progressClick = 0;
	}
}
};
}