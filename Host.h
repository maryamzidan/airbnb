#pragma once
#include"User.h"
#include"Place.h"
class Host : public User {
public:
	Host(string name, string email, string password, int age, string nationality, string gender, string FavouritColor);
	Host();
	~Host();
	void DisplayHost();
	void addPlace();
};

