#include "User.h"
#include<IOSTREAM>
using namespace std;


User::User(string name, string email, string password, int age, string nationality, string gender, string FavouritColor) {
	this->name = name;
	this->email = email;
	this->password = password;
	this->age = age;
	this->nationality = nationality;
	this->gender = gender;
	this->FavouriteColor = FavouritColor;
}
void User::Display() {
	cout << "Username : " << name;
	cout << "Password :" << password;
	cout << "Age : " << age;
	cout << "Nationality :" << nationality;
	cout << "Gender : " << gender;
}
User::~User() {

}
User::User(){}