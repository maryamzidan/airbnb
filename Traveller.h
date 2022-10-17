
#include "structs.h"
#pragma once
#include "User.h"
#include<vector>

class Traveller : public User {
public:
	vector<rented> rentedPlaces;
	Traveller(string name, string email, string password, int age, string nationality, string gender, string FavouritColor );
	Traveller();
	~Traveller();
	int Search();
	int Pay(date d1 , date d2);
	void ShowRentedPlaces();
	void DisplayTrav();
	void AddRent(rented r);
};
