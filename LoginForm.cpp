//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "LoginForm.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyLoginForm *MyLoginForm;
//---------------------------------------------------------------------------
__fastcall TMyLoginForm::TMyLoginForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
std::vector<std::string>parseCommaDelimiter(std::string line){

	std::vector<std::string> result;
	std::stringstream s_stream(line);

	while(s_stream.good()){

		   std::string substr;
		   getline(s_stream,substr,',');
		   result.push_back(substr);

	}


	return result;
}

//---------------------------------------------------------------------------
void __fastcall TMyLoginForm::LoginButtonClick(TObject *Sender)
{

	fstream myFile;
	myFile.open("registeredUsers.txt",ios::in);



	if(myFile.is_open()){

		std::string line;

		while(getline(myFile,line)){

			std::vector<std::string> resultVector = parseCommaDelimiter(line);
			 const char*username =resultVector.at(2).c_str();

			AnsiString editUsername = usernameEdit->Text;
			const char* usernameString  = editUsername.c_str();

			if(std::strcmp(username,usernameString)==0){
				const char* password = resultVector.at(3).c_str();

				AnsiString editPassword = passwordEdit->Text;
				const char* passwordString  = editPassword.c_str();

				if(std::strcmp(password,passwordString)==0){

					   messageLabel->Text="You Are Logged In!";


				}
				else{


					messageLabel->Text ="Wrong Credentials!";

				}

			}
		}



	}



}
//---------------------------------------------------------------------------

