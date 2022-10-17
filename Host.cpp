#include"Main_Menu.h"
#include "Host.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include <regex>
#include <map>
using namespace std;
Host::Host(string name, string email, string password, int age, string nationality, string gender, string FavouritColor)
	:User(name, email, password, age, nationality, gender, FavouritColor) {
}
Host::~Host() {

}
Host::Host() {

}
void Host::DisplayHost() {

	cout << "Name  :" << name << endl;
	cout << "Email :" << email << endl;
	cout << "Password :" << password << endl;
	cout << "Nationality :" << nationality << endl;
	cout << "Age :" << age << endl;
	cout << "Gender :" <<gender << endl;
}
void Host::addPlace() {
	string typeofplace, address, city;
	int id, price, numofGuests, numofRooms;
	date from, to;
	bool reserved = false;
	int choice;
	cout << "|Enter The Type of The place              |\n";
	cout << "|-----------------------------------------|\n";
	cout << "| |1: Apartment| |2: Villa | |3: Hostel | |\n";
	cout << "|-----------------------------------------|\n";
	cin >> choice;
	if (choice == 1) typeofplace = "Apartment";
	else if (choice == 2) typeofplace = "Villa";
	else if (choice == 3) typeofplace = "Hostel";
	cout << "|-----------------------------------------|\n";
	cout << "|Enter City                               |\n";
	cout << "|-----------------------------------------|\n";
	cin >> city;
	cout << "|-----------------------------------------|\n";
	cout << "|Enter place Price                        |\n";
	cout << "|-----------------------------------------|\n";
	cin >> price;
	cout << "|-----------------------------------------|\n";
	cout << "|Enter Start Date (DD/MM/YY):             |\n";
	cout << "|-----------------------------------------|\n";
	cin >> from.d >> from.m >> from.y;
	cout << "|-----------------------------------------|\n";
	cout << "|Enter End Date (DD/MM/YY):               |\n";
	cout << "|-----------------------------------------|\n";
	cin >> to.d >> to.m >> to.y;
	cout << "|-----------------------------------------|\n";
	cout << "|Enter The Address of the Place           |\n";
	cout << "|-----------------------------------------|\n";
	cin >> address;
	cout << "|-----------------------------------------|\n";
	cout << "|Enter The number of Guests               |\n";
	cout << "|-----------------------------------------|\n";
	cin >> numofGuests;
	cout << "|-----------------------------------------|\n";
	cout << "|Enter the number of Rooms                |\n";
	cout << "|-----------------------------------------|\n";
	cin >> numofRooms;
	Place tmp2(typeofplace, city, address, from, to, price, numofGuests,numofRooms);
	Main_Menu::places.push_back(tmp2);
}

