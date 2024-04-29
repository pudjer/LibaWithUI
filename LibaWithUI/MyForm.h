#pragma once
#include "BookRepository.h"
#include "GenreRepository.h"
#include "ClientRepository.h"
#include "BookLoanRepository.h"
#include <Windows.h> // Для использования нативных типов Windows
#include <vcclr.h>
#include "GetDb.h"
#include <msclr\marshal_cppstd.h>
#include "Exceptions.h"
#include <regex>
using namespace Repositories;

namespace LibaWithUI {


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
	private: 
		sqlite3* db;
		BookRepository* bookRepo;
		GenreRepository* genreRepo;
		ClientRepository* clientRepo;
	private: System::Windows::Forms::Panel^ GenrePanel;
	private: System::Windows::Forms::Button^ AddGenre;
	private: System::Windows::Forms::Button^ RefreshGenres;
	private: System::Windows::Forms::Label^ GenreDescription;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ GenreList;
	private: System::Windows::Forms::Label^ SelectedGenre;
	private: System::Windows::Forms::Panel^ AddGenrePanel;
	private: System::Windows::Forms::Button^ SaveGenreButton;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ GenreDescriptionForSave;

	private: System::Windows::Forms::TextBox^ GenreNameForSave;
	private: System::Windows::Forms::Button^ UpdateGenreButton;
	private: System::Windows::Forms::Button^ DeleteGenreButton;
	private: System::Windows::Forms::Button^ BookMenuButton;
	private: System::Windows::Forms::Panel^ BookPanel;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ListBox^ BookList;
	private: System::Windows::Forms::TextBox^ BookAuthor;
	private: System::Windows::Forms::TextBox^ BookTitle;
	private: System::Windows::Forms::Label^ BookIdLable;
	private: System::Windows::Forms::TextBox^ BookCount;
	private: System::Windows::Forms::TextBox^ BookYear;
	private: System::Windows::Forms::Button^ DeleteBookButton;

	private: System::Windows::Forms::Button^ AddBookButton;
	private: System::Windows::Forms::Button^ SaveBookButton;
	private: System::Windows::Forms::Button^ RefreshBooksButton;
	private: System::Windows::Forms::Label^ BookSaveTypeLable;
	private: System::Windows::Forms::CheckedListBox^ BooksGenreList;
	private: System::Windows::Forms::Button^ ClientsMenuButton;
	private: System::Windows::Forms::Panel^ ClientPanel;
	private: System::Windows::Forms::TextBox^ PassportNumberTextBox;

	private: System::Windows::Forms::TextBox^ LastNameTextBox;
	private: System::Windows::Forms::TextBox^ MiddleNameTextBox;


	private: System::Windows::Forms::TextBox^ FirstNameTextBox;
	private: System::Windows::Forms::TextBox^ DateOfBirthTextBox;



	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ DeleteClientButton;

	private: System::Windows::Forms::Button^ AddClientButton;

	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::ListBox^ ClientList;

	private: System::Windows::Forms::Label^ ClientIdLable;
	private: System::Windows::Forms::Button^ SaveClientButton;
	private: System::Windows::Forms::Button^ RefreshClientsButton;
	private: System::Windows::Forms::Label^ ClientSaveType;
	private: System::Windows::Forms::TextBox^ AddressTextBox;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;









