#pragma once

namespace Kurs2Work {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->axWindowsMediaPlayer2 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer2))->BeginInit();
			this->SuspendLayout();
			// 
			// axWindowsMediaPlayer2
			// 
			this->axWindowsMediaPlayer2->Enabled = true;
			this->axWindowsMediaPlayer2->Location = System::Drawing::Point(171, 44);
			this->axWindowsMediaPlayer2->Name = L"axWindowsMediaPlayer2";
			this->axWindowsMediaPlayer2->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer2.OcxState")));
			this->axWindowsMediaPlayer2->Size = System::Drawing::Size(187, 143);
			this->axWindowsMediaPlayer2->TabIndex = 0;
			this->axWindowsMediaPlayer2->Enter += gcnew System::EventHandler(this, &MyForm1::axWindowsMediaPlayer2_Enter_1);
			// 
			// MyForm1
			// 
			this->ClientSize = System::Drawing::Size(632, 370);
			this->Controls->Add(this->axWindowsMediaPlayer2);
			this->Name = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void axWindowsMediaPlayer2_Enter_1(System::Object^ sender, System::EventArgs^ e) {
		try {
			// ���������, ��� ���� ���������� �� ���������� ����
			axWindowsMediaPlayer2->URL = "C:\\Users\\User\\source\\repos\\�������.mp4"; // �������� �� ��� ����
			axWindowsMediaPlayer2->Ctlcontrols->play();
		}
		catch (Exception^ ex) {
			MessageBox::Show("������: " + ex->Message);
		}
	}
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
