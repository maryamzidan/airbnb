#include "Place.h"
#include<iostream>
using namespace std;

Place::Place(string t, string c, string a, date s, date e, int p, int g, int r) {
	typeOfPlace = t;
	id = placesCount++;
	city = c;
	address = a;
	avaliableFROM = s;
	avaliableTO = e;
	price = p;
	guests = g;
	NumOfRooms = r;
}
void Place::DisplayPlace() {
	cout << "\n-------------------------------------------\n";
	cout << "Place ID : " << id;
	cout << "\nPlace Type : " << typeOfPlace;
	cout << "\nCity : " << city;
	cout << "\nAddress : " << address;
	cout << "\nPrice ( for one night) : " << price;
	cout << "\nAvability:";
	cout << "\nFrom : "   << avaliableFROM.d << "/" << avaliableFROM.m << "/" << avaliableFROM.y;
	cout << "\nTo   : "   << avaliableTO.d   << "/" << avaliableTO.m   << "/" << avaliableTO.y;
	cout << "\nNumber of Guests :" << guests;
	cout << "\nNumber of Rooms :" << NumOfRooms;
	cout << "\n-------------------------------------------\n";
}
bool Place::isReserved() {
	return reserved;
}

Place::~Place(void) {}
