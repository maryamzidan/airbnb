#include"structs.h"
#pragma once

	static int placesCount;

class Place
{

public:
	string typeOfPlace;
	int id;
	string city;
	int price;
	date avaliableFROM;
	date avaliableTO;
	string address;
	int guests;
	int NumOfRooms;
	bool reserved = false;


	Place(string, string, string, date, date, int, int, int);
	~Place(void);
	void DisplayPlace();
	bool isReserved();

};