		   BookLoanRepository* bookLoanRepo;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			db = DB::getDb();
			bookRepo = new BookRepository(db);
			genreRepo = new GenreRepository(db);
			clientRepo = new ClientRepository(db);
			bookLoanRepo = new BookLoanRepository(db);
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
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ GenresMenuButton;
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
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->GenresMenuButton = (gcnew System::Windows::Forms::Button());
			this->BookMenuButton = (gcnew System::Windows::Forms::Button());
			this->ClientsMenuButton = (gcnew System::Windows::Forms::Button());
			this->GenrePanel = (gcnew System::Windows::Forms::Panel());
			this->DeleteGenreButton = (gcnew System::Windows::Forms::Button());
			this->UpdateGenreButton = (gcnew System::Windows::Forms::Button());
			this->AddGenre = (gcnew System::Windows::Forms::Button());
			this->RefreshGenres = (gcnew System::Windows::Forms::Button());
			this->GenreDescription = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->GenreList = (gcnew System::Windows::Forms::ListBox());
			this->SelectedGenre = (gcnew System::Windows::Forms::Label());
			this->AddGenrePanel = (gcnew System::Windows::Forms::Panel());
			this->SaveGenreButton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->GenreDescriptionForSave = (gcnew System::Windows::Forms::TextBox());
			this->GenreNameForSave = (gcnew System::Windows::Forms::TextBox());
			this->BookPanel = (gcnew System::Windows::Forms::Panel());
			this->BooksGenreList = (gcnew System::Windows::Forms::CheckedListBox());
			this->BookSaveTypeLable = (gcnew System::Windows::Forms::Label());
			this->RefreshBooksButton = (gcnew System::Windows::Forms::Button());
			this->SaveBookButton = (gcnew System::Windows::Forms::Button());
			this->DeleteBookButton = (gcnew System::Windows::Forms::Button());
			this->AddBookButton = (gcnew System::Windows::Forms::Button());
			this->BookCount = (gcnew System::Windows::Forms::TextBox());
			this->BookYear = (gcnew System::Windows::Forms::TextBox());
			this->BookAuthor = (gcnew System::Windows::Forms::TextBox());
			this->BookTitle = (gcnew System::Windows::Forms::TextBox());
			this->BookIdLable = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->BookList = (gcnew System::Windows::Forms::ListBox());
			this->ClientPanel = (gcnew System::Windows::Forms::Panel());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->AddressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ClientSaveType = (gcnew System::Windows::Forms::Label());
			this->RefreshClientsButton = (gcnew System::Windows::Forms::Button());
			this->SaveClientButton = (gcnew System::Windows::Forms::Button());
			this->ClientIdLable = (gcnew System::Windows::Forms::Label());
			this->DeleteClientButton = (gcnew System::Windows::Forms::Button());
			this->AddClientButton = (gcnew System::Windows::Forms::Button());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->ClientList = (gcnew System::Windows::Forms::ListBox());
			this->PassportNumberTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LastNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MiddleNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FirstNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DateOfBirthTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1->SuspendLayout();
			this->GenrePanel->SuspendLayout();
			this->AddGenrePanel->SuspendLayout();
			this->BookPanel->SuspendLayout();
			this->ClientPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->GenresMenuButton);
			this->flowLayoutPanel1->Controls->Add(this->BookMenuButton);
			this->flowLayoutPanel1->Controls->Add(this->ClientsMenuButton);
			this->flowLayoutPanel1->Location = System::Drawing::Point(6, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(927, 75);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// GenresMenuButton
			// 
			this->GenresMenuButton->Location = System::Drawing::Point(3, 3);
			this->GenresMenuButton->Name = L"GenresMenuButton";
			this->GenresMenuButton->Size = System::Drawing::Size(218, 72);
			this->GenresMenuButton->TabIndex = 0;
			this->GenresMenuButton->Text = L"Жанры";
			this->GenresMenuButton->UseVisualStyleBackColor = true;
			this->GenresMenuButton->Click += gcnew System::EventHandler(this, &MyForm::GenresMenuButton_Click);
			// 
			// BookMenuButton
			// 
			this->BookMenuButton->Location = System::Drawing::Point(227, 3);
			this->BookMenuButton->Name = L"BookMenuButton";
			this->BookMenuButton->Size = System::Drawing::Size(203, 72);
			this->BookMenuButton->TabIndex = 1;
			this->BookMenuButton->Text = L"Книги";
			this->BookMenuButton->UseVisualStyleBackColor = true;
			this->BookMenuButton->Click += gcnew System::EventHandler(this, &MyForm::BookMenuButton_Click);
			// 
			// ClientsMenuButton
			// 
			this->ClientsMenuButton->Location = System::Drawing::Point(436, 3);
			this->ClientsMenuButton->Name = L"ClientsMenuButton";
			this->ClientsMenuButton->Size = System::Drawing::Size(221, 70);
			this->ClientsMenuButton->TabIndex = 2;
			this->ClientsMenuButton->Text = L"Читатели";
			this->ClientsMenuButton->UseVisualStyleBackColor = true;
			this->ClientsMenuButton->Click += gcnew System::EventHandler(this, &MyForm::ClientsMenuButton_Click);
			// 
			// GenrePanel
			// 
			this->GenrePanel->Controls->Add(this->DeleteGenreButton);
			this->GenrePanel->Controls->Add(this->UpdateGenreButton);
			this->GenrePanel->Controls->Add(this->AddGenre);
			this->GenrePanel->Controls->Add(this->RefreshGenres);
			this->GenrePanel->Controls->Add(this->GenreDescription);
			this->GenrePanel->Controls->Add(this->label2);
			this->GenrePanel->Controls->Add(this->label1);
			this->GenrePanel->Controls->Add(this->GenreList);
			this->GenrePanel->Controls->Add(this->SelectedGenre);
			this->GenrePanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GenrePanel->Location = System::Drawing::Point(78, 101);
			this->GenrePanel->Name = L"GenrePanel";
			this->GenrePanel->Size = System::Drawing::Size(843, 745);
			this->GenrePanel->TabIndex = 2;
			// 
			// DeleteGenreButton
			// 
			this->DeleteGenreButton->BackColor = System::Drawing::Color::Red;
			this->DeleteGenreButton->Location = System::Drawing::Point(63, 704);
			this->DeleteGenreButton->Name = L"DeleteGenreButton";
			this->DeleteGenreButton->Size = System::Drawing::Size(126, 39);
			this->DeleteGenreButton->TabIndex = 10;
			this->DeleteGenreButton->Text = L"Удалить";
			this->DeleteGenreButton->UseVisualStyleBackColor = false;
			this->DeleteGenreButton->Click += gcnew System::EventHandler(this, &MyForm::DeleteGenreButton_Click);
			// 
			// UpdateGenreButton
			// 
			this->UpdateGenreButton->Location = System::Drawing::Point(121, 677);
			this->UpdateGenreButton->Name = L"UpdateGenreButton";
			this->UpdateGenreButton->Size = System::Drawing::Size(113, 27);
			this->UpdateGenreButton->TabIndex = 9;
			this->UpdateGenreButton->Text = L"Изменить";
			this->UpdateGenreButton->UseVisualStyleBackColor = true;
			this->UpdateGenreButton->Click += gcnew System::EventHandler(this, &MyForm::UpdateGenreButton_Click);
			// 
			// AddGenre
			// 
			this->AddGenre->Location = System::Drawing::Point(16, 677);
			this->AddGenre->Name = L"AddGenre";
			this->AddGenre->Size = System::Drawing::Size(107, 27);
			this->AddGenre->TabIndex = 8;
			this->AddGenre->Text = L"Добавить";
			this->AddGenre->UseVisualStyleBackColor = true;
			this->AddGenre->Click += gcnew System::EventHandler(this, &MyForm::AddGenre_Click);
			// 
			// RefreshGenres
			// 
			this->RefreshGenres->Location = System::Drawing::Point(121, 140);
			this->RefreshGenres->Name = L"RefreshGenres";
			this->RefreshGenres->Size = System::Drawing::Size(115, 27);
			this->RefreshGenres->TabIndex = 7;
			this->RefreshGenres->Text = L"Обновить";
			this->RefreshGenres->UseVisualStyleBackColor = true;
			this->RefreshGenres->Click += gcnew System::EventHandler(this, &MyForm::RefreshGenres_Click);
			// 
			// GenreDescription
			// 
			this->GenreDescription->AutoSize = true;
			this->GenreDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->GenreDescription->Location = System::Drawing::Point(250, 177);
			this->GenreDescription->Name = L"GenreDescription";
			this->GenreDescription->Size = System::Drawing::Size(0, 31);
			this->GenreDescription->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(250, 129);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(149, 33);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Описание";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(13, 133);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 31);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Жанры";
			// 
			// GenreList
			// 
			this->GenreList->FormattingEnabled = true;
			this->GenreList->ItemHeight = 18;
			this->GenreList->Location = System::Drawing::Point(16, 172);
			this->GenreList->Name = L"GenreList";
			this->GenreList->Size = System::Drawing::Size(218, 508);
			this->GenreList->TabIndex = 1;
			this->GenreList->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::GenreList_SelectedIndexChanged);
			this->GenreList->Leave += gcnew System::EventHandler(this, &MyForm::GenreList_Leave);
			// 
			// SelectedGenre
			// 
			this->SelectedGenre->AutoSize = true;
			this->SelectedGenre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SelectedGenre->Location = System::Drawing::Point(49, 28);
			this->SelectedGenre->Name = L"SelectedGenre";
			this->SelectedGenre->Size = System::Drawing::Size(501, 73);
			this->SelectedGenre->TabIndex = 0;
			this->SelectedGenre->Text = L"Выберите жанр";
			// 
			// AddGenrePanel
			// 
			this->AddGenrePanel->Controls->Add(this->SaveGenreButton);
			this->AddGenrePanel->Controls->Add(this->label4);
			this->AddGenrePanel->Controls->Add(this->label3);
			this->AddGenrePanel->Controls->Add(this->GenreDescriptionForSave);
			this->AddGenrePanel->Controls->Add(this->GenreNameForSave);
			this->AddGenrePanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddGenrePanel->Location = System::Drawing::Point(100, 82);
			this->AddGenrePanel->Name = L"AddGenrePanel";
			this->AddGenrePanel->Size = System::Drawing::Size(824, 745);
			this->AddGenrePanel->TabIndex = 3;
			// 
			// SaveGenreButton
			// 
			this->SaveGenreButton->Location = System::Drawing::Point(284, 661);
			this->SaveGenreButton->Name = L"SaveGenreButton";
			this->SaveGenreButton->Size = System::Drawing::Size(220, 50);
			this->SaveGenreButton->TabIndex = 4;
			this->SaveGenreButton->Text = L"Сохранить";
			this->SaveGenreButton->UseVisualStyleBackColor = true;
			this->SaveGenreButton->Click += gcnew System::EventHandler(this, &MyForm::SaveGenreButton_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(277, 201);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(192, 42);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Описание";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(290, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(189, 42);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Название";
			// 
			// GenreDescriptionForSave
			// 
			this->GenreDescriptionForSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->GenreDescriptionForSave->Location = System::Drawing::Point(48, 268);
			this->GenreDescriptionForSave->Multiline = true;
			this->GenreDescriptionForSave->Name = L"GenreDescriptionForSave";
			this->GenreDescriptionForSave->Size = System::Drawing::Size(693, 298);
			this->GenreDescriptionForSave->TabIndex = 1;
			// 
			// GenreNameForSave
			// 
			this->GenreNameForSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->GenreNameForSave->Location = System::Drawing::Point(117, 89);
			this->GenreNameForSave->Name = L"GenreNameForSave";
			this->GenreNameForSave->Size = System::Drawing::Size(538, 47);
			this->GenreNameForSave->TabIndex = 0;
			// 
			// BookPanel
			// 
			this->BookPanel->Controls->Add(this->label19);
			this->BookPanel->Controls->Add(this->BooksGenreList);
			this->BookPanel->Controls->Add(this->BookSaveTypeLable);
			this->BookPanel->Controls->Add(this->RefreshBooksButton);
			this->BookPanel->Controls->Add(this->SaveBookButton);
			this->BookPanel->Controls->Add(this->DeleteBookButton);
			this->BookPanel->Controls->Add(this->AddBookButton);
			this->BookPanel->Controls->Add(this->BookCount);
			this->BookPanel->Controls->Add(this->BookYear);
			this->BookPanel->Controls->Add(this->BookAuthor);
			this->BookPanel->Controls->Add(this->BookTitle);
			this->BookPanel->Controls->Add(this->BookIdLable);
			this->BookPanel->Controls->Add(this->label10);
			this->BookPanel->Controls->Add(this->label9);
			this->BookPanel->Controls->Add(this->label8);
			this->BookPanel->Controls->Add(this->label7);
			this->BookPanel->Controls->Add(this->label6);
			this->BookPanel->Controls->Add(this->label5);
			this->BookPanel->Controls->Add(this->BookList);
			this->BookPanel->Location = System::Drawing::Point(58, 110);
			this->BookPanel->Name = L"BookPanel";
			this->BookPanel->Size = System::Drawing::Size(865, 716);
			this->BookPanel->TabIndex = 4;
			// 
			// BooksGenreList
			// 
			this->BooksGenreList->CheckOnClick = true;
			this->BooksGenreList->FormattingEnabled = true;
			this->BooksGenreList->Location = System::Drawing::Point(669, 120);
			this->BooksGenreList->Name = L"BooksGenreList";
			this->BooksGenreList->Size = System::Drawing::Size(160, 484);
			this->BooksGenreList->TabIndex = 17;
			// 
			// BookSaveTypeLable
			// 
			this->BookSaveTypeLable->AutoSize = true;
			this->BookSaveTypeLable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BookSaveTypeLable->Location = System::Drawing::Point(280, 34);
			this->BookSaveTypeLable->Name = L"BookSaveTypeLable";
			this->BookSaveTypeLable->Size = System::Drawing::Size(232, 37);
			this->BookSaveTypeLable->TabIndex = 16;
			this->BookSaveTypeLable->Text = L"Добавить книгу";
			// 
			// RefreshBooksButton
			// 
			this->RefreshBooksButton->Location = System::Drawing::Point(134, 95);
			this->RefreshBooksButton->Name = L"RefreshBooksButton";
			this->RefreshBooksButton->Size = System::Drawing::Size(75, 23);
			this->RefreshBooksButton->TabIndex = 15;
			this->RefreshBooksButton->Text = L"Обновить";
			this->RefreshBooksButton->UseVisualStyleBackColor = true;
			this->RefreshBooksButton->Click += gcnew System::EventHandler(this, &MyForm::RefreshBooksButton_Click);
			// 
			// SaveBookButton
			// 
			this->SaveBookButton->Location = System::Drawing::Point(296, 593);
			this->SaveBookButton->Name = L"SaveBookButton";
			this->SaveBookButton->Size = System::Drawing::Size(172, 52);
			this->SaveBookButton->TabIndex = 14;
			this->SaveBookButton->Text = L"Сохранить";
			this->SaveBookButton->UseVisualStyleBackColor = true;
			this->SaveBookButton->Click += gcnew System::EventHandler(this, &MyForm::SaveBookButton_Click);
			// 
			// DeleteBookButton
			// 
			this->DeleteBookButton->BackColor = System::Drawing::Color::Red;
			this->DeleteBookButton->Location = System::Drawing::Point(116, 635);
			this->DeleteBookButton->Name = L"DeleteBookButton";
			this->DeleteBookButton->Size = System::Drawing::Size(106, 31);
			this->DeleteBookButton->TabIndex = 13;
			this->DeleteBookButton->Text = L"Удалить";
			this->DeleteBookButton->UseVisualStyleBackColor = false;
			this->DeleteBookButton->Click += gcnew System::EventHandler(this, &MyForm::DeleteBookButton_Click);
			// 
			// AddBookButton
			// 
			this->AddBookButton->Location = System::Drawing::Point(20, 635);
			this->AddBookButton->Name = L"AddBookButton";
			this->AddBookButton->Size = System::Drawing::Size(99, 31);
			this->AddBookButton->TabIndex = 12;
			this->AddBookButton->Text = L"Добавить";
			this->AddBookButton->UseVisualStyleBackColor = true;
			this->AddBookButton->Click += gcnew System::EventHandler(this, &MyForm::AddBookButton_Click);
			// 
			// BookCount
			// 
			this->BookCount->Location = System::Drawing::Point(278, 491);
			this->BookCount->Name = L"BookCount";
			this->BookCount->Size = System::Drawing::Size(162, 20);
			this->BookCount->TabIndex = 11;
			// 
			// BookYear
			// 
			this->BookYear->Location = System::Drawing::Point(278, 409);
			this->BookYear->Name = L"BookYear";
			this->BookYear->Size = System::Drawing::Size(292, 20);
			this->BookYear->TabIndex = 10;
			// 
			// BookAuthor
			// 
			this->BookAuthor->Location = System::Drawing::Point(278, 330);
			this->BookAuthor->Name = L"BookAuthor";
			this->BookAuthor->Size = System::Drawing::Size(292, 20);
			this->BookAuthor->TabIndex = 9;
			// 
			// BookTitle
			// 
			this->BookTitle->Location = System::Drawing::Point(275, 242);
			this->BookTitle->Name = L"BookTitle";
			this->BookTitle->Size = System::Drawing::Size(296, 20);
			this->BookTitle->TabIndex = 8;
			// 
			// BookIdLable
			// 
			this->BookIdLable->AutoSize = true;
			this->BookIdLable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BookIdLable->Location = System::Drawing::Point(278, 162);
			this->BookIdLable->Name = L"BookIdLable";
			this->BookIdLable->Size = System::Drawing::Size(0, 31);
			this->BookIdLable->TabIndex = 7;
			this->BookIdLable->TextChanged += gcnew System::EventHandler(this, &MyForm::BookIdLable_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(271, 454);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(242, 25);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Свободное количество";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(271, 367);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(48, 25);
			this->label9->TabIndex = 5;
			this->label9->Text = L"Год";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(271, 295);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(71, 25);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Автор";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(271, 209);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(109, 25);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Название";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(271, 124);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(78, 25);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Номер";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(17, 60);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 33);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Книги";
			// 
			// BookList
			// 
			this->BookList->FormattingEnabled = true;
			this->BookList->Location = System::Drawing::Point(20, 124);
			this->BookList->Name = L"BookList";
			this->BookList->Size = System::Drawing::Size(202, 511);
			this->BookList->TabIndex = 0;
			this->BookList->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::BookList_SelectedIndexChanged);
			// 
			// ClientPanel
			// 
			this->ClientPanel->Controls->Add(this->label18);
			this->ClientPanel->Controls->Add(this->AddressTextBox);
			this->ClientPanel->Controls->Add(this->ClientSaveType);
			this->ClientPanel->Controls->Add(this->RefreshClientsButton);
			this->ClientPanel->Controls->Add(this->SaveClientButton);
			this->ClientPanel->Controls->Add(this->ClientIdLable);
			this->ClientPanel->Controls->Add(this->DeleteClientButton);
			this->ClientPanel->Controls->Add(this->AddClientButton);
			this->ClientPanel->Controls->Add(this->label17);
			this->ClientPanel->Controls->Add(this->ClientList);
			this->ClientPanel->Controls->Add(this->PassportNumberTextBox);
			this->ClientPanel->Controls->Add(this->LastNameTextBox);
			this->ClientPanel->Controls->Add(this->MiddleNameTextBox);
			this->ClientPanel->Controls->Add(this->FirstNameTextBox);
			this->ClientPanel->Controls->Add(this->DateOfBirthTextBox);
			this->ClientPanel->Controls->Add(this->label16);
			this->ClientPanel->Controls->Add(this->label15);
			this->ClientPanel->Controls->Add(this->label14);
			this->ClientPanel->Controls->Add(this->label13);
			this->ClientPanel->Controls->Add(this->label12);
			this->ClientPanel->Controls->Add(this->label11);
			this->ClientPanel->Location = System::Drawing::Point(48, 125);
			this->ClientPanel->Name = L"ClientPanel";
			this->ClientPanel->Size = System::Drawing::Size(847, 743);
			this->ClientPanel->TabIndex = 5;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->Location = System::Drawing::Point(372, 587);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(98, 33);
			this->label18->TabIndex = 21;
			this->label18->Text = L"Адрес";
			// 
			// AddressTextBox
			// 
			this->AddressTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddressTextBox->Location = System::Drawing::Point(375, 625);
			this->AddressTextBox->Name = L"AddressTextBox";
			this->AddressTextBox->Size = System::Drawing::Size(384, 31);
			this->AddressTextBox->TabIndex = 20;
			// 
			// ClientSaveType
			// 
			this->ClientSaveType->AutoSize = true;
			this->ClientSaveType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ClientSaveType->Location = System::Drawing::Point(371, 13);
			this->ClientSaveType->Name = L"ClientSaveType";
			this->ClientSaveType->Size = System::Drawing::Size(355, 42);
			this->ClientSaveType->TabIndex = 19;
			this->ClientSaveType->Text = L"Добавить читателя";
			// 
			// RefreshClientsButton
			// 
			this->RefreshClientsButton->Location = System::Drawing::Point(232, 33);
			this->RefreshClientsButton->Name = L"RefreshClientsButton";
			this->RefreshClientsButton->Size = System::Drawing::Size(74, 22);
			this->RefreshClientsButton->TabIndex = 18;
			this->RefreshClientsButton->Text = L"Обновить";
			this->RefreshClientsButton->UseVisualStyleBackColor = true;
			this->RefreshClientsButton->Click += gcnew System::EventHandler(this, &MyForm::RefreshClientsButton_Click);
			// 
			// SaveClientButton
			// 
			this->SaveClientButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->SaveClientButton->Location = System::Drawing::Point(508, 697);
			this->SaveClientButton->Name = L"SaveClientButton";
			this->SaveClientButton->Size = System::Drawing::Size(133, 45);
			this->SaveClientButton->TabIndex = 17;
			this->SaveClientButton->Text = L"Сохранить";
			this->SaveClientButton->UseVisualStyleBackColor = true;
			this->SaveClientButton->Click += gcnew System::EventHandler(this, &MyForm::SaveClientButton_Click);
			// 
			// ClientIdLable
			// 
			this->ClientIdLable->AutoSize = true;
			this->ClientIdLable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ClientIdLable->Location = System::Drawing::Point(369, 110);
			this->ClientIdLable->Name = L"ClientIdLable";
			this->ClientIdLable->Size = System::Drawing::Size(0, 33);
			this->ClientIdLable->TabIndex = 16;
			this->ClientIdLable->TextChanged += gcnew System::EventHandler(this, &MyForm::ClientIdLable_TextChanged);
			// 
			// DeleteClientButton
			// 
			this->DeleteClientButton->BackColor = System::Drawing::Color::Red;
			this->DeleteClientButton->Location = System::Drawing::Point(179, 646);
			this->DeleteClientButton->Name = L"DeleteClientButton";
			this->DeleteClientButton->Size = System::Drawing::Size(132, 33);
			this->DeleteClientButton->TabIndex = 15;
			this->DeleteClientButton->Text = L"Удалить";
			this->DeleteClientButton->UseVisualStyleBackColor = false;
			this->DeleteClientButton->Click += gcnew System::EventHandler(this, &MyForm::DeleteClientButton_Click);
			// 
			// AddClientButton
			// 
			this->AddClientButton->Location = System::Drawing::Point(55, 646);
			this->AddClientButton->Name = L"AddClientButton";
			this->AddClientButton->Size = System::Drawing::Size(125, 34);
			this->AddClientButton->TabIndex = 14;
			this->AddClientButton->Text = L"Добавить";
			this->AddClientButton->UseVisualStyleBackColor = true;
			this->AddClientButton->Click += gcnew System::EventHandler(this, &MyForm::AddClientButton_Click);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(55, 23);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(142, 33);
			this->label17->TabIndex = 13;
			this->label17->Text = L"Читатели";
			// 
			// ClientList
			// 
			this->ClientList->FormattingEnabled = true;
			this->ClientList->Location = System::Drawing::Point(55, 71);
			this->ClientList->Name = L"ClientList";
			this->ClientList->Size = System::Drawing::Size(252, 576);
			this->ClientList->TabIndex = 12;
			this->ClientList->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ClientList_SelectedIndexChanged);
			// 
			// PassportNumberTextBox
			// 
			this->PassportNumberTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->PassportNumberTextBox->Location = System::Drawing::Point(374, 544);
			this->PassportNumberTextBox->Name = L"PassportNumberTextBox";
			this->PassportNumberTextBox->Size = System::Drawing::Size(384, 31);
			this->PassportNumberTextBox->TabIndex = 11;
			// 
			// LastNameTextBox
			// 
			this->LastNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->LastNameTextBox->Location = System::Drawing::Point(374, 191);
			this->LastNameTextBox->Name = L"LastNameTextBox";
			this->LastNameTextBox->Size = System::Drawing::Size(388, 31);
			this->LastNameTextBox->TabIndex = 10;
			// 
			// MiddleNameTextBox
			// 
			this->MiddleNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->MiddleNameTextBox->Location = System::Drawing::Point(375, 369);
			this->MiddleNameTextBox->Name = L"MiddleNameTextBox";
			this->MiddleNameTextBox->Size = System::Drawing::Size(387, 31);
			this->MiddleNameTextBox->TabIndex = 9;
			// 
			// FirstNameTextBox
			// 
			this->FirstNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->FirstNameTextBox->Location = System::Drawing::Point(371, 277);
			this->FirstNameTextBox->Name = L"FirstNameTextBox";
			this->FirstNameTextBox->Size = System::Drawing::Size(387, 31);
			this->FirstNameTextBox->TabIndex = 8;
			// 
			// DateOfBirthTextBox
			// 
			this->DateOfBirthTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->DateOfBirthTextBox->Location = System::Drawing::Point(375, 453);
			this->DateOfBirthTextBox->Name = L"DateOfBirthTextBox";
			this->DateOfBirthTextBox->Size = System::Drawing::Size(387, 31);
			this->DateOfBirthTextBox->TabIndex = 7;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(365, 146);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(142, 33);
			this->label16->TabIndex = 5;
			this->label16->Text = L"Фамилия";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(365, 238);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(73, 33);
			this->label15->TabIndex = 4;
			this->label15->Text = L"Имя";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(378, 508);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(237, 33);
			this->label14->TabIndex = 3;
			this->label14->Text = L"Номер паспорта";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(372, 417);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(224, 33);
			this->label13->TabIndex = 2;
			this->label13->Text = L"Дата рождения";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(365, 333);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(141, 33);
			this->label12->TabIndex = 1;
			this->label12->Text = L"Отчество";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(368, 60);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(410, 33);
			this->label11->TabIndex = 0;
			this->label11->Text = L"Номер читательского билета";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->Location = System::Drawing::Point(666, 95);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(143, 25);
			this->label19->TabIndex = 18;
			this->label19->Text = L"Жанры книги";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(945, 880);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->BookPanel);
			this->Controls->Add(this->GenrePanel);
			this->Controls->Add(this->AddGenrePanel);
			this->Controls->Add(this->ClientPanel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->GenrePanel->ResumeLayout(false);
			this->GenrePanel->PerformLayout();
			this->AddGenrePanel->ResumeLayout(false);
			this->AddGenrePanel->PerformLayout();
			this->BookPanel->ResumeLayout(false);
			this->BookPanel->PerformLayout();
			this->ClientPanel->ResumeLayout(false);
			this->ClientPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
//navigation
private: System::Void hidePanels() {
	this->GenrePanel->Visible = false;
	this->AddGenrePanel->Visible = false;
	this->BookPanel->Visible = false;
	this->ClientPanel->Visible = false;

}
private: System::Void GenresMenuButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->hidePanels();
	this->GenrePanel->Visible = true;
}
private: System::Void BookMenuButton_Click(System::Object^ sender, System::EventArgs^ e) {
	hidePanels();
	this->BookPanel->Visible = true;
}
private: System::Void ClientsMenuButton_Click(System::Object^ sender, System::EventArgs^ e) {
	hidePanels();
	this->ClientPanel->Visible = true;
}

