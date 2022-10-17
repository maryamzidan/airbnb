#pragma once

#ifndef MY_HEADER 
#define MY_HEADER
#include"Host.h"
#include"Traveller.h"
#include"DateCalc.h"
#include<vector>
#include<map>
#include<string>
#include"structs.h"
class Main_Menu
{

public:
	static vector <Traveller> Trav_Users;
	static map<string, string> Trav_Enter;
	static vector<Host> Host_Users;
	static map<string, string> Host_Enter;
	static CurrentUser LoggedinUser;
	static vector<Place> places;

	Main_Menu();
	~Main_Menu();
	void menu();
	void WelcomeScreen();
	void signup();
	bool login();
	bool Email_Check(string email);
	Traveller& TGetUserInfoByEmail(string email);
	Host& HGetUserInfoByEmail(string email);

};

#endif