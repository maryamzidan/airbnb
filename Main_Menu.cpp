#pragma once
#include "Main_Menu.h"
#include "Host.h"
#include "Admin.h"
#include <iostream>
#include "Windows.h"
#include<regex>

using namespace std;
vector<Host>        Main_Menu::Host_Users;
map<string, string> Main_Menu::Host_Enter;
vector<Traveller>   Main_Menu::Trav_Users;
map<string, string> Main_Menu::Trav_Enter;
vector<Place> Main_Menu::places;
CurrentUser Main_Menu::LoggedinUser;

Host h1;
Traveller t;
Admin a;
string tname;
string temail;
string tpassword;
string tnationality;
string tgender;
int tage;
string tFavouriteColor;

          Main_Menu::Main_Menu(){}
void Main_Menu::WelcomeScreen(void)
{


	cout << "\n\n\n\n\n\n\n\t\t\t\t\t\n";
	cout << "\t\t\t\t _______________________________________________________________________________________ \n";
	cout << "\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t|  GEN_034    D A T A  S T R U C T U R E S  P R O J E C T   2022                        |\n";
	cout << "\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t|                                  WELCOME TO                                           |\n";
	cout << "\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t|                                    AIRBNB                                             |\n";
	cout << "\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t|                                                                                       |\n";
	cout << "\t\t\t\t|                  -Please Run in Fullscreen mode for better show :)                    |\n";
	cout << "\t\t\t\t|_______________________________________________________________________________________|\n";
	cout << "\t\t\t\t\n\n\n\n\t\t\t\t\t";
	Sleep(3000);
	system("cls");

}
void      Main_Menu::menu() {
	int ch = 0;
	int ch2;
	bool LoginSuccess;
	bool RegisterSuccess;

MAIN:cout<< "|------ M  A  I  N       M  E  N  U ------|\n";
	cout << "|                                         |\n";
	cout << "| [Type  1 to Enter  as  a  Traveller]    |\n";
	cout << "|                                         |\n";
	cout << "| [Type  2 to Enter  as  a  Host]         |\n";
	cout << "|                                         |\n";
	cout << "| [Type  3 to Enter  as  a  Admin ]       |\n";
	cout << "|                                         |\n";
	cout << "| [Type  4 to Exit]                       |\n";
	cout << "|                                         |\n";
	cout << "|-----------------------------------------|\n";
	cout << "|Your Choice-->>>>>>>>>>>>>>>>>>>>>>>>>>>>";
	while (ch != 4)
	{
		cin >> ch;
		/*>>*/if (ch == 1) //Enter As Traveller
		{
			LoggedinUser.type = "T";
			int ch_T;
			system("cls");
			//----------------------------------------------------
	 LOGOUT:cout << "|-- E N T E R   A S   T R A V E L L E R --|\n";
			cout << "|                                         |\n";
			cout << "| [Type  1 to Sign Up]                    |\n";
			cout << "|                                         |\n";
			cout << "| [Type  2 to Log in ]                    |\n";
			cout << "|                                         |\n";
			cout << "| [Type  3 to Back to Main Menu ]         |\n";
			cout << "|                                         |\n";
			cout << "|-----------------------------------------|\n";
			cout << "|Your Choice-->>>>>>>>>>>>>>>>>>>>>>>>>>>>";
			//----------------------------------------------------
			cin >> ch_T;
			if (ch_T == 1) //1 - Sign Up
			{
				signup();
				cout << "Redirecting to Log in.......\n";
				Sleep(2000);
				system("CLS");
				goto LOOP0;

			}
			else if (ch_T == 2) //2 - Log In
			{

			LOOP0:
				while (true) /*loop until login succeeded*/ {

					LoginSuccess = login();

					if (LoginSuccess == true)

						break;

					else {

						cout << "1 - Forgot My Password\n\n";

						cout << "2 - Retry Loggin in.\n\n";

						cin >> ch;
						system("cls");

						if (ch == 2) // retry logging in
							continue;

						else if (ch == 1) // forgot password
						{
							string Email;
							string FavColor;

							cout << "\nEnter Email " << endl;
							cin >> Email;

							cout << "\nEnter Your Favourite Color\n";
							cin >> FavColor;


							//////////////////////////Edited//////////////////
							bool exist = false;
							for (int i = 0; i < Trav_Users.size(); i++)
							{
								if (Email == Trav_Users[i].email)
								{
									exist = true;
									break;
								}

							}
							if (exist == false)
							{
								cout << "\nThis Email is Not Found !\n";
								Sleep(2000);
								goto LOOP00;
							}
							else
							{

								if (TGetUserInfoByEmail(Email).FavouriteColor == FavColor) {
									cout << "Your Password is : " << Trav_Enter[Email] << endl;
									Sleep(4000);
								}
								else {
									cout << "Wrong Answer!\n";
									Sleep(2000);
									goto LOOP00;
								}


							}
							Sleep(2000);

						}

					}
				}   
				cout << "\n";
				cout << "\t\t\t\t _______________________________________________________________________________________ \n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                          WELCOME, "<<LoggedinUser.name<<" :)                                           |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                             LOADING......                                             |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                  -Please Run in Fullscreen mode for better show :)                    |\n";
				cout << "\t\t\t\t|_______________________________________________________________________________________|\n";
				cout << "\t\t\t\t|"; for (int i = 1; i < 88; i++) { cout << "*"; Sleep(30); } cout << "|";
	
			
				
				system("cls");

		  LOOP1:cout << "|--   T R A V E L L E R ' S  M E N U    --|\n";
				cout << "|                                         |\n";
				cout << "| [ 1 -   Search for a Place    ]         |\n";
				cout << "|                                         |\n";
				cout << "| [ 2 -   Show my Rented Places ]         |\n";
				cout << "|                                         |\n";
				cout << "| [ 3 -   Log Out               ]         |\n";
				cout << "|                                         |\n";
				cout << "|-----------------------------------------|\n";
				cout << "|Your Choice-->>>>>>>>>>>>>>>>>>>>>>>>>>>>";
				cin >> ch2;
				if (ch2 == 1) {
					system("CLS");
				cout << "|--- S E A R C H  F O R  A  P L A C E  ---|\n";
					int flag = t.Search();
					if ( flag == 1) goto LOOP1;
					else if (flag == 2)  goto LOOP0;
					system("CLS");
					goto LOOP1;
				}
				else if (ch2 == 2) {
					system("CLS");
			    cout << "|---  M Y  R E N T E D  P L A C E S    ---|\n";
				cout << "-------------------------------------------\n";

					TGetUserInfoByEmail(LoggedinUser.email).ShowRentedPlaces();
					cout << "1 - Back\n";
					cin >> ch;
					if (ch == 1) {
						system("cls");
						goto LOOP1;
					}


				}
				else if (ch2 == 3) {
					system("cls");
					cout << "Logging Out....\n";
					system("cls");
					goto LOGOUT;
				}

			}
			else if (ch_T == 3) // 3- Back to Main Menu
			{
				system("cls");

				goto MAIN;

			}
		}
		/*>>*/else if (ch == 2) //Enter As Host
		{
			LoggedinUser.type = "H";

			system("cls");
	LOGOUT2:cout << "|--      E N T E R   A S   H O S T      --|\n";
			cout << "|                                         |\n";
			cout << "| [Type  1 to Sign Up]                    |\n";
			cout << "|                                         |\n";
			cout << "| [Type  2 to Log in ]                    |\n";
			cout << "|                                         |\n";
			cout << "| [Type  3 to Back to Main Menu ]         |\n";
			cout << "|                                         |\n";
			cout << "|-----------------------------------------|\n";
			cout << "|Your Choice-->>>>>>>>>>>>>>>>>>>>>>>>>>>>";
			int ch_H;
			cin >> ch_H;
			if (ch_H == 1) //1 - Sign Up
			{
				signup();
				cout << "Redirecting to Log in.......\n";
				Sleep(2000);
				system("CLS");
				goto LOOP00;

			}
			else if (ch_H == 2) //2 - Log In
			{

			LOOP00:cout << "Log In\n";

				while (true) /*loop until login succeeded*/ {

					LoginSuccess = login();

					if (LoginSuccess == true)

						break;

					else {

						cout << "1 - Forgot My Password\n\n";

						cout << "2 - Retry Loggin in.\n\n";

						cin >> ch;

						if (ch == 2) // retry logging in
							continue;

						else if (ch == 1) // forgot password
						{
							string Email;
							string FavColor;

							cout << "\nEnter Email " << endl;
							cin >> Email;

							cout << "\nEnter Your Favourite Color\n";
							cin >> FavColor;

						
							//////////////////////////Edited//////////////////
							bool exist = false;
							for (int i = 0; i < Host_Users.size(); i++)
							{
								if (Email == Host_Users[i].email)
								{
									exist = true;
									break;
								}

							}
							if (exist == false)
							{
								cout << "\nThis Email is Not Found !\n";
								Sleep(2000);
								goto LOOP00;
							}
							else
							{
							
								if (HGetUserInfoByEmail(Email).FavouriteColor == FavColor) {
									cout << "Your Password is : " << Host_Enter[Email] << endl;
									Sleep(4000);
								}
								else {
									cout << "Wrong Answer!\n";
									Sleep(2000);
									goto LOOP00;
								}


							}
							Sleep(2000);

						}

					}
				}
				cout << "\n";
				cout << "\t\t\t\t _______________________________________________________________________________________ \n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                          WELCOME, " << LoggedinUser.name << " :)                                           |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                             LOADING......                                             |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                                                                                       |\n";
				cout << "\t\t\t\t|                  -Please Run in Fullscreen mode for better show :)                    |\n";
				cout << "\t\t\t\t|_______________________________________________________________________________________|\n";
				cout << "\t\t\t\t|"; for (int i = 1; i < 88; i++) { cout << "*"; Sleep(30); } cout << "|";
				system("CLS");


		  LOOP3:cout << "|--         H O S T ' S  M E N U        --|\n";
				cout << "|                                         |\n";
				cout << "| [ 1 -   Add a Place          ]          |\n";
				cout << "|                                         |\n";
				cout << "| [ 2 -   Log Out              ]          |\n";
				cout << "|                                         |\n";
				cout << "|-----------------------------------------|\n";
				cout << "|Your Choice-->>>>>>>>>>>>>>>>>>>>>>>>>>>>";


				int ch2;
				cin >> ch2;
				system("CLS");

				if (ch2 == 1) {
					cout << "|--    A  D  D    A    P  L  A  C  E    --|\n";
					cout << "|-----------------------------------------|\n";
					h1.addPlace();
					system("CLS");
					goto LOOP3;
				}

				else if (ch2 == 2) {
					system("cls");
					cout << "Logging Out....\n";
					cout << endl;
					system("cls");
					goto LOGOUT2;
				}



			}
			else if (ch_H == 3) {
				system("cls");
				goto MAIN;

			}
		}
		/*>>*/else if (ch == 3) //Enter as Admin
		{
			a.login();
			int choice=-1;
			while (true)
			{
		
				system("cls");
				a.Dashboard();
			}

		}
		      else if (ch == 4) {
		exit(0);
}
		/*>>*/else {
			cout << "\n Invalid Choice Try Again ):" << endl;
			Sleep(2000);
			system("cls");
			goto MAIN;
		}

	}
}
void      Main_Menu::signup() {
	
	system("cls");                                              
	        cout << "|--------- S I G N I N G   U P ------------|\n";
	cout << "Enter your First name : ";
	cin >> tname;
	cout << "Enter your Email : ";
	while (true) {
		cin >> temail;
		if (LoggedinUser.type == "T") {
			if (Main_Menu::Trav_Enter.count(temail) > 0) {
				cout << "This Email is Already Registered , please write another email..... \n";
				cout << "Enter your Email : ";
				continue;

			}
			 if (Email_Check(temail) == false) {
				cout << "Invalid Email, please write an vaild E-Mail\n";
				cout << "Enter your Email : ";
				continue;

			}
			else
				break;
		}
		 if (LoggedinUser.type == "H") {
			if (Main_Menu::Host_Enter.count(temail) > 0) {
				cout << "This Email is Already Registered , please write another email..... \n";
				cout << "Enter your Email : ";
				continue;

			}
			if (Email_Check(temail) == false) {
				cout << "Invalid Email, please write an vaild E-Mail\n";
				cout << "Enter your Email : ";
				continue;

			}
			else
				break;
		}
	}
	cout << "Enter your password : ";
	while (true) {
		cin >> tpassword;
		if (tpassword.size() < 6) {
			cout << "Password length should be at least 6\n";
			cout << "Enter your password : ";
			continue;
		}
		else
			break;
	}
	cout << "Enter your nationality : ";
	cin >> tnationality;
	cout << "Enter your gender( Male or Female)  : ";
	while (true) {
		cin >> tgender;
		if (tgender == "Male" || tgender == "male" || tgender == "Female" || tgender == "female" ||
			tgender == "M" || tgender == "m" ||tgender == "F" || tgender == "f") {
			break;
		}
		else {
			cout << "Invalid gender [ Should be (Male or male or M or m) or (Female or female or F or f) ]\n";
			cout << "Enter your gender : ";
			continue;
		}

	}
	cout << "Enter your Age : ";
	cin >> tage;
	cout << "Enter your Favourite Color (Important to protect your Email)\n";
	cin >> tFavouriteColor;
	if (LoggedinUser.type == "T")
	{
		Traveller t(tname, temail, tpassword, tage, tnationality, tgender, tFavouriteColor);
		Main_Menu::Trav_Users.push_back(t);
		Main_Menu::Trav_Enter.insert(pair<string, string>(temail, tpassword));
	}
	else {
		Host h(tname, temail, tpassword, tage, tnationality, tgender, tFavouriteColor);
		Main_Menu::Host_Users.push_back(h);
		Main_Menu::Host_Enter.insert(pair<string, string>(temail, tpassword));
	}

	
	cout << "|S I G N E D  U P  S U C C E S S F U L L Y |\n";

	Sleep(2000);
	system("cls");
}
bool      Main_Menu::login() {
	string email, password;

	system("cls");                                      /////
	cout << "|--------- L O G I N I N G  I N -----------|\n";
	cout << "Enter Email : ";
	cin >> email;
	cout << "Enter password : ";
	cin >> password;
	if (Main_Menu::LoggedinUser.type == "H") {
		if (Main_Menu::Host_Enter[email] == password) {
			cout << "Logged in succesfully!\n " << endl;
			system("cls");
			Main_Menu::LoggedinUser.email = email;
			for (int i = 0; i < Main_Menu::Host_Enter.size(); i++) {
				if (email == Main_Menu::Host_Users[i].email) {
					Main_Menu::LoggedinUser.name = Main_Menu::Host_Users[i].name;
					break;
				}

			}
			return true;
		}
		else {
			cout << "Invalid Email or Worng Password!\n" << endl;
			Sleep(3000);
			return false;
		}
	}
	else if (Main_Menu::LoggedinUser.type == "T") {
		if (Main_Menu::Trav_Enter[email] == password) {
			cout << "|L O G G E D  I N  S U C C E S S F U L L Y |\n";
			Sleep(1000);
			system("cls");
			Main_Menu::LoggedinUser.email = email;
			for (int i = 0; i < Main_Menu::Trav_Enter.size(); i++) {
				if (email == Main_Menu::Trav_Users[i].email) {
					Main_Menu::LoggedinUser.name = Main_Menu::Trav_Users[i].name;
					break;
				}

			}
			return true;
		}
		else {
			cout << "Invalid Email or Worng Password!\n" << endl;
			Sleep(3000);
			return false;
		}
	}
}
bool      Main_Menu::Email_Check(string email) {

	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(email, pattern);

}

Traveller& Main_Menu::TGetUserInfoByEmail(string email){
	for (int i = 0; i < Main_Menu::Trav_Users.size(); i++) {
		if (Main_Menu::Trav_Users[i].email == email)
			return Main_Menu::Trav_Users[i];
	}
}
Host&      Main_Menu::HGetUserInfoByEmail(string email) {
	for (int i = 0; i < Main_Menu::Host_Users.size(); i++) {
		if (Main_Menu::Host_Users[i].email == email)
			return Main_Menu::Host_Users[i];
	}
}
          Main_Menu::~Main_Menu(){}