//GenrePanel
private: string getSelectedGenre() {
	int index = this->GenreList->SelectedIndex;
	if (index == -1) {
		throw NotSelected("genre");
	}
	auto a = this->GenreList->Items[index];
	return msclr::interop::marshal_as<std::string>(a->ToString());
}
private: System::Void GenreList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	try {
		string selected = getSelectedGenre();
		Genre genre = this->genreRepo->getGenre(selected.c_str());
		String^ genreDesc = gcnew String(genre.description.c_str());
		this->GenreDescription->Text = genreDesc;
		String^ genreName = gcnew String(genre.name.c_str());
		this->SelectedGenre->Text = genreName;
	}catch(NotSelected &e) {
		this->GenreDescription->Text = "";
		this->SelectedGenre->Text = "";
	}

}
private: System::Void AddGenre_Click(System::Object^ sender, System::EventArgs^ e) {
	this->hidePanels();
	this->AddGenrePanel->Visible = true;
}
private: System::Void RefreshGenres_Click(System::Object^ sender, System::EventArgs^ e) {
	vector<Genre> genres = this->genreRepo->getAllGenres();
	this->GenreList->Items->Clear();
	for (auto genre : genres) {
		auto str = gcnew String(genre.name.c_str());
		this->GenreList->Items->Add(str);
	}
	this->refreshBookGenres();
}
//GenreAddPanel
private: void closeGenreAddPanel(System::Object^ sender, System::EventArgs^ e) {
	this->GenreDescriptionForSave->Text = "";
	this->GenreNameForSave->Text = "";
	this->GenresMenuButton_Click(sender, e);
	this->RefreshGenres_Click(sender, e);
}
private: System::Void SaveGenreButton_Click(System::Object^ sender, System::EventArgs^ e) {
	string genreName = msclr::interop::marshal_as<std::string>(this->GenreNameForSave->Text);
	string genreDesc = msclr::interop::marshal_as<std::string>(this->GenreDescriptionForSave->Text);
	if ((genreName == "") || (genreDesc == "")) {
		MessageBox::Show("fullfill form");
		return;
	}
	Genre genre{ genreName, genreDesc };
	this->genreRepo->saveGenre(&genre);
	closeGenreAddPanel(sender, e);
}
private: System::Void UpdateGenreButton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		string selected = getSelectedGenre();
		Genre genre = this->genreRepo->getGenre(selected.c_str());
		String^ genreDesc = gcnew String(genre.description.c_str());
		this->GenreDescriptionForSave->Text = genreDesc;
		String^ genreName = gcnew String(genre.name.c_str());
		this->GenreNameForSave->Text = genreName;
		this->hidePanels();
		this->AddGenrePanel->Visible = true;
	}catch (NotSelected& e) {
		MessageBox::Show("Select Genre!!");
	}
}
private: System::Void DeleteGenreButton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		string selected = getSelectedGenre();
		this->genreRepo->deleteGenre(selected.c_str());
		this->RefreshGenres_Click(sender, e);
	}catch (NotSelected& e) {
		MessageBox::Show("Select Genre!!");
	}
}

