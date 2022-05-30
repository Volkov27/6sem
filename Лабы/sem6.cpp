//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
#include <iostream>
#include <filesystem>
#include "sem6.h"
using namespace std::filesystem;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ReadDrctClick(TObject *Sender)
{
	path dir_path( "C:\\");
	directory_iterator end_itr; // default construction yields past-the-end
	ListEntry *headEntry = NULL;
	ListEntry *lastEntry = NULL;

	//for (directory_iterator itr(dir_path); itr != end_itr; ++itr)

	for (auto dir_entry : directory_iterator(dir_path))
	{
		if (lastEntry == NULL)
		{
			headEntry = new ListEntry;
			headEntry->data.fileName = dir_entry.path().string();
			headEntry->prev = NULL;
			headEntry->next = NULL;
			lastEntry = headEntry;
		}
		else
		{
			lastEntry->next = new ListEntry;
			lastEntry->next->data.fileName = dir_entry.path().string();
			lastEntry->next->prev = lastEntry;
			lastEntry->next->next = NULL;
		}

	}
	return;
}
//---------------------------------------------------------------------------
