#pragma once
#include<string>
using namespace std;

class User
{
public:
	string name;
	string email;
	string password;
	int age = 20;
	string nationality;
	string gender;
	string FavouriteColor;
public:
	User(string name, string email, string password, int age, string nationality, string gender, string FavouritColor);
	User(void);
	void Display();
	~User(void);


};