private: System::Void GenreList_Leave(System::Object^ sender, System::EventArgs^ e) {
	this->GenreDescription->Text = "";
	this->SelectedGenre->Text = "Выберите жанр";

}

//BooksPanel
private: System::Void RefreshBooksButton_Click(System::Object^ sender, System::EventArgs^ e) {
	vector<Book> books = this->bookRepo->getAllBooks();
	this->BookList->Items->Clear();
	for (Book book : books) {
		auto str = gcnew String(("№ "+to_string(book.id)+": "+book.title).c_str());
		this->BookList->Items->Add(str);
	}
}
private: int getSelectedBook() {
	int index = this->BookList->SelectedIndex;
	if (index == -1) {
		throw NotSelected("book");
	}
	auto a = this->BookList->Items[index];
	string selected =  msclr::interop::marshal_as<std::string>(a->ToString());
	size_t pos = selected.find(':'); // Find the position of the colon
	std::string idString = selected.substr(2, pos - 2); // Extract the substring containing the id
	int id = std::stoi(idString);
	return id;
}
private: System::Void DeleteBookButton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		int selected = getSelectedBook();
		this->bookRepo->deleteBook(selected);
		this->RefreshBooksButton_Click(sender, e);
	}
	catch (NotSelected& e) {
		MessageBox::Show("Select Book!!");
	}
}


