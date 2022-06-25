#pragma once
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <map>

std::map<int, char> characters1 { {0,'À'}, {1,'Á'}, {2,'Â'}, {3,'Ã'}, {4,'Ä'}, {5,'Å'}, {6,'¨'}, {7,'Æ'}, {8,'Ç'}, {9,'È'},
	{10,'É'}, {11,'Ê'}, {12,'Ë'}, {13,'Ì'}, {14,'Í'}, {15,'Î'}, {16,'Ï'}, {17,'Ð'}, {18,'Ñ'},
	{19,'Ò'}, {20,'Ó'}, {21,'Ô'}, {22,'Õ'}, {23,'Ö'}, {24,'×'}, {25,'Ø'}, {26,'Ù'}, {27,'Ü'}, {28,'Û'}, {29,'Ú'},
	{30,'Ý'}, {31,'Þ'}, {32,'ß'} };
std::map<char, int> characters2 { {'À',0}, {'Á',1}, {'Â',2}, {'Ã',3}, {'Ä',4}, {'Å',5}, {'¨',6}, {'Æ',7}, {'Ç',8}, {'È',9},
	{'É',10}, {'Ê',11}, {'Ë',12}, {'Ì',13}, {'Í',14}, {'Î',15}, {'Ï',16}, {'Ð',17}, {'Ñ',18},
	{'Ò',19}, {'Ó',20}, {'Ô',21}, {'Õ',22}, {'Ö',23}, {'×',24}, {'Ø',25}, {'Ù',26}, {'Ú',27}, {'Û',28}, {'Ü',29},
	{'Ý',30}, {'Þ',31}, {'ß',32} };
int N = 33;
std::string alb = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß";


void MarshalString(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	s = s->ToUpper();
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}


class Vig {
public:
	std::string k;
	Vig(std::string k) {
		this->k = k;
	}
	std::string decryption(std::string t, int** matr) {
		std::string output;
		for (int i = 0, i1 = 0; i < t.length(); ++i) {
			int temp = std::count(alb.begin(), alb.end(), t[i]);
			if (std::count(alb.begin(), alb.end(), t[i])==0) { output += t[i]; continue; }
			int a = characters2[t[i]], b = characters2[k[i1]], j = 0;
			while (matr[j][b] != a) {
				j++;
			}
			output += characters1[j];
			i1++;
		}
		return output;
	}
};

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	protected:

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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(39, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(162, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Çàãðóçèòü";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button1_MouseClick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(41, 293);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(162, 36);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Ñîõðàíèòü";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button2_MouseClick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(441, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(144, 20);
			this->textBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(382, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Êëþ÷";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(41, 90);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(160, 185);
			this->textBox2->TabIndex = 5;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(409, 293);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(176, 36);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Ðàñøèôðîâàòü";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(409, 90);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(176, 185);
			this->textBox3->TabIndex = 7;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Çàøèôðîâàííûé òåêñò:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(406, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Èñõîäíûé òåêñò:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(647, 351);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		openFileDialog1->ShowDialog();
		System::String^ path_f = openFileDialog1->FileName;
		try
		{
			StreamReader^ DataIn = File::OpenText(path_f);
			String^ DataStr;
			int count = 0;
			while ((DataStr = DataIn->ReadLine()) != nullptr)
			{
				count++;
				textBox2->Text += DataStr + Environment::NewLine;
			}
		}
		catch (Exception^ e)
		{
			if (dynamic_cast<FileNotFoundException^>(e))
				MessageBox::Show("File " + path_f + " not found");
		}
		}
	private: System::Void button2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		saveFileDialog1->ShowDialog();
		System::String^ path_f = saveFileDialog1->FileName;
		StreamWriter^ outFile = gcnew StreamWriter(path_f);
		outFile->WriteLine(textBox3->Text);
		outFile->Close();
	}
    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
	private: std::string GetRepeatKey(std::string s, int n)
	{
			   std::string p = s;
			   while (p.length() < n)
			   {
				   p += p;
			   }

			   return p.substr(0, n);
		   }
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string key, encrypt;
	MarshalString(textBox1->Text, key);
	MarshalString(textBox2->Text, encrypt);


	int** matrix = new int* [N];
	for (int i = 0; i < N; i++) matrix[i] = new int[N];
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			while ((i + j - N * k) >= N) k++;
			matrix[i][j] = i + j - N * k;
			k = 0;
		}
	}
	key = GetRepeatKey(key, encrypt.length());
	Vig v(key);
	textBox3->Text = gcnew String(v.decryption(encrypt, matrix).c_str());
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
