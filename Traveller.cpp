#include "Main_Menu.h"

#include <iostream>
using namespace std;
Main_Menu m2;
Traveller::Traveller() {};
Traveller::Traveller(string name, string email, string password, int age, string nationality, string gender, string FavouritColor )
	:User(name, email, password, age, nationality, gender, FavouritColor) {
}
int  Traveller::Search() {

	//-------------------------------------------------------------------------------------------------
	string city;
	int range1;
	int range2;
	date trav_s;
	date trav_e;
	int count = 0; //>>>>>>>>>how many places matches ?
	int ch;
	//-------------------------------------------------------------------------------------------------


	//-------------------TAKES INPUTS FROM USER------------------------------------------------------------------------------
	
	cout << "Enter City : ";
	cin >> city;
	cout << "Enter Price Range:\n";
	cout << "From : "; cin >> range1;
	cout << "To : "; cin >> range2;
	cout << "Start Date (DD MM YY) :"; cin >> trav_s.d >> trav_s.m >> trav_s.y;
	cout << "End Date   (DD MM YY) :";  cin >> trav_e.d >> trav_e.m >> trav_e.y;
	//-------------------------------------------------------------------------------------------------

	// counts how many matches found 
	for (int i = 0; i < Main_Menu::places.size(); i++) {
		if ((
			DateCalc::CheckForAvability(Main_Menu::places[i].avaliableFROM, Main_Menu::places[i].avaliableTO, trav_s, trav_e) == true &&
			Main_Menu::places[i].price >= range1 && Main_Menu::places[i].price <= range2) &&
			Main_Menu::places[i].city == city &&
			!Main_Menu::places[i].isReserved()) {

			count++;
		}
	}
	// --------------------------

	//if there at least one matches found show its info if not display No Matches Found-----
	if (count > 0) {
	  //cout << "|--- S E A R C H  F O R  A  P L A C E  ---|\n";

		cout << "-------------------------------------------\n";
		cout << "|       "<<count<<"  M A T C H E S  F O U N D       |\n";
		cout << "-------------------------------------------\n";
		cout << "|---    P L A C E S  D E T A I L S     ---|\n";
		for (int i = 0; i < Main_Menu::places.size(); i++) {
			if (
				(DateCalc::CheckForAvability(Main_Menu::places[i].avaliableFROM, Main_Menu::places[i].avaliableTO, trav_s, trav_e) == true &&
					(Main_Menu::places[i].price >= range1 && Main_Menu::places[i].price <= range2) &&
					Main_Menu::places[i].city == city &&
					!Main_Menu::places[i].isReserved())
				)
			{
				Main_Menu::places[i].DisplayPlace();


			}
		}
		int flag = Pay(trav_s, trav_e);
		if (flag == 0) return 0;

	}
	else {
		system("cls");
		cout << "No Matches Found :(\n";
		cout << "1 - Back \n";
		cout << "2 - Log out\n";
		cin >> ch;
		if (ch == 1) { system("cls"); return 1; }
		else if (ch == 2) { system("cls");  return 2; }
	}
	//--------------------------------------------------------------------------------------

	// make the user choose a place then add it to his struct and shows the invoice----
	//----------------------------------------------------------------------------------
}
int  Traveller::Pay(date d1, date d2) {
	//----------------------------------------------------------------------------
	int choosedPlaceID;
	int choice2;
	int price;
	int Stay = DateCalc::diff(d1, d2);
	//----------------------------------------------------------------------------

	//-------- User Chooses A place Through it's ID ----------------------------------------------------------------------------------
	cout << "\nChoose a place to rent (Type the ID)\n";
	cin >> choosedPlaceID;
	cout << "-------------------------------------------\n";
	if (choosedPlaceID > Main_Menu::places.size() && choosedPlaceID < 0) //if the entered id is bigger than the vector size, its invalid choice of course 
		cout << "Invalid Choice, please try again!\n";

	//---------------------------------------------------------------------------------------------------------------------------------
	price = Main_Menu::places[choosedPlaceID].price; // getting the price of the choosed place

//-------------------- Showing The Choosed place Details + the Invoice ---------------------
	system("cls");
	cout << "|--------I  N  V  O  I  C  E--------------|\n";
	cout << " Place Details\n";
	Main_Menu::places[choosedPlaceID].DisplayPlace();
	cout << "\n Days of Stay  :" << Stay;
	cout << "\n Total : " << Stay * price << " $\n";
	cout << "-------------------------------------------\n";
	cout << "\nPress 1 to Confirm Payment\n";
	cout << "Press 2 to Cancel Payment\n";
	cout << "-------------------------------------------\n";
	//---------------------------------------------------------------------------------------------
	cin >> choice2;
	//-------- Confirm Payment-------------------------------------------------
	if (choice2 == 1) {
		rented r; // create an object of rented to store the choosed place in it
		system("cls");
		cout << "Paid Successfully!\n";
		Main_Menu::places[choosedPlaceID].reserved = true; // make the choosed place reserved محجوز
         r = { Main_Menu::places[choosedPlaceID].id,Main_Menu::places[choosedPlaceID].typeOfPlace,Main_Menu::places[choosedPlaceID].city , Main_Menu::places[choosedPlaceID].address , Main_Menu::places[choosedPlaceID].price , d1 , d2 ,DateCalc::diff(d1,d2) , Main_Menu::places[choosedPlaceID].NumOfRooms };
		 m2.TGetUserInfoByEmail(Main_Menu::LoggedinUser.email).AddRent(r);
		
	}
	//------------------------------------------------------------------------

	//--------Cancel Payment --------------------------------------------------
	else {
		system("CLS");
		return 1;
	}
	//------------------------------------------------------------------------

}
void Traveller::ShowRentedPlaces() {
	if (rentedPlaces.size() == 0) 
		cout << "You Have no Rented Places\n";
	else
	for (int j = 0; j < rentedPlaces.size(); j++) {
	
				cout << "Rented Place No. " << j << endl;
				cout << "Type :" << rentedPlaces[j].type << endl;
				cout << "City: " << rentedPlaces[j].city << endl;
				cout << "Address: " <<rentedPlaces[j].address << endl;
				cout << "Price: " << rentedPlaces[j].price << endl;
				cout << "From: " << rentedPlaces[j].from.d << "/" << rentedPlaces[j].from.m << "/" << rentedPlaces[j].from.y << endl;
				cout << "To:   " << rentedPlaces[j].to.d   << "/" << rentedPlaces[j].to.m   << "/" << rentedPlaces[j].to.y   << endl;
				cout << "Days of stay: " << rentedPlaces[j].days << endl;
				cout << "Number of Rooms: " << rentedPlaces[j].rooms << endl;
				cout << "-------------------------------------------\n";

		
		
	
			
		
	}
}
void Traveller::DisplayTrav() {

		cout << "Name : " << name << endl;
		cout << "Email : " << email << endl;
		cout << "Password : " << password << endl;
		cout << "Nationality : " << nationality << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " <<gender << endl;
	

	
}
void Traveller::AddRent(rented r) {
	this->rentedPlaces.push_back(r);
}
Traveller::~Traveller(){}