private: System::Void AddBookButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->BookTitle->Text = "";
	this->BookAuthor->Text = "";
	this->BookYear->Text = "";
	this->BookCount->Text = "";
	this->BookIdLable->Text = "";
}
private: void refreshBookGenres() {
	try {
		int selected = getSelectedBook();
		Book book = this->bookRepo->getBookById(selected);
		this->BooksGenreList->Items->Clear();
		auto genres = this->genreRepo->getAllGenres();
		for (auto genre : genres) {
			this->BooksGenreList->Items->Add(gcnew String(genre.name.c_str()), false);
		}
		for (auto genre : book.genres) {
			this->BooksGenreList->Items->Remove(gcnew String(genre.name.c_str()));
			this->BooksGenreList->Items->Add(gcnew String(genre.name.c_str()), true);
		}
	}
	catch (NotSelected& e) {
		return;
	}

}
private: System::Void BookList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	try {
		int selected = getSelectedBook();
		Book book = this->bookRepo->getBookById(selected);
		this->BookTitle->Text = gcnew String(book.title.c_str());
		this->BookAuthor->Text = gcnew String(book.author.c_str());
		this->BookYear->Text = gcnew String(to_string(book.year).c_str());
		this->BookCount->Text = gcnew String(to_string(book.count).c_str());
		this->BookIdLable->Text = gcnew String(to_string(book.id).c_str());

		refreshBookGenres();
	}
	catch (NotSelected& a) {
		AddBookButton_Click(sender, e);
	}
}

