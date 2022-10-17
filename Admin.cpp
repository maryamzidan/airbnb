#include "Admin.h"
#include<iostream>
#include <conio.h>
#include "Windows.h"
#include "Main_Menu.h"
#include "statistics.h"
using namespace std;

Traveller tr;
Host ho;
Main_Menu m;
statistics s;

Admin::Admin() {

}
void Admin::Dashboard() {
	cout << "**********************\n";
	cout << "*   Admin Dashboard  *\n";
	cout << "*                    *\n";
	cout << "**********************\n\n\n";

	cout << "View Data :\n";
	cout << "-----------------------------------\n\n";
	cout << "\t1 - View All Travellers Users\n\n";
	cout << "\t2 - View All Hosts Users\n\n";
	cout << "\t3 - View All Places\n\n";
	cout << "-----------------------------------\n";
	cout << "Edit Data :\n";
	cout << "-----------------------------------\n\n";
	cout << "\t4 - Edit Travellers Users\n\n";
	cout << "\t5 - Edit Hosts Users\n\n";
	cout << "\t6 - Edit Places\n\n";
	cout << "-----------------------------------\n";
	cout << "\t7 - Log out" << endl;
	cout << "Choose : ";
	int ch;
	cin >> ch;
	if (ch == 1) {
		system("cls");
		cout << "1 - Show Stats" << endl;
		cout << "2 - Display Travellers " << endl;
		int see = 0;
		cin >> see;
		system("cls");
		if (see == 1) {
			cout << "Traveler's\n";
			cout << "Number of Travelers : " << Main_Menu::Trav_Users.size() << endl;
			cout << "Travellers Age Mean : " << s.AgeTMean() << endl;
			cout << "Travellers Age Median : " << s.AgeTMedian() << endl;
			cout << "Common Travellers Name : " << s.NameTMode() << endl;
			cout << "Common Travellers Age : " << s.AgeTMode() << endl;
			cout << "Common Travellers Naionality : " << s.NationalityTMode() << endl;
			cout << "Common Travellers Gender : " << s.GenderTMode() << endl;
			Sleep(3000);
			system("pause");
			system("cls");
		}
		else if (see == 2) {
			cout << "Traveler's\n";
			cout << "Number of Travelers : " << Main_Menu::Trav_Users.size() << endl;
			DisplayAllTravs();
			system("pause");
		}

	}
	else if (ch == 2) {
		system("cls");
		cout << "1 - Show Stats" << endl;
		cout << "2 - Display Hosts " << endl;
		int see = 0;
		cin >> see;
		system("cls");

		if (see == 1) {
			cout << "Host's\n";
			cout << "Number of Hosts : " << Main_Menu::Host_Users.size() << endl;
			cout << "Common Hosts Name : " << s.NameHMode() << endl;
			cout << "Common Hosts Age : " << s.AgeHMode() << endl;
			cout << "Common Hosts Naionality : " << s.NationalityHMode() << endl;
			cout << "Common Hosts Gender : " << s.GenderHMode() << endl;
			Sleep(3000);
			system("pause");

			system("cls");
		}
		else if (see == 2) {
			cout << "Host's\n";
			cout << "Number of Hosts : " << Main_Menu::Host_Users.size() << endl;
			DisplayAllHosts();
			system("pause");
		}
	}
	else if (ch == 3) {
		system("cls");
		cout << "1 - Show Stats" << endl;
		cout << "2 - Display places " << endl;
		int see;
		cin >> see;
		system("cls");
		if (see == 1) {
			cout << "Places\n";
			cout << "Number of places : " << Main_Menu::places.size() << endl;
			cout << "Price Mean : " << s.PriceMean() << endl;
			cout << "Price Mode : " << s.PriceMode() << endl;
			cout << "Price Median : " << s.PriceMedian() << endl;
			cout << "----------------------------------------------------------------------" << endl;
			cout << "Number of Guests Mean : " << s.GuestsMean() << endl;
			cout << "Number of Guests Mode : " << s.GuestsMode() << endl;
			cout << "Number Guests Median : " << s.GuestsMedian() << endl;
			cout << "----------------------------------------------------------------------" << endl;
			cout << "Number of Rooms Mean : " << s.RoomMean() << endl;
			cout << "Number of Rooms Mode : " << s.RoomMode() << endl;
			cout << "Number of Rooms Median : " << s.RoomMedian() << endl;
			cout << "----------------------------------------------------------------------" << endl;
			cout << "Common City : " << s.CityMode() << endl;
			cout << "Common Place : " << s.TypeMode() << endl;
			cout << "----------------------------------------------------------------------" << endl;
			Sleep(3000);
			system("pause");
			system("cls");
		}
		else if (see == 2) {
			cout << "Places\n";
			cout << "Number of places : " << Main_Menu::places.size() << endl;
			DisplayAllPlaces();
			system("pause");
		}
	}
	else if (ch == 4) {
		system("cls");
		ChangeTraveler();

	}
	else if (ch == 5) {
		system("cls");
		ChangeHost();
		system("pause");

	}
	else if (ch == 6) {
		system("cls");
		ChangePlace();

	}
	else if (ch == 7) {
		system("cls");
		m.menu();

	}
}
void Admin::login() {
	string Email;
START:system("cls");
	cout << "Enter Email : ";
	cin >> Email;

	cout << "Enter Password  : ";
	char pass[6] = "admin";
	int i = 0;
	char a;
	bool right = true;
	for (i = 0;;)
	{
		a = _getch();
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
		{
			if (a != pass[i])
				right = false;
			i++;
			cout << "*";
		}
		if (a == '\b' && i >= 1)
		{
			cout << "\b \b";
			--i;
		}
		if (a == '\r')
		{
			break;
		}
	}
	if (Email == "admin" && right == true) {

		cout << "\nLogin in Succesfully ..." << endl;
		Sleep(2000);
		system("CLS");
	}
	else {
		cout << "\nInvalid Email or Password, please try again\n";
		Sleep(2000);
		system("CLS");
		goto START;
	}
}
int Admin::SearchForPlace() {
	cout << "Enter id place that you want to Edit : ";
	int id;
	cin >> id;
	for (int i = 0; i < Main_Menu::places.size(); i++) {
		if (Main_Menu::places[i].id == id) {
			return i;
		}
	}
	return -1;
}
void Admin::ChangeTraveler() {
Start:cout << "Enter Email that you want to Edit : ";
	string Email, tmp;
	cin >> Email;
	int index, tmp1;
	bool right = false;
	for (int i = 0; i < Main_Menu::Trav_Users.size(); i++) {
		if (Main_Menu::Trav_Users[i].email == Email) {
			index = i;
			right = true;
		}
	}
	if (right == true) {
		while (true) {
			system("cls");
			cout << "Editing for : " << Email;
			int choice;
			cout << "\n1 - Change password " << endl;
			cout << "2 - Change gender " << endl;
			cout << "3 - Change nationality " << endl;
			cout << "4 - Change age " << endl;
			cout << "5 - Delete Traveler " << endl;
			cout << "6 - Delete Rented place " << endl;
			cout << "7 - Back " << endl;

			cin >> choice;

			if (choice == 1) {
				cout << "Enter New password : ";
				cin >> tmp;
				Main_Menu::Trav_Enter[Email] = tmp;
				Main_Menu::Trav_Users[index].password = tmp;

			}
			else if (choice == 2) {
				cout << "Enter new Gender : ";
				cin >> tmp;
				Main_Menu::Trav_Users[index].gender = tmp;


			}
			else if (choice == 3) {
				cout << "Enter new nationality : ";
				cin >> tmp;
				Main_Menu::Trav_Users[index].nationality = tmp;
			}
			else if (choice == 4) {
				cout << "Enter new age : ";
				cin >> tmp1;
				Main_Menu::Trav_Users[index].age = tmp1;
			}
			else if (choice == 5) {
				Main_Menu::Trav_Users.erase(Main_Menu::Trav_Users.begin() + index);
			}
			else if (choice == 6) {
				if (Main_Menu::Trav_Users[index].rentedPlaces.size() != 0) {
					Main_Menu::Trav_Users[index].ShowRentedPlaces();
					cout << "Choose Place to Cancel " << endl;
					int tmpid;
					cin >> tmpid;
					int indexofDeletedPlace = Main_Menu::Trav_Users[index].rentedPlaces[tmpid].id;
					Main_Menu::places[indexofDeletedPlace].reserved = false;
					Main_Menu::Trav_Users[index].rentedPlaces.erase(Main_Menu::Trav_Users[index].rentedPlaces.begin() + tmpid);
				}
				else {
					cout << "This User doesn't have any rented places\n";
					Sleep(3000);
				}
			}
			else if (choice == 7) {
				break;
			}
			else {
				system("cls");
				cout << "Invalid Choice , Try again " << endl;
				goto Start;
			}
		}
	}
	else {
		system("cls");
		cout << "Email Not Found , Try again " << endl;
		goto Start;

	}

}
void Admin::ChangeHost() {
Start:cout << "Enter Email that you want to Edit : ";
	string Email, tmp;
	cin >> Email;
	int index, tmp1;
	bool right = false;
	for (int i = 0; i < Main_Menu::Host_Users.size(); i++) {
		if (Main_Menu::Host_Users[i].email == Email) {
			index = i;
			right = true;
		}
	}
	if (right == true) {
		while (true) {
			system("cls");
			cout << "Editing for : " << Email;
			int choice;
			cout << "\n1 - Change password " << endl;
			cout << "2 - Change gender " << endl;
			cout << "3 - Change nationality " << endl;
			cout << "4 - Change age " << endl;
			cout << "5 - Delete Host " << endl;
			cout << "6 - Back\n";
			cin >> choice;
			if (choice == 1) {
				cout << "Enter New password : ";
				cin >> tmp;
				Main_Menu::Host_Enter[Email] = tmp;
				Main_Menu::Host_Users[index].password = tmp;
			}
			else if (choice == 2) {
				cout << "Enter new Gender : ";
				cin >> tmp;
				Main_Menu::Host_Users[index].gender = tmp;
			}
			else if (choice == 3) {
				cout << "Enter new nationality : ";
				cin >> tmp;
				Main_Menu::Host_Users[index].nationality = tmp;
			}
			else if (choice == 4) {
				cout << "Enter new age : ";
				cin >> tmp1;
				Main_Menu::Host_Users[index].age = tmp1;
			}
			else if (choice == 5) {
				Main_Menu::Host_Users.erase(Main_Menu::Host_Users.begin() + index);
			}
			else if (choice == 6)
				break;
			else {
				system("cls");
				cout << "Invalid Choice , Try again " << endl;
				goto Start;

			}
		}
	}
	else {
		system("cls");
		cout << "Email Not Found , Try again " << endl;
		goto Start;

	}

}
void Admin::ChangePlace() {
Start:int index = SearchForPlace();
	int Choice, tmp3;
	date tmp1;
	string tmp2;
	if (index != -1) {
		while (true) {
			system("cls");

			cout << "1 - Change Type Of Place " << endl;
			cout << "2 - Change City " << endl;
			cout << "3 - Change Price" << endl;
			cout << "4 - Change Start Date " << endl;
			cout << "5 - Change End Date " << endl;
			cout << "6 - Change address " << endl;
			cout << "7 - Change Number Of Guests " << endl;
			cout << "8 - Change Number of Rooms " << endl;
			cout << "9 - Delete Place " << endl;
			cout << "10 - Back\n";
			cin >> Choice;
			if (Choice == 1) {
				cout << "Enter New Type of place : ";
				cin >> tmp2;
				Main_Menu::places[index].typeOfPlace = tmp2;
			}
			else if (Choice == 2) {
				cout << "Enter New City : ";
				cin >> tmp2;
				Main_Menu::places[index].city = tmp2;
			}
			else if (Choice == 3) {
				cout << "Enter New price : ";
				cin >> tmp3;
				Main_Menu::places[index].price = tmp3;
			}
			else if (Choice == 4) {
				cout << "Enter New Start Date (YY//MM//DD): ";
				cin >> tmp1.d;
				cin >> tmp1.m;
				cin >> tmp1.y;
				Main_Menu::places[index].avaliableFROM = tmp1;
			}
			else if (Choice == 5) {
				cout << "Enter New New End Date (YY//MM//DD): ";
				cin >> tmp1.d;
				cin >> tmp1.m;
				cin >> tmp1.y;
				Main_Menu::places[index].avaliableTO = tmp1;
			}
			else if (Choice == 6) {
				cout << "Enter New address : ";
				cin >> tmp2;
				Main_Menu::places[index].address = tmp2;
			}
			else if (Choice == 7) {
				cout << "Enter New Number of guests : ";
				cin >> tmp3;
				Main_Menu::places[index].guests = tmp3;
			}
			else if (Choice == 8) {
				cout << "Enter New Number of Rooms : ";
				cin >> tmp3;
				Main_Menu::places[index].NumOfRooms = tmp3;
			}
			else if (Choice == 9) {
				Main_Menu::places.erase(Main_Menu::places.begin() + index);
			}
			else if (Choice == 10) {
				break;
			}
			else {
				system("cls");
				cout << "Invalid Choice , Try again " << endl;
				goto Start;
			}
		}
	}
	else {
		system("cls");
		cout << "Id Not Found , Try again " << endl;
		goto Start;
	}
}
void Admin::DisplayAllHosts() {
	for (int i = 0; i < Main_Menu::Host_Users.size(); i++) {
		cout << "---------------------------------\n";
		Main_Menu::Host_Users[i].DisplayHost();
		cout << "---------------------------------\n";

	}
}
void Admin::DisplayAllTravs() {
	for (int i = 0; i < Main_Menu::Trav_Users.size(); i++) {
		cout << "---------------------------------\n";
		Main_Menu::Trav_Users[i].DisplayTrav();
		cout << "---------------------------------\n";

	}
}
void Admin::DisplayAllPlaces() {
	for (int i = 0; i < Main_Menu::places.size(); i++) {
		cout << "---------------------------------\n";
		Main_Menu::places[i].DisplayPlace();
		cout << "---------------------------------\n";

	}
}
Admin::~Admin() {

}