private: System::Void BookIdLable_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->BookIdLable->Text == "") {
		this->BookSaveTypeLable->Text = "Добавить книгу";
	}
	else {
		this->BookSaveTypeLable->Text = "Изменить книгу";
	}
}
private: void validateBookForm() {
	// Check if the title is empty
	if (this->BookTitle->Text == "") {
		throw runtime_error("Please enter a book title.");
	}

	// Check if the author is empty
	if (this->BookAuthor->Text == "") {
		throw runtime_error("Please enter the author's name.");
	}

	// Check if the year is a valid integer
	try {
		stoi(msclr::interop::marshal_as<std::string>(this->BookYear->Text));
	}
	catch (...) {
		throw runtime_error("Please enter a valid year.");
	}
	try {
		stoi(msclr::interop::marshal_as<std::string>(this->BookCount->Text));
	}
	catch (...) {
		throw runtime_error("Please enter a valid count.");
	}
	// Check if the count is a valid integer

	string idString = msclr::interop::marshal_as<std::string>(this->BookIdLable->Text);
	if (idString != string("")) {
		try {
			stoi(idString);
		}
		catch (...) {
			throw runtime_error("Please enter a valid id.");
		}
	}

}
private: System::Void SaveBookButton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		validateBookForm();
		Book book;
		book.title = msclr::interop::marshal_as<std::string>(this->BookTitle->Text);
		book.author = msclr::interop::marshal_as<std::string>(this->BookAuthor->Text);
		book.year = stoi(msclr::interop::marshal_as<std::string>(this->BookYear->Text));
		book.count = stoi(msclr::interop::marshal_as<std::string>(this->BookCount->Text));
		string idString = msclr::interop::marshal_as<std::string>(this->BookIdLable->Text);
		cout << idString;
		if (idString == string("")) {
			book.id = 0;
		}
		else {
			book.id = stoi(msclr::interop::marshal_as<std::string>(this->BookIdLable->Text));
		}
		book.genres = getCheckedGenres();
		this->bookRepo->saveBook(&book);
		this->BookIdLable->Text = gcnew String(to_string(book.id).c_str());
		this->RefreshBooksButton_Click(sender, e);
	}
	catch (runtime_error &e) {
		MessageBox::Show(gcnew String(e.what()));
	}
}
private: vector<Genre> getCheckedGenres(){
	auto checkedItems = this->BooksGenreList->CheckedItems;
	vector<Genre> genres;
	for (int i = 0; i < checkedItems->Count; i++) {
		string name = msclr::interop::marshal_as<std::string>(checkedItems[i]->ToString());
		genres.push_back(this->genreRepo->getGenre(name.c_str()));
	}
	return genres;
}

private: System::Void RefreshClientsButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->ClientList->Items->Clear();
	auto clients = this->clientRepo->getAllClients();
	for (auto client : clients) {
		string clientString = to_string(client.id) + " " + client.lastName + " " + client.firstName + " " + client.middleName;
		this->ClientList->Items->Add(gcnew String(clientString.c_str()));
	}
}	
private: int getSelectedClient() {
	int index = this->ClientList->SelectedIndex;
	if (index == -1) {
		throw NotSelected("client");
	}
	auto a = this->ClientList->Items[index];
	string selected = msclr::interop::marshal_as<std::string>(a->ToString());
	size_t pos = selected.find(' '); // Find the position of the colon
	std::string idString = selected.substr(0, pos); // Extract the substring containing the id
	int id = std::stoi(idString);
	return id;
}


private: System::Void ClientList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	try {
		int selected = getSelectedClient();
		Client client = this->clientRepo->getClientById(selected);
		this->ClientIdLable->Text = gcnew String(to_string(client.id).c_str());
		this->LastNameTextBox->Text = gcnew String(client.lastName.c_str());
		this->FirstNameTextBox->Text = gcnew String(client.firstName.c_str());
		this->MiddleNameTextBox->Text = gcnew String(client.middleName.c_str());
		this->DateOfBirthTextBox->Text = gcnew String(client.dateOfBirth.c_str());
		this->PassportNumberTextBox->Text = gcnew String(client.passportNumber.c_str());
		this->AddressTextBox->Text = gcnew String(client.address.c_str());

	}
	catch (NotSelected& a) {
		AddClientButton_Click(sender, e);
	}
}
private: System::Void AddClientButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->ClientIdLable->Text = "";
	this->LastNameTextBox->Text = "";
	this->FirstNameTextBox->Text = "";
	this->MiddleNameTextBox->Text = "";
	this->DateOfBirthTextBox->Text = "";
	this->PassportNumberTextBox->Text = "";
	this->AddressTextBox->Text = "";

}
private: System::Void ClientIdLable_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->ClientIdLable->Text == "") {
		this->ClientSaveType->Text = "Добавить читателя";
	}
	else {
		this->ClientSaveType->Text = "Изменить читателя";

	}
}
private: void validateClientForm() {
	if (this->LastNameTextBox->Text == "") {
		throw runtime_error("Please enter last name.");
	}

	if (this->FirstNameTextBox->Text == "") {
		throw runtime_error("Please enter first name.");
	}

	if (this->MiddleNameTextBox->Text == "") {
		throw runtime_error("Please enter middle name.");
	}
	std::regex datePattern("\\b(\\d{2})\\.(\\d{2})\\.(\\d{4})\\b");
	string bD = msclr::interop::marshal_as<std::string>(this->DateOfBirthTextBox->Text);
	bool correct = regex_match(bD, datePattern);
	if (!correct) {
		throw runtime_error("Please enter date (dd.mm.yyyy)");
	}
	std::regex passportPattern("\\b(\\d{4}) (\\d{6})\\b");
	string pN = msclr::interop::marshal_as<std::string>(this->PassportNumberTextBox->Text);
	bool correct1 = regex_match(pN, passportPattern);
	if (!correct1) {
		throw runtime_error("Please enter passport number (ssss nnnnnn)");
	}
	if (this->AddressTextBox->Text == "") {
		throw runtime_error("Please enter adress.");
	}
	string idString = msclr::interop::marshal_as<std::string>(this->ClientIdLable->Text);
	if (idString != string("")) {
		try {
			stoi(idString);
		}
		catch (...) {
			throw runtime_error("Please enter a valid id.");
		}
	}

}
private: Client getClientFromForm() {
	validateClientForm();
	Client client;
	client.passportNumber = msclr::interop::marshal_as<std::string>(this->PassportNumberTextBox->Text);
	client.lastName = msclr::interop::marshal_as<std::string>(this->LastNameTextBox->Text);
	client.firstName = msclr::interop::marshal_as<std::string>(this->FirstNameTextBox->Text);
	client.middleName = msclr::interop::marshal_as<std::string>(this->MiddleNameTextBox->Text);
	client.address = msclr::interop::marshal_as<std::string>(this->AddressTextBox->Text);
	client.dateOfBirth = msclr::interop::marshal_as<std::string>(this->DateOfBirthTextBox->Text);
	string idString = msclr::interop::marshal_as<std::string>(this->ClientIdLable->Text);
	if (idString == string("")) {
		client.id = 0;
	}
	else {
		client.id = stoi(msclr::interop::marshal_as<std::string>(this->ClientIdLable->Text));
	}
	return client;
}
private: System::Void DeleteClientButton_Click(System::Object^ sender, System::EventArgs^ e) {
	int id = getSelectedClient();
	cout << id;
	this->clientRepo->deleteClient(id);
	RefreshClientsButton_Click(sender, e);

}
private: System::Void SaveClientButton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		Client client = getClientFromForm();
		this->clientRepo->saveClient(&client);
		RefreshClientsButton_Click(sender, e);
	}
	catch (runtime_error& e) {
		MessageBox::Show(gcnew String(e.what()));
	}
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	RefreshBooksButton_Click(sender, e);
	RefreshClientsButton_Click(sender, e);
	RefreshGenres_Click(sender, e);
}
};


}